#include "Idle.h"
#include "Starting.h"
#include "App.h"
#include "Assets.h"
#include "Settings.h"

IDLE::IDLE(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void IDLE::update(){
    app->renderer->animate();
}

void IDLE::draw(){
    float width = Settings::getInstance()->getWidth();
    float height = Settings::getInstance()->getHeight();
    
    Assets::getInstance()->background_neutro.draw(0, 0, width, height);
    for(int i = 0; i < 5; i ++)
        Assets::getInstance()->back_art_0[i].draw(0, 0, width, height);
    Assets::getInstance()->background_idle.draw(0, 0, width,  height);
    
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