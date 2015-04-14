#ifndef __planta__Running_state__
#define __planta__Running_state__

#include <State.h>

class Running: public State
{
public:
    Running(App *g);
    std::string toString() { return "Running"; }
    void update();
    void draw();
    void next();
};

#endif /* defined(__planta__First_state__) */
