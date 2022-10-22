class IFigure {
 public:
  IFigure() = default;

  virtual void About() = 0;
};


class Point: public IFigure {
 public:
  void About() override;
};

class Line: public IFigure {
 public:
  void About() override;
};

class Rectangle: public IFigure {
 public:
  void About() override;
};

class Circle: public IFigure {
 public:
  void About() override;
};