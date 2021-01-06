#ifndef _SYNTHESIZER_H_
#define _SYNTHESIZER_H_
#include<iostream>
#include "osc.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

class Synthesizer{
public:
  Synthesizer(double frequency, double samplerate);
  ~Synthesizer();
  Osc* selectOsc(int numOsc);
private:
  double frequency;
  double samplerate;
};

#endif
