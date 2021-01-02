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
  double y = 0;
  //Saw waves are buildup of all harmonics.
  //So if freq= 100, all harmonics are 100 * x | where x = the number of the harmonic
  //Here I use an abritrary number of 80
  //TO DO || Make it so the harmonics have different amplitudes.
  //??Nyquist frequency interaction?
  for(unsigned int i = 1; i<150; i++)
  {
    y += (sin(M_PI * 2 * phase * i))/i;
  }
  sample = y;
}
