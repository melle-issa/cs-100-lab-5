#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "base.hpp"
#include <string>

TEST(DivTest, DivEvaluateNonZero) {
    Base *obj1 = new Op(6.0);
    Base *obj2 = new Op(3.0);
    Base *test = new Div(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 2.0);
    EXPECT_EQ(test->stringify(), "(6.000000/3.000000)");
}

TEST(DivTest, DivEvaluateZero) {
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
#endif //__DIV_TEST_HPP__
