#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "base.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Mult* test = new Mult(1,2);
    EXPECT_EQ(test->evaluate(), 2.0);
}

#endif //__MULT_TEST_HPP__
