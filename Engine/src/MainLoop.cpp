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
        _Update(_GetDeltaTime());
        _Draw();
    }
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

void MainLoop::_Update(float delta) {
    SControl.Update(delta);
    Update(delta);
}

void MainLoop::Update(float delta) {

}

void MainLoop::EventHandler(SDL_Event event) {

}
