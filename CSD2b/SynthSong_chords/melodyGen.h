#ifndef _MELODYGEN_H_
#define _MELODYGEN_H_
#include<iostream>
#include<string>

class MelodyGen{
public:
  MelodyGen();
  ~MelodyGen();
  // sets the key for the chord progression
  void setKey(int key);
  // gets the key
  int getKey();
  // gives a seed to rand()
  void init();
  // generate random key
  int generateRandomKey();
  // generates a random number in the key
  int generateMidiRoot();
  int generateMidiThird(int midiRoot);
  int generateMidiFifth(int midiRoot);
  // function to convert a midi note to a freq
  double mtof(int midiValue);
  // gets the frequencies
  double getFreq(int midiNote);
protected:
  int midiRoot;
  int midiThird;
  int midiFifth;
  int randKey;
  int randNote;
  int midiNote;
  int scale[7] = {0,2,4,5,7,9,11};
  int key;
  double freq;
  int midivalue;
};

#endif
