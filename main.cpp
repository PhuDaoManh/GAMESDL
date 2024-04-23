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
    SDL_Texture* shit=graphics.loadTexture("image/shit.png");


    Scrollbk background;
    background.setTexture(bk);
    srand(time(NULL));

    Mycar motion;
    int a[4]={leftlanex,midlane1x,midlane2x,rightlanex};
   vector<Othercar> ocar(5);
    ocar[0].x=rightlanex;
    ocar[0].texture=car5;
    ocar[0].y=-200;
    ocar[1].texture=car3;
    ocar[2].texture=car5;
    ocar[3].texture=car3;
    ocar[4].texture=truck;
    for(int i=1;i<5;i++)
    {
      if(i%2==0)
        ocar[i].x=a[rand()%2];
      else ocar[i].x=a[rand()%2+2];
      ocar[i].y=ocar[i-1].y-300;
    }
    while(!quit)
    {

        graphics.prepareScene(bk);
        motion.Mycarmove(quit);

        background.scroll(15);
        graphics.render(background);
        for(int i=0;i<5;i++)
        {
          ocar[i].move(i);
          if(checkCollision(ocar[i].x,ocar[i].y,motion.x,motion.y))
          {
            ocar[i].y=-200;
            exit(0);
          }

        graphics.renderTexture(ocar[i].texture,ocar[i].x,ocar[i].y);}
        graphics.renderTexture(mycar,motion.x,motion.y);
        graphics.presentScene();

        SDL_Delay(100);
    }

    SDL_DestroyTexture(background.texture);
    for(int i=0;i<5;i++){
    SDL_DestroyTexture(ocar[i].texture);}
    graphics.quit();
    return 0;
}
