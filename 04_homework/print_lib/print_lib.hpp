#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <type_traits>


/// <summary>
/// prints IP which is stored in integer data types
/// </summary>
/// <typeparam name="T">The Type of the data which must be integer.</typeparam>
/// <param name="t">Data of IP address.</param>
/// <returns>void</returns>
template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
void print_ip(T t){
  std::string result;
  unsigned char* u = reinterpret_cast<unsigned char*>(&t);
  for(size_t i = sizeof(T); i > 0; i--){
    result += std::to_string(*(u + i - 1)) + ((i == 1) ? "" : ".");
  }
  std::cout << result << std::endl;
}

/// <summary>
/// prints IP which is stored in string
/// </summary>
/// <typeparam name="T">The Type of the data which must be string.</typeparam>
/// <param name="t">string of IP address.</param>
/// <returns>void</returns>
template<typename U, std::enable_if_t<std::is_same<char const*, decltype(std::declval<U>().c_str())>::value, bool> = true>
void print_ip(const U& container){
  std::cout << container.c_str() << std::endl;
}

/// <summary>
/// prints IP which is stored in container data types
/// </summary>
/// <typeparam name="T">The Type of the data which must be container.</typeparam>
/// <param name="t">Data of IP address.</param>
/// <returns>void</returns>
template<typename U, std::enable_if_t<!std::is_same<char, typename U::value_type>::value, bool> = true>
void print_ip(const U& container) {
  for(auto t = container.cbegin(); t != container.cend(); t = next(t)) {
    std::cout << *t << ((next(t) != container.cend()) ? "." : "\n");
  }
}

/// <summary>
/// prints IP which is stored in tuple data type
/// </summary>
/// <typeparam name="T">The Type of the data which must be tuple.</typeparam>
/// <param name="t">Data of IP address.</param>
/// <returns>void</returns>
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