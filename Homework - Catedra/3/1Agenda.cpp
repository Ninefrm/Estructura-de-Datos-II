#include "Agenda.h"
void Agenda::addContact(){
  //int C=1;
  std::string Name, Phone, Email, Tmp="1";
  std::ofstream File("example.txt", std::ios::app);
  std::cout<<"Name: ";
  getline(std::cin,Name);
  std::cout<<"Phone: ";
  getline(std::cin,Phone);
  //while(C){
    std::cout<<"Email: ";
    getline(std::cin,Email);
    //if(Emailcheck(Email)){
      //C=0;
    //}
  //}
  int NameSize = (Name.size());
  int PhoneSize = (Phone.size());
  int EmailSize = (Email.size());
  C.addName(Name);
  
  C.addPhone(Phone);
  C.addEmail(Email);
  C.addStatus(Tmp);

  File<<C.rName()<<"#"<<C.rPhone()<<"#"<<C.rEmail()<<"#"<<C.rStatus()<<'\n';
}
void Agenda::ShowContact(){
  std::string Tmp;
  std::ifstream Read("example.txt");
  if(!Read.good())
    std::cout<<"Error";
  else
    while(!Read.eof()){
      getline(Read,Tmp,'#');
      C.addName(Tmp);
      getline(Read,Tmp,'#');
      C.addPhone(Tmp);
      getline(Read,Tmp,'#');
      C.addEmail(Tmp);
      getline(Read,Tmp,'\n');
      C.addStatus(Tmp);
      if(Read.eof())break;
      //std::cout<<C.rStatus()<<std::endl;
      if(C.rStatus()=="1"){
          std::cout<<C.rName()<<" "<<C.rPhone()<<" "<<C.rEmail()<<std::endl;
      }
    }Read.close();
}

void Agenda::SearchContact(std::string sName){
  std::string Tmp;
  std::ifstream Read("example.txt");
  if(!Read.good())
    std::cout<<"Error";
  else
    while(!Read.eof()){
      getline(Read,Tmp,'#');
      C.addName(Tmp);
      getline(Read,Tmp,'#');
      C.addPhone(Tmp);
      getline(Read,Tmp,'#');
      C.addEmail(Tmp);
      getline(Read,Tmp,'\n');
      C.addStatus(Tmp);
      if(Read.eof())break;
      if(sName == C.rName()) std::cout<<C.rName()<<" "<<C.rPhone()<<" "<<C.rEmail()<<" "<<C.rStatus()<<std::endl;
    }Read.close();
}
void Agenda::EditContact(std::string sName){
  std::string Tmp;
  int A=1;
  int OP;
  std::ofstream File("tmp.txt", std::ios::app);
  std::ifstream Read("example.txt");
  while(!Read.eof()){
    getline(Read,Tmp,'#');
    C.addName(Tmp);
    getline(Read,Tmp,'#');
    C.addPhone(Tmp);
    getline(Read,Tmp,'#');
    C.addEmail(Tmp);
    getline(Read,Tmp,'\n');
    C.addStatus(Tmp);
    if(Read.eof())break;
    if(sName == C.rName()){
      while(A){
        std::cout<<"Edit: "<<std::endl;
        std::cout<<"1.Name"<<std::endl;
        std::cout<<"2.Phone"<<std::endl;
        std::cout<<"3.Email"<<std::endl;
        std::cout<<"4.Status"<<std::endl;
        std::cin>>OP;
        std::cin.ignore();
        switch (OP) {
          case 1:
          std::cout<<"Name: "<<std::endl;
          getline(std::cin, Tmp);
            C.addName(Tmp);
          break;
          case 2:
          std::cout<<"Phone number:"<<std::endl;
          getline(std::cin, Tmp);
            C.addPhone(Tmp);
          break;
          case 3:
          std::cout<<"Email:"<<std::endl;
          getline(std::cin, Tmp);
            C.addEmail(Tmp);
          break;
          case 4:
          std::cout<<"Status:"<<std::endl;
          getline(std::cin, Tmp);
            C.addStatus(Tmp);
          default:
          A=0;
          break;
        }
      }
    }
    File<<C.rName()<<"#"<<C.rPhone()<<"#"<<C.rEmail()<<"#"<<C.rStatus()<<'\n';
  }Read.close(); File.close();
  remove("example.txt");
  rename("tmp.txt","example.txt");
}
void Agenda::DeleteContact(std::string sName){
  std::string Tmp;
  int A=1;
  int OP;
  std::ofstream File("tmp.txt", std::ios::app);
  std::ifstream Read("example.txt");
  while(!Read.eof()){
    getline(Read,Tmp,'#');
    C.addName(Tmp);
    getline(Read,Tmp,'#');
    C.addPhone(Tmp);
    getline(Read,Tmp,'#');
    C.addEmail(Tmp);
    getline(Read,Tmp,'\n');
    C.addStatus(Tmp);
    if(Read.eof())break;
    if(sName != C.rName()){
      File<<C.rName()<<"#"<<C.rPhone()<<"#"<<C.rEmail()<<"#"<<C.rStatus()<<'\n';
    }
    if(sName == C.rName() && C.rStatus()=="0"){
      std::cout<<"ERROR: Logic deleted"<<std::endl;
        File<<C.rName()<<"#"<<C.rPhone()<<"#"<<C.rEmail()<<"#"<<C.rStatus()<<'\n';
    }
  }Read.close(); File.close();
  remove("example.txt");
  rename("tmp.txt","example.txt");
}
void Agenda::EditStatus(){
  std::string Tmp;
  std::ifstream Read("example.txt");
  if(!Read.good())
    std::cout<<"Error";
  else
    while(!Read.eof()){
      getline(Read,Tmp,'#');
      C.addName(Tmp);
      getline(Read,Tmp,'#');
      C.addPhone(Tmp);
      getline(Read,Tmp,'#');
      C.addEmail(Tmp);
      getline(Read,Tmp,'\n');
      C.addStatus(Tmp);
      if(Read.eof())break;
      std::cout<<C.rName()<<" "<<C.rPhone()<<" "<<C.rEmail()<<" "<<C.rStatus()<<std::endl;
    }Read.close();
}
// std::string Emailcheck(std::string Email){
//   std::string Name, Phone, Email, Tmp="1";
//   std::ofstream File("email.txt", std::ios::app);
//   File<<Email<<'\n';
//
// }
