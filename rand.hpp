#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <iostream>
#include <string>
#include <ccmath>

class Rand : public Base {
    private: 
	double value;
    public:
	double getVal(){return value;}
        Rand() : Base() {value = rand() % 100; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
};

#endif
