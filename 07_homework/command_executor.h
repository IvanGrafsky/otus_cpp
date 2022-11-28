#include <fstream>
#include <iostream>
#include <vector>

#include "command.h"

#pragma once

class CommandExecutor{
 public:
  int ExecuteCommands(std::vector<Command>& v);
 private:
  int ExecuteCommand(Command& c);
};