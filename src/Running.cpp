//
//  Running.cpp
//  ruleta_paris
//
//  Created by miguel on 21/02/15.
//
//

#include "Running.h"
#include "Winner.h"
#include "App.h"
#include "Settings.h"
#include "Assets.h"

Running::Running(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    back = 0;

};

void Running::draw(){
    
    float width = Settings::getInstance()->getWidth();
    float height = Settings::getInstance()->getHeight();
    
    
    Assets::getInstance()->background[back].draw(0, 0, width, height);
    
    
    app->ruleta->draw(ofColor(0));
    
    Assets::getInstance()->title.draw(0, 0, width, height);
    
    Assets::getInstance()->hash.draw(0, 0, width, height);
    
};

void Running::update(){
    
    if(ofGetFrameNum() % 30 == 0)
        back = (back + 1) % 2;
    
    if(app->ruleta->hasStopped()){
        ofSleepMillis(Settings::getInstance()->getSleepTime());
        app->setCurrentState(new Winner(app));
        app->priceManager->disableCurrentPrice();
        delete this;
    }
}

void Running::next(){
    app->setCurrentState(new Winner(app));
    delete this;
};