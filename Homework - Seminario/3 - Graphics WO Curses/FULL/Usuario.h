#ifndef _USUARIO_H_
#define _USUARIO_H_
#include "User.h"

class Usuario:public User{
  private:
    int code;
    std::string password;
  private:
    void NewUser();
    void showUsers();
    void searchUsers();
    void EditUsers();
    void logicDelete();
  };

#endif
