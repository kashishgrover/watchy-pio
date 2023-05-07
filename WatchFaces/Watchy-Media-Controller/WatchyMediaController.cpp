#include "WatchyMediaController.h"

void WatchyMediaController::handleButtonPress()
{
    uint64_t wakeupBit = esp_sleep_get_ext1_wakeup_status();

    if (wakeupBit & MENU_BTN_MASK)
    {
        Serial.println("Menu button pressed!");
    }
    else if (wakeupBit & BACK_BTN_MASK)
    {
        Serial.println("Back button pressed!");
    }
    else if (wakeupBit & UP_BTN_MASK)
    {
        Serial.println("Up button pressed!");
    }
    else if (wakeupBit & DOWN_BTN_MASK)
    {
        Serial.println("Down button pressed!");
    }
    else
    {
        Serial.println("Not a button!");
    }
}