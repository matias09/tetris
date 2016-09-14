#ifndef GRAPHIC_HANDLER_INTERFACE_H
#define GRAPHIC_HANDLER_INTERFACE_H

class GraphicHandlerInterface
{
public:
    virtual ~GraphicHandlerInterface() {};
    virtual bool IsGraphicSdlEnabled() = 0;
    virtual void Render(bool** matrix, const int columns, const int rows) = 0;
    virtual void CreateWindow() = 0;

    const bool CHANGE_COLOR_MARK = 1;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int PIXEL_BOARD_WIDTH = 15;
    const int PIXEL_BOARD_HEIGHT = 15;
    const int PIXEL_SPACE_BETWEEN = 5;
    const char* WINDOW_TITLE = "Tetris Game";
};

#endif // !GRAPHIC_HANDLER_INTERFACE_H
