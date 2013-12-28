//
//  gameEvent.h
//  Geosociety
//
//  Created by praveen Kumar on 30/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Geosociety_monster_h
#define Geosociety_monster_h
#include "StringConvertion.h"
#include "cocos2d.h"
#include "CoolSprite.h"
#include "menuScene.h"
#include "dataDictionary.h"

USING_NS_CC;

class dataMonster;
class monster: public CCObject
{
        
public:
    dataMonster * mon;
    
    int internalMonId;
    int position,exp,hp,hpLeft,lvl,atk,def,spd,intel,stat_points,reborn,special;
    bool bIsMale;
    
    monster * initWithMonster(dataMonster * monTemplate,int  level) ;
    void  check(dataDictionary * database);
    
    void evolve(dataDictionary * database);
    
    monster* init();
    CCString * saveToString();
    StringConvertion* convertedString;
    CCString * getImage();
    dataMonster * getMonster();
    CCString* getName();
    
    CCString* getHpString();
   CCString* getLvlString() ;
    
   /* PENDING_DEEPAK - (void)encodeWithCoder:(NSCoder *)coder;
    - (id)initWithCoder:(NSCoder *)coder;
    */

};

#endif
