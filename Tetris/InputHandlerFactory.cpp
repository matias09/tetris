#include "InputHandlerFactory.h"
#include "InputSdlImp.h"

InputHandlerInterface* InputHandlerFactory::GetInputHandler(int inputHandler)
{
    InputHandlerInterface* inpHnd = nullptr;

    switch (inputHandler)
    {
    case LIBS::SDL:
        inpHnd = new InputSdlImp();
        break;
    }

    return inpHnd;
}
