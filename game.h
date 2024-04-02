#ifndef _GAME_H
#define _GAME_H
#include "graphics.h"
struct Motion{
   int dx=midlane2x;
   int dy=SCREEN_HEIGHT-100;
   void Handlemove(SDL_Event event,bool &quit){
       if(event.type==SDL_QUIT)
         quit=true;
       else if(event.type==SDL_KEYDOWN){
               switch(event.key.keysym.sym){
                  case SDLK_UP:
                      dy-=carspeed;
                      if(dy<0)
                        dy+=carspeed;
                      break;
                  case SDLK_DOWN:
                      dy+=carspeed;
                      if(dy>SCREEN_HEIGHT-100)
                        dy-=carspeed;
                      break;
                  case SDLK_RIGHT:
                      dx+=move;
                      if(dx>rightlanex)
                        dx-=move;
                      break;
                  case SDLK_LEFT:
                      dx-=move;
                      if(dx<leftlanex)
                        dx+=move;
                       break;
                  }}
}


};
struct Othercar{
   int y;
   int a[4]={midlane1x,rightlanex,leftlanex,midlane2x};
   int x=a[0];
   int speed=Threatspeed;
   SDL_Texture* texture;
   void move(){
         y+=speed;
        if(y>SCREEN_HEIGHT)
        {
            y=-200;
            x=a[rand()%4];
        }
   }
};





#endif // _GAME_H
