#include <stdio.h>
#include "GraphicSdlImp.h"

GraphicSdlImp::GraphicSdlImp()
{
    if (SDL_Init(SDL_INIT_VIDEO) == SDL_GRAPHIC_INITIALIZED)
    {            
        _mIsGraphicEnable = true;
	    CreateWindow();
        _mSquare = new SDL_Rect();
        _mSquare->w = PIXEL_BOARD_WIDTH;
        _mSquare->h = PIXEL_BOARD_HEIGHT;
    }
}

GraphicSdlImp::~GraphicSdlImp()
{
    if (_mIsGraphicEnable == true)
    {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}

bool GraphicSdlImp::IsGraphicSdlEnabled()
{
    return _mIsGraphicEnable;
}

void GraphicSdlImp::Render(bool** matrix, const int columns, const int rows)
{
   int xSeparation = 0;
   int ySeparation = 0;

   printf("\n Drawing board \n ");

   for (int i = 0; i < rows; ++i)
   {
       for (int j = 0; j < columns; ++j)
       {
            _mSquare->x = xSeparation;
            _mSquare->y = ySeparation;
	    
            xSeparation += PIXEL_BOARD_WIDTH + PIXEL_SPACE_BETWEEN;
                
            if (matrix[i][j] == CHANGE_COLOR_MARK)
            {
               SDL_FillRect(_mSurface, _mSquare, SDL_MapRGB(_mSurface->format, 0x00, 0x00, 0xff)); 
            }
            else
            {
               SDL_FillRect(_mSurface, _mSquare, SDL_MapRGB(_mSurface->format, 0x00, 0xff, 0xff)); 
            }
       }

       xSeparation = 0;
       ySeparation += PIXEL_SPACE_BETWEEN + PIXEL_BOARD_WIDTH;
   }

   SDL_UpdateWindowSurface(_mWindow);
}

void GraphicSdlImp::CreateWindow()
{
    _mWindow = SDL_CreateWindow(
        WINDOW_TITLE, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN 
    );

    if (_mWindow == nullptr)
    {
       _mIsGraphicEnable = false;
    }
    else
    {
       _mSurface = SDL_GetWindowSurface(_mWindow);
    }
}
