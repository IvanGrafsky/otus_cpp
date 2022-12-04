#include <iostream>
#include "logger.h"

Logger* Logger::log_= nullptr;

Logger* Logger::GetInstance(){
  if(log_ == nullptr){
    log_ = new Logger();
  }
  return log_;
}

void  Logger::Log(const std::string& str){
  std::cout << str;
}