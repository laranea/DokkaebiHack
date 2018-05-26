#ifndef ASSETMANAGER_H 
#define ASSETMANAGER_H 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class AssetManager {
    public:
        SDL_Window * window;
        SDL_Renderer * renderer;

        /* Textures */
        SDL_Texture * background;
        SDL_Texture * club_1;
        SDL_Texture * club_2;
        SDL_Texture * dokkaebi_1;
        SDL_Texture * dokkaebi_2;
        SDL_Texture * dokkaebi_3;
        SDL_Texture * snow_1;
        SDL_Texture * snow_2;
        SDL_Texture * snow_3;
        SDL_Texture * snow_4;
        SDL_Texture * snow_5;
        SDL_Texture * text;

        AssetManager();
        ~AssetManager();
        bool initialize();

    private:
        SDL_Texture * _loadAsset(const char * file);
};

#endif
