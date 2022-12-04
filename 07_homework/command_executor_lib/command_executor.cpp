#include "command_executor.h"
#include <fstream>
#include <iomanip>


int CommandExecutor::ExecuteCommands(std::vector<Command>& v){
  int result = 0;

  if(!v.empty()){
    log_->Log("bulk: ");
  } else {
    return result;
  }

  std::ofstream file;
  file.open("bulk" + std::to_string(v[0].GetTime()) + ".log");

  for(size_t i = 0; i < v.size(); i++){
    log_->Log(v[i].GetName());
    file << v[i].GetName() << std::endl;
    if(i != v.size() - 1){
      log_->Log(", ");
    } else {
      log_->Log("\n");
    }
    result += ExecuteCommand(v[i]);
  }

  file.close();

  return result;
}

int CommandExecutor::ExecuteCommand(Command& c){
  (void)c;
  return 0;
}