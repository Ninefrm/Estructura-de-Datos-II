#include "Venta.h"

void Venta::addClient(){
  std::stringstream Temp;
  std::string Name, Phone, Email, Payments, RFC, Tmp;
  //std::cout<<CtS<<std::endl;

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
  Temp<<CtS;
  Temp>>Tmp;
  A.addID(Tmp);
  std::string X;
  X="1";
  A.addStatus(X);
Write<<A.sName()<<"#"<<A.sID()<<"#"<<A.sPhone()<<"#"<<A.sEmail()<<"#"<<A.sPayment()<<"#"<<A.sRFC()<<"#"<<A.sStatus()<<'\n';
CtS++;
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
      getline(Read,Tmp,'#');
      A.addRFC(Tmp);
      getline(Read,Tmp,'\n');
      A.addStatus(Tmp);
      if(Read.eof())break;
      if(A.sStatus()=="1"){
        std::cout<<A.sName()<<" "<<A.sID()<<"      "<<A.sPhone()<<"     "<<A.sEmail()<<"    "<<A.sPayment()<<"    "<<A.sRFC()<<std::endl;
      }
    }Read.close();
}

void Venta::Search(std::string Name){
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
      getline(Read,Tmp,'#');
      A.addRFC(Tmp);
      getline(Read,Tmp,'\n');
      A.addStatus(Tmp);
      if(Read.eof())break;
      if(Name == A.sName())std::cout<<A.sName()<<" "<<A.sID()<<"      "<<A.sPhone()<<"     "<<A.sEmail()<<"    "<<A.sPayment()<<"    "<<A.sRFC()<<std::endl;
    }Read.close();
}

void Venta::Edit(std::string Name){
  std::string Tmp;
  int W=1;
  int OP;
  std::ofstream File("tmp.txt", std::ios::app);
  std::ifstream Read("Clientes.txt");
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
      getline(Read,Tmp,'#');
      A.addRFC(Tmp);
      getline(Read,Tmp,'\n');
      A.addStatus(Tmp);
      if(Read.eof())break;
      if(Name == A.sName()){
        while(W){
          std::cout<<"Edit: "<<std::endl;
          std::cout<<"1.Name"<<std::endl;
          std::cout<<"2.Phone"<<std::endl;
          std::cout<<"3.Email"<<std::endl;
          std::cout<<"4.Payment"<<std::endl;
          std::cout<<"5.Adress"<<std::endl;
          std::cout<<"6.Status"<<std::endl;

          std::cin>>OP;
          std::cin.ignore();
          switch (OP) {
            case 1:
            if(A.sStatus()=="1"){
              std::cout<<"Name: "<<std::endl;
              getline(std::cin, Tmp);
                A.addName(Tmp);
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 2:
            if(A.sStatus()=="1"){
              std::cout<<"Phone number:"<<std::endl;
              getline(std::cin, Tmp);
                A.addPhone(Tmp);
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 3:
            if(A.sStatus()=="1"){
              std::cout<<"Email:"<<std::endl;
              getline(std::cin, Tmp);
                A.addEmail(Tmp);
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 4:
            std::cout<<"Payment:"<<std::endl;
            getline(std::cin, Tmp);
              A.addPayment(Tmp);
            break;
            case 5:
            if(A.sStatus()=="1"){
              std::cout<<"Adress: "<<std::endl;
              getline(std::cin, Tmp);
                A.addRFC(Tmp);
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 6:
              std::cout<<"Status: "<<std::endl;
              getline(std::cin, Tmp);
                A.addStatus(Tmp);
            break;
            default:
            W=0;
            break;
          }
      }
    }
    File<<A.sName()<<"#"<<A.sID()<<"#"<<A.sPhone()<<"#"<<A.sEmail()<<"#"<<A.sPayment()<<"#"<<A.sRFC()<<"#"<<A.sStatus()<<'\n';
  }Read.close(); File.close();
    remove("Clientes.txt");
    rename("tmp.txt","Clientes.txt");
}

void Venta::Delete(std::string sName){
  std::string Tmp;
  int W=1;
  int OP;
  std::ofstream File("tmp.txt", std::ios::app);
  std::ifstream Read("Clientes.txt");
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
      getline(Read,Tmp,'#');
      A.addRFC(Tmp);
      getline(Read,Tmp,'\n');
      A.addStatus(Tmp);
      if(Read.eof())break;
      if(sName != A.sName()){
        File<<A.sName()<<"#"<<A.sID()<<"#"<<A.sPhone()<<"#"<<A.sEmail()<<"#"<<A.sPayment()<<"#"<<A.sRFC()<<"#"<<A.sStatus()<<'\n';
      }
      if(sName == A.sName() && A.sStatus()=="0"){
        std::cout<<"ERROR: Logic deleted"<<std::endl;
          File<<A.sName()<<"#"<<A.sID()<<"#"<<A.sPhone()<<"#"<<A.sEmail()<<"#"<<A.sPayment()<<"#"<<A.sRFC()<<"#"<<A.sStatus()<<'\n';
      }
  }Read.close(); File.close();
    remove("Clientes.txt");
    rename("tmp.txt","Clientes.txt");
}
