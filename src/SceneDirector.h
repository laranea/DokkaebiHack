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

#ifndef SCENEDIRECTOR_H 
#define SCENEDIRECTOR_H 

#include <SDL2/SDL.h>
#include "AssetManager.h"
#include "Scene.h"
#include "scenes/HackedScene.h"

class SceneDirector {
    public:
        SceneDirector(AssetManager * assetManager);
        ~SceneDirector();
        bool direct();

    private:
        Uint64 _now;
        Uint64 _last;
        SceneType _scene;
        AssetManager * _assetManager;
        HackedScene * _hackedScene;
};

#endif
