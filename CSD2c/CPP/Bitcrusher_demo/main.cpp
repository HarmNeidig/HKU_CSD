#include <iostream>
#include <thread>
#include <vector>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "bitcrusher.h"


/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define PI_2 6.28318530717959


// Function from the web to print a vector
void write_vec(const std::vector<double>& vec) {
    for (std::vector<double>::const_iterator iter = vec.begin();
        iter != vec.end(); ++iter) {
        std::cout << *iter << ", ";
      }
}

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;
  // init the jack, use program name as JACK client name
  jack.init("example");
  double samplerate = jack.getSamplerate();
  Sine sine(440, samplerate);
  sine.setFrequency(220);

  Bitcrusher bit;
  bit.setGain(0.5);
  bit.setFoldmode(0);
  bit.makeSampleVector(4);
  std::vector<double> sampleVector = bit.getSampleVector();
  write_vec(sampleVector);
  //assign a function to the JackModule::onProces
  jack.onProcess = [&sine, &bit](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {


    for(unsigned int i = 0; i < nframes; i++) {
      double sample = bit.crusher(bit.clipping(sine.getSample()));
      outBuf[i] = sample;
      sine.tick();
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
