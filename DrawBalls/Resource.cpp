//
// Created by l on 11/29/22.
//

#include "Resource.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#define IMG_FILE_NAME "ball.jpg"
SDL_Texture* ballTexture;

int Resource_Load(SDL_Renderer*renderer)
{
    ballTexture=IMG_LoadTexture(renderer,IMG_FILE_NAME);
    if(ballTexture==NULL)
    {
        SDL_Log("Can not log Texture,%s",IMG_GetError());
        return 1;
    }
    return 0;
}

SDL_Texture* Resource_GetBallTexture()
{
    return ballTexture;
}

void Resource_Unload()
{
    SDL_DestroyTexture(ballTexture);
}