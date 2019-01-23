#include "User.h"
void User::addName(std::string& aName){
  Name = aName;
}
void User::addRank(std::string& aRank){
  Rank = aRank;
}
void User::addRFC(std::string& aRFC){
  RFC = aRFC;
}
std::string User::sName(){
  return Name;
}
std::string User::sRank(){
  return Rank;
}
std::string User::sRFC(){
  return RFC;
}
