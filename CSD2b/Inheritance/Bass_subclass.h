#include"Instrument_class.h"

class Bass_subclass : public Instrument_class{
public:
  // constructor
  Bass_subclass(std::string name);
  // destrutor
  ~Bass_subclass();
private:
  std::string name;
};
