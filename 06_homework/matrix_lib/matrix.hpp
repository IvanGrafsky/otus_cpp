#include <map>
#include <iterator>

// template<typename T, T t>
// class Matrix{
//  public:
//   Matrix() : size_(0u){}

//   ~Matrix(){

//   }

//   T operator[](size_t value){
//     return default_value_;
//   }

//   size_t size() const {
//     return size_;
//   }

//   bool operator==(T u){
//     return u == default_value_;
//   }

//  private:
//   std::map<size_t, std::map<size_t, T>> storage_;
//   size_t size_;
//   T default_value_ = t;
// };

// template<typename T, T t>
// class HorizStorage{
//  public:
//   HorizStorage() : default_value_(t){}

//   T& operator[](size_t s){
//     auto tmp = storage.find(s);
//     if(storage.find(s) != storage.end()){

//       return tmp->second;
//     }
//     return default_value_;
//   }

//   // iterator begin(){
//   //   return storage.begin();
//   // }

//   // iterator end(){
//   //   return storage.end();
//   // }

//  private:
//   T default_value_;
//   std::map<size_t, T> storage;
// };

template<typename T, T def>
class HorizCellStorage;

template<typename T, T def>
class CleanMe{
 public:
  CleanMe(HorizCellStorage<T, def>* s) : storage_(s){}

  void ExecuteClean(size_t x_pos, size_t y_pos){
    std::cout << "In CleanMe" << std::endl;
    x_pos_ = x_pos;
    y_pos_ = y_pos;
    storage_->size_--;
    storage_->clean_ = true;
    storage_->clean_pos_ = x_pos;
  }

  void ChangeSize(){
    std::cout << "ChangeSize" << std::endl;
    storage_->IncrementSize();
  }
 private:
  HorizCellStorage<T, def>* storage_;
  size_t x_pos_;
  size_t y_pos_;
};


template<typename T, T def>
class Cell{
 public:
  Cell(size_t x_pos, size_t y_pos, CleanMe<T, def>& clean) : x_pos_(x_pos),
                                      y_pos_(y_pos) , clean_(clean),
                                      value_(def){

  }

  operator T() const{
    return value_;
  }

  operator T&(){
    return value_;
  }


  T operator=(T t){
    std::cout << "In operator=" << std::endl;
    if(t != def){
      value_ = t;
      clean_.ChangeSize();
      return t;
    } else {
      clean_.ExecuteClean(x_pos_, y_pos_);
      return def;
    }
  }


 private:
  size_t x_pos_;
  size_t y_pos_;
  T value_;
  const T default_value_ = def;
  CleanMe<T, def>& clean_;
};

template<typename T, T def>
class HorizCellStorage{

  friend class CleanMe<T, def>;

 public:
  HorizCellStorage() : size_(0), cl(this){}

  Cell<T, def>& operator[](size_t s){
    ExecuteCleaning();
    auto tmp = storage.find(s);
    if(storage.find(s) != storage.end()){
      return tmp->second;
    } else {
      auto t = storage.emplace(std::make_pair(s, Cell<T, def>(s, 0, cl)));
      return t.first->second;
    }
  }

  size_t size() const{
    ExecuteCleaning();
    return size_;
  }

  auto begin(){
    ExecuteCleaning();
    return storage.begin();
  }

  auto end(){
    ExecuteCleaning();
    return storage.end();
  }

 private:
  void ExecuteCleaning() const {
    if(clean_) {
      std::cout << "In execute cleaning" << std::endl;
      DeleteCell(clean_pos_);
      clean_ = false;
    }
  }

  mutable bool clean_ = false;
  mutable size_t clean_pos_ = 0;

  void DeleteCell(size_t pos) const {
    std::cout << "In deleting cell" << std::endl;
    auto it = storage.find(pos);
    if(it != storage.end()){
      std::cout << "Found " << std::endl;
      storage.erase(it);
    }
  }

  void IncrementSize(){
    size_++;
  }

  mutable  size_t size_;
  CleanMe<T, def> cl;
  mutable std::map<size_t, Cell<T, def>> storage;
};
