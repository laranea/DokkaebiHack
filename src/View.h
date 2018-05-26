#ifndef VIEW_H 
#define VIEW_H 

#include <SDL2/SDL.h>
#include "AssetManager.h"

class View {
    public:
        SDL_Rect rect;
        View(AssetManager * assetManager);
        virtual ~View();
        void setRect(int x, int y, int w, int h);
        virtual void render();

    protected:
        AssetManager * _assetManager;
};

#endif
