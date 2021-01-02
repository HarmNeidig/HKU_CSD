#ifndef _SQUARE_H_
#define _SQUARE_H_
#include"osc.h"
#include <iostream>


class Square : public Osc
{
public:
  //Constructor and destructor
  Square(double frequency, double samplerate);
  ~Square();
  // go to next sample
  void tick();
};

#endif
