#pragma once
#include "config.hpp"
#include "types.hpp"
#include <memory>
namespace classroom { class WhisperEngine { struct Impl;std::unique_ptr<Impl>p_;Config c_;public:explicit WhisperEngine(const Config&);~WhisperEngine();TranscriptEvent transcribe(SpeechSegment);};}
