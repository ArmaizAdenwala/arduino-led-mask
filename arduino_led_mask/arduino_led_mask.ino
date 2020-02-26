#include <FastLED.h>

#define LED_PIN A5
#define NUM_LEDS 161
#define NUM_ROWS 7
#define NUM_FIRST_ROW 26
#define LED_TYPE WS2812B
#define BRIGHTNESS 20

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(4.5, 500);
  FastLED.show();
}

// Examples of designs you can loop through
void loop()
{
  // rainbowFade();
  // lineFade();
  // lineFade();
  // lineFade();
  // horizontalLineFade();
  // horizontalLineFade();
  // horizontalLineFade();
  uint_least8_t circlePattern[NUM_LEDS] = {
    0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 1, 1, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0,
      1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 2, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1,
      2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 3, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2,
        3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3,
        3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 3, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3,
          3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 2, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3,
          3, 4, 0, 1, 2, 3, 4, 0, 1, 1, 1, 1, 0, 4, 3, 2, 1, 0, 4, 3
  };
  uint_least8_t linePattern[NUM_LEDS] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
         5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6
  };

  // uint_least8_t line2Pattern[NUM_LEDS] = {
  //   1, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 1, 0, 0, 0, 0, 1,
  //    1, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 0, 0, 0, 3, 3, 2, 2, 2, 1, 1, 0, 0, 0, 1,
  //     1, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 0, 0, 3, 3, 3, 2, 2, 1, 1, 1, 0, 0, 1,
  //      1, 0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 0, 3, 3, 3, 3, 2, 1, 1, 1, 1, 0, 1,
  //       0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 0, 0, 3, 3, 3, 2, 2, 1, 1, 1, 0, 1,
  //        0, 0, 1, 1, 2, 2, 2, 3, 3, 0, 0, 0, 3, 3, 2, 2, 2, 1, 1, 0, 1,
  //         0, 0, 1, 2, 2, 2, 2, 3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 1, 0, 1
  // };

  uint_least8_t verticalLinePattern[NUM_LEDS] = {
    0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0,
     0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0,
      0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0,
       0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0,
        0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0,
         0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0,
          0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0
  };

  uint_least8_t lineColors[5] = { 4, 4, 5, 5, 5 };
  uint_least8_t line2Colors[6] = { 6, 6, 5, 5, 8, 8 };
  uint_least8_t verticalColors[5] = { 9, 9, 10, 10, 10 };
  uint_least8_t tempColors[20] = { 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 2, 2, 2, 2, 2 };
  uint_least8_t circleColors[5]= { 0, 0, 0, 1, 1};
  uint_least8_t circleColors2[5] = { 2, 2, 2, 3, 3 };
  pattern(circlePattern, circleColors, false, 1, 5);
  pattern(circlePattern, circleColors, false, 1, 5);
  pattern(circlePattern, circleColors, false, 1, 5);

  pattern(circlePattern, circleColors2, true, 1, 5);
  pattern(circlePattern, circleColors2, true, 1, 5);
  pattern(circlePattern, circleColors2, true, 1, 5);

  pattern(linePattern, lineColors, false, 1, 5);
  pattern(linePattern, lineColors, false, 1, 5);
  pattern(linePattern, lineColors, false, 1, 5);

  // pattern(line2Pattern, line2Colors, false, 3, 6);
  // pattern(line2Pattern, line2Colors, false, 3, 6);
  // pattern(line2Pattern, line2Colors, false, 3, 6);

  pattern(verticalLinePattern, verticalColors, false, 1.5, 5);
  pattern(verticalLinePattern, verticalColors, false, 1.5, 5);
  pattern(verticalLinePattern, verticalColors, false, 1.5, 5);

  pattern(linePattern, tempColors, false, 1.5, 20);
}

void pattern(uint_least8_t pattern[NUM_LEDS], uint_least8_t rgbColors[5], bool reverse, float speed, uint_least8_t max) {
  uint_least8_t colors[11][3] = {
    {95, 0, 10},
    {130, 170, 23},
    {5, 100, 150},
    {120, 35, 190},
    {5, 160, 60},
    {60, 35, 150},
    {5, 100, 150},
    {0, 30, 170},
    {140, 165, 10},
    {130, 130, 130},
    {10, 100, 00}
  };
  for (uint_least8_t x = 0; x < max; x++) {
    for (uint_least8_t z = 0; z < (4 * speed); z++) {
      for (uint_least8_t i = 0; i < NUM_LEDS; i++) {
        uint_least8_t colorA;
        uint_least8_t colorB;
        if (reverse) {
          colorB = (pattern[i] + (4 - x)) % max;
          colorA = (colorB + 1) % max;
        } else {
          colorA = (pattern[i] + x) % max;
          colorB = (colorA + 1) % max;
        }
        leds[i] = CRGB(
          getColorFade(colors[rgbColors[colorA]][0], colors[rgbColors[colorB]][0], z, (4 * speed), i),
          getColorFade(colors[rgbColors[colorA]][1], colors[rgbColors[colorB]][1], z, (4 * speed), i),
          getColorFade(colors[rgbColors[colorA]][2], colors[rgbColors[colorB]][2], z, (4 * speed), i)
        );
      }
      FastLED.show();
      FastLED.delay(1);
    }
  }
}

float getColorFade(uint_least8_t a, uint_least8_t b, uint_least8_t index, uint_least8_t range, uint_least8_t i)
{
  if (a == b)
  {
    return a;
  }
  uint_least8_t dif = abs(a - b);
  float change = (float)dif / range * (index + 1);
  if (a > b)
  {
    return a - change;
  }
  return a + change;
}

// void horizontalLineFade()
// {
//   uint_least8_t pattern[NUM_LEDS] = {
//     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
//        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
//         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
//           6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
//   };
//   uint_least8_t rgbColors[7][3] = {
//       {5, 160, 60},
//       {5, 160, 60},
//       {60, 35, 150},
//       {60, 35, 150},
//   };

//   for (uint_least8_t x = 3; x >= 0; x--) {
//     for (uint_least8_t z = 0; z < 8; z++) {
//       for (uint_least8_t i = 0; i < NUM_LEDS; i++) {
//         uint_least8_t color = (pattern[i] + x) % 4;
//         uint_least8_t nextColor = (color + 1) % 4;
//         float r = getColorFade(rgbColors[nextColor][0], rgbColors[color][0], z, 8, i);
//         float g = getColorFade(rgbColors[nextColor][1], rgbColors[color][1], z, 8, i);
//         float b = getColorFade(rgbColors[nextColor][2], rgbColors[color][2], z, 8, i);
//         leds[i] = CRGB(r, g, b);
//       }
//       FastLED.show();
//       FastLED.delay(1);
//     }
//   }
// }

// void lineFade()
// {
//   uint_least8_t pattern[NUM_LEDS] = {
//     1, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 1, 0, 0, 0, 0, 1,
//      1, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 0, 0, 0, 3, 3, 2, 2, 2, 1, 1, 0, 0, 0, 1,
//       1, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 0, 0, 3, 3, 3, 2, 2, 1, 1, 1, 0, 0, 1,
//        1, 0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 0, 3, 3, 3, 3, 2, 1, 1, 1, 1, 0, 1,
//         0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 0, 0, 3, 3, 3, 2, 2, 1, 1, 1, 0, 1,
//          0, 0, 1, 1, 2, 2, 2, 3, 3, 0, 0, 0, 3, 3, 2, 2, 2, 1, 1, 0, 1,
//           0, 0, 1, 2, 2, 2, 2, 3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 1, 0, 1
//   };
//   uint_least8_t rgbColors[6][3] = {
//       {5, 100, 150},
//       {5, 100, 150},
//       {120, 35, 190},
//       {120, 35, 190},
//       {140, 165, 10},
//       {140, 165, 10},
//   };

//   for (uint_least8_t x = 5; x >= 0; x--) {
//     for (uint_least8_t z = 0; z < 8; z++) {
//       for (uint_least8_t i = 0; i < NUM_LEDS; i++) {
//         uint_least8_t color = (pattern[i] + x) % 6;
//         uint_least8_t nextColor = (color + 1) % 6;
//         float r = getColorFade(rgbColors[nextColor][0], rgbColors[color][0], z, 8, i);
//         float g = getColorFade(rgbColors[nextColor][1], rgbColors[color][1], z, 8, i);
//         float b = getColorFade(rgbColors[nextColor][2], rgbColors[color][2], z, 8, i);
//         leds[i] = CRGB(r, g, b);
//       }
//       FastLED.show();
//       FastLED.delay(1);
//     }
//   }
// }




// void rainbowFade()
// {
//   fadeToColor(0, 0, 200, 100, 0, 100, 150, 1);
//   delay(10);
//   fadeToColor(100, 0, 100, 0, 0, 200, 150, 1);
//   delay(10);
//   fadeToColor(0, 0, 200, 0, 100, 10, 150, 1);
//   delay(10);
//   fadeToColor(0, 100, 10, 0, 0, 200, 150, 1);
//   delay(10);
// }

// void fillColor(uint_least8_t r, uint_least8_t g, uint_least8_t b)
// {
//   for (uint_least8_t i = 0; i < NUM_LEDS; i++)
//   {
//     leds[i] = CRGB(g, r, b);
//   }
// }

// void fadeToColor(float r1, float g1, float b1, float r2, float g2, float b2, float steps, uint_least8_t speed)
// {
//   float deltaR = (r2 - r1) / steps;
//   float deltaG = (g2 - g1) / steps;
//   float deltaB = (b2 - b1) / steps;
//   float curR = r1;
//   float curG = g1;
//   float curB = b1;

//   float curDeltaR = 0;
//   float curDeltaG = 0;
//   float curDeltaB = 0;
//   for (uint_least8_t i = 0; i < steps; i++)
//   {
//     curDeltaR += deltaR;
//     curDeltaG += deltaG;
//     curDeltaB += deltaB;
//     fillColor(
//         curR + curDeltaR,
//         curG + curDeltaG,
//         curB + curDeltaB);
//     FastLED.show();
//     delay(speed);
//   }
// }
