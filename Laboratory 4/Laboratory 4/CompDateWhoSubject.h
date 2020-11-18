#ifndef CompDateWhoSubject_h
#define CompDateWhoSubject_h

#include "Email.h"

class CompDateWhoSubject
{
public:
    bool operator()(Email& lhs, Email& rhs)
    {
        return lhs.date__ < rhs.date__ || lhs.date__ == rhs.date__;
    }
};

#endif