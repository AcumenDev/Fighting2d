#include "Player.h"
Player::Player(float x, float y) {
    _x=x;
    _y=y;
}
Player::Player() {
    _x=0;
    _y=0;
}

void Player::Update(float delta) {

}

void Player::Draw() {

}

void Player::SetTexture(SDL_Texture* texture) {
    _texture=texture;
}


void Player::ToRight(float m) {

}

void Player::ToLeft(float m) {

}


