#ifndef __FLIP_RESET__
#define __FLIP_RESET__

#include "screenprogram.h"
#include <Arduino.h>

class FlipReset : public ScreenProgram {
  private:
    bool s;
    FlipScreen* sign;
  public:
    FlipReset(FlipScreen* _sign) : ScreenProgram(_sign) {
      s = false;
      sign = _sign;
    }

    void start() {}
    void stop() {}

    void loop(char* input) {
      for(int x = 0; x < PANEL_WIDTH; x++) {
        for(int y = 0; y < PANEL_HEIGHT; y++) {
          sign->_setDot(x,y,s);
        }
      }
      s = !s;
    }
};

#endif
