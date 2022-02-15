#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateDouble) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateString){
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, OpEvaluateNegative){
    Op* test = new Op(-9);
    EXPECT_EQ(test->evaluate(), -9);
}
TEST(OpTest, OpRounding){
    Op* test = new Op(9.0000002);
    EXPECT_EQ(test->stringify(), "9.000000");
}

#endif //__OP_TEST_HPP__
