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
  amountFolds = 0;
  while (foldmode == 0){
    if (sample > 1){
      crushedSample = 1;
      return crushedSample;
    } else if (sample < -1){
      crushedSample = -1;
      return crushedSample;
    } else {
      return sample;
    }
  }
  // fold mode 1 is a wrapping algo
  // that means when a sample reaches 1.2
  // it wraps back to 0.2
  while (foldmode == 1){
    std::cout << amountFolds;
    // top folding
    if (sample < 1 && sample > -1){
      return sample;
    } else if (sample > 1){
      if (sample > 1 && amountFolds == 0){
        excessSample = sample - 1;
        amountFolds+=1;
        return excessSample;
      } else if (sample > (1+amountFolds) && amountFolds != 0){
        excessSample = sample - (1 + amountFolds);
        return excessSample;
        amountFolds+=1;
      } else if (sample < (1+amountFolds) && amountFolds != 0){
        excessSample = sample - (1 + amountFolds);
        return excessSample;
        amountFolds-=1;
      }
  } else if (sample < -1){
    if (sample < -1 && amountFolds == 0){
      excessSample = sample + 1;
      return excessSample;
      amountFolds+=1;
    } else if (sample < (-1-amountFolds) && amountFolds != 0){
      excessSample = sample + (1 + amountFolds);
      return excessSample;
      amountFolds+=1;
    } else if (sample > (1+amountFolds) && amountFolds != 0){
      excessSample = sample + (1 + amountFolds);
      return excessSample;
      amountFolds-=1;
      }
    }
  }


  // fold mode 2 is a folding algo
  // that means when a sample reaches 1.2
  // it folds back to 0.8
  // TODO: This algo still goes past 0.
  while (foldmode == 2){
    // top folding
    if (sample < 1 && sample > -1){
      return sample;
    } else if (sample > 1){
      if (sample > 1 && amountFolds == 0){
        excessSample = sample - 1;
        foldedSample = 1 - excessSample;
        return foldedSample;
        amountFolds+=1;
      } else if (sample > (1+amountFolds) && amountFolds != 0){
        excessSample = sample - (1 + amountFolds);
        foldedSample = 1 - excessSample;
        return foldedSample;
        amountFolds+=1;
      } else if (sample < (1+amountFolds) && amountFolds != 0){
        excessSample = sample - amountFolds;
        foldedSample = 1 - excessSample;
        return foldedSample;
        amountFolds-=1;
      }
  } else if (sample < -1){
    if (sample < -1 && amountFolds == 0){
      excessSample = sample + 1;
      foldedSample = -1 + std::abs(excessSample);
      return foldedSample;
      amountFolds+=1;
    } else if (sample < (-1-amountFolds) && amountFolds != 0){
      excessSample = sample + (1 + amountFolds);
      foldedSample = -1 + std::abs(excessSample);
      return foldedSample;
      amountFolds+=1;
    } else if (sample > (1+amountFolds) && amountFolds != 0){
      excessSample = sample + amountFolds;
      foldedSample = -1 + std::abs(excessSample);
      return foldedSample;
      amountFolds-=1;
      }
    }
  }
}


double Bitcrusher::crusher(double sample){
  int bits = samples.size();
  for (int i = 0; i < bits; i++){
    if ((sample > samples[i-1]) && (sample < samples[i])){
      double crushedSample = samples[i];
      return crushedSample;
    }
  }
}
// Modulo of ratio??
