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
  int choiceOsc;
  int choiceLength;
  int nTimes;
  std::cout << "What waveform do you want to use?" << std::endl;
  std::cout << "1 = Sine, 2 = Saw, 3 = Square" << std::endl;
  std::cout << "Your choice: ";
  std::cin >> choiceOsc;
  if (choiceOsc < 1 || choiceOsc > 3){
    std::cout << "Choice out of range" << std::endl;
    return 0;
  }
  std::cout << "How fast do you want the synth to play?" << std::endl;
  std::cout << "1 = Slow, 2 = Medium, 3 = Fast, 4 = Über fast" << std::endl;
  std::cout << "Your choice: ";
  std::cin >> choiceLength;
  if (choiceLength == 1){
    nTimes = 650;
  } else if (choiceLength == 2){
    nTimes = 500;
  } else if (choiceLength == 3){
    nTimes = 200;
  } else if (choiceLength == 4){
    nTimes = 50;
  } else {
    std::cout << "Choice out of range" << std::endl;
    return 0;
  }
  Generator gen;
  gen.init();
  // create a JackModule instance
  JackModule jack;
  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  Synth synth(880, samplerate);
  Osc* wave = synth.selectOsc(choiceOsc);
  //assign a function to the JackModule::onProces
  jack.onProcess = [&wave,&n,&gen,&nTimes](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // calculate current sample and divide by four so no speakers get hurt
      outBuf[i] = wave->getSample()/2;
      // in the tick function the next sample is calculated
      wave->tick();
      // i goes up to nframes, which is 255
      if (i == 255){
        n += 1;
        // using the n as counter for new notes
        if (n == nTimes){
          // reset n
          n = 0;
          // generate a note (C5 - C6)
          double fqWav = gen.generateNote();
          // print generated content
          std::cout << "random note " << fqWav << std::endl;
          // set frequency
          wave->setFrequency(fqWav);
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
