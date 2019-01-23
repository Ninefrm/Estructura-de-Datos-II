#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

int main(){
  std::ofstream File("example.txt", ios::app);
  std::cout<<"Name: ";
  getline(Name);
  cout<<"Phone: ";
  getline(Phone);
  cout<<"Email: ";
  getline(Email);
  Contact.addName(Name);
  Contact.addPhone(Phone);
  Contact.addEmail(Email);

  File<<Contact.rName()<<"#"<<Contact.rPhone()<<"#"<<Contact.rEmail()<<'/n';


  return 0;
}
