#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include "allocator_lib/logging_allocator.cpp"
#include "allocator_lib/my_allocator.cpp"
#include "my_vector_lib/my_vector.cpp"


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

template<typename U, typename S>
std::ostream& operator<<(std::ostream& os, const std::pair<U, S>& t){
	os << t.first << ' ' << t.second;
	return os;
}


template<class T>
void Print(const T& container){
	for(const auto& x : container){
		std::cout << x << std::endl;
	}
}

int main(){
	{
		std::vector<int, logging_allocator<int>> vect(10);
	}
	std::cout << "=========================" << std::endl;
	{
		my_vector<int, logging_allocator<int>> vect(10);
	}
	std::cout << "=========================" << std::endl;

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

	my_vector<int, my_allocator<int, 10>> vect;

	for(int i = 0; i < 10; i++){
		vect.push_back(i);
	}

	Print(vect);

  return 0;
}