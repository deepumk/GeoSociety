//
//  CoolLabel.h
//  Geosociety
//
//  Created by Deepak on 20/11/13.
//
//

#ifndef __Geosociety__CoolLabel__
#define __Geosociety__CoolLabel__

#include <iostream>
#include "cocos2d.h"


USING_NS_CC;
class CoolLabel:public CCObject
{
  
public:
    
    ~CoolLabel();
    CCLabelTTF * main;
	CCLabelTTF * shadow1;
	CCLabelTTF * shadow2;
	CCLabelTTF * shadow3;
	CCLabelTTF * shadow4;
	CCLayer* parentObject;
	
	CCString * contentStr;
	CCString * fontStr;
	int fontSize;
	
	int fixedHeight;
	
	int x; //Custom Counter for Animation
	int y; //Custom Counter for Animation
	
	int custCounter1; //Custom Counter for Animation
	int custCounter2; //Custom Counter for Animation
	int custCounter3; //Custom Counter for Animation
	int custCounter4; //Custom Counter for Animation
	int custCounter5; //Custom Counter for Animation
	
	int intTag1;
	int intTag2;
    
    
    
    CoolLabel* initWithCoolString(CCString* content ,const char*fontNmae, float size);
    void updatePosition(CCPoint pos);
    void updateColor(ccColor3B col);
    void updateOpacity(int alpha);
    void updateContent(CCString* content);
    void addToLayer(CCLayer *layer ,int startZ );
    void updateAnchorPointBottomRight();
    int updateWithConstantWidth(int width);

};



#endif /* defined(__Geosociety__CoolLabel__) */
