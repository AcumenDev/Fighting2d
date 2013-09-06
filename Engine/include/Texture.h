#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include "SDL2/SDL.h"
class Texture {
public:
    Texture(SDL_Renderer *  renderer);
    virtual ~Texture();
    void LoadTextureFromFile(std::string fileName);
protected:
private:
    SDL_Renderer * _renderer;
};

#endif // TEXTURE_H
