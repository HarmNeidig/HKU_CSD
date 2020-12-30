#ifndef _SINE_H_
#define _SINE_H_
#include"osc.h"
#include <iostream>


class Sine : public Osc
{
public:
  //Constructor and destructor
  Sine(float frequency, double samplerate);
  ~Sine();
  // go to next sample
  void tick();
private:
  double samplerate;
  float frequency;
  float phase;
  // single current sample to be put out
  float sample;
};

#endif
