#include "Email.h"
#include "MailBox.h"

template<class T, class T2>
void Show(const std::vector<T>& v_mail_param)
{
    T2 mailbox;

    for (int i = 0; i < v_mail_param.size(); i++) //  works..
        std::cout << v_mail_param[i];
}


int main()
{
    Email a("Anders", "2002-02-28", "lab 1");
    Email b("Anders", "2002-02-28", "lab 2");
    
    

    
    const std::vector<Email> mails{ a, b }; 

    Show<Email, MailBox>(mails);

}