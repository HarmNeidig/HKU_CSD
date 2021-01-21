#ifndef _FM_SYNTH_H_
#define _FM_SYNTH_H_
#include<iostream>
#include"osc.h"
#include"sine.h"

class FM_Synth
{
public:
  //Constructor and destructor
              // 400 FREQ, 0.5 RATIO = FREQ2 200
  FM_Synth(double frequency, double samplerate, double ratio);
  ~FM_Synth();
  void setFreqAndRatio(double frequency, double ratio);
  Osc* makeCar();
  Osc* makeMod();
  double getSample();
  void tick();
private:
  Osc* carrier;
  Osc* modulator;
  double carrierSample;
  double modulatorSample;
  double samplerate;
  double frequency;
  double ratio;
  double frequencyModulator;
  int numOsc = 1;
  double sample;
};

#endif
