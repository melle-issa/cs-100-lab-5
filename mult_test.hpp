#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "base.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Base *obj1 = new Op(1.0);
    Base *obj2 = new Op(2.0);
    Base* test = new Mult(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 2.0);
}

#endif //__MULT_TEST_HPP__
