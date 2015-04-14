//
//  OscAdapter.h
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#ifndef __carrousel__OscAdapter__
#define __carrousel__OscAdapter__

#include "ofMain.h"
#include "ofxOsc.h"



class OscAdapter{
    ofxOscReceiver *receiver;
public:
    OscAdapter();
    
    ~OscAdapter();
    bool bOnline;
    void update(ofEventArgs &args);
    static void notifyPush();
};



#endif /* defined(__carrousel__OscAdapter__) */
