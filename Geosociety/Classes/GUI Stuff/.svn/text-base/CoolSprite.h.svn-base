//
//  CoolSprite.h
//  Geosociety
//
//  Created by Deepak on 20/11/13.
//
//

#ifndef __Geosociety__CoolSprite__
#define __Geosociety__CoolSprite__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;
class CoolSprite: public CCObject
{
public:
    CCSprite * img;
	
	~CoolSprite();
  CoolSprite();
	int curAlpha;
	
	CCLayer* parentObject;
	float myScale;
	CCAnimation * frames;
	int frame,frameCount;
	
	
	int z;
	int x; //Custom Counter for Animation
	int y; //Custom Counter for Animation
	
	
	int intTag1;
	int intTag2;
	int intTag3;
	int intTag4;

    
   
    bool initWithFile(CCString* fontName);
    bool initWithTexture(CCTexture2D * texture, CCRect rect);
    

    
    
    void updatePosition(CCPoint pos);
    void updateOpacity(int alpha);
    void updateScale(float scale);
    void updateRotation(float Rotation);
    void addToLayer(CCLayer* layer, int startZ);
    void addFrame(CCString* filename);
    

    void addFrame(CCTexture2D *texture, CCRect rect );
    void reorderTo(int newZ);
    void commitFrames();
    void nextFrame();
    void setFrame(int newFrame);
    void flipX();
    void updateYScale(float scaleY);
    void updateXScale(float scaleX);
    void updateAnchorPointBottomRight();
    void updateFile(CCString* filename);

};


class CoolFreeformLabel: public::CCLabelTTF
{
public:
    int baseX;
	int baseY;
};





#endif /* defined(__Geosociety__CoolSprite__) */
