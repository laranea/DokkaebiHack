#ifndef TEXTVIEW_H 
#define TEXTVIEW_H 

#include "../View.h"

class TextView : public View {
    using View::View;

    public:
        void render() override;
};

#endif
