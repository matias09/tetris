#ifndef GRAPHIC_SDL_IMP_H
#define GRAPHIC_SDL_IMP_H

#include "GraphicHandlerInterface.h"

class GraphicSdlImp : public GraphicHandlerInterface
{
public:
    GraphicSdlImp();
    virtual ~GraphicSdlImp();
    virtual bool IsGraphicSdlEnabled();
    virtual void Render(bool** matrix, const int columns, const int rows, const int pixelBoardWith, const int pixelSpaceBetween);
private:
    const int SDL_GRAPHIC_INITIALIZED = 0;

    bool _mIsGraphicEnable = false;
};

#endif // !GRAPHIC_SDL_IMP_H

