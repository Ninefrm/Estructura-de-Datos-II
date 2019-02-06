#include "Usuario.h"

void Usuario::NewUser(){
  std::string Name, Code, Password, Status="1", OfCode;
  std::ofstream File("Usuarios.txt", std::ios::app);
  std::cout<<"Code: ";
  getline(std::cin,Code);
  std::cout<<"Name: ";
  getline(std::cin,Name);
  std::cout<<"Password: ";
  getline(std::cin,Password);
  std::cout<<"Office Code: ";
  getline(std::cin,OfCode);
  //while(C){
    //std::cout<<"Email: ";
    //getline(std::cin,Email);
    //if(Emailcheck(Email)){
      //C=0;
    //}
  //}
  int CodeSize = (Code.size());
  int NameSize = (Name.size());
  int PasswordSize = (Password.size());
  int OfCodeSize = (OfCode.size());
  int StatusSize = (Status.size());

  File.write(reinterpret_cast<char *>(&CodeSize), sizeof(int));
  File.write(Code.c_str(),CodeSize);

  File.write(reinterpret_cast<char *>(&NameSize), sizeof(int));
  File.write(Name.c_str(),NameSize);

  File.write(reinterpret_cast<char *>(&PasswordSize), sizeof(int));
  File.write(Password.c_str(),PasswordSize);

  File.write(reinterpret_cast<char *>(&OfCodeSize), sizeof(int));
  File.write(OfCode.c_str(),OfCodeSize);

  File.write(reinterpret_cast<char *>(&StatusSize), sizeof(int));
  File.write(Status.c_str(),StatusSize);

  File.flush();
  File.close();
}

void Usuario::showUsers(){
  char *buf;
  std::string Name, Code, Password, Status="1", OfCode;
  std::ifstream File("Usuarios.txt");
  int CodeSize;
  int NameSize;
  int PasswordSize;
  int OfCodeSize;
  int StatusSize;
  std::cout<<"CODE "<<"\t \tNAME "<<"\t \t PASSWORD "<<"\t \t OFFICE CODE "<<std::endl;

  while(!File.eof()){
    File.read(reinterpret_cast<char *>(&CodeSize), sizeof(int));
    buf = new char[CodeSize];
    File.read(buf,CodeSize);
    Code="";
    Code.append(buf,CodeSize);

    File.read(reinterpret_cast<char *>(&NameSize), sizeof(int));
    buf = new char[NameSize];
    File.read(buf,NameSize);
    Name="";
    Name.append(buf,NameSize);

    File.read(reinterpret_cast<char *>(&PasswordSize), sizeof(int));
    buf = new char[PasswordSize];
    File.read(buf,PasswordSize);
    Password="";
    Password.append(buf,PasswordSize);

    File.read(reinterpret_cast<char *>(&OfCodeSize), sizeof(int));
    buf = new char[OfCodeSize];
    File.read(buf,OfCodeSize);
    OfCode="";
    OfCode.append(buf,OfCodeSize);

    File.read(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    buf = new char[StatusSize];
    File.read(buf,StatusSize);
    Status="";
    Status.append(buf,StatusSize);

    if(File.eof())break;
  if(Status == "1")std::cout<<Code<<"\t"<<"\t"<<Name<<"\t"<<"\t"<<Password<<"\t"<<"\t"<<OfCode<<std::endl;
  }File.close();
}
void Usuario::searchUsers(std::string sCode){
  char *buf;
  std::string Name, Code, Password, Status="1", OfCode;
  std::ifstream File("Usuarios.txt");
  int CodeSize;
  int NameSize;
  int PasswordSize;
  int OfCodeSize;
  int StatusSize;
  std::cout<<"CODE "<<"\t \tNAME "<<"\t \t PASSWORD "<<"\t \t OFFICE CODE "<<std::endl;

  while(!File.eof()){
    File.read(reinterpret_cast<char *>(&CodeSize), sizeof(int));
    buf = new char[CodeSize];
    File.read(buf,CodeSize);
    Code="";
    Code.append(buf,CodeSize);

    File.read(reinterpret_cast<char *>(&NameSize), sizeof(int));
    buf = new char[NameSize];
    File.read(buf,NameSize);
    Name="";
    Name.append(buf,NameSize);

    File.read(reinterpret_cast<char *>(&PasswordSize), sizeof(int));
    buf = new char[PasswordSize];
    File.read(buf,PasswordSize);
    Password="";
    Password.append(buf,PasswordSize);

    File.read(reinterpret_cast<char *>(&OfCodeSize), sizeof(int));
    buf = new char[OfCodeSize];
    File.read(buf,OfCodeSize);
    OfCode="";
    OfCode.append(buf,OfCodeSize);

    File.read(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    buf = new char[StatusSize];
    File.read(buf,StatusSize);
    Status="";
    Status.append(buf,StatusSize);

    if(File.eof())break;
  if(sCode == Code)std::cout<<Code<<"\t"<<"\t"<<Name<<"\t"<<"\t"<<Password<<"\t"<<"\t"<<OfCode<<std::endl;
  }File.close();

}
void Usuario::EditUsers(std::string sCode){
  char *buf;
  std::string Name, Code, Password, Status="1", OfCode, Tmp;
  std::ifstream File("Usuarios.txt");
  std::ofstream Temp("tmp.txt", std::ios::app);
  int CodeSize;
  int NameSize;
  int PasswordSize;
  int OfCodeSize;
  int StatusSize;
  int A = 1, OP;
  std::cout<<"CODE "<<"\t \tNAME "<<"\t \t PASSWORD "<<"\t \t OFFICE CODE "<<std::endl;

  while(!File.eof()){
    File.read(reinterpret_cast<char *>(&CodeSize), sizeof(int));
    buf = new char[CodeSize];
    File.read(buf,CodeSize);
    Code="";
    Code.append(buf,CodeSize);

    File.read(reinterpret_cast<char *>(&NameSize), sizeof(int));
    buf = new char[NameSize];
    File.read(buf,NameSize);
    Name="";
    Name.append(buf,NameSize);

    File.read(reinterpret_cast<char *>(&PasswordSize), sizeof(int));
    buf = new char[PasswordSize];
    File.read(buf,PasswordSize);
    Password="";
    Password.append(buf,PasswordSize);

    File.read(reinterpret_cast<char *>(&OfCodeSize), sizeof(int));
    buf = new char[OfCodeSize];
    File.read(buf,OfCodeSize);
    OfCode="";
    OfCode.append(buf,OfCodeSize);

    File.read(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    buf = new char[StatusSize];
    File.read(buf,StatusSize);
    Status="";
    Status.append(buf,StatusSize);

    if(File.eof())break;
  if(sCode == Code){
    while(A){
      std::cout<<"Edit: "<<std::endl;
      std::cout<<"1.Code"<<std::endl;
      std::cout<<"2.Name"<<std::endl;
      std::cout<<"3.Password"<<std::endl;
      std::cout<<"4.OfCode"<<std::endl;
      std::cout<<"5.Status"<<std::endl;
      std::cin>>OP;
      std::cin.ignore();
      switch (OP) {
        case 1:
        if(Status == "1"){
          std::cout<<"Code: "<<std::endl;
          getline(std::cin, Tmp);
            Code = Tmp;
        }
        else{
          std::cout<<"Logic Deleted"<<std::endl;
        }
        break;
        case 2:
        if(Status == "1"){
          std::cout<<"Name: "<<std::endl;
          getline(std::cin, Tmp);
            Name = Tmp;
        }
        else{
          std::cout<<"Logic Deleted"<<std::endl;
        }
        break;
        case 3:
        if(Status == "1"){
          std::cout<<"Password: "<<std::endl;
          getline(std::cin, Tmp);
            Password = Tmp;
        }
        else{
          std::cout<<"Logic Deleted"<<std::endl;
        }
        break;
        case 4:
        if(Status == "1"){
          std::cout<<"Office Code: "<<std::endl;
          getline(std::cin, Tmp);
            OfCode = Tmp;
        }
        else{
          std::cout<<"Logic Deleted"<<std::endl;
        }
        break;
        case 5:
        std::cout<<"Status:"<<std::endl;
        getline(std::cin, Tmp);
          Status = Tmp;
        default:
        A=0;
        break;
        }
      }
    }
    int CodeSize = (Code.size());
    int NameSize = (Name.size());
    int PasswordSize = (Password.size());
    int OfCodeSize = (OfCode.size());
    int StatusSize = (Status.size());

    Temp.write(reinterpret_cast<char *>(&CodeSize), sizeof(int));
    Temp.write(Code.c_str(),CodeSize);

    Temp.write(reinterpret_cast<char *>(&NameSize), sizeof(int));
    Temp.write(Name.c_str(),NameSize);

    Temp.write(reinterpret_cast<char *>(&PasswordSize), sizeof(int));
    Temp.write(Password.c_str(),PasswordSize);

    Temp.write(reinterpret_cast<char *>(&OfCodeSize), sizeof(int));
    Temp.write(OfCode.c_str(),OfCodeSize);

    Temp.write(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    Temp.write(Status.c_str(),StatusSize);
  }Temp.flush(); Temp.close(); File.close();
  remove("Usuarios.txt");
  rename("tmp.txt","Usuarios.txt");
}
//void Usuario::logicDelete(){

//}

int Usuario::login(std::string sCode, std::string sPassword){
  char *buf;
  std::string Name, Code, Password, Status="1", OfCode;
  std::ifstream File("Usuarios.txt");
  int CodeSize;
  int NameSize;
  int PasswordSize;
  int OfCodeSize;
  int StatusSize;

  while(!File.eof()){
    File.read(reinterpret_cast<char *>(&CodeSize), sizeof(int));
    buf = new char[CodeSize];
    File.read(buf,CodeSize);
    Code="";
    Code.append(buf,CodeSize);

    File.read(reinterpret_cast<char *>(&NameSize), sizeof(int));
    buf = new char[NameSize];
    File.read(buf,NameSize);
    Name="";
    Name.append(buf,NameSize);

    File.read(reinterpret_cast<char *>(&PasswordSize), sizeof(int));
    buf = new char[PasswordSize];
    File.read(buf,PasswordSize);
    Password="";
    Password.append(buf,PasswordSize);

    File.read(reinterpret_cast<char *>(&OfCodeSize), sizeof(int));
    buf = new char[OfCodeSize];
    File.read(buf,OfCodeSize);
    OfCode="";
    OfCode.append(buf,OfCodeSize);

    File.read(reinterpret_cast<char *>(&StatusSize), sizeof(int));
    buf = new char[StatusSize];
    File.read(buf,StatusSize);
    Status="";
    Status.append(buf,StatusSize);

    if(File.eof())break;
  if(sCode == Code && sPassword == Password && Status == "1")return 1;
  }File.close();
  return 0;
}
