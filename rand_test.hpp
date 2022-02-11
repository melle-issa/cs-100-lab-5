#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"

TEST(RandTest, RandEvaluateNonZero) {
    Rand* test = new Rand();
    double *temp = test->getValue(); 
    EXPECT_TRUE(temp != 100.0);
}


#endif
