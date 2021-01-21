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
  FM_Synth(double frequency, double samplerate, int ratio);
  ~FM_Synth();
  void setFreqAndRatio(double frequency, int ratio);
  Osc* makeCar(int choiceCar);
  Osc* makeMod(int choiceMod);
  double getSample();
  void tick();
private:
  int choiceMod;
  int choiceCar;
  Osc* carrier;
  Osc* modulator;
  double carrierSample;
  double modulatorSample;
  double samplerate;
  double frequency;
  int ratio;
  double frequencyModulator;
  double sample;
};

#endif
