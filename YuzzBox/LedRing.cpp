#include "LedRing.h"
#include "hsv.h"

LedRing::LedRing(Adafruit_NeoPixel* _ring)
  : ring(_ring){
  size = ring->numPixels();
  position = 0;
}

void LedRing::chargingAnimation(int wait) {
  for (int i = 0; i < size; i++) {
    
    uint32_t redColor = getPixelColorHsv( i, 0, 255, ring->gamma8(i * (255 / size)) );
    // Extract red, green, and blue components
    uint8_t red = (redColor >> 16) & 0xFF;
    uint8_t green = (redColor >> 8) & 0xFF;
    uint8_t blue = redColor & 0xFF;
    // Swap red and green components
    uint32_t greenColor = (uint32_t(green) << 16) | (uint32_t(red) << 8) | blue;
    ring->setPixelColor( (i + position) % size, greenColor);
  }
  ring->show();
  position++;
  position %= size;
  delay(wait);
  ring->clear();
}

void LedRing::dischargingAnimation(int wait) {
  for (int i = 0; i < size; i++) {
    ring->setPixelColor((i + position) % size, getPixelColorHsv(i, 0, 255, ring->gamma8(i * (255 / size))));
  }
  ring->show();
  position++;
  position %= size;
  delay(wait);
  ring->clear();
}
