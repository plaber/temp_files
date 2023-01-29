#include <NeoPixelBrightnessBus.h>

NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt0Ws2812xMethod>* strip0 = NULL;
NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt1Ws2812xMethod>* strip1 = NULL;
NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt2Ws2812xMethod>* strip2 = NULL;
NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt3Ws2812xMethod>* strip3 = NULL;
NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32I2s0Ws2812xMethod>* strip4 = NULL;
NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32I2s1Ws2812xMethod>* strip5 = NULL;

RgbColor black(0, 0, 0);
RgbColor white(255, 255, 255);
RgbColor dwhite(128, 128, 128);
RgbColor red(255, 0, 0);
RgbColor yellow(255, 255, 0);
RgbColor orange(255, 127, 0);
RgbColor green(0, 255, 0);
RgbColor wgreen(102, 255, 0);
RgbColor blue(0, 0, 255);

int leds = 12;

void setup() {

  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  
  Serial.begin(115200);
  delay(500);
  Serial.println("Hello");
  
  strip0 = new NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt0Ws2812xMethod> (leds, 22);
  strip1 = new NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt1Ws2812xMethod> (leds, 25);
  strip2 = new NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt2Ws2812xMethod> (leds, 26);
  strip3 = new NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt3Ws2812xMethod> (leds, 27);
  strip4 = new NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32I2s0Ws2812xMethod> (leds, 14);
  strip5 = new NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32I2s1Ws2812xMethod> (leds, 23);

  strip0->Begin();
  strip1->Begin();
  strip2->Begin();
  strip3->Begin();
  strip4->Begin();
  strip5->Begin();

    strip0->SetBrightness(16);
    strip1->SetBrightness(16);
    strip2->SetBrightness(16);
    strip3->SetBrightness(16);
    strip4->SetBrightness(16);
    strip5->SetBrightness(16);
}

void led_show(){
    strip0->Show();
    strip1->Show();
    strip2->Show();
    strip3->Show();
    strip4->Show();
    strip5->Show();
}

void set(int i, RgbColor c)
{
  if (i < leds * 1) {strip0->SetPixelColor(i % leds, c); return;}
  if (i < leds * 2) {strip1->SetPixelColor(i % leds, c); return;}
  if (i < leds * 3) {strip2->SetPixelColor(i % leds, c); return;}
  if (i < leds * 4) {strip3->SetPixelColor(i % leds, c); return;}
  if (i < leds * 5) {strip4->SetPixelColor(i % leds, c); return;}
  if (i < leds * 6) {strip5->SetPixelColor(i % leds, c); return;}
}

void led_clearto(char r, char g, char b)
{
  RgbColor color(r, g, b);
  strip0->ClearTo(color);
  strip1->ClearTo(color);
  strip2->ClearTo(color);
  strip3->ClearTo(color);
  strip4->ClearTo(color);
  strip5->ClearTo(color);
}

void loop() {

  led_clearto(255,0,0); led_show(); delay(500);
  led_clearto(0,255,0); led_show(); delay(500);
  led_clearto(0,0,255); led_show(); delay(500);
  led_clearto(0,0,0);
  
  for(int i = 0; i < 72; i++)
  {
    set(i, red); led_show(); set(i, black); delay(30);
  }
    for(int i = 0; i < 72; i++)
  {
    set(i, green); led_show(); set(i, black); delay(30);
  }
    for(int i = 0; i < 72; i++)
  {
    set(i, blue); led_show(); set(i, black); delay(20);
  }
}
