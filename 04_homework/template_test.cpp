#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <type_traits>

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
void print_ip(T t){
  std::string result;
  unsigned char* u = reinterpret_cast<unsigned char*>(&t);
  for(size_t i = sizeof(T); i > 0; i--){
    result += std::to_string(*(u + i - 1)) + ((i == 1) ? "" : ".");
  }
  std::cout << result << std::endl;
}

template<typename U, std::enable_if_t<std::is_same<char const*, decltype(std::declval<U>().c_str())>::value, bool> = true>
void print_ip(const U& container){
  std::cout << container.c_str() << std::endl;
}

template<typename U, std::enable_if_t<!std::is_same<char, typename U::value_type>::value, bool> = true>
void print_ip(const U& container) {
  for(auto t = container.cbegin(); t != container.cend(); t = next(t)) {
    std::cout << *t << ((next(t) != container.cend()) ? "." : "\n");
  }
}

template<typename ...Ts, std::enable_if_t<
                std::is_same<typename std::tuple_size<std::tuple<Ts...>>::value_type, std::size_t>::value, bool> = true>
void print_ip(const std::tuple<Ts...> tup){
  std::apply
    (
        [](Ts const&... tupleArgs)
        {
            std::size_t n{0};
            ((std::cout << tupleArgs << (++n != sizeof...(Ts) ? "." : "\n")), ...);
        }, tup
    );
}


int main(){
  print_ip( int8_t{-1} ); // 255
  print_ip( int16_t{0} ); // 0.0
  print_ip( int32_t{2130706433} ); // 127.0.0.1
  print_ip( int64_t{8875824491850138409} );// 123.45.67.89.101.112.131.41
  print_ip( std::string{"Hello, World!"} ); // Hello, World!
  print_ip( std::vector<int>{100, 200, 300, 400} ); // 100.200.300.400
  print_ip( std::list<short>{400, 300, 200, 100} ); // 400.300.200.100

  print_ip( std::make_tuple(123, 456, 789, 0) ); // 123.456.789.0

  return 0;
}