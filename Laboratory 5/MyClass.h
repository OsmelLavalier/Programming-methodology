#ifndef MyClass_h
#define MyClass_h

#include "Person.h"

class MyClass 
{
    public:
    void operator()(Person& person)
    {
        std::cout << person;
    }
};

#endif
