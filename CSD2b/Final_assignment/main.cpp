#include<iostream>
#include<thread>
#include "jack_module.h"
#include "math.h"
#include "osc.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

// Replace with math library M_PI

// to run jack:
// jackd -d coreaudio

int main(int argc,char **argv)
{
  JackModule jack;
  jack.init(argv[0]);
  double samplerate=jack.getSamplerate();
  Saw sine(820.0, samplerate);

  jack.onProcess = [&sine](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = sine.getSample();
      std::cout << sine.getSample() << std::endl;
      sine.tick();
    }
  return 0;
  };
  jack.autoConnect();

  std::cout << "Press q to stop" << std::endl;
  bool running = true;
  while (running)
  {
    switch(std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }

  return 0;
}
