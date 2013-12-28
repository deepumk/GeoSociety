//
//  menuScene.h
//  Geosociety
//
//  Created by Deepak on 21/11/13.
//
//

#ifndef __Geosociety__dataDictionary__
#define __Geosociety__dataDictionary__

#include <iostream>
#include "cocos2d.h"
#include "CoolInput.h"
#include "CoolFreeform.h"
#include "SimpleAudioEngine.h"
#include "StringConvertion.h"



class dataMonster;
class dataItem;
class dataSkill;
class dataZoneMonster;
USING_NS_CC;
class dataDictionary: public CCObject 
{
    public:
    CCArray * monsters;
	CCArray * items;
    int seed;
    

    void getMonstersOfType(CCString *type,CCArray * array);
    dataDictionary * init();
    dataMonster * monById(int monid);
    dataItem * itemById(int itemid);
    dataItem * getItemForValue(int value) ;
    CCArray *  getAttacksForMonster(int monid, int intel);
    dataSkill *  getAttackForId(int skillid);
    double typeModFor(int atkType,int defType);
    void loadZoneInto(CCArray * zoneArray ,CCString * zone);
    CCString *getTypeFromId(int typeId);
    CCString * typeFromNumber(int no);
    void readMonsters();
    void readItems();

};




class dataSkill: public CCObject
{
    
    
    public:
        CCString * name;
        
        int skillid,hits,scope,element_type_id;
        double power,evomultiplier,accuracy;

   //PENDING_DEEPAK dataSkill * init(sqlite3_stmt * stmt);
    CCString * getName();
    CCString * getScope();
    bool isBattleItem();
    int getTypeId();

};

class dataItem : public CCObject
{
	public:
    int itemid;
	CCString * name;
	CCString * scope;
	CCString * description;
    
	int buyPrice;
	int sellPrice;
	

   //PENDING_DEEPAK -(dataItem *) init: (sqlite3_stmt *) stmt;
    CCString * getDescription();
    CCString * getName();
    CCString * getScope();
    bool isBattleItem();
};


class dataZoneMonster :public cocos2d::CCObject
{
    
    
public:
        int monid,levellow,levelhigh;
        dataMonster * mon;

 //PENDING_DEEPAK  dataZoneMonster * init(sqlite3_stmt * stmt ,dataDictionary * parent);
    //-(dataZoneMonster *) init: (sqlite3_stmt *) stmt
    dataMonster * getMonster();

};



class dataMonster: public CCObject
{
        
    
public:
    int monid;
	CCString * name;
    
	CCString * type1;
	CCString * type2;
	CCString * category;
    dataDictionary * parentObj;
    
	int hp,atk,def,spd,intel;
	
	int exp,evolvelvl,evolvesto,evolutionlvl,tamedifficulty,type1Id,type2Id;
	double maleratio,rarity;
    
    StringConvertion* convertedString;
    
    
   // PENDING_DEEPAK -(dataMonster *) init: (sqlite3_stmt *) stmt andDatabase: (dataDictionary *) parent;
    //-(dataMonster *) init: (sqlite3_stmt *) stmt;
   
    CCString * getImage() ;
    CCString *get3DigitNo();
    CCString* getName();
    CCString* getType1();
    CCString* getType2();
    CCString* getCategory();
    
    
};





#endif /* defined(__Geosociety__menuScene__) */
