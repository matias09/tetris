#ifndef GAME_FLOW_PLAYING_H
#define GAME_FLOW_PLAYING_H

#include "GameFlowInterface.h"
#include "Board.h"
#include "Shape.h"

class GameFlowPlaying : public GameFlowInterface
{
public:
	GameFlowPlaying();
    virtual ~GameFlowPlaying();
    virtual signed int Run(InputHandlerInterface& inpHandler, GraphicHandlerInterface& grpHandler);
    virtual void Pause();
    virtual void Exit();
    virtual bool _ThereIsCollision();
	virtual bool _IsBottomOrDownShapeCollision();

	// Set
	virtual void SetDificultyGrade(const unsigned int dificulty) { _mDificultyGrade = dificulty; }
	virtual void SetPuntuation(const unsigned int puntuation) { _mPuntuation = puntuation; }
private:
	void _ExecuteShapeDown();
	void _ExecuteShapeRight();
	void _ExecuteShapeLeft();
	void _ExecuteShapeRotate();
	virtual void _ResetShapePtr();
    Shape* _GetRandomShape();

    Shape* _mShape;
    Board* _mBoard;
    int _mScore;
    int _mTime;
	unsigned int _mDificultyGrade;
	unsigned int _mPuntuation;
	signed int* _mPosFrom;
	signed int* _mPosTo;
};
#endif
