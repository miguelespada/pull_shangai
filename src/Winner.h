#ifndef __planta__Winner_state__
#define __planta__Winner_state__

#include <State.h>

class Winner: public State
{
public:
    Winner(App *g);
    std::string toString() { return "Winner"; }
    void update();
    void draw();
    void next();
};

#endif /* defined(__planta__First_state__) */

