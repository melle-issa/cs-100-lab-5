#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "base.hpp"

TEST(DivTest, DivEvaluateNonZero) {
    Base *obj1 = new Op(6.0);
    Base *obj2 = new Op(3.0);
    Base* test = new Div(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 2.0);
}
#endif //__DIV_TEST_HPP__
