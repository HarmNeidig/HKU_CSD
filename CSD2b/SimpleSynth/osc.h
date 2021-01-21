#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
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
  void setFrequency(double frequency);
  float getFrequency();
  void tick();
  virtual double getSample();
  virtual void calculate(double phase) = 0;
protected:
  double samplerate;
  double frequency;
  double phase;
  // single current sample to be put out
  double sample;
};

#endif
