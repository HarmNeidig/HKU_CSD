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
  // generates a random number in the key
  int generateMidiSine();
  int generateMidiSaw(int midiSine);
  int generateMidiSquare(int midiSine);
  // function to convert a midi note to a freq
  double mtof(int midiValue);
  // gets the frequencies
  double getFreqSine(int midiSine);
  double getFreqSaw(int midiSaw);
  double getFreqSquare(int midiSquare);
protected:
  int randNote;
  int scale[7] = {0,2,4,5,7,9,11};
  int key;
  double freqSine;
  double freqSaw;
  double freqSquare;
  int midivalue;
};

#endif
