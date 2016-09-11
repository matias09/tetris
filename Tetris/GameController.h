#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

// Handlers
#include "InputHandlerInterface.h"
#include "GraphicHandlerInterface.h"

// Game Flows
#include "GameFlowInterface.h"

class GameController
{
public:
    GameController();
    ~GameController();
    int Run();
private: 
    int _mActualState = 0;
    InputHandlerInterface* _mInputHandler;
    GraphicHandlerInterface* _mGraphicHandler;
    GameFlowInterface* _mGameFlow;
};
#endif //GAME_CONTROLLER_H
