#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "sub.hpp"
#include "op.hpp"

TEST(SubTest, SubEvaluateNonZero) {
    Base *obj1 = new Op(2.0);
    Base *obj2 = new Op(1.0);
    Base *test = new sub(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 1.0);
}

TEST(SubTest, SubEvaluateString){
    Base *obj1 = new Op(2.0);
    Base *obj2 = new Op(1.0);
    Base *test = new sub(obj1, obj2);
    EXPECT_EQ(test->stringify(), "1.000000");
}

TEST(SubTest, SubEvaluateNegative){
    Base *obj1 = new Op(1.0);
    Base *obj2 = new Op(2.0);
    Base *test = new sub(obj1, obj2);
    EXPECT_EQ(test->stringify(), -1);
}

#endif
