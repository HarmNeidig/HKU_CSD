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
  double getFrequency();
  void tick();
  double getSample();
  virtual void calculate() = 0;
protected:
  double phase;
  double samplerate;
  double frequency;
  double sample;
};

#endif
