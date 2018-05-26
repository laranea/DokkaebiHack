// Dokkaebi Hack
// Copyright (C) 2018 Steven Mattera
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

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