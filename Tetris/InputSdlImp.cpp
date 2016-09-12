#include <stdio.h>

#include "InputSdlImp.h"
#include "SDL.h"

InputSdlImp::InputSdlImp()
{
    // TODO :: Sacar este hardcodeo HORROROSO
    // TODO :: Inicializar SDL en algun lugar mas
    // inteligente
    SDL_Init(0);
    // TODO :: Inicializar Events y no el video.
    // hacer la llamada del video cuando llamamos a la
    // implementacion de la parte grafica.
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) == SDL_EVENT_INITIALIZED)
    {
        _mIsSdlEventsInitialized = true;
    // TODO :: Sacar este hardcodeo HORROROSO
        SDL_CreateWindow("El Sr Titulo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    }
}

InputSdlImp::~InputSdlImp()
{
    if (_mIsSdlEventsInitialized == true)
    {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}

bool InputSdlImp::IsInputSdlEnabled()
{
    return _mIsSdlEventsInitialized;
}

signed int InputSdlImp::GetInput()
{
    signed int entryInput = 0;
    SDL_Event e;
    while (entryInput != GAME_KEY_INPUTS::KEY_SCAPE)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                entryInput = GAME_KEY_INPUTS::KEY_SCAPE;
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
                case SDLK_SPACE:
                    printf("The SPACE_BAR arrow key were pressed \n");
                    entryInput = GAME_KEY_INPUTS::KEY_SPACE;
                    break;
                case SDLK_RETURN:
                    printf("The RETURN arrow key were pressed \n");
                    entryInput = GAME_KEY_INPUTS::KEY_ENTER;
                    break;
                case SDLK_ESCAPE:
                    printf("The ESCAPE key were pressed \n");
                    entryInput = GAME_KEY_INPUTS::KEY_SCAPE;
                    break;
                }
            }
        }
    }
    return entryInput;
}
