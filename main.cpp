#include<sdl.h>
#include<SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include<SDL_events.h>
#include<bits/stdc++.h>
#include "logic.h"

using namespace std;
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&(e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
void processClick(int x,int y,Tictactoe &game){
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;

    game.move(clickedCol,clickedRow);
}

int main(int argc,char* argv[]){
 Graphics graphics;
  graphics.init();

 Tictactoe game;
  game.init();
  graphics.render(game);

  SDL_Event event;
  bool quit=false;
  int x,y;

  while(!quit){
    SDL_PollEvent(&event);
    if(event.type==SDL_QUIT)
        quit=true;
    else if(event.type==SDL_MOUSEBUTTONDOWN){
        SDL_GetMouseState(&x,&y);
        processClick(x,y,game);
        graphics.render(game);
        cerr << x << y;}
  }


graphics.quit();
return 0;

}

