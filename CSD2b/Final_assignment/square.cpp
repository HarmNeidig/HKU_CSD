#include "square.h"
#include "math.h"

Square::Square(double frequency, double samplerate) : Osc(frequency, samplerate)
  {
  std::cout << "Square - constructor" << std::endl;
}

Square::~Square() {
  std::cout << "Square - destructor" << std::endl;
}

void Square::tick() {
  phase += frequency / samplerate;
  double y = 0;
  for(unsigned int i = 0; i<70; i++)
  {
    //Alleen oneven harmonischen
    int n = (i*2)+1;
    //Iteratief de samples per harmonic bij elkaar optellen
    y += (sin(M_PI * 2 * phase * n)/n);
  }
  sample = y;
}
