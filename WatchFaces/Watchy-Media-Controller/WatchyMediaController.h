#ifndef WATCHY_MEDIA_CONTROLLER_H
#define WATCHY_MEDIA_CONTROLLER_H

#include <Watchy.h>

class WatchyMediaController : public Watchy{
    public:
        using Watchy::Watchy;
        void handleButtonPress() override;
};

#endif