#include <stdio.h>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PIXEL_BOARD_WIDTH = 15;
const int PIXEL_BOARD_HEIGHT = 15;
const int PIXEL_SPACE_BETWEEN = 5;
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int FIGURE_DIMENSION = 2;
const int CHANGE_COLOR = 1;

//comment added

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;
SDL_Rect* board[BOARD_HEIGHT][BOARD_WIDTH];

bool init();
bool loadMedia();
SDL_Surface* loadImage(const char* path);
void freeResource();
void updateBoard(const int** figure);
int** getSquare();

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL_ErrorMsg: %s\n ", SDL_GetError());
        success = false;
    }
    else
    {
        window = SDL_CreateWindow("El Sr Titulo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == NULL)
        {
            printf("SDL_ErrorMgs: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            screenSurface = SDL_GetWindowSurface(window);
        }
    }

    return success;
}

//Function Not Used For now. Only returns True
bool loadMedia()
{
    return true;
}

SDL_Surface* loadImage(const char* path)
{
    SDL_Surface* imgSurface = SDL_LoadBMP(path);

    if (imgSurface == NULL)
    {
        printf("Was not possible load the image \"%s\" \n SDL_ErrorMsg: %s\n", path, SDL_GetError());
    }

    return imgSurface;
}

void freeResource()
{
    SDL_FreeSurface(screenSurface);
    screenSurface = nullptr;

    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
}

void createBoard()
{
    int xSeparation = 0;
    int ySeparation = 0;
    for (int i = 0; i < BOARD_HEIGHT; ++i)
    {
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            SDL_Rect* pixelBoard = new SDL_Rect();
            pixelBoard->h = PIXEL_BOARD_HEIGHT;
            pixelBoard->w = PIXEL_BOARD_WIDTH;

            pixelBoard->x = xSeparation;
            pixelBoard->y = ySeparation;

            xSeparation += PIXEL_SPACE_BETWEEN + PIXEL_BOARD_WIDTH;

            SDL_FillRect(screenSurface, pixelBoard, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0xFF));

            board[i][j] = pixelBoard;
        }
        xSeparation = 0;
        ySeparation += PIXEL_SPACE_BETWEEN + PIXEL_BOARD_WIDTH;
    }
}

void updateBoard(int** figure)
{
    for (int i = 0; i < FIGURE_DIMENSION; ++i)
    {
        for (int j = 0; j < FIGURE_DIMENSION; ++j)
        {
            if (figure[i][j] == CHANGE_COLOR)
            {
                SDL_FillRect(screenSurface, board[i][j], SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0xFF));
            }
            else
            {
                SDL_FillRect(screenSurface, board[i][j], SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0xFF));
            }
        }
    }
}

int** getSquare()
{
    int** figure = new int*[FIGURE_DIMENSION];
    figure[0] = new int[FIGURE_DIMENSION];
    figure[1] = new int[FIGURE_DIMENSION];
    figure[0][0] = 1;
    figure[0][1] = 1;
    figure[1][0] = 1;
    figure[1][1] = 1;

    return figure;
}

int** getDefault()
{
    int** figure = new int*[FIGURE_DIMENSION];
    figure[0] = new int[FIGURE_DIMENSION];
    figure[1] = new int[FIGURE_DIMENSION];
    figure[0][0] = 0;
    figure[0][1] = 0;
    figure[1][0] = 0;
    figure[1][1] = 0;

    return figure;
}

int main(int argc, char* args[])
{
    if (!init())
    {
        printf("SDL Could not Start... \n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Media Files Could Not been Loaded... \n");
        }
        else
        {
            bool userQuit = false;
            SDL_Event e;
            createBoard();

            while (!userQuit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        userQuit = true;
                    }
                    else if (e.type == SDL_KEYDOWN)
                    {
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_w:
                        case SDLK_UP:
                            printf("The w or UP arrow key were pressed \n");
                            updateBoard(getSquare());
                            break;
                        case SDLK_s:
                        case SDLK_DOWN:
                            printf("The s or DOWN arrow key were pressed \n");
                            updateBoard(getSquare());
                            break;
                        case SDLK_a:
                        case SDLK_LEFT:
                            printf("The a or LEFT arrow key were pressed \n");
                            updateBoard(getDefault());
                            break;
                        case SDLK_d:
                        case SDLK_RIGHT:
                            printf("The d or RIGHT arrow key were pressed \n");
                            updateBoard(getDefault());
                            break;
                        case SDLK_ESCAPE:
                            printf("The ESCAPE key were pressed \n");
                            userQuit = true;
                            break;
                        }
                    }
                }

                SDL_UpdateWindowSurface(window);
            }
        }
    }

    freeResource();
    return 0;
}