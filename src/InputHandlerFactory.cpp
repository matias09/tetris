#include "InputHandlerFactory.h"
#include "Config.h"

// Implementations
#include "InputSdlImp.h"

InputHandlerInterface* InputHandlerFactory::GetInputHandler(const int handler)
{
  InputHandlerInterface* inpHnd = nullptr;

  switch (handler) {
  case INPUT_CONFIG::INPUT_IMPLEMENTATION::SDL:
    inpHnd = new InputSdlImp();
    break;
  }

  return inpHnd;
}
