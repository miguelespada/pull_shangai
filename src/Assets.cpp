//
//  Assets.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "Assets.h"

#define BACKGROUND_ANIMATIONS false
Assets::Assets(){
}

Assets* Assets::instance = 0;

Assets* Assets::getInstance(){
    if (instance == 0){
        instance = new Assets();
        instance->load();
    }
    return instance;
};

void Assets::load(){
    string assets_path = Settings::getInstance()->assetsPath();
    ofLogNotice() << "Loading assets from: " << assets_path;
    
    import_price_list();
    
    string filename = assets_path + "background/idle.png";
    background_idle.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    filename = assets_path + "background/running.png";
    background_runnning.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;

    
    filename = assets_path + "background/background.png";
    background_neutro.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;

    
    for(int i = 0; i < price_number(); i++){
        string filename = assets_path + "icons/" + prices[i] + ".png";
        price_images[prices[i]].loadImage( filename );
        ofLogNotice() << "Loading: " << filename;
        
        filename = assets_path + "names/" + prices[i] + ".png";
        price_captions[prices[i]].loadImage( filename );
        ofLogNotice() << "Loading: " << filename;
        
        if(prices[i] != "nothing"){
            price_samples.push_back(price_images[prices[i]]);
        }
        
        filename = assets_path + "win/" + prices[i] + ".png";
        ofImage img;
        img.loadImage(filename);
        price_winnings[prices[i]] = img;
        ofLogNotice() << "Loading: " << filename;
    }

    for(int i = 0; i < Settings::getInstance()->getNumRules(); i ++){
        string filename = assets_path + "rules/rule_" + ofToString(i) + ".png";
        rules[i].loadImage(filename);
        ofLogNotice() << "Loading: " << filename ;
    }
    
    for(int i = 0; i < 5; i ++){
        string filename = assets_path + "background/art_0/back_" + ofToString(i) + ".png";
        back_art_0[i].loadImage(filename);
        ofLogNotice() << "Loading: " << filename ;
    }
    
    for(int i = 0; i < 5; i ++){
        string filename = assets_path + "background/art_1/back_" + ofToString(i) + ".png";
        back_art_1[i].loadImage(filename);
        ofLogNotice() << "Loading: " << filename ;
    }
    
    for(int i = 0; i < 4; i ++){
        string filename = assets_path + "background/art_2/back_" + ofToString(i) + ".png";
        back_art_2[i].loadImage(filename);
        ofLogNotice() << "Loading: " << filename ;
    }

}

int Assets::price_number(){
    return prices.size();
}

void Assets::import_price_list(){
    ofxJSONElement list;
    bOnline = list.open("http://localhost:3000/prices/list.json");
    for(int i = 0; i < list.size(); i++){
        prices.push_back(list[i].asString());
        ofLogNotice() << "Adding price: " << list[i].asString();
    }
    prices.push_back("nothing");
}

string Assets::getRandomPrice(){
    return prices[ofRandom(price_number())];
}
