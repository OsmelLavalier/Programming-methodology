#ifndef MailBox_h
#define MailBox_h

#include "Email.h"
#include "CompWhoDateSubject.h"

class MailBox
{
private:
    std::vector<Email> emails__; //  container to hold our emails... 

public:
    MailBox();
    void SortSender(Email& lhs, Email& rhs);
};

#endif

