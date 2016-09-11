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

    enum GAME_STATES {
        EXIT_GAME = -1,
        PRESENTATION,
        MAIN_MENU,
        IN_GAME
    };

    int _mActualState = 0;
    InputHandlerInterface* _mInputHandler;
    GraphicHandlerInterface* _mGraphicHandler;
    GameFlowInterface* _mGameFlow;
};
#endif //GAME_CONTROLLER_H
