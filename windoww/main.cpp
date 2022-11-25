#include"bits/stdc++.h"
#include"SDL2/SDL.h"
#define WIDTH 400
#define HEIGHT 300

int x=0;
int y=0;


void draw(SDL_Window *win,SDL_Surface*screen)
{
    x++;//窗口x坐标移动
    y++;//窗口y坐标移动
    SDL_Rect r={0,0,WIDTH,HEIGHT};
    SDL_Rect t={x,y,100,100};
    SDL_FillRect(screen,&r,0xffffffff);//32位无符号整数 ARGB:透明度，红，绿，蓝
    SDL_FillRect(screen,&t,0xffff0000);
    SDL_UpdateWindowSurface(win);
}
void event_loop(SDL_Window* win,SDL_Surface* screen)
{
    while(1)//无限循环一个事件
    {
        draw(win,screen);
        SDL_Event event;//事件的定义
        if(SDL_PollEvent(&event)) {
            if(event.type==SDL_QUIT)//点击删除命令后退出
                break;
            //printf("event type: %d\n", event.type);
        }
        SDL_Delay(50);//创造一个延迟 每秒20帧
    }
    return;
}
int main()
{
      if(SDL_Init(SDL_INIT_AUDIO))
      {
          SDL_Log("Init error,%s",SDL_GetError());
          return 1;
      }
      SDL_Window *win= SDL_CreateWindow("title",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        WIDTH,HEIGHT,
                                        SDL_WINDOW_SHOWN);//初始化一个窗口
      if(win==NULL) {
          SDL_Log("cant open window", SDL_GetError());
          return 1;
      }
      SDL_Surface* screen= SDL_GetWindowSurface(win);
     event_loop(win,screen);
    SDL_DestroyWindow(win);
      return 0;

}
