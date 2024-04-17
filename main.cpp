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

    SDL_Texture* bk=graphics.loadTexture("image/road9.jpg");
    SDL_Texture* mycar=graphics.loadTexture("image/car.png");
    SDL_Texture* car3=graphics.loadTexture("image/car3.png");
    SDL_Texture* car5=graphics.loadTexture("image/car5.png");
    SDL_Texture* truck=graphics.loadTexture("image/truck.png");
    Scrollbk background;
    background.setTexture(bk);
    srand(time(NULL));
    Motion motion;

    vector<Othercar> ocar(4);
    ocar[0]={rightlanex,-200,Threatspeed,truck};
    for(int i=1;i<4;i++)
    {
      if(i%2==0)
        ocar[i].x=rand()%2;
      else ocar[i].x=rand()%2+2;
      ocar[i].y=ocar[i-1].y-(rand()%200+200);
    }


    while(!quit)
    {   graphics.prepareScene(bk);

        motion.Mycarmove(quit);

        background.scroll(15);
        graphics.render(background);

        for(int i=0;i<2;i++)
        {
          ocar[i].move(i);
        if(ocar[i].x==motion.x){
            if(ocar[i].y+carsizey>motion.y&&motion.y>ocar[i].y||motion.y+carsizey>ocar[i].y&&ocar[i].y>motion.y)
            { ocar[i].y=-300;
              ocar[i].x=midlane1x;
            cout << "may ngu hon con cho nha tao";
            SDL_Delay(1000);}
;
        } graphics.renderTexture(ocar[i].texture,ocar[i].x,ocar[i].y);    }
        graphics.renderTexture(mycar,motion.x,motion.y);
        graphics.presentScene();
        SDL_Delay(100);
    }

    SDL_DestroyTexture(background.texture);
    SDL_DestroyTexture(ocar[0].texture);
    graphics.quit();
    return 0;
}
