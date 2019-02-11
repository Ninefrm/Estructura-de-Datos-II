#include "AddProfile.h"

void AddProfile::Add(){
  int Tmp;
  Username();
  Password();
  std::cout<<"Permissions: ";
  std::cout<<"Can the profile add clients?: ";
  std::cin>>Tmp;
  A.Permissions1 = Tmp;
  std::cout<<"Can the profile search clients?: ";
  std::cin>>Tmp;
  A.Permissions2 = Tmp;
  std::cout<<"Can the profile show clients?: ";
  std::cin>>Tmp;
  A.Permissions3 = Tmp;
  std::cout<<"Can the profile modify clients?: ";
  std::cin>>Tmp;
  A.Permissions4 = Tmp;
  std::cout<<"Can the profile logically delete clients?: ";
  std::cin>>Tmp;
  A.Permissions5 = Tmp;
  std::cout<<"Can the profile create/see profiles?: ";
  std::cin>>Tmp;
  A.Permissions6 = Tmp;
  A.Status = 1;
  std::ofstream escribir("Perfiles.txt",std::ios::app);
  escribir.write((char*)&A,sizeof(A));
  escribir.close();
}

void AddProfile::Show(){
  std::ifstream leer("Perfiles.txt");
  if(!leer.is_open())std::cout<<"No records found"<<std::endl;
  else{

      while(!leer.eof()){

          leer.read((char*)&A,sizeof(A));

          // if(leer.eof()){
          //   std::cout<<"HOLA";
          //   break;
          // }
          std::cout<<A.Status;
          if(A.Status==1){
            std::cout<<"Profile: "<<A.Username<<std::endl;;
            std::cout<<"Password: "<<A.Password<<std::endl;;
            std::cout<<"Permissions: "<<std::endl;
              std::cout<<A.Permissions1<<std::endl;
              std::cout<<A.Permissions2<<std::endl;
              std::cout<<A.Permissions3<<std::endl;
              std::cout<<A.Permissions4<<std::endl;
              std::cout<<A.Permissions5<<std::endl;
              std::cout<<A.Permissions6<<std::endl;
            std::cout<<"Status: "<<A.Status<<std::endl;
          }
      }
      leer.close();
  }
}

void AddProfile::Edit(){
  std::fstream leer("Perfiles.txt");
  char *strUsername;
  std::string Username;
  int Tmp;
  while(true){
      std::cout << "Username: ";
      getline(std::cin, Username);
      strUsername = new char[Username.length()];
      strcpy(strUsername, Username.c_str());
      std::cout << strlen(strUsername) << std::endl;
      if(strlen(strUsername)<10){
          break;
      }
      else{

          std::cout << "Usuario muy larga." << std::endl;
      }
  }

  if(!leer.is_open())std::cout<<"No records found"<<std::endl;



  else{
    for(int i=0;!leer.eof();i=i+sizeof(A)){
      leer.seekg(i,leer.beg);
      leer.read((char*)&A,sizeof(A));
      if(strcmp(A.Username, strUsername) == 0 && A.Status == 1){
        leer.seekp(i,leer.beg);
        Password();
        std::cout<<"Permissions: ";
        std::cout<<"Can the profile add clients?: ";
        std::cin>>Tmp;
        A.Permissions1 = Tmp;
        std::cout<<"Can the profile search clients?: ";
        std::cin>>Tmp;
        A.Permissions2 = Tmp;
        std::cout<<"Can the profile show clients?: ";
        std::cin>>Tmp;
        A.Permissions3 = Tmp;
        std::cout<<"Can the profile modify clients?: ";
        std::cin>>Tmp;
        A.Permissions4 = Tmp;
        std::cout<<"Can the profile logically delete clients?: ";
        std::cin>>Tmp;
        A.Permissions5 = Tmp;
        std::cout<<"Can the profile create/see profiles?: ";
        std::cin>>Tmp;
        A.Permissions6 = Tmp;
        leer.write((char*)&A,sizeof(A));
        leer.close();
        break;
      }
      else if(strcmp (A.Username, strUsername) == 0 && A.Status == 0){
          std::cout<<"LOGIC DELETED";
          break;
      }
      else
          continue;
    }
  }
}

void AddProfile::Delete(){
  std::ifstream leer("Perfiles.txt");
  std::ofstream temp("Temp.txt");
  char *strUsername;
  std::string Username;
  int Tmp;
  while(true){
      std::cout << "Username: ";
      getline(std::cin, Username);
      strUsername = new char[Username.length()];
      strcpy(strUsername, Username.c_str());
      std::cout << strlen(strUsername) << std::endl;
      if(strlen(strUsername)<10){
          break;
      }
      else{

          std::cout << "Usuario muy larga." << std::endl;
      }
  }

  if(!leer.is_open())std::cout<<"No records found"<<std::endl;



  else{
    while(!leer.eof())
    {
        leer.read((char*)&A,sizeof(A));
        if(strcmp(A.Username, strUsername) == 0 && A.Status == 1)
            std::cout<<"DELETED."<<std::endl;
        else
        {
            if(leer.eof())
                break;
            if(strcmp(A.Username, strUsername) == 0 && A.Status == 0)
                std::cout<<"LOGIC DELETED.";
            temp.write((char*)&A,sizeof(A));
        }
    }
    leer.close();
    temp.close();
    remove("Perfiles.txt");
    rename("Temp.txt","Perfiles.txt");

}
}

void AddProfile::LogicDelete(){
  std::fstream leer("Perfiles.txt");
  char *strUsername;
  std::string Username;
  int Tmp;
  while(true){
      std::cout << "Username: ";
      getline(std::cin, Username);
      strUsername = new char[Username.length()];
      strcpy(strUsername, Username.c_str());
      std::cout << strlen(strUsername) << std::endl;
      if(strlen(strUsername)<10){
          break;
      }
      else{

          std::cout << "Usuario muy larga." << std::endl;
      }
  }

  if(!leer.is_open())std::cout<<"No records found"<<std::endl;



  else{
    for(int i=0;!leer.eof();i=i+sizeof(A)){
      leer.seekg(i,leer.beg);
      leer.read((char*)&A,sizeof(A));
      if(strcmp(A.Username, strUsername) == 0){
        leer.seekp(i,leer.beg);
        std::cin>>A.Status;
        leer.write((char*)&A,sizeof(A));
        leer.close();
        break;
      }
      else
          continue;
    }
  }
}

bool AddProfile::RepeatedProfile(char *strUsername){
  std::ifstream leer("Perfiles.txt");
  if(!leer.is_open()) return true;
  else{
    while(!leer.eof()){
        leer.read((char*)&A,sizeof(A));
        if(leer.eof())break;
      if(strcmp(A.Username, strUsername) == 0){
        return false;
        break;
      }
    }
    leer.close();
  }
  return true;
}

void AddProfile::Username(){
  char *strUsername;
  std::string Username;
  while(true){
      std::cout << "Username: ";
      getline(std::cin, Username);
      strUsername = new char[Username.length()];
      strcpy(strUsername, Username.c_str());
      std::cout << strlen(strUsername) << std::endl;
      if(strlen(strUsername)<10 && RepeatedProfile(strUsername)){
          strcpy(A.Username,strUsername);
          break;
      }
      else if(strlen(strUsername)>10){
          std::cout << "Usuario muy larga" << std::endl;
      }
      else if(RepeatedProfile(strUsername)==0){
          std::cout << "Usuario repetido" << std::endl;
      }
  }
}

void AddProfile::Password(){
  char *strPassword;
  std::string Password;
  while(true){
      std::cout << "Password: ";
      getline(std::cin, Password);
      strPassword = new char[Password.length()];
      strcpy(strPassword, Password.c_str());
      std::cout << strlen(strPassword) << std::endl;
      if(strlen(strPassword) < 10){
          strcpy(A.Password,strPassword);
          break;
      }
      else{
          std::cout << "Contraseña muy larga." << std::endl;
      }
  }
}
