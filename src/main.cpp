#include "classroom/application.hpp"
#include "classroom/config.hpp"
#include <csignal>
#include <exception>
#include <iostream>
static classroom::Application* app=nullptr;static void sig(int){if(app)app->stop();}
int main(int argc,char**argv){try{auto c=classroom::Config::load(argc,argv);classroom::Application a(c);app=&a;std::signal(SIGINT,sig);std::signal(SIGTERM,sig);return a.run();}catch(const std::exception&e){std::cerr<<"fatal: "<<e.what()<<"\n";return 1;}}
