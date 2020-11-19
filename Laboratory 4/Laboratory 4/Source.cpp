#include "MailBox.h"

template<typename T, typename T2>
void Show(const std::vector<T>& v_mail_param)
{
    T2 mailbox;

    mailbox.set_emails(v_mail_param);
    auto mails = mailbox.get_emails();

    //mailbox.SortSender(mails);
    //mailbox.SortSubject(mails);
    mailbox.SortDate(mails);

    for (int i = 0; i < mails.size(); i++) //  works..
	       std::cout << mails[i];
}


int main()
{
    Email a("Anders Karlsson ", "2002-02-28", "lab 1");
    Email c("Johan Wehlin", "2002-10-10", "lab 3");
    Email d("Lena Sundström", "2002-10-10", "lab 4");
    Email b("Anders Karlsson", "2002-02-28", "lab 5");
    Email e("Kerstin Lindström", "1969-09-22", "lab 2");

    const std::vector<Email> mails{ a, b, c, d, e}; 

    Show<Email, MailBox>(mails);

}
