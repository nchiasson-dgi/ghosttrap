#ifndef _BLINKER_H
#define _BLINKER_H

class Blinker {
  int ledPin;
  long OnTime;
  long OffTime;

  int ledState;
  unsigned long previousMillis;
  int count;

  public:
  Blinker(int pin, long on, long off) {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);

    OnTime = on;
    OffTime = off;

    ledState = 0;
    previousMillis = 0;
    count = 0;
  }

  void Update() {
    unsigned long currentMillis = millis();

    if ((ledState) && (currentMillis - previousMillis >= OnTime)) {
      ledState = !ledState;
      previousMillis = currentMillis;
      digitalWrite(ledPin, ledState);
      count++;
    }
    else if ((!ledState) && (currentMillis - previousMillis >= OffTime)) {
      ledState = !ledState;
      previousMillis = currentMillis;
      digitalWrite(ledPin, ledState);
    }
  }

  void resetCount() {
    count = 0;
  }

  int getCount() {
    return count;
  }
};
#endif