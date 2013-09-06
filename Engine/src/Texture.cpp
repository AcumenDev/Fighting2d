#include "Texture.h"

Texture::Texture(SDL_Renderer *  renderer) {
 _renderer = renderer;
}

Texture::~Texture() {
    //dtor
}

void Texture::LoadTextureFromFile(std::string fileName) {
    SDL_Surface *bmp = SDL_LoadBMP(fileName.c_str());
    if (bmp == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
       return;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(_renderer, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return;
    }
}
