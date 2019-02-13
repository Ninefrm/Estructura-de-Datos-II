#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>      // std::ifstream
#include "Colonia.h"
#include "Index.h"

using namespace std;

void Capturar(Colonia &Reg, FILE *fa);
void Insertar(FILE *fa, Colonia &reg);
void ReconstruirIndices(FILE *fa);
void EliminarRetornoLinea(char *cad);
void ListarPorTelefonos(FILE *fa);
void Name(Colonia &A, FILE *fa);
bool Repeated(char *strUsername, Colonia &A, FILE *fa);

int main(int argc, char const *argv[]) {
  Colonia Reg;
  FILE *fa;
  char Nombre[20];

  fa = fopen("Colonias.txt","r+b");
  if(!fa) fa = fopen ("Colonias.txt", "w+b");

  Capturar(Reg, fa);
  Insertar(fa, Reg);
  ListarPorTelefonos(fa);
  return 0;
}

void Capturar(Colonia &Reg, FILE *fa){
  int i;
  // char Nombre[20];
  // cout << "NAME: "<< endl;
  // fgets(Reg.Nombre, 20, stdin);
  // EliminarRetornoLinea(Reg.Nombre);
  Name(Reg, fa);
  cout << "SECTOR: "<< endl;
  fgets(Reg.Sector, 20, stdin);
  EliminarRetornoLinea(Reg.Sector);
  cout << "LONGITUD: "<< endl;
  cin>>Reg.Longitud;
  cout << "LATITUD: "<< endl;
  cin>>Reg.Latitud;
}

void Insertar(FILE *fa, Colonia &reg){
   // Insertar al final:
   fseek(fa, 0, SEEK_END);
   fwrite(&reg, sizeof(Colonia), 1, fa);
   ReconstruirIndices(fa);
}

void ReconstruirIndices(FILE *fa){
   long n=0;
   FILE *fi;
   Colonia Reg;
   Index Ind;

   // Crea el fichero de índices a partir del archivo de datos:
   fi = fopen("Index.txt","w+b");
   rewind(fa);
   while(fread(&Reg, sizeof(Colonia), 1, fa)) {
      strcpy(Ind.Nombre, Reg.Nombre);
      Ind.Indice = n++;
      fwrite(&Ind, sizeof(Index), 1, fi);
   }
   // Ordena usando el algoritmo Quicksort:
   //QuickSort(fi, 0, n-1);
   fclose(fi);
}

void EliminarRetornoLinea(char *cad){
   int i;
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(cad)-1; i >= 0 && cad[i] < ' '; i--) cad[i] = 0;
}

void ListarPorTelefonos(FILE *fa){
   FILE *fi;
   Index ind;
   Colonia reg;

   system("cls");
   fi = fopen("Index.txt", "rb");
   while(fread(&ind, sizeof(Index), 1, fi)) {
      fseek(fa, ind.Indice*sizeof(Colonia), SEEK_SET);
      fread(&reg, sizeof(Colonia), 1, fa);
      cout << reg.Nombre << reg.Sector << reg.Longitud << reg.Latitud << endl;
   }
   fclose(fi);
}

void Name(Colonia &A, FILE *fa){
  char *strName;
  std::string Name;
  while(true){
    std::cout<<"Name: ";
    getline(std::cin,Name);
    if(Name.length()<20){
      strName = new char[Name.length()];
      strcpy(strName, Name.c_str());
      if(Repeated(strName, A, fa)){
        cout<<"No repetido."<<endl;
        strcpy(A.Nombre,strName);
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

bool Repeated(char *strUsername, Colonia &A, FILE *fa){
  FILE *fi;
  Index ind;
  Colonia reg;
  // fi = fopen("Index.txt", "rb");
  // while(fread(&ind, sizeof(Index), 1, fi)) {
  //    fseek(fa, ind.Indice*sizeof(Colonia), SEEK_SET);
  //    fread(&reg, sizeof(Colonia), 1, fa);
  //      if(strcmp(A.Nombre,strUsername)==0){
  //        std::cout<<"Sali aquí1";
  //        return false;
  //      }
  //   }
  //   fclose(fi);
  //   return true;

    std::ifstream leer("Index.txt");
    if(!leer.is_open()){
      std::cout<<"Sali aquí";
      return true;
    }
    else{
      for(int i=0; !leer.eof();i=i+sizeof(A)){
        //std::cout<<"Hola"<<i;
        leer.seekg(i,leer.beg);
        leer.read((char*)&A,sizeof(Colonia));
        //std::cout<<A.Username<<" "<<strUsername<<std::endl;
        if(strcmp(A.Nombre,strUsername)==0){
          std::cout<<"Sali aquí1";
          return false;
        }

      }
      leer.close();
      return true;
    }
}
