#ifndef GAME_FLOW_INTERFACE_H 
#define GAME_FLOW_INTERFACE_H 

#include "InputHandlerInterface.h"
#include "GraphicHandlerInterface.h"

class GameFlowInterface
{
public:
    virtual ~GameFlowInterface() {};
    virtual signed int Run(InputHandlerInterface& inpHandler, GraphicHandlerInterface& grpHandler) = 0;
    virtual void Pause() = 0;
    virtual void Exit() = 0;
    virtual bool _ThereIsCollision() = 0;

    const int COORDINATE_ELEMENTS = 2;
    const int X_COORDINATE = 0;
    const int Y_COORDINATE = 1;
};

#endif // !GAME_FLOW_INTERFACE_H 