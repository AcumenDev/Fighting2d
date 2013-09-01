#ifndef SCENECONTROL_H
#define SCENECONTROL_H
#include <list>
#include <iostream>
#include "IDraw.h"

class SceneControl {
public:
    SceneControl();
    virtual ~SceneControl();
    void AddObject(IDraw * object);
    void Draw();
protected:
private:
    std::list<IDraw*> DrawsList;
};

#endif // SCENECONTROL_H
