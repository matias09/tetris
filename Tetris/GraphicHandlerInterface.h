#ifndef GRAPHIC_HANDLER_INTERFACE_H
#define GRAPHIC_HANDLER_INTERFACE_H

class GraphicHandlerInterface
{
public:
    GraphicHandlerInterface();
    virtual ~GraphicHandlerInterface();
    virtual void Render(const bool** matrix);
};

#endif // !GRAPHIC_HANDLER_INTERFACE_H
