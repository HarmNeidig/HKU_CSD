#include<iostream>
#include<vector>
#include<cmath>
#include"bitcrusher.h"

Bitcrusher::Bitcrusher(){
  std::cout << "Begins crushing the bits" << std::endl;
}

Bitcrusher::~Bitcrusher(){
  std::cout << "stops crushing the bits" << std::endl;
}

void Bitcrusher::setBitDepth(int bitDepth){
  this->bitDepth = bitDepth;
}

void Bitcrusher::setGain(float gain){
  this->gain = gain;
}

void Bitcrusher::getBitDepth(){
  std::cout << "bitDepth = " << bitDepth << std::endl;
}

float Bitcrusher::getGain(){
  return gain;
}

void Bitcrusher::setFoldmode(int foldmode){
  this->foldmode = foldmode;
}

std::vector<double> Bitcrusher::getSampleVector(){
  return samples;
}

void Bitcrusher::makeSampleVector(int bitDepth){
  this->bitDepth = bitDepth;
  int bitDepthPow = pow(2, bitDepth);
  std::cout << "2 ^ "<< bitDepth << " = " << bitDepthPow << std::endl;
  if (bitDepth > 1 & bitDepth < 16){
    double adder = 2. / bitDepthPow;
    double firstSample = -1.;
    samples.push_back(firstSample);
    for (int i = 0; i < bitDepthPow; i++){
      double sample = firstSample + (adder*(i+1));
      samples.push_back(sample);
      }
  } else {
  std::cout << "BitDepth should be in range 3-16." << std::endl;
  }
}


double Bitcrusher::clipping(double sample){
  sample*=gain;
  while (foldmode == 0){
    if (sample > 1){
      crushedSample = 1;
      return crushedSample;
    } else if (sample < -1){
      crushedSample = -1;
      return crushedSample;
    } else {
      return crushedSample;
    }
  }
}


double Bitcrusher::crusher(double sample){
  int bits = samples.size();
  for (int i = 0; i < bits; i++){
    if ((sample > samples[i]) && (sample < samples[i+1])){
      double crushedSample = samples[i];
      return crushedSample;
    }
  }
}

// Modulo of ratio??
