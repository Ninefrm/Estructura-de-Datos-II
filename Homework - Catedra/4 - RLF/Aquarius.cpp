#include "Aquarius.h"

Aquarius addDate(Aquarius A){
  int day = 0;
  int month = 0;
  int year = 0;
  char tmp = 47;
  char a;
  char b;

  std::cout << "DATE:"<< std::endl;
  std::cin >> day >> a >> month >> b >> year;
    
  if ( day>0 && day< 32 && a == tmp && month >0 && month < 13 && b == tmp && year>2000 && year<2101 ){
    cout << "La fecha es correcta!" << endl;
    cout << "Fecha actual: " << day << tmp << month << tmp <<year <<endl;
  }else{
    cout << "Incorrecto el formato: DD/MM/AAAA";
  }
}
