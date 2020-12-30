#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, double samplerate) : Osc(frequency, samplerate)
  {
  std::cout << "Sine - constructor" << std::endl;
}

Sine::~Sine() {
  std::cout << "Sine - destructor" << std::endl;
}

float Sine::tick() {
  phase += frequency / samplerate;
  sample = sin(M_PI * 2 * phase);
  return sample;
}
