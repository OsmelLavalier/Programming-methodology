#ifndef MailBox_h
#define MailBox_h

#include "Email.h"
#include "CompWhoDateSubject.h"
#include "CompDateWhoSubject.h"
#include "CompSubjectWhoDate.h"

class MailBox
{
private:
    std::vector<Email> emails__; //  container to hold our emails... 

public:
    MailBox();
    void set_emails(std::vector<Email> m);
    std::vector<Email> get_emails();
    
    /* Comparator Functions */
    void SortSender(std::vector<Email>& m);
    void SortDate(std::vector<Email>& m);
    void SortSubject(std::vector<Email>& m);
};

#endif

