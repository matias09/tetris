#ifndef GAME_FLOW_PLAYING
#define GAME_FLOW_PLAYING

#include "GameFlowInterface.h"

class GameFlowPlaying : public GameFlowInterface
{
public:
    GameFlowPlaying();
    ~GameFlowPlaying();
    virtual int Run() = 0;
    virtual void Pause() = 0;
    virtual void Exit() = 0;
};
#endif