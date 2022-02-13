#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "base.hpp"

TEST(AddTest, AddEvaluateNonZero) {
    Base *obj1 = new Op(3.5);
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
#endif //__ADD_TEST_HPP__
