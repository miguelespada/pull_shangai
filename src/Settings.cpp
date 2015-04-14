#include "Settings.h"
#include "Assets.h"

Settings::Settings(){
}

Settings* Settings::instance = 0;
Settings* Settings::getInstance(){
    if (instance == 0){
        instance = new Settings();
        instance->load();
    }
    return instance;
};

void Settings::load(){
    string path = ofToDataPath("settings.json");
    ofLogNotice() << "Loading settings from: " << path;
    json_file.open(path);
}

string Settings::assetsPath(){
    return ofToDataPath("assets") + "/shangai/" ;
}

Json::Value Settings::getData(string key){
    return Settings::json_file[key];
}

float Settings::getScale(){
    return getData("scale").asFloat();
}

int Settings::getWidth(){
    return getData("width").asInt() * getScale();
}

int Settings::getHeight(){
    return getData("height").asInt() * getScale();
}

ofColor Settings::getBackgroundColor(int index){
    string color = getData("background")[index].asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}


int Settings::getLocalPort(){
    return getData("local_port").asInt();
}

int Settings::getRemotePort(){
    return getData("remote_port").asInt();
}

string Settings::getRemoteHost(){
    return getData("remote_host").asString();
}


int Settings::getSpeed(){
    return getData("speed").asInt();
};

float Settings::getDecay(){
    return getData("decay").asFloat();

};

int  Settings::getExponentialTime(){
    return getData("exponential_time").asInt();
    
};

int  Settings::getLinearTime(){
    return getData("linear_time").asInt();
    
};

int  Settings::getIconSize(){
    return getData("icon_size").asInt() * getScale();
    
};

int  Settings::getSleepTime(){
    return getData("sleep_time").asInt();
    
};

int  Settings::getPriceSampleX(){
    return getData("price_sample_x").asInt();
    
};

int  Settings::getPriceSampleY(){
    return getData("price_sample_y").asInt();
    
};

int  Settings::getPace(){
    return getData("pace").asInt();
};


int Settings::getNumRules() {
    return 3;
};

int Settings::getNumLang() {
    return 1;
};

int Settings::getNumOfBackgroundColors() {
    return getData("background").size();
};
