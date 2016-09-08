#include "GameController.h"

int main(int argc, char** args)
{
    int gameCode = 0;
    GameController* gmController = new GameController();
    gameCode = gmController->Run();
    return gameCode;
}