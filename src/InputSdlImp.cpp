#include <stdio.h>

#include "InputSdlImp.h"

#ifndef GRAPHIC_SDL_IMP_H
#include "SDL.h"
#endif // !GRAPHIC_SDL_IMP_H

InputSdlImp::InputSdlImp()
{
  if (SDL_InitSubSystem(SDL_INIT_EVENTS) == SDL_EVENT_INITIALIZED)
    _mIsSdlEventsInitialized = true;
}

InputSdlImp::~InputSdlImp()
{
  if (_mIsSdlEventsInitialized == true)
    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

bool InputSdlImp::IsInputSdlEnabled() { return _mIsSdlEventsInitialized; }

signed int InputSdlImp::GetInput()
{
  unsigned int currentTime = 0;
  unsigned int lastTime = 0;
  signed int entryInput = 0;
  SDL_Event e;

  currentTime = GetTicks();
  while (currentTime > (lastTime + 500))
  {
    while (SDL_PollEvent(&e) != 0)
    {
      if (e.type == SDL_QUIT)
        entryInput = GAME_KEY_INPUTS::KEY_SCAPE;
      else if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
        case SDLK_UP:
          entryInput = GAME_KEY_INPUTS::KEY_ARROW_UP;
          break;
        case SDLK_DOWN:
          entryInput = GAME_KEY_INPUTS::KEY_ARROW_DOWN;
          break;
        case SDLK_LEFT:
          entryInput = GAME_KEY_INPUTS::KEY_ARROW_LEFT;
          break;
        case SDLK_RIGHT:
          entryInput = GAME_KEY_INPUTS::KEY_ARROW_RIGHT;
          break;
        case SDLK_SPACE:
          entryInput = GAME_KEY_INPUTS::KEY_SPACE;
          break;
        case SDLK_RETURN:
          entryInput = GAME_KEY_INPUTS::KEY_ENTER;
          break;
        case SDLK_ESCAPE:
          entryInput = GAME_KEY_INPUTS::KEY_SCAPE;
          break;
        }
      }
    }

    lastTime = currentTime;
  }
  return entryInput;
}

unsigned int InputSdlImp::GetTicks() { return SDL_GetTicks(); }
