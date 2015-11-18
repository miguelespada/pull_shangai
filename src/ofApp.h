#pragma once

#include "ofMain.h"
#include "App.h"
#include "Info.h"
#include "OscAdapter.h"

class ofApp : public ofBaseApp{
public:
    ofApp();

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void setRotation();

    App app;
    Info info;
    OscAdapter osc;
    bool bRotated = false;
};


