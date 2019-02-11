#ifndef _LOGIN_H_
#define _LOGIN_H_
#include "Profiles.h"
#include "Venta.h"
#include <iostream>
#include <string>
#include <fstream>

class Login{
  private:
    Profile P;
    Venta V;
  public:
    bool Sesion();
    char* Username();
    char* Password();
    bool Verify(char *strUsername, char *strPassword);
    User Copy(char *strUsername, char *strPassword);
};
#endif
