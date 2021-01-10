#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
const int channel = 0;
/*
  Sharp distance sensor 0-1023 op A0
  MIDI.sendNoteOff(note, velocity, channel);
  MIDI.sendNoteOn(note, velocity, channel);
  150 = verste waarde waar de toon moet klinken
  900 = dichtbijste waarde waar de toon moet klinken
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 1;  // variable to store the value coming from the sensor
int lastPlayedNote = 0;
int ver = 120;
int dicht = 1023;
int rangeKlinkt = dicht - ver;
int presetValue = 3;
int preset_maj8[] = {0, 2, 4, 5 ,7, 9, 11, 12};
int preset_maj6[] = {0, 2, 4, 7, 9, 12};
int preset_min8[] = {0, 2, 3, 5 ,7, 8, 10, 12};
int preset_min6[] = {0, 3, 5, 7, 10, 12};
int stepSize_8 = rangeKlinkt / 8;
int stepSize_6 = rangeKlinkt / 6;
int C = 60;


void setup() {
   MIDI.begin();
   Serial.begin(9600);
   Serial1.setTX(1);
   Serial1.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(lastPlayedNote);    
  MIDI.sendNoteOff(lastPlayedNote, 0, channel);
  if (presetValue == 0){
      // do nothing
  }
    //preset one is maj 8
  if (presetValue == 1){ 
    if (sensorValue < ver){
      lastPlayedNote = 0;
      MIDI.sendNoteOff(lastPlayedNote, 0, channel);
    } else { 
        // first note
        if (sensorValue >= ver && sensorValue < ver+stepSize_8){
          Serial.println("first note plays");
          lastPlayedNote = preset_maj8[0] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
        // second note
        if (sensorValue >= ver+stepSize_8 && sensorValue < ver+(stepSize_8*2)){
          Serial.println("second note plays");
          lastPlayedNote = preset_maj8[1] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
        // third note
        if (sensorValue >= ver+(stepSize_8*2) && sensorValue < ver+(stepSize_8*3)){
          Serial.println("third note plays");
          lastPlayedNote = preset_maj8[2] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
        // forth note
        if (sensorValue >= (ver+(stepSize_8*3))&& (sensorValue < ver+(stepSize_8*4))){
          Serial.println("forth note plays"); 
          lastPlayedNote = preset_maj8[3] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);    
        } 
        // fifth note
        if (sensorValue >= (ver+(stepSize_8*4))&& (sensorValue < ver+(stepSize_8*5))){
          Serial.println("fifth note plays");
          lastPlayedNote = preset_maj8[4] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        }   
        // sixth note
        if (sensorValue >= (ver+(stepSize_8*5))&& (sensorValue < ver+(stepSize_8*6))){
          Serial.println("sixth note plays");
          lastPlayedNote = preset_maj8[5] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        }
        // seventh note
        if (sensorValue >= (ver+(stepSize_8*6))&& (sensorValue < ver+(stepSize_8*7))){
          Serial.println("seventh note plays");
          lastPlayedNote = preset_maj8[6] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        }    
        // eighth note
        if (sensorValue >= (ver+(stepSize_8*7))&& (sensorValue < ver+(stepSize_8*8))){
          Serial.println("eighth note plays");
          lastPlayedNote = preset_maj8[7] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        }
    } 
  }     
  if (presetValue == 2){ 
   if (sensorValue < ver){
      lastPlayedNote = 0;
    } else { 
        // first note
        if (sensorValue >= ver && sensorValue < ver+stepSize_6){
          Serial.println("first note plays");
          lastPlayedNote = preset_maj6[0] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
        // second note
        if (sensorValue >= ver+stepSize_6 && sensorValue < ver+(stepSize_6*2)){
          Serial.println("second note plays");
          lastPlayedNote = preset_maj6[1] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
        // third note
        if (sensorValue >= ver+(stepSize_6*2) && sensorValue < ver+(stepSize_6*3)){
          Serial.println("third note plays");
          lastPlayedNote = preset_maj6[2] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);    
        }
        // forth note
        if (sensorValue >= (ver+(stepSize_6*3))&& (sensorValue < ver+(stepSize_6*4))){
          Serial.println("forth note plays");
          lastPlayedNote = preset_maj6[3] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        } 
        // fifth note
        if (sensorValue >= (ver+(stepSize_6*4))&& (sensorValue < ver+(stepSize_6*5))){
          Serial.println("fifth note plays");
          lastPlayedNote = preset_maj6[4] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }   
        // sixth note
        if (sensorValue >= (ver+(stepSize_6*5))&& (sensorValue < ver+(stepSize_6*6))){
          Serial.println("sixth note plays"); 
          lastPlayedNote = preset_maj6[5] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
    }
   } 
  if (presetValue == 3){ 
    if (sensorValue < ver){
      lastPlayedNote = 0;
    } else { 
        // first note
        if (sensorValue >= ver && sensorValue < ver+stepSize_8){
          Serial.println("first note plays");
          lastPlayedNote = preset_min8[0] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
        // second note
        if (sensorValue >= ver+stepSize_8 && sensorValue < ver+(stepSize_8*2)){
          Serial.println("second note plays");
          lastPlayedNote = preset_min8[1] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
        // third note
        if (sensorValue >= ver+(stepSize_8*2) && sensorValue < ver+(stepSize_8*3)){
          Serial.println("third note plays");
          lastPlayedNote = preset_min8[2] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);    
        }
        // forth note
        if (sensorValue >= (ver+(stepSize_8*3))&& (sensorValue < ver+(stepSize_8*4))){
          Serial.println("forth note plays"); 
          lastPlayedNote = preset_min8[3] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);    
        } 
        // fifth note
        if (sensorValue >= (ver+(stepSize_8*4))&& (sensorValue < ver+(stepSize_8*5))){
          Serial.println("fifth note plays");
          lastPlayedNote = preset_min8[4] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        }   
        // sixth note
        if (sensorValue >= (ver+(stepSize_8*5))&& (sensorValue < ver+(stepSize_8*6))){
          Serial.println("sixth note plays");
          lastPlayedNote = preset_min8[5] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        }
        // seventh note
        if (sensorValue >= (ver+(stepSize_8*6))&& (sensorValue < ver+(stepSize_8*7))){
          Serial.println("seventh note plays");
          lastPlayedNote = preset_min8[6] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        }    
        // eighth note
        if (sensorValue >= (ver+(stepSize_8*7))&& (sensorValue < ver+(stepSize_8*8))){
          Serial.println("eighth note plays");
          lastPlayedNote = preset_min8[7] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        }
    }
  }     
  if (presetValue == 4){
    if (sensorValue < ver){
      lastPlayedNote = 0;
    } else { 
        // first note
        if (sensorValue >= ver && sensorValue < ver+stepSize_6){
          Serial.println("first note plays");
          lastPlayedNote = preset_min6[0] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
        // second note
        if (sensorValue >= ver+stepSize_6 && sensorValue < ver+(stepSize_6*2)){
          Serial.println("second note plays");
          lastPlayedNote = preset_min6[1] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }
        // third note
        if (sensorValue >= ver+(stepSize_6*2) && sensorValue < ver+(stepSize_6*3)){
          Serial.println("third note plays");
          lastPlayedNote = preset_min6[2] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);    
        }
        // forth note
        if (sensorValue >= (ver+(stepSize_6*3))&& (sensorValue < ver+(stepSize_6*4))){
          Serial.println("forth note plays");
          lastPlayedNote = preset_min6[3] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);     
        } 
        // fifth note
        if (sensorValue >= (ver+(stepSize_6*4))&& (sensorValue < ver+(stepSize_6*5))){
          Serial.println("fifth note plays");
          lastPlayedNote = preset_min6[4] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);
        }   
        // sixth note
        if (sensorValue >= (ver+(stepSize_6*5))&& (sensorValue < ver+(stepSize_6*6))){
          Serial.println("sixth note plays"); 
          lastPlayedNote = preset_min6[5] + C;
          MIDI.sendNoteOn(lastPlayedNote, 127, channel);         
      }
    }
  }
  delay(50);          
}
