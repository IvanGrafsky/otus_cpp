#include "command_executor.h"
#include <fstream>
#include <iomanip>


int CommandExecutor::ExecuteCommands(std::vector<Command>& v){
  int result = 0;

  if(!v.empty()){
    LOG("bulk: ");
  } else {
    return result;
  }

  std::ofstream file;
  file.open("bulk" + std::to_string(v[0].GetTime()) + ".log");

  for(size_t i = 0; i < v.size(); i++){
    LOG(v[i].GetName());
    file << v[i].GetName() << std::endl;
    if(i != v.size() - 1){
      LOG(", ");
    } else {
      LOG("\n");
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