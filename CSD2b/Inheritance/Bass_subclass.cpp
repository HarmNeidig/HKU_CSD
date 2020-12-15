#include<iostream>
#include"Bass_subclass.h"


Bass_subclass::Bass_subclass(std::string name, std::string sound) : Instrument_class(name, sound)
{
  std::cout << "Bass begins" << std::endl;
}

Bass_subclass::~Bass_subclass()
{
  std::cout << "Bass ends." << std::endl;
}
