
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=259,198
AudioEffectGranular      granular1;      //xy=448,190
AudioOutputI2S           audioOutput;    //xy=626,189
AudioConnection          patchCord1(i2s1, 0, granular1, 0);
AudioConnection          patchCord2(granular1, 0, audioOutput, 0);
AudioConnection          patchCord3(granular1, 0, audioOutput, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=281,258
// GUItool: end automatically generated code


Bounce button0 = Bounce(2, 15);
Bounce toggle = Bounce(17, 15);


#define GRANULAR_MEMORY_SIZE 12800  // enough for 290 ms at 44.1 kHz
int16_t granularMemory[GRANULAR_MEMORY_SIZE];

void setup() {
  Serial.begin(9600);
  AudioMemory(10);

  pinMode(2, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  
  // the Granular effect requires memory to operate
  granular1.begin(granularMemory, GRANULAR_MEMORY_SIZE);
}


void loop() {
  // read button and toggle
  button0.update();
  toggle.update();
  // read knobs, scale to 0-1.0 numbers
  float sensor = (float)analogRead(A0) / 1023.0;
  float knobA1 = (float)analogRead(A1) / 1023.0;
  float knobA2 = ((float)analogRead(A2) / 1023.0);
  sgtl5000_1.volume(knobA1);


  // button starts Freeze effect
  if (button0.fallingEdge()) {
    float msec = 100.0 * (powf(2.0, knobA2 * 2.0 - 1.0));
    granular1.beginFreeze(msec);
    Serial.print("Begin granular freeze using ");
    Serial.print(msec);
    Serial.println(" grains");
    float knobA2 = ((float)analogRead(A2) / 1023.0);

  }
  if (button0.risingEdge()) {
    granular1.stop();
  }

  // toggle starts Pitch Shift effect
  if (toggle.fallingEdge()) {
    float msec = 25.0 + (sensor * 75.0);
    granular1.beginPitchShift(msec);
    Serial.print("Begin granular pitch phift using ");
    Serial.print(msec);
    Serial.println(" grains");
  }
  if (toggle.risingEdge()) {
    granular1.stop();
  }
  
  // Continuously adjust the speed, based on the sensor
  float ratio;
  ratio = powf(2.0, sensor * 2.0 - 1.0); // 0.5 to 2.0
  granular1.setSpeed(ratio);
}
