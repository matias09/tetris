#include "GraphicSdlImp.h"
#include "SDL.h"

GraphicSdlImp::GraphicSdlImp()
{
    if (SDL_Init(SDL_INIT_VIDEO) == SDL_GRAPHIC_INITIALIZED)
    {            
        _mIsGraphicEnable = true;
    }
}

GraphicSdlImp::~GraphicSdlImp()
{
    if (_mIsGraphicEnable == true)
    {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}

bool GraphicSdlImp::IsGraphicSdlEnabled()
{
    return _mIsGraphicEnable;
}

void GraphicSdlImp::Render(bool** matrix, const int columns, const int rows, const int pixelBoardWith, const int pixelSpaceBetween)
{

}
