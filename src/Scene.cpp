#include "Scene.h"

Scene::Scene(AssetManager * assetManager, SceneType sceneType) {
    _assetManager = assetManager;
    _sceneType = sceneType;
}

Scene::~Scene() {}

SceneType Scene::play(double dTime) {
    // Read joystick controls.
    _readControls();

    // Draw scene.
    draw(dTime);

    return _sceneType;
}

void Scene::draw(double dTime) {}
void Scene::onButtonDown(HidControllerID id, u64 button) {}
void Scene::onButtonHeld(HidControllerID id, u64 button) {}
void Scene::onButtonUp(HidControllerID id, u64 button) {}

void Scene::exitScene(SceneType sceneType) {
    _sceneType = sceneType;
}

void Scene::_readControls() {
    for (int id = 0; id <= 10; id++) {
        HidControllerID controllerId = (HidControllerID) id;

        u64 heldKey = hidKeysHeld(controllerId);
        if (heldKey != 0) {
            onButtonHeld(controllerId, heldKey);
        }

        u64 downKey = hidKeysDown(controllerId);
        if (downKey != 0) {
            onButtonDown(controllerId, downKey);
        }
    }
}