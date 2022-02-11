#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>
#include <iostream>

class Op : public Base {
    private: 
	double value;
    public:
        Op(double value1) : Base() {value = value1;}
	double getVal(){return value;}
        virtual double evaluate() { return value;}
        virtual std::string stringify() {return std::to_string(value); }
};

#endif //__OP_HPP__
