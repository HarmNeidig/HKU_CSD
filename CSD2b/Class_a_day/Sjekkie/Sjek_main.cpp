#include<iostream>

class Sjek{
public:
  Sjek();
  ~Sjek();
  string setSjekType(string sjekType);
  string getSjekType;
private:
  string sjekType;
};

Sjek::Sjek(){
  std::cout << "*pakt een filter*" << std::endl;
}

Sjek::~Sjek(){
  std::cout << "*draait m dicht*" << std::endl;
}

void Sjek::setSjekType(string sjekType){
  this sjekType->sjekType;
}

string Sjek::getSjekType(){
  return sjekType;
}

int main(){
  Sjek SjekkieInDeOchtend();
  SjekkieInDeOchtend.setSjekType("Javaanse Jongens")
  std::cout << "*rookt " + sjekType + "*" << std::endl;
  return 0;
}
