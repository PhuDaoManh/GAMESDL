#include<sdl.h>
#include<SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include <SDL_image.h>
#include <sdl.h>
#include<SDL_events.h>
#include<iostream>

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

int main(int argc,char* argv[]){
 Graphics graphics;
    graphics.init();

    SDL_Event event;
    int x,y;
    SDL_GetMouseState(&x,&y);
    cerr << x,y;

    SDL_Texture* background = graphics.loadTexture("botbien.jpg");
    graphics.prepareScene(background);
    graphics.presentScene();
    waitUntilKeyPressed();

    SDL_Texture* spongeBob = graphics.loadTexture("botbien2.png");
    graphics.renderTexture(spongeBob, 200, 200);
    graphics.presentScene();
    waitUntilKeyPressed();

    SDL_DestroyTexture( spongeBob );
    spongeBob = NULL;
    SDL_DestroyTexture( background );
    background = NULL;

    graphics.quit();
    return 0;



}
