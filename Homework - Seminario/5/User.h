#ifndef _USER_H_
#define _USER_H_
#include <fstream>

class User{
  public:
    char Username[10];
    char Password[10];
    int Permissions1;
    int Permissions2;
    int Permissions3;
    int Permissions4;
    int Permissions5;
    int Permissions6;

    int Status;
};

#endif
