//
//  homeScene.h
//  Geosociety
//
//  Created by Deepak on 19/11/13.
//
//

#ifndef __Geosociety__homeScene__
#define __Geosociety__homeScene__

#include <iostream>
#include "cocos2d.h"


USING_NS_CC;

class homeLayer;

class homeScene:public CCScene
{
    homeLayer* layer;
public:
    virtual bool init();
    
    homeScene();
    
     
    CREATE_FUNC(homeScene);
};



class homeLayer : public CCLayer
{
    public:
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
//    static CCScene* scene();
    
    /* CONVERTION */
    
//    virtual bool initWithParent(homeScene* par);
    
    void resignTimer();
    void startTimer();
    void tick(float dt);
    
    
    homeLayer();
    
    
    int fadeOut;
    int page;
    
    int width;
    int height;
    
    int tick_wait;
    
    
     CCDictionary * menuItems;
    
    
    void spriteAtPosition(CCString *image ,CCPoint pos ,int z,float scale,float opacity,CCString* key);
  
    
    void freeformAtPosition(CCString* content,CCString* style,float size,int width,bool instant, CCPoint pos, int z, CCString* key);
   
     virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
//    CREATE_FUNC(homeLayer);
};

#endif /* defined(__Geosociety__homeScene__) */
