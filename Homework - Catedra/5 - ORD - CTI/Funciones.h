#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_
#include <iostream>

int CharToInt(char A){
  if(A == 48){
    return 0;
  }
  else if(A == 49){
    return 1;
  }
  else if(A == 50){
    return 2;
  }
  else if(A == 51){
    return 3;
  }
  else if(A == 52){
    return 4;
  }
  else if(A == 53){
    return 5;
  }
  else if(A == 54){
    return 6;
  }
  else if(A == 55){
    return 7;
  }
  else if(A == 56){
    return 8;
  }
  else if(A == 57){
    return 9;
  }
  return false;
}

long double DateToInt(char DATE[]){
  long double iDATE, Dm, Um, Cml, Dml, Uml, C, D, U;

  Dm = 10000000*CharToInt(DATE[0]);
  Um = 1000000*CharToInt(DATE[1]);
  Cml = 100000*CharToInt(DATE[3]);
  Dml = 10000*CharToInt(DATE[4]);
  Uml = 1000*CharToInt(DATE[6]);
  C = 100*CharToInt(DATE[7]);
  D = 10*CharToInt(DATE[8]);
  U = CharToInt(DATE[9]);

  iDATE = Dm + Um + Cml + Dml + Uml + C + D + U;

  // std::cout<<Dm<<std::endl;
  // std::cout<<Um<<std::endl;
  // std::cout<<Cml<<std::endl;
  // std::cout<<Dml<<std::endl;
  // std::cout<<Uml<<std::endl;
  // std::cout<<C<<std::endl;
  // std::cout<<D<<std::endl;
  // std::cout<<U<<std::endl;
  return iDATE;
}

void Ordenamiento(){
  char FishBowlCode[];
  char FishBowlDATE[];
  int x=0;
  ifstream leer("peceras.txt");
  if(!leer.is_open())cout<<"No records found"<<std::endl;
  else{
      while(!leer.eof()){
        leer.read((char*)&p,sizeof(p));
        if(leer.eof())break;
          if(p.STATUS==1){
              FishBowlCode[x] = p.CODE;
              FishBowlDATE[x] = p.DATE;
          }
        x++;
      }
      leer.close();
  }

}


#endif
