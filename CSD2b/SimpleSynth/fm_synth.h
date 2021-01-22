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
  FM_Synth(double samplerate);
  ~FM_Synth();
  void setFreqWithRatio(double frequency, int ratio);
  double getSampleCar();
  double getSampleMod();
  Osc* makeCar(int choiceCar, double frequencyCarrier);
  Osc* makeMod(int choiceMod, double frequencyModulator);
  void setFreqMod(double frequencyCarrier);
  void setFreqCar(double frequencyModulator);
  void tickAll();
private:
  int choiceMod;
  int choiceCar;
  Osc* carrier;
  Osc* modulator;
  double carrierSample;
  double modulatorSample;
  double samplerate;
  double frequency;
  int ratio = 1;
  double frequencyModulator;
  double frequencyCarrier;
  double sample;
};

#endif
