#ifndef SCENECONTROL_H
#define SCENECONTROL_H
#include <list>
#include <iostream>
#include "IDraw.h"

class SceneControl {
public:
    SceneControl();
    virtual ~SceneControl();
    IDraw * AddObject(IDraw * object);
    void Draw();
    void Update(float delta);
protected:
private:
    std::list<IDraw*> _drawsList;
};

#endif // SCENECONTROL_H
