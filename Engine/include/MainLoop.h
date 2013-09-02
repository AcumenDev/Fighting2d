#ifndef MAINLOOP_H
#define MAINLOOP_H
#include <iostream>
#include <chrono>
#include "SDL2/SDL.h"


class MainLoop {

public:
    MainLoop();
    virtual ~MainLoop() {};
    void Start();
    void Stop();
    virtual void Draw(float delta);
    virtual void EventHandler(SDL_Event event);
protected:
    float GetDeltaTime();
private:
    void UpdateTime();
    bool _running;
    std::chrono::steady_clock::time_point _start;
    float _deltaTime;
};

#endif // MAINLOOP_H
