#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include "SDL2/SDL.h"
#include "MainLoopGame.h"

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
    Window window(600,800);
    window.Show();
    SceneControl sceneControl;
    MainLoopGame mainLoopGame;
    mainLoopGame.Start();


//        SDL_RenderClear(window.GetRenderer());
//        ApplySurface(x,y,tex,window.GetRenderer());
//        // sceneControl.Draw();
//        SDL_RenderPresent(window.GetRenderer());
    return 0;
}
