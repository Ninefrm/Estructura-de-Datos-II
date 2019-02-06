#ifndef _USUARIO_H_
#define _USUARIO_H_
#include "User.h"
#include <iostream>
#include <string>
#include <fstream>

class Usuario:public User{
  private:
    int xCode;
    std::string xpassword;
  public:
    void NewUser();
    void showUsers();
    void searchUsers(std::string sCode);
    void EditUsers(std::string sCode);
    //void logicDelete();
    int login(std::string sCode, std::string sPassword);
  };

#endif
