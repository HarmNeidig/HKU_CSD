#include<iostream>
#include<vector>
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

std::vector<double> Bitcrusher::getSampleVector(){
  return samples;
}

void Bitcrusher::makeSampleVector(int bitDepth){
  bitDepth-=1;
  if (bitDepth > 1 & bitDepth < 16){
    double adder = 2. / bitDepth;
    double firstSample = -1.;
    samples.push_back(firstSample);
    for (int i = 0; i < bitDepth; i++){
      double sample = firstSample + (adder*(i+1));
      samples.push_back(sample);
      }
  } else {
  std::cout << "BitDepth should be in range 3-16." << std::endl;
  }
}


double Bitcrusher::calculateSignal(double sample, int foldmode){
  int bits = samples.size();
  if (foldmode == 0){
    for (int i = 0; i < bits; i++){
      if ((sample >= samples[i]) && (sample <= samples[i+1])){
        double crushedSample = samples[i] * gain;
        return crushedSample;
      }
    }
  }
  if (foldmode == 1){
    for (int i = 0; i < bits; i++){
      if ((sample >= samples[i]) && (sample <= samples[i+1])){
        double crushedSample = samples[i] * gain;
        return crushedSample;
      }
    }
  }
  if (foldmode == 2){
    for (int i = 0; i < bits; i++){
      if ((sample >= samples[i]) && (sample <= samples[i+1])){
        double crushedSample = samples[i] * gain;
        return crushedSample;
      }
    }
  }
}
