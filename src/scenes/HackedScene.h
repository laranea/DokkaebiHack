#ifndef HACKEDSCENE_H 
#define HACKEDSCENE_H 

#include <switch.h>
#include "../Scene.h"
#include "../views/BackgroundView.h"
#include "../views/DokkaebiView.h"
#include "../views/TextView.h"
#include "../views/ClubsView.h"

class HackedScene : public Scene {
    public:
        HackedScene(AssetManager * assetManager, SceneType sceneType);
        ~HackedScene();
        void draw(double dTime) override;
        void onButtonDown(HidControllerID id, u64 button) override;

    private:
        double _timeSpent;

        // Background View
        BackgroundView * _backgroundView;
        u8 _snow[350];
        double _lastSnowGeneration;
        void _generateSnow();

        // Dokkaebi View
        DokkaebiView * _dokkaebiView;
        u8 _face;
        double _lastDokkaebiFaceChange;

        // Text View
        TextView * _textView;

        // Clubs View
        ClubsView * _clubsView;
        int _leftClubY;
        int _rightClubY;
};

#endif
