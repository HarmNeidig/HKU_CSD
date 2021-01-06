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

// to run jack:
// jackd -d coreaudio

int main(int argc,char **argv)
{
  JackModule jack;
  MelodyGen mellow;
  mellow.init();
  jack.init(argv[0]);
  double samplerate=jack.getSamplerate();
  Synthesizer synthSine(0, samplerate);
  int oscSelection;
  std::cout << "What waveform do you want to use?\n";
  std::cout << "1 for Sine\n";
  std::cout << "2 for Saw\n";
  std::cout << "3 for Square\n";
  std::cout << "Your choice: ";
  std::cin >> oscSelection;
  int amountNotes;
  std::cout << "How many notes do you want to generate? \n";
  std::cin >> amountNotes;
  int keyOfChords;
  std::cout << "What key should the progression be?\n";
  std::cout << "0 for C\n";
  std::cout << "1 for C#\n";
  std::cout << "2 for D\n";
  std::cout << "3 for D#\n";
  std::cout << "4 for E\n";
  std::cout << "5 for F\n";
  std::cout << "6 for F#\n";
  std::cout << "7 for G\n";
  std::cout << "8 for G#\n";
  std::cout << "9 for A\n";
  std::cout << "10 for A#\n";
  std::cout << "11 for B\n";
  std::cout << "Your choice: ";
  std::cin >> keyOfChords;
  Osc* root = synthSine.selectOsc(oscSelection);
  Osc* third = synthSine.selectOsc(oscSelection);
  Osc* fifth = synthSine.selectOsc(oscSelection);
  mellow.setKey(keyOfChords);
  jack.onProcess = [&root,&third,&fifth](jack_default_audio_sample_t *inBuf,
      jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
          outBuf[i] = ((root->getSample()+third->getSample()+fifth->getSample())/3);
          root->tick();
          third->tick();
          fifth->tick();
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
      case 'n':
        int newMidiRoot=mellow.generateMidiRoot();
        int newMidiThird=mellow.generateMidiThird(newMidiRoot);
        int newMidiFifth=mellow.generateMidiFifth(newMidiRoot);
        root->setFrequency(mellow.getFreq(newMidiRoot));
        third->setFrequency(mellow.getFreq(newMidiThird));
        fifth->setFrequency(mellow.getFreq(newMidiFifth));
        break;
      case 'k':
        newKey=mellow.generateRandomKey();
        mellow.setKey(newKey);
        break;
    }
  }
  return 0;
}
