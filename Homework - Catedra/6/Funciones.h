#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

char* ReturnChar(){
  //SOLICITAMOS USUARIO
    char *str;
    std::string Read;
    int LengthChar = 20; //ACOMODAR LA LONGITUD DEL CHAR
    while(true){
      std::cout<<"Read: ";
      getline(std::cin,Read);
      if(Read.length()<LengthChar){
        str = new char[Read.length()];
        strcpy(str, Read.c_str());
        return str;
      }
      else {
        std::cout << "VERY LONG: " << LengthChar - Read.length() << std::endl;
      }
    }
}


#endif
