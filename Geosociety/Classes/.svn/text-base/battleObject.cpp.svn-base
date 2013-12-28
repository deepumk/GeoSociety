//
//  gameEvent.cpp
//  Geosociety
//
//  Created by praveen Kumar on 30/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//


#include "battleObject.h"




battleObject::battleObject()
{
    
}


battleObject *battleObject::initWithData(CCArray * data,int row,dataDictionary *  database,menuLayer * parent) 
{
//	self = [super init];
//	if( self != nil )
//  
  {
		parentLayer = parent;    
    if( (convertedString->lowercaseString(((CCString*)data->objectAtIndex(0))))->isEqual(CCString::create("mon"))) 
    {
			mon = database->monById((int)data->objectAtIndex(1));;
			
			lvl = (int)data->objectAtIndex(2);
			hp = (int)(mon->hp * lvl * 1.3);
			
			double combined = (mon->hp + mon->atk + mon->def + mon->spd + mon->intel) * 2;
			atk = (double)mon->atk / combined * (lvl * combined);
			def = (double)mon->def / combined * (lvl * combined);
			spd = (double)(mon->spd / combined * (lvl * combined)) * 1.5;
			intel = (double)mon->intel / combined * (lvl * combined);
			
      special = 0;
      int result = arc4random() % 8080;
      if( result == 1 ) {
        special = 5;
        atk = atk * 1.1;
        def = def * 1.1;
        spd = spd * 1.1;
        intel = intel * 1.1;
      }
      
      convincedAmount = mon->tamedifficulty;
      
      //convincedAmount
		}
		hpLeft = hp;
		attackPoint = 400;
	}
	return this;
}






dataMonster *battleObject::getMonster()
{
  return mon;
}
monster *battleObject::getTeamMonster()
{
  return teamMonster;
}

CCString *battleObject::convince(dataItem * geoShock,double strength)
{
  int typeForGS = 0;
  int convinceEffect = 0;
  
  if( geoShock->itemid == 1 )
  {
    typeForGS = 7;
  } 
  else if( geoShock->itemid == 2 ) 
  {
    typeForGS = 2;
  } 
  else if( geoShock->itemid == 3 ) 
  {
    typeForGS = 1;
  } 
  else if( geoShock->itemid == 4 ) 
  {
    typeForGS = 6;
  } 
  else if( geoShock->itemid == 5 ) 
  {
    typeForGS = 14;
  } 
  else if( geoShock->itemid == 6 ) 
  {
    typeForGS = 4;
  }
  else if( geoShock->itemid == 7 ) 
  {
    typeForGS = 10;
  } 
  else if( geoShock->itemid == 8 )
  {
    typeForGS = 21;
  }
  else if( geoShock->itemid == 9 )
  {
    typeForGS = 22;
  } 
  else if( geoShock->itemid == 10 ) 
  {
    typeForGS = 19;
  } 
  else if( geoShock->itemid == 11 ) 
  {
    typeForGS = 9;
  } 
  else if( geoShock->itemid == 12 ) 
  {
    typeForGS = 20;
  } 
  else if( geoShock->itemid == 30 ) 
  {
    typeForGS = 0;
  }  
  
  
  if( typeForGS == mon->type1Id ) 
  {
    convinceEffect = 35;
  } 
  else if( typeForGS == mon->type2Id ) 
  {
    convinceEffect = 15;
  } 
  else if( typeForGS == 0 ) 
  {
    convinceEffect = 45;
  }
  
  convincedAmount = convincedAmount - ((double)convinceEffect) * strength;
  
  if( ((double)convinceEffect) * strength == 0 ) 
  {
    return CCString::createWithFormat("The GeoShock didn't effect %s at all.",mon->getName()->getCString());
  }
  else if( ((double)convinceEffect) * strength < 15 ) 
  {
    return CCString::createWithFormat("%s seems a bit less agitated by you.",mon->getName()->getCString());
  } 
  else if( ((double)convinceEffect) * strength <= 25 ) 
  {
    return CCString::createWithFormat("%s appeared to enjoy that.",mon->getName()->getCString());
  } 
  else if( ((double)convinceEffect) * strength <= 40 ) 
  {
    return CCString::createWithFormat("%s appears to be more relaxed.",mon->getName()->getCString());
  } 
  else if( ((double)convinceEffect) * strength <= 45 )
  {
    return CCString::createWithFormat("%s seems to like you more.",mon->getName()->getCString());
  } 
  return CCString::createWithFormat("%s appears indifferent.",mon->getName()->getCString());
}





battleObject *battleObject::initWithMonster(monster * monster, menuLayer * parent)
{
//	self = [super init];
//	if( self != nil )
  {
		parentLayer = parent;
    
    mon = monster->getMonster();
    teamMonster = monster;
    
    lvl = monster->lvl;
    hp = monster->hp;
    special = monster->special;
    
    atk = monster->atk;
    def = monster->def;
    spd = monster->spd;
    intel = monster->intel;
    
    position = monster->position;
    
		hpLeft = monster->hpLeft;
		attackPoint = 400;
	}
	return this;
}

CCString *battleObject::getImage()
{
	if( mon != NULL )
  {
		CCString * fullID = CCString::createWithFormat("%s%d","000",mon->monid);
      CCString * leadingZerosID =convertedString->substringToIndex(fullID, fullID->length()-3);
		CCString * fileName = CCString::createWithFormat("%s%s%s","dpffa",leadingZerosID->getCString(),".png");
    
    if( special == 5 )
    {
      fileName = CCString::createWithFormat("gold%s",fileName->getCString());
    }
		return fileName;
	} 
  else 
  {
		if( bUser ) 
    {
			return CCString::create("");
		} 
    else 
    {
			return CCString::create("80-26.png");
		}
	}
}

CCString *battleObject:: getHpString ()
{
	return CCString::createWithFormat("HP.%d/%d",hpLeft,hp);
}
CCString *battleObject::getLvlString()
{
	return CCString::createWithFormat("Lvl.%d",lvl);
}

CCString *battleObject::getName()
{
	if( mon != NULL ) 
  {
		return mon->getName();
	} 
  else 
  {
		return CCString::create("");
	}
}


void battleObject::speedOfFastestMonsterInBattle(int monspd )
{
	attackTickAdd = (double)((double)spd / (double)monspd) * (double)2;
}

bool battleObject::isReady()
{
	if( attackTick >= attackPoint ) 
  {
		return true;
	}
	return false;
}
void battleObject::reset()
{
	attackTick = 0;
}
void battleObject::advanceOne()
{
	attackTick=attackTick+attackTickAdd;
}









