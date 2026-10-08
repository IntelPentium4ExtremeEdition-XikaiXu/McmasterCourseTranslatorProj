#pragma once
#include <string>
namespace classroom { struct Config { std::string model="models/ggml-tiny.en.bin"; std::string transcript_dir="transcripts"; std::string fifo="/tmp/classroom-translator.pipe"; int vad_threshold=450; int hangover_ms=650; int max_segment_ms=14000; int whisper_threads=1; bool gpu=true; bool fifo_enabled=true; static Config load(int,char**); }; }
