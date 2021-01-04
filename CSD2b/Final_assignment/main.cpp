#include<iostream>
#include<thread>
#include<string>
#include "jack_module.h"
#include "math.h"
#include "osc.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "melodyGen.h"
#include "synthesizer.h"
#include "time.h"

// Replace with math library M_PI

// to run jack:
// jackd -d coreaudio

int main(int argc,char **argv)
{
  JackModule jack;
  jack.init(argv[0]);
  double samplerate=jack.getSamplerate();
  Synthesizer synthSine(440, samplerate);
  Osc* osc1 = synthSine.selectOsc(1);
  osc1->setFrequency(330);
  jack.onProcess = [&osc1](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = osc1->getSample();
      osc1->tick();
    }
  return 0;
  };
  jack.autoConnect();

  std::cout << "Press x to abort" << std::endl;
  bool running = true;
  while (running)
  {
    switch(std::cin.get())
    {
      case 'x':
        running = false;
        jack.end();
        break;
    }
  }
  return 0;
}
