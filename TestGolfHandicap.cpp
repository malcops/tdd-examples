#include "GolfHandicap.hpp"
#include "gtest/gtest.h"

TEST(TestGolfHandicap, initialize){
    GolfHandicap rb = GolfHandicap();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
