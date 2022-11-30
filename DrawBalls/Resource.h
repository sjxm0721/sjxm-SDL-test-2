//
// Created by l on 11/29/22.
//

#ifndef DRAWBALLS_RESOURCE_H
#define DRAWBALLS_RESOURCE_H


#include"SDL2/SDL.h"

int Resource_Load(SDL_Renderer*);
SDL_Texture* Resource_GetBallTexture();
void Resource_Unload();


#endif //DRAWBALLS_RESOURCE_H
