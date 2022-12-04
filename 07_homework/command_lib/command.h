#include <chrono>
#include <string>

#pragma once

class Command{
 public:
  Command() = delete;

  Command(std::string& name);

  const std::string& GetName() const;
  const std::clock_t& GetTime() const;

 private:
  std::string name_;
  std::clock_t time_;
};