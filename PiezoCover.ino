// Piezo buzzer with knock sensor feature
// Copyright (C) 2019 Mastro Gippo
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.

#include <toneAC.h>

#define NOTE_B5  988
#define NOTE_E6  1319

#define ledPin 13
#define knockSensor A0 
#define threshold 40 

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  //knock sensor mode
  pinMode(10, INPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW); 
}

void loop() {
  if (analogRead(knockSensor) >= threshold) {
    delay(10);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    
    toneAC(NOTE_B5,10);
    delay(100);
    toneAC(NOTE_E6,10);
    delay(800);
    toneAC();

    digitalWrite(ledPin, HIGH);
    Serial.println("knock");

    //restore knock sensor mode
    pinMode(10, INPUT);
    pinMode(9, OUTPUT);
    digitalWrite(9, LOW); 

    //wait for the piezo to finish vibrating after emitting the note
    delay(50);
    digitalWrite(ledPin, LOW);
  } 
}
