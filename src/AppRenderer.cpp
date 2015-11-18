//
//  AppRenderer.cpp
//  ruleta_paris
//
//  Created by miguel on 22/02/15.
//
//

#include "AppRenderer.h"
#include "Settings.h"
#include "Assets.h"

AppRenderer::AppRenderer(){
    background_color = 0;
    language = 0;
    rule = Settings::getInstance()->getNumRules() - 1;
    animation = 0;
    price_sample = 0;
    ruleta_background = 0;
    random_sample = 0;
    win_animation = 0;
}

void AppRenderer::drawBackground(){
    ofBackground(getBackgroundColor());
}

void AppRenderer::drawRules(){
    ofPushStyle();
    ofSetColor(255);
    
    Assets *assets = Assets::getInstance();
    
    float width = Settings::getInstance()->getWidth();
    float height = Settings::getInstance()->getHeight();
    
    assets->rules[rule].draw(0, 0, width, height);
    
    assets->conditions.draw(0, 0, width, height);
    assets->pull.draw(0, 0, width, height);
    ofPopStyle();
}

void AppRenderer::drawDot(){
    ofPushStyle();
    ofSetColor(255);
    
    Assets *assets = Assets::getInstance();
    
    ofPopStyle();
    
    int pace = Settings::getInstance()->getPace();
    if(ofGetFrameNum() % pace == 0)
        animation = (animation + 1) % 3;
    
}

void AppRenderer::drawWin(){
    ofPushStyle();
    ofSetColor(255);
    
    ofPopStyle();
    
    
}

void AppRenderer::animate(){
    Assets *assets = Assets::getInstance();
    
    int pace = Settings::getInstance()->getPace();
    
    
    if(ofGetFrameNum() % (4 * pace) == 0){
        if(assets->price_number() > 1)
            price_sample = (price_sample + 1) % (assets->price_number() - 1);
    }
    
    if(ofGetFrameNum() % (8 * pace) == 0){
        rule = (rule + 1) % Settings::getInstance()->getNumRules() ;
        
        random_sample = ofRandom(assets->price_samples.size());
    }
    
}

ofColor AppRenderer::getBackgroundColor(){
    return Settings::getInstance()->getBackgroundColor(background_color);
}

void AppRenderer::drawWinner(string price){
    ofPushStyle();
    ofSetColor(255);
    
    Assets *assets = Assets::getInstance();
    assets->price_winnings[price].draw(0, 0);
    ofPopStyle();

}
