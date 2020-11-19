#include "Email.h"


Email::Email(std::string sender, std::string date, std::string subject)
    : sender__(sender), date__(date), subject__(subject)
{
}

std::ostream& operator<<(std::ostream& out, const Email& email) 
{
    out << email.sender__ << " " << email.date__ << " " << email.subject__ << "\n";
    return out;
}