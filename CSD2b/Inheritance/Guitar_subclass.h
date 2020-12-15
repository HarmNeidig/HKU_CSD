#include"Instrument_class.h"

class Guitar_subclass : public Instrument_class{
public:
  // constructor
  Guitar_subclass(std::string name);
  // destrutor
  ~Guitar_subclass();
private:
  std::string name;
};
