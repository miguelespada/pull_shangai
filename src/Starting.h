#ifndef __planta__First_state__
#define __planta__First_state__

#include <State.h>

class Starting: public State
{
public:
    Starting(App *g);
    std::string toString() { return "Starting"; }
    void update();
    void draw();
    void next();
    void push();
    void jump();
};

#endif /* defined(__planta__First_state__) */
