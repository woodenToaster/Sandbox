#include <gtest/gtest.h>
#include "../../include/Tile.h"

TEST(testTile, can create) {
  Tile tile = Tile();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}