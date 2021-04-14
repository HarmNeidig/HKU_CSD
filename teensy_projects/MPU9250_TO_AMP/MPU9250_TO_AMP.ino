#include "MPU9250.h"
#include <Math.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=147,108
AudioAmplifier           amp1;           //xy=535,93
AudioAmplifier           amp2;           //xy=571,132
AudioOutputI2S           i2s2;           //xy=865,113
AudioConnection          patchCord1(playSdWav1, 0, amp1, 0);
AudioConnection          patchCord2(playSdWav1, 1, amp2, 0);
AudioConnection          patchCord3(amp1, 0, i2s2, 0);
AudioConnection          patchCord4(amp2, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=476,460
// GUItool: end automatically generated code

#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

MPU9250 mpu;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    AudioMemory(32);
    delay(2000);
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.4);
    sgtl5000_1.inputSelect(myInput);
    if (!mpu.setup(0x68)) {  // change to your own address
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }
    SPI.setMOSI(SDCARD_MOSI_PIN);
    SPI.setSCK(SDCARD_SCK_PIN);
    if (!(SD.begin(SDCARD_CS_PIN))) {
      // stop here, but print a message repetitively
      while (1) {
        Serial.println("Unable to access the SD card");
        delay(500);
      }
    }
    playFile("ZJ.WAV");
}

void loop() {
    float pot1 = analogRead(A0) / 1023.;
    float pot2 = analogRead(A1) / 1023.;
    sgtl5000_1.volume(pot1);
    if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
          amp1.gain(GetRollScaled());
          amp2.gain(GetYawScaled());
          Serial.print("Yaw: ");
          Serial.println(GetYawScaled());
          Serial.print("Roll: ");
          Serial.println(GetRollScaled());
        }
    }
}

float GetRollScaled() {
    float roll = (mpu.getPitch() / 180.);
    if (roll < 0){
      roll = abs(roll);
      }
    return roll;
}

float GetYawScaled() {
    float yaw = (mpu.getYaw() / 180.);
    if (yaw < 0){
      yaw = abs(yaw);
      }
    return yaw;
}


// from the WavFilePlayer.ino teensy audio examples from paul stoffregen
void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);
  playSdWav1.play(filename);
  delay(5);
}
