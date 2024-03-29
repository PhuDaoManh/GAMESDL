#ifndef _GAME_H
#define _GAME_H
struct Motion{
   int dx=midlanex+50,dy=SCREEN_HEIGHT-200;
   void Handlemove(SDL_Event event){
       if(event.type==SDL_KEYDOWN){
               switch(event.key.keysym.sym){
                  case SDLK_UP:
                      dy-=carspeed;
                      break;
                  case SDLK_DOWN:
                      dy+=carspeed;
                      break;
                  case SDLK_RIGHT:
                      dx+=carspeed;
                      break;
                  case SDLK_LEFT:
                      dx-=carspeed;
                       break;
                  }
       }else if(event.type==SDL_KEYUP){
                switch(event.key.keysym.sym){
                  case SDLK_UP:
                      dy+=carspeed;
                      break;
                  case SDLK_DOWN:
                      dy-=carspeed;
                      break;
                  case SDLK_RIGHT:
                      dx-=carspeed;
                      break;
                  case SDLK_LEFT:
                      dx+=carspeed;
                       break;
                  }}

   }





};


#endif // _GAME_H
