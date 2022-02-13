#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "op.hpp"
#include <string>

TEST(SubTest, SubEvaluateNonZero) {
    Base *obj1 = new Op(2.0);
    Base *obj2 = new Op(1.0);
    Base *test = new sub(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 1.0);
}

TEST(SubTest, SubStringify){
    Base *obj1 = new Op(2.0);
    Base *obj2 = new Op(1.0);
    Base *test = new sub(obj1, obj2);
    EXPECT_EQ(test->stringify(), "(2.000000-1.000000)");
}

TEST(SubTest, SubEvaluateNegative){
    Base *obj1 = new Op(1.0);
    Base *obj2 = new Op(2.0);
    Base *test = new sub(obj1, obj2);
    EXPECT_EQ(test->evaluate(), -1.0);
}

TEST(SubTest, MultObject){
    Base *obj1 = new Op(3.0);
    Base *obj2 = new Op(2.0);
    Base *obj3 = new Mult(obj1, obj2);
    Base *test = new sub(obj3, obj2);
    EXPECT_EQ(test->evaluate(), 4.0);
}

TEST(SubTest,ZeroTest){
     Base *obj1 = new Op(2.0);
    Base *obj2 = new Op(2.0);
    Base *test = new sub(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 0.0);
}
TEST(SubTest, TwoNegatives){
    Base *obj1 = new Op(-3.0);
    Base *obj2 = new Op(-4.0);
    Base *test = new sub(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 1);
}
TEST(SubTest, TwoNegsString){
    Base *obj1 = new Op(-3.0);
    Base *obj2 = new Op(-4.0);
    Base *test = new sub(obj1, obj2);
    EXPECT_EQ(test->stringify(), "(-3.000000--4.000000)");
}
#endif
