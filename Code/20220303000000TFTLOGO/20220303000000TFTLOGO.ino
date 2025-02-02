/*---------------------------------------ILI9341_DRIVER 320x240 2.2' TFT-----------------------------------------*/
// https://blog.csdn.net/weixin_45488643/article/details/113702365

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

#define TFT_BL    25
int RotationDisplay = 3;

// http://www.rinkydinkelectronics.com/t_imageconverter565.php
#include "SeaOtterLogo.h"

// https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.h
// Default color definitions
#define TFT_BLACK       0x0000      /*   0,   0,   0 */
#define TFT_NAVY        0x000F      /*   0,   0, 128 */
#define TFT_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define TFT_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define TFT_MAROON      0x7800      /* 128,   0,   0 */
#define TFT_PURPLE      0x780F      /* 128,   0, 128 */
#define TFT_OLIVE       0x7BE0      /* 128, 128,   0 */
#define TFT_LIGHTGREY   0xD69A      /* 211, 211, 211 */
#define TFT_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define TFT_BLUE        0x001F      /*   0,   0, 255 */
#define TFT_GREEN       0x07E0      /*   0, 255,   0 */
#define TFT_CYAN        0x07FF      /*   0, 255, 255 */
#define TFT_RED         0xF800      /* 255,   0,   0 */
#define TFT_MAGENTA     0xF81F      /* 255,   0, 255 */
#define TFT_YELLOW      0xFFE0      /* 255, 255,   0 */
#define TFT_WHITE       0xFFFF      /* 255, 255, 255 */
#define TFT_ORANGE      0xFDA0      /* 255, 180,   0 */
#define TFT_GREENYELLOW 0xB7E0      /* 180, 255,   0 */
#define TFT_PINK        0xFE19      /* 255, 192, 203 */ //Lighter pink, was 0xFC9F      
#define TFT_BROWN       0x9A60      /* 150,  75,   0 */
#define TFT_GOLD        0xFEA0      /* 255, 215,   0 */
#define TFT_SILVER      0xC618      /* 192, 192, 192 */
#define TFT_SKYBLUE     0x867D      /* 135, 206, 235 */
#define TFT_VIOLET      0x915C      /* 180,  46, 226 */

unsigned int colour = TFT_SKYBLUE; // Font Color

void setup()
{
  Serial.begin(115200);   // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)

  // setting PWM properties
#define freq 5000
#define ledChannel 0
#define resolution 8
  int TFT_BLBrightness = 200;
  //
  ledcSetup(ledChannel, freq, resolution); //宣告ledChannel特性
  ledcAttachPin(TFT_BL, ledChannel); //將上述ledChannel附加到ledPin腳位上
  ledcWrite(ledChannel, TFT_BLBrightness);

  tft.init();
  tft.setRotation(RotationDisplay);

  // 這裡擺LOGO
  tft.fillScreen(TFT_WHITE);
  tft.setSwapBytes(true); // pushImage is used for 16-bit sprites, the effect of swap bytes is reversed
  tft.pushImage(0, 0, 320, 240, SeaOtter);
  delay(2000);
  //
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(5, 5, 2);
  tft.setTextColor(TFT_WHITE);
  tft.setTextFont(1);
  tft.println("System Ini...");
  //
}

void loop()
{
  // put your main code here, to run repeatedly:

}
