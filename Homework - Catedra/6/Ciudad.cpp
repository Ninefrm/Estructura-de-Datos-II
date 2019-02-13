#include "Ciudad.h"

void Ciudad::Add(){
  int Tmp;


  std::cout<<"COLONIA: "<<std::endl;
  std::cout<<"NAME: ";
  A.Name = ReturnChar();
  std::cout<<"SECTOR: ";
  A.Sector = ReturnChar();
  std::cout<<"LONGITUD: ";
  std::cin>>Tmp;
  A.Longitud = Tmp;
  std::cout<<"LATITUD: ";
  std::cin>>Tmp;
  A.Latitud = Tmp;
  std::ofstream escribir("Perfiles.txt",std::ios::app);
  escribir.write((char*)&A,sizeof(A));
  escribir.close();
}
