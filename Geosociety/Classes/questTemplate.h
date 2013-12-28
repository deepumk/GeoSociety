//
//  gameEvent.h
//  Geosociety
//
//  Created by praveen Kumar on 30/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Geosociety_questTemplate_h
#define Geosociety_questTemplate_h
#include "StringConvertion.h"
#include "menuScene+GameEngine.h"
#include "menuScene+Scripts.h"
#include "cocos2d.h"
#include "CoolSprite.h"
#include "menuScene.h"
#include "dataDictionary.h"
#include "monster.h"


USING_NS_CC;
class menuLayer;
class GameEngine;
class questTemplate:public CCObject
{
    
    
  
  public://0 == f - s == 6
    int questClass;
    int questStory;
    int questWeather;
    
    int missionCode;
    
    int type1Id;
    int type2Id;
    
    int mapSeed;
    
    int seededMapNo;
    bool bSnowing;
    bool bCompleted;
    
    //Not Coded
    menuLayer * parent;
    
    CCTMXTiledMap * map;
    CCPoint startingPoint;
    StringConvertion* convertedString;
    CCArray * questEvents;
    int eventCount;
    
    void  addAllEvents();
    CCString *  getDescription();
    CCString * getClass();
    CCString * getWeather();
    CCString *  getMapName() ;
    CCString * getZoneName();
    void  setupEvents() ;
    void  loadedMap(int mapNo);
    void  randomMapFromClass();
    void loadMap();
    GameEngine* gameEngineScene;
    //Event Generation
    void createTreasureChest(CCPoint  position,CCString * script);
    void createDarkBattleEvent(CCPoint  position,CCString * script,bool  bBossBattle);
    CCPoint findClearing();
    void createNPCBattleEvent(CCPoint position,CCString * script,bool  bBossBattle);
    
    void createZombieEvent(CCPoint position,CCString * script,bool bBossBattle);    
    questTemplate * init();
    questTemplate * initWithParent(menuLayer * par,int classCode,int missionNo) ; 
    
   //PENDING_DEEPAK NSCODER void encodeWithCoder:(NSCoder *)coder;
   //PENDING_DEEPAK NSCODER   -(id)initWithCoder:(NSCoder *)coder;
    void reloadWithParent(menuLayer * par) ;

    
    
};


#endif
