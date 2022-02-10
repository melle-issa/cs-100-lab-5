#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include<iostream>

using namespace std;

class Base {
    public:
        /* Constructors */
        Base() { }

        virtual ~Base() {}
    
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
};

class NegOpMock: public Base {
    public:
	NegOpMock() { }

	virtual double evaluate() { return -2.0; }
	virtual string stringify() {return "-2.0"; }	
};

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { }

        virtual double evaluate() { return 0.0; }
        virtual string stringify() { return "0.0"; }
};

class SevenOpMock: public Base {
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
};



#endif //__BASE_HPP__


