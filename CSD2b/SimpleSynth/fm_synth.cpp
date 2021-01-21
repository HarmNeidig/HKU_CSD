#include<iostream>
#include"osc.h"
#include"fm_synth.h"


FM_Synth::FM_Synth(double frequency, double samplerate, int ratio){
  std::cout << "FM Constructor" << std::endl;
}

FM_Synth::~FM_Synth(){

}

Osc* FM_Synth::makeCar(int choiceCar){
  if(choiceCar == 1){
    carrier = new Sine(frequency, samplerate);
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

Osc* FM_Synth::makeMod(int choiceMod){
  frequencyModulator = frequency / ratio;
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

double FM_Synth::getSample(){
  carrierSample=carrier->getSample()*0.5;
  modulatorSample=modulator->getSample()*0.5;
  sample=carrierSample*modulatorSample;
  return sample;
}

void FM_Synth::tick(){
  carrier->tick();
  modulator->tick();
}

void FM_Synth::setFreqAndRatio(double frequency, int ratio){
  this->frequency = frequency;
  this->ratio = ratio;
}
