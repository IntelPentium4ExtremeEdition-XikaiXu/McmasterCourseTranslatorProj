#include "classroom/config.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
namespace classroom { Config Config::load(int argc,char**argv){Config c; std::string path="config/default.conf"; for(int i=1;i<argc;i++){std::string a=argv[i];if(a=="--config"&&i+1<argc)path=argv[++i];else if(a=="--model"&&i+1<argc)c.model=argv[++i];else if(a=="--no-gpu")c.gpu=false;else if(a=="--help"){std::cout<<"--config FILE --model FILE --no-gpu\n";std::exit(0);}}
 std::ifstream f(path); if(!f)return c; std::string s; while(std::getline(f,s)){if(s.empty()||s[0]=='#')continue;auto p=s.find('=');if(p==std::string::npos)continue;auto k=s.substr(0,p),v=s.substr(p+1);if(k=="whisper.model")c.model=v;else if(k=="whisper.cpu_threads")c.whisper_threads=std::stoi(v);else if(k=="whisper.use_gpu")c.gpu=(v=="true");else if(k=="vad.threshold")c.vad_threshold=std::stoi(v);else if(k=="vad.hangover_ms")c.hangover_ms=std::stoi(v);else if(k=="vad.max_segment_ms")c.max_segment_ms=std::stoi(v);else if(k=="output.fifo")c.fifo=v;else if(k=="output.transcript_dir")c.transcript_dir=v;else std::cerr<<"warning: unknown config key "<<k<<"\n";} return c;}}
