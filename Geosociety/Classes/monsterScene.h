//
//  monsterScene.h
//  Geosociety
//
//  Created by praveen Kumar on 29/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Geosociety_monsterScene_h
#define Geosociety_monsterScene_h
#include "cocos2d.h"
#include "CoolLabel.h"
#include "CoolSprite.h"
#include "CoolFreeform.h"
#include "menuScene.h"
#include "dataDictionary.h"
#include "StringConvertion.h"
USING_NS_CC;
class monsterLayer;
class dataDictionary;
class dataMonster;
class menuLayer;
class monsterScene: public CCScene
{
    public:
      monsterScene();
	monsterLayer * layer;
   
    monsterScene * initWithMonsterData(dataDictionary * database, int monid);


};

class monsterLayer: public CCLayer
{
        CCArray * staticItems;
        CCArray * menuItems;
    StringConvertion* convertedString;
        int slidePosition;
        int maxHeight;
        
    dataDictionary * database;

        //Touch Variables
        bool bTouchWasSlide;
        int touchStartX;
        int touchStartY;
        
public:
    monsterLayer * initWithMonsterData(dataDictionary * database,int monid);
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);

    virtual void  ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);

    virtual void ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
};


#endif
