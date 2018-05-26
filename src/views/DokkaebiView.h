#ifndef DOKKAEBIVIEW_H 
#define DOKKAEBIVIEW_H 

#include <switch.h>
#include "../View.h"

class DokkaebiView : public View {
    using View::View;

    public:
        void render() override;
        u8 * face;
};

#endif
