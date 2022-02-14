#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "base.hpp"

TEST(AddTest, AddEvaluateNonZero) {
    Base *obj1 = new Op(3.500000000);
    Base *obj2 = new Op(3.5);
    Base* test = new Add(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 7.0);
    EXPECT_EQ(test->stringify(), "(3.500000+3.500000)");
}

TEST(AddTest, AddEvaluateZero) {
    Base *obj1 = new Op(3.5);
    Base *obj2 = new Op(0.00);
    Base* test = new Add(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 3.5);
    EXPECT_EQ(test->stringify(), "(3.500000+0.000000)");
}

TEST(AddTest, AddEvaluateTwoZeros) {
    Base *obj1 = new Op(0.0000);
    Base *obj2 = new Op(0.00);
    Base* test = new Add(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 0.0);
    EXPECT_EQ(test->stringify(), "(0.000000+0.000000)");
}

TEST(AddTest, AddEvaluateOneNeg) {
    Base *obj1 = new Op(3.500);
    Base *obj2 = new Op(-1.00);
    Base* test = new Add(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 2.5);
    EXPECT_EQ(test->stringify(), "(3.500000+-1.000000)");
}
TEST(AddTest, AddEvaluateTwoNeg) {
    Base *obj1 = new Op(-3.5);
    Base *obj2 = new Op(-1.00);
    Base* test = new Add(obj1,obj2);
    EXPECT_EQ(test->evaluate(), -4.5);
    EXPECT_EQ(test->stringify(), "(-3.500000+-1.000000)");
}

TEST(AddTest, AddEvaluateUsingMult) { // adding using Mult object
    Base *obj1 = new Op(3.5);
    Base *mult1 = new Op(1.0); Base *mult2 = new Op(0.0000); // also testing mult by 0 here
    Base *obj2 = new Mult(mult1,mult2);
    Base* test = new Add(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 3.5);
    EXPECT_EQ(test->stringify(), "(3.500000+(1.000000*0.000000))");
}

TEST(AddTest, AddEvaluateUsingSub) { // adding using Sub object
    Base *obj1 = new Op(3.5);
    Base *sub1 = new Op(2.50); Base *sub2 = new Op(0.50000);
    Base *obj2 = new Sub(sub1, sub2);
    Base *test = new Add(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 5.5);
    EXPECT_EQ(test->stringify(), "(3.500000+(2.500000*0.500000))");
}
