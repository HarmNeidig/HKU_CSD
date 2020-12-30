#ifndef _SAW_H_
#define _SAW_H_
#include"osc.h"
#include <iostream>


class Saw : public Osc
{
public:
  //Constructor and destructor
  Saw(float frequency, double samplerate);
  ~Saw();
  // go to next sample
  void tick();
};

#endif
