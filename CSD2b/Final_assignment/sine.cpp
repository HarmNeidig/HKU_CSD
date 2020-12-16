#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, double samplerate) : Osc(frequency, samplerate)
  : frequency(frequency), samplerate(samplerate), amplitude(0.5), sample(0), phase(0) 
  {
  std::cout << "Sine - constructor" << std::endl;
}

Sine::~Sine() {
  std::cout << "Sine - destructor" << std::endl;
}

void Sine::tick() {
  phase += frequency / samplerate;
  sample = sin(M_PI * 2 * phase);
}

float Sine::getSample(){
  return sample;
}
