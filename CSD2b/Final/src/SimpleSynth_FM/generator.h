#ifndef _GENERATOR_H_
#define _GENERATOR_H_
#include<iostream>

class Generator
{
public:
  Generator();
  ~Generator();
  // seed the rand
  void init();
  double generateNote();
  double generateRatio(double frequencyCarrier);
protected:
  double scale[8] = {523.25, 587.33, 659.25,
    698.46, 783.99,880.00, 987.77, 1046.50};
  double frequencyCarrier;
  double frequencyModulator;
  int index;
};

#endif
