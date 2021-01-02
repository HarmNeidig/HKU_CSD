#include<iostream>
#ifndef _OSC_H_
#define _OSC_H_


class Osc
{
public:
  // Constructor
  Osc(double frequency, double samplerate);
  // Destructor
  ~Osc();
  double getSample();
  void setFrequency(float frequency);
  float getFrequency();
protected:
  double samplerate;
  double frequency;
  double phase;
  // single current sample to be put out
  double sample;
};

#endif
