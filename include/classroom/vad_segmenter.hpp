#pragma once
#include "types.hpp"
#include <functional>
#include <vector>
namespace classroom { class VadSegmenter { int threshold_,hang_,max_; bool active_{};int silence_{};uint64_t seq_{};int64_t clock_ms_{};std::vector<float> segment_,preroll_;std::function<void(SpeechSegment)> emit_; public: VadSegmenter(int,int,int,std::function<void(SpeechSegment)>);void consume(const float*,size_t);void flush();};}
