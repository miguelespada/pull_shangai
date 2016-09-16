//
//  OscAdapter.cpp
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#include "OscAdapter.h"
#include "OscEvent.h"
#include "Settings.h"


OscAdapter::OscAdapter(){
    int localPort = Settings::getInstance()->getLocalPort();
    receiver = new ofxOscReceiver;
    receiver->setup(localPort);
    ofLogNotice() << "listening for osc messages on port " << localPort;
    bOnline = false;
    
    ofAddListener(ofEvents().update, this, &OscAdapter::update);
}

OscAdapter::~OscAdapter(){
    delete receiver;
}

void OscAdapter::notifyPush(){
    OscEvent event("push");
    ofLogNotice() << "Received: /keydown";
    ofNotifyEvent(OscEvent::OscEvents, event);
}

void OscAdapter::update(ofEventArgs &args){
    while(receiver->hasWaitingMessages()){
        bOnline = true;
        ofxOscMessage m;
        receiver->getNextMessage(&m);
        cout << m.getAddress()  << endl;
        if(m.getAddress() == "/key_down"){
            notifyPush();
        }
        if(m.getAddress() == "/keydown"){
            notifyPush();
        }
        if(m.getAddress() == "/ping"){
            cout << "Rasp alive" << endl;
        }
    }
}
