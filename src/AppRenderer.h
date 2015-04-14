//
//  AppRenderer.h
//  ruleta_paris
//
//  Created by miguel on 22/02/15.
//
//

#ifndef __ruleta_paris__AppRenderer__
#define __ruleta_paris__AppRenderer__

#include "ofMain.h"

class AppRenderer
{
    int background_color;
    int language;
    int rule;
    int animation;
    int price_sample;
    int ruleta_background;
    int random_sample;
    int win_animation;
    
public:
    AppRenderer();
    
    void drawBackground();
    ofColor getBackgroundColor();
    void drawRules();
    void drawDot();
    void drawWin();
    void animate();
    
    void drawWinner(string price);
    
};

#endif /* defined(__ruleta_paris__AppRenderer__) */
