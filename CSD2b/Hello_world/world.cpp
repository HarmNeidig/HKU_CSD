#include"world.h"
#include<iostream>

// constructor
world::world(int newyear)
{
  std::cout << "World begins" << std::endl;
  year=newyear;
}

//destrutor
world::~world()
{
  std::cout << "World ends" << std::endl;
}

void world::hello()
{
  std::cout << "Hey " << year << std::endl;
}
