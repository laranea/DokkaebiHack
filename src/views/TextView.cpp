#include "TextView.h"

void TextView::render() {
    SDL_RenderCopy(_assetManager->renderer, _assetManager->text, NULL, &rect);
}
