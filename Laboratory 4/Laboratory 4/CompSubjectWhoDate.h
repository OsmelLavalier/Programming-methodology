#ifndef CompSubjectWheDate_h
#define CompSubjectWheDate_h

#include "Email.h"

class CompSubjectWhoDate
{
public:
    bool operator()(Email& lhs, Email& rhs)
    {
        return lhs.subject__ < rhs.subject__ || lhs.subject__ == rhs.subject__;
    }
};

#endif