/* Mono Peak Meter

   Scrolling peak audio level meter in the Arduino Serial Monitor

   Audio input needs to connect to pin 16 (A2).  The signal range is 0 to 1.2V.
   See the documentation in the Audio System Design Tool for the recommended
   circuit to connect an analog signal.

   This example code is in the public domain
*/

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputAnalog         adc1;           //xy=164,95
AudioAnalyzePeak         peak1;          //xy=317,123
AudioConnection          patchCord1(adc1, peak1);
// GUItool: end automatically generated code

int led = 3;

void setup() {
  AudioMemory(4);
  Serial.begin(9600);
}

// for best effect make your terminal/monitor a minimum of 31 chars wide and as high as you can.
float blowState = 0.;
elapsedMillis fps;

void loop() {
  if (fps > 24) {
    if (peak1.available()) {
      fps = 0;
      float monoPeak = peak1.read() * 100.0;
      Serial.print("|");
      for (int cnt=0; cnt<monoPeak; cnt++) {
      }
      if (monoPeak > 85.0){
        blowState = monoPeak;
        delay(20);
      } else {
        blowState = 0;
      }
      Serial.println();
    }
  }
}
