#include<iostream>
#include"Instrument_class.h"

// constructor
Instrument_class::Instrument_class(int NewAmp)
{
  int Amp = NewAmp;
  std::cout << "Start Instrument" << std::endl;
}

//destrutor
Instrument_class::~Instrument_class()
{
  std::cout << "Instrument ended" << std::endl;
}

//method
void Instrument_class::play()
{
  if (Amp < 50){
    std::cout << "*quiet guitar playing*" << std::endl;
  }
  else {
    std::cout << "*LOUD NOISE GUITAR PLAYING*" << std::endl;
  }
}
