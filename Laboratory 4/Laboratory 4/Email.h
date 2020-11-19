#ifndef Email_h
#define Email_h

#include<vector>
#include<algorithm>
#include<iostream>
#include<string>

class Email
{
private:
    std::string sender__;
    std::string date__;
    std::string subject__;

    friend class CompWhoDateSubject;
    friend class CompDateWhoSubject;
    friend class CompSubjectWhoDate;

public:
    Email(std::string sender, std::string date, std::string subject);

    friend std::ostream& operator<<(std::ostream& out, const Email& email);
};

#endif

