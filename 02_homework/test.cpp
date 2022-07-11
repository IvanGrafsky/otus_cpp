#include <gtest/gtest.h>
#include <ip_lib.h>

TEST(IpLibTest, CheckSomething) {
  ASSERT_TRUE(1);
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}