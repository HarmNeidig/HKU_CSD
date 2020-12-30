#include"square.h"

square::square()
{
  std::cout << "calculating square" << std::endl;
}

square::~square()
{
  std::cout << "done calculating square" << std::endl;
}

void square::setNum(int x)
{
  this->x = x;
}

int square::getNum()
{
  return x;
}

int square::calculate()
{
  return x*x;
}
