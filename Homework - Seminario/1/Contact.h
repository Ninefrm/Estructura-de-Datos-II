#ifndef _CONTACT_H_
#define _CONTACT_H_
#include <string>
#include <iostream>

class Contact{
  private:
    std::string Name;
    std::string Phone;
    std::string Email;
  public:
    Contact();
    /*void ShowContact();
    void SearchContact();
    void EditContact();
    void DeleteContact();*/
    void addName(std::string &N);
    void addEmail(std::string &N);
    void addPhone(std::string &N);
    std::string rName();
    std::string rEmail();
    std::string rPhone();
};

#endif
