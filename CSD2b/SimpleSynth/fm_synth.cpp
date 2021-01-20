#include<iostream>
#include"osc.h"
#include"fm_synth.h"


FM_Synth::FM_Synth(double frequency, double samplerate, double ratio){
  std::cout << "FM Constructor" << std::endl;
}

FM_Synth::~FM_Synth(){

}

Osc* FM_Synth::makeCar(double frequency, int numOsc){
  if(numOsc == 1){
    carrier =  new Sine(frequency, samplerate);
  /*
  } else if(numOsc == 2) {
    osc = new Saw(frequency, samplerate);
  } else if(numOsc == 3) {
    osc = new Square(frequency, samplerate)
  */
  } else {
    std::cout << "Error: no osc found" << std::endl;
  }
  return carrier;
}

Osc* FM_Synth::makeMod(double frequency, int numOsc, double ratio){
  double frequencyModulator = frequency / ratio;
  if(numOsc == 1){
    modulator =  new Sine(frequencyModulator, samplerate);
  /*
  } else if(numOsc == 2) {
    modulator = new Saw(frequency, samplerate);
  } else if(numOsc == 3) {
    modulator = new Square(frequency, samplerate)
    */
  } else {
    std::cout << "Error: no osc found" << std::endl;
  }
  return modulator;
}

double FM_Synth::getSample(){
  carrierSample=carrier->getSample();
  modulatorSample=modulator->getSample();
  sample = carrierSample*modulatorSample;
  return sample;
}

void FM_Synth::tick(){

}

void FM_Synth::setFreqAndRatio(double frequency, double ratio){
  this->frequency = frequency;
  this->ratio = ratio;
}
