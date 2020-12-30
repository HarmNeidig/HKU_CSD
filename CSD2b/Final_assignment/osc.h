#include<iostream>
#ifndef _OSC_H_
#define _OSC_H_


class Osc
{
public:
  // Constructor
  Osc(float frequency, double samplerate);
  // Destructor
  ~Osc();
  float getSample();
  void setFrequency(float frequency);
  float getFrequency();
protected:
  double samplerate;
  float frequency;
  float phase;
  // single current sample to be put out
  float sample;
};

#endif
