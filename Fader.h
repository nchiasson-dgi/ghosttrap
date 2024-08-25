#ifndef _FADER_H
#define _FADER_H

#include "Blinker.h"

class Fader: public Blinker {
  long fade;

  public:
  Fader(int pin, long on, long off, long transition):Blinker(pin, on, off) {
    long fade = transition;
  }
};
#endif