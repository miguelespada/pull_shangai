//
//  Events.h
//  planta
//
//  Created by miguel on 21/02/15.
//
//

#ifndef _Events_h
#define _Events_h
#pragma once
#include "ofMain.h"

class OscEvent : public ofEventArgs {
    
public:
    string type;
    OscEvent(string _type) {
        type = _type;
    }
    
    static ofEvent <OscEvent> OscEvents;
};

#endif
