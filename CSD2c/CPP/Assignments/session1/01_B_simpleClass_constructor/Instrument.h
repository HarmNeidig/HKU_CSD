#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  //default constructor (different from the implicit default constructor)
  Instrument();
  //it is possible to overload the constructor to allow setting aSound string
  Instrument(std::string aSound);
  // third constructor
  Instrument(std::string aSound, double frequency);

  void makeSound();
  //setter and getter function
  void setSound(std::string aSound);
  std::string getSound();
  double getFreq();

private:
  std::string sound;
  double frequency;
};




#endif
