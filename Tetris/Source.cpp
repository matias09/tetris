#include "GameController.h"

int main(int argc, char** args)
{
    int gameCode = 0;
    GameController* gmController = new GameController();

    if (gmController != nullptr)
    {
        if (gmController->ThereIsAnyToolError() != false)
        {
            gameCode = gmController->Run();
            delete gmController;
            gmController = nullptr;
        }
    }

    return gameCode;
}