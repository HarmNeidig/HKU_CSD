#include "sine.h"
#include "math.h"

Sine::Sine(double frequency, double samplerate) : Osc(frequency, samplerate)
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
