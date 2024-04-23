#ifndef _GAME_H
#define _GAME_H
#include "graphics.h"
struct Mycar
{
   int x=midlane2x;
   int y=SCREEN_HEIGHT-100;
   SDL_Event event;
   Motion(){}
   void Mouse();
   void Mycarmove(bool &quit);
};

struct Othercar
{
   int x,y;
   int speed=Threatspeed;
   SDL_Texture* texture;
   Othercar(){}
   int a[4]={leftlanex,midlane1x,midlane2x,rightlanex};
   void move(int i);
};

bool checkCollision(int x1,int y1,int x2,int y2);


#endif // _GAME_H
