#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
// #include <gtest/gtest.h>



// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

// int main(int argc, char const *argv[])
// {
//     try
//     {
//         std::vector<std::vector<std::string> > ip_pool;

//         for(std::string line; std::getline(std::cin, line);)
//         {
//             std::vector<std::string> v = split(line, '\t');
//             ip_pool.push_back(split(v.at(0), '.'));
//         }

//         // TODO reverse lexicographically sort

//         for(std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
//         {
//             for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
//             {
//                 if (ip_part != ip->cbegin())
//                 {
//                     std::cout << ".";

//                 }
//                 std::cout << *ip_part;
//             }
//             std::cout << std::endl;
//         }

//         // 222.173.235.246
//         // 222.130.177.64
//         // 222.82.198.61
//         // ...
//         // 1.70.44.170
//         // 1.29.168.152
//         // 1.1.234.8

//         // TODO filter by first byte and output
//         // ip = filter(1)

//         // 1.231.69.33
//         // 1.87.203.225
//         // 1.70.44.170
//         // 1.29.168.152
//         // 1.1.234.8

//         // TODO filter by first and second bytes and output
//         // ip = filter(46, 70)

//         // 46.70.225.39
//         // 46.70.147.26
//         // 46.70.113.73
//         // 46.70.29.76

//         // TODO filter by any byte and output
//         // ip = filter_any(46)

//         // 186.204.34.46
//         // 186.46.222.194
//         // 185.46.87.231
//         // 185.46.86.132
//         // 185.46.86.131
//         // 185.46.86.131
//         // 185.46.86.22
//         // 185.46.85.204
//         // 185.46.85.78
//         // 68.46.218.208
//         // 46.251.197.23
//         // 46.223.254.56
//         // 46.223.254.56
//         // 46.182.19.219
//         // 46.161.63.66
//         // 46.161.61.51
//         // 46.161.60.92
//         // 46.161.60.35
//         // 46.161.58.202
//         // 46.161.56.241
//         // 46.161.56.203
//         // 46.161.56.174
//         // 46.161.56.106
//         // 46.161.56.106
//         // 46.101.163.119
//         // 46.101.127.145
//         // 46.70.225.39
//         // 46.70.147.26
//         // 46.70.113.73
//         // 46.70.29.76
//         // 46.55.46.98
//         // 46.49.43.85
//         // 39.46.86.85
//         // 5.189.203.46
//     }
//     catch(const std::exception &e)
//     {
//         std::cerr << e.what() << std::endl;
//     }

//     return 0;
// }


using Ip = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;

Ip get_ip(const std::string &str){
    const char point = '.';
    const uint8_t ip_byte_num = 4;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(point);

    int ip_part[ip_byte_num];

    for(size_t i = 0; i < ip_byte_num; i++){
        ip_part[i] = atoi(str.substr(start, stop - start).c_str());

        start = stop + 1;
        stop = str.find_first_of(point, start);
    }

    return Ip(ip_part[0], ip_part[1], ip_part[2], ip_part[3]);
}

// TEST(IpFilter, GetIp) {
//   ASSERT_TRUE(1);
// }

void Print(const Ip& ip){
    std::cout << static_cast<uint8_t>(std::get<0>(ip)) << ".";
    std::cout << static_cast<uint8_t>(std::get<1>(ip)) << ".";
    std::cout << static_cast<uint8_t>(std::get<2>(ip)) << ".";
    std::cout << static_cast<uint8_t>(std::get<3>(ip)) << std::endl;
}

std::vector<Ip> filter(const std::vector<Ip>& ip_pool, uint8_t first_byte);
std::vector<Ip> filter(const std::vector<Ip>& ip_pool, uint8_t first_byte, uint8_t second_byte);
std::vector<Ip> filter_any(const std::vector<Ip>& ip_pool, uint8_t any_byte);


std::vector<Ip> filter(const std::vector<Ip>& ip_pool, uint8_t first_byte){
    std::vector<Ip> result;

    for(const auto& ip : ip_pool){
        if(std::get<0>(ip) == first_byte){
            result.push_back(ip);
        }
    }

    return result;
}

std::vector<Ip> filter(const std::vector<Ip>& ip_pool, uint8_t first_byte, uint8_t second_byte){
    std::vector<Ip> result;

    for(const auto& ip : ip_pool){
        if((std::get<0>(ip) == first_byte) && (std::get<1>(ip) == second_byte)){
            result.push_back(ip);
        }
    }

    return result;
}

// std::vector<Ip> filter_any(const std::vector<Ip>& ip_pool, uint8_t any_byte){
//     std::vector<Ip> result;


//     for(size_t i = 0; i < 4; i++){

//     }
//     // for(const auto& ip : ip_pool){

//     // }

//     return result;
// }

int main(int argc, char **argv){
    //::testing::InitGoogleTest(&argc, argv);

    Ip a;

    a = get_ip("92.168.1.145 8 3");
    Print(a);

    a = get_ip("117.241.3.153	2	4");
    Print(a);
    a = get_ip("86.146.190.166	1	0");
    Print(a);
    a = get_ip("68.60.148.11	1	0");
    Print(a);
    a = get_ip("89.146.70.220	0	1");
    Print(a);

    return 0;//RUN_ALL_TESTS();
}


// get ip from string
// sort ip in reverse
// filter ip



