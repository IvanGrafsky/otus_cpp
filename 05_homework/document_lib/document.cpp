#include "document.hpp"
#include <iostream>

Document::Document(){
  std::cout << "Document created" << std::endl;
}

Document::Document(const std::string& path){
  std::cout << "Document created from " << path << std::endl;
}

void Document::SaveDocument(const std::string& path){
  std::cout << "Document saved to " << path << std::endl;
  std::cout << "Figures in document: " << std::endl;
  for(auto& i : figures){
    i->About();
  }
  std::cout << "==================== " << std::endl;
}

void Document::AddFigure(IFigure& figure){
  std::cout << "Added figure ";
  figure.About();
  figures.push_back(std::unique_ptr<IFigure>(&figure));
}

void Document::DeleteFigure(size_t num){
  std::cout << "Deleted figure " << num << std::endl;
  figures[num]->About();
  figures.erase(figures.begin() + num);
}

Document::~Document(){
  std::cout << "Document destroyed" << std::endl;
}