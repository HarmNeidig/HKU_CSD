#include "osc.h"
#include "math.h"

// Constructor
Osc::Osc(float frequency, double samplerate) : frequency(frequency),
  samplerate(samplerate), amplitude(0.5), sample(0), phase(0)
  {
    std::cout << "Oscillator begins" << std::endl;
}

// Destructor
Osc::~Osc(){
    std::cout << "Oscillator ends" << std::endl;
  }

// Getter for sample
float Osc::getSample(){
    return sample;
  }

void Osc::setFrequency(float frequency){
  this->frequency = frequency;
}

float Osc::getFrequency(){
  return frequency;
}
