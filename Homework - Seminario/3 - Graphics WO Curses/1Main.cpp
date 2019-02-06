#include <iostream>
#include <conio.h>
#include "Venta.h"

int main(int argc, char const *argv[]) {

  int W = 1;
  int OP;
  char p;
  std::string Tmp;
  std::string Usuario, Contrasena;
  int INTENTOS = 0;
  system("cls");
  while(INTENTOS<3){
    std::cout<<INTENTOS<<std::endl;
    std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
    std::cout<<"Usuario: ";
    getline(std::cin, Usuario);
    std::cout<<"Password: ";
    Contrasena="";
    p=1;
    while(p!=13){
      p=getch();
      if(p!=8){
       Contrasena.push_back(p);
       std::cout<<"*";
      }
      else if(Contrasena.size()>0){
        std::cout<<"\b \b";
        Contrasena.pop_back();
      }
      else
        std::cout<<"";
    }
    Contrasena.pop_back();
    std::cout<<"\b \b";
    //getline(std::cin, Contrasena);
    /*std::ofstream Write("UsPass.txt", std::ios::app);
    Write<<Usuario<<'\n'<<Contrasena<<'\n';*/

    std::string rUsuario, rContrasena;

    std::ifstream Read("UsPass.txt");
        getline(Read,rUsuario,'#');
        //std::cout<<"A:"<<rUsuario<<std::endl;
        getline(Read,rContrasena,'#');
        //std::cout<<"B:"<<rContrasena<<std::endl;

    std::cout<<"A2:"<<rUsuario<<std::endl;
    std::cout<<"B2:"<<rContrasena<<std::endl;

    if(Usuario == rUsuario && Contrasena == rContrasena){
      system("cls");
      Venta A;
      while(W){
        system("cls");
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
          system("cls");
          std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
          std::cout<<" \n USERNAME: "<<rUsuario<<std::endl;
          std::cout<<" \n \t ADD CLIENT. "<<std::endl;
            A.addClient();
            system("PAUSE");
            break;

          case 2:
          system("cls");
          std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
          std::cout<<" \n USERNAME: "<<rUsuario<<std::endl;
          std::cout<<" \n \t CLIENT LIST. "<<std::endl;
            A.ShowClients();
            system("PAUSE");
            break;

          case 3:
          system("cls");
          std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
          std::cout<<" \n USERNAME: "<<rUsuario<<std::endl;
          std::cout<<" \n \t SEARCH CLIENTE. "<<std::endl;
          std::cout<<"Name: "<<std::endl;
            getline(std::cin, Tmp);
            A.Search(Tmp);
            system("PAUSE");
            break;

          case 4:
          system("cls");
          std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
          std::cout<<" \n USERNAME: "<<rUsuario<<std::endl;
          std::cout<<" \n \t EDIT CLIENT. "<<std::endl;
          std::cout<<"Name: "<<std::endl;
            getline(std::cin, Tmp);
            A.Edit(Tmp);
            system("PAUSE");
            break;

          case 5:
          system("cls");
          std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
          std::cout<<" \n USERNAME: "<<rUsuario<<std::endl;
          std::cout<<" \n \t DELETE CLIENT. "<<std::endl;
          std::cout<<"Name: "<<std::endl;
            getline(std::cin, Tmp);
            A.Delete(Tmp);
            system("PAUSE");
            break;

          default:
          W=0;
          INTENTOS = 10;
          break;
        }
      }
    }
    else{
      system("cls");
      INTENTOS++;
    }
  }

  if(INTENTOS == 3) std::cout<<"The password you've entered is incorrect."<<std::endl;
  return 0;
}
