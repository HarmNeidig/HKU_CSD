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
      crusher(sample);
    }
  }


  // foldmode 1 folds back from 0
  // If the sample is 1.2 it folds back to 0.2
  // TODO: This mode still doesnt operate properly
  while (foldmode == 1){
    // if between -1 and 1 return sample (no folding)
    if (sample < 1 && sample > -1){
      return sample;
    }
    // bottom half folding (-)
    else if (sample < -1){
      if (amountFolds == 0){
        excessSample = sample + 1;
        if (excessSample != -1){
          return excessSample;
        }
        if (excessSample <= -1){
          amountFolds = amountFolds + 1;
          return excessSample;
        }
      } else if (amountFolds != 0 && sample <= (-1-amountFolds)){
        excessSample = sample + (amountFolds + 1);
        if (excessSample != -1){
          return excessSample;
        }
        if (excessSample <= -1){
          amountFolds = amountFolds + 1;
          return excessSample;
        }
      } else if (amountFolds != 0 && sample >= (-1-amountFolds)){
        excessSample = sample + (amountFolds + 1);
        if (excessSample != -1){
          return excessSample;
        }
        if (excessSample >= 0){
          amountFolds = amountFolds - 1;
          return excessSample;
        }
        }
    }
    // top half folding (+)
    else if (sample > 1){
      // first fold
      if (amountFolds == 0){
        excessSample = sample - 1;
        if (excessSample != 1){
          return excessSample;
        }
        if (excessSample > 1){
          amountFolds+=1;
          return excessSample;
        }
        // left of the fold
      } else if (amountFolds != 0 && sample > (1+amountFolds) &&
      sample > amountFolds){
        excessSample = sample - (amountFolds + 1);
        if (excessSample < 1){
          return excessSample;
        }
        if (excessSample > 1){
          amountFolds = amountFolds + 1;
          return excessSample;
        }
        // go from 1 to -1
      } else if (amountFolds != 0 && sample < (1+amountFolds) &&
      sample < amountFolds){
        excessSample = sample - (amountFolds + 1);
        if (excessSample != 0){
          return excessSample;
        }
        if (excessSample <= 0){
          amountFolds = amountFolds - 1;
          return excessSample;
        }
      }
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
