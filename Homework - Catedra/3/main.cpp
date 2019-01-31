#include <iostream>
#include "Agenda.h"

int main(){
  Agenda W;
  std::string sName;
  int A=1;
  while(A){
    std::cout<<"1.Add Contact"<<std::endl;
    std::cout<<"2.Show Contacts"<<std::endl;
    std::cout<<"3.Search Contact"<<std::endl;
    std::cout<<"4.Edit Contact"<<std::endl;
    std::cout<<"5.Delete Contact"<<std::endl;
    std::cout<<"6.Exit"<<std::endl;
    int OP;
    std::cin>>OP;
    std::cin.ignore(); //Enteros, para después caracteres.
    switch (OP) {
      case 1:
        W.addContact();
      break;
      case 2:
        W.ShowContact();
      break;
      case 3:
      std::cout<<"Name: "<<std::endl;
        getline(std::cin, sName);
        W.SearchContact(sName);
      break;
      case 4:
      std::cout<<"Name: "<<std::endl;
        getline(std::cin, sName);
        W.EditContact(sName);
      break;
      case 5:
      std::cout<<"Name: "<<std::endl;
        getline(std::cin, sName);
        W.DeleteContact(sName);
        break;
      
      default:
        A=0;
        break;
    }
  }

  return 0;
}
