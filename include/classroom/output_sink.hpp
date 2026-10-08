#pragma once
#include "config.hpp"
#include "types.hpp"
#include <fstream>
namespace classroom {class OutputSink{Config c_;int fifo_fd_=-1;std::ofstream transcript_;void try_fifo();public:explicit OutputSink(const Config&);~OutputSink();void write(const TranscriptEvent&);};}
