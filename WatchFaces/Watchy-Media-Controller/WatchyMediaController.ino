#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_7C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#include "BleKeyboard.h"

BleKeyboard bleKeyboard;

#define DOWN_LEFT_BUTTON 26
#define UP_LEFT_BUTTON 25
#define UP_RIGHT_BUTTON 35
#define DOWN_RIGHT_BUTTON 4

#define SERVICE_UUID "1655ac6e-ec9d-11ed-a05b-0242ac120003"
#define CHARACTERISTIC_UUID "1bbfbcbc-ec9d-11ed-a05b-0242ac120003"

boolean wasConnected = false;

GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(5, 10, 9, 19));

void initPins()
{
  pinMode(DOWN_LEFT_BUTTON, INPUT);
  pinMode(UP_LEFT_BUTTON, INPUT);
  pinMode(UP_RIGHT_BUTTON, INPUT);
  pinMode(DOWN_RIGHT_BUTTON, INPUT);
}

void printUI()
{
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.setFullWindow();
  display.firstPage();

  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(0, 20);
    display.print("Play");
    display.setCursor(0, 190);
    display.print("Pause");
    display.setCursor(150, 20);
    display.print("Prev");
    display.setCursor(150, 190);
    display.print("Next");
  } while (display.nextPage());
}

void printTextOnDisplay(String text)
{
  Serial.println(text);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby;
  uint16_t tbw, tbh;
  display.getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center the bounding box by transposition of the origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(text);
  } while (display.nextPage());
}

void setup()
{
  display.init(115200, true, 2, false);

  printUI();

  bleKeyboard.begin();
  bleKeyboard.setName("Watchy Media Controller");

  initPins();
}

void handleKeyPresses()
{
  if (digitalRead(DOWN_LEFT_BUTTON) == HIGH)
  {
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
  }

  if (digitalRead(UP_LEFT_BUTTON) == HIGH)
  {
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
  }

  if (digitalRead(UP_RIGHT_BUTTON) == HIGH)
  {
    bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
  }

  if (digitalRead(DOWN_RIGHT_BUTTON) == HIGH)
  {
    bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
  }
}

void loop()
{
  if (bleKeyboard.isConnected() && !wasConnected)
  {
    printUI();
    wasConnected = true;
  }
  else if (!bleKeyboard.isConnected() && wasConnected)
  {
    printTextOnDisplay("Disconnected");
    wasConnected = false;
  }
  else if (bleKeyboard.isConnected() && wasConnected)
  {
    handleKeyPresses();
    delay(500);
  }
}