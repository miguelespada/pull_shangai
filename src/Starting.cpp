#include "Starting.h"
#include "App.h"
#include "Idle.h"
#include "Running.h"
#include "Winner.h"
#include "Assets.h"

Starting::Starting(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void Starting::draw(){
    
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

void Starting::update(){
    if(!app->ruleta->isCancelable()){
        app->setCurrentState(new Running(app));
        delete this;
    };
}


void Starting::push(){
    app->setCurrentState(new IDLE(app));
    delete this;
};

void Starting::next(){
    app->setCurrentState(new Running(app));
    delete this;
};

void Starting::jump(){
    app->setCurrentState(new Winner(app));
    delete this;
};