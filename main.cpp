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
    mouse.x = SCREEN_WIDTH / 2;
    mouse.y = SCREEN_HEIGHT / 2;

    bool quit = false;
    SDL_Event event;
   SDL_Texture* car=graphics.loadTexture("image/car.png");
    SDL_Texture* bk=graphics.loadTexture("image/road.png");

    while (!quit && !gameOver(mouse)) {
        graphics.prepareScene(bk);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP]) mouse.goUp();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) mouse.goDown();
        if (currentKeyStates[SDL_SCANCODE_LEFT]) mouse.turnLeft();
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) mouse.turnRight();

        mouse.move();
        SDL_Rect rect={mouse.x,mouse.y,150,150};
        SDL_RenderCopy(graphics.renderer,car,NULL,&rect);
        graphics.presentScene();
        SDL_Delay(10);
    }

    graphics.quit();
    return 0;
}
