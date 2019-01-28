#include <iostream>
#include "Venta.h"

int main(int argc, char const *argv[]) {
  Venta A;
  int W = 1;
  int OP;
  std::string Tmp;
  while(W){
    std::cout<<"1.- ADD CLIENT."<<std::endl;
    std::cout<<"2.- SHOW CLIENTS."<<std::endl;
    std::cout<<"3.- SEARCH CLIENT."<<std::endl;
    std::cout<<"4.- EDIT CLIENT."<<std::endl;
    std::cout<<"5.- DELETE CLIENT."<<std::endl;
    std::cout<<"6.- EXIT."<<std::endl;
    std::cin>>OP;
    std::cin.ignore();
    switch ( OP) {
      case 1:
        A.addClient();
        break;

      case 2:
        A.ShowClients();
        break;

      case 3:
      std::cout<<"Name: "<<std::endl;
        getline(std::cin, Tmp);
        A.Search(Tmp);
        break;

      case 4:
      std::cout<<"Name: "<<std::endl;
        getline(std::cin, Tmp);
        A.Edit(Tmp);
        break;

      case 5:
      std::cout<<"Name: "<<std::endl;
        getline(std::cin, Tmp);
        A.Delete(Tmp);
        break;

      default:
      W=0;
      break;
    }
  }
  return 0;
}
