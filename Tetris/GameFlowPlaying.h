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
	void SetDificultyGrade(const unsigned int dificulty) { _mDificultyGrade = dificulty; }
	void SetPuntuation(const unsigned int puntuation) { _mPuntuation = puntuation; }
	void SetScore(const unsigned int score) { _mScore = score; }
	void SetThereIsLateralCollision(const bool thereIsCollision) { _mThereIsLateralCollision = thereIsCollision; }
	void SetThereIsBottomCollision(const bool thereIsCollision) { _mThereIsBottomCollision = thereIsCollision; }
private:
	void _ResetShapePtr();
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
    const unsigned int CONSTANT_DIFICULTY = 50;
    const unsigned int DIFFICULTY_UNIT = 100;
    const unsigned int PUNTUATION_UNIT = 1;
    const unsigned int OBJECTIVE = 5;
    const unsigned short int COORDINATE_ELEMENTS = 2;
    const unsigned short int X_COORDINATE = 0;
    const unsigned short int Y_COORDINATE = 1;

    Shape* _mShape;
    Board* _mBoard;
    bool _mThereIsLateralCollision;
    bool _mThereIsBottomCollision;
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
