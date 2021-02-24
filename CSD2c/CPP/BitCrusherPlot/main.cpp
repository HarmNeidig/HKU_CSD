#include <iostream>
#include "sine.h"
#include "bitcrusher.h"
#include "writeToFile.h"

// Function from the web to print a vector
void write_vec(const std::vector<double>& vec) {
    for (std::vector<double>::const_iterator iter = vec.begin();
        iter != vec.end(); ++iter) {
        std::cout << *iter << ", ";
      }
}

int main() {
  // create sine wave
  Bitcrusher bit;
  bit.setFoldmode(1);
  bit.setGain(1.6);
  bit.makeSampleVector(4);
  Sine sine(1, 48000);
  std::cout << "Sine frequency: " << sine.getFrequency() << "\n";
  std::vector<double> sampleVector = bit.getSampleVector();
  std::cout << "Sample vector is " << std::endl;
  write_vec(sampleVector);

  // write 1 second of samples to file
  WriteToFile fileWriter("output.csv", true);
  for(int i = 0; i < 48000; i++) {
    double sampie = sine.getSample();
    fileWriter.write(std::to_string(bit.calculateSignal(sampie)) + "\n");
    sine.tick();
  }

  // end of program
  return 0;
}
