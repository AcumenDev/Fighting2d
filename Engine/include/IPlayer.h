#ifndef IPLAYER_H
#define IPLAYER_H
#include "SDL2/SDL.h"

class IPlayer {
public:
    IPlayer() {};
    virtual ~IPlayer() {};
    virtual void SetTexture(SDL_Texture* texture)=0;
    virtual void ToLeft(float )=0;
    virtual void ToRight(float )=0;
};

#endif // IPLAYER_H
