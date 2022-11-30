//
// Created by l on 11/29/22.
//

#ifndef DRAWBALLS_BALL_H
#define DRAWBALLS_BALL_H

#include<SDL2/SDL.h>

typedef struct
{
    SDL_Rect dest; // 目标区域（图片的区域）
    double angle;//角度
    double rotateSpeed;//旋转速度
}Ball;

Ball* Ball_Create(int x,int y,double speed);

void Ball_Draw(Ball*self,SDL_Renderer* renderer);

void Ball_Destroy(Ball*);
#endif //DRAWBALLS_BALL_H
