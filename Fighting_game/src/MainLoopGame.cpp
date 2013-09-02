#include "MainLoopGame.h"

MainLoopGame::MainLoopGame() {
    //ctor
}

MainLoopGame::~MainLoopGame() {
    //dtor
}


void MainLoopGame::EventHandler(SDL_Event event) {
    switch(event.type) {
    case SDL_QUIT : {
        Stop();
        break;
    }
    case SDL_KEYDOWN : {
        switch(event.key.keysym.sym) {
        case SDLK_LEFT: {
            // x-=delta*0.2;
            break;
        }
        case SDLK_RIGHT: {
            // x+=delta*0.2;
            break;
        }
        case SDLK_UP: {
            break;
        }
        }
    }
    }
}


void MainLoopGame::Draw(float delta) {


//    SDL_RenderClear(renderer);
//    ApplySurface(x,y,tex,renderer);
//    // sceneControl.Draw();
//    SDL_RenderPresent(renderer);

}
