#ifndef __Mult_HPP__
#define __Mult_HPP__

#include "base.hpp"
#include <string>
class Mult : public Base {
    private:
        Base *Left_op;
        Base *Right_op;
    public:
        Mult(Base *leftVal, Base *rightVal) : Base() {
            Left_op = leftVal;
            Right_op = rightVal;
         }
        virtual double evaluate() { 
            return Left_op->evaluate() * Right_op->evaluate(); 
         }
        virtual std::string stringify() { 
            return '(' + Left_op->stringify() + "*" + Right_op->stringify() + ')';
         }
};

#endif //__Mult_HPP__
