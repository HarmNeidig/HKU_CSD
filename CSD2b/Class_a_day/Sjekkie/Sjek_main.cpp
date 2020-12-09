#include<iostream>
#include<string>
#include"Sjek.h"

int main(){
  Sjek SjekkieInDeOchtend;
  SjekkieInDeOchtend.setSjekType("Javaanse Jongens");
  std::string aSjekType = SjekkieInDeOchtend.getSjekType();
  std::cout << "*rookt " + aSjekType + "*" << std::endl;
  return 0;
}
