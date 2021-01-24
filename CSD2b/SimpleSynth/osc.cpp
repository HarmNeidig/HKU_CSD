#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#include "osc.h"
#include "math.h"

// Constructor
Osc::Osc(double frequency, double samplerate) : frequency(frequency),
  samplerate(samplerate){
    std::cout << "Oscillator begins" << std::endl;
}

// Destructor
Osc::~Osc(){
    std::cout << "Oscillator ends" << std::endl;
}

void Osc::tick(){
  phase += frequency/samplerate;
  calculate();
}

// Getter for sample
double Osc::getSample(){
  return sample;
}

void Osc::setFrequency(double frequency){
  this->frequency = frequency;
}

double Osc::getFrequency(){
  return frequency;
}
