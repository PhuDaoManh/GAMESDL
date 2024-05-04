
#include "graphics.h"
using namespace std;

void Graphics::loadMedia()
{
    pic.push_back( loadTexture("assets/image/car.png"));
    pic.push_back( loadTexture("assets/image/car2.png"));
    pic.push_back( loadTexture("assets/image/car3.png"));
    pic.push_back(loadTexture("assets/image/car4.png"));
    pic.push_back( loadTexture("assets/image/car5.png"));
    pic.push_back( loadTexture("assets/image/road9.jpg"));
    pic.push_back(loadTexture("assets/image/menu.png"));
    pic.push_back(loadTexture("assets/image/heart.png"));
    pic.push_back(loadTexture("assets/image/playbutton.png"));
    pic.push_back(loadTexture("assets/image/unselectplay.png"));
    pic.push_back(loadTexture("assets/image/exitbutton.png"));
    pic.push_back(loadTexture("assets/image/unselectexit.png"));
    pic.push_back(loadTexture("assets/image/title.png"));
    pic.push_back(loadTexture("assets/image/gameover.jpg"));
    pic.push_back(loadTexture("assets/image/big-explosion.png"));
    pic.push_back(loadTexture("assets/image/shield1.png"));
    pic.push_back(loadTexture("assets/image/yes.png"));
    pic.push_back(loadTexture("assets/image/no.png"));

    font=loadFont("assets/font/DroidSans.ttf",18);

    music.push_back(loadMusic("assets/sound/menu.mp3"));
    music.push_back(loadMusic("assets/sound/start.mp3"));

    sound.push_back(loadSound("assets/sound/gamestart.mp3"));
    sound.push_back(loadSound("assets/sound/gameOver.mp3"));
    sound.push_back(loadSound("assets/sound/crash.mp3"));
    sound.push_back(loadSound("assets/sound/gain.mp3"));
}

void Scrollbk::setTexture(SDL_Texture* _texture)
{
        texture = _texture;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void Scrollbk::scroll(int distance)
{
        sc += distance;
        if( sc >height ) {sc = 0;}
}


void Graphics::logErrorAndExit(const char* msg, const char* error)
{
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,"%s: %s", msg, error);
        SDL_Quit();
}

void Graphics::init()
{
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if (window == nullptr)
                   logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

        if (renderer == nullptr)
             logErrorAndExit("CreateRenderer", SDL_GetError());

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
                  logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n",
                    Mix_GetError() );
        }
        if (TTF_Init() == -1)
        {
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ",
                             TTF_GetError());
        }

        loadMedia();

}
void Graphics::prepareScene()
   {
      SDL_RenderClear(renderer);
   }

void Graphics::presentScene()
{
        SDL_RenderPresent(renderer);
}

SDL_Texture* Graphics::loadTexture(const char *filename)
{
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,"Loading %s", filename);
        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());
        return texture;
}

void Graphics::renderTexture(SDL_Texture *texture, int x, int y)
{
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        SDL_RenderCopy(renderer, texture, NULL, &dest);
}
void Graphics::renderTexture(SDL_Texture *texture, int x, int y,int w,int h)
{
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        dest.w = w;
        dest.h = h;

        SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Graphics::render(const Scrollbk& background)
{
     renderTexture(background.texture,0,background.sc);
     renderTexture(background.texture,0, background.sc - background.height);
}

Mix_Music* Graphics::loadMusic(const char* path)
{
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr)
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,"Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
}
void Graphics::play(Mix_Music *gMusic)
{
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0)
        {
            Mix_PlayMusic( gMusic, -1 );
        }
}

Mix_Chunk* Graphics::loadSound(const char* path)
{
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr)
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,"Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
return gChunk;
}

void Graphics::play(Mix_Chunk* gChunk)
{
        if (gChunk != nullptr)
        {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
}
 void Graphics::render(int x, int y, const Sprite& sprite)
 {
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
}

TTF_Font* Graphics::loadFont(const char* path, int size)
{
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr)
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load font %s", TTF_GetError());
        }
return gFont;
}

SDL_Texture* Graphics::renderText(const char* text, TTF_Font* font, SDL_Color textColor)
{
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, text, textColor );
        if( textSurface == nullptr )
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( texture == nullptr )
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
        }

        SDL_FreeSurface( textSurface );
        return texture;
}


    void Graphics::quit()
    {    TTF_Quit();
         Mix_Quit();
         IMG_Quit();
         SDL_DestroyRenderer(renderer);
         SDL_DestroyWindow(window);
         SDL_Quit();
    }




