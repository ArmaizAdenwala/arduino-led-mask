#include <FastLED.h>

#define LED_PIN A5
#define NUM_LEDS 160
#define NUM_ROWS 7
#define NUM_FIRST_ROW 26
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS 90

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
  // fillColor(0, 0, 200);
  fadeToColor(0, 0, 10, 20, 0, 100, 150, 1);
  fadeToColor(20, 0, 100, 0, 0, 10, 150, 1);
  // FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
  // FastLED.delay(200);
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
    FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
    FastLED.show();
    delay(speed);
  }
}
// void fadePinkBlue()
// {
//   for (float z = 1; z > 0; z -= 0.0025)
//   {
//     for (int i = 0; i < NUM_LEDS; i++)
//     {
//       leds[i] = CRGB(5 * z, 200 * (z / 2), 160);
//     }
//     FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
//     FastLED.show();
//     delay(1);
//   }
//   for (float z = 0; z <= 1; z += 0.0025)
//   {
//     for (int i = 0; i < NUM_LEDS; i++)
//     {
//       leds[i] = CRGB(5 * z, 200 * (z / 2), 160);
//     }
//     FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
//     FastLED.show();
//     delay(1);
//   }
// }
