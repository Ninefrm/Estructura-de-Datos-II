#ifndef _USER_H_
#define _USER_H_
#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include <fstream>

class User{
  private:
    std::string Name;
    std::string Rank;
    std::string RFC;
  public:
    void addName(std::string& aName);
    void addRank(std::string& aRank);
    void addRFC(std::string& aRFC);
    std::string sName();
    std::string sRank();
    std::string sRFC();
};

#endif
