#include <string>
#include <memory>
#include "../document_lib/document.hpp"

class Engine{
 public:
  Engine();

  void OpenDocument(const std::string& path);

  void CreateDocument();

  void SaveDocument(const std::string& path);

  void CreateFigure();

  void DeleteFigure();

  ~Engine();
private:
  std::unique_ptr<Document> doc;
};