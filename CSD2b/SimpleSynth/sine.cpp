#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#include "sine.h"
#include "math.h"

Sine::Sine(double frequency, double samplerate) : Osc(frequency, samplerate)
  {
  std::cout << "Sine -- " << frequency << " Hz" << std::endl;
}

Sine::~Sine() {
  std::cout << "Sine - destructor" << std::endl;
}

// calculate sample with sin from math library
void Sine::calculate() {
  sample = sin(M_PI * 2 * phase);
}
