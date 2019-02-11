#ifndef _PROFILE_H_
#define _PROFILE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "User.h"
#include "Venta.h"

class Profile{
  private:
    Venta W;
  public:
    User A;
    void Add();
    void Show();
    void Edit();
    void Username();
    void Password();
    void Delete();
    bool RepeatedProfile(char *strUsername);
};
#endif
