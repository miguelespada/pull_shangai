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
    
    for(int i = 0; i < price_number(); i++){
        string filename = assets_path + "icons/" + prices[i] + ".png";
        price_images[prices[i]].loadImage( filename );
        ofLogNotice() << "Loading: " << filename;
            
        if(prices[i] != "nothing"){
            price_samples.push_back(price_images[prices[i]]);
        }
        
        filename = assets_path + "win/es/" + prices[i] + ".png";
        ofImage img;
        img.loadImage(filename);
        price_winnings_es[prices[i]] = img;
        ofLogNotice() << "Loading: " << filename;
        
        filename = assets_path + "win/en/" + prices[i] + ".png";
        ofImage img2;
        img2.loadImage(filename);
        price_winnings_en[prices[i]] = img2;
        ofLogNotice() << "Loading: " << filename;
        
        
        filename = assets_path + "win/icons/" + prices[i] + ".png";
        ofImage img3;
        img3.loadImage(filename);
        price_images[prices[i]] = img3;
        ofLogNotice() << "Loading: " << filename;
    }
    

    for(int i = 0; i < 2; i ++){
        string filename = assets_path + "rules/es/" + ofToString(i) + ".png";
        rules_es[i].loadImage(filename);
        ofLogNotice() << "Loading: " << filename ;
    }
    
    
    for(int i = 0; i < 2; i ++){
        string filename = assets_path + "rules/en/" + ofToString(i) + ".png";
        rules_en[i].loadImage(filename);
        ofLogNotice() << "Loading: " << filename ;
    }

    
    for(int i = 0; i < 4; i ++){
        string filename = assets_path + "background/" + ofToString(i) + ".png";
        background[i].loadImage(filename);
        ofLogNotice() << "Loading: " << filename ;
    }


    string filename;
    
    filename = assets_path + "hash.png";
    hash.loadImage(filename);
    ofLogNotice() << "Loading: " << filename ;
    
    filename = assets_path + "title.png";
    title.loadImage(filename);
    
    ofLogNotice() << "Loading: " << filename ;
    filename = assets_path + "rules/es/terms.png";
    terms_es.loadImage(filename);
    
    ofLogNotice() << "Loading: " << filename ;
    filename = assets_path + "rules/en/terms.png";
    terms_en.loadImage(filename);
    ofLogNotice() << "Loading: " << filename ;
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
