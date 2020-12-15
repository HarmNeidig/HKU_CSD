#include"Instrument_class.h"

class Bass_subclass : public Instrument_class{
public:
  // constructor
  Bass_subclass(std::string name, std::string sound);
  // destrutor
  ~Bass_subclass();
private:
  std::string name;
  std::string sound;
};
