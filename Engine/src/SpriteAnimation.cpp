#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation() {
    //ctor
}

SpriteAnimation::~SpriteAnimation() {
    //dtor
}

void SpriteAnimation::CreateAnimationFromTexture(const Texture& texture) {

}

void SpriteAnimation::AddAnimationKey(AnimationKey animationKey)
{
    _animationKeys.push_back(animationKey);
}
