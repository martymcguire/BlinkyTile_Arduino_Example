// Rainbow Demo Sketch for a BlinkyTile sculpture.
//
// Should work with any 168, 328, or 32U4 based Arduino.
// Tested with BlinkyTape Controller RevH
//
// Based on WS282x_Programmer Copyright 2014 Matt Mets
// Simplification by Marty McGuire

#include "DmxSimpleMod.h"

#define DATA_PIN    13      // Pin connected to the data output

int maxPixel      = 14;    // Maximum pixel to display

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(DATA_PIN, LOW);
  
  DmxSimple.usePin(DATA_PIN);
  DmxSimple.maxChannel(maxPixel*3);
  DmxSimple.begin();
  
}

void writePixel(int pixel, int r, int g, int b) {
  DmxSimple.write((pixel - 1)*3 + 1, b);
  DmxSimple.write((pixel - 1)*3 + 2, g);
  DmxSimple.write((pixel - 1)*3 + 3, r);   
}

void color_loop() {  
  static uint8_t i = 0;
  static int j = 0;
  static int f = 0;
  static int k = 0;
  static int count;

  static int pixelIndex;
  
  for (uint16_t i = 0; i < maxPixel*10; i+=10) {
    writePixel(i/10+1,
      128*(1+sin(i/30.0 + j/1.3       )),
      128*(1+sin(i/10.0 + f/2.9)),
      128*(1+sin(i/25.0 + k/5.6))
//      128*(1+sin(i/10.0 + f/9.0  + 2.1)),
//      128*(1+sin(i/30.0 + k/14.0 + 4.2))
    );
  }
  
  j = j + 1;
  f = f + 1;
  k = k + 2;
}

void loop() {
  color_loop();
}
