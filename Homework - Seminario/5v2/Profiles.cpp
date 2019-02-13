#include "Profiles.h"

void Profile::Add(){
  int Tmp;
  Username();
  Password();
  std::cout<<"Permissions: "<<std::endl;
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

void Profile::Show(){
  std::ifstream leer("Perfiles.txt");
  if(!leer.is_open())
      std::cout<<"No records found"<<std::endl;
  else{
      while(!leer.eof()){
          leer.read((char*)&A,sizeof(A));
          if(leer.eof())break;
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

void Profile::Edit(){
  char *strUsername;
  std::string Username;
  std::cout<<"Username:";
  int OP, Tmp;
  getline(std::cin,Username);
  if(Username.length()<10){
    strUsername = new char[Username.length()];
    strcpy(strUsername, Username.c_str());

    std::fstream leer("Perfiles.txt");
    if(!leer.is_open()){
      std::cout<<"Sali aquí";
    }
    else{
      for(int i=0; !leer.eof();i=i+sizeof(A)){
        //std::cout<<"Hola"<<i;
        leer.seekp(i,leer.beg);
        leer.read((char*)&A,sizeof(A));
        //std::cout<<A.Username<<" "<<strUsername<<std::endl;
        if(strcmp(A.Username,strUsername)==0){
          leer.seekp(i,leer.beg);
          std::cout<<"1.- Password"<<std::endl;
          std::cout<<"2.- Can the profile add clients?"<<std::endl;
          std::cout<<"3.- Can the profile search clients?"<<std::endl;
          std::cout<<"4.- Can the profile show clients?"<<std::endl;
          std::cout<<"5.- Can the profile modify clients?"<<std::endl;
          std::cout<<"6.- Can the profile logically delete clients?"<<std::endl;
          std::cout<<"7.- Can the profile create/see profiles?"<<std::endl;
          std::cout<<"8.- Status"<<std::endl;
          std::cin>>OP;
          std::cin.ignore();
          switch(OP){
            case 1:
            if(A.Status == 1){
            Password();
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 2:
            if(A.Status == 1){
            std::cout<<"Permissions: "<<std::endl;
            std::cout<<"Can the profile add clients?: ";
            std::cin>>Tmp;
            A.Permissions1 = Tmp;
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 3:
            if(A.Status == 1){
            std::cout<<"Can the profile search clients?: ";
            std::cin>>Tmp;
            A.Permissions2 = Tmp;
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 4:
            if(A.Status == 1){
            std::cout<<"Can the profile show clients?: ";
            std::cin>>Tmp;
            A.Permissions3 = Tmp;
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 5:
            if(A.Status == 1){
            std::cout<<"Can the profile modify clients?: ";
            std::cin>>Tmp;
            A.Permissions4 = Tmp;
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 6:
            if(A.Status == 1){
            std::cout<<"Can the profile logically delete clients?: ";
            std::cin>>Tmp;
            A.Permissions5 = Tmp;
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 7:
            if(A.Status == 1){
            std::cout<<"Can the profile create/see profiles?: ";
            std::cin>>Tmp;
            A.Permissions6 = Tmp;
            }
            else{
              std::cout<<"Logic deleted"<<std::endl;
            }
            break;
            case 8:

            std::cout<<"Status: ";
            std::cin>>Tmp;
            A.Status = Tmp;

            break;
          }
          leer.write((char*)&A,sizeof(A));
          leer.close();
          break;
        }
        if(strcmp(A.Username,strUsername)==0 && A.Status==0)
        {
            std::cout<<"LOGIC DELETED";
            break;
        }
        else
            continue;

      }

    }

  }
  else {
    std::cout << "Usuario muy larga" << std::endl;
  }
}

void Profile::Username(){
  char *strUsername;
  std::string Username;
  while(true){
    std::cout<<"Username:";
    getline(std::cin,Username);
    if(Username.length()<10){
      strUsername = new char[Username.length()];
      strcpy(strUsername, Username.c_str());
      if(RepeatedProfile(strUsername)){
        strcpy(A.Username,strUsername);
        break;
      }
      else{
        std::cout << "Usuario repetido" << std::endl;
      }
    }
    else {
      std::cout << "Usuario muy larga" << std::endl;
    }
  }
}
void Profile::Password(){
  char *strUsername;
  std::string Username;
  while(true){
    std::cout<<"Password:";
    getline(std::cin,Username);
    if(Username.length()<10){
      strUsername = new char[Username.length()];
      strcpy(strUsername, Username.c_str());
        strcpy(A.Password,strUsername);
        break;
    }
    else {
      std::cout << "Contraseña muy larga" << std::endl;
    }
  }
}

void Profile::Delete(char *sUsername){
  std::ifstream leer("Perfiles.txt");
  std::ofstream Tmp("Temp.txt");
  char *strUsername;
  std::string Username;
  std::cout<<"Username:";
  getline(std::cin,Username);
  if(Username.length()<10){
    strUsername = new char[Username.length()];
    strcpy(strUsername, Username.c_str());
  }

  if(!leer.is_open())
      std::cout<<"No records found"<<std::endl;
  else{
      while(!leer.eof()){
          leer.read((char*)&A,sizeof(A));
          if(strcmp(A.Username,strUsername)==0 && A.Status == 1 && W.HaveClients(Username)==false && Username != sUsername){

          }
          else{
            if(leer.eof()) break;
            if(strcmp(A.Username,strUsername)==0 && A.Status == 0)std::cout<<"Logic Deleted";
            Tmp.write((char*)&A,sizeof(A));
          }
      }
      leer.close();
      Tmp.close();
    }
    remove("Perfiles.txt");
    rename("Temp.txt","Perfiles.txt");
}

bool Profile::RepeatedProfile(char *strUsername){
  std::ifstream leer("Perfiles.txt");
  if(!leer.is_open()){
    std::cout<<"Sali aquí";
    return true;
  }
  else{
    for(int i=0; !leer.eof();i=i+sizeof(A)){
      //std::cout<<"Hola"<<i;
      leer.seekg(i,leer.beg);
      leer.read((char*)&A,sizeof(A));
      //std::cout<<A.Username<<" "<<strUsername<<std::endl;
      if(strcmp(A.Username,strUsername)==0){
        std::cout<<"Sali aquí1";
        return false;
      }

    }
    leer.close();
    return true;
  }
}
