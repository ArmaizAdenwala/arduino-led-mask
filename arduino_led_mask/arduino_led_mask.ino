#include <FastLED.h>

#define LED_PIN A5
#define NUM_LEDS 161
#define NUM_ROWS 7
#define NUM_FIRST_ROW 26
#define LED_TYPE WS2812B
#define COLOR_ORDER RGB
#define BRIGHTNESS 190

CRGB leds[NUM_LEDS];

// Sets up FastLED library
void setup()
{
  Serial.begin(9600);
  delay(1000);
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(4.5, 500);
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
  // fillColor(100, 30, 233);
  // FastLED.show();
  // FastLED.delay(500);
  // fillColor(5, 5, 230);
  // FastLED.show();
  // FastLED.delay(500);
  // fillColor(80, 10, 180);
  // FastLED.show();
  // FastLED.delay(500);
  // fadePinkBlue();
  // fadeToColor(0, 0, 200, 0, 40, 80, 150, 1);
  // delay(10);
  // fadeToColor(0, 40, 80, 0, 0, 200, 150, 1);
  // delay(10);
  // fadeToColor(0, 0, 200, 0, 40, 80, 150, 1);
  // delay(10);
  // rainbowFade();
  effect1();
  // circle();
  // circle();
  // circleInverse();
  // circleInverse();
  // circleInverse();
  // circle();
  // circle();
  // circle();
  // circleInverse();
  // circleInverse();
  // circleInverse();
  // FastLED.setMaxPowerInVoltsAndMilliamps(4.5, 500);
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
      {5, 100, 150},
      {5, 100, 150},
      {5, 100, 150},
      {120, 35, 190},
      {120, 35, 190}
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
      FastLED.setMaxPowerInVoltsAndMilliamps(4.5, 750);
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

  int rgbColors[5][3] = {
      {5, 5, 230},
      {130, 170, 23},
      {130, 170, 23},
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
      FastLED.setMaxPowerInVoltsAndMilliamps(4.5, 750);
      FastLED.delay(1);
    }
  }
}

void effect1()
{
  int arr[NUM_LEDS] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };
  int pattern[NUM_LEDS] = {};
  int startIndex = 0;
  for (int row = 0; row < NUM_ROWS; row++) {
    if (row % 2 == 0) {
      for (int index = 0; index < (NUM_FIRST_ROW - row); index ++) {
        pattern[index + startIndex] = arr[index + startIndex];
      }
      startIndex += (NUM_FIRST_ROW - row);
    }
    else {
      for (int index = 0; index < (NUM_FIRST_ROW - row); index ++) {
        pattern[index + startIndex] = arr[startIndex + NUM_FIRST_ROW - row - index];
      }
      startIndex += (NUM_FIRST_ROW - row);
    }
  }

  int rgbColors[5][3] = {
      {5, 5, 230},
      {130, 170, 23},
      {130, 170, 23},
      {5, 5, 230},
      {5, 5, 230},
  };
  for (int i = 0; i < NUM_LEDS; i++) {
    int color = pattern[i];
    if (color == 0) {
      leds[i] = CRGB(0, 0, 5);
    } else {
      leds[i] = CRGB(5, 0, 0);
    }
    FastLED.show();
    FastLED.setMaxPowerInVoltsAndMilliamps(4.5, 750);
    FastLED.delay(100);
  }
  FastLED.show();
  FastLED.setMaxPowerInVoltsAndMilliamps(4.5, 750);
  FastLED.delay(1);
}

int* flipArray(int arr[]) {
  int newArr[NUM_LEDS] = {};
  int startIndex = 0;
  for (int row = 0; row < NUM_ROWS; row++) {
    if (row % 2 == 0) {
      for (int index = 0; index < (NUM_FIRST_ROW - row); index ++) {
        newArr[index + startIndex] = arr[index + startIndex];
      }
      startIndex += (NUM_FIRST_ROW - row);
    }
    else {
      for (int index = 0; index < (NUM_FIRST_ROW - row); index ++) {
        newArr[index + startIndex] = arr[startIndex + NUM_FIRST_ROW - row - index];
      }
      startIndex += (NUM_FIRST_ROW - row);
    }
  }
  return newArr;
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
