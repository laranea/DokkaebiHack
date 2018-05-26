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

#include "DokkaebiView.h"

void DokkaebiView::render() {
    SDL_Rect faceRect = rect;
    switch(*face) {
        case 0:
            faceRect.w = 348;
            faceRect.h = 240;
            SDL_RenderCopy(_assetManager->renderer, _assetManager->dokkaebi_1, NULL, &faceRect);
            break;

        case 1:
            faceRect.x += 6;
            faceRect.y += 10;
            faceRect.w = 335;
            faceRect.h = 240;
            SDL_RenderCopy(_assetManager->renderer, _assetManager->dokkaebi_2, NULL, &faceRect);
            break;

        case 2:
            faceRect.x += 6;
            faceRect.y += 20;
            faceRect.w = 335;
            faceRect.h = 249;
            SDL_RenderCopy(_assetManager->renderer, _assetManager->dokkaebi_3, NULL, &faceRect);
            break;
    }
}