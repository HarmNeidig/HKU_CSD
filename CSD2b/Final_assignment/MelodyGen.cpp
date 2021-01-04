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
  return (a / 32) * pow(2, ((midiValue - 9) / 12));
}

double MelodyGen::getFreqRoot(int midiRoot){
  freqRoot = mtof(midiRoot);
  return freqRoot;
}

double MelodyGen::getFreqThird(int midiThird){
  freqThird = mtof(midiThird);
  return freqThird;
}

double MelodyGen::getFreqFifth(int midiFifth){
  freqFifth = mtof(midiFifth);
  return freqFifth;
}
