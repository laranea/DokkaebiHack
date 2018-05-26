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
#include "BackgroundView.h"

void BackgroundView::render() {
    for (int x = 0; x < 25; x++) {
        for (int y = 0; y < 14; y++) {
            u8 snowType = *(snow + y * 25 + x);
            if (snowType > 4) {
                SDL_Rect snowRect = { x * 50, y * 50, 50, 50};

                switch(snowType - 4) {
                    case 0:
                        SDL_RenderCopy(_assetManager->renderer, _assetManager->snow_1, NULL, &snowRect);
                        break;
                    
                    case 1:
                        SDL_RenderCopy(_assetManager->renderer, _assetManager->snow_2, NULL, &snowRect);
                        break;

                    case 2:
                        SDL_RenderCopy(_assetManager->renderer, _assetManager->snow_3, NULL, &snowRect);
                        break;

                    case 3:
                        SDL_RenderCopy(_assetManager->renderer, _assetManager->snow_4, NULL, &snowRect);
                        break;

                    case 4:
                        SDL_RenderCopy(_assetManager->renderer, _assetManager->snow_5, NULL, &snowRect);
                        break;
                }
            } 
        }
    }

    SDL_RenderCopy(_assetManager->renderer, _assetManager->background, NULL, &rect);
}