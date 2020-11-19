#include "MailBox.h"

MailBox::MailBox() {}

void MailBox::set_emails(std::vector<Email> m)
{
	emails__ = m;
}

std::vector<Email> MailBox::get_emails() 
{
	return emails__;
}


void MailBox::SortSender(std::vector<Email>& m)
{
    std::sort(m.begin(), m.end(), CompWhoDateSubject());
}


void MailBox::SortDate(std::vector<Email>& m)
{
	std::sort(m.begin(), m.end(), CompDateWhoSubject());
}

void MailBox::SortSubject(std::vector<Email>& m)
{
	std::sort(m.begin(), m.end(), CompSubjectWhoDate());
}