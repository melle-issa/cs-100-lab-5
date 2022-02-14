#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "add.hpp"
#include "base.hpp"
#include <string>

TEST(DivTest, DivEvaluateNonZero) {
    Base *obj1 = new Op(6.0);
    Base *obj2 = new Op(3.0);
    Base *test = new Div(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 2.0);
    EXPECT_EQ(test->stringify(), "(6.000000/3.000000)");
}

TEST(DivTest, DivEvaluateZeroDen) { // zero as the denominator
    Base *obj1 = new Op(6.0);
    Base *obj2 = new Op(0.0);
    EXPECT_THROW(Div(obj1,obj2), std::invalid_argument);
}

TEST(DivTest, DivEvaluateDecimal) {
   Base *obj1 = new Op(6.75);
   Base *obj2 = new Op(2.25);
   Base *test = new Div(obj1,obj2);
   EXPECT_EQ(test->evaluate(), 3.0);
   EXPECT_EQ(test->stringify(), "(6.750000/2.250000)");
}

TEST(DivTest, DivEvaluateZeroNum) { // zero as the numerator
   Base *obj1 = new Op(0.000);
   Base *obj2 = new Op(9.0);
   Base *test = new Div(obj1,obj2);
   EXPECT_EQ(test->evaluate(), 0.0);
   EXPECT_EQ(test->stringify(), "(0.000000/9.000000)");
}

TEST(DivTest, DivEvaluateTwoZeros) { // error expected with 0 as denominator
   Base *obj1 = new Op(0.000);
   Base *obj2 = new Op(0.0);
   EXPECT_THROW(Div(obj1,obj2), std::invalid_argument);
}

TEST(DivTest, DivEvaluateLongNum) {
   Base *obj1 = new Op(1.999999);
   Base *obj2 = new Op(1.0);
   Base *test = new Div(obj1,obj2);
   EXPECT_EQ(test->evaluate(), 1.999999);
   EXPECT_EQ(test->stringify(), "(1.999999/1.000000)");
}

TEST(DivTest, DivEvaluateLongerNum) { // stringify rounds past 6 decimal points
   Base *obj1 = new Op(1.9999999);
   Base *obj2 = new Op(1.0);
   Base *test = new Div(obj1,obj2);
   EXPECT_EQ(test->evaluate(), 1.9999999);
   EXPECT_EQ(test->stringify(), "(2.000000/1.000000)");
}

TEST(DivTest, DivEvaluateNegNum) {
   Base *obj1 = new Op(-10.0);
   Base *add1 = new Op(2.0); Base *add2 = new Op(3.000);
   Base *obj2 = new Add(add1, add2); // testing using different objects
   Base *test = new Div(obj1,obj2);
   EXPECT_EQ(test->evaluate(), -2.0 );
   EXPECT_EQ(test->stringify(), "(-10.000000/(2.000000+3.000000))");
}
#endif //__DIV_TEST_HPP__
