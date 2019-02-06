#include <iostream>
#include <windows.h>

struct Aquarius{
  int CODE;
  char DATE[10];
  double PH;
  double SALINIDAD;
  double NITRITOS;
  double NITRATOS;
  double AMONIO;
};

int main (){
    Aquarius A;
    int dia = 0;
    int mes = 0;
    int anio = 0;
    char letra = 47;
    char a;
    char b;

    std::cout << "Entre la hora actual"<< std::endl;
    std::cin >> dia >> a >> mes >> b >> anio;

    if ( dia>0 && dia< 32 && a == letra && mes >0 && mes < 13 && b == letra && anio>2000 && anio<2101 ){
        std::cout << "La fecha es correcta!" << std::endl;
        std::cout << "Fecha actual: " << dia << letra << mes << letra <<anio <<std::endl;
    }else{
        std::cout << "Incorrecto el formato: DD/MM/AAAA";
    }

    for(int i = 0; i<10; i++){
      A.DATE[i] =
    }
    system("pause>null");

    return 0;
}
