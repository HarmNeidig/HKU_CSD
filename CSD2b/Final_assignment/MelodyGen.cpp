#include<MelodyGen.h>
#include<iostream>
#include<string>

MelodyGen::MelodyGen(int key, int timeInterval) : key(key),
  timeInterval(timeInterval)
  {
    std::cout << "Melody generator begins/n"
}

MelodyGen::~MelodyGen(){
  std::cout << "Melody generator ends/n"
}

MelodyGen::void setKey(int key){
  this->key = key;
}

MelodyGen::std::string getKey(){
  return key;
}

MelodyGen::double mtof(int midivalue){

}
MelodyGen::double getFreqSine();

protected:
  int key;
  double freqSine;
  double freqSaw;
  double freqSquare;
  int midivalue;
};

#endif
