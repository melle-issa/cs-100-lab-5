#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "add.hpp"
#include "op.hpp"
#include "sub.hpp"

TEST(RandTest, RandEvaluateNonZero) {
    Rand* test = new Rand();
    double temp = test->getVal(); 
    EXPECT_TRUE(temp != 100.0);
}

TEST(RandTest, RandEvaluateString){
    Rand* test = new Rand();
    EXPECT_TRUE(test->stringify() != "");
}

TEST(RandTest, RandEvaluateNegative){
    Rand* test = new Rand();
    EXPECT_TRUE(test->evaluate() >= 0);
}
TEST(RandTest, RandSubtraction){
    Rand* rand = new Rand();
    Base* obj1 = new Op(0.0);
    Base* test = new sub(rand, obj1);
    EXPECT_TRUE(test->evaluate() == rand->evaluate());
}
TEST(RandTest, LowerBounds){
    Rand* test = new Rand();
    EXPECT_TRUE(test-> evaluate() >= 0.0);
}
TEST(RandTest, RandAddition){
    Rand* rand = new Rand();
    Base* obj1 = new Op(0.0);
    Base* test = new Add(rand, obj1);
    EXPECT_TRUE(test->evaluate() == rand->evaluate());
}
TEST(RandTest, RandDivision){
    Rand* rand = new Rand();
    Base* obj1 = new Op(0.0);
    EXPECT_THROW(Div(rand, obj1), std::invalid_argument);
}
#endif
