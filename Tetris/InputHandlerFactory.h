#ifndef INPUT_HANDLER_FACTORY_H
#define INPUT_HANDLER_FACTORY_H

#include "InputHandlerInterface.h"

class InputHandlerFactory
{
public:
    InputHandlerInterface* GetInputHandler(int inputHandler);
private:
    enum LIBS {
        SDL
    };
};

#endif //INPUT_HANDLER_FACTORY_H
