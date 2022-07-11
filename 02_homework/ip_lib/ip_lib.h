#pragma once

#include <string>
#include <tuple>
#include <vector>

using Ip = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;

Ip get_ip(const std::string &str);
void Print(const Ip& ip);
void Print(const std::vector<Ip>& ip);

std::vector<Ip> filter(const std::vector<Ip>& ip_pool, uint8_t first_byte);
std::vector<Ip> filter(const std::vector<Ip>& ip_pool, uint8_t first_byte, uint8_t second_byte);
std::vector<Ip> filter_any(const std::vector<Ip>& ip_pool, uint8_t any_byte);