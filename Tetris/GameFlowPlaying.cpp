#include "GameFlowPlaying.h"
#include "InputHandlerFactory.h"

GameFlowPlaying::GameFlowPlaying()
{
}

GameFlowPlaying::~GameFlowPlaying()
{
}

int GameFlowPlaying::Run()
{
    InputHandlerFactory inpFactory;
    inpHdlInt = inpFactory.GetInputHandler(1);

    while (inpHdlInt->GetInput())
    {
        return -1;
    }
}

void GameFlowPlaying::Pause()
{}

void GameFlowPlaying::Exit()
{}
