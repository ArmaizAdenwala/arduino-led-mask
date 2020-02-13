#include <FastLED.h>

#define LED_PIN A5
#define NUM_LEDS 161
#define NUM_ROWS 7
#define NUM_FIRST_ROW 26
#define LED_TYPE WS2812B
#define COLOR_ORDER RGB
#define BRIGHTNESS 150

CRGB leds[NUM_LEDS];

// Sets up FastLED library
void setup()
{
  Serial.begin(9600);
  delay(1000);
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
  FastLED.clear();
  FastLED.show();
}

// Examples of designs you can loop through
void loop()
{
  // fadePinkBlue();
  // rainbowFade();
  circle();
  // FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
  // FastLED.delay(200);
}

void circle()
{
  int pattern[NUM_LEDS] = {
    0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 1, 1, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0,
     1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 2, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1,
      2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 3, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2,
       3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3,
        3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 3, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3,
         3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 2, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3,
          3, 4, 0, 1, 2, 3, 4, 0, 1, 1, 1, 1, 0, 4, 3, 2, 1, 0, 4, 3
  };
  int rgbColors[5][3] = {
      {10, 50, 90},
      {40, 20, 40},
      {170, 30, 60},
      {190, 70, 180},
      {10, 150, 162},
  };
  for (int z = 0; z < 5; z++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      int color = (pattern[i] + z) % 5;
      leds[i] = CRGB(rgbColors[color][0], rgbColors[color][1], rgbColors[color][2]);
    }
    delay(200);
    FastLED.show();
  }
}

void getIndex() {

}

void rainbowFade()
{
  fadeToColor(0, 0, 200, 100, 0, 100, 150, 1);
  delay(10);
  fadeToColor(100, 0, 100, 0, 0, 200, 150, 1);
  delay(10);
  fadeToColor(0, 0, 200, 0, 100, 10, 150, 1);
  delay(10);
  fadeToColor(0, 100, 10, 0, 0, 200, 150, 1);
  delay(10);
}

void fillColor(int r, int g, int b)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(g, r, b);
  }
}

void fadeToColor(float r1, float g1, float b1, float r2, float g2, float b2, float steps, int speed)
{
  float deltaR = (r2 - r1) / steps;
  float deltaG = (g2 - g1) / steps;
  float deltaB = (b2 - b1) / steps;
  float curR = r1;
  float curG = g1;
  float curB = b1;

  float curDeltaR = 0;
  float curDeltaG = 0;
  float curDeltaB = 0;
  for (int i = 0; i < steps; i++)
  {
    curDeltaR += deltaR;
    curDeltaG += deltaG;
    curDeltaB += deltaB;
    fillColor(
        curR + curDeltaR,
        curG + curDeltaG,
        curB + curDeltaB);
    FastLED.show();
    delay(speed);
  }
}
