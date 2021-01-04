#include<iostream>
#include "osc.h"
#include "sine.h"
#include "synthesizer.h"


Synthesizer::Synthesizer(double frequency, double samplerate){
  std::cout << "synth begins" << std::endl;
}
Synthesizer::~Synthesizer(){
  std::cout << "synth ends" << std::endl;
}

Osc* Synthesizer::selectOsc(int numOsc){
  Osc* osc = nullptr;
  if(numOsc == 1){
  osc =  new Sine(440, 44100);
  }

  return osc;
}
