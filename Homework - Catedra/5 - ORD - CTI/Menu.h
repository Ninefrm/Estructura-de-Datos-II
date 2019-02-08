#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "Aquarius.h"

using namespace std;

class Menu{
  private:
    Aquarius p;
  public:
    void DATE();
    void ADD();
    void SHOW();
    void MENU();
    void SEARCH();
    void EDIT();
    void DELETE();
    void LOGICDELETE();
    void LOGICRES();
    bool isValidDate(char* date);
};

#endif
