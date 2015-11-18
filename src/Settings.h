//
//  Settings.h
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __Settings__
#define __Settings__

#include "ofxJSON.h"
#include "ofMain.h"

class Settings{
public:
    static Settings* getInstance();
    void load();
    string assetsPath();
    
    int getWidth();
    int getHeight();
    float getScale();
    
    int getRemotePort();
    int getLocalPort();
    string getRemoteHost();
    
    ofColor getBackgroundColor();
    
    int getSpeed();
    float getDecay();
    int getExponentialTime();
    int getLinearTime();
    int getIconSize();
    int getSleepTime();
    int getPriceSampleX();
    int getPriceSampleY();
    int getPace();
    
    ofColor getBackgroundColor(int index);
    
    int getNumRules();
    int getNumLang();
    int getNumOfBackgroundColors();
    
private:
    static Settings* instance;
    Settings();
    Settings(Settings const&);
    void operator=(Settings const&);
    
    ofxJSONElement json_file;
    Json::Value getData(string key);
};
#endif
