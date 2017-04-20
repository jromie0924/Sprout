#include <Adafruit_NeoPixel.h>

#define STRIP_PIN 6
#define NUM_PIX 4

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIX, STRIP_PIN, NEO_GRBW + NEO_KHZ800); 

void setup() {
  strip.begin();
  strip.show();
  Serial.begin(9600);

  powerOn();
  delay(1000);
  start();
  delay(20000);
  for(int a = 0; a < strip.numPixels(); a++) {
    strip.setPixelColor(a, 0, 0, 0);
  }
  strip.show();

  delay(1000);
}

void powerOn() {
  
  for (int a = 0; a <= 255; a++) {
    for(int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, a, a, a);
    }
    
    delay(30);
    strip.show();
  }
}

void start() {

  /* +++++++++++++++++++++++++ Growing ++++++++++++++++++++++++++++ */
  for(int i = 255; i >= 0; i--) {
    for(int a = 0; a < strip.numPixels(); a++) {
      strip.setPixelColor(a, i, i, i);
    }
    strip.show();
    delay(1);
  }

  delay(500);
  for(int a = 0; a < 255; a++) {
    strip.setPixelColor(3, 0, a, 0);
    strip.show();
    delay(2);
  }

  /* +++++++++++++++++++++++++ Phone Connection ++++++++++++++++++++++++++++ */
  delay(5000);
  connectPhone();
  connectPhone();
  connectPhone();

  for(int a = 0; a < 255; a++) {
    strip.setPixelColor(2, a, a, a);
    strip.show();
    delay(1);
  }

  /* +++++++++++++++++++++++++ Water ++++++++++++++++++++++++++++ */
  delay(5000);
  for(int a = 0; a < 255; a++) {
    strip.setPixelColor(1, a, 0, 0);
    strip.show();
    delay(2);
  }

  delay(7000);
  for(int a = 255; a >= 0; a--) {
    strip.setPixelColor(1, a, 0, 0);
    strip.show();
    delay(2);
  }

  for(int a = 0; a < 255; a++) {
    strip.setPixelColor(1, a, a, a);
    strip.show();
  }

  /* +++++++++++++++++++++++++ Sunlight ++++++++++++++++++++++++++++ */
  delay(5000);
  for(int a = 0; a < 255; a++) {
    strip.setPixelColor(0, a, 0, 0);
    strip.show();
    delay(2);
  }

  delay(7000);
  for(int a = 255; a >= 0; a--) {
    strip.setPixelColor(0, a, 0, 0);
    strip.show();
    delay(2);
  }

  for(int a = 0; a < 255; a++) {
    strip.setPixelColor(0, a, a, a);
    strip.show();
  }

  delay(10000);
}

void connectPhone() {
  delay(50);
  for(int a = 0; a < 255; a++) {
    strip.setPixelColor(2, a, a, a);
    strip.show();
    delay(2);
  }

  for(int a = 254; a >= 0; a--) {
    strip.setPixelColor(2, a, a, a);
    strip.show();
    delay(2);
  }
}

void loop() {
  
  powerOn();
  delay(1000);
  start();

  
  delay(20000);
  for(int a = 0; a < strip.numPixels(); a++) {
    strip.setPixelColor(a, 0, 0, 0);
  }
  strip.show();

  delay(1000);
}
