#pragma once
#include <array>
#include <atomic>
#include <cstddef>
namespace classroom {
template<class T,size_t N> class AudioRing { static_assert((N&(N-1))==0); std::array<T,N> a_{}; alignas(64) std::atomic<size_t> h_{}; alignas(64) std::atomic<size_t> t_{};
public: bool push(const T& v){auto h=h_.load(std::memory_order_relaxed), n=(h+1)&(N-1); if(n==t_.load(std::memory_order_acquire)) return false; a_[h]=v; h_.store(n,std::memory_order_release);return true;}
 bool pop(T& v){auto t=t_.load(std::memory_order_relaxed);if(t==h_.load(std::memory_order_acquire))return false;v=a_[t];t_.store((t+1)&(N-1),std::memory_order_release);return true;}};}
