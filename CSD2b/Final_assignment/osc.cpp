#include "osc.h"
#include "math.h"

// Constructor
Osc::Osc(double frequency, double samplerate) : frequency(frequency),
  samplerate(samplerate)
  {
    std::cout << "Oscillator begins" << std::endl;
}

// Destructor
Osc::~Osc(){
    std::cout << "Oscillator ends" << std::endl;
  }

// Getter for sample
double Osc::getSample(){
    return sample;
  }

void Osc::setFrequency(float frequency){
  this->frequency = frequency;
}

float Osc::getFrequency(){
  return frequency;
}
