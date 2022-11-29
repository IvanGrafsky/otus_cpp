#include "execution_manager.h"
#include "../command_lib/command.h"

  ExecutionManager::ExecutionManager(CommandExecutor& exec,
                                      size_t bulk_size) : exec_(exec),
                                                          bulk_size_(bulk_size){}

  void ExecutionManager::StartExecution(){
    // rewrite with move
    std::vector<Command> vec;
    for(auto& x : q_){
      vec.push_back(x);
    }
    q_.clear();
    exec_.ExecuteCommands(vec);
  }

  void ExecutionManager::ExecutionLoop(std::istream& is){
    std::string tmp;
    bool dynamic_block = false;
    size_t parenthesis_counter = 0;
    while(1){
      is >> tmp;
      if(tmp == "EOF"){
        if(!dynamic_block){
          StartExecution();
        }
        break;
      } else if(tmp == "{"){
        parenthesis_counter++;
        if(!q_.empty() && !dynamic_block){
          dynamic_block = true;
          StartExecution();
        }
      } else if(tmp == "}"){
        if(dynamic_block > 0){
          parenthesis_counter--;
        }
        if(parenthesis_counter == 0){
          StartExecution();
        }
      } else {
        q_.emplace_back(Command(tmp));
        if(!dynamic_block){
          if(q_.size() == bulk_size_){
            StartExecution();
          }
        }
      }
    }
  }