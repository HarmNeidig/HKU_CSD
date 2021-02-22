#ifndef H_WOODWIND_INSTRUMENT
#define H_WOODWIND_INSTRUMENT
#include "Instrument.h"
#include "StringInstrument.h"

class WoodwindInstrument : public StringInstrument {
public:
  WoodwindInstrument(std::string aSound);
}

#endif
