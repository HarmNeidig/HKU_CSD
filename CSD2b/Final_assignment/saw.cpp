#include "saw.h"
#include "math.h"

Saw::Saw(double frequency, double samplerate) : Osc(frequency, samplerate)
  {
  std::cout << "Saw - constructor" << std::endl;
}

Saw::~Saw() {
  std::cout << "Saw - destructor" << std::endl;
}

void Saw::tick() {
  phase += frequency / samplerate;
  double x = 0;
  //??Nyquist frequency interaction?
  for(unsigned int i = 1; i<150; i++)
  {
    x += (sin(M_PI * 2 * phase * i))/i;
  }
  sample = x;
}
