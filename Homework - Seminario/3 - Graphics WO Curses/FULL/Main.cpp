#include <iostream>
#include "Venta.h"
#include "Usuario.h"

int main(int argc, char const *argv[]) {
  Venta A;
  Usuario B;
  int W = 1;
  int Q = 1;
  int OP, X;
  std::string Tmp;
  std::string Usuario, Contrasena;
  int INTENTOS = 0;
  system("cls");
  while(Q){
    std::cout<<"1.- Create new user."<<std::endl;
    std::cout<<"2.- Login."<<std::endl;
    std::cin>>X;
    std::cin.ignore();
    switch (X) {
      case 1:
        B.NewUser();
        break;
      case 2:
        while(INTENTOS<3){
          std::cout<<INTENTOS<<std::endl;
          std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
          std::cout<<"Usuario: ";
          getline(std::cin, Usuario);
          std::cout<<"Contraseña: ";
          getline(std::cin, Contrasena);
          /*std::ofstream Write("UsPass.txt", std::ios::app);
          Write<<Usuario<<'\n'<<Contrasena<<'\n';*/

          if(B.login(Usuario, Contrasena)){
            system("cls");
            while(W){
              std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
              std::cout<<" \n USERNAME: "<<Usuario<<std::endl;
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
        break;
        default:
          X=0;
        break;
    }
  }
  //rename("UsPass.txt","sPass.txt");
  return 0;
}
