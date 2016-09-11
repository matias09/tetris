#ifndef INPUT_HANDLER_FACTORY_H
#define INPUT_HANDLER_FACTORY_H

#include "InputHandlerInterface.h"

class InputHandlerFactory
{
public:
    InputHandlerInterface* GetInputHandler(const int inputHandlerImp);
};

#endif //INPUT_HANDLER_FACTORY_H
