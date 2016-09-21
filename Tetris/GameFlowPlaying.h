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
    virtual bool _ThereIsCollision(bool rightDirection);
	virtual bool _IsBottomOrDownShapeCollision();

	// Set
	virtual void SetDificultyGrade(const unsigned int dificulty) { _mDificultyGrade = dificulty; }
	virtual void SetPuntuation(const unsigned int puntuation) { _mPuntuation = puntuation; }
private:
	virtual void _ResetShapePtr();
	void _ExecuteShapeDown();
	void _ExecuteShapeRight();
	void _ExecuteShapeLeft();
	void _ExecuteShapeRotate();
	void _CheckRowsFilled();
	void _DownGradeRestOfRows(unsigned int startRow);
    Shape* _GetRandomShape();

    Shape* _mShape;
    Board* _mBoard;
    int _mTime;
    int _mHigestRowMod;
    unsigned int _mScore;
	unsigned int _mDificultyGrade;
	unsigned int _mPuntuation;
	signed int* _mPosFrom;
	signed int* _mPosTo;
};
#endif
