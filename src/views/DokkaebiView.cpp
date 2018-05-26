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