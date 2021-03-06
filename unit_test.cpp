#include "gtest/gtest.h"

#include "op_test.hpp"
#include "rand_test.hpp"
#include "base.hpp"
#include "sub_test.hpp"
#include "pow_test.hpp"
#include "mult_test.hpp"
#include "div_test.hpp"
#include "add_test.hpp"

TEST(Representation, zeroTest){
    ZeroOpMock obj1;
    EXPECT_TRUE(obj1.evaluate() == 0.0);
    EXPECT_TRUE(obj1.stringify() == "0.0");
}

TEST(Representation, negTest){
    NegOpMock obj2;
    EXPECT_TRUE(obj2.evaluate() == -2.0);
    EXPECT_TRUE(obj2.stringify() == "-2.0");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
