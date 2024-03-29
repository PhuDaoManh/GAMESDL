#include<bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    bool quit = false;
    SDL_Event event;

    SDL_Texture* car=graphics.loadTexture("image/car4.png");
    SDL_Texture* bk=graphics.loadTexture("image/road4.jpg");
    SDL_Texture* car2=graphics.loadTexture("image/car2.png");
    Scrollbk background;
    background.setTexture(bk);

    Othercar ocar;
    Othercar ocar2;
    Motion motion;
    while(!quit){
        while(SDL_PollEvent(&event)!=0){
            if(event.type==SDL_QUIT)
             quit=true;
            motion.Handlemove(event);
        }SDL_RenderClear(graphics.renderer);
        background.scroll(10);
        graphics.render(background);
        graphics.rendercar(car,ocar.x,ocar.y);
        ocar.move();
        graphics.rendercar(car2,motion.dx,motion.dy);
        graphics.presentScene();
        SDL_Delay(100);
    }
    SDL_DestroyTexture(background.texture);
    SDL_DestroyTexture(car);
    graphics.quit();
    return 0;
}
