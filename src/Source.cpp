#include "GameController.h"

int main(int argc, char** args)
{
  int stateCode = 0;
  GameController* gmController = new GameController();

  if (gmController != nullptr) {
    if (gmController->ThereIsAnyToolError() != false) {
      stateCode = gmController->Run();

      delete gmController;
      gmController = nullptr;
    }
  }

  return stateCode;
}
