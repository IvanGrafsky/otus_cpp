#include <fstream>
#include <iostream>
#include <vector>

#include "../command_lib/command.h"
#include "../logger_lib/logger.h"

#pragma once

class CommandExecutor{
 public:
  CommandExecutor() = delete;
  CommandExecutor(Logger* log) : log_(log){};

  int ExecuteCommands(std::vector<Command>& v);
 private:
  Logger* log_;
  int ExecuteCommand(Command& c);
};