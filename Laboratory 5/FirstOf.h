#ifndef FirstOf_h
#define FirstOf_h

#include "Person.h"

class FirstOfObject
{
    std::string name__; 
    int age__;
    public:
    FirstOfObject(std::string name, double age): name__(name), age__(age) {}
    bool operator()(Person& rhs)
    {
        if(rhs.name__ > name__)
        {
            if(rhs.age__ > age__)
                return true;
        }
        return false;
    }
};

#endif