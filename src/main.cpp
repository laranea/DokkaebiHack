#include <switch.h>

#include "AssetManager.h"
#include "SceneDirector.h"

using namespace std;

int main()
{
    AssetManager * assetManager = new AssetManager();
    if(!assetManager->initialize()) {
        return -1;
    }

    SceneDirector * sceneDirector = new SceneDirector(assetManager);

    // Main Game Loop
    while(appletMainLoop())
    {
        if (!sceneDirector->direct())
            break;
    }

    delete sceneDirector;
    delete assetManager;

    return 0;
}
