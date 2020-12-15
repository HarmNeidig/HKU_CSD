#include<iostream>
#include"Guitar_subclass.h"


Guitar_subclass::Guitar_subclass(std::string name) : Instrument_class(name)
{
  std::cout << "Guitar begins" << std::endl;
}

Guitar_subclass::~Guitar_subclass()
{
  std::cout << "Guitar ends." << std::endl;
}
