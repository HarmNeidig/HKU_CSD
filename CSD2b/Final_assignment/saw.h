#ifndef _SAW_H_
#define _SAW_H_
#include"osc.h"
#include <iostream>


class Saw : public Osc
{
public:
  //Constructor and destructor
  Saw(double frequency, double samplerate);
  ~Saw();
  // go to next sample
  void calculate();
};

#endif
