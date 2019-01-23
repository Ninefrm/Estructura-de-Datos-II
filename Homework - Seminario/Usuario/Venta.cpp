#include "Venta.h"

void Venta::addClient(){
  int CT=0;
  std::stringstream Temp;
  std::string Name, Phone, Email, Payments, RFC, Tmp;
  std::ifstream Read("Clientes.txt");
  if(!Read.good())
    std::cout<<"Error";
  else
    while(!Read.eof()){
      getline(Read,Tmp,'#');
      getline(Read,Tmp,'#');
      getline(Read,Tmp,'#');
      getline(Read,Tmp,'#');
      getline(Read,Tmp,'#');
      getline(Read,Tmp,'\n');
      if(Read.eof())break;
      CT++;
    }Read.close();
  std::cout<<CT<<std::endl;

  std::ofstream Write("Clientes.txt", std::ios::app);
  std::cout<<"Name: ";
  getline(std::cin,Name);
  std::cout<<"Phone: ";
  getline(std::cin,Phone);
  std::cout<<"Email: ";
  getline(std::cin,Email);
  std::cout<<"Payments: ";
  getline(std::cin, Payments);
  std::cout<<"Address: ";
  getline(std::cin, RFC);
  A.addName(Name);
  A.addPhone(Phone);
  A.addEmail(Email);
  A.addRFC(RFC);
  A.addPayment(Payments);
  Temp<<CT;
  Temp>>Tmp;
  A.addID(Tmp);

Write<<A.sName()<<"#"<<A.sID()<<"#"<<A.sPhone()<<"#"<<A.sEmail()<<"#"<<A.sPayment()<<"#"<<A.sRFC()<<'\n';
}
void Venta::ShowClients(){
  std::string Tmp;
  std::ifstream Read("Clientes.txt");
  if(!Read.good())
    std::cout<<"Error";
  else
  std::cout<<"NAME    "<<"CODE  "<<"PHONE NUMBER   "<<"EMAIL              "<<"PAYMENT        "<<"ADDRESS   "<<std::endl;
    while(!Read.eof()){
      getline(Read,Tmp,'#');
      A.addName(Tmp);
      getline(Read,Tmp,'#');
      A.addID(Tmp);
      getline(Read,Tmp,'#');
      A.addPhone(Tmp);
      getline(Read,Tmp,'#');
      A.addEmail(Tmp);
      getline(Read,Tmp,'#');
      A.addPayment(Tmp);
      getline(Read,Tmp,'\n');
      A.addRFC(Tmp);
      if(Read.eof())break;
      std::cout<<A.sName()<<" "<<A.sID()<<"      "<<A.sPhone()<<"     "<<A.sEmail()<<"    "<<A.sPayment()<<"    "<<A.sRFC()<<std::endl;
    }Read.close();
}
