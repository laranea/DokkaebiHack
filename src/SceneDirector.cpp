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

#include <switch.h>
#include "SceneDirector.h"

SceneDirector::SceneDirector(AssetManager * assetManager) {
    _now = SDL_GetPerformanceCounter();
    _last = 0;
    _scene = Hacked;
    _assetManager = assetManager;
    _hackedScene = NULL;
}

SceneDirector::~SceneDirector() {
    if (_hackedScene != NULL) delete _hackedScene;
}

bool SceneDirector::direct() {
    _last = _now;
    _now = SDL_GetPerformanceCounter();
    double dTime = (double) ((_now - _last) * 1000 / SDL_GetPerformanceFrequency());

    hidScanInput();
    SDL_RenderClear(_assetManager->renderer);

    switch (_scene) {
        case Hacked:
            if (_hackedScene == NULL) {
                _hackedScene = new HackedScene(_assetManager, Hacked);
            }

            _scene = _hackedScene->play(dTime);
            break;

        default:
            return false;
    }

    SDL_RenderPresent(_assetManager->renderer);
    
    return true;
};
