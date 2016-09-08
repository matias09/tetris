#ifndef INPUT_SDL_IMP
#define INPUT_SDL_IMP

#include "InputHandlerInterface.h"

class InputSdlImp : public InputHandlerInterface
{
public:
    InputSdlImp();
    ~InputSdlImp();
    virtual signed int GetInput();
private:
    bool _mIsSdlEventsInitialized = false;
    const int SDL_EVENT_INITIALIZED = 0;
};
#endif