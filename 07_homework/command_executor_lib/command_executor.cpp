#include "command_executor.h"
#include <iomanip>

int CommandExecutor::ExecuteCommands(std::vector<Command>& v){
  int result = 0;

  if(!v.empty()){
    log_->Log("bulk: ");
  }

  for(size_t i = 0; i < v.size(); i++){
    log_->Log(v[i].GetName());
    if(i != v.size() - 1){
      log_->Log(", ");
    }
    result += ExecuteCommand(v[i]);
  }

  return result;
}

int CommandExecutor::ExecuteCommand(Command& c){
  std::cout << "Executing " << c.GetName() << " " << "in time "/*;
            << std::put_time(std::localtime(c.GetTime()), "%F %T.\n")*/ << std::endl;
  return 0;
}