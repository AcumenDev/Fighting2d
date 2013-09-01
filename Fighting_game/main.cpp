#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include "SDL2/SDL.h"
#include <chrono>

#include "SceneControl.h"
#include "Player.h"

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::steady_clock;

using namespace std;

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}


void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend, SDL_Rect *clip = NULL) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    //Detect if we should use clip width settings or texture width
    if (clip != NULL) {
        pos.w = clip->w;
        pos.h = clip->h;
    } else {
        SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    }
    SDL_RenderCopy(rend, tex, clip, &pos);
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        logSDLError(std::cout, "SDL_Init");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Lesson 2", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        logSDLError(std::cout, "CreateWindow");
        return 2;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                             SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        logSDLError(std::cout, "CreateRenderer");
        return 3;
    }
    bool running = true;


    SDL_Surface *bmp = SDL_LoadBMP("test.bmp");
    if (bmp == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return 1;
    }

//SDL_Rect* rect1 =  new SDL_Rect;
//rect1->x=11;
//rect1->y=22;
//rect1->h=100;
//rect1->w=50;

    steady_clock::time_point start = steady_clock::now();
    float x,y;
    x=y=0;

    Player* player =  new Player(x,y);
    //player.SetTexture(tex);
    player->SetTexture(tex);


SceneControl sceneControl;

   sceneControl.AddObject(player);


    while (running) {

        float delta=   duration_cast<milliseconds>(steady_clock::now() - start).count();
        start = steady_clock::now();


        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_QUIT : {
                running = false;
                break;
            }
            case SDL_KEYDOWN : {
                switch(event.key.keysym.sym) {
                case SDLK_LEFT: {
                    x-=delta*0.2;
                    break;
                }
                case SDLK_RIGHT: {
                    x+=delta*0.2;
                    break;
                }
                case SDLK_UP: {
                    break;
                }
                }
            }
            }
        }
        SDL_RenderClear(renderer);
        ApplySurface(x,y,tex,renderer);


        sceneControl.Draw();

        SDL_RenderPresent(renderer);

    }
    SDL_Quit();
    return 0;
}
