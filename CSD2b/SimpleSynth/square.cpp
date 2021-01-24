#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#include "square.h"
#include "math.h"

Square::Square(double frequency, double samplerate) : Osc(frequency, samplerate)
  {
  std::cout << "Square -- " << frequency << " Hz" << std::endl;
}

Square::~Square() {
  std::cout << "Square - destructor" << std::endl;
}

// calculate sample for square wave (just uneven overtones)
void Square::calculate() {
  double x = 0;
  for(unsigned int i = 0; i<70; i++)
  {
    int n = (i*2)+1;
    x += (sin(M_PI * 2 * phase * n)/n);
  }
  sample = x;
}
