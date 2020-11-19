#ifndef CompDateWhoSubject_h
#define CompDateWhoSubject_h

class CompDateWhoSubject
{
public:
    
    bool operator()(Email& lhs, Email& rhs)
    {
        if(lhs.date__ == rhs.date__)
            return lhs.sender__ < rhs.sender__;

        else if(lhs.sender__ == rhs.sender__)
            return lhs.subject__ < rhs.subject__;

        return lhs.date__ < rhs.date__;
    }
};

#endif