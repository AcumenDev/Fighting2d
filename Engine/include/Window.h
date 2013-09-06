#ifndef WINDOW_H
#define WINDOW_H
#include "iostream"
#include "SDL2/SDL.h"

class Window {
public:
    Window(int height, int width);
    virtual ~Window();
    // void SetPosition();
    //  void SetSize();
    void Show();
    SDL_Renderer * GetRenderer();
protected:
private:
    int _height;
    int _width;
    void logSDLError(std::ostream &os, const std::string &msg);
    SDL_Window *_window;
    SDL_Renderer *_renderer;
};

#endif // WINDOW_H
