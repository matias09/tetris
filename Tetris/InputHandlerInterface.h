#ifndef INPUT_HANDLER_INTERFACE_H
#define INPUT_HANDLER_INTERFACE_H

class InputHandlerInterface
{
public:
    virtual signed int GetInput() = 0;

    enum GAME_KEY_INPUTS {
        KEY_ARROW_UP,
        KEY_ARROW_DOWN,
        KEY_ARROW_RIGHT,
        KEY_ARROW_LEFT,
        KEY_SPACE,
        KEY_ENTER,
        KEY_SCAPE
    };

    enum GAME_EVENT_INPUTS {
        EVENT_EXIT_GAME = -1,
        EVENT_GO_BACK = -2,
        EVENT_INITIALIZE_ERROR = -3
    };
};

#endif // !INPUT_HANDLER_INTERFACE_H
