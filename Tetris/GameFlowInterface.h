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
    virtual bool _ThereIsCollision(bool rightDirection) = 0;
	virtual void _ResetShapePtr() = 0;
	virtual bool _IsBottomOrDownShapeCollision() = 0;

	// Set
	virtual void SetDificultyGrade(const unsigned int dificulty) = 0;
	virtual void SetPuntuation(const unsigned int puntuation) = 0;

    const unsigned int SCORE_PER_LEVEL_UNIT = 100;
    const unsigned int DIFFICULTY_UNIT = 200;
    const unsigned int PUNTUATION_UNIT = 1;
    const unsigned int OBJECTIVE = 10;
    const int COORDINATE_ELEMENTS = 2;
    const int X_COORDINATE = 0;
    const int Y_COORDINATE = 1;
};

#endif // !GAME_FLOW_INTERFACE_H 