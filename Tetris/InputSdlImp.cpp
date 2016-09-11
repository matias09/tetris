#include <stdio.h>

#include "InputSdlImp.h"
#include "GameEvents.h"
#include "SDL.h"

InputSdlImp::~InputSdlImp()
{
    if (_mIsSdlEventsInitialized == true)
    {
        SDL_QuitSubSystem(SDL_INIT_EVENTS);
    }
}

signed int InputSdlImp::GetInput()
{
    signed int entryInput = 0;
    if (SDL_InitSubSystem(SDL_INIT_EVENTS) == SDL_EVENT_INITIALIZED)
    {
        _mIsSdlEventsInitialized = true;
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                entryInput = GAME_EVENTS::EXIT_GAME_SUCCEFULLY;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    printf("The UP arrow key were pressed \n");
                    entryInput = GAME_KEY_INPUTS::KEY_ARROW_UP;
                    break;
                case SDLK_DOWN:
                    printf("The DOWN arrow key were pressed \n");
                    entryInput = GAME_KEY_INPUTS::KEY_ARROW_DOWN;
                    break;
                case SDLK_LEFT:
                    printf("The LEFT arrow key were pressed \n");
                    entryInput = GAME_KEY_INPUTS::KEY_ARROW_LEFT;
                    break;
                case SDLK_RIGHT:
                    printf("The RIGHT arrow key were pressed \n");
                    entryInput = GAME_KEY_INPUTS::KEY_ARROW_RIGHT;
                    break;
                case SDLK_ESCAPE:
                    printf("The ESCAPE key were pressed \n");
                    entryInput = GAME_EVENTS::GO_BACK;
                    break;
                }
            }
        }
    }
    else
    {
        entryInput = GAME_EVENTS::EXIT_GAME_WITH_ERROR;
    }

    return entryInput;
}
