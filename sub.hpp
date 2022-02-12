#ifndef __SUB_HPP
#define __SUB_HPP

#include "base.hpp"
#include <string>

class sub : public Base{
    private:
	Base *Left_op;
	Base *Right_op;
    public:
	sub(Base *leftVal, Base *rightVal) : Base(){
	    Left_op = leftVal;
	    Right_op = rightVal;
	}
	virtual double evaluate(){
	    return Left_op->evaluate() - Right_op->evaluate();
	}
	virtual std::string stringify(){
	    return '(' + Left_op->stringify() + '-' + Right_op->stringify() + ')';
	}
};

#endif
