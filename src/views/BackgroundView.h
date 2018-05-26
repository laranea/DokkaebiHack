#ifndef BACKGROUNDVIEW_H 
#define BACKGROUNDVIEW_H 

#include <switch.h>
#include "../View.h"

class BackgroundView : public View {
    using View::View;

    public:
        u8 * snow;
        void render() override;
};

#endif
