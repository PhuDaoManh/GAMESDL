#include <iostream>
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

    motion mouse;
    mouse.x = (SCREEN_WIDTH / 2)-70;
    mouse.y = (SCREEN_HEIGHT / 2)-70;

    bool quit = false;
    SDL_Event event;
   SDL_Texture* car=graphics.loadTexture("image/car.png");
    SDL_Texture* bk=graphics.loadTexture("image/botbien.jpg");
    while (!quit && !gameOver(mouse)) {
        graphics.prepareScene(bk);
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) quit = true;
            else if(event.type == SDL_KEYDOWN){
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP]) mouse.goUp();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) mouse.goDown();
        if (currentKeyStates[SDL_SCANCODE_LEFT]) mouse.turnLeft();
       if (currentKeyStates[SDL_SCANCODE_RIGHT]) mouse.turnRight();
        mouse.move();}
           else if(event.type==SDL_KEYUP){
              switch(event.key.keysym.sym){
                        case SDLK_UP:
                        case SDLK_DOWN:
                            mouse.dy = 0;
                            break;
                        case SDLK_LEFT:
                        case SDLK_RIGHT:
                            mouse.dx = 0;
                            break;

                 }
           }}
        SDL_Rect rect={mouse.x,mouse.y,100,100};
        SDL_RenderCopy(graphics.renderer,car,NULL,&rect);
        graphics.presentScene();
        SDL_Delay(10);
    }

    graphics.quit();
    return 0;
}
