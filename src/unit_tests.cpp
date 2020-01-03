#include "gtest/gtest.h"

#include "stack.h"

TEST(NormalExecutionPath, copy_an_empty_stack) {
    Stack y;
    Stack x = y;
    assert(y.count() == 0);    

    EXPECT_FALSE(0 == x.count());
}

TEST(NormalExecutionPath, copy_with_assignment) {
    Stack a, b;
    a.push(0);
    a = b;
    printf("%u\n", a.count());

    EXPECT_TRUE(1 == a.count());
}

TEST(ExceptionExecutionPath, copy_with_assignment) {
    try {
        Stack x, y;
        y = x;
    }
    catch (const std::exception& err) {
        ASSERT_STREQ("error message", err.what());
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}