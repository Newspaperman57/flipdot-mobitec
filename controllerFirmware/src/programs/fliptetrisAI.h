#ifndef __FLIP_RESET__
#define __FLIP_RESET__

#include "screenprogram.h"
#include <Arduino.h>

class FlipTetrisAI : public ScreenProgram {
  private:
    bool s;
    FlipScreen* sign;
  public:
    FlipTetrisAI(FlipScreen* _sign) : ScreenProgram(_sign) {
    }

    void start() {}
    void stop() {}

    void loop(char* input) {
    }
};

#endif
