#include "View.h"

View::View(AssetManager * assetManager) {
    _assetManager = assetManager;
}

View::~View() {}

void View::setRect(int x, int y, int w, int h) {
    rect = { x, y, w, h};
}

void View::render() {}