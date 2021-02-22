#include"Instrument.h"
#include"InstrDerived.h"

std::string InstrDerived::getSound(){
  return sound;
}

std::string InstrDerived::getMaterial(){
  return material;
}
