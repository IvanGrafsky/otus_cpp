#include "ip_lib.h"

#include <iostream>

void Print(const Ip& ip){
    std::cout << static_cast<uint8_t>(std::get<0>(ip)) << ".";
    std::cout << static_cast<uint8_t>(std::get<1>(ip)) << ".";
    std::cout << static_cast<uint8_t>(std::get<2>(ip)) << ".";
    std::cout << static_cast<uint8_t>(std::get<3>(ip)) << std::endl;
}

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

std::vector<Ip> filter_any(const std::vector<Ip>& ip_pool, uint8_t any_byte){
    std::vector<Ip> result;

    for(const auto& ip : ip_pool){
        if((std::get<0>(ip) == any_byte) ||
            (std::get<1>(ip) == any_byte) ||
            (std::get<2>(ip) == any_byte) ||
            (std::get<3>(ip) == any_byte)){
                result.push_back(ip);
            }

        // for(auto x: ip){
        //     if(x == any_byte){
        //         result.push_back(ip);
        //         break;
        //     }
        // }
    }

    return result;
}