#include <math.h>
#include "HackedScene.h"
#include "time.h"

HackedScene::HackedScene(AssetManager * assetManager, SceneType sceneType) : Scene(assetManager, sceneType) {
    srand(time(NULL));

    _lastSnowGeneration = 0;
    _generateSnow();

    _backgroundView = new BackgroundView(assetManager);
    _backgroundView->setRect(0, 0, 1280, 720);
    _backgroundView->snow = &_snow[0];

    _lastDokkaebiFaceChange = 0;
    _face = 0;

    _dokkaebiView = new DokkaebiView(assetManager);
    _dokkaebiView->setRect(466, 37, 348, 249);
    _dokkaebiView->face = &_face;

    _textView = new TextView(assetManager);
    _textView->setRect(502, 323, 276, 73);

    _leftClubY = 0;
    _rightClubY = 20;

    _clubsView = new ClubsView(assetManager);
    _clubsView->setRect(509, 463, 261, 189);
    _clubsView->leftClubY = &_leftClubY;
    _clubsView->rightClubY = &_rightClubY;
}

HackedScene::~HackedScene() {
    delete _backgroundView;
    delete _dokkaebiView;
    delete _textView;
    delete _clubsView;
}

void HackedScene::draw(double dTime) {
    _timeSpent += dTime;

    // Background View
    if (_timeSpent - _lastSnowGeneration > 250) {
        _lastSnowGeneration = _timeSpent;
        _generateSnow();
    }
    _backgroundView->render();

    // Dokkaebi View
    if (_timeSpent - _lastDokkaebiFaceChange > 100) {
        _lastDokkaebiFaceChange = _timeSpent;
        _face++;
        if (_face > 2) {
            _face = 0;
        }
    }
    _dokkaebiView->render();

    // Text View
    _textView->render();

    // Clubs View
    _leftClubY = (sin(_timeSpent) * 10) + 10;
    _rightClubY = (sin(_timeSpent + M_PI) * 10) + 10;
    _clubsView->render();

    // Limit our time spent.
    if (_timeSpent > M_PI * 300) {
        _timeSpent -= M_PI * 300;
        _lastSnowGeneration -= M_PI * 300;
        _lastDokkaebiFaceChange -= M_PI * 300;
    }
}

void HackedScene::onButtonDown(HidControllerID id, u64 button) {
    if (button & KEY_A) {
        exitScene(None);
    }
}

void HackedScene::_generateSnow() {
    for (int i = 0; i < 350; i++) {
        _snow[i] = rand() % 10;
    }
}