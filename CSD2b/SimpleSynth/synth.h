#ifndef _SYNTH_H_
#define _SYNTH_H_
#include<iostream>
#include"osc.h"
#include"sine.h"
#include"saw.h"
#include"square.h"


class Synth
{
public:
  // Constructor and destructor
  Synth(double frequency,double samplerate);
  ~Synth();
  // get current sample
  virtual double getSample();
  // select osc and make it
  Osc* selectOsc(int choice);
private:
  double samplerate;
  double frequency;
};

#endif
