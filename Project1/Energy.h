#pragma once
#include <iostream>
#include <compare>
#include "Constant.h"
#include "Massa.h"
#include "Base.h"


using namespace std;

class Energy: public Base
{
public:
    Energy();
    Energy(const Energy& reference);
    Energy(Energy&& reference)
    {
        this->value = reference.value;
    }
    Energy(double _v);

    Energy& operator=(const Energy& right);
    Energy& operator=(Energy&& right)    
    {
        this->value = right.value;
    }
    double  get() const override;

    operator Massa() const;
    virtual ~Energy();
    std::partial_ordering operator<=>(const Energy&) const noexcept;
    bool operator==(const Energy& energy) const noexcept;
};

Energy operator "" J(long double x);
Energy operator+(const Energy& left, const Energy& right);

Energy operator-(const Energy& left, const Energy& right);

ostream& operator<<(ostream& out, const Energy& obj);