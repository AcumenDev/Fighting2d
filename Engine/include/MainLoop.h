#ifndef MAINLOOP_H
#define MAINLOOP_H
#include <iostream>
#include <chrono>
#include "SceneControl.h"
#include "SDL2/SDL.h"


class MainLoop {

public:
    SceneControl SControl;
    MainLoop();
    virtual ~MainLoop() {};
    void Start();
    void Stop();
    virtual void Draw();
    virtual void EventHandler(SDL_Event event);
    virtual void Update(float delta);
protected:
    float _GetDeltaTime();
private:
    void _Draw();
    void _Update(float delta);
    void _UpdateTime();
    bool _running;
    std::chrono::steady_clock::time_point _start;
    float _deltaTime;

};

#endif // MAINLOOP_H
