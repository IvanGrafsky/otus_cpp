#include <iostream>
#include "execution_manager.h"
#include "command_executor.h"

int main(int argc, char** argv){
  CommandExecutor executor;

  ExecutionManager manager(executor, std::stoi(argv[1]));

  manager.ExecutionLoop(std::cin);

  return 0;
}