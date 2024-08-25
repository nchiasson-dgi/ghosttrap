#ifndef _HEADBAR_H
#define _HEADBAR_H

#include "Shifter.h"
#include "Blinker.h"

class Headbar{
  int initialLedPin;
  unsigned long previousMillis;
  long interval;

  Shifter *shifter;
  Blinker *blinker;
  Blinker *blinker2;
  int blinks = 0;
  int totalBlinks = 3;
  bool blinkerInit = false;

  public:
  Headbar(int intPin, int latch, int clock, int data, long _interval) {
    initialLedPin = intPin;
    interval = _interval;
    shifter = new Shifter(latch, clock, data, 8, _interval, false);
    blinker = new Blinker(7, 1000, 500);
    blinker2 = new Blinker(8, 600, 300);
  }

  void Update() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      blinker->Update();
      if(shifter->getCurrentLed() == 7 && blinker2->getCount() < 3) {
        blinker2->Update();
      }
      else {
        shifter->Update();
        if (blinker2->getCount() >= 3) {
          blinker2->resetCount();
        }
      }

      previousMillis = currentMillis;
    }
  }
};
#endif