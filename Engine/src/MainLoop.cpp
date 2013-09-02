#include "MainLoop.h"

MainLoop::MainLoop() {
    _start = std::chrono::steady_clock::now();
}

void MainLoop::UpdateTime() {
    _deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _start).count();
    _start = std::chrono::steady_clock::now();
}

void MainLoop::Start() {
    _running = true;
    while(_running) {
        UpdateTime();
        SDL_Event event;
        SDL_PollEvent(&event);
        EventHandler(event);
        Draw(GetDeltaTime());
    }
}
float MainLoop::GetDeltaTime()
{
    return _deltaTime;
}
void MainLoop::Stop()
{
    _running = false;
}


void MainLoop::Draw(float delta) {

}


void MainLoop::EventHandler(SDL_Event event) {

}
