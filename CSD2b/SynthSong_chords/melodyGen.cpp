#include"melodyGen.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

MelodyGen::MelodyGen(){
    std::cout << "Melody generator begins" << std::endl;
}

MelodyGen::~MelodyGen(){
  std::cout << "Melody generator ends" << std::endl;
}

void MelodyGen::setKey(int key){
  this->key = key;
}

int MelodyGen::getKey(){
  return key;
}

void MelodyGen::init(){
  srand(std::time(0));
}

int MelodyGen::generateMidiRoot(){
  randNote = (rand() % 3)+(rand() % 4);
  int midiSine = (scale[randNote]);
  return midiRoot;
}

int MelodyGen::generateRandomKey(){
  randKey = (rand() % 3)+(rand() % 4);
  return randKey;
}

int MelodyGen::generateMidiThird(int midiRoot){
  int index = ((randNote + 2) % 7);
  int midiThird = scale[index];
  if (midiThird < midiRoot){
    midiThird+=12;
  }
  return midiThird;
}

int MelodyGen::generateMidiFifth(int midiRoot){
  int index = ((randNote + 4) % 7);
  int midiFifth = scale[index];
  if (midiFifth < midiRoot){
    midiFifth+=12;
  }
  return midiFifth;
}

double MelodyGen::mtof(int midiValue){
  int a = 440; //frequency of A (coomon value is 440Hz)
  return (a / 32) * pow(2, (((midiValue+key) - 9) / 12));
}

double MelodyGen::getFreq(int midiNote){
  freq = mtof(midiNote);
  return freq;
}
