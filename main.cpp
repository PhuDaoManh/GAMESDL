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

    SDL_Texture* bk=graphics.loadTexture("image/road9.jpg");
    SDL_Texture* mycar=graphics.loadTexture("image/car.png");
    SDL_Texture* car3=graphics.loadTexture("image/car3.png");
    Scrollbk background;
    background.setTexture(bk);
    srand(time(NULL));
    Motion motion;

    vector<Othercar> other(5);
    other[0].y=-400;
    other[0].texture=car3;
    for(int i=1;i<5;i++)
    {  other[i].y=other[i-1].y-(rand()%200+201);
       other[i].texture=car3;
    }
    while(!quit)
    {
        while(SDL_PollEvent(&event)!=0)
        {
          motion.Handlemove(event,quit);
        }
        SDL_RenderClear(graphics.renderer);

        background.scroll(15);
        graphics.render(background);
        graphics.renderTexture(mycar,motion.dx,motion.dy);
        for(int i=0;i<5;i++){
            graphics.renderTexture(other[i].texture,other[i].x,other[i].y);
            other[i].move();
         if(motion.dx==other[i].x&&motion.dy>other[i].y&&motion.dy<other[i].y+carsizey)
          cout << "Oh no you touch other car"<<endl;
       }


        graphics.presentScene();
        SDL_Delay(100);
    }

    SDL_DestroyTexture(background.texture);
    graphics.quit();
    return 0;
}
