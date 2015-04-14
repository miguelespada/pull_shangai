#ifndef App_App_h
#define App_App_h

#include "ofMain.h"
#include "State.h"
#include "OscEvent.h"
#include "AppRenderer.h"
#include "PriceManager.h"
#include "Ruleta.h"

class App
{
    
public:
    App();    
    class State *current_state;
    
    void setCurrentState(State *s);
    void keyPressed(ofKeyEventArgs& eventArgs);
    void update(ofEventArgs &args);
    
    void update();
    void next();
    void jump();
    void draw();
    void cancel();
    void push(OscEvent &e);
    
    AppRenderer *renderer;
    PriceManager *priceManager;
    Ruleta *ruleta;  
};

#endif
