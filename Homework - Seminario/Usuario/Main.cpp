#include <iostream>
#include "Venta.h"

int main(int argc, char const *argv[]) {
  Venta A;
  int W = 1;
  int OP;
  while(W){
    std::cout<<"1.- ADD CLIENT."<<std::endl;
    std::cout<<"2.- SHOW CLIENTS."<<std::endl;
    std::cout<<"3.- EXIT."<<std::endl;
    std::cin>>OP;
    std::cin.ignore();
    switch ( OP) {
      case 1:
        A.addClient();
        break;
      case 2:
        A.ShowClients();
        break;
      default:
      W=0;
      break;
    }
  }
  return 0;
}
