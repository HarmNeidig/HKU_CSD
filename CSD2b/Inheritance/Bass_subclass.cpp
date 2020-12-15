#include<iostream>
#include"Bass_subclass.h"


Bass_subclass::Bass_subclass(std::string name) : Instrument_class(name)
{
  std::cout << "Bass begins" << std::endl;
}

Bass_subclass::~Bass_subclass()
{
  std::cout << "Bass ends." << std::endl;
}
