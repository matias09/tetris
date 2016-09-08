#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "GameFlow.h"

class GameController
{
public:
    GameController();
    ~GameController();
    void ChangeState(const int state);
private:
    enum GAME_STATES {
        PRESENTATION,
        MAIN_MENU,
        IN_GAME
    };

    int _mActualState = 0;
};
#endif //GAME_CONTROLLER_H
