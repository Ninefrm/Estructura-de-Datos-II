#include "Agenda.h"
void Agenda::addContact(){
  //int C=1;
  std::string Name, Phone, Email, Status="1";
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
  int StatusSize = (Status.size());

  File.write(reinterpret_cast<char *>(&NameSize), sizeof(int));
  File.write(Name.c_str(),NameSize);

  File.write(reinterpret_cast<char *>(&PhoneSize), sizeof(int));
  File.write(Phone.c_str(),PhoneSize);

  File.write(reinterpret_cast<char *>(&EmailSize), sizeof(int));
  File.write(Email.c_str(),EmailSize);

  File.write(reinterpret_cast<char *>(&StatusSize), sizeof(int));
  File.write(Status.c_str(),StatusSize);

  File.flush();
  File.close();
}
void Agenda::ShowContact(){
  char *buf;
  std::ifstream File("example.txt");
  std::string Name, Phone, Email, Status;
  int NameSize;
  int PhoneSize;
  int EmailSize;
  int StatusSize;
  std::cout<<"NAME "<<"\t \t PHONE "<<"\t \t EMAIL "<<std::endl;

  while(!File.eof()){
    File.read(reinterpret_cast<char *>(&NameSize), sizeof(int));
    buf = new char[NameSize];
    File.read(buf,NameSize);
    Name="";
    Name.append(buf,NameSize);

    File.read(reinterpret_cast<char *>(&PhoneSize), sizeof(int));
    buf = new char[PhoneSize];
    File.read(buf,PhoneSize);
    Phone="";
    Phone.append(buf,PhoneSize);

    File.read(reinterpret_cast<char *>(&EmailSize), sizeof(int));
    buf = new char[EmailSize];
    File.read(buf,EmailSize);
    Email="";
    Email.append(buf,EmailSize);

    File.read(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    buf = new char[StatusSize];
    File.read(buf,StatusSize);
    Status="";
    Status.append(buf,StatusSize);

    if(File.eof())break;
  if(Status == "1")std::cout<<Name<<"\t"<<"\t"<<Phone<<"\t"<<"\t"<<Email<<std::endl;
  }File.close();
}

void Agenda::SearchContact(std::string sName){
  char *buf;
  std::ifstream File("example.txt");
  std::string Name, Phone, Email, Status;
  int NameSize;
  int PhoneSize;
  int EmailSize;
  int StatusSize;
  std::cout<<"NAME "<<"\t \t PHONE "<<"\t \t EMAIL "<<std::endl;

  while(!File.eof()){
    File.read(reinterpret_cast<char *>(&NameSize), sizeof(int));
    buf = new char[NameSize];
    File.read(buf,NameSize);
    Name="";
    Name.append(buf,NameSize);


    File.read(reinterpret_cast<char *>(&PhoneSize), sizeof(int));
    buf = new char[PhoneSize];
    File.read(buf,PhoneSize);
    Phone="";
    Phone.append(buf,PhoneSize);

    File.read(reinterpret_cast<char *>(&EmailSize), sizeof(int));
    buf = new char[EmailSize];
    File.read(buf,EmailSize);
    Email="";
    Email.append(buf,EmailSize);

    File.read(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    buf = new char[StatusSize];
    File.read(buf,StatusSize);
    Status="";
    Status.append(buf,StatusSize);

    if(File.eof())break;
  if(sName == Name)std::cout<<Name<<"\t"<<"\t"<<Phone<<"\t"<<"\t"<<Email<<std::endl;
  }File.close();
}

void Agenda::EditContact(std::string sName){
  char *buf;
  std::string Tmp;
  std::ifstream File("example.txt");
  std::ofstream Temp("tmp.txt", std::ios::app);
  std::string Name, Phone, Email, Status;
  int NameSize;
  int PhoneSize;
  int EmailSize;
  int StatusSize;
  int A = 1, OP;
  std::cout<<"NAME "<<"\t \t PHONE "<<"\t \t EMAIL "<<std::endl;

  while(!File.eof()){
    File.read(reinterpret_cast<char *>(&NameSize), sizeof(int));
    buf = new char[NameSize];
    File.read(buf,NameSize);
    Name="";
    Name.append(buf,NameSize);

    File.read(reinterpret_cast<char *>(&PhoneSize), sizeof(int));
    buf = new char[PhoneSize];
    File.read(buf,PhoneSize);
    Phone="";
    Phone.append(buf,PhoneSize);

    File.read(reinterpret_cast<char *>(&EmailSize), sizeof(int));
    buf = new char[EmailSize];
    File.read(buf,EmailSize);
    Email="";
    Email.append(buf,EmailSize);

    File.read(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    buf = new char[StatusSize];
    File.read(buf,StatusSize);
    Status="";
    Status.append(buf,StatusSize);

    if(File.eof())break;
    if(sName == Name){
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
          if(Status == "1"){
            std::cout<<"Name: "<<std::endl;
            getline(std::cin, Tmp);
              Name = Tmp;
          }
          else{
            std::cout<<"Logic Deleted"<<std::endl;
          }
          break;
          case 2:
          if(Status == "1"){
            std::cout<<"Phone number:"<<std::endl;
            getline(std::cin, Tmp);
              Phone = Tmp;
          }else{
            std::cout<<"Logic Deleted"<<std::endl;
          }
          break;
          case 3:
          if(Status == "1"){
            std::cout<<"Email:"<<std::endl;
            getline(std::cin, Tmp);
              Email = Tmp;
          }else{
            std::cout<<"Logic Deleted"<<std::endl;
          }
          break;
          case 4:
          std::cout<<"Status:"<<std::endl;
          getline(std::cin, Tmp);
            Status = Tmp;
          default:
          A=0;
          break;
        }
      }
    }
    int NameSize = (Name.size());
    int PhoneSize = (Phone.size());
    int EmailSize = (Email.size());
    int StatusSize = (Status.size());

    Temp.write(reinterpret_cast<char *>(&NameSize), sizeof(int));
    Temp.write(Name.c_str(),NameSize);

    Temp.write(reinterpret_cast<char *>(&PhoneSize), sizeof(int));
    Temp.write(Phone.c_str(),PhoneSize);

    Temp.write(reinterpret_cast<char *>(&EmailSize), sizeof(int));
    Temp.write(Email.c_str(),EmailSize);

    Temp.write(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    Temp.write(Status.c_str(),StatusSize);

  }Temp.flush(); Temp.close(); File.close();
  remove("example.txt");
  rename("tmp.txt","example.txt");
}

void Agenda::DeleteContact(std::string sName){
  char *buf;
  std::string Tmp;
  std::ifstream File("example.txt");
  std::ofstream Temp("tmp.txt", std::ios::app);
  std::string Name, Phone, Email, Status;
  int NameSize;
  int PhoneSize;
  int EmailSize;
  int StatusSize;
  int A = 1, OP;
  std::cout<<"NAME "<<"\t \t PHONE "<<"\t \t EMAIL "<<std::endl;

  while(!File.eof()){
    File.read(reinterpret_cast<char *>(&NameSize), sizeof(int));
    buf = new char[NameSize];
    File.read(buf,NameSize);
    Name="";
    Name.append(buf,NameSize);


    File.read(reinterpret_cast<char *>(&PhoneSize), sizeof(int));
    buf = new char[PhoneSize];
    File.read(buf,PhoneSize);
    Phone="";
    Phone.append(buf,PhoneSize);

    File.read(reinterpret_cast<char *>(&EmailSize), sizeof(int));
    buf = new char[EmailSize];
    File.read(buf,EmailSize);
    Email="";
    Email.append(buf,EmailSize);

    File.read(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    buf = new char[StatusSize];
    File.read(buf,StatusSize);
    Status="";
    Status.append(buf,StatusSize);

    if(File.eof())break;
    if(sName != Name){
      int NameSize = (Name.size());
      int PhoneSize = (Phone.size());
      int EmailSize = (Email.size());
      int StatusSize = (Status.size());

      Temp.write(reinterpret_cast<char *>(&NameSize), sizeof(int));
      Temp.write(Name.c_str(),NameSize);

      Temp.write(reinterpret_cast<char *>(&PhoneSize), sizeof(int));
      Temp.write(Phone.c_str(),PhoneSize);

      Temp.write(reinterpret_cast<char *>(&EmailSize), sizeof(int));
      Temp.write(Email.c_str(),EmailSize);

      Temp.write(reinterpret_cast<char *>(&StatusSize), sizeof(int));
      Temp.write(Status.c_str(),StatusSize);

    }
    if(sName == Name && Status=="0"){
      std::cout<<"ERROR: Logic deleted"<<std::endl;
      int NameSize = (Name.size());
      int PhoneSize = (Phone.size());
      int EmailSize = (Email.size());
      int StatusSize = (Status.size());

      Temp.write(reinterpret_cast<char *>(&NameSize), sizeof(int));
      Temp.write(Name.c_str(),NameSize);

      Temp.write(reinterpret_cast<char *>(&PhoneSize), sizeof(int));
      Temp.write(Phone.c_str(),PhoneSize);

      Temp.write(reinterpret_cast<char *>(&EmailSize), sizeof(int));
      Temp.write(Email.c_str(),EmailSize);

      Temp.write(reinterpret_cast<char *>(&StatusSize), sizeof(int));
      Temp.write(Status.c_str(),StatusSize);
    }
  }Temp.flush(); Temp.close(); File.close();
  remove("example.txt");
  rename("tmp.txt","example.txt");
}
/*
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
}*/
// std::string Emailcheck(std::string Email){
//   std::string Name, Phone, Email, Tmp="1";
//   std::ofstream File("email.txt", std::ios::app);
//   File<<Email<<'\n';
//
// }
