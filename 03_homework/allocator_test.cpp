#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include "logging_allocator.cpp"
#include "my_allocator.cpp"


size_t factorial(size_t n){
	if(n <= 1){
		return 1;
	}

	size_t result = 1;

	for(size_t i = 2; i <= n; i++){
		result *= i;
	}

	return result;
}


template<class T>
void Print(const T& container){
	for(const auto& x : container){
		std::cout << x.first << ' ' << x.second << std::endl;
	}
}


int main(){
  std::map<int, int> dict_0;

	for(int i = 0; i < 10; i++) {
		dict_0[i] = factorial(i);
	}

	std::map<int, int, std::less<int>, my_allocator<std::pair<const int, int>>> dict_1;

	for(int i = 0; i < 10; i++) {
		dict_1[i] = factorial(i);
	}

	std::cout << "My allocator" << std::endl;
	Print(dict_1);

  return 0;
}