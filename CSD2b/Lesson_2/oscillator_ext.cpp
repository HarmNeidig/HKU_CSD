#include<iostream>

//access specifier: public, private, protected
// public: van buiten de class te gebruiken
// protected en private: alleen door het obj zelf te gebruiken

class Oscillator{
public:
  Oscillator();
  ~Oscillator();
  void setFreq(float freq);
  float getFreq;
protected:
  float freq;
};

Oscillator::Oscillator(){
  std::cout << "Oscillator - constructor\n";
}

Oscillator::~Oscillator(){
  std::cout << "Oscillator - destructor\n";
}
//setter
void Oscillator::setFreq(float freq){
  if (freq > 0 && freq < 22050){
    //this pointer
    this->freq = freq;
  } else {
    std::cout << "ERROR" << endl
  }
}
//getter
float Oscillator::getFreq(){
  return freq;
}

int main(){
  Oscillator osc;
  osc.setFreq(220);
  std::cout << "Freq field contains value: " << osc.getFreq() << endl;

}
