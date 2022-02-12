#ifndef __POW_HPP
#define __POW_HPP

#include "base.hpp"
#include <string>
#include <cmath>
#include<iostream>

class Pow : public Base{
    private:
	Base *Left_op;
	Base *Right_op;
    public:
	Pow(Base *leftVal, Base *rightVal) : Base(){
	    Left_op = leftVal;
	    Right_op = rightVal;
	}
	virtual double evaluate(){
	    return pow(Left_op ->evaluate() , Right_op->evaluate());
	}
	virtual std::string stringify(){
	    return '(' + Left_op->stringify() + '*' + '*' + Right_op->stringify() + ')';
	}
};

#endif
