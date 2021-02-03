#ifndef H_INSTRDERIVED
#define H_INSTRDERIVED

#include"Instrument.h"
#include<iostream>

class InstrDerived : public Instrument
{
public:
  std::string getSound();
  std::string getMaterial();
};

#endif
