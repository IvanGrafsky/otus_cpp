#include <string>

#pragma once

class Logger{
 public:
  Logger(Logger&) = delete;

  void operator=(const Logger&) = delete;

  static Logger* GetInstance();

  void Log(const std::string&);
 protected:
  Logger(){};

 private:
  static Logger* log_;
};