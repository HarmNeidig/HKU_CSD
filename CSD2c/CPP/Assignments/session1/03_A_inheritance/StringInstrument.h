#ifndef H_STRING_INSTRUMENT
#define H_STRING_INSTRUMENT
#include "Instrument.h"

class StringInstrument : public Instrument {
public:
  StringInstrument(std::string aSound);
  void makePublicSound();
private:
  void makeSound();
};

#endif
