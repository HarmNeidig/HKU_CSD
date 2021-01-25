#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#include "generator.h"

Generator::Generator(){
  std::cout << "Generator begins" << std::endl;
}

Generator::~Generator(){
  std::cout << "Generator ends" << std::endl;
}

void Generator::init(){
  srand(std::time(NULL));
}

double Generator::generateNote(){
  int index = rand() % 8;
  double frequency = scale[index];
  return frequency;
}
