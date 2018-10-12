#include "flipscreen.h"

int FlipScreen::index_to_bitpattern(int index) {
  return 1+index + (index/7);
}

void FlipScreen::_digitalWrite(unsigned char pin, unsigned char state) {
  if(this->gpiostate[pin] == state) return;
  this->gpiostate[pin] = state;
  // digitalWrite(pin, state);
  if(pin < 8) {
    // A
    PORTA_EXTENDER ^= 1 << pin;
    Wire.beginTransmission(0x27);
    Wire.write(0x0A);
    Wire.write(PORTA_EXTENDER);
    if(Wire.endTransmission() != 0) {
      Serial.println("Error!");
    }
  } else {
    // B
    PORTB_EXTENDER ^= 1 << (pin - 8);
    Wire.beginTransmission(0x27);
    Wire.write(0x1A);
    Wire.write(PORTB_EXTENDER);
    if(Wire.endTransmission() != 0) {
      Serial.println("Error!");
    }
  }
}

FlipScreen::FlipScreen() {
  int i = 0;
  Wire.setClock(100000);
  do {
    i = 0;
    Wire.begin();
    Wire.beginTransmission(0x27); // Reconfigure all pins as outputs
    Wire.write(0x00); // Set pointer
    Wire.write(0x00); // 0x00 to 00000000
    Wire.write(0x00); // 0x01 to 00000000
    i += Wire.endTransmission();

    Wire.beginTransmission(0x27); // Enable WEAK (0.4mA) pull-up. Should be enough though
    Wire.write(0x06); // Set pointer
    Wire.write(0xFF); //
    i += Wire.endTransmission();

    Wire.beginTransmission(0x27); // Enable pull-up for bank 2
    Wire.write(0x16); // Set pointer
    Wire.write(0xFF); //
    i += Wire.endTransmission();
    Serial.println(i);
  } while(i != 0);

  i = 0;
  char str[256];
  while(true) {
    clear(true);
    clear(false);
  }

  // fill fast index-map
  for(int i = 0; i < 28; i++) {
    index_to_bitpattern_map[i] = index_to_bitpattern(i);
  }

  // reset lookup tables
  for(int i = 0; i < 40; i++) {
    this->gpiostate[i] = 0x00;
  }

  // All pins in extender are set to output by default
  // set control pins to output
  // pinMode(this->color_pin, OUTPUT);
  // for(int i = 0; i < 4; i++) {
  //   pinMode(this->panel_triggers[i], OUTPUT);
  // }
  // for(int i = 0; i < 5; i++) {
  //   pinMode(this->row_addr_pins[i], OUTPUT);
  //   pinMode(this->col_addr_pins[i], OUTPUT);
  // }

  // pinMode(backlight_pin, OUTPUT);
  _digitalWrite(backlight_pin, backlight_state);

  // clear the screen
  for(int x = 0; x < PANEL_WIDTH; x++) {
    for(int y = 0; y < PANEL_HEIGHT; y++) {
      screenState[x][y] = 0xFF;
      screenBuffer[x][y] = BLACK;
    }
  }
}

void FlipScreen::flip() {
  for(int x = 0; x < PANEL_WIDTH; x++) {
    for(int y = 0; y < PANEL_HEIGHT; y++) {
      _setDot(x,y,screenBuffer[x][y]);
    }
  }
}

void FlipScreen::putPixel(unsigned int x, unsigned int y, unsigned char color) {
  if(x < 0 || y < 0 || x >= PANEL_WIDTH || y >= PANEL_HEIGHT) return;
  screenBuffer[x][y] = color;
}
void FlipScreen::_setDot(unsigned int x, unsigned int y, unsigned char color) {
  if(x < 0 || y < 0 || x >= PANEL_WIDTH || y >= PANEL_HEIGHT || color > 1 || this->screenState[x][y] == color) return;
  this->screenState[x][y] = color;

  int panel = x/28;
  x %= 28;

  for(int i = 0; i < 5; i++) {
    _digitalWrite(this->row_addr_pins[i], index_to_bitpattern_map[y]&(1<<i));
    _digitalWrite(this->col_addr_pins[i], index_to_bitpattern_map[x]&(1<<i));
  }
  _digitalWrite(this->color_pin, color);

  _digitalWrite(this->panel_triggers[panel], HIGH);
  delayMicroseconds(500);
  _digitalWrite(this->panel_triggers[panel], LOW);
  delayMicroseconds(10);
}

void FlipScreen::fillRect(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, unsigned char color) {
  for(int y = y1; y <= y2; y++) {
    for(int x = x1; x <= x2; x++) {
      this->putPixel(x,y, color);
    }
  }
}

void FlipScreen::clear(unsigned char color /*= BLACK*/ ) {
  for(int y = 0; y < PANEL_HEIGHT; y++) {
    for(int x = 0; x < PANEL_WIDTH; x++) {
      this->putPixel(x,y, color);
    }
  }
}

void FlipScreen::putChar(unsigned int x, unsigned int y, char c, unsigned char inverted) {
  for(int _x = 0; _x < 10; _x++) {
    for(int _y = 0; _y < 18; _y++) {
      if(!inverted)
        this->putPixel(x+_x, y+_y, (font[c][_y]&((1<<16)>>_x)) ? WHITE : BLACK);
      else
        this->putPixel(x+_x, y+_y, (font[c][_y]&((1<<16)>>_x)) ? BLACK : WHITE);
    }
  }
}

void FlipScreen::write(const char* str, unsigned char inverted) {
  int strlen = 0;
  unsigned int index = 0;
  while(str[strlen] != '\0') strlen++;

  int x = -1 + PANEL_WIDTH/2 - (strlen*10/2);

  char c;
  while((c = str[index++]) != '\0') {
    this->putChar(x, 0, c, inverted);
    x += 10;
  }
}

void FlipScreen::setBacklight(bool state) {
  backlight_state = state;
  digitalWrite(backlight_pin, state);
}

bool FlipScreen::getBacklight() {
  return backlight_state;
}

void FlipScreen::screenToUart() {
  Serial.println();
  for(int y = 0; y < PANEL_HEIGHT; y++) {
    for(int x = 0; x < PANEL_WIDTH; x++) {
      Serial.print(this->screenState[x][y] ? '.' : '*');
    }
    Serial.println();
  }
  Serial.println();

}
