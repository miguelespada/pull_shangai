#include "Starting.h"
#include "App.h"
#include "Idle.h"
#include "Running.h"
#include "Winner.h"
#include "Assets.h"

Starting::Starting(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    back = 0;
};

void Starting::draw(){
    
    float width = Settings::getInstance()->getWidth();
    float height = Settings::getInstance()->getHeight();
    
    
    Assets::getInstance()->background[back].draw(0, 0, width, height);
    
    
    app->ruleta->draw(ofColor(0));
    
    Assets::getInstance()->title.draw(0, 0, width, height);
    
    Assets::getInstance()->hash.draw(0, 0, width, height);

    
};

void Starting::update(){
    
    if(ofGetFrameNum() % 30 == 0)
        back = (back + 1) % 2;
    
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