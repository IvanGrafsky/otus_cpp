#include <iostream>
#include "execution_manager.h"
#include "command_executor.h"
#include "logger.h"

int main(int argc, char** argv){
  if(argc <= 1){
    return -1;
  }

  auto logger = Logger::GetInstance();

  CommandExecutor executor(logger);

  ExecutionManager manager(executor, std::stoi(argv[1]));

  manager.ExecutionLoop(std::cin);

  return 0;
}