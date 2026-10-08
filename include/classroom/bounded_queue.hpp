#pragma once
#include <condition_variable>
#include <deque>
#include <mutex>
#include <optional>
#include <stop_token>
namespace classroom {
template<class T> class BoundedQueue {
 std::mutex m_; std::condition_variable_any cv_; std::deque<T> q_; size_t cap_; bool closed_{};
public:
 explicit BoundedQueue(size_t c):cap_(c){}
 bool try_push(T v){std::lock_guard l(m_); if(closed_||q_.size()>=cap_) return false; q_.push_back(std::move(v)); cv_.notify_one(); return true;}
 bool push_drop_oldest(T v){std::lock_guard l(m_); if(closed_) return false; if(q_.size()>=cap_) q_.pop_front(); q_.push_back(std::move(v)); cv_.notify_one(); return true;}
 std::optional<T> wait_pop(std::stop_token st){std::unique_lock l(m_); cv_.wait(l,st,[&]{return closed_||!q_.empty();}); if(q_.empty()) return {}; T v=std::move(q_.front());q_.pop_front();return v;}
 void close(){std::lock_guard l(m_);closed_=true;cv_.notify_all();}
 size_t size(){std::lock_guard l(m_);return q_.size();}
};}
