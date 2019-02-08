#include "Funciones.h"
#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) {
  char DATE[]={'2','0','/','1','1','/','1','9','9','7'};
  char DATE2[]={'2','7','/','1','0','/','2','0','0','1'};
  // for(int i = 0; i < 10; i++){
  //   std::cout<<DATE[i]<<std::endl;
  // }
  if(DateToInt(DATE) < DateToInt(DATE2)){
    std::cout<<std::fixed<<DateToInt(DATE2);
  }
  else if(DateToInt(DATE) > DateToInt(DATE2)){
    std::cout<<std::fixed<<DateToInt(DATE)<<std::endl;
  }
  return 0;
}
