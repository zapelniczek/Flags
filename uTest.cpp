#include <gtest/gtest.h>
#include "header.h"

TEST(uTest, smallTest)
{
    std::vector<int> vec {1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
    solution(vec);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}