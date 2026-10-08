#include "classroom/audio_capture.hpp"
#include <pipewire/pipewire.h>
#include <spa/param/audio/format-utils.h>
#include <iostream>
namespace classroom {
struct AudioCapture::Impl { pw_thread_loop* loop{}; pw_stream* stream{}; spa_hook listener{}; AudioCapture* owner{}; };
static void process(void* data){auto*p=static_cast<AudioCapture::Impl*>(data);auto*b=pw_stream_dequeue_buffer(p->stream);if(!b)return;auto*buf=b->buffer; if(buf->datas[0].data){auto*n=buf->datas[0].chunk; size_t bytes=n?n->size:0; p->owner->cb_(static_cast<float*>(buf->datas[0].data),bytes/sizeof(float));}pw_stream_queue_buffer(p->stream,b);}
static const pw_stream_events events={PW_VERSION_STREAM_EVENTS,.process=process};
AudioCapture::AudioCapture(std::function<void(const float*,size_t)> cb):p_(new Impl),cb_(std::move(cb)){p_->owner=this;}
AudioCapture::~AudioCapture(){stop();delete p_;}
bool AudioCapture::start(){pw_init(nullptr,nullptr);p_->loop=pw_thread_loop_new("classroom-audio",nullptr);if(!p_->loop)return false;auto*ctx=pw_context_new(pw_thread_loop_get_loop(p_->loop),nullptr,0);auto*core=pw_context_connect(ctx,nullptr,0);p_->stream=pw_stream_new(core,"classroom-translator",pw_properties_new(PW_KEY_MEDIA_TYPE,"Audio",PW_KEY_MEDIA_CATEGORY,"Capture",PW_KEY_MEDIA_ROLE,"Communication",nullptr));pw_stream_add_listener(p_->stream,&p_->listener,&events,p_);uint8_t buffer[1024];spa_pod_builder b=SPA_POD_BUILDER_INIT(buffer,sizeof(buffer));spa_audio_info_raw info{};info.format=SPA_AUDIO_FORMAT_F32;info.rate=16000;info.channels=1;const spa_pod* params[1]={spa_format_audio_raw_build(&b,SPA_PARAM_EnumFormat,&info)};if(pw_stream_connect(p_->stream,PW_DIRECTION_INPUT,PW_ID_ANY,(pw_stream_flags)(PW_STREAM_FLAG_AUTOCONNECT|PW_STREAM_FLAG_MAP_BUFFERS|PW_STREAM_FLAG_RT_PROCESS),params,1)<0)return false;return pw_thread_loop_start(p_->loop)>=0;}
void AudioCapture::stop(){if(!p_||!p_->loop)return;pw_thread_loop_stop(p_->loop);if(p_->stream)pw_stream_destroy(p_->stream);pw_thread_loop_destroy(p_->loop);p_->stream=nullptr;p_->loop=nullptr;pw_deinit();}
}
