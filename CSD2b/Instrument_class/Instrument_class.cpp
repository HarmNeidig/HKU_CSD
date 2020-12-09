#include<iostream>
#include"Instrument_class.h"
// constructor
Instrument_class::Instrument_class()
{
  std::cout << "Start Instrument" << std::endl;
}

//destrutor
Instrument_class::~Instrument_class()
{
  std::cout << "Instrument ended" << std::endl;
}

//setter
void Instrument_class::setAmp(int newAmp){
  if (newAmp > 0 && newAmp < 100){
    //this pointer
    this->newAmp = Amp;
    {
      if (Amp < 50){
        std::cout << "*quiet guitar playing*" << std::endl;
      }
      else {
        std::cout << "*LOUD NOISE GUITAR PLAYING*" << std::endl;
      }
    }
  } else {
    std::cout << "ERROR" << std::endl;
  }
}

//getter
int Instrument_class::getAmp(){
  return Amp;
}
