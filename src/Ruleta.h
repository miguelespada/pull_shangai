//
//  Ruleta.h
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#ifndef __carrousel__Ruleta__
#define __carrousel__Ruleta__

#include "ofMain.h"

class Ruleta{
    
    class priceIcon{
    public:
        priceIcon(){};
        priceIcon(float _x, string _name){
            name = _name;
            x = _x;
        }
        float x;
        string name;
    };
    
    float speed;
    float price_x;
    float time;
    
    vector<priceIcon> prices;
    
    void drawPrices();
    void drawPrice(priceIcon p);
    void drawFrame();
    
public:
    Ruleta();
    
    void start(string name);
    
    void draw(ofColor back_color);
    void drawMasks(ofColor back_color);
    void update();
    
    bool hasStopped();
    bool isCancelable();
};
#endif /* defined(__carrousel__Ruleta__) */
