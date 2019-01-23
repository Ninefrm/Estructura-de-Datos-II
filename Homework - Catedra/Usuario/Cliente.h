#ifndef _CLIENTE_H_
#define _CLIENTE_H_
#include "User.h"

class Cliente:public User{
  private:
    User C;
    std::string Payment;
    std::string Email;
    std::string Phone;
  public:
    Cliente();
    void addPayment(std::string& aPayment);
    void addEmail(std::string& aEmail);
    void addPhone(std::string& aPhone);
    void addClient();
    std::string sPayment();
    std::string sEmail();
    std::string sPhone();
};

#endif
