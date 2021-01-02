#ifndef _MELODYGEN_H_
#define _MELODYGEN_H_
#include<iostream>
#include<string>

class MelodyGen{
public:
  MelodyGen(int key, int timeInterval);
  ~MelodyGen();
  void setKey(int key);
  std::string getKey();
  double mtof(int midivalue);
  double getFreqSine();
protected:
  int key;
  double freqSine;
  double freqSaw;
  double freqSquare;
  int midivalue;
};

#endif
