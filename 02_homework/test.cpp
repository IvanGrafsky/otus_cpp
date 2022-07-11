#include <algorithm>
#include <fstream>
#include <gtest/gtest.h>
#include <ip_lib.h>

TEST(IpLibTest, CheckGetIP) {
  ASSERT_EQ(Ip(113, 162, 145, 156),	 get_ip("113.162.145.156	111	0"));
  ASSERT_EQ(Ip(157, 39, 22, 224), get_ip("157.39.22.224	5	6"));
  ASSERT_EQ(Ip(79, 180, 73, 190), get_ip("79.180.73.190	2	1"));
  ASSERT_EQ(Ip(179, 210, 145, 4), get_ip("179.210.145.4	22	0"));
  ASSERT_EQ(Ip(219, 102, 120, 135), get_ip("219.102.120.135	486	0"));
  ASSERT_EQ(Ip(67, 232, 81, 208), get_ip("67.232.81.208	1	0"));
  ASSERT_EQ(Ip(85, 254, 10, 197), get_ip("85.254.10.197	0	7"));
  ASSERT_EQ(Ip(23, 240, 215, 189), get_ip("23.240.215.189	6	0"));
}


TEST(IpLibTest, CheckFilter) {
  std::fstream test_file;

  test_file.open("../ip_filter.tsv", std::fstream::in);

  std::vector<Ip> ip_pool;

  for(std::string line; std::getline(test_file, line);){
    ip_pool.push_back(get_ip(line));
  }

  std::sort(ip_pool.begin(), ip_pool.end(), [](Ip lhs, Ip rhs){
    return lhs > rhs;
  });

  ASSERT_EQ(Ip(1,1,234,8), ip_pool[ip_pool.size() - 1]);
  ASSERT_EQ(Ip(1,29,168,152), ip_pool[ip_pool.size() - 2]);
  ASSERT_EQ(Ip(1,70,44,170), ip_pool[ip_pool.size() - 3]);

  ASSERT_EQ(Ip(222,173,235,246), ip_pool[0]);
  ASSERT_EQ(Ip(222,130,177,64), ip_pool[1]);
  ASSERT_EQ(Ip(222,82,198,61), ip_pool[2]);

  std::vector<Ip> filter_1 = filter(ip_pool, 1);

  ASSERT_EQ(filter_1.size(), 5);
  ASSERT_EQ(Ip(1,231,69,33), filter_1[0]);
  ASSERT_EQ(Ip(1,87,203,225), filter_1[1]);
  ASSERT_EQ(Ip(1,70,44,170), filter_1[2]);
  ASSERT_EQ(Ip(1,29,168,152), filter_1[3]);
  ASSERT_EQ(Ip(1,1,234,8), filter_1[4]);

  std::vector<Ip> filter_2 = filter(ip_pool, 46, 70);

  ASSERT_EQ(filter_2.size(), 4);

  ASSERT_EQ(Ip(46,70,225,39), filter_2[0]);
  ASSERT_EQ(Ip(46,70,147,26), filter_2[1]);
  ASSERT_EQ(Ip(46,70,113,73), filter_2[2]);
  ASSERT_EQ(Ip(46,70,29,76), filter_2[3]);

  std::vector<Ip> filter_3 = filter_any(ip_pool, 46);

  ASSERT_EQ(filter_3.size(), 34);

  ASSERT_EQ(Ip(186,204,34,46), filter_3[0]);
  ASSERT_EQ(Ip(186,46,222,194), filter_3[1]);
  ASSERT_EQ(Ip(185,46,87,231), filter_3[2]);
  ASSERT_EQ(Ip(185,46,86,132), filter_3[3]);
  ASSERT_EQ(Ip(46,55,46,98), filter_3[filter_3.size() - 4]);
  ASSERT_EQ(Ip(46,49,43,85), filter_3[filter_3.size() - 3]);
  ASSERT_EQ(Ip(39,46,86,85), filter_3[filter_3.size() - 2]);
  ASSERT_EQ(Ip(5,189,203,46), filter_3[filter_3.size() - 1]);

  test_file.close();
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}