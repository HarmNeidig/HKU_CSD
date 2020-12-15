#include<iostream>
#include"Guitar_subclass.h"


Guitar_subclass::Guitar_subclass(std::string name, std::string sound) : Instrument_class(name, sound)
{
  std::cout << "Guitar begins" << std::endl;
}

Guitar_subclass::~Guitar_subclass()
{
  std::cout << "Guitar ends." << std::endl;
}
