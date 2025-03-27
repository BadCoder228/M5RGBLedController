#include <M5Stack.h>
#undef min

#include <BaseX.h>
#include <Adafruit_NeoPixel.h>

#define PixelPin 26 
#define PixelPort 3   

Adafruit_NeoPixel RgbData = Adafruit_NeoPixel(PixelPort, PixelPin, NEO_GRB + NEO_KHZ800); 

BASE_X BaseX = BASE_X();

void PixelShow(int *arr);

void setup(){ // <= like [redacted]
  m5.begin();
  m5.Power.begin();
  RgbData.begin();
  RgbData.setBrightness(100);
}

void loop(){ // <= like [redacted]
  m5.update();
  /* port value
      vvv   v  
      red - 1; green - 2; blue - 3*/
  int color_value[3];
  for (byte i = 0; i < 3; i++)
  color_value[i] = int(abs((BaseX.GetEncoderValue(1 + i) % 360) * 0.7));
  PixelShow(color_value);
}

void PixelShow(int *arr){
  //need array to continue
  for (byte i = 0; i < 3; i++)
  RgbData.setPixelColor(i, RgbData.Color(*arr, *(arr+1), *(arr+2)));
  RgbData.show();
}