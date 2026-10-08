#include "classroom/audio_ring.hpp"
#include "classroom/vad_segmenter.hpp"
#include <cassert>
#include <vector>
int main(){classroom::AudioRing<int,8>r;for(int i=0;i<7;i++)assert(r.push(i));assert(!r.push(8));for(int i=0,x;i<7;i++){assert(r.pop(x));assert(x==i);}std::vector<classroom::SpeechSegment>o;classroom::VadSegmenter v(100,40,1000,[&](auto s){o.push_back(std::move(s));});std::vector<float>s(320,.1f),z(320,0);v.consume(s.data(),s.size());v.consume(z.data(),z.size());v.consume(z.data(),z.size());assert(o.size()==1);}
