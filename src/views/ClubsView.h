#ifndef CLUBSVIEW_H 
#define CLUBSVIEW_H 

#include "../View.h"

class ClubsView : public View {
    using View::View;

    public:
        int * leftClubY;
        int * rightClubY;
        void render() override;
};

#endif
