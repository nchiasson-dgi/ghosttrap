#ifndef _SHIFTER_H
#define _SHIFTER_H

class Shifter {
  int latchPin;
  int clockPin;
  int dataPin;
  int totalLeds;
  unsigned long previousMillis;
  bool displayFirstDigit;

  long interval;
  int currentLed = 0;
  int nextLed = 0;
  byte leds = 0;
  bool direction = true;

  public:
  Shifter(int latch, int clock, int data, int ledVal, long intVal, bool firstDigit) {
    latchPin = latch;
    clockPin = clock;
    dataPin = data;
    totalLeds = ledVal;
    interval = intVal;
    displayFirstDigit = firstDigit;
    currentLed = (int)firstDigit;

    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);

    previousMillis = 0;
  }

  void Update() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      updateLeds();
      updateShiftRegister();
      checkDirection();
      //testReport();

      previousMillis = currentMillis;
    }
  }

  void updateLeds() {
    if (currentLed == 0 && leds == 0) {
      bitSet(leds, currentLed);
    }
    else {
      if (direction) {
        getNewLed();
        bitSet(leds, currentLed);
      }
      else {
        bitClear(leds, currentLed);
        getNewLed();
      }
    }
  }

  void getNewLed() {
    if (!direction) {
      currentLed--;
    }
    else {
      currentLed++;
    }

    return currentLed;
  }

  void checkDirection() {
    if (currentLed <= 0 && leds == 0){
      direction = true;
    }
    else if (currentLed >= (totalLeds-1)) {
      direction = false;
    }
  }

  void updateShiftRegister() {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
  }

  byte getLeds() {
    return leds;
  }

  int getCurrentLed() {
    return currentLed;
  }

  void testReport() {
    Serial.print("Current Led: ");
    Serial.println(currentLed);
    Serial.print("Leds: ");
    Serial.println(leds);
    Serial.print("Direction: ");
    Serial.println(direction);
    Serial.println("------------");
  }
};
#endif