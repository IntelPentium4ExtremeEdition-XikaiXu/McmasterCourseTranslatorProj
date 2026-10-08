#include "classroom/vad_segmenter.hpp"
#include <algorithm>
#include <cmath>
namespace classroom {VadSegmenter::VadSegmenter(int t,int h,int m,std::function<void(SpeechSegment)>e):threshold_(t),hang_(h),max_(m),emit_(std::move(e)){}
void VadSegmenter::consume(const float*x,size_t n){if(!n)return;double sum=0;for(size_t i=0;i<n;i++)sum+=x[i]*x[i];int rms=int(std::sqrt(sum/n)*32768);int ms=int(n*1000/16000);bool speech=rms>=threshold_;if(!active_){preroll_.insert(preroll_.end(),x,x+n);size_t keep=4800;if(preroll_.size()>keep)preroll_.erase(preroll_.begin(),preroll_.end()-keep);if(speech){active_=true;silence_=0;segment_=preroll_;preroll_.clear();}}else{segment_.insert(segment_.end(),x,x+n);silence_=speech?0:silence_+ms;if(silence_>=hang_||int(segment_.size()*1000/16000)>=max_)flush();}clock_ms_+=ms;}
void VadSegmenter::flush(){if(!active_||segment_.empty())return;int64_t dur=segment_.size()*1000/16000;emit_({++seq_,clock_ms_-dur,clock_ms_,std::move(segment_)});segment_.clear();active_=false;silence_=0;}}
