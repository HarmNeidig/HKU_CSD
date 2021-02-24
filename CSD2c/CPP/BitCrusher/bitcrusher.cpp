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
  sample*=gain;
  int bits = samples.size();
  // foldmode 0 is just straight clipping.
  // If the sample is 1.2 it stays at 1
  if (foldmode == 0){
    for (int i = 0; i < bits; i++){
      if ((sample >= samples[i]) && (sample <= samples[i+1])){
        double crushedSample = samples[i];
        return crushedSample;
      }
    }
  }
  // foldmode 1 folds back from 0
  // If the sample is 1.2 it folds back to 0.2
  if (foldmode == 1){
    for (int i = 0; i < bits; i++){
      if ((sample >= samples[i]) && (sample <= samples[i+1])){
        if (sample >= 1){
          sample-=1;
          if (sample <= 0){
            sample+=1;
          }
        }
        if (sample <= -1){
          sample+=1;
          if (sample <= 0){
            sample-=1;
          }
        }
        double crushedSample = samples[i];
        return crushedSample;
      }
    }
  }
  // foldmode 2 folds back from 1
  // If the sample is 1.2 it folds back to 0.8
  if (foldmode == 2){
    for (int i = 0; i < bits; i++){
      if ((sample >= samples[i]) && (sample <= samples[i+1])){
        double crushedSample = samples[i];
        return crushedSample;
      }
    }
  }
}
