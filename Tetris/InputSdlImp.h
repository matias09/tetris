#ifndef INPUT_SDL_IMP_H
#define INPUT_SDL_IMP_H

#include "InputHandlerInterface.h"

class InputSdlImp : public InputHandlerInterface
{
public:
    InputSdlImp() {};
    virtual ~InputSdlImp();
    virtual signed int GetInput();
private:
    bool _mIsSdlEventsInitialized = false;

    const int SDL_EVENT_INITIALIZED = 0;
};
#endif // !INPUT_SDL_IMP_H