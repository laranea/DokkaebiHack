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
