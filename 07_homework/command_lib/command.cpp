#include "command.h"


Command::Command(std::string& name) : name_(name){
  time_ = std::clock();
}

const std::string& Command::GetName() const {
  return name_;
}

const std::clock_t& Command::GetTime() const {
  return time_;
}