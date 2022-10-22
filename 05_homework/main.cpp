#include <iostream>
#include "engine_lib/engine.hpp"

int main(){
  Engine engine;

  engine.CreateDocument();

  for(int i = 0; i < 3; i++){
    engine.CreateFigure();
  }

  engine.SaveDocument("./");

  engine.OpenDocument("./");

  engine.DeleteFigure();

  engine.SaveDocument("./");

  return 0;
}