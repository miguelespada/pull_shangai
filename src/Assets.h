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

    std::map<std::string, ofImage> price_images, price_winnings_es, price_winnings_en;
    vector<ofImage> price_samples;
    
    ofImage background[4];
    ofImage rules_es[2];
    ofImage rules_en[2];
    
    
    ofImage terms_es;
    ofImage terms_en;
    ofImage hash;
    ofImage title;
    ofImage pull;
  
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
