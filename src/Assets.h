//
//  Assets.h
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __carrousel__Assets__
#define __carrousel__Assets__

#include <stdio.h>
#include "ofMain.h"
#include "ofxJSON.h"
#include "Settings.h"


class Assets{
public:
    static Assets* getInstance();
    void load();

    std::map<std::string, ofImage> price_images, price_captions, price_winnings;
    vector<ofImage> price_samples;
    ofImage background_idle;
    ofImage background_runnning;
    ofImage background_neutro;
    ofImage background_gagne;
    ofImage rules[3];
    ofImage dot_animation[3];
    ofImage win_animation[2];
    ofImage back_art_0[5];
    ofImage back_art_1[5];
    ofImage back_art_2[4];
    
    vector<string> prices;
    int price_number();
    
    bool bOnline;
    string getRandomPrice();
    
private:
    static Assets* instance;
    void import_price_list();
    
    Assets();
};

#endif /* defined(__carrousel__Assets__) */
