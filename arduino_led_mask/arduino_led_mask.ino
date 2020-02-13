#include <FastLED.h>

#define LED_PIN A5
#define NUM_LEDS 161
#define NUM_ROWS 7
#define NUM_FIRST_ROW 26
#define LED_TYPE WS2812B
#define COLOR_ORDER RGB
#define BRIGHTNESS 160

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
  // fillColor(10, 160, 103);
  // fillColor(60, 10, 230);
  // fillColor(100, 20, 250);
  // fillColor(10, 200, 163);
  // fillColor(10, 170, 223);
  // FastLED.show();
  // FastLED.delay(500);
  // fillColor(80, 10, 180);
  // FastLED.show();
  // FastLED.delay(500);
  // fadePinkBlue();
  fadeToColor(0, 0, 200, 0, 40, 80, 150, 1);
  delay(10);
  fadeToColor(0, 40, 80, 0, 0, 200, 150, 1);
  delay(10);
  fadeToColor(0, 0, 200, 0, 40, 80, 150, 1);
  delay(10);
  rainbowFade();
  circle();
  circle();
  circle();
  circle();
  circleInverse();
  circleInverse();
  circleInverse();
  circleInverse();
  // FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
  // FastLED.delay(200);
}

void circleInverse()
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
      {5, 40, 190},
      {5, 40, 190},
      {5, 40, 190},
      {80, 5, 190},
      {80, 5, 190}
  };

  for (int x = 4; x >= 0; x--) {
    for (int z = 0; z < 6; z++) {
      for (int i = 0; i < NUM_LEDS; i++) {
        int color = (pattern[i] + x) % 5;
        int nextColor = (color + 1) % 5;
        float r = getColorFade(rgbColors[nextColor][0], rgbColors[color][0], z, 6, i);
        float g = getColorFade(rgbColors[nextColor][1], rgbColors[color][1], z, 6, i);
        float b = getColorFade(rgbColors[nextColor][2], rgbColors[color][2], z, 6, i);
        leds[i] = CRGB(r, g, b);
      }
      FastLED.show();
      FastLED.setMaxPowerInVoltsAndMilliamps(5, 750);
      FastLED.delay(1);
    }
  }
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
  // int rgbColors[5][3] = {
  //     {160, 10, 103},
  //     {5, 5, 230},
  //     {5, 5, 230},
  //     {5, 5, 230},
  //     {5, 5, 230}
  // }

  int rgbColors[5][3] = {
      {120, 10, 143},
      {100, 30, 233},
      {5, 5, 230},
      {5, 5, 230},
      {5, 5, 230},
  };
  for (int x = 0; x < 5; x++) {
    for (int z = 0; z < 4; z++) {
      for (int i = 0; i < NUM_LEDS; i++) {
        int color = (pattern[i] + x) % 5;
        int nextColor = (color + 1) % 5;
        float r = getColorFade(rgbColors[color][0], rgbColors[nextColor][0], z, 4, i);
        float g = getColorFade(rgbColors[color][1], rgbColors[nextColor][1], z, 4, i);
        float b = getColorFade(rgbColors[color][2], rgbColors[nextColor][2], z, 4, i);
        leds[i] = CRGB(r, g, b);
      }
      FastLED.show();
      FastLED.setMaxPowerInVoltsAndMilliamps(5, 750);
      FastLED.delay(1);
    }
  }
}

float getColorFade(int a, int b, int index, int range, int i)
{
  if (a == b)
  {
    return a;
  }
  int dif = abs(a - b);
  float change = (float)dif / range * (index + 1);
  if (a > b)
  {
    return a - change;
  }
  return a + change;
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
