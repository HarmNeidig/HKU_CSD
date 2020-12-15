#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
class Instrument_class
{
public:
  // constructor
  Instrument_class(std::string name, std::string sound);
  // destrutor
  ~Instrument_class();
  // setters
  void setAmp(int amp);
  void setName(std::string name);
  void setRange(int range);
  // getters
  int getAmp();
  std::string getName();
  std::string getSound();
  int getRange();
  // method
  void play();
protected:
  int range;
  int amp;
  std::string name;
  std::string sound;
};

#endif
