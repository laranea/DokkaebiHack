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
