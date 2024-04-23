#include<bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "game.h"

using namespace std;

   void Mycar::Mycarmove(bool &quit)
   { while(SDL_PollEvent(&event)!=0){
       if(event.type==SDL_QUIT)
         quit=true;
       else if(event.type==SDL_KEYDOWN)
        {
         switch(event.key.keysym.sym)
         {
            case SDLK_UP:
                y-=carspeed;
                if(y<0)
                y+=carspeed;
                break;
            case SDLK_DOWN:
                 y+=carspeed;
                 if(y>SCREEN_HEIGHT-100)
                 y-=carspeed;
                 break;
            case SDLK_RIGHT:
                x+=lanesize;
                if(x>rightlanex)
                x-=lanesize;
                break;
            case SDLK_LEFT:
                x-=lanesize;
                if(x<leftlanex)
                x+=lanesize;
                break;
          }
        }
        else if(event.type==SDL_MOUSEBUTTONDOWN)
        {   int x,y;
            SDL_GetMouseState(&x,&y);
            cout << x << y;
        }
   }
   }
   void Othercar::move(int i)
   {    y+=speed;
        if(y>SCREEN_HEIGHT)
        {   y=-200;
            if(i==0)
              x=a[rand()%2];
            else x=a[rand()%2+2];

        }
   }


bool checkCollision(int x1,int y1,int x2,int y2)
{
        if(x1==x2){
            if(y1+carsizey>y2&&y2>y1||y2+carsizey>y1&&y1>y2)
               return true;
        }
return false;
}


