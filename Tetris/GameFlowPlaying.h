#ifndef GAME_FLOW_PLAYING_H
#define GAME_FLOW_PLAYING_H

#include "GameFlowInterface.h"
#include "Board.h"
#include "Shape.h"

class GameFlowPlaying : public GameFlowInterface
{
public:
    GameFlowPlaying() {};
    virtual ~GameFlowPlaying() {};
    virtual signed int Run(InputHandlerInterface& inpHandler, GraphicHandlerInterface& grpHandler);
    virtual void Pause();
    virtual void Exit();
private:
    int _mScore;
    int _mTime;
    Board* _mBoard;
    Shape* _mShape;
};
#endif