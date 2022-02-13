#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "pow.hpp"
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

#endif
