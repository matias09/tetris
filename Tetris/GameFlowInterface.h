#ifndef GAME_FLOW_INTERFACE_H 
#define GAME_FLOW_INTERFACE_H 

#include "InputHandlerInterface.h"
#include "GameController.h"

class GameController;
class GameFlowInterface
{
public:
    InputHandlerInterface* inpHdlInt;
    virtual int Run() = 0;
    virtual void Pause() = 0;
    virtual void Exit() = 0;
};

#endif // !GAME_FLOW_INTERFACE_H 