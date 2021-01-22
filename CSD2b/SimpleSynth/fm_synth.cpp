#include<iostream>
#include"osc.h"
#include"fm_synth.h"


FM_Synth::FM_Synth(double samplerate){
  std::cout << "FM Constructor" << std::endl;
}

FM_Synth::~FM_Synth(){

}

Osc* FM_Synth::makeCar(int choiceCar, double frequencyCarrier){
  if(choiceCar == 1){
    carrier = new Sine(frequencyCarrier, samplerate);
  /*
  } else if(choiceCar == 2) {
    carrier = new Saw(frequency, samplerate);
  } else if(choiceCar == 3) {
    carrier = new Square(frequency, samplerate)
  */
  } else {
    std::cout << "Error: no osc found" << std::endl;
  }
  return carrier;
}

Osc* FM_Synth::makeMod(int choiceMod, double frequencyModulator){
  std::cout << "freq mod = "<<frequencyModulator << std::endl;
  if(choiceMod == 1){
    modulator =  new Sine(frequencyModulator, samplerate);
  /*
  } else if(choiceMod == 2) {
    modulator = new Saw(frequencyModulator, samplerate);
  } else if(choiceMod == 3) {
    modulator = new Square(frequencyModulator, samplerate)
    */
  } else {
    std::cout << "Error: no osc found" << std::endl;
  }
  return modulator;
}

void FM_Synth::setFreqMod(double frequency){
  modulator->setFrequency(frequency);
}

void FM_Synth::setFreqCar(double frequency){
  carrier->setFrequency(frequency);
}

double FM_Synth::getSampleCar(){
  carrierSample=carrier->getSample();
  return carrierSample;
}

double FM_Synth::getSampleMod(){
  modulatorSample=modulator->getSample();
  return modulatorSample;
}

void FM_Synth::tickAll(){
  carrier->tick();
  modulator->tick();
}

void FM_Synth::setFreqWithRatio(double frequency, int ratio){
  this->frequency = frequencyCarrier;
  this->ratio = ratio;
  frequencyModulator = frequencyCarrier/ratio;
  setFreqCar(frequencyCarrier);
  setFreqMod(frequencyModulator);
}
