#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "osc.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "synth.h"
#include "generator.h"


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
  int n;
  Generator gen;
  gen.init();
  // create a JackModule instance
  JackModule jack;
  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  Synth synth(880, samplerate);
  Osc* carrier = synth.selectOsc(3);
  Osc* modulator = synth.selectOsc(1);
  modulator->setFrequency(8.8);
  //assign a function to the JackModule::onProces
  jack.onProcess = [&carrier,&modulator,&n,&gen](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // calculate current sample and divide by four so no speakers get hurt
      outBuf[i] = (carrier->getSample()*modulator->getSample())/4;
      // in the tick function the next sample is calculated
      carrier->tick();
      modulator->tick();
      // i goes up to nframes, which is 255
      if (i == 255){
        n += 1;
        // using the n as counter for new notes
        if (n == 500){
          // reset n
          n = 0;
          // generate a note for carrier (C5 - C6)
          double fqCar = gen.generateNote();
          // generate a ratio for modulator (which is based on the carrier freq)
          double fqMod = gen.generateRatio(fqCar);
          // print generated content
          std::cout << "random note " << fqCar << std::endl;
          std::cout << "random ratio " << fqMod << std::endl;
          // set frequencies
          carrier->setFrequency(fqCar);
          modulator->setFrequency(fqMod);
        }
      }
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
