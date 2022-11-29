#include "command_executor.h"
#include <iomanip>

int CommandExecutor::ExecuteCommands(std::vector<Command>& v){
  int result = 0;

  for(auto& c : v){
    result += ExecuteCommand(c);
  }
  return result;
}

int CommandExecutor::ExecuteCommand(Command& c){
  std::cout << "Executing " << c.GetName() << " " << "in time "/*;
            << std::put_time(std::localtime(c.GetTime()), "%F %T.\n")*/ << std::endl;
  return 0;
}