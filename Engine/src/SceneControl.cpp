#include "SceneControl.h"

SceneControl::SceneControl() {
    //ctor
}

SceneControl::~SceneControl() {
    //dtor
}

void SceneControl::AddObject(IDraw* object) {
    DrawsList.push_back(object);
}

void SceneControl::Draw() {
    for(const auto &i : DrawsList) {
       // i->Update(delta);
        i->Draw();
    }
}


