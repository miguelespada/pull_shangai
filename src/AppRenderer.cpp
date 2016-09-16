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
    
    if(language == 0){
        assets->rules_es[rule].draw(0, 0, width, height);
        assets->terms_es.draw(0, 0, width, height);
    }
    else{
        assets->rules_en[rule].draw(0, 0, width, height);
        assets->terms_en.draw(0, 0, width, height);
    }
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
    
    
    if(ofGetFrameNum() % (6 * pace) == 0){
        rule = (rule + 1) % Settings::getInstance()->getNumRules() ;
        if(rule == 0){
            language = (language + 1) % Settings::getInstance()->getNumLang() ;
        }
    }
    
}

ofColor AppRenderer::getBackgroundColor(){
    return Settings::getInstance()->getBackgroundColor(background_color);
}

void AppRenderer::drawWinner(string price){
    ofPushStyle();
    ofSetColor(255);
    Assets *assets = Assets::getInstance();
    
    if(language == 0){
        assets->price_winnings_es[price].draw(0, 0);
    }
    else{
        assets->price_winnings_en [price].draw(0, 0);
    }
    ofPopStyle();

}
