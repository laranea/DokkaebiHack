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
