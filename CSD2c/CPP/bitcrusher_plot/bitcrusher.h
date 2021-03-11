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
  // calculates all potential signal values
  void makeSampleVector(int bitDepth);
  //
  double clipping(double sample);
  // compares this sample with the sample vector
  // and returns a value from the vector
  double crusher(double sample);
private:
  // this variable is meant for the amount a sample goes above 1 or below -1.
  int amountFolds = 0;
  double excessSample = 0;
  double foldedSample = 0;
  int foldmode;
  float gain;
  double crushedSample;
  std::vector<double> samples {};
  int bitDepth;
  int bitDepthPow;
};

#endif
