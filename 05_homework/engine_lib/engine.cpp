#include "engine.hpp"

#include <iostream>

Engine::Engine(){
  std::cout << "Engine starts" << std::endl;
}

Engine::~Engine(){
  std::cout << "Engine ends" << std::endl;
}


void Engine::OpenDocument(const std::string& path){
  std::cout << "Engine opens document from " << path << std::endl;
  std::cout << "Document reading imitation" << std::endl;
  doc = std::make_unique<Document>();
  Point* p = new Point;
  doc->AddFigure(*p);
  Circle* c = new Circle;
  doc->AddFigure(*c);
  Line* l = new Line;
  doc->AddFigure(*l);
}

void Engine::CreateDocument(){
  std::cout << "Engine creates document " << std::endl;
  doc = std::make_unique<Document>();
}

void Engine::SaveDocument(const std::string& path){
  std::cout << "Engine saves document to " << path << std::endl;
  doc->SaveDocument(path);
}

void Engine::CreateFigure(){
  std::cout << "Engine creates figure " << std::endl;
  std::cout << "0 - point, 1 - line, 2 - rectangle, 3 - circle" << std::endl;
  int tmp;
  std::cin >> tmp;
  if(tmp == 0){
    Point* p = new Point;
    doc->AddFigure(*p);
  } else if(tmp == 1){
    Line* l = new Line;
    doc->AddFigure(*l);
  } else if(tmp == 2){
    Rectangle* r = new Rectangle;
    doc->AddFigure(*r);
  } else if(tmp == 3){
    Circle* c = new Circle;
    doc->AddFigure(*c);
  }
}

void Engine::DeleteFigure(){
  std::cout << "Engine deletes figure " << std::endl;
  std::cout << "Insert num of figure " << std::endl;
  int tmp;
  std::cin >> tmp;
  doc->DeleteFigure(tmp);
}

