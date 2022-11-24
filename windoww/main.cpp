#include"bits/stdc++.h"
#include"SDL2/SDL.h"
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
                                        300,400,SDL_WINDOW_SHOWN);
      if(win==NULL)
      {
          SDL_Log("cant open window",SDL_GetError());
          return 1;
      }
      SDL_Delay(3000);
    SDL_DestroyWindow(win);
      return 0;

}
