#ifndef _ADDPROFILE_H_
#define _ADDPROFILE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "User.h"

class AddProfile{
  private:
    User A;
  public:
    void Add();
    void Show();
    void Edit();
    void Username();
    void Password();
    void Delete();
    void LogicDelete();
    bool RepeatedProfile(char *strUsername);
};

#endif
