//
// Created by l on 11/29/22.
//

#include"Ball.h"
#include"Resource.h"

Ball* Ball_Create(int x,int y,double speed)
{
    Ball* b=(Ball*)malloc(sizeof(Ball));
    b->dest.x=x;
    b->dest.y=y;
    b->dest.w=30;
    b->dest.h=30;
    b->angle=0;
    b->rotateSpeed=speed;
    return b;

}

void Ball_Draw(Ball* self,SDL_Renderer* renderer)
{
    self->angle+=self->rotateSpeed;
    SDL_RenderCopyEx(
                            renderer,
                     Resource_GetBallTexture(),
                     NULL,
                     &(self->dest),
                     self->angle,
                     NULL,
                     SDL_FLIP_NONE
    );//打印小球
}



void Ball_Destroy(Ball* b)
{
    free(b);
}