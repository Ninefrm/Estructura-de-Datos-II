#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


int main(){
  std::string Name;
  double Phone;
  std::string Email;
  std::fstream File("test.txt", std::fstream::in | std::fstream::out);
  fflush(stdin);
  std::cout<<"Name: ";
  getline(File, Name, '#');
  std::cout<<"Phone: ";
  getline(File, Phone, '#');
  std::cout<<"Email: ";
  getline(File, Name, '#');
  write(Name, strlen(Name));
  write(Phone, strlen(Phone));
  write(Email, strlen(Email));
  File.close();
  return 0;
}
