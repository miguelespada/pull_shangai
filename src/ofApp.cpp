#include "ofApp.h"
#include "Idle.h"
#include "Settings.h"
#include "Assets.h"
#include "OscEvent.h"


ofApp::ofApp(){
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    ofSetWindowShape(Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
    app.setCurrentState(new IDLE(&app));
    setRotation();
    
    ofToggleFullscreen();
    ofSetWindowPosition(1281, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    // Services are updated with listeners
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    if(bRotated){
        ofTranslate(ofGetWidth(), 0);
        ofRotate(90);
    }
    app.draw();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'c':
            ofHideCursor();
            break;
        case 'C':
            ofShowCursor();
            break;
        case ' ':
            OscAdapter::notifyPush();
            break;
        
        case 'R':
            bRotated = !bRotated;
            setRotation();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){}

void ofApp::setRotation(){
    
    if(bRotated)
        ofSetWindowShape(Settings::getInstance()->getHeight(), Settings::getInstance()->getWidth());
    else
        ofSetWindowShape(Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
}