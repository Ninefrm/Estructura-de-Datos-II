#ifndef _CLIENTE_H_
#define _CLIENTE_H_
#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include <fstream>

class Cliente{
  private:
    std::string Payment;
    std::string Email;
    std::string Phone;
    std::string ID;
    std::string Status;
    std::string Name;
    std::string RFC;
    std::string Owner;
  public:
    // Cliente();
    void addName(std::string& aName);
    void addRFC(std::string& aRFC);
    void addPayment(std::string& aPayment);
    void addEmail(std::string& aEmail);
    void addPhone(std::string& aPhone);
    void addID(std::string aID);
    void addStatus(std::string& aStatus);
    void addOwner(std::string& aOwner);
    std::string sOwner();
    std::string sID();
    std::string sPayment();
    std::string sEmail();
    std::string sPhone();
    std::string sStatus();
    std::string sName();
    std::string sRFC();
};

#endif
