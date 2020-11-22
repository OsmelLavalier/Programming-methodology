#ifndef MyUnOp_h
#define MyUnOp_h

#include "Person.h"

class MyUnOp
{
    double mean__;
    public:
    MyUnOp(double mean=0): mean__(mean) {}

    double operator()(Person& person)
    {
        return person.get_age() - mean__;
    }
};

#endif