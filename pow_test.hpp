#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "op.hpp"

TEST(PowTest, PowEvaluateNonZero) {
    Base *obj1 = new Op(2.0);
    Base *obj2 = new Op(1.0);
    Base *test = new Pow(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 2.0);
}

TEST(PowTest, PowStringify){
    Base *obj1 = new Op(2.0);
    Base *obj2 = new Op(1.0);
    Base *test = new Pow(obj1, obj2);
    EXPECT_EQ(test->stringify(), "(2.000000**1.000000)");
}

TEST(PowTest, PowEvaluateZero){
    Base *obj1 = new Op(4.0);
    Base *obj2 = new Op(0.0);
    Base *test = new Pow(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 1.0);
}
TEST(PowTest, PowEvaluateNegative){
    Base *obj1 = new Op(-1.0);
    Base *obj2 = new Op(2.0);
    Base *test = new Pow(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 1.0);
}
TEST(PowTest, PowWithSub){
    Base *obj1 = new Op(2.0);
    Base *obj2 = new Op(1.0);
    Base *obj3 = new sub(obj1, obj2);
    Base *test = new Pow(obj1, obj3);
    EXPECT_EQ(test->evaluate(), 2.0);
}
TEST(PowTest, SquareRoot){
    Base *obj1 = new Op(0.5);
    Base *obj2 = new Op(25.0);
    Base *test = new Pow(obj2, obj1);
    EXPECT_EQ(test->evaluate(), 5.0);
}
TEST(PowTest, DoublePow){
    Base *obj1 = new Op(2.0);
    Base *firstPow = new Pow(obj1, obj1);
    Base *test = new Pow(firstPow, obj1);
    EXPECT_EQ(test->evaluate(), 16.0);
}
#endif
