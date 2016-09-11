#ifndef INPUT_HANDLER_INTERFACE_H
#define INPUT_HANDLER_INTERFACE_H

class InputHandlerInterface
{
public:
    virtual ~InputHandlerInterface() {};
    virtual signed int GetInput() = 0;

    enum GAME_KEY_INPUTS {
        KEY_ARROW_UP = 0,
        KEY_ARROW_DOWN,
        KEY_ARROW_RIGHT,
        KEY_ARROW_LEFT,
        KEY_SPACE,
        KEY_ENTER,
        KEY_SCAPE
    };
};

#endif // !INPUT_HANDLER_INTERFACE_H
