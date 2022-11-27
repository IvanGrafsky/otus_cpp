#include <iostream>
#include <map>
// #include "matrix_lib/matrix.hpp"

class MatrixManager{
  public:
    MatrixManager(size_t* ptr) : ptr_(ptr){

    }

    void UpdatePos(size_t rank, size_t pos){
      *(ptr_+(rank-1)) = pos;
    }

  private:
    size_t* ptr_;
};


template<typename T, T def, size_t dim = 1>
class ShadowMatrix{
  using MM = MatrixManager;

  public:
    ShadowMatrix(){
      std::cout << "default constr" << std::endl;
    }


    ShadowMatrix(MM* mm) : mm_(mm){};

    T& operator[](size_t pos){
      mm_->UpdatePos(dim, pos);
      auto it = storage_.find(pos);
      if(it == storage_.end()){
        storage_[pos] = def;
      }
      return storage_[pos];
    }

  private:
    std::map<size_t, T> storage_;
    MM* mm_;
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
        storage_.emplace(std::make_pair(pos, ShadowMatrix<T, def, dim-1>(&mm_)));
      }
      return storage_[pos];
    }

    size_t size() {
      CheckCell();
      return size_;
    }

  private:
    void CheckCell(){
      if(this->operator[](req_pos[1]).operator[](req_pos[0]) == def){
        std::cout << "Delete cell" << req_pos[1] << " " << req_pos[0] << std::endl;
      }
    }


    size_t size_;
    size_t req_pos[dim];
    std::map<size_t, X> storage_;
    MM mm_;
};

int main(){
  std::cout << "Hello" << std::endl;

  {
    Matrix2<int, -1> m;

    std::cout << m[0][0] << std::endl;
    std::cout << m[0][1] << std::endl;

    std::cout << m.size() << std::endl;
   }

  // Matrix<int, -1> m;

  // std::cout << m.size() << std::endl;

  // std::cout << (m == -1) << std::endl;

  // HorizStorage<int, -1> h;

  // h[0] = 100;

  // std::cout << h[0] << std::endl;

  // h[0] = -1;

  // CleanMe cl;

  // Cell<int, -1> c(2, 3, cl);

  // c = 5;

  // c = -1;

  // HorizCellStorage<int, -1> cellstorage;

  // std::cout << "Size " << cellstorage.size() << std::endl;

  // cellstorage[0];

  // std::cout << "Size " << cellstorage.size() << std::endl;

  // std::cout << cellstorage[0] << std::endl;

  // auto a = cellstorage[0];

  // std::cout << "a: " << a << std::endl;

  // cellstorage[0] = 5;

  // std::cout << "Size " << cellstorage.size() << std::endl;

  // std::cout << cellstorage[0] << std::endl;

  // cellstorage[0] = -1;

  // std::cout << "Size " << cellstorage.size() << std::endl;

  // std::cout << cellstorage[0] << std::endl;

  // std::cout << "Size " << cellstorage.size() << std::endl;


  // cellstorage[5] = 5;
  // cellstorage[10] = 10;
  // cellstorage[15] = 15;
  // cellstorage[16] = 5;
  // cellstorage[16] = -1;

  // std::cout << "Size " << cellstorage.size() << std::endl;

  // for(auto a : cellstorage){
  //   int x, y;
  //   std::tie(x,y) = a;
  //   std::cout << x << " " << y << std::endl;
  // }

  return 0;
}