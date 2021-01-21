#include<iostream>
#include"osc.h"
#include"fm_synth.h"


FM_Synth::FM_Synth(double frequency, double samplerate, double ratio){
  std::cout << "FM Constructor" << std::endl;
}

FM_Synth::~FM_Synth(){

}

Osc* FM_Synth::makeCar(){
  if(numOsc == 1){
    carrier =  new Sine(frequency, samplerate);
  /*
  } else if(numOsc == 2) {
    carrier = new Saw(frequency, samplerate);
  } else if(numOsc == 3) {
    carrier = new Square(frequency, samplerate)
  */
  } else {
    std::cout << "Error: no osc found" << std::endl;
  }
  return carrier;
}

Osc* FM_Synth::makeMod(){
  frequencyModulator = frequency / ratio;
  if(numOsc == 1){
    modulator =  new Sine(frequencyModulator, samplerate);
  /*
  } else if(numOsc == 2) {
    modulator = new Saw(frequencyModulator, samplerate);
  } else if(numOsc == 3) {
    modulator = new Square(frequencyModulator, samplerate)
    */
  } else {
    std::cout << "Error: no osc found" << std::endl;
  }
  return modulator;
}

double FM_Synth::getSample(){
  carrierSample=carrier->getSample()*0.5;
  std::cout << "carrier = " << carrierSample << std::endl;
  modulatorSample=modulator->getSample()*0.5;
  sample=carrierSample*modulatorSample;
  return sample;
}

void FM_Synth::tick(){
  carrier->tick();
  modulator->tick();
}

void FM_Synth::setFreqAndRatio(double frequency, double ratio){
  this->frequency = frequency;
  this->ratio = ratio;
}
