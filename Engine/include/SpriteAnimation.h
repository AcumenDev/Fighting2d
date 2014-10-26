#ifndef ANIMATION_H
#define ANIMATION_H
#include <list>
#include "Texture.h"

class AnimationKey {
public:
    AnimationKey(int id,int x,int y,int h,int w)
        : _id(id),_x(x),_y(y),_h(h),_w(w) {};
private:
    int _id;
    int _x;
    int _y;
    int _h;
    int _w;
};



class SpriteAnimation {
public:
    SpriteAnimation();
    virtual ~SpriteAnimation();
    void CreateAnimationFromTexture(const Texture& texture);
    void AddAnimationKey(AnimationKey animationKey);
protected:
private:
    std::list<AnimationKey> _animationKeys;
    int _currentSprite;
};

#endif // ANIMATION_H
