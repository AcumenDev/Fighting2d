#include "MainLoopGame.h"

MainLoopGame::MainLoopGame() {
    //ctor

    _player =  new Player(0,0);

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
            _player->ToLeft(_GetDeltaTime()*0.2);
            break;
        }
        case SDLK_RIGHT: {
            _player->ToRight(_GetDeltaTime()*0.2);
            break;
        }
        case SDLK_UP: {
            break;
        }
        }
    }
    }
}


void MainLoopGame::Draw() {


//    SDL_RenderClear(renderer);
//    ApplySurface(x,y,tex,renderer);
//    // sceneControl.Draw();
//    SDL_RenderPresent(renderer);
_player->Draw();
}

void MainLoopGame::Update()
{
    _player->Update(_GetDeltaTime());
}

