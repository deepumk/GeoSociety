//
//  CoolFreeform.h
//  Geosociety
//
//  Created by Deepak on 20/11/13.
//
//

#ifndef __Geosociety__CoolFreeform__
#define __Geosociety__CoolFreeform__

#include <iostream>
#include "cocos2d.h"
#include "CoolSprite.h"
#include "StringConvertion.h"
USING_NS_CC;

class CoolSprite;
class CoolFreeform:public CCObject
{
  
   
public:
    
      ~CoolFreeform();
    CoolFreeform();
    CCArray * letters;
	
	CCString * contentStr;
	CCString * fontStr;
	float fontSize;
	
	CCSpriteBatchNode *spriteSheet;
	
	bool instant;
	bool bCenter;
	bool bFinished;
    StringConvertion* convertedString;
	
	CCLayer* parentObject;
	
	int x; //Custom Counter for Animation
	int y; //Custom Counter for Animation
	int maxWidth;
	
	int custCounter1; //Custom Counter for Animation
	int custCounter2; //Custom Counter for Animation
	int custCounter3; //Custom Counter for Animation
	int custCounter4; //Custom Counter for Animation
	int custCounter5; //Custom Counter for Animation
	
	int intTag1;
	int intTag2;
    
    int z;
    
    
    
    void finish();
    bool isFinished();
    void evaluate();
    CoolFreeform* initWithCoolSheet(CCString* content ,const char* font,float size, int MaxWidth, bool showInstantly);
    CCRect letterToRect(CCString*letter );
    void updatePosition(CCPoint pos);
    void updateColor(ccColor3B col);
    void updateOpacity(int alpha);
    void updateContent(CCString* content);
    void addToLayer(CCLayer *layer ,int startZ );
    
    void processContent();
     

};



#endif /* defined(__Geosociety__CoolFreeform__) */
