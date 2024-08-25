#include "Blinker.h"
#include "Shifter.h"
#include "Fader.h"
#include "Headbar.h"

//Blinker led1(A0, 100, 400);
//Shifter shifter1(5, 6, 4, 8, 1000, false);
//Fader fade1(A1, 200, 400, 1000);
Headbar headBar(2, 5, 6, 4, 100);
int incomingByte = 0;
int test;

void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(9, OUTPUT);
}

bool runOnce = true;
int current = 0;
int next = 5;
unsigned long previousMillis = 0;
bool whiteflasher = true;

void loop() {
  unsigned long currentMillis = millis();

  headBar.Update();
  if (currentMillis - previousMillis >= random(50, 1000)) {
    analogWrite(A0, random(0, 256));
    analogWrite(A1, random(0, 256));
    analogWrite(A2, random(0, 256));
    digitalWrite(9, whiteflasher = !whiteflasher);
    previousMillis = currentMillis;
  }
}