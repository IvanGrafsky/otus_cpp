#include <fstream>
#include <iostream>
#include <exception>
#include <vector>

#include "../command_lib/command.h"
#include "../logger_lib/logger.h"

#pragma once

class CommandExecutor{
 public:
  int ExecuteCommands(std::vector<Command>& v);
 private:
  int ExecuteCommand(Command& c);
};