#include<iostream>
#include"Sjek.h"
#include<string>

Sjek::Sjek(){
  std::cout << "*draait m dicht*" << std::endl;
}

Sjek::~Sjek(){
  std::cout << "*stopt de rest in de asbak*" << std::endl;
}

void Sjek::setSjekType(std::string sjekType){
  this->sjekType = sjekType;
}

std::string Sjek::getSjekType(){
  return sjekType;
}
