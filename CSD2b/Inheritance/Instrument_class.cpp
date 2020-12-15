#include<iostream>
#include"Instrument_class.h"

// constructor
Instrument_class::Instrument_class(std::string name, std::string sound)
{
  this->name = name;
  this->sound = sound;
  std::cout << "Start Instrument" << std::endl;
}

//destrutor
Instrument_class::~Instrument_class()
{
  std::cout << "Instrument ended" << std::endl;
}

//setters
void Instrument_class::setAmp(int amp){
  if (amp > 0 && amp < 100){
    //this pointer
    this->amp = amp;
  } else {
    std::cout << "This amp is out of range 1-100." << std::endl;
  }
}

void Instrument_class::setRange(int range)
{
  if (range > 0 && range < 128){
    this->range = range;
  }
}

void Instrument_class::setName(std::string name){
    this->name = name;
}

//getters
int Instrument_class::getAmp(){
  return amp;
}

int Instrument_class::getRange()
{
  return range;
}

std::string Instrument_class::getName(){
  return name;
}

std::string Instrument_class::getSound(){
  return sound;
}
// play method
void Instrument_class::play(){
  std::cout << getName() << " is playing with a range of "
  << getRange() << " and an amp of " <<
  getAmp() << "." << std::endl;
  std::cout << getName() << " goes " << getSound() << std::endl;
}
