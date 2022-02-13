#ifndef __Div_HPP__
#define __Div_HPP__

#include "base.hpp"
#include <string>
class Div : public Base {
    private:
        Base *Left_op;
        Base *Right_op;
    public:
        Div(Base *leftVal, Base *rightVal) : Base() {
            if (leftVal->evaluate() == 0.0 || rightVal->evaluate() == 0.0){
                throw std::invalid_argument("error!!!");
            }
            else{
           	 Left_op = leftVal;
           	 Right_op = rightVal;
            }
         }
        virtual double evaluate() {
            return Left_op->evaluate() / Right_op->evaluate();
         }
        virtual std::string stringify() {
            return '(' + Left_op->stringify() + "/" + Right_op->stringify() + ')';
         }
};

#endif //__Div_HPP__
