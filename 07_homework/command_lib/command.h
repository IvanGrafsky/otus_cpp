#include <chrono>
#include <string>

#pragma once

class Command{
 public:
  using steady_time_t = std::chrono::time_point<std::chrono::steady_clock> ;

  Command() = delete;

  Command(std::string& name);

  const std::string& GetName() const;
  const steady_time_t& GetTime() const;

 private:
  std::string name_;
  steady_time_t time_;
};