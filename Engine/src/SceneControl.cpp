#include "SceneControl.h"

SceneControl::SceneControl() {
    //ctor
}

SceneControl::~SceneControl() {
    //dtor
}

IDraw * SceneControl::AddObject(IDraw* object) {
    _drawsList.push_back(object);
    return object;
}

void SceneControl::Draw() {
    for(const auto &i : _drawsList) {
        i->Draw();
    }
}

void SceneControl::Update(float delta) {
    for(const auto &i : _drawsList) {
        i->Update(delta);
    }
}

