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
