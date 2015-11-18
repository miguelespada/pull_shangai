#include "Winner.h"
#include "App.h"
#include "Idle.h"
#include "Assets.h"

Winner::Winner(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    timer = ofGetElapsedTimeMillis();
    back = 0;
};

void Winner::draw(){
    float width = Settings::getInstance()->getWidth();
    float height = Settings::getInstance()->getHeight();
 
    Assets::getInstance()->background[back + 1].draw(0, 0, width, height);
    
    app->renderer->drawWinner(app->priceManager->getPrice());
    
    
    app->ruleta->draw(ofColor(0));
    
    Assets::getInstance()->hash.draw(0, 0, width, height);
};

void Winner::update(){
    if((ofGetElapsedTimeMillis() - timer) > Settings::getInstance()->getSleepTime() * 4){
        app->setCurrentState(new IDLE(app));
        delete this;
    }
    
    if(ofGetFrameNum() % 15 == 0)
        back = (back + 1) % 2;
}

void Winner::next(){
    app->setCurrentState(new IDLE(app));
    delete this;
};