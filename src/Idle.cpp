#include "Idle.h"
#include "Starting.h"
#include "App.h"
#include "Assets.h"
#include "Settings.h"

IDLE::IDLE(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    back = 0;
};

void IDLE::update(){
    app->renderer->animate();
    
    if(ofGetFrameNum() % 30 == 0)
        back = (back + 1) % 2;
}

void IDLE::draw(){
    float width = Settings::getInstance()->getWidth();
    float height = Settings::getInstance()->getHeight();
    
    
    Assets::getInstance()->background[back].draw(0, 0, width, height);
    Assets::getInstance()->title.draw(0, 0, width, height);
  
    app->renderer->drawRules();
    
};

void IDLE::push(){
    app->priceManager->getNextPrice();
    app->ruleta->start(app->priceManager->getPrice());
    app->setCurrentState(new Starting(app));
    
    delete this;
}

void IDLE::next(){
    app->setCurrentState(new Starting(app));
    delete this;
};