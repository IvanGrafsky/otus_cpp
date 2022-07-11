#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ip_lib.h>


int main()
{
    try
    {
        std::vector<Ip> ip_pool;
        std::vector<Ip> filter_result;

        for(std::string line; std::getline(std::cin, line);){
            ip_pool.push_back(get_ip(line));
        }

        std::sort(ip_pool.begin(), ip_pool.end(), [](Ip lhs, Ip rhs){
            return lhs > rhs;
        });

        Print(ip_pool);

        filter_result = filter(ip_pool, 1);
        Print(filter_result);

        filter_result = filter(ip_pool, 46, 70);
        Print(filter_result);

        filter_result = filter_any(ip_pool, 46);
        Print(filter_result);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}




