#ifndef __Add_HPP__
#define __Add_HPP__

#include "base.hpp"
#include <string>

class Add : public Base {
    private:
        Base *Left_op;
        Base *Right_op;
    public:
        Add(Base *leftVal, Base *rightVal) : Base() {
            Left_op = leftVal;
            Right_op = rightVal;
         }
        virtual double evaluate() { 
            return Left_op->evaluate() + Right_op->evaluate(); 
         }
        virtual std::string stringify() { 
            return '(' + Left_op->stringify() + "+" + Right_op->stringify() + ')';
         }
};

#endif //__Add_HPP__
