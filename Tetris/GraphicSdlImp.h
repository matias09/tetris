#ifndef GRAPHIC_SDL_IMP_H
#define GRAPHIC_SDL_IMP_H

#include "GraphicHandlerInterface.h"

class GraphicSdlImp : public GraphicHandlerInterface
{
public:
    GraphicSdlImp();
    ~GraphicSdlImp();
    virtual void Render(const bool** matrix);
};

#endif // !GRAPHIC_SDL_IMP_H

