#include <FastLED.h>

#define LED_PIN A5
#define NUM_LEDS 160
#define NUM_ROWS 7
#define NUM_FIRST_ROW 26
#define LED_TYPE WS2812B
#define COLOR_ORDER RGB
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
  // fadePink();
  fadePinkBlue();

  FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
  FastLED.delay(200);
}

void fadePinkBlue()
{
  for (float z = 1; z > 0; z -= 0.0025)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(5 * z, 200 * (z / 2), 160);
    }
    FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
    FastLED.show();
    delay(1);
  }
  for (float z = 0; z <= 1; z += 0.0025)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(5 * z, 200 * (z / 2), 160);
    }
    FastLED.setMaxPowerInVoltsAndMilliamps(3, 500);
    FastLED.show();
    delay(1);
  }
}

void fadePink()
{
  for (float z = 1; z > 0.1; z -= 0.0045)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(0, 100 * z, 200 * (z / 2));
    }
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
    FastLED.show();
    delay(2);
  }
  for (float z = 0.1; z <= 1; z += 0.0045)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(0, 100 * z, 160 * (z / 2));
    }
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
    FastLED.show();
    delay(2);
  }
}
