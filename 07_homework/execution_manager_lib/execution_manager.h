#include <deque>
#include <iostream>

#include "command_executor.h"

#pragma once

class ExecutionManager{
 public:
  ExecutionManager() = delete;

  ExecutionManager(CommandExecutor& exec, size_t bulk_size);

  void ExecutionLoop(std::istream& is);

 private:
  void StartExecution();

  CommandExecutor& exec_;
  std::deque<Command> q_;
  size_t bulk_size_;
};