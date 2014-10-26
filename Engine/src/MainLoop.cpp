#include "MainLoop.h"

MainLoop::MainLoop() {
    _start = std::chrono::steady_clock::now();
}

void MainLoop::_UpdateTime() {
    _deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _start).count();
    _start = std::chrono::steady_clock::now();
}

void MainLoop::Start() {
    _running = true;
    while(_running) {
        _UpdateTime();
        SDL_Event event;
        SDL_PollEvent(&event);
        EventHandler(event);
        _Update();
        _Draw();
    }
      SDL_Quit();
}

float MainLoop::_GetDeltaTime() {
    return _deltaTime;
}

void MainLoop::Stop() {
    _running = false;
}

void MainLoop::_Draw() {
    SControl.Draw();
    Draw();
}

void MainLoop::Draw() {

}

void MainLoop::_Update() {
    SControl.Update(_GetDeltaTime());
    Update();
}

void MainLoop::Update() {

}

void MainLoop::EventHandler(SDL_Event event) {

}
