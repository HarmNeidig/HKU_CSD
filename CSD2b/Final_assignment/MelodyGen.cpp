#include"melodyGen.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

MelodyGen::MelodyGen(int key){
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

int MelodyGen::generateMidiSine(){
  randNote = (rand() % 3)+(rand() % 4);
  int midiSine = (scale[randNote]);
  return midiSine;
}

int MelodyGen::generateMidiSaw(int midiSine){
  int index = ((randNote + 2) % 7);
  int midiSaw = scale[index];
  if (midiSaw < midiSine){
    midiSaw+=12;
  }
  return midiSaw;
}

int MelodyGen::generateMidiSquare(int midiSine){
  int index = ((randNote + 4) % 7);
  int midiSquare = scale[index];
  if (midiSquare < midiSine){
    midiSquare+=12;
  }
  return midiSquare;
}

double MelodyGen::mtof(int midiValue){
  int a = 440; //frequency of A (coomon value is 440Hz)
  return (a / 32) * pow(2, ((midiValue - 9) / 12));
}

double MelodyGen::getFreqSine(int midiSine){
  freqSine = mtof(midiSine);
  return freqSine;
}

double MelodyGen::getFreqSaw(int midiSaw){
  freqSaw = mtof(midiSaw);
  return freqSaw;
}

double MelodyGen::getFreqSquare(int midiSquare){
  freqSquare = mtof(midiSquare);
  return freqSquare;
}
