#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "rand.hpp"
#include "op.hpp"

TEST(RandTest, RandEvaluateNonZero) {
    Rand* test = new Rand();
    double temp = test->getVal(); 
    EXPECT_TRUE(temp != 100.0);
}

#endif
