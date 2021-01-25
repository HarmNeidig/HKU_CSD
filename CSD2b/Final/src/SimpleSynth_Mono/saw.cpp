#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#include "saw.h"
#include "math.h"

Saw::Saw(double frequency, double samplerate) : Osc(frequency, samplerate)
  {
  std::cout << "Saw -- "<< frequency << " Hz" << std::endl;
}

Saw::~Saw() {
  std::cout << "Saw - destructor" << std::endl;
}

// Calculate sample for saw (150 overtones)
void Saw::calculate() {
  double x = 0;
  for(unsigned int i = 1; i<150; i++)
  {
    x += (sin(M_PI * 2 * phase * i))/i;
  }
  sample = x;
}
