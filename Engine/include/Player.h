#ifndef PLAYER_H
#define PLAYER_H
#include "IDraw.h"
#include "IPlayer.h"

class Player : public IDraw,IPlayer {
public:

    Player();
    Player(float x,float y);
    virtual ~Player() {};

    void Update(float delta)override;
    void Draw()override;

    void SetTexture(SDL_Texture* texture) override;


    void ToRight(float)override;

    void ToLeft(float)override;

private:
    float _x,_y;
    SDL_Texture* _texture;
};

#endif // PLAYER_H
