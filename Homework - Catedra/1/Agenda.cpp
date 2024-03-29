#include "Agenda.h"
void Agenda::addContact(){
  std::string Name, Phone, Email;
  std::ofstream File("example.txt", std::ios::app);
  std::cout<<"Name: ";
  getline(std::cin,Name);
  std::cout<<"Phone: ";
  getline(std::cin,Phone);
  std::cout<<"Email: ";
  getline(std::cin,Email);
  C.addName(Name);
  C.addPhone(Phone);
  C.addEmail(Email);

  File<<C.rName()<<"#"<<C.rPhone()<<"#"<<C.rEmail()<<'\n';
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
      getline(Read,Tmp,'\n');
      C.addEmail(Tmp);
      if(Read.eof())break;
      std::cout<<C.rName()<<" "<<C.rPhone()<<" "<<C.rEmail()<<std::endl;
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
      getline(Read,Tmp,'\n');
      C.addEmail(Tmp);
      if(Read.eof())break;
      if(sName == C.rName()) std::cout<<C.rName()<<" "<<C.rPhone()<<" "<<C.rEmail()<<std::endl;
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
    getline(Read,Tmp,'\n');
    C.addEmail(Tmp);
    if(Read.eof())break;
    if(sName == C.rName()){
      while(A){
        std::cout<<"Edit: "<<std::endl;
        std::cout<<"1.Name"<<std::endl;
        std::cout<<"2.Phone"<<std::endl;
        std::cout<<"3.Email"<<std::endl;
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
          default:
          A=0;
          break;
        }
      }
    }
    File<<C.rName()<<"#"<<C.rPhone()<<"#"<<C.rEmail()<<'\n';
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
    getline(Read,Tmp,'\n');
    C.addEmail(Tmp);
    if(Read.eof())break;
    if(sName != C.rName()){
      File<<C.rName()<<"#"<<C.rPhone()<<"#"<<C.rEmail()<<'\n';
    }
  }Read.close(); File.close();
  remove("example.txt");
  rename("tmp.txt","example.txt");
}
