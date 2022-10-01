#include <cstdlib>
#include <cstring>
#include <iostream>


template<class T, class Allocator = std::allocator<T>>
class my_vector{
public:
  my_vector(size_t count = 1) : size_(count) {
    block_ptr_ = al.allocate(size_);
    if(block_ptr_ == NULL){
      std::cout << "Fail in getting " << sizeof(T) * size_ << " bytes" << std::endl;
    } else {
      std::cout << "Got " << sizeof(T) * size_ << " bytes" << std::endl;
    }
  }

  void push_back(T t){
    if(amount_ == size_) {
      T* new_block_ptr = al.allocate(2 * size_);
      std::memcpy(new_block_ptr, block_ptr_, amount_);
      al.deallocate(block_ptr_, size_);
      block_ptr_ = new_block_ptr;
    }
    *(block_ptr_ + amount_) = t;
    amount_++;
  }

  T* begin() const{
    return block_ptr_;
  }

  T* end() const{
    return block_ptr_ + amount_;
  }

  const T& operator[](const int n){
    return *(block_ptr_ + n);
  }

private:
  T* block_ptr_;
  size_t size_ = 1;
  size_t amount_ = 0;
  Allocator al;
};