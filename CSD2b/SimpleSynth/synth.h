#ifndef _SYNTH_H_
#define _SYNTH_H_
#include<iostream>
#include"osc.h"
#include"sine.h"

class Synth
{
public:
  Synth(double frequency,double samplerate);
  ~Synth();
  virtual double getSample();
  Osc* selectOsc(int choice);
  void setFreq(double frequency);
private:
  int choice;
  Osc* oscillator;
  double sample;
  double samplerate;
  double frequency;
};

#endif
