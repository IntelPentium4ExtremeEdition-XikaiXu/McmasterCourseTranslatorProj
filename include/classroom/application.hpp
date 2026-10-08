#pragma once
#include "audio_capture.hpp"
#include "bounded_queue.hpp"
#include "config.hpp"
#include "output_sink.hpp"
#include "types.hpp"
#include "vad_segmenter.hpp"
#include "whisper_engine.hpp"
#include <atomic>
#include <memory>
#include <thread>
namespace classroom {class Application{Config c_;BoundedQueue<SpeechSegment>q_{4};WhisperEngine whisper_;OutputSink out_;VadSegmenter vad_;AudioCapture capture_;std::jthread worker_;std::atomic<bool>running_{true};public:explicit Application(Config);int run();void stop();};}
