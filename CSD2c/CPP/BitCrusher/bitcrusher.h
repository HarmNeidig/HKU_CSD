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
  void getBitDepth();
  std::vector<double> getSampleVector();
  //methods
  void makeSampleVector(int bitDepth);
  double calculateSignal(double sample);
private:
  double crushedSample;
  std::vector<double> samples {};
  int bitDepth;
};

#endif
