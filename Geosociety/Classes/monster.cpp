//
//  gameEvent.cpp
//  Geosociety
//
//  Created by praveen Kumar on 30/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//


#include "monster.h"
/* PENDING_DEEPAK NSCODER - (void)encodeWithCoder:(NSCoder *)coder
{
    
    internalMonId = mon.monid;
    
    [coder encodeInteger:internalMonId forKey:@"internalMonId"];
    [coder encodeInteger:position forKey:@"position"];
    [coder encodeInteger:exp forKey:@"exp"];
    [coder encodeInteger:hp forKey:@"hp"];
    [coder encodeInteger:hpLeft forKey:@"hpLeft"];
    [coder encodeInteger:lvl forKey:@"lvl"];
    [coder encodeInteger:atk forKey:@"atk"];
    [coder encodeInteger:def forKey:@"def"];
    [coder encodeInteger:spd forKey:@"spd"];
    [coder encodeInteger:intel forKey:@"intel"];
    [coder encodeInteger:stat_points forKey:@"stat_points"];
    [coder encodeInteger:reborn forKey:@"reborn"];
    [coder encodeInteger:special forKey:@"special"];
    [coder encodeBool:bIsMale forKey:@"bIsMale"];
    
    
    
}

- (id)initWithCoder:(NSCoder *)coder
{
    self = [[monster alloc] init];
    if (self != nil)
    {
        
        internalMonId = [coder decodeIntegerForKey:@"internalMonId"];
        position = [coder decodeIntegerForKey:@"position"];
        exp = [coder decodeIntegerForKey:@"exp"];
        hp = [coder decodeIntegerForKey:@"hp"];
        hpLeft = [coder decodeIntegerForKey:@"hpLeft"];
        lvl = [coder decodeIntegerForKey:@"lvl"];
        atk = [coder decodeIntegerForKey:@"atk"];
        def = [coder decodeIntegerForKey:@"def"];
        spd = [coder decodeIntegerForKey:@"spd"];
        intel = [coder decodeIntegerForKey:@"intel"];
        stat_points = [coder decodeIntegerForKey:@"stat_points"];
        reborn = [coder decodeIntegerForKey:@"reborn"];
        bIsMale = [coder decodeBoolForKey:@"bIsMale"];
        
        if( [coder containsValueForKey:@"special"] ) {
            special = [coder decodeIntegerForKey:@"special"];
        }
    }   
    return self;
}
 
 */




CCString *monster:: getHpString()
{
	return CCString::createWithFormat("HP.%d/%d",hpLeft,hp);
}
CCString *monster:: getLvlString ()
{
	return CCString::createWithFormat("Lvl.%d",lvl);
}

void monster::check(dataDictionary * database)
{
    
    mon = database->monById(internalMonId);
    
}


monster *monster::init()
{
    
    return this;
}

monster *monster::initWithMonster(dataMonster * monTemplate,int level)
{
//    self = [super init];
//    if(self!= nil )
    {
        mon = monTemplate;
        
        lvl = level;
       hp = (int)(mon->hp * lvl * 1.3);
        
        double combined = mon->hp + mon->atk + mon->def + mon->spd + mon->intel;
        atk = (double)mon->atk / combined * (lvl * combined);
        def = (double)mon->def / combined * (lvl * combined);
        spd = (double)mon->spd / combined * (lvl * combined);
        intel = (double)mon->intel / combined * (lvl * combined);
        
        if( monTemplate->maleratio * 100 <= arc4random() % 100 ) 
        {
            bIsMale = true;
        }
        
        stat_points = 5;
        
        exp = lvl * lvl * lvl;
        
        hpLeft = hp;
    }
    return this;
}



CCString *monster::getName()
{
    return mon->getName();
}
dataMonster *monster::getMonster()
{
    return mon;
}

void monster::evolve(dataDictionary * database)
{
    
    internalMonId =  this->getMonster()->evolvesto;
    mon = database->monById(internalMonId);
}

CCString *monster::getImage()
{
    CCString * fullID = CCString::createWithFormat("%s%d","000",mon->monid);
    CCString * leadingZerosID = new CCString();
    leadingZerosID= convertedString->substringToIndex(fullID, fullID->length()-3); 
    CCString * fileName = CCString::createWithFormat("%s%s%s","dpffa",leadingZerosID->getCString(),".png");
    if( special == 5 ) 
    {
        fileName = CCString::createWithFormat("gold%s",fileName->getCString());
    }
    return fileName;
    return fileName;
	
}

CCString *monster::saveToString()
{
    
    return CCString::create("");
}

