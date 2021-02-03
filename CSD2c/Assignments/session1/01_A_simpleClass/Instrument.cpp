#include "Instrument.h"

void Instrument::makeSound() {
  std::cout << "A sound is produced: \"";
  std::cout << sound << "\"" << std::endl;
}

void Instrument::setFrequency(double frequency){
  this->frequency = frequency;
  std::cout << "frequency = " << frequency << std::endl;
}
