#include <Arduino.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include "engine.cpp"
#include <Vector.h>

TFT_eSPI tft; 
typedef Vector<int> Elements;


void setup()
{
  digitalWrite(LCD_BACKLIGHT, HIGH); // turn on the backlight
  tft.begin();
  tft.setRotation(1);
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);           
}

void loop()
{
  //tft.begin();
	Engine3D demo(&tft);
  demo.OnUserCreate();
  while(1) {
    demo.OnUserUpdate(millis()/200000.0f);
  }
}
