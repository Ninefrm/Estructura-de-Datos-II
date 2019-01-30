#ifndef _VENTA_H_
#define _VENTA_H_
#include "Cliente.h"
#include <cstdlib>
#include <sstream>
class Venta{
  private:
    Cliente A;
    std::string Count;
    int CtS=0;
  public:
    void addClient();
    void ShowClients();
    void Search(std::string Name);
    void Edit(std::string Name);
    void Delete(std::string sName);
};

#endif
