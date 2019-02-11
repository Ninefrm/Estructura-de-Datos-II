#include "Login.h"

bool Login::Sesion(){
  int Intentos=0;
  int W = 1;
  int OP, X;
  User Access;
  std::string Tmp;
  while(Intentos < 3){
    char* Usuario = Username();
    char* Pass = Password();

    if(Verify(Usuario, Pass)){
      std::cout<<"LO LOGRASTE"<<std::endl;
      Access = Copy(Usuario,Pass);
        std::string Owner(Access.Username);
//INICIAR LA VENTA
        // system("cls");
        while(W){
          std::cout<<"\t \t \t Transportes Terrestres."<<std::endl;
          std::cout<<" \n USERNAME: "<<Usuario<<std::endl;
          std::cout<<" \n \n \t1.- ADD CLIENT."<<std::endl;
          std::cout<<"\t2.- SHOW CLIENTS."<<std::endl;
          std::cout<<"\t3.- SEARCH CLIENT."<<std::endl;
          std::cout<<"\t4.- EDIT CLIENT."<<std::endl;
          std::cout<<"\t5.- DELETE CLIENT."<<std::endl;
          std::cout<<"\t6.- Add Profile."<<std::endl;
          std::cout<<"\t7.- Show Profile."<<std::endl;
          std::cout<<"\t8.- Edit Profile."<<std::endl;
          std::cout<<"\t9.- Delete Profile."<<std::endl;
          std::cout<<"\t10.- Exit."<<std::endl;
          std::cin>>OP;
          std::cin.ignore();
          switch ( OP) {
            case 1:
            if(Access.Permissions1){
              V.addClient(Owner);
            }
            else{
              std::cout<<"Access denied"<<std::endl;
            }
              break;

            case 2:
            if(Access.Permissions3){
              V.ShowClients(Owner);
            }
            else{
              std::cout<<"Access denied"<<std::endl;
            }
              break;

            case 3:
            if(Access.Permissions2){
              std::cout<<"Name: "<<std::endl;
                getline(std::cin, Tmp);
                V.Search(Tmp,Owner);
            }
            else{
              std::cout<<"Access denied"<<std::endl;
            }

              break;

            case 4:
            if(Access.Permissions4){
              std::cout<<"Name: "<<std::endl;
                getline(std::cin, Tmp);
                V.Edit(Tmp,Owner);
            }
            else{
              std::cout<<"Access denied"<<std::endl;
            }

              break;

            case 5:
            if(Access.Permissions5){
              std::cout<<"Name: "<<std::endl;
                getline(std::cin, Tmp);
                V.Delete(Tmp,Owner);
            }
            else{
              std::cout<<"Access denied"<<std::endl;
            }

              break;
            case 6:
            if(Access.Permissions6){
              P.Add();
            }
            else{
              std::cout<<"Access denied"<<std::endl;
            }
              break;
            case 7:
            if(Access.Permissions5){
              P.Show();
            }
            else{
              std::cout<<"Access denied"<<std::endl;
            }
              break;
            case 8:
            if(Access.Permissions1 && Access.Permissions2 && Access.Permissions3 && Access.Permissions4 && Access.Permissions5 && Access.Permissions6){
              P.Edit();
            }
            else{
              std::cout<<"Access denied"<<std::endl;
            }
              break;
            case 9:
            if(Access.Permissions1 && Access.Permissions2 && Access.Permissions3 && Access.Permissions4 && Access.Permissions5 && Access.Permissions6){
              P.Delete();
            }
            else{
              std::cout<<"Access denied"<<std::endl;
            }
              break;
            case 10:
              W=0;
            break;
            default:
            W=0;
            break;
          }
        }
///VENTAS

      Intentos = 0;
      break;
    }
    else {
      Intentos++;
    }
  }
  return true;
}

char* Login::Username(){
  //SOLICITAMOS USUARIO
    char *strUsername;
    std::string Username;
    while(true){
      std::cout<<"Username:";
      getline(std::cin,Username);
      if(Username.length()<10){
        strUsername = new char[Username.length()];
        strcpy(strUsername, Username.c_str());
        return strUsername;
      }
      else {
        std::cout << "Usuario muy largo" << std::endl;
      }
    }
}

char* Login::Password(){
  //SOLICITAMOS CONTRASEÑA
      char *strPassword;
      std::string Password;
      while(true){
        std::cout<<"Password:";
        getline(std::cin,Password);
        if(Password.length()<10){
          strPassword = new char[Password.length()];
          strcpy(strPassword, Password.c_str());
          return strPassword;
        }
        else {
          std::cout << "Contraseña muy larga" << std::endl;
        }
      }
}

bool Login::Verify(char *strUsername, char *strPassword){
  //BUSCAMOS COINCIDENCIA DE USUARIO Y CONTRASEÑA
      std::ifstream leer("Perfiles.txt");
      if(!leer.is_open()){

        return false;
      }
      else{
        for(int i=0; !leer.eof();i=i+sizeof(P.A)){
          //std::cout<<"Hola"<<i;
          leer.seekg(i,leer.beg);
          leer.read((char*)&P.A,sizeof(P.A));
          //std::cout<<A.Username<<" "<<strUsername<<std::endl;
          if(strcmp(P.A.Username,strUsername)==0 && strcmp(P.A.Password,strPassword)==0 && P.A.Status == 1){

            return true;
          }
          if(strcmp(P.A.Username,strUsername)==0 && strcmp(P.A.Password,strPassword)==0 && P.A.Status == 0){
            std::cout<<" Account Locked"<<std::endl;
          }

        }
        leer.close();
        return false;
      }
}

User Login::Copy(char *strUsername, char *strPassword){
  User W;
  std::ifstream leer("Perfiles.txt");
  for(int i=0; !leer.eof();i=i+sizeof(P.A)){
    //std::cout<<"Hola"<<i;
    leer.seekg(i,leer.beg);
    leer.read((char*)&P.A,sizeof(P.A));
    //std::cout<<A.Username<<" "<<strUsername<<std::endl;
    if(strcmp(P.A.Username,strUsername)==0 && strcmp(P.A.Password,strPassword)==0){
      strcpy(W.Username,P.A.Username);
      strcpy(W.Password,P.A.Password);
      W.Permissions1 = P.A.Permissions1;
      W.Permissions2 = P.A.Permissions2;
      W.Permissions3 = P.A.Permissions3;
      W.Permissions4 = P.A.Permissions4;
      W.Permissions5 = P.A.Permissions5;
      W.Permissions6 = P.A.Permissions6;
      W.Status = P.A.Status;
      break;
    }
    std::cout<<W.Status;
  }
  return W;
}
