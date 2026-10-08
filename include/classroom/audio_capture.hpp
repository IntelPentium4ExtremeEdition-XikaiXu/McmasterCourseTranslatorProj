#pragma once
#include <atomic>
#include <functional>
#include <thread>
namespace classroom { class AudioCapture { struct Impl; Impl* p_{}; std::function<void(const float*,size_t)> cb_; public: explicit AudioCapture(std::function<void(const float*,size_t)>); ~AudioCapture(); bool start(); void stop(); }; }
