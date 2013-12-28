//
//  gameEvent.h
//  Geosociety
//
//  Created by praveen Kumar on 30/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Geosociety_battleObject_h
#define Geosociety_battleObject_h
#include "cocos2d.h"
#include "CoolSprite.h"
#include "menuScene.h"
#import "dataDictionary.h"
#import "monster.h"
#include "StringConvertion.h"

USING_NS_CC;
class dataMonster;

class battleObject:public CCObject
{
    public:
    
    battleObject();
    
    bool bPlayersTeam;
	
	int hp;
	int hpLeft;
	
	int lvl;
	int atk;
	int def;
	int spd;
	int intel;
	
	int position;
	int special;
	
	dataMonster * mon;
	monster * teamMonster;
	
	double attackPoint;
	double attackTick;
	double attackTickAdd;
	
	bool bUser;
    bool bReadyToMutate;
	
    int convincedAmount;
    
	
	menuLayer * parentLayer;
  
    StringConvertion* convertedString;
  
  battleObject * initWithMonster(monster * monster,menuLayer * parent);
  battleObject * initWithData(CCArray * data,int row,dataDictionary *  database,menuLayer * parent) ;
  CCString * getImage();
  CCString* getName();
  dataMonster *getMonster();
  monster * getTeamMonster();
  CCString* getLvlString() ;
  CCString* getHpString();
  
  bool isReady();
  void  reset();
  void advanceOne();
  void  speedOfFastestMonsterInBattle(int  monspd);
  CCString*  convince(dataItem * geoShock,double  strength);

  
  
  
  
  
  
};


#endif
