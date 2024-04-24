#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include<SDL_mixer.h>
#include"defs.h"


struct Scrollbk
{
    SDL_Texture* texture;

    int sc = 0;
    int width, height;
    Scrollbk(){}
    void setTexture(SDL_Texture* _texture);
    void scroll(int distance) ;

};

struct Graphics{
    SDL_Renderer *renderer;
    SDL_Window *window;

    Graphics(){}

    void renderMenu();
    void loadImageandSound();
    void logErrorAndExit(const char* msg, const char* error);
    void init();
    void prepareScene(SDL_Texture * background);
    void presentScene();
    SDL_Texture *loadTexture(const char *filename);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void render(const Scrollbk& background);
    void quit();
};
#endif _GRAPHICS__H


