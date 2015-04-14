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
};

void Running::draw(){
    
    
    float width = Settings::getInstance()->getWidth();
    float height = Settings::getInstance()->getHeight();
    
    
    Assets::getInstance()->background_neutro.draw(0, 0, width, height);
    Assets::getInstance()->back_art_1[0].draw(0, 0, width, height);
    
    Assets::getInstance()->background_runnning.draw(0,0,width, height);
    app->ruleta->draw(ofColor(0));
    app->ruleta->drawMasks(ofColor(0));
    
    for(int i = 1; i < 5; i ++)
        Assets::getInstance()->back_art_1[i].draw(0, 0, width, height);

};

void Running::update(){
    
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