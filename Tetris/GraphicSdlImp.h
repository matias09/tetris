#ifndef GRAPHIC_SDL_IMP_H
#define GRAPHIC_SDL_IMP_H

#include "GraphicHandlerInterface.h"
#include "SDL.h"

class GraphicSdlImp : public GraphicHandlerInterface
{
public:
    GraphicSdlImp();
    virtual ~GraphicSdlImp();
    virtual bool IsGraphicSdlEnabled();
    virtual void Render(bool** matrix, const int columns, const int rows, int colorMod = 0);
    virtual void CreateWindow();
private:
    const int SDL_GRAPHIC_INITIALIZED = 0;

    bool _mIsGraphicEnable = false;
    SDL_Window* _mWindow = nullptr;
    SDL_Surface* _mSurface = nullptr;
    SDL_Rect* _mSquare = nullptr;
};

#endif // !GRAPHIC_SDL_IMP_H

