#ifndef GRAPHIC_HANDLER_INTERFACE_H
#define GRAPHIC_HANDLER_INTERFACE_H

class GraphicHandlerInterface
{
public:
    virtual ~GraphicHandlerInterface() {};
    virtual void Render(const bool** matrix, const int columns, const int rows, const int pixelBoardWith, const int pixelSpaceBetween) = 0;
};

#endif // !GRAPHIC_HANDLER_INTERFACE_H
