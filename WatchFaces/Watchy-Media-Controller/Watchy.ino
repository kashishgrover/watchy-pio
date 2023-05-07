#include "WatchyMediaController.h"
#include "settings.h"

WatchyMediaController watchy(settings);

void setup()
{
  Serial.begin(1843200);
  watchy.init();
}

void loop()
{
}