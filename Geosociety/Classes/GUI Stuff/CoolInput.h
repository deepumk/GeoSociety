//
//  CoolInput.h
//  Geosociety
//
//  Created by Deepak on 20/11/13.
//
//

#ifndef __Geosociety__CoolInput__
#define __Geosociety__CoolInput__

#include <iostream>
#include "cocos2d.h"
#include "CoolLabel.h"
#include "CoolSprite.h"
#include "SimpleAudioEngine.h"
#include "CCEditBox.h"
class CoolInput:public CCObject
{
    
public:
    
    ~CoolInput();
    
    CCTextFieldTTF * faketxtbox;
	
	CCPoint topLeft;
	
	CoolSprite * lineBg;
	
	CCString * labelTitle;
	CCString * labelContent;
	
	
	CoolLabel * label;
	CCLayer* parentObject;
	
	int maxTextWidth;
	
	bool bIsPassword;
	int z;
	
	int contentWidth;
    
    void wipe();
    void updatePosition(CCPoint topleft);
    void takeFocus();
    void giveFocus();
    CCString* getData();
    int updateWithConstantWidth(int width);
    
    
    CoolInput* initWithCoolLabel(CCString* labelStr, CCString* data, CCLayer* layer, int zOrder);
    
    
    
    
    
};
#endif /* defined(__Geosociety__CoolInput__) */
