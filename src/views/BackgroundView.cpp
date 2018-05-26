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