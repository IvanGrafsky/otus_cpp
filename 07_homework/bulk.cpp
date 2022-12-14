#include <iostream>
#include "execution_manager.h"
#include "command_executor.h"
#include "logger.h"

int main(int argc, char** argv){
  try{

    if(argc <= 1){
      throw std::invalid_argument("number of args less than 1");
    }

    CommandExecutor executor;
    ExecutionManager manager(executor, std::stoi(argv[1]));
    manager.ExecutionLoop(std::cin);

  } catch(const std::exception &e){
    std::cout << "Something went wrong: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}