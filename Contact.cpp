Contact::Contact(){
  Name="Example";
  Phone=0000000000;
  Email="example@example.com"
}
void Contact::NewContact(){
  fflush(stdin);
  cout<<"Name: ";
  getline(File, Name, '#');
  cout<<"Phone: ";
  getline(File, Phone, '#');
  cout<<"Email: ";
  getline(File, Name, '#');
  write(Name, strlen(Name));
  write(Phone, strlen(Phone));
  write(Email, strlen(Email));
}
void ShowContact(){

}
void Contact::SearchContact(){

}
void Contact::EditContact(){

}
void Contact::DeleteContact(){

}
