#include "Cliente.h"

Cliente::Cliente(){
  std::string tmp;
  tmp = "Cliente";
  C.addRank(tmp);
}
void Cliente::addPayment(std::string& aPayment){
  Payment = aPayment;
}
void Cliente::addEmail(std::string& aEmail){
  Email = aEmail;
}
void Cliente::addPhone(std::string& aPhone){
  Phone = aPhone;
}
std::string Cliente::sPayment(){
  return Payment;
}
std::string Cliente::sEmail(){
  return Email;
}
std::string Cliente::sPhone(){
  return Phone;
}
void Cliente::addID(std::string aID){
  ID = aID;
}
std::string Cliente::sID(){
  return ID;
}
