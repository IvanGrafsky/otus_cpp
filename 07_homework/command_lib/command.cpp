#include "command.h"


Command::Command(std::string& name) : name_(name){
  time_ = std::chrono::steady_clock::now();
}

const std::string& Command::GetName() const {
  return name_;
}

const Command::steady_time_t& Command::GetTime() const {
  return time_;
}