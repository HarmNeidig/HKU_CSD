#include<iostream>
#include "osc.h"
#include "synthesizer.h"


Synthesizer::Synthesizer(double frequency, double samplerate){
  this->frequency = frequency;
  this->samplerate = samplerate;

  std::cout << "synth begins" << std::endl;
}

Synthesizer::~Synthesizer(){
  std::cout << "synth ends" << std::endl;
}

Osc* Synthesizer::selectOsc(int numOsc){
  Osc* osc = nullptr;
  if(numOsc == 1){
  osc =  new Sine(frequency, samplerate);
} else if(numOsc == 2) {
  osc = new Saw(frequency, samplerate);
} else if(numOsc == 3) {
  osc = new Square(frequency, samplerate);
} else {
  std::cout << "Error: no osc found" << std::endl;
}
  return osc;
}
