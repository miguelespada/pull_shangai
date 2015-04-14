//
//  Ruleta.cpp
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#include "Ruleta.h"
#include "Settings.h"
#include "Assets.h"


Ruleta::Ruleta(){
}

void Ruleta::start(string name){
    Settings *settings = Settings::getInstance();
    
    speed = settings->getSpeed();
    
    price_x = -speed *
    (pow(settings->getDecay(), settings->getExponentialTime()) - 1)/ (settings->getDecay() - 1)
    - settings->getLinearTime() * speed;
    
    prices.clear();
    
    time = settings->getExponentialTime() + settings->getLinearTime();
    
    for(int i = 1; i < 5; i ++) {
        prices.push_back(priceIcon(price_x - settings->getIconSize() * i,
                                   Assets::getInstance()->getRandomPrice()));
    }
    
    prices.push_back(priceIcon(price_x, name));
    
    int xx = price_x + settings->getIconSize();
    while(xx < settings->getIconSize() * 4){
        prices.push_back(priceIcon(xx, Assets::getInstance()->getRandomPrice()));
        xx += settings->getIconSize();
    }
    
}



void Ruleta::update(){
    
    Settings *settings = Settings::getInstance();
    price_x += speed;
    
    if(time < settings->getExponentialTime()){
        speed *= settings->getDecay();
    }
    
    time -= 1;
    
    if(time == 0)
        speed = 0;
    
    if(abs(price_x) < 1){
        time = 0;
    }
}

bool Ruleta::hasStopped(){
    return time == 0;
}

bool Ruleta::isCancelable(){
    return speed == Settings::getInstance()->getSpeed();
}



void Ruleta::draw(ofColor back_color){
    ofPushStyle();
    drawPrices();
    ofPopStyle();
    
    if(time != 0)
        update();
}

void Ruleta::drawFrame(){
    
    Assets *assets = Assets::getInstance();
    
    ofSetColor(255);
}

void Ruleta::drawPrices(){
    for (std::vector<priceIcon>::iterator it = prices.begin() ; it != prices.end(); ++it){
        drawPrice(*it);
        if (time > 0) (*it).x += speed;
    }
}

void Ruleta::drawPrice(priceIcon p){
    Settings *settings = Settings::getInstance();
    Assets *assets = Assets::getInstance();
    
    float scale = Settings::getInstance()->getScale();
    
    float height = assets->price_images[p.name].getHeight() * scale;
    float width = assets->price_images[p.name].getWidth() * scale;
    
    
    ofPushMatrix();
    ofTranslate(settings->getWidth()/2 + 55 * scale, settings->getHeight()/2 - height/2);
    
    
    Assets::getInstance()->price_images[p.name].draw(0, p.x + height/2 + 12 * scale, height, width);

    
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(55 * scale, settings->getHeight()/2 - height/2);
    if(abs(p.x) < 45)
        Assets::getInstance()->price_captions[p.name].draw(0, height/2 + 12 * scale, height, width);
    ofPopMatrix();
    
}


void Ruleta::drawMasks(ofColor back_color){
    ofPushStyle();
    
    float width = Settings::getInstance()->getWidth();
    float height = Settings::getInstance()->getHeight();
    
    Settings *settings = Settings::getInstance();
    float scale = Settings::getInstance()->getScale();
    float icon_size = settings->getIconSize();
    
    ofSetColor(255, 170, 127, 200);
    
    ofRect(width/2,
           0,
           width,
           height/2  + 14 * scale);
    
    ofRect(width/2,
           height/2  + icon_size + 33 * scale,
           width,
           height);
    
    ofPopStyle();
}



