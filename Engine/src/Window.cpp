#include "Window.h"

void Window::logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

Window::Window(int height, int width):  _height(height),_width(width) {

}

Window::~Window() {

}

void Window::Show() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        logSDLError(std::cout, "SDL_Init");
        // return 1;
    }

    _window = SDL_CreateWindow("", 100, 100, _width, _height,
                                          SDL_WINDOW_SHOWN);
    if (_window == nullptr) {
        logSDLError(std::cout, "CreateWindow");
        // return 2;
    }
    _renderer = SDL_CreateRenderer(_window, -1,
                             SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr) {
        logSDLError(std::cout, "CreateRenderer");
        //  return 3;
    }
}
SDL_Renderer * Window::GetRenderer()
{
   return _renderer;
}
