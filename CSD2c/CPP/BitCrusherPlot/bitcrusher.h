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
  void setFoldmode(int foldmode);
  std::vector<double> getSampleVector();
  //methods
  void makeSampleVector(int bitDepth);
  double calculateSignal(double sample);
private:
  // this variable is meant for the amount a sample goes above 1 or below -1.
  double excessSample;
  int foldmode;
  float gain;
  double crushedSample;
  std::vector<double> samples {};
  int bitDepth;
  int bitDepthPow;
};

#endif
