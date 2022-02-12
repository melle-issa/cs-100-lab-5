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
}

#endif //__ADD_TEST_HPP__
