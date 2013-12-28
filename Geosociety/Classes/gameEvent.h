//
//  gameEvent.h
//  Geosociety
//
//  Created by praveen Kumar on 30/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Geosociety_gameEvent_h
#define Geosociety_gameEvent_h
#include "StringConvertion.h"
#include "cocos2d.h"
#include "CoolSprite.h"
#include "menuScene.h"


USING_NS_CC;
class menuLayer;
class GameEngine;
class StringConvertion;
class gameEvent:public CCObject
{
  
  public:
	menuLayer * parentLayer;
	
	CoolSprite * sprite;
	CCSpriteBatchNode *spriteSheet;
    CCRect spriteSize;
	
	CCArray * moveQueue;
	
	CCPoint mapPosition;
	
	bool bIsUser;
	
	//Movement
	int stepPart;
	int direction; 
	int stepAnimation;
	
	bool bJumping;
	double jumpYAdd;
	double jumpYAcc;
	
	//Event Properties
	CCArray * eventData;
	bool bEventEnabled;
	bool bHasAppearance;
	
    bool bHidden;
    bool bZombie;
    GameEngine* gameEngineScene;
    StringConvertion* convertedString;
    
	double gameScale;
    
    
    bool onTalk();
    CCString * getScript();
    void scaleTo(double newScale);
    void updateImage(CCString * newStyle);
    gameEvent * initWithData(CCArray * data,menuLayer * pL);
    gameEvent * initSelf(CCPoint position,menuLayer * pL);
    void evaluate();
    int getDirection();
    void processMoveQueue();
    void updatePosition();
    void loadAnimationFromSheet();
    bool isEnabled();
    bool onWalk();
    bool onViewCollisionX1();
    bool onViewCollisionX2();
    bool onViewCollisionX3();
    bool hasAppearance();
    int moveQueueSize();
    CCString * getName();
    void addMoveQueue(CCString * moveDirection) ;
    void processNPCMovement();
    bool tileIsWalkable(CCTMXTiledMap * map,CCPoint position);
    void processConditions();
    
    
};


#endif
