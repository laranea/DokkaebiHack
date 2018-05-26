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

#ifndef SCENE_H 
#define SCENE_H 

#include <SDL2/SDL.h>
#include <switch.h>
#include "AssetManager.h"

enum SceneType {
    None,
    Hacked
};

class Scene {
    public:
        Scene(AssetManager * assetManager, SceneType sceneType);
        virtual ~Scene();
        SceneType play(double dTime);

        virtual void draw(double dTime);

        virtual void onButtonDown(HidControllerID id, u64 button);
        virtual void onButtonHeld(HidControllerID id, u64 button);
        virtual void onButtonUp(HidControllerID id, u64 button);

        void exitScene(SceneType sceneType);
    private:
        SceneType _sceneType;
        AssetManager * _assetManager;

        void _readControls();
};

#endif
