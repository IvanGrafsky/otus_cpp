#include <vector>
#include <memory>
#include "../figure_lib/figure.hpp"

class Document{
 public:
  Document();

  Document(const std::string& path);

  void SaveDocument(const std::string& path);

  void AddFigure(IFigure& figure);

  void DeleteFigure(size_t num);

  ~Document();
 private:
  std::vector<std::unique_ptr<IFigure>> figures;
};