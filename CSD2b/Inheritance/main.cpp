#include<iostream>
#include"Instrument_class.h"
#include"Guitar_subclass.h"
#include"Bass_subclass.h"

int main(){
  Guitar_subclass Guitar("guitar", "ploink");
  Bass_subclass Bass("bassssss", "brrrrr");
  Guitar.setRange(20);
  Bass.setRange(2);
  Bass.setAmp(99);
  Guitar.play();
  Bass.play();
  return 0;
}
