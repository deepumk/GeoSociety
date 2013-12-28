//
//  gameEvent.cpp
//  Geosociety
//
//  Created by praveen Kumar on 30/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//


#include "questTemplate.h"














/* PENDING_DEEPAK NSCODER
- (void)encodeWithCoder:(NSCoder *)coder
{
    
    
    NSString * aggString = @"";
    for(NSString * str in questEvents) {
        aggString = [NSString stringWithFormat:@"%@`%@",aggString,str];
    }
    [coder encodeObject:aggString forKey:@"questEventsStr"];
    
    NSLog(@"Saved quest with %d events",[questEvents count]);
    
    [coder encodeInteger:missionCode forKey:@"missionCode"];
    [coder encodeInteger:questClass forKey:@"questClass"];
    [coder encodeInteger:questStory forKey:@"questStory"];
    [coder encodeInteger:questWeather forKey:@"questWeather"];
    [coder encodeInteger:type1Id forKey:@"type1Id"];
    [coder encodeInteger:type2Id forKey:@"type2Id"];
    [coder encodeInteger:seededMapNo forKey:@"seededMapNo"];
    [coder encodeBool:bSnowing forKey:@"bSnowing"];
    [coder encodeBool:bCompleted forKey:@"bCompleted"];
    [coder encodeInteger:mapSeed forKey:@"mapSeed"];
    
    
    //[coder encodeObject:events forKey:@"questEvents"];
    //[events release];
    
}

- (id)initWithCoder:(NSCoder *)coder
{
    self = [[questTemplate alloc] init];
    if (self != nil)
    {
        
        missionCode = [coder decodeIntegerForKey:@"missionCode"];
        mapSeed = [coder decodeIntegerForKey:@"mapSeed"];
        questClass = [coder decodeIntegerForKey:@"questClass"];
        questStory = [coder decodeIntegerForKey:@"questStory"];
        questWeather = [coder decodeIntegerForKey:@"questWeather"];
        type1Id = [coder decodeIntegerForKey:@"type1Id"];
        type2Id = [coder decodeIntegerForKey:@"type2Id"];
        seededMapNo = [coder decodeIntegerForKey:@"seededMapNo"];
        bSnowing = [coder decodeBoolForKey:@"bSnowing"];
        bCompleted = [coder decodeBoolForKey:@"bCompleted"];
        
        
        if( [coder containsValueForKey:@"questEventsStr"] ) {
            NSString * eventsStr = [coder decodeObjectForKey:@"questEventsStr"];
            questEvents = [[NSMutableArray alloc] initWithArray:[eventsStr componentsSeparatedByString:@"`"]];
            [questEvents removeObjectAtIndex:0];
        } else {
            questEvents = [[NSMutableArray alloc] init];
        }
        
        NSLog(@"Loaded Quest with: %d events.",[questEvents count]);
        
        if( questStory == 2 )
            questStory = 4;
            
            map = nil;
            }   
    return self;
}*/




void questTemplate::addAllEvents()
{
    for (int i=0; i<questEvents->count(); i++)
    {
        CCString* str= (CCString*)questEvents->objectAtIndex(i);
        parent->addMapEvent(CCArray::create(convertedString->componentsSeparatedByString(str, CCString::create("|"))));
    }

}

questTemplate *questTemplate::init()
{
    
    {
        questEvents = new CCArray();
        
    }
    return this;
}

void questTemplate::reloadWithParent(menuLayer * par) 
{
    parent = par;
    if( map == NULL )
    {
        this->loadMap();
    }
}

void questTemplate::loadMap() 
{
    if( map == NULL )
    {
        
        CCString * mapName =this->getMapName();
        map = CCTMXTiledMap::create(mapName->getCString());
        
        CCArray * tmpStr =new CCArray();
        
        
        std::string FileMeasure=((CCString*)map->propertyNamed("EntrancePos"))->getCString();
        int TempNumOne=FileMeasure.size();
        char str[100];
        for (int a=0;a<=TempNumOne;a++)
        {
            str[a]=FileMeasure[a];
        } 
        char * pch;
        pch = strtok (str,",");
        
        tmpStr->addObject(CCString::create(pch));// componentsSeparatedByString:@","];
        startingPoint.x = (int)tmpStr->objectAtIndex(0);
        startingPoint.y = (int)tmpStr->objectAtIndex(1);
    }
}


questTemplate *questTemplate::initWithParent(menuLayer * par,int classCode,int missionNo)
{
//    self = [super init];
//    if( self != nil ) 
    {
        parent = par;
        missionCode = missionNo;
        questEvents = new CCArray();
        
        mapSeed = arc4random() % 1000000000;
        
        CCArray * questRatings = new CCArray();
        CCArray * possibleTypes = new CCArray(); 
        questRatings->addObject(CCString::create("F"));
        
        possibleTypes->addObject(CCString::create("1"));
        possibleTypes->addObject(CCString::create("2"));
        possibleTypes->addObject(CCString::create("7"));
        possibleTypes->addObject(CCString::create("10"));
        
       
        if( parent->getGlobalBool(CCString::create("SYS.QUEST.E.UNLOCKED")))
        {
            questRatings->addObject(CCString::create("E"));
        } 
        else if( parent->getGlobalBool(CCString::create("SYS.QUEST.D.UNLOCKED")) )
        {
            questRatings->addObject(CCString::create("D"));
        }
        else if(parent->getGlobalBool(CCString::create("SYS.QUEST.C.UNLOCKED")))
        {
            questRatings->addObject(CCString::create("C"));
        } 
        else if( parent->getGlobalBool(CCString::create("SYS.QUEST.B.UNLOCKED")))
        {
            questRatings->addObject(CCString::create("B"));
        } else if( parent->getGlobalBool(CCString::create("SYS.QUEST.A.UNLOCKED")))
        {
            questRatings->addObject(CCString::create("A"));
        } 
        else if(parent->getGlobalBool(CCString::create("SYS.QUEST.S.UNLOCKED")))
        {
            questRatings->addObject(CCString::create("S"));
        } 
       
        if( classCode == -1 ) 
        {
            questClass = arc4random() % questRatings->count();
        } 
        else
        {
            questClass = classCode;
        }
        
        if( questClass == 1 ) 
        {
            possibleTypes->addObject(CCString::create("4"));
        } 
        else if( questClass == 2 )
        {
            possibleTypes->addObject(CCString::create("9"));
        } 
        else if( questClass == 3 ) 
        {
            possibleTypes->addObject(CCString::create("6"));
            possibleTypes->addObject(CCString::create("14"));
        } 
        else if( questClass == 4 ) 
        {
            possibleTypes->addObject(CCString::create("20"));
        }
        else if( questClass == 5 ) 
        {
            possibleTypes->addObject(CCString::create("19"));
        } 
        
        this->randomMapFromClass();
        
        if( missionCode == 1 )
        {
            seededMapNo = 1000;
        } 
        else if( missionCode == 2 ) 
        {
            seededMapNo = 1001;
        } 
        else if( missionCode == 3 ) 
        {
            seededMapNo = 1002;
        }
        
        
        
        
        CCString * fullID = CCString::createWithFormat("%s%d","0000",seededMapNo);
        CCString * leadingZerosID = new CCString();
        leadingZerosID= convertedString->substringToIndex(fullID, fullID->length()-4);
        CCString * mapName = CCString::createWithFormat("seedMap.%s.6.tmx",leadingZerosID->getCString());
        
        if( missionCode > 0 ) 
        {
            mapName =CCString::createWithFormat("seedMap.%s.0.tmx",leadingZerosID->getCString());
        }
        
        map = CCTMXTiledMap::create(mapName->getCString());
        
        questStory  = arc4random() % 5 + 1;
        //1 == Defeat Dark Tamers
        //2 == Defeat Rouge Monster
        //3 == Defeat Destroy Artifact / Zombies
        //4 == Defeat Random Tamer
        //5 == Retrieve Loot.
        //6 == Special Mission.
        if( questStory == 3 ) 
        {
            //Make Zombie Mode x5 Rarer
            questStory  = arc4random() % 5 + 1;
        }
        if( questStory == 2 )
        {
            questStory = 1;
        }
        
        
        if( missionCode > 0 )
        {
            questStory = 6;
        }
        
        
        std::string FileMeasure=((CCString*)map->propertyNamed("EntrancePos"))->getCString();
        int TempNumOne=FileMeasure.size();
        char str[100];
        for (int a=0;a<=TempNumOne;a++)
        {
            str[a]=FileMeasure[a];
        } 
        char * pch;
        pch = strtok (str,",");
        
        CCArray * tmpStr = new CCArray(); 
        
        tmpStr->addObject(CCString::create(pch));
        startingPoint.x = (int)tmpStr->objectAtIndex(0);
        startingPoint.y =  (int)tmpStr->objectAtIndex(1);
        
        //bSnowing
        CCTMXLayer * layer1 = map->layerNamed("Base");
        int tileType = layer1->tileGIDAt(ccp(0,0));
        if( tileType == 535 ) 
        {
            bSnowing = true;
        }
        
        if( bSnowing )
        {
            questWeather = 5; 
        } else
        {
            questWeather = arc4random() % 5;
        }
        
        if( missionCode > 0 ) 
        {
            questWeather = 6;
        }
        
        //0 Sunny
        //1 Light Rain
        //2 Heavy Rain
        //3 Night Time
        //4 Night Rain
        //5 Snowing
        
        
        type1Id = arc4random() % possibleTypes->count();
        type2Id = arc4random() % possibleTypes->count();
        while( type2Id == type1Id )
        {
            type2Id = arc4random() % possibleTypes->count();
        }
        type1Id  = (int)possibleTypes->objectAtIndex(type1Id) ;
        type2Id  = (int)possibleTypes->objectAtIndex(type2Id);
        
        questRatings->removeAllObjects();
        questRatings->release();
        questRatings = NULL;
        
        possibleTypes->removeAllObjects();
        possibleTypes->release();
        possibleTypes = NULL;
        
    }
    return this;
}




CCString *questTemplate::getMapName()
{
    CCString * fullID = CCString::createWithFormat("%s%d","0000",seededMapNo);
    CCString * leadingZerosID = new CCString();
    leadingZerosID= convertedString->substringToIndex(fullID, fullID->length()-4);
    CCString * mapName = CCString::createWithFormat("seedMap.%s.6.tmx",leadingZerosID->getCString());
    
    if( missionCode > 0 )
    {
        mapName = CCString::createWithFormat("seedMap.%s.0.tmx",leadingZerosID->getCString());
    }
    
    return mapName;
}

CCString *questTemplate:: getZoneName()
{
    
    return  CCString::createWithFormat("%s.%s", parent->getDatabase()->getTypeFromId(type1Id)->getCString(),parent->getDatabase()->getTypeFromId(type2Id)->getCString());
}


void  questTemplate::setupEvents() 
{
    
}



void questTemplate::loadedMap(int mapNo)
{
    if( questEvents == NULL )
        questEvents = new CCArray();
        
        questEvents->removeAllObjects();
    
    //TODO: Add Events to match the story.
    CCTMXMapInfo * curMap =(CCTMXMapInfo*)parent->getMap();
    
    if( missionCode == 1 )
    {
        //Misison - no treasures as they get in the way of events.
        
        for(int i=0;i<10;i++) 
        {
            CCPoint pos = this->findClearing();
            while(  pos.y < 24 ) 
            {
                pos = this->findClearing();
            }
            this->createDarkBattleEvent(pos,NULL,false);
        } 
    } 
    else if( missionCode == 2 ) 
    {
        
        for(int i=0;i<5;i++) 
        {
            if( mapNo == 0 ) 
            {
                CCPoint pos = this->findClearing();
                this->createDarkBattleEvent(pos,NULL, false);
            }
        } 
        
        
    } 
    else if( missionCode == 3 ) 
    {
        
        for(int i=0;i<3;i++) 
        {
            if( mapNo != 9 && mapNo != 4 )
            {
                CCPoint pos = this->findClearing();
                this->createDarkBattleEvent(pos,NULL, false);
            }
        } 
        
        for(int i=0;i<5;i++)
        {
            if( mapNo != 9  && mapNo != 4 )
            {
                CCPoint pos = this->findClearing();
                if( arc4random() % 3 == 1 )
                {
                    this->createTreasureChest(pos,CCString::create("Treasure Chest\tCOIN^100^50~"));
                } 
                else
                {
                    this->createTreasureChest(pos,CCString::create("Treasure Chest\tITEM^100^100~"));
                }
            }
        }
    }
    else
    {
        //If not a mission distribute treasure boxes
        
        for(int i=0;i<3;i++)
        {
            CCPoint pos = this->findClearing();
            if( arc4random() % 3 == 1 ) 
            {
                this->createTreasureChest(pos,CCString::create("Treasure Chest\tCOIN^100^50~"));
            } 
            else
            {
                this->createTreasureChest(pos,CCString::create("Treasure Chest\tITEM^100^100~"));
            }
        }
        
    }
    
    
    int rewardCoin = 500;
    if( questClass == 0 )
    {
        
    }
    else if( questClass == 1 ) 
    {
        rewardCoin = 1000;
    } 
    else if( questClass == 2 )
    {
        rewardCoin = 1500;
    } 
    else if( questClass == 3 )
    {
        rewardCoin = 2000;
    } 
    else if( questClass == 4 ) 
    {
        rewardCoin = 2500;
    } 
    else if( questClass == 5 )
    {
        rewardCoin = 4000;
    } 
    else if( questClass == 6 ) 
    {
        rewardCoin = 5000;
    } 
    else if( questClass == 7 )
    {
        
    } 
    
    CCString * coinScript = CCString::createWithFormat("~Change Coin\tADD^%d~Display Message\tYour reward is %d Coin.^",rewardCoin,rewardCoin);
    
    
    
    if( questStory == 1 )
    {
        //CREATE 3 HELLS ANVIL NPC's
        //CREATE BOSS IF WE ARE ON THE FINAL MAP
        
        //createDarkBattleEvent
        
        for(int i=0;i<2;i++) 
        {
            CCPoint pos =this->findClearing();
            this->createDarkBattleEvent(pos,CCString::create("Treasure Chest\tCOIN^100^50~"), false);
        }
        
        if( mapNo == (int)map->propertyNamed("ExitMap"))
        { 
            CCPoint pos;
            
            std::string FileMeasure=((CCString*)map->propertyNamed("ExitPos"))->getCString();
            int TempNumOne=FileMeasure.size();
            char str[100];
            for (int a=0;a<=TempNumOne;a++)
            {
                str[a]=FileMeasure[a];
            } 
            char * pch;
            pch = strtok (str,",");
            CCArray * tmpRay = new CCArray();
            tmpRay->addObject(CCString::create(pch));
            pos.x = (int)tmpRay->objectAtIndex(0);
            pos.y = (int)tmpRay->objectAtIndex(1);
            this->createDarkBattleEvent(pos,CCString::createWithFormat("Treasure Chest\tCOIN^100^50~Display Message\tYou have Defeated the Hell's Anvil Leader of this Area!^~Display Message\tMission Complete.^~Quest Completed\t^%s~Set Zone\t~Change Weather\tNormal~Full Restore\t~Generate Quests\t^~Relocate User\tGeoSocietyHalls.tmx^27^18~Change Music\tNewGameLoop^~Save Game\t^~",coinScript->getCString()), true);
        }
    } 
    else if( questStory == 3 ) 
    {
        //CREATE 8 ZOMBIES
        //CREATE ARTIFACT IF WE ARE ON THE FINAL MAP
        
        for(int i=0;i<12;i++) 
        {
            CCPoint pos = this->findClearing();
            this->createZombieEvent(pos,NULL, false);
        }
        
        if( mapNo == (int)map->propertyNamed("ExitMap") ) 
        {
            CCPoint pos;
            std::string FileMeasure=((CCString*)map->propertyNamed("ExitPos"))->getCString();
            int TempNumOne=FileMeasure.size();
            char str[100];
            for (int a=0;a<=TempNumOne;a++)
            {
                str[a]=FileMeasure[a];
            } 
            char * pch;
            pch = strtok (str,",");
            
            CCArray * tmpRay =new CCArray();
            tmpRay->addObject(CCString::create(pch));
            pos.x = (int)tmpRay->objectAtIndex(0);
            pos.y = (int)tmpRay->objectAtIndex(1);
            this->createZombieEvent(pos,CCString::createWithFormat("Display Message\tYou have Destroyed the Zombie Artifact!^~Display Message\tMission Complete.^~Quest Completed\t^%s~Set Zone\t~Change Weather\tNormal~Full Restore\t~Generate Quests\t^~Relocate User\tGeoSocietyHalls.tmx^27^18~Change Music\tNewGameLoop^~Save Game\t^~",coinScript->getCString()),true);
        }
        
        
    } 
    else if( questStory == 4 ) 
    {
        //CREATE 3 NPC's
        //CREATE BOSS NPC IF WE ARE ON THE FINAL MAP
        
        for(int i=0;i<2;i++) 
        {
            CCPoint pos =this->findClearing();
            this->createNPCBattleEvent(pos,CCString::create("Treasure Chest\tCOIN^100^50~"),false);
        }
        
        
        if( mapNo ==  (int)map->propertyNamed("ExitMap")) 
        {
            CCPoint pos;
            std::string FileMeasure=((CCString*)map->propertyNamed("ExitPos"))->getCString();
            int TempNumOne=FileMeasure.size();
            char str[100];
            for (int a=0;a<=TempNumOne;a++)
            {
                str[a]=FileMeasure[a];
            } 
            char * pch;
            pch = strtok (str,",");
            CCArray * tmpRay = new CCArray();
            tmpRay->addObject(CCString::create(pch));
            pos.x = (int)tmpRay->objectAtIndex(0);
            pos.y = (int)tmpRay->objectAtIndex(1);
            this->createNPCBattleEvent(pos,CCString::createWithFormat("Treasure Chest\tCOIN^100^50~Display Message\tYou have Defeated the rogue GeoMonster Tamer!^~Display Message\tMission Complete.^~Quest Completed\t^%s~Set Zone\t~Change Weather\tNormal~Full Restore\t~Generate Quests\t^~Relocate User\tGeoSocietyHalls.tmx^27^18~Change Music\tNewGameLoop^~Save Game\t^~",coinScript->getCString()), true);
        }
    } 
    else if( questStory == 5 ) 
    {
        //CREATE 3 TREASURE CHESTS
        //CREATE FINAL TREASURE CHEST
        
        
        for(int i=0;i<2;i++) 
        {
            CCPoint pos = this->findClearing();
            this->createNPCBattleEvent(pos,CCString::create("Treasure Chest\tCOIN^100^50~"),false);
        }
        
        for(int i=0;i<3;i++)
        {
            CCPoint pos = this->findClearing();
            if( arc4random() % 3 == 1 )
            {
                this->createTreasureChest(pos, CCString::create("Treasure Chest\tCOIN^100^50~"));
            } 
            else
            {
                this->createTreasureChest(pos,CCString::create("Treasure Chest\tITEM^100^100~"));
            }
        }
        
        
        
        if( mapNo ==  (int)map->propertyNamed("ExitMap")) 
        {
            CCPoint pos;
            std::string FileMeasure=((CCString*)map->propertyNamed("ExitPos"))->getCString();
            int TempNumOne=FileMeasure.size();
            char str[100];
            for (int a=0;a<=TempNumOne;a++)
            {
                str[a]=FileMeasure[a];
            } 
            char * pch;
            pch = strtok (str,",");
            CCArray * tmpRay = new CCArray();
            tmpRay->addObject(CCString::create(pch));
            pos.x = (int)tmpRay->objectAtIndex(0);
            pos.y = (int) tmpRay->objectAtIndex(1);
            
            this->createTreasureChest(pos,CCString::createWithFormat("Display Message\tYou have found the missing GeoSociety Equipment!^~Display Message\tMission Complete.^~Quest Completed\t^%s~Set Zone\t~Change Weather\tNormal~Full Restore\t~Generate Quests\t^~Relocate User\tGeoSocietyHalls.tmx^27^18~Change Music\tNewGameLoop^~Save Game\t^~",coinScript->getCString()));
        }
        
    } 
    
}







CCPoint questTemplate::findClearing()
{
    CCPoint pos;
    pos.x = -3;
    pos.y = -3;
    
    CCTMXTiledMap * curMap = (CCTMXTiledMap*)parent->getMap();
	CCTMXLayer * layer1 =(CCTMXLayer*) curMap->layerNamed("Collision");
    if( layer1 != NULL)
    {
        int x = (arc4random() % 40)+4;
        int y = (arc4random() % 40)+4;
        //make sure theres a wide berth.
        while( (layer1->tileGIDAt(ccp(x,y))) !=0 || (layer1->tileGIDAt(ccp(x-1,y))) !=0  || (layer1->tileGIDAt(ccp(x+1,y))) !=0
              || (layer1->tileGIDAt(ccp(x,y-1))) !=0  || (layer1->tileGIDAt(ccp(x,y+1))) !=0  ) 
        {
            x = (arc4random() % 40)+4;
            y = (arc4random() % 40)+4;
        }
        pos.x = x;
        pos.y = y;
    }
    
    return pos;
}



void questTemplate::createZombieEvent(CCPoint position,CCString * script,bool bBossBattle)
{
    eventCount++;
    
    CCString * scriptAdd = NULL;
    CCString * scriptAppearance = NULL;
    
    if( script == NULL )
        script = CCString::create("");
        
        
        CCString * evntData = NULL;
        if( bBossBattle ) 
        {
            evntData = CCString::createWithFormat("SYS.ZOMBIE.%d.%d|Action Button|objects1.png|Up|Still|%d|%d||%s",mapSeed,eventCount,(int)position.x,(int)position.y,script->getCString());
        } 
        else
        {
            evntData = CCString::createWithFormat("SYS.ZOMBIE.%d.%d|View Collision x1|Zombie.png|Down|Fast Towards User|%d|%d||Bite\t~",mapSeed,eventCount,(int)position.x,(int)position.y);
        }
    
    std::string FileMeasure=evntData->getCString();
    int TempNumOne=FileMeasure.size();
    char str[100];
    for (int a=0;a<=TempNumOne;a++)
    {
        str[a]=FileMeasure[a];
    } 
    char * pch;
    pch = strtok (str,"|");

    
    parent->addMapEvent( CCArray::create(CCString::create(pch)));
    questEvents->addObject(evntData);
    
    
    return;
}



void questTemplate::createNPCBattleEvent(CCPoint  position,CCString *  script,bool  bBossBattle)
{
    eventCount++;
    
    CCArray * darkMonsters = new CCArray();
    if( questClass < 4 ) 
    {
        darkMonsters->addObject(CCString::create("1"));
        darkMonsters->addObject(CCString::create("4"));
        darkMonsters->addObject(CCString::create("7"));
        darkMonsters->addObject(CCString::create("10"));
        darkMonsters->addObject(CCString::create("12"));
        darkMonsters->addObject(CCString::create("15"));
        darkMonsters->addObject(CCString::create("17"));
        darkMonsters->addObject(CCString::create("19"));
        darkMonsters->addObject(CCString::create("21"));
        darkMonsters->addObject(CCString::create("23"));
        darkMonsters->addObject(CCString::create("25"));
        darkMonsters->addObject(CCString::create("27"));
        darkMonsters->addObject(CCString::create("30"));
        darkMonsters->addObject(CCString::create("32"));
        darkMonsters->addObject(CCString::create("35"));
       darkMonsters->addObject(CCString::create("37"));
    } 
    else
    {
        darkMonsters->addObject(CCString::create("581"));
        darkMonsters->addObject(CCString::create("590"));
        darkMonsters->addObject(CCString::create("618"));
        darkMonsters->addObject(CCString::create("621"));
        darkMonsters->addObject(CCString::create("624"));
        darkMonsters->addObject(CCString::create("839"));
        darkMonsters->addObject(CCString::create("841"));
        darkMonsters->addObject(CCString::create("64"));
        darkMonsters->addObject(CCString::create("67"));
        darkMonsters->addObject(CCString::create("25"));
        darkMonsters->addObject(CCString::create("27"));
        darkMonsters->addObject(CCString::create("30"));
        darkMonsters->addObject(CCString::create("32"));
    }
    
    int levellow = 3;
    int levelhigh = 6;
    int teamSize = 3;
    
    
    if( questClass == 0 ) 
    {
        
    } 
    else if( questClass == 1 )
    {
        levellow = 8;
        levelhigh = 16;
    } 
    else if( questClass == 2 ) 
    {
        levellow = 16;
        levelhigh = 22;
        teamSize = 5;
    } 
    else if( questClass == 3 ) 
    {
        levellow =20;
        levelhigh = 25;
        teamSize = 6;
    } 
    else if( questClass == 4 ) 
    {
        levellow =24;
        levelhigh = 28;
        teamSize = 7;
    }
    else if( questClass == 5 ) 
    {
        levellow = 26;
        levelhigh = 30;
        teamSize = 9;
    } 
    else if( questClass == 6 ) 
    {
        levellow = 30;
        levelhigh = 36;
        teamSize = 9;
    }
    
    if( bBossBattle )  
    {
        levellow = levellow * 1.35;
        levelhigh = levelhigh * 1.35;
        teamSize++;
        if( teamSize > 9 ) {
            teamSize = 9;
        }
    }
    
    CCString * tmpStr = CCString::create("false^");
    for(int i=0;i<teamSize;i++)
    {
        int monID = arc4random() % darkMonsters->count();
        monID = (int)darkMonsters->objectAtIndex(monID);
        int monLevel = arc4random() % (levelhigh - levellow) + levellow;
        
        
        std::string str2= tmpStr->getCString();
        tmpStr = CCString::create(str2.append((CCString::createWithFormat("MON,%d,%d.",monID,monLevel))->getCString()));
        
        if( i==2 || i==5 || i==8 ) 
        {
            std::string str3= tmpStr->getCString();
            tmpStr = CCString::create((str3.append("^")));
        }
    }
    
    CCString * scriptAdd = NULL;
    CCString * scriptAppearance = NULL;
    
    int randScript = arc4random() % 4;
    if( bBossBattle ) 
    {
        scriptAdd = CCString::createWithFormat("Display Message\tI'm taking over this GeoRealm. Do you really think you can stop me?^~Start Battle\t%s~",tmpStr->getCString());
        
        scriptAppearance = CCString::create("maleblue3.png");
    } 
    else
    {
        if( randScript == 0 ) 
        {
            scriptAdd =CCString::createWithFormat("Display Message\tWould you like to battle me?^~Start Battle\t%s~",tmpStr->getCString());
            scriptAppearance = CCString::create("maleblue2.png");
        } 
        else if( randScript == 1 ) 
        {
            scriptAdd = CCString::createWithFormat("Display Message\tMy monsters need some training will you help?^~Start Battle\t%s~",tmpStr->getCString());
            scriptAppearance =CCString::create("malegreen.png");
        } 
        else if( randScript == 2 )
        {
            scriptAdd = CCString::createWithFormat("Display Message\tAre those your Monsters, wow they look tough!^~Start Battle\t%s~",tmpStr->getCString());
            scriptAppearance = CCString::create("femalegolden.png");
        } 
        else if( randScript == 3 )
        {
            scriptAdd = CCString::createWithFormat("Display Message\tI'm keen for a fight, are you in?^~Start Battle\t%s~",tmpStr->getCString());
            scriptAppearance = CCString::create("femaledarkgray.png");
        } 
    }
    
    if( script == NULL )
        script = CCString::create("");
        
        
        
        
        CCString * evntData = NULL;
        if( bBossBattle )
        {
            evntData = CCString::createWithFormat("SYS.BATTLE.%d.%d|Action Button|%s|Down|Still|%d|%d||%sMove Event\tSYS.BATTLE.%d.%d^Hide~%s",mapSeed,eventCount,scriptAppearance->getCString(),(int)position.x,(int)position.y,scriptAdd->getCString(),mapSeed,eventCount,script->getCString());
        } 
        else 
        {
            evntData = CCString::createWithFormat("SYS.BATTLE.%d.%d|Action Button|%s|Down|Slow Random|%d|%d||%sMove Event\tSYS.BATTLE.%d.%d^Hide~%s",mapSeed,eventCount,scriptAppearance->getCString(),(int)position.x,(int)position.y,scriptAdd->getCString(),mapSeed,eventCount,script->getCString());
        }
    
    
    std::string FileMeasure=evntData->getCString();
    int TempNumOne=FileMeasure.size();
    char str[100];
    for (int a=0;a<=TempNumOne;a++)
    {
        str[a]=FileMeasure[a];
    } 
    char * pch;
    pch = strtok (str,"|");

    
    parent->addMapEvent(CCArray::create(CCString::create(pch)));
    questEvents->addObject(evntData);
    
    
    darkMonsters->release();
    return;
}





void  questTemplate::createDarkBattleEvent(CCPoint  position,CCString * script,bool  bBossBattle)
{
    eventCount++;
    
    CCArray * darkMonsters = new CCArray();
    if( questClass < 4 )
    {
         darkMonsters->addObject(CCString::create("15"));
         darkMonsters->addObject(CCString::create("27"));
         darkMonsters->addObject(CCString::create("30"));
         darkMonsters->addObject(CCString::create("54"));
         darkMonsters->addObject(CCString::create("62"));
         darkMonsters->addObject(CCString::create("66"));
         darkMonsters->addObject(CCString::create("83"));
         darkMonsters->addObject(CCString::create("85"));
         darkMonsters->addObject(CCString::create("89"));
         darkMonsters->addObject(CCString::create("91"));
         darkMonsters->addObject(CCString::create("94"));
         darkMonsters->addObject(CCString::create("161"));
         darkMonsters->addObject(CCString::create("354"));
         darkMonsters->addObject(CCString::create("360"));
         darkMonsters->addObject(CCString::create("575"));
         darkMonsters->addObject(CCString::create("577"));
         darkMonsters->addObject(CCString::create("580"));
         darkMonsters->addObject(CCString::create("823"));
    }
    else
    {
         darkMonsters->addObject(CCString::create("575"));
         darkMonsters->addObject(CCString::create("577"));
         darkMonsters->addObject(CCString::create("580"));
         darkMonsters->addObject(CCString::create("586"));
         darkMonsters->addObject(CCString::create("587"));
         darkMonsters->addObject(CCString::create("591"));
        darkMonsters->addObject(CCString::create("592"));
         darkMonsters->addObject(CCString::create("594"));
         darkMonsters->addObject(CCString::create("567"));
    }
    
    int levellow = 3;
    int levelhigh = 6;
    int teamSize = 3;
    
    
    if( questClass == 0 ) 
    {
        
    } 
    else if( questClass == 1 ) 
    {
        levellow = 8;
        levelhigh = 16;
    } 
    else if( questClass == 2 ) 
    {
        levellow = 16;
        levelhigh = 22;
        teamSize = 5;
    }  
    else if( questClass == 3 ) 
    {
        levellow =20;
        levelhigh = 25;
        teamSize = 6;
    } 
    else if( questClass == 4 ) 
    {
        levellow =24;
        levelhigh = 28;
        teamSize = 7;
    } 
    else if( questClass == 5 )
    {
        levellow = 26;
        levelhigh = 30;
        teamSize = 9;
    }
    else if( questClass == 6 ) 
    {
        levellow = 30;
        levelhigh = 36;
        teamSize = 9;
    }
    
    if( bBossBattle )  {
        levellow = levellow * 1.35;
        levelhigh = levelhigh * 1.35;
        teamSize++;
        if( teamSize > 9 )
        {
            teamSize = 9;
        }
    }
    
    CCString * tmpStr = CCString::create("false^");
    for(int i=0;i<teamSize;i++)
    {
        int monID = arc4random() % darkMonsters->count();
        monID = ((CCString*)darkMonsters->objectAtIndex(monID))->intValue();
        int monLevel = arc4random() % (levelhigh - levellow) + levellow;
        
        tmpStr = convertedString->stringByAppendingFormat(tmpStr, CCString::createWithFormat("MON,%d,%d.",monID,monLevel));
        
        
        if( i==2 || i==5 || i==8 ) 
            tmpStr = convertedString->stringByAppendingFormat(tmpStr, CCString::create("^"));
        }
    
    CCString * scriptAdd = NULL;
    int randScript = arc4random() % 4;
    if( bBossBattle ) 
    {
        scriptAdd =CCString::createWithFormat("Display Message\tI'm the Clan Leader for this Area. Time to teach you a lesson.^~Start Battle\t%s~",tmpStr->getCString());
    } 
    else 
    {
        if( randScript == 0 ) 
        {
            scriptAdd = CCString::createWithFormat("Display Message\tYour in over your head kid!^~Start Battle\t%s~",tmpStr->getCString());
        } 
        else if( randScript == 1 ) 
        {
            scriptAdd = CCString::createWithFormat("Display Message\tGet out of my way!!^~Start Battle\t%s~",tmpStr->getCString());
        }
        else if( randScript == 2 )
        {
            scriptAdd =CCString::createWithFormat("Display Message\tStop spying on us!^~Start Battle\t%s~",tmpStr->getCString());
        } 
        else if( randScript == 3 )
        {
            scriptAdd = CCString::createWithFormat("Display Message\tDamnit kid I haven't even hit my quota yet!^~Start Battle\t%s~",tmpStr->getCString());
        } 
    }
    
    if( script == NULL )
        script = CCString::create("");
        
        CCString * evntData = NULL;
        if( bBossBattle )
        {
            evntData = CCString::createWithFormat("SYS.BATTLE.%d.%d|Action Button|DarkTamer.png|Down|Still|%d|%d||%sMove Event\tSYS.BATTLE.%d.%d^Hide~%s",mapSeed,eventCount,(int)position.x,(int)position.y,scriptAdd->getCString(),mapSeed,eventCount,script->getCString());
        } else {
            evntData = CCString::createWithFormat("SYS.BATTLE.%d.%d|View Collision x3|DarkTamer.png|Down|Slow Towards User|%d|%d||%sMove Event\tSYS.BATTLE.%d.%d^Hide~%s",mapSeed,eventCount,(int)position.x,(int)position.y,scriptAdd->getCString(),mapSeed,eventCount,script->getCString());
        }
    
    
    
    
//    parent->addMapEvent(CCArray::create(CCString::create(convertedString->componentsSeparatedByString(evntData, CCString::create("|"))->getCString())));
    questEvents->addObject(evntData);
    
    
    darkMonsters->release();
    return;
}




void questTemplate::createTreasureChest(CCPoint position,CCString * script)
{
    eventCount++;
    CCString * evntData = CCString::createWithFormat("SYS.TRESURE.%d.%d|Action Button|objects1.png|Down|Still|%d|%d||%sMove Event\tSYS.TRESURE.%d.%d^Hide~",mapSeed,eventCount,(int)position.x,(int)position.y,script->getCString(),mapSeed,eventCount);
    
    
    std::string FileMeasure=evntData->getCString();
    int TempNumOne=FileMeasure.size();
    char str[100];
    for (int a=0;a<=TempNumOne;a++)
    {
        str[a]=FileMeasure[a];
    } 
    char * pch;
    pch = strtok (str,"|");
    
    parent->addMapEvent( CCArray::create(convertedString->componentsSeparatedByString(evntData, CCString::create("|"))));
    questEvents->addObject(evntData);
    return;
}

CCString *questTemplate::getWeather()
{
    if( questWeather == 0 )
    {
        return CCString::createWithFormat("Sunny and Bright");
    } 
    else if( questWeather == 1 )
    {
        return CCString::createWithFormat("Light Drizzle");
    } 
    else if( questWeather == 2 ) 
    {
        return CCString::createWithFormat("Heavy Rain");
    } 
    else if( questWeather == 3 ) 
    {
        return CCString::createWithFormat("Midnight");
    } 
    else if( questWeather == 4 )
    {
        return CCString::createWithFormat("Heavy Rain at Midnight");
    } 
    else if( questWeather == 6 ) 
    {
        return CCString::createWithFormat("Mission Indoors");
    } 
    else 
    {
        return CCString::createWithFormat("Snowing - A Winter Wonderland.");
    } 
}

CCString *questTemplate:: getDescription()
{
    if( questStory == 1 )
    {
        return CCString::createWithFormat("Stop Hell's Anvil Activty in the Area.");
    } 
    else if( questStory == 2 )
    {
        return CCString::createWithFormat("Defeat the Dominant GeoMonster.");
    } 
    else if( questStory == 3 )
    {
        return CCString::createWithFormat("Destroy a Soul Artifact. Avoid the Zombies.");
    } 
    else if( questStory == 4 ) 
    {
        return CCString::createWithFormat("Defeat a rogue GeoTamer.");
    } 
    else if( questStory == 6 )
    {
        return CCString::createWithFormat("Mission Unknown.");
    } 
    else 
    {
        return CCString::createWithFormat("Retrieve Loot left by a fellow GeoSociety Member.");
    } 
}

CCString *questTemplate::getClass()
{
    if( questClass == 0 ) 
    {
        return CCString::createWithFormat("F");
    } 
    else if( questClass == 1 ) 
    {
        return CCString::createWithFormat("E");
    } 
    else if( questClass == 2 )
    {
        return CCString::createWithFormat("D");
    }
    else if( questClass == 3 ) 
    {
        return CCString::createWithFormat("C");
    }
    else if( questClass == 4 ) 
    {
        return CCString::createWithFormat("B");
    } 
    else if( questClass == 5 )
    {
        return CCString::createWithFormat("A");
    } 
    else 
    {
        return CCString::createWithFormat("S");
    } 
}



void questTemplate::randomMapFromClass()
{
    
    int rangeLow = 1;
    int rangeHigh = 40;
    
    if( questClass == 0 ) 
    {
        rangeLow = 1;
        rangeHigh = 40;
    } 
    else if( questClass == 1 ) 
    {
        rangeLow = 41;
        rangeHigh = 80;
    }
    else if( questClass == 2 ) 
    {
        rangeLow = 81;
        rangeHigh = 120;
    } 
    else if( questClass == 3 ) 
    {
        rangeLow = 121;
        rangeHigh = 160;
    } 
    else if( questClass == 4 )
    {
        rangeLow = 161;
        rangeHigh = 200;
    } 
    else if( questClass == 5 ) 
    {
        rangeLow = 201;
        rangeHigh = 240;
    } 
    else if( questClass == 6 ) 
    {
        rangeLow = 241;
        rangeHigh = 280;
    } 
    
    seededMapNo = arc4random() % (rangeHigh - rangeLow) + rangeLow;
}





















