#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Base *obj1 = new Op(1.0);
    Base *obj2 = new Op(2.0);
    Base *test = new Mult(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 2.0);
    EXPECT_EQ(test->stringify(), "(1.000000*2.000000)");
}

TEST(MultTest, MultEvaluateZero) {
    Base *obj1 = new Op(1.0);
    Base *obj2 = new Op(0.0);
    Base *test = new Mult(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 0.0);
    EXPECT_EQ(test->stringify(), "(1.000000*0.000000)");
}

TEST(MultTest, MultEvaluateDecimal){
    Base *obj1 = new Op(1.5);
    Base *obj2 = new Op(2.5);
    Base *test = new Mult(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 3.75);
    EXPECT_EQ(test->stringify(), "(1.500000*2.500000)");
}

TEST(MultTest, MultEvaluateUsingSub) { // multiplying using Sub object
    Base *obj1 = new Op(3.5);
    Base *sub1 = new Op(2.50); Base *sub2 = new Op(0.50000);
    Base *obj2 = new sub(sub1, sub2);
    Base *test = new Mult(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 7.0);
    EXPECT_EQ(test->stringify(), "(3.500000*(2.500000-0.500000))");
}

TEST(MultTest, MultEvaluateUsingAdd) { // multiplying using Add object
    Base *obj1 = new Op(3.5);
    Base *add1 = new Op(2.50); Base *add2 = new Op(0.50000);
    Base *obj2 = new Add(add1,add2);
    Base *test = new Mult(obj1,obj2);
    EXPECT_EQ(test->evaluate(), 10.5);
    EXPECT_EQ(test->stringify(), "(3.500000*(2.500000+0.500000))");
}

TEST(MultTest, MultEvaluateOneNeg){
    Base *obj1 = new Op(1.5);
    Base *obj2 = new Op(-12.5);
    Base *test = new Mult(obj1, obj2);
    EXPECT_EQ(test->evaluate(), -18.75);
    EXPECT_EQ(test->stringify(), "(1.500000*-12.500000)");
}

TEST(MultTest, MultEvaluateTwoNeg){
    Base *obj1 = new Op(-1.5);
    Base *obj2 = new Op(-12.5);
    Base *test = new Mult(obj1, obj2);
    EXPECT_EQ(test->evaluate(), 18.75);
    EXPECT_EQ(test->stringify(), "(-1.500000*-12.500000)");
}
#endif //__MULT_TEST_HPP__
