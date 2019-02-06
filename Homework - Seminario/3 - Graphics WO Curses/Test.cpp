#include "Usuario.h"

int main(int argc, char const *argv[]) {
  Usuario A;
  A.NewUser();
  std::cout<<A.login("2011","1");
  return 0;
}
