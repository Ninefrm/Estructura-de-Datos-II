#ifndef _VENTA_H_
#define _VENTA_H_
#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include "Cliente.h"
#include <sstream>
class Venta{
  private:
    Cliente A;
    std::string Count;
    int CtS=0;
  public:
    void addClient(std::string Owner);
    void ShowClients(std::string Owner);
    void Search(std::string Name, std::string Owner);
    void Edit(std::string Name, std::string Owner);
    void Delete(std::string sName, std::string Owner);
    bool HaveClients(std::string& Owner);
};

#endif
