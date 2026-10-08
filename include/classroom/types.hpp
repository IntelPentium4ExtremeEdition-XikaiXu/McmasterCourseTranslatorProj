#pragma once
#include <chrono>
#include <cstdint>
#include <string>
#include <vector>
namespace classroom {
using Clock=std::chrono::steady_clock;
struct SpeechSegment { uint64_t sequence{}; int64_t start_ms{}; int64_t end_ms{}; std::vector<float> samples; };
struct TranscriptEvent { uint64_t sequence{}; int64_t start_ms{}; int64_t end_ms{}; std::string english; std::string chinese; double inference_ms{}; };
}
