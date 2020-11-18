#ifndef CompWhoDateSubject_h
#define CompWhoDateSubject_h

#include "Email.h"

class CompWhoDateSubject 
{
public:
    bool operator()(Email& lhs, Email& rhs)
    {
        return lhs.sender__ < rhs.sender__ || lhs.sender__ == rhs.sender__;
    }
};

#endif
