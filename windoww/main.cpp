#include <iostream>
#include<SDL2/SDL.h>
int main(){

    SDL_Window *window =NULL;
    SDL_Renderer *render =NULL;
    SDL_Texture * texture =NULL;
    int quit=1;
    SDL_Event event;
    SDL_Rect rect;
    SDL_Init(SDL_INIT_VIDEO) ;

//200,200 显示的位置
//640,680,窗口宽高，
//SDL_WINDOW_SHOWN|SDL_WINDOW_BORDER:窗口标志位
    window =SDL_CreateWindow("window_title",200,200,640,480,SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS);

    if(!window){
        goto __EXIT;
    }

    render  = SDL_CreateRenderer(window,-1,0);//-1,0 暂时不用理解
    if(!render){
        SDL_Log("failed 头 create Render！");
        goto __DWINDOW;
    }



SDL_SetRenderDrawColor(render,255,0,0,255/*透明度，255不退出*/);//换个红色

    SDL_RenderClear(render);//把之前的数据清掉

    SDL_RenderPresent(render);

                              //SDL_Delay(30000);//延时显示30S
                              texture = SDL_CreateTexture(render,SDL_PIXELFORMAT_RGBA8888,
                                                          SDL_TEXTUREACCESS_TARGET,
                                                          640,480);
    if(!texture){
        SDL_Log("failed 头 create Texture!");
        goto __RENDER;
    }

    do{//添加事件监听

        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                quit=0;
                break;
            default:

                SDL_Log("event type is %d",event.type);
        }


        rect.w=30;
        rect.h=30;
        rect.x=rand()%600;
        rect.y=rand()%450;

        //
        SDL_SetRenderTarget(render,texture);//改变渲染的目标是纹理
        SDL_SetRenderDrawColor(render,0,0,0,0);//设置背景颜色
        SDL_RenderClear(render);

        SDL_RenderDrawRect(render,&rect);//画方块
        SDL_SetRenderDrawColor(render,255,0,0,0);//把方块设置成红色
        SDL_RenderFillRect(render,&rect);

                SDL_SetRenderTarget(render,NULL);//把纹理渲染到窗口去，这个时候，恢复成默认的window
        SDL_RenderCopy(render,texture,NULL,NULL);//把纹理交给显卡

        SDL_RenderPresent(render);//显卡计算完，显不显示，由着个函数决定

    }while(quit);

    SDL_DestroyTexture(texture);



    __RENDER:

    __DWINDOW:
    SDL_DestroyWindow(window);//销毁窗口

    __EXIT:
    SDL_Quit() ;
    return 0;

}