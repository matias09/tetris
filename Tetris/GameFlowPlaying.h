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

	// Set
	virtual void SetDificultyGrade(const unsigned int dificulty) { _mDificultyGrade = dificulty; }
	virtual void SetPuntuation(const unsigned int puntuation) { _mPuntuation = puntuation; }
private:
	virtual void _ResetShapePtr();
    bool _ThereIsCollision(bool rightDirection);
	bool _IsBottomOrDownShapeCollision();
	void _ExecuteShapeDown();
	void _ExecuteShapeRight();
	void _ExecuteShapeLeft();
	void _ExecuteShapeRotate();
	void _CheckRowsFilled();
	void _DownGradeRestOfRows(unsigned int startRow);
	void _RotateShape();
	void _CalculateNewXYPosition();
    Shape* _GetRandomShape();

    const unsigned int SCORE_PER_LEVEL_UNIT = 100;
    const unsigned int DIFFICULTY_UNIT = 200;
    const unsigned int PUNTUATION_UNIT = 1;
    const unsigned int OBJECTIVE = 10;
    const unsigned short int COORDINATE_ELEMENTS = 2;
    const unsigned short int X_COORDINATE = 0;
    const unsigned short int Y_COORDINATE = 1;

    Shape* _mShape;
    Board* _mBoard;
    int _mTime;
    int _mHigestRowMod;
    unsigned int _mScore;
	unsigned int _mDificultyGrade;
	unsigned int _mPuntuation;
	unsigned short int actShpRot;
	signed int* _mPosFrom;
	signed int* _mPosTo;
};

#endif // GAME_FLOW_PLAYING_H
