#ifndef ANIMATION_H
#define ANIMATION_H
#include "Texture.h"

class SpriteAnimation {
public:
    SpriteAnimation();
    virtual ~SpriteAnimation();
    void CreateAnimationFromTexture(const Texture& texture);
protected:
private:
};

#endif // ANIMATION_H
