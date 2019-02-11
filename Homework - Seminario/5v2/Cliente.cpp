#include "Cliente.h"
// Cliente::Cliente(){
//
// }

void Cliente::addName(std::string& aName){
  Name = aName;
}

void Cliente::addRFC(std::string& aRFC){
  RFC = aRFC;
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

void Cliente::addID(std::string aID){
  ID = aID;
}

void Cliente::addStatus(std::string& aStatus){
  Status = aStatus;
}

void Cliente::addOwner(std::string& aOwner){
  Owner = aOwner;
}
std::string Cliente::sID(){
  return ID;
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

std::string Cliente::sStatus(){
  return  Status;
}

std::string Cliente::sName(){
  return Name;
}

std::string Cliente::sRFC(){
  return RFC;
}

std::string Cliente::sOwner(){
  return Owner;
}
