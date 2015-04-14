//
//  priceManager.h
//  ruleta_paris
//
//  Created by miguel on 22/02/15.
//
//

#ifndef __ruleta_paris__priceManager__
#define __ruleta_paris__priceManager__

#include "ofMain.h"

class PriceManager
{
    
    string price;
    string priceId;
    bool bPriceEnabled;
    
public:
    PriceManager();
    
    void getNextPrice();
    void disableCurrentPrice();
    string getPrice();
    
};
#endif /* defined(__ruleta_paris__priceManager__) */
