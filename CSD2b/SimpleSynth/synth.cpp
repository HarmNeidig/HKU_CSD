#include<iostream>
#include"osc.h"
#include"synth.h"

// Constructor and destructor
Synth::Synth(double frequency, double samplerate){
  std::cout << "Synth Constructor" << std::endl;
  std::cout << "Freq for this synth = " << frequency << std::endl;
  std::cout << "Samplerate for this synth = " << samplerate << std::endl;
  this->frequency = frequency;
  this->samplerate = samplerate;
}

Synth::~Synth(){
  std::cout << "Synth destructor" << std::endl;
}

// Select waveform and make oscillator
Osc* Synth::selectOsc(int choice){
  Osc* oscillator = nullptr;
  if(choice == 1){
    oscillator =  new Sine(frequency, samplerate);
  } else if(choice == 2) {
    oscillator = new Saw(frequency, samplerate);
  } else if(choice == 3) {
    oscillator = new Square(frequency, samplerate);
  } else {
    std::cout << "Error: no osc found" << std::endl;
  }
  return oscillator;
}

// virtual get sample (thats why its empty)
double Synth::getSample(){}
