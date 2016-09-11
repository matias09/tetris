#include "GameController.h"

int main(int argc, char** args)
{
    int gameCode = 0;
    GameController* gmController = nullptr;
    gmController = new GameController(); 

    if (gmController != nullptr)
    {
        gameCode = gmController->Run();
        delete gmController;
        gmController = nullptr;
    }

    return gameCode;
}