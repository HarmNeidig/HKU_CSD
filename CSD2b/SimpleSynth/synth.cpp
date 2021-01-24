#include<iostream>
#include"osc.h"
#include"synth.h"


Synth::Synth(double frequency, double samplerate){
  std::cout << "Synth Constructor" << std::endl;
  std::cout << "Freq for this synth = " << frequency << std::endl;
  std::cout << "Samplerate for this synth = " << samplerate << std::endl;
  this->frequency = frequency;
  this->samplerate = samplerate;
}

Synth::~Synth(){

}

Osc* Synth::selectOsc(int choiceMod){
  Osc* oscillator = nullptr;
  if(choiceMod == 1){
    oscillator =  new Sine(frequency, samplerate);
  /*
  } else if(choiceMod == 2) {
    modulator = new Saw(frequencyModulator, samplerate);
  } else if(choiceMod == 3) {
    modulator = new Square(frequencyModulator, samplerate)
    */
  } else {
    std::cout << "Error: no osc found" << std::endl;
  }
  return oscillator;
}

void Synth::setFreq(double frequency){
  oscillator->setFrequency(frequency);
}


double Synth::getSample(){

}
