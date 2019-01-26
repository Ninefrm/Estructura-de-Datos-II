#include <iostream>
#include <string>
#include <fstream>

std::string Emailcheck(std::string Email);

int main(){
  std::string Email;
  std::cout<<"Email: ";
  getline(std::cin,Email);
  Emailcheck(Email);
  return 0;
}

std::string Emailcheck(std::string Email){
  std::string identificador, dominio, servidor, Tmp;
  std::ofstream File("email.txt", std::ios::app);
  File<<Email<<std::endl;

  std::ofstream File2("email2.txt", std::ios::app);
  std::ifstream Read("email.txt");
      getline(Read,Tmp,'@');
      identificador = Tmp;
      getline(Read,Tmp,'.');
      servidor = Tmp;
      //getline(Read,Tmp,'#');
      //C.addEmail(Tmp);
      getline(Read,Tmp,'\n');
      dominio=Tmp;
      //std::cout<<C.rStatus()<<std::endl;
  File.close();
  Read.close();
  remove("email.txt");
  for (int i=0; i<identificador.length();i++){
    for(int j=0; j<25; j++){
      if(identificador[i] == (char)(j+65) || identificador[i] == (char)(j+97)){
        std::cout<<"_"<<identificador[i]<<"_"<<std::endl;
      }
      /*else{
        std::cout<<"Error"<<std::endl;
      }*/
    }
  }

  File2<<identificador<<std::endl;
  File2<<servidor<<std::endl;
  File2<<dominio<<std::endl;
}
