#ifndef GRAPHIC_SDL_IMP_H
#define GRAPHIC_SDL_IMP_H

#include "GraphicHandlerInterface.h"

class GraphicSdlImp : public GraphicHandlerInterface
{
public:
    GraphicSdlImp() {};
    virtual ~GraphicSdlImp();
    virtual void Render(const bool** matrix, const int columns, const int rows, const int pixelBoardWith, const int pixelSpaceBetween);
};

#endif // !GRAPHIC_SDL_IMP_H

