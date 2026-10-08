#include "classroom/output_sink.hpp"
#include <filesystem>
#include <fcntl.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <unistd.h>
namespace classroom {static std::string ts(int64_t m){std::ostringstream o;o<<std::setfill('0')<<std::setw(2)<<m/3600000<<":"<<std::setw(2)<<(m/60000)%60<<":"<<std::setw(2)<<(m/1000)%60<<"."<<std::setw(3)<<m%1000;return o.str();}OutputSink::OutputSink(const Config&c):c_(c){std::filesystem::create_directories(c.transcript_dir);transcript_.open(c.transcript_dir+"/session.txt",std::ios::app);if(c.fifo_enabled){mkfifo(c.fifo.c_str(),0600);try_fifo();}}OutputSink::~OutputSink(){if(fifo_fd_>=0)close(fifo_fd_);}void OutputSink::try_fifo(){if(fifo_fd_<0)fifo_fd_=open(c_.fifo.c_str(),O_WRONLY|O_NONBLOCK);}void OutputSink::write(const TranscriptEvent&e){std::string line="["+ts(e.start_ms)+" -> "+ts(e.end_ms)+"] EN:"+e.english+"\n";std::cout<<line<<std::flush;if(transcript_){transcript_<<line;transcript_.flush();}try_fifo();if(fifo_fd_>=0&&::write(fifo_fd_,line.data(),line.size())<0){close(fifo_fd_);fifo_fd_=-1;}}}
