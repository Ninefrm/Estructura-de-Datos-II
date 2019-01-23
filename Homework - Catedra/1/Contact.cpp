
#include "Contact.h"

Contact::Contact(){
  Name="Example";
  Phone="0000000000";
  Email="example@example.com";
}

void Contact::addName(std::string &N){
  Name = N;
}
void Contact::addEmail(std::string &N){
  Email = N;
}
void Contact::addPhone(std::string &N){
  Phone = N;
}
std::string Contact::rName(){
  return Name;
}
std::string Contact::rEmail(){
  return Email;
}
std::string Contact::rPhone(){
  return Phone;
}
