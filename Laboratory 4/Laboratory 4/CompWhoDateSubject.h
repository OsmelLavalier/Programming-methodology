#ifndef CompWhoDateSubject_h
#define CompWhoDateSubject_h

#include "Email.h"

class CompWhoDateSubject 
{
public:
    bool operator()(const Email& lhs, const Email& rhs)
    {
    	if(lhs.date__ == rhs.date__)
            return lhs.subject__ < rhs.subject__;

        else if(lhs.subject__ == rhs.subject__)
            return lhs.date__ < rhs.date__;

        return lhs.sender__ < rhs.sender__;
    }
};

#endif
