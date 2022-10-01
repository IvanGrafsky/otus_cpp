#include <cstdlib>
#include <cstring>
#include <iostream>

template <typename T, size_t Size = 100>
class my_allocator{
public:
  using value_type = T;

  my_allocator(){
    mem_start_ptr_ = reinterpret_cast<T*>(malloc(size_ * sizeof(T)));
    free_offset_ = 0;
    if(mem_start_ptr_ == NULL){
      std::cout << "Fail in getting " << sizeof(T) * size_ << " bytes" << std::endl;
    } else {
      std::cout << "Got " << sizeof(T) * size_ << " bytes" << std::endl;
    }
  }

  my_allocator(const my_allocator<T> &al){
    std::cout << "In copy constructor " << std::endl;
    this->mem_start_ptr_ = reinterpret_cast<T*>(malloc(size_ * sizeof(T)));
    if(this->mem_start_ptr_ == NULL){
      std::cout << "Fail in getting " << sizeof(T) * size_ << " bytes" << std::endl;
    } else {
      std::cout << "Got " << sizeof(T) * size_ << " bytes" << std::endl;
      std::memcpy(reinterpret_cast<void *>(this->mem_start_ptr_),
                  reinterpret_cast<void *>(al.mem_start_ptr_),
                  al.free_offset_ * sizeof(T));
      this->free_offset_ = al.free_offset_;
    }
  }

  template<class U>
  struct rebind {
    using other = my_allocator<U>;
  };

  T* allocate(std::size_t n){
    T* result;
    if(free_offset_ + n > size_) {
      std::cout << "Fail in allocation " << sizeof(T) * n << " bytes" << std::endl;
      throw std::bad_alloc();
      result = NULL;
    } else {
      result = mem_start_ptr_ + free_offset_;
      free_offset_ += n;
      std::cout << "Allocated " << sizeof(T) * n << " bytes" << std::endl;
    }
    return result;
  }

  void deallocate(T* p, std::size_t n){
    (void)p;
    (void)n;
    std::cout << "Deallocating " << sizeof(T) * n << " bytes" << std::endl;
  }

  ~my_allocator(){
    std::cout << "In destructor" << std::endl;
    if(mem_start_ptr_ != NULL) {
      free(mem_start_ptr_);
      std::cout << "Freed " << sizeof(T) * size_ << " bytes" << std::endl;
    }
  }
private:
  static constexpr size_t size_ = Size;
  T* mem_start_ptr_;
  size_t free_offset_;
};