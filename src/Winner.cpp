#include "Winner.h"
#include "App.h"
#include "Idle.h"
#include "Assets.h"

Winner::Winner(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    timer = ofGetElapsedTimeMillis();
};

void Winner::draw(){
    float width = Settings::getInstance()->getWidth();
    float height = Settings::getInstance()->getHeight();
    
    Assets::getInstance()->background_neutro.draw(0, 0,width, height);

    if((ofGetFrameNum() / 30) % 2 == 0){
        for(int i = 0; i < 4; i ++)
            Assets::getInstance()->back_art_1[i].draw(0, 0,width, height);
    }
    else{
        
        for(int i = 0; i < 4; i ++)
            Assets::getInstance()->back_art_2[i].draw(0, 0,width, height);
    }

    app->renderer->drawWinner(app->priceManager->getPrice());
    
  //  app->ruleta->draw(ofColor(0));
};

void Winner::update(){
    if((ofGetElapsedTimeMillis() - timer) > Settings::getInstance()->getSleepTime() * 4){
        app->setCurrentState(new IDLE(app));
        delete this;
    }
}

void Winner::next(){
    app->setCurrentState(new IDLE(app));
    delete this;
};