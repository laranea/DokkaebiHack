#include "ClubsView.h"

void ClubsView::render() {
    SDL_Rect leftRect = rect;
    leftRect.y += *leftClubY;
    leftRect.w = 261;
    SDL_RenderCopy(_assetManager->renderer, _assetManager->club_2, NULL, &leftRect);

    SDL_Rect rightRect = rect;
    rightRect.y += *rightClubY;
    rightRect.w = 255;
    SDL_RenderCopy(_assetManager->renderer, _assetManager->club_1, NULL, &rightRect);
}