#include <iostream>
#include "Venta.h"

int main(int argc, char const *argv[]) {
  Venta A;
  int W = 1;
  int OP;
  std::string Tmp;
  std::string Usuario, Contrasena;
  int INTENTOS = 0;
  system("cls");
  while(INTENTOS<3){
    std::cout<<INTENTOS<<std::endl;
    std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
    std::cout<<"Usuario: ";
    getline(std::cin, Usuario);
    std::cout<<"Contraseña: ";
    getline(std::cin, Contrasena);
    /*std::ofstream Write("UsPass.txt", std::ios::app);
    Write<<Usuario<<'\n'<<Contrasena<<'\n';*/

    std::string rUsuario, rContrasena;

    std::ifstream Read("UsPass.txt");
        getline(Read,rUsuario,'#');
        std::cout<<"A:"<<rUsuario<<std::endl;
        getline(Read,rContrasena,'#');
        std::cout<<"B:"<<rContrasena<<std::endl;

    std::cout<<"A2:"<<rUsuario<<std::endl;
    std::cout<<"B2:"<<rContrasena<<std::endl;

    if(Usuario == rUsuario && Contrasena == rContrasena){
      system("cls");
      while(W){
        std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
        std::cout<<" \n USERNAME: "<<rUsuario<<std::endl;
        std::cout<<" \n \n \t1.- ADD CLIENT."<<std::endl;
        std::cout<<"\t2.- SHOW CLIENTS."<<std::endl;
        std::cout<<"\t3.- SEARCH CLIENT."<<std::endl;
        std::cout<<"\t4.- EDIT CLIENT."<<std::endl;
        std::cout<<"\t5.- DELETE CLIENT."<<std::endl;
        std::cout<<"\t6.- EXIT."<<std::endl;
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
    }
    else{
      system("cls");
      INTENTOS++;
    }
  }
  std::cout<<"The password you've entered is incorrect."<<std::endl;
  rename("UsPass.txt","sPass.txt");
  return 0;
}
