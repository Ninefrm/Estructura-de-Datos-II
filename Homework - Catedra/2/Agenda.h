#ifndef _AGENDA_H_
#define _AGENDA_H_
#include "Contact.h"
#include <iostream>
#include <string>
#include <fstream>

class Agenda{
  private:
    Contact C;
  public:
    void addContact();
    void ShowContact();
    void SearchContact(std::string sName);
    void EditContact(std::string sName);
    void DeleteContact(std::string sName);
    void EditStatus();
};
#endif
