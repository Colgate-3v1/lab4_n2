#pragma once
#include <iostream>
#include <memory>
#include <regex>
#include <string>
using namespace std;
class Base
{
protected:
	double value;
public:
    virtual double get() const;
};


