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

#include "AssetManager.h"

AssetManager::AssetManager() {
    window = NULL;
    renderer = NULL;
    background = NULL;
    club_1 = NULL;
    club_2 = NULL;
    dokkaebi_1 = NULL;
    dokkaebi_2 = NULL;
    dokkaebi_3 = NULL;
    snow_1 = NULL;
    snow_2 = NULL;
    snow_3 = NULL;
    snow_4 = NULL;
    snow_5 = NULL;
    text = NULL;
}

AssetManager::~AssetManager() {
    if (background != NULL) SDL_DestroyTexture(background);
    if (club_1 != NULL) SDL_DestroyTexture(club_1);
    if (club_2 != NULL) SDL_DestroyTexture(club_2);
    if (dokkaebi_1 != NULL) SDL_DestroyTexture(dokkaebi_1);
    if (dokkaebi_2 != NULL) SDL_DestroyTexture(dokkaebi_2);
    if (dokkaebi_3 != NULL) SDL_DestroyTexture(dokkaebi_3);
    if (snow_1 != NULL) SDL_DestroyTexture(snow_1);
    if (snow_2 != NULL) SDL_DestroyTexture(snow_2);
    if (snow_3 != NULL) SDL_DestroyTexture(snow_3);
    if (snow_4 != NULL) SDL_DestroyTexture(snow_4);
    if (snow_5 != NULL) SDL_DestroyTexture(snow_5);
    if (text != NULL) SDL_DestroyTexture(text);

    if (renderer != NULL) SDL_DestroyRenderer(renderer);
    if (window != NULL) SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
};

bool AssetManager::initialize() {
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
        return false;

    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_FULLSCREEN);
    if (!window)
        return false;

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_SOFTWARE);
    if (!renderer)
        return false;

    background = _loadAsset("/switch/DokkaebiHack/assets/background.png");
    club_1 = _loadAsset("/switch/DokkaebiHack/assets/club_1.png");
    club_2 = _loadAsset("/switch/DokkaebiHack/assets/club_2.png");
    dokkaebi_1 = _loadAsset("/switch/DokkaebiHack/assets/dokkaebi_1.png");
    dokkaebi_2 = _loadAsset("/switch/DokkaebiHack/assets/dokkaebi_2.png");
    dokkaebi_3 = _loadAsset("/switch/DokkaebiHack/assets/dokkaebi_3.png");
    snow_1 = _loadAsset("/switch/DokkaebiHack/assets/snow_1.png");
    snow_2 = _loadAsset("/switch/DokkaebiHack/assets/snow_2.png");
    snow_3 = _loadAsset("/switch/DokkaebiHack/assets/snow_3.png");
    snow_4 = _loadAsset("/switch/DokkaebiHack/assets/snow_4.png");
    snow_5 = _loadAsset("/switch/DokkaebiHack/assets/snow_5.png");
    text = _loadAsset("/switch/DokkaebiHack/assets/text.png");

    return true;
};

SDL_Texture * AssetManager::_loadAsset(const char * file) {
    SDL_Surface * image = IMG_Load(file);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    return texture;
};
