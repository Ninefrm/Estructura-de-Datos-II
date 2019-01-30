#ifndef _VENTA_H_
#define _VENTA_H_
#include "Cliente.h"
#include <cstdlib>
#include <sstream>
class Venta{
  private:
    Cliente A;
  public:
    void addClient();
    void ShowClients();
};

#endif
