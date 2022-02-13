#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "base.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Base *obj1 = new Op(1.0);
    Base *obj2 = new Op(2.0);
    Base *test = new Mult(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 2.0);
    EXPECT_EQ(test->stringify(), "(1.000000*2.000000)");
}

TEST(MultTest, MultEvaluateZero) {
    Base *obj1 = new Op(1.0);
    Base *obj2 = new Op(0.0);
    Base *test = new Mult(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 0.0);
    EXPECT_EQ(test->stringify(), "(1.000000*0.000000)");
}

TEST(MultTest, MultEvaluateDecimal){
    Base *obj1 = new Op(1.5);
    Base *obj2 = new Op(2.5);
    Base *test = new Mult(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 3.75);
    EXPECT_EQ(test->stringify(), "(1.500000*2.500000)");
}
#endif //__MULT_TEST_HPP__
