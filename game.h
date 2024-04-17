#ifndef _GAME_H
#define _GAME_H
#include "graphics.h"
struct Motion
{
   int x=midlane2x;
   int y=SCREEN_HEIGHT-100;
   SDL_Event event;
   void Mycarmove(bool &quit)
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
   }
   }
};
 int a[4]={leftlanex,midlane1x,midlane2x,rightlanex};
struct Othercar
{
   int x,y;
   int speed=Threatspeed;
   SDL_Texture* texture;
   void move(int i)
   {    y+=speed;
        if(y>SCREEN_HEIGHT)
        {   y=-200;
            if(i==0)
              x=a[rand()%2];
            else x=a[rand()%2+2];

        }
   }
};






#endif // _GAME_H
