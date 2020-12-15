#include"Instrument_class.h"

class Guitar_subclass : public Instrument_class{
public:
  // constructor
  Guitar_subclass(std::string name, std::string sound);
  // destrutor
  ~Guitar_subclass();
private:
  std::string name;
  std::string sound;
};
