#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
class Instrument_class
{
public:
  // constructor
  Instrument_class(std::string name);
  // destrutor
  ~Instrument_class();
  // setters
  void setAmp(int amp);
  void setName(std::string name);
  void setRange(int range);
  // getters
  int getAmp();
  std::string getName();
  int getRange();
  // method
  void play();
protected:
  int range;
  int amp;
  std::string name;
};

#endif
