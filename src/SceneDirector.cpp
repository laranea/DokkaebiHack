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
