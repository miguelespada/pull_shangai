//
//  priceManager.cpp
//  ruleta_paris
//
//  Created by miguel on 22/02/15.
//
//

#include "priceManager.h"
#include "ofxJSON.h"


PriceManager::PriceManager(){
    bPriceEnabled = false;
};

void PriceManager::getNextPrice(){
    ofxJSONElement response;
    response.open("http://localhost:3000/prices/next.json");
    bPriceEnabled  = response["enabled"].asBool();
    priceId = response["_id"]["$oid"].asString();
    price = response["type"].asString();
}

void PriceManager::disableCurrentPrice(){
    if(bPriceEnabled){
        ofxJSONElement response;
        response.open("http://localhost:3000/prices/disable/" + priceId);
        bPriceEnabled = false;
    }
}

string PriceManager::getPrice(){
    return price;
}