#include <iostream>
#include <cstdlib>


template <typename T>
class logging_allocator{
public:
  using value_type = T;

  logging_allocator(){
    std::cout << "In constructor" << std::endl;
  }

  logging_allocator(const logging_allocator<T>& ){
    std::cout << "In copy constructor" << std::endl;
  }

  T* allocate(std::size_t n){
    T* result = reinterpret_cast<T*>(malloc(sizeof(T) * n));
    if(result == NULL){
      std::cout << "Fail in allocation " << sizeof(T) * n << " bytes" << std::endl;
    } else {
      std::cout << "Allocated " << sizeof(T) * n << " bytes" << std::endl;
    }
    return result;
  }

  template<class U>
  struct rebind {
    using other = logging_allocator<U>;
  };

  void deallocate(T* p, std::size_t n){
    free(p);
    std::cout << "Deallocating " << sizeof(T) * n << " bytes" << std::endl;
  }

  ~logging_allocator(){
    std::cout << "In destructor" << std::endl;
  }
};