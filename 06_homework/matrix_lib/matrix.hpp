#include <map>
#include <iterator>

class MatrixManager{
  public:
    MatrixManager(size_t* ptr) : ptr_(ptr){

    }

    // void UpdatePos(size_t rank, size_t pos){

    // }

  private:
    size_t* ptr_;
};



// template<typename T, T def, size_t dim>
// class ShadowMatrix{
//   using X = ShadowMatrix<T, def, dim-1>;
//   using MM = MatrixManager;
//  public:
//   ShadowMatrix(MM& mm) : mm_(mm){};

//   X& operator[](size_t pos){
//     auto it = storage_.find(pos);
//     if(it == storage_.end()){
//       storage_.emplace(std::make_pair(pos, X(mm_)));
//     }
//     return storage_[pos];
//   }

//   private:
//     std::map<size_t, ShadowMatrix<T, def, dim - 1>> storage_;
//     MM& mm_;
// };

template<typename T, T def, size_t dim = 1>
class ShadowMatrix{
  using MM = MatrixManager;

  public:
    ShadowMatrix(MM& mm) : mm_(mm){};

    T& operator[](size_t pos){
      auto it = storage_.find(pos);
      if(it == storage_.end()){
        storage_[pos] = def;
      }
      return storage_[pos];
    }

  private:
    std::map<size_t, T> storage_;
    MM& mm_;
};


template<typename T, T def, size_t dim = 2>
class Matrix2{

  using X = ShadowMatrix<T, def, dim-1>;
  using MM = MatrixManager;

  public:
    Matrix2() : size_(0),
                mm_(req_pos){}

    X& operator[](size_t pos){
      auto it = storage_.find(pos);
      if(it == storage_.end()){
        // storage_.insert(pos, mm_);
        storage_.emplace(std::make_pair(pos, ShadowMatrix<T, def, dim-1>(mm_)));
      }
      return storage_[pos];
    }

    size_t size() const {
      return size_;
    }

  private:
    size_t size_;
    size_t req_pos[dim];
    std::map<size_t, X> storage_;
    MM mm_;
};


// template<typename T, T def>
// class HorizCellStorage;

// template<typename T, T def>
// class CleanMe{
//  public:
//   CleanMe(HorizCellStorage<T, def>* s) : storage_(s){}

//   void ExecuteClean(size_t x_pos, size_t y_pos){
//     std::cout << "In CleanMe" << std::endl;
//     x_pos_ = x_pos;
//     y_pos_ = y_pos;
//     storage_->size_--;
//     storage_->clean_ = true;
//     storage_->clean_pos_ = x_pos;
//   }

//   void ChangeSize(){
//     std::cout << "ChangeSize" << std::endl;
//     storage_->IncrementSize();
//   }
//  private:
//   HorizCellStorage<T, def>* storage_;
//   size_t x_pos_;
//   size_t y_pos_;
// };


// template<typename T, T def>
// class Cell{
//  public:
//   Cell(size_t x_pos, size_t y_pos, CleanMe<T, def>& clean) : x_pos_(x_pos),
//                                       y_pos_(y_pos) , clean_(clean),
//                                       value_(def){

//   }

//   operator T() const{
//     return value_;
//   }

//   operator T&(){
//     return value_;
//   }


//   T operator=(T t){
//     std::cout << "In operator=" << std::endl;
//     if(t != def){
//       value_ = t;
//       clean_.ChangeSize();
//       return t;
//     } else {
//       clean_.ExecuteClean(x_pos_, y_pos_);
//       return def;
//     }
//   }

//  private:
//   size_t x_pos_;
//   size_t y_pos_;
//   T value_;
//   const T default_value_ = def;
//   CleanMe<T, def>& clean_;
// };

// template<typename T, T def>
// class HorizCellStorage{

//   friend class CleanMe<T, def>;

//  public:
//   HorizCellStorage() : size_(0), cl(this){}

//   Cell<T, def>& operator[](size_t s){
//     ExecuteCleaning();
//     auto tmp = storage.find(s);
//     if(storage.find(s) != storage.end()){
//       return tmp->second;
//     } else {
//       auto t = storage.emplace(std::make_pair(s, Cell<T, def>(s, 0, cl)));
//       clean_ = true;
//       clean_pos_ = s;
//       return t.first->second;
//     }
//   }

//   size_t size() const{
//     ExecuteCleaning();
//     std::cout << "Internal size " << storage.size() << std::endl;
//     return size_;
//   }

//   auto begin(){
//     ExecuteCleaning();
//     return storage.begin();
//   }

//   auto end(){
//     ExecuteCleaning();
//     return storage.end();
//   }

//  private:
//   void ExecuteCleaning() const {
//     if(clean_) {
//       std::cout << "In execute cleaning" << std::endl;
//       DeleteCell(clean_pos_);
//       clean_ = false;
//     }
//   }

//   mutable bool clean_ = false;
//   mutable size_t clean_pos_ = 0;

//   void DeleteCell(size_t pos) const {
//     std::cout << "In deleting cell" << std::endl;
//     std::cout << "Storage size before " << storage.size() << std::endl;
//     auto it = storage.find(pos);
//     if(it != storage.end()){
//       std::cout << "Found " << std::endl;
//       if(it->second == def){
//         storage.erase(it);
//       }
//     }
//      std::cout << "Storage size after " << storage.size() << std::endl;
//   }

//   void IncrementSize(){
//     size_++;
//   }

//   mutable  size_t size_;
//   CleanMe<T, def> cl;
//   mutable std::map<size_t, Cell<T, def>> storage;
// };
