#ifndef _BITCRUSHER_H_
#define _BITCRUSHER_H_
#include<iostream>
#include<vector>


class Bitcrusher{
public:
  // Constructor and Destructor
  Bitcrusher();
  ~Bitcrusher();

  // Setters and getters
  void setBitDepth(int bitDepth);
  void setGain(float gain);

  void getBitDepth();
  float getGain();

  std::vector<double> getSampleVector();
  //methods
  void makeSampleVector(int bitDepth);
  double calculateSignal(double sample, int foldMode);
private:
  int foldMode;
  float gain;
  double crushedSample;
  std::vector<double> samples {};
  int bitDepth;
};

#endif
