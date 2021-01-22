#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "osc.h"
#include "sine.h"
#include "fm_synth.h"


/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;
  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  FM_Synth synth(samplerate);
  Osc* carrier = synth.makeCar(1, 440.);
  std::cout<<"carrier freq = "<<carrier->getFrequency()<<std::endl;
  Osc* modulator = synth.makeMod(1, 4.);
  std::cout<<"mod freq = "<<modulator->getFrequency()<<std::endl;

  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {


    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = synth.getSampleCar()*synth.getSampleMod()/2.;
      synth.tickAll();
    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }

  //end the program
  return 0;
}
