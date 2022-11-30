#include"bits/stdc++.h"
#include"SDL2/SDL.h"
#include"SDL2/SDL_image.h"
#include"SDL2/SDL_ttf.h"
#define WIDTH 600
#define HEIGHT 800
#define FRAMERATE 60//固定帧数
#define FONT_SIZE 32


int x=0;
int y=0;

SDL_Surface *img,*screen;
TTF_Font * font;


void draw(SDL_Window *win,SDL_Surface*screen)
{
    //x++;//窗口x坐标移动
    //y++;//窗口y坐标移动
    //SDL_Rect r={0,0,WIDTH,HEIGHT};
    //SDL_Rect t={x,y,100,100};
    //SDL_FillRect(screen,&r,0xffffffff);//32位无符号整数 ARGB:透明度，红，绿，蓝
    //SDL_FillRect(screen,&t,0xffff0000);
     SDL_Color color={0,255,255,255};
    SDL_Surface *text=TTF_RenderUTF8_Blended(font,"https://sjxm0721.com",color);
    SDL_Rect src={0,0,text->w,text->h};
    SDL_BlitSurface(text,&src,screen,&src);
    SDL_FreeSurface(text);
    SDL_UpdateWindowSurface(win);
}
void event_loop(SDL_Window* win,SDL_Surface* screen)
{
    while(1)//无限循环一个事件
    {
        long begin=SDL_GetTicks();
        draw(win,screen);
        SDL_Event event;//事件的定义
        while(SDL_PollEvent(&event)) {//一直处理到事件为空
            if(event.type==SDL_QUIT)//点击删除命令后退出
                return;
            //printf("event type: %d\n", event.type);
        }
        long current=SDL_GetTicks();
        long cost=current-begin;
        long need=1000/FRAMERATE;
        if(need>cost) {
            //SDL_Delay(need-cost);//创造一个延迟 每秒20帧
        }
    }
    return;
}
int main()
{
    if(TTF_Init())
    {
        SDL_Log("Can not init ttf,%s",TTF_GetError());
    }
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
      //img=IMG_Load("sjxm.jpg");
      font= TTF_OpenFont("ani.ttf",FONT_SIZE);
      if(font==NULL)
      {
          SDL_Log("Can not open font");
          return 1;
      }
      screen= SDL_GetWindowSurface(win);
     event_loop(win,screen);
    //SDL_FreeSurface(img);
    TTF_CloseFont(font);
    SDL_DestroyWindow(win);
      return 0;

}
