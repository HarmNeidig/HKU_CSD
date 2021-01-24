#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "osc.h"
#include "sine.h"
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
  Synth synth(440, samplerate);
  Osc* carrier = synth.selectOsc(1);
  Osc* modulator = synth.selectOsc(1);
  modulator->setFrequency(1);
  //assign a function to the JackModule::onProces
  jack.onProcess = [&carrier,&modulator,&n,&gen](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = (carrier->getSample()*modulator->getSample())/2;
      carrier->tick();
      modulator->tick();
      if (i == 255){
//        std::cout << "this samp = " << outBuf[i] << std::endl;
        n += 1;
//        std::cout << n << std::endl;
        if (n == 300){
          n = 0;
            double fqCar = gen.generateNote();
            double fqMod = gen.generateRatio(fqCar);
            std::cout << "random note " << fqCar << std::endl;
            std::cout << "random ratio " << fqMod << std::endl;
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
