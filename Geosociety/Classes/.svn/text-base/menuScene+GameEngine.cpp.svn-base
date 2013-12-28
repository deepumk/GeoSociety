////
////  menuScene+GameEngine.cpp
////  Geosociety
////
////  Created by macbookpro on 04/12/13.
////  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
////
//
//#include <iostream>
//
//#include "menuScene+GameEngine.h"
//
//
//
//
//
//
//
//void GameEngine::saveAccount()
//{
//	
//    
//	menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.POSITION",menuLayerObj->profileNumber),CCString::createWithFormat("%s,%d,%d",menuLayerObj->mapFilename->getCString(),(int)menuLayerObj->me->mapPosition.x,(int)menuLayerObj->me->mapPosition.y));
//  
//	menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.MUSIC",menuLayerObj->profileNumber),menuLayerObj->musicname);
//  
//	menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.STEPSTAKEN",menuLayerObj->profileNumber),CCString::createWithFormat("%qu",menuLayerObj->stepsTaken));
//	
//  menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.MONSTERCOUNT",menuLayerObj->profileNumber),CCString::createWithFormat("%d",menuLayerObj->monsters->count()));
//	menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.MISSIONSCOMPLETED",menuLayerObj->profileNumber),CCString::createWithFormat("%d", menuLayerObj->missionsAccomplished));
//  
//  
//	menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.CONTROL",menuLayerObj->profileNumber),CCString::createWithFormat("%d", menuLayerObj->controlMode));
//  
//	menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.CLASSFILTER",menuLayerObj->profileNumber),CCString::createWithFormat("%d", menuLayerObj->classFilter));
//  
//  
//  
//  menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.ZONE",menuLayerObj->profileNumber), menuLayerObj->zone);
//  menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.WEATHER",menuLayerObj->profileNumber),menuLayerObj->weather);
//  
//  menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.COIN",menuLayerObj->profileNumber),CCString::createWithFormat("%d",menuLayerObj->coin));
//  
//  menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.STATRESETS",menuLayerObj->profileNumber),CCString::createWithFormat("%d",menuLayerObj->statResetsRemaining));
//  menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.SEED",menuLayerObj->profileNumber),CCString::createWithFormat("%d",menuLayerObj->seed));
//  
//  menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.EXPSHARE",menuLayerObj->profileNumber),CCString::createWithFormat("%d",menuLayerObj->expSharePurchased));
//  
//  
//  
//  
//  CCUserDefault *standardUserDefaults = CCUserDefault::sharedUserDefault();
//	if (standardUserDefaults)
//  {
//        
//    CCData * data = this->dictToData(menuLayerObj->globalSettings);
//    CCString * str =(CCString*)this->base64forData(data);
//    menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.GLOBALS",menuLayerObj->profileNumber),str);
//    
//    data = this->dictToData(menuLayerObj->inventory);
//    str = this->base64forData(data);
//    menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.ITEMS",menuLayerObj->profileNumber),str  );
//    
//    data = this->dictToData(menuLayerObj->monstersSeen);
//    str = this->base64forData(data);
//    menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.MONSEEN",menuLayerObj->profileNumber),str);
//    
//    data = this->dictToData(menuLayerObj->monstersSeen);
//    str = this->base64forData(data);
//    menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.MONCAUGHT",menuLayerObj->profileNumber),str);
//     
//    
//    /*
//     tmpKey = [NSString stringWithFormat:@"USER.%d.ITEMS",profileNumber];
//     [standardUserDefaults setObject:inventory forKey:tmpKey];
//     
//     tmpKey = [NSString stringWithFormat:@"USER.%d.MONSEEN",profileNumber];
//     [standardUserDefaults setObject:monstersSeen forKey:tmpKey];
//     
//     tmpKey = [NSString stringWithFormat:@"USER.%d.MONCAUGHT",profileNumber];
//     [standardUserDefaults setObject:monstersCaught forKey:tmpKey];
//     
//     NSString * tmpKey = [NSString stringWithFormat:@"USER.%d.GLOBALS",profileNumber];
//     [standardUserDefaults setObject:globalSettings forKey:tmpKey];
//     */
//    
//   /* PENDING_DEEPAK  NSKeyedArchiver
//    data = [NSKeyedArchiver archivedDataWithRootObject:monsters];
//    str = [menuLayer base64forData:data];
//    [self saveToUserDefaults:[NSString stringWithFormat:@"USER.%d.MONSTERS",profileNumber] andValue:str  ];
//    
//    NSLog(@"Saved %d Monsters",[monsters count]);
//    
//    data = [NSKeyedArchiver archivedDataWithRootObject:availableQuests];
//    str = [menuLayer base64forData:data];
//    [self saveToStdUserDefaults:[NSString stringWithFormat:@"USER.%d.QUESTS",profileNumber] andValue:str  ];
//    
//    
//    NSLog(@"Saved %d Quests",[availableQuests count]);
//    
//    ///data = [NSKeyedArchiver archivedDataWithRootObject:filteredQuests];
//    //str = [menuLayer base64forData:data];
//    //[self saveToUserDefaults:[NSString stringWithFormat:@"USER.%d.FQUESTS",profileNumber] andValue:str  ];
//    */
//    
//    
//    
//    if( menuLayerObj->mapIsGeoRealm() )
//    {
//      //It we are in the georealm then we need to create the active quests sprites in the menuLayer array.
//      
//      //questTemplate * tmp = [filteredQuests objectAtIndex:questMenu];
//      
//      
//      menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.QUESTMENU",menuLayerObj->profileNumber),CCString::createWithFormat("%d",menuLayerObj->questMenu));
//      
//     // NSLog("Saved %d Quest Menu Item",questMenu);
//      
//      
//    } else {
//      
//      menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.QUESTMENU",menuLayerObj->profileNumber),CCString::createWithFormat("%d",-1));
//      
////      NSLog(@"Saved %d Quest Menu Item",-1);
//    }
//    
//    
//    
//    /*
//     tmpKey = [NSString stringWithFormat:@"USER.%d.MONSTERS",profileNumber];
//     [standardUserDefaults setObject:[NSKeyedArchiver archivedDataWithRootObject:monsters] forKey:tmpKey];
//     
//     
//     tmpKey = [NSString stringWithFormat:@"USER.%d.QUESTS",profileNumber];
//     [standardUserDefaults setObject:[NSKeyedArchiver archivedDataWithRootObject:availableQuests] forKey:tmpKey];
//     */
//    
//    
//    
//		//PENDING_DEEPAKstandardUserDefaults->synchronize();
//	}
//  
//  
//	return;
//	
//}
//
//
//
//
//
//CCString *GameEngine::base64forData(CCData* theData )
//{
//  
//   /* PENDING_DEEPAK  Becoz dataWithLength
//    const uint8_t* input = (const uint8_t*)theData->getBytes();
//    CCInteger length = (int)theData->getSize();
//  
//  static char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
//  
//    CCData* data = CCData::dataWithLength:((length + 2) / 3) * 4];
//  uint8_t* output = (uint8_t*)data.mutableBytes;
//  
//  CCInteger i;
//  for (i=0; i < length; i += 3) {
//    NSInteger value = 0;
//    NSInteger j;
//    for (j = i; j < (i + 3); j++) {
//      value <<= 8;
//      
//      if (j < length) {
//        value |= (0xFF & input[j]);
//      }
//      }
//      
//      NSInteger theIndex = (i / 3) * 4;
//      output[theIndex + 0] =                    table[(value >> 18) & 0x3F];
//      output[theIndex + 1] =                    table[(value >> 12) & 0x3F];
//      output[theIndex + 2] = (i + 1) < length ? table[(value >> 6)  & 0x3F] : '=';
//      output[theIndex + 3] = (i + 2) < length ? table[(value >> 0)  & 0x3F] : '=';
//      }
//      
//      return [[[NSString alloc] initWithData:data encoding:NSASCIIStringEncoding] autorelease];
//      }
//
//
//      -(NSData *) dictToData: (NSDictionary *) dict {
//        NSMutableData *data = [[NSMutableData alloc]init];
//        NSKeyedArchiver *archiver = [[NSKeyedArchiver alloc]initForWritingWithMutableData:data];
//        [archiver encodeObject:dict forKey: @"key"];
//        [archiver finishEncoding];
//        [archiver release];
//        return [data autorelease];
//      }
//      
//      -(NSDictionary *) dataToDict:(NSData *)data {
//        NSKeyedUnarchiver *unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
//        NSDictionary * dict = [unarchiver decodeObjectForKey: @"key"];
//        [unarchiver finishDecoding];
//        [unarchiver release];
//        return dict;
//      }
//
//
//*/
//}
//
//
//
//
//CCData *GameEngine::dictToData(CCDictionary * dict)
//{
//    CCData *data ;
////    NSKeyedArchiver *archiver = [[NSKeyedArchiver alloc]initForWritingWithMutableData:data];
////    [archiver encodeObject:dict forKey: @"key"];
////    [archiver finishEncoding];
////    [archiver release];
//    return data;
//}
//
//CCDictionary *GameEngine:: dataToDict(CCData *data)
//{
////    NSKeyedUnarchiver *unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
////    NSDictionary * dict = [unarchiver decodeObjectForKey: @"key"];
////    [unarchiver finishDecoding];
////    [unarchiver release];
////    return dict;
//    
//    
//}
//
//
//
//void GameEngine::loadAccount()
//{
//	menuLayerObj= new menuLayer();
//  
//	if((menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.POSITION",menuLayerObj->profileNumber))) == NULL)
//  {
//    //Error Finding Save File
//    menuLayerObj->profileDisplay();
//    return;
//  
//  } 
//  else 
//  {
//    
//    
//		CCArray * userData = new CCArray();
//    userData->addObject(convertedString->componentsSeparatedByString((CCString::createWithFormat("USER.%d.POSITION",menuLayerObj->profileNumber)), CCString::create(","))); 
//		
//    
//    
//    
//    //statResetsRemaining
//    CCString * tmpStatResets =menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.STATRESETS",menuLayerObj->profileNumber));
//    
//    if( tmpStatResets != NULL ) 
//    {
//      if( tmpStatResets->isEqual(CCString::create("")) == false )
//      {
//        menuLayerObj->statResetsRemaining = (int)tmpStatResets;
//      }
//    } 
//    else 
//    {
//      menuLayerObj->statResetsRemaining = 1;
//    }
//    
//    CCString * tmpSeed = menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.SEED",menuLayerObj->profileNumber));
//    
//    if( tmpSeed != NULL ) 
//    {
//      if( tmpSeed->isEqual(CCString::create(""))== false ) 
//      {
//        menuLayerObj->seed = (int)tmpSeed;
//      }
//    }
//    
//    
//    CCString * tmpExpShare = menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.EXPSHARE",menuLayerObj->profileNumber));
//   
//    if( tmpExpShare != NULL)
//    {
//      if( tmpExpShare->isEqual(CCString::create("")) == false )
//      {
//        menuLayerObj->expSharePurchased = (int)tmpExpShare;
//      }
//    }
//    
//    CCString * tmpClassFilter = menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.CLASSFILTER",menuLayerObj->profileNumber));
//    
//    if( tmpClassFilter != NULL ) 
//    {
//      if( tmpClassFilter->isEqual(CCString::create("")) == false ) 
//      {
//        menuLayerObj->classFilter = (int)tmpClassFilter;
//      }
//    }
//    
//    
//    
//    CCString * tmpControlMode = menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.CONTROL",menuLayerObj->profileNumber));
//    
//    if( tmpControlMode != NULL )
//    {
//      if( tmpControlMode->isEqual(CCString::create("")) == false ) 
//      {
//        menuLayerObj->controlMode = (int)tmpControlMode;
//      }
//    }
//    
//    
//    CCString * tmpQuestMenu =menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.QUESTMENU",menuLayerObj->profileNumber));
//   
//    if( tmpQuestMenu != NULL )
//    {
//      if( tmpQuestMenu->isEqual(CCString::create("")) == false )
//      {
//        menuLayerObj->questMenu = (int)tmpQuestMenu;
//      }
//    }
//    
//    
//    CCString * tmpMusicName = menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.MUSIC",menuLayerObj->profileNumber));
//    
//    if(tmpMusicName  != NULL )
//    {
//      
//     menuLayerObj->playSong(tmpMusicName->getCString());
//    }
//    
//    
//    CCString * tmpStrCoin = menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.COIN",menuLayerObj->profileNumber));
//    
//    if( tmpStrCoin != NULL ) 
//    {
//      menuLayerObj->coin = (int)tmpStrCoin;
//    } 
//    else
//    {
//      //coin = 100000;
//    }
//    
//    menuLayerObj->zone->release();
//    menuLayerObj->zone = NULL;
//    menuLayerObj->zone = CCString::create(menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.ZONE",menuLayerObj->profileNumber))->getCString());
//    
//    menuLayerObj->activeScript->addObject(convertedString->componentsSeparatedByString(CCString::createWithFormat("Set Zone\t%s^",menuLayerObj->zone->getCString()),CCString::create("\t")));
//    
//    menuLayerObj->weather->release();
//    menuLayerObj->weather = NULL;
//    menuLayerObj->weather = CCString::create(menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.WEATHER",menuLayerObj->profileNumber))->getCString());
//    
//    menuLayerObj->activeScript->addObject( convertedString->componentsSeparatedByString(CCString::createWithFormat("Change Weather\t%s^",menuLayerObj->weather->getCString()),CCString::create("\t")));
//    
//    menuLayerObj->monsters->release();
//    menuLayerObj->globalSettings->release();
//    menuLayerObj->inventory->release();
//    menuLayerObj->monsters = NULL;
//    menuLayerObj->globalSettings = NULL;
//    menuLayerObj->inventory = NULL;
//    
//    
//    
//    
//    CCUserDefault *standardUserDefaults =  CCUserDefault::sharedUserDefault();
//    if (standardUserDefaults) 
//    {
//      
//      /* PENDING_DEEPAK-BECAUSE "NSData+Base64
//      CCData *data =this->dataFromBase64String(this->retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.ITEMS",profileNumber]]];
//      inventory = [[NSMutableDictionary alloc] initWithDictionary: [self dataToDict: data]];
//      
//      data = [NSData dataFromBase64String: [self retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.MONSEEN",profileNumber]]];
//      monstersSeen = [[NSMutableDictionary alloc] initWithDictionary: [self dataToDict: data]];
//      
//      data = [NSData dataFromBase64String: [self retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.MONCAUGHT",profileNumber]]];
//      monstersCaught = [[NSMutableDictionary alloc] initWithDictionary: [self dataToDict: data]];
//      
//      data = [NSData dataFromBase64String: [self retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.GLOBALS",profileNumber]]];
//      globalSettings = [[NSMutableDictionary alloc] initWithDictionary: [self dataToDict: data]];
//      
//      
//      
//      data = [NSData dataFromBase64String: [self retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.MONSTERS",profileNumber]]];
//      monsters = [[NSMutableArray alloc] initWithArray: [NSKeyedUnarchiver unarchiveObjectWithData:data]];
//      
//      data = [NSData dataFromBase64String: [self retrieveFromStdUserDefaults:[NSString stringWithFormat:@"USER.%d.QUESTS",profileNumber]]];
//      availableQuests = [[NSMutableArray alloc] initWithArray: [NSKeyedUnarchiver unarchiveObjectWithData:data]];
//      
//      */
//      
//      for(int i=0;i<menuLayerObj->monsters->count();i++)
//      {
//        monster * mon= (monster*)menuLayerObj->monsters->objectAtIndex(i);
//        mon->check(menuLayerObj->database);
//      }
//      
//      for(int i=0;i<menuLayerObj->availableQuests->count();i++)
//      {
//        questTemplate * quest=(questTemplate*)menuLayerObj->availableQuests->objectAtIndex(i);
//        quest->reloadWithParent(menuLayerObj);
//      }
//      /*
//       if( questMenu > -1 ) {
//       [[availableQuests objectAtIndex:questMenu] addAllEvents];
//       
//       
//       }
//       */
//      
//     
//    /*   
//        CCString * tmpKey = CCString::createWithFormat("USER.%d.GLOBALS",menuLayerObj->profileNumber);
//       menuLayerObj->globalSettings-> initWithDictionary:[standardUserDefaults objectForKey:tmpKey]];
//        menuLayerObj->globalSettings
//       
//       tmpKey = [NSString stringWithFormat:@"USER.%d.ITEMS",profileNumber];
//       inventory = [[NSMutableDictionary alloc] initWithDictionary: [standardUserDefaults objectForKey:tmpKey]];
//       
//       
//       tmpKey = [NSString stringWithFormat:@"USER.%d.MONSEEN",profileNumber];
//       if( [standardUserDefaults objectForKey:tmpKey] != nil ) {
//       [monstersSeen release];
//       monstersSeen = [[NSMutableDictionary alloc] initWithDictionary: [standardUserDefaults objectForKey:tmpKey]];
//       }
//       
//       
//       tmpKey = [NSString stringWithFormat:@"USER.%d.MONCAUGHT",profileNumber];
//       if( [standardUserDefaults objectForKey:tmpKey] != nil ) {
//       [monstersCaught release];
//       monstersCaught = [[NSMutableDictionary alloc] initWithDictionary: [standardUserDefaults objectForKey:tmpKey]];
//       }
//       */
//      
//      //PENDING_DEEPAK[standardUserDefaults synchronize];
//    }
//    
//    CCString * tmpStr = CCString::create((menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.STEPSTAKEN",menuLayerObj->profileNumber)))->getCString());
//    
//    if( tmpStr !=NULL )
//    {
//      if( tmpStr->isEqual(CCString::create("")) == false ) 
//      {
//        /*PENDING_DEEPAK NSNumberFormatter * formatter = [[NSNumberFormatter alloc] init];
//        stepsTaken = [[formatter numberFromString:tmpStr] unsignedLongValue];
//        [formatter release];*/
//      }
//    }
//    
//    tmpStr = CCString::create((menuLayerObj->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.MISSIONSCOMPLETED",menuLayerObj->profileNumber)))->getCString());
//    
//    if( tmpStr != NULL ) 
//    {
//      menuLayerObj->missionsAccomplished = (int)tmpStr;
//    }
//    
//		//[self displayGame:@"seedMap.1002.14.tmx" andPosition: ccp(2,3)];
//		//PENDING_DEEPAK userData this->displayGame((CCString*)userData->objectAtIndex(0),    ccp([[userData objectAtIndex:1] intValue],[[userData objectAtIndex:2] intValue])];
//    this->displayMenuButton();
//    
//    if( menuLayerObj->mapIsGeoRealm() ) 
//    {
//      //questEvents
//      
//      //Rebuild array
//     menuLayerObj->buildQuestFilter();
//      
//      if( menuLayerObj->questMenu < menuLayerObj->filteredQuests->count())
//      {
//        questTemplate * tmp = (questTemplate*)menuLayerObj->filteredQuests->objectAtIndex(menuLayerObj->questMenu);
//        tmp->addAllEvents();
//      }
//    }
//    
//    
//    menuLayerObj->activeScript->addObject(convertedString->componentsSeparatedByString(CCString::create("Fade In\t^"), CCString::create("\t")));
//    menuLayerObj->scriptProgress();
//    
//    
//    
//    
//    
//    
//    /*
//     for(monster * mon in monsters) {
//     
//     [self sawMonster: [mon getMonster].monid];
//     [self caughtMonster: [mon getMonster].monid];
//     }
//     */
//    /* //PENDING_DEEPAK MKStoreManager [[MKStoreManager sharedManager] requestProductData];
//    [[MKStoreManager sharedManager].purchasableObjects count];*/
//	}
//}
//
//
//
//
//
//void GameEngine::displayGame(CCString * withMap,CCPoint mapPosition)
//{
//	menuLayerObj->menuStage = 999;
//	
//	menuLayerObj->menuItems->removeAllObjects();
//  
//  
//  menuLayerObj->btnTalkPosition = CCPoint((CCDirector::sharedDirector()->getWinSize().width)-40, 320-235);
//  menuLayerObj->btnRunPosition = CCPoint((CCDirector::sharedDirector()->getWinSize().width)-40,320-35);
//  
//	//[self playSong:MUSIC_INTRO];
//	menuLayerObj->spriteAtPosition(CCString::create("bg1.png"),ccp((CCDirector::sharedDirector()->getWinSize().width)/2,160),1);
//  menuLayerObj->spriteAtPosition(CCString::create("buttonTalk.png"),menuLayerObj->btnTalkPosition,41);
// menuLayerObj->spriteAtPosition(CCString::create("buttonRun.png"),menuLayerObj->btnRunPosition,41);
//  
//  menuLayerObj->btnRunOn->initWithFile(CCString::create("buttonRunOn.png"));
//  menuLayerObj->btnRunOn->addToLayer(menuLayerObj,42);
//  menuLayerObj->btnRunOn->updateOpacity(0);
//  menuLayerObj->btnRunOn->updatePosition(menuLayerObj->btnRunPosition);
//  
//  //320-285 == 35
//  
//  
//  menuLayerObj->btnScalePosition = CCPoint((CCDirector::sharedDirector()->getWinSize().width)-40, 320-290);
//  menuLayerObj->spriteAtPosition(CCString::create("ZoomIcon.png"),menuLayerObj->btnScalePosition,41);
//  
//  menuLayerObj->btnKeypad= new CoolSprite();
//  menuLayerObj->btnKeypad->initWithFile(CCString::create("dpad.png"));
//  menuLayerObj->btnKeypad->addToLayer(menuLayerObj,41);
//  
//  if( menuLayerObj->controlMode == control_mode_fixed ) 
//  {
//    menuLayerObj->keypadPosition = ccp(68,320-256);
//    menuLayerObj->btnKeypad->updatePosition(menuLayerObj->keypadPosition);
//    menuLayerObj->bKeypadOn = true;
//  } 
//  else 
//  {
//    menuLayerObj->btnKeypad->updatePosition(ccp(-999,-999));
//    
//  }
//  menuLayerObj->btnKeypad->updateOpacity(180);
//  menuLayerObj->menuItems->addObject(menuLayerObj->btnKeypad);
//  menuLayerObj->btnKeypad->updatePosition(ccp(menuLayerObj->keypadPosition.x,menuLayerObj->keypadPosition.y));
//  
//	if( menuLayerObj->clouds == NULL ) 
//  {
//		menuLayerObj->clouds = new CoolSprite();
//        menuLayerObj->clouds->initWithFile(CCString::create("clouds.png"));
//		menuLayerObj->clouds->addToLayer(menuLayerObj,29);
//		menuLayerObj->clouds->updatePosition(ccp((CCDirector::sharedDirector()->getWinSize().width)/2,320/2));
//		menuLayerObj->clouds->updateOpacity(0);
//		menuLayerObj->clouds->updateScale(1.7);
//		
//		menuLayerObj->blackOverlay = new CoolSprite();
//        menuLayerObj->blackOverlay->initWithFile(CCString::create("blackOverlay.png"));
//		menuLayerObj->blackOverlay->addToLayer(menuLayerObj,28);
//		menuLayerObj->blackOverlay->updatePosition(ccp((CCDirector::sharedDirector()->getWinSize().width)/2,320/2));
//		menuLayerObj->blackOverlay->updateOpacity(0);
//		
//		menuLayerObj->glare = new CoolSprite();
//        menuLayerObj->glare->initWithFile(CCString::create("glare.png"));
//		menuLayerObj->glare->addToLayer(menuLayerObj,28);
//		menuLayerObj->glare->updatePosition(ccp((CCDirector::sharedDirector()->getWinSize().width)/2,320/2));
//		menuLayerObj->glare->updateOpacity(0);
//		
//		menuLayerObj->blackCover =  new CoolSprite();
//        menuLayerObj->blackCover->initWithFile(CCString::create("blackCover.png"));
//		menuLayerObj->blackCover->addToLayer(menuLayerObj,28);
//		menuLayerObj->blackCover->updatePosition(ccp((CCDirector::sharedDirector()->getWinSize().width)/2,320/2));
//		menuLayerObj->blackCover->updateOpacity(255);
//    
//		menuLayerObj->redFlash = new CoolSprite();
//        menuLayerObj->redFlash->initWithFile(CCString::create("redFlash.png"));
//		menuLayerObj->redFlash->addToLayer(menuLayerObj,28);
//		menuLayerObj->redFlash->updatePosition(ccp(480/2,320/2));
//		menuLayerObj->redFlash->updateOpacity(0);
//    
//    
//		menuLayerObj->rainEmitter = new CCParticleRain();
//        menuLayerObj->rainEmitter->setTexture(CCTextureCache::sharedTextureCache()->addImage("rainParticle.png"));
//		
//		menuLayerObj->rainEmitter->setPosition(ccp(240,320));
//		//double the normal
//        menuLayerObj->rainEmitter->setEmissionRate(40);
//	
//		menuLayerObj->addChild(menuLayerObj->rainEmitter,30);
//		menuLayerObj->rainEmitter->stopSystem();
//		
//		menuLayerObj->snowEmitter =new CCParticleSnow();
//		menuLayerObj->snowEmitter->setTexture(CCTextureCache::sharedTextureCache()->addImage("snowParticle.png"));
//		menuLayerObj->snowEmitter->setPosition(ccp(240,320));
//		menuLayerObj->addChild(menuLayerObj->snowEmitter,30);
//		menuLayerObj->snowEmitter->stopSystem();
//	}
//  
//	
//	if( withMap != NULL ) 
//  {
//		this->loadMap(withMap, mapPosition);
//	} 
//  else 
//  {
//		
//	}
//  
//  int seed = rand() % 3 + 1;
//  menuLayerObj->database->seed= seed;
//	
//    gameEvent * event = menuLayerObj->eventByName( CCString::create("SYS.Game Start"));
//  if( event != NULL )
//  {
//    menuLayerObj->triggerEvent( event, false);
//  }
//  
//  //~Display Credits	^
//  
//  
//  //NSString * tmpStr = [NSString stringWithFormat:@"Display Credits\t"]; 
//  //[self addScript:[tmpStr componentsSeparatedByString:@"\t"]];
//	
//}
//
//
//
//
//void GameEngine::displayMenuButton()
//{
//  menuLayerObj->btnMenuPosition = ccp((CCDirector::sharedDirector()->getWinSize().width) - 95,320-290);
//  menuLayerObj->spriteAtPosition(CCString::create("buttonMenu.png") ,menuLayerObj->btnMenuPosition,41);
//	//[self spriteAtPosition: @"buttonOrange.png" andPosition:ccp(100+42+120,480-310-64) andZ: 41];
//	//[self freeformAtPosition:@"Menu" andStyle:FONT_WHITE fontSize:0.45 andMaxWidth:310 instant:false andPosition:ccp(100+42+3+120,480-310-64+15) andZ:45];
//}
//
//
//void GameEngine::loadMap(CCString * mapName,CCPoint mapPosition)
//{
//	
////  printf( "Load Map: %s\n", mapName->UTF8String());
//  
//  double oldScale = menuLayerObj->gameScale;
//  menuLayerObj->changeGameScaleTo(1);
//  
//	//NSURL *url = [NSURL fileURLWithPath:xmlFilename];	
//	this->resetKeys();
//	
//	if( menuLayerObj->mapFilename != NULL ) 
//  {
//		menuLayerObj->mapFilename->release();
//		menuLayerObj->mapFilename = NULL;
//	}
//	menuLayerObj->mapFilename->create(mapName->getCString());
//	
//	if( menuLayerObj->map != NULL ) 
//  {
//		menuLayerObj->removeChild(menuLayerObj->layerAbove,false);
//    menuLayerObj->layerAbove->release();
//    menuLayerObj->layerAbove = NULL;
//    
//		menuLayerObj->removeChild(menuLayerObj->map,false);
//		menuLayerObj->map->release();
//		menuLayerObj->map = NULL;
//    
//	}
//	menuLayerObj->map = new CCTMXTiledMap();
//    menuLayerObj->map->create(mapName->getCString());
//	menuLayerObj->map->setPosition(ccp(240,60));
//    menuLayerObj-> map->setScale(menuLayerObj->gameScale);
//	menuLayerObj->addChild(menuLayerObj->map,8);
//	
//  printf( "Load Map: Map Object Created\n");
//  
//  
//  
//	menuLayerObj->layerAbove = menuLayerObj->map->layerNamed("Above");
//  if( menuLayerObj->layerAbove != NULL )
//  {
//    menuLayerObj->layerAbove->retain();
//    menuLayerObj->map->removeChild(menuLayerObj->layerAbove,false);
//    menuLayerObj->addChild(menuLayerObj->layerAbove,12);
//    menuLayerObj->layerAbove->setScale(menuLayerObj->gameScale);
//  }
//  printf( "Load Map: Top Layer Isolated\n");
//  
//	menuLayerObj->me->mapPosition = mapPosition;
//	this->setMapCenter();
//	
//	menuLayerObj->mapEvents->removeAllObjects();
//  printf( "Load Map: Map Repositioned\n");
//  
//	/* PENDING_DEEPAK NSBundle
//	NSString* path = [[NSBundle mainBundle] pathForResource:mapName ofType:@"dat"];
//	NSString* content = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:NULL];
//	NSArray * dataLines = [content componentsSeparatedByString:@"\n"];
//  
//  printf( "Load Map: Event Data Loaded\n");
//	
//	for(NSString * eventStr in dataLines) {
//		if( [eventStr isEqualToString:@""] == false ) {
//			NSArray * eventData = [eventStr componentsSeparatedByString:@"|"];
//			
//			gameEvent * newEvent = [[gameEvent alloc] initWithData: eventData andLayer:self];
//			[mapEvents addObject:newEvent];
//      [newEvent scaleTo: gameScale];
//			[newEvent release];
//		}
//	}
//   */
//  printf( "Load Map: Events Created\n");
//  
//  
//  if( menuLayerObj->mapIsGeoRealm() ) 
//  {
//    printf( "Load Map: Map is in the GeoRealm\n");
//    
//    CCArray * tmpArray = CCArray::create( CCString::create(convertedString->componentsSeparatedByString(menuLayerObj->mapFilename, CCString::create("."))->getCString()));
//    if( tmpArray->count() > 2 ) 
//    {
//      menuLayerObj->mapNumber =(int)tmpArray->objectAtIndex(2);
//      
//      
//      if( menuLayerObj->filteredQuests->count() > 0 )
//      {
//        (((questTemplate*)menuLayerObj->filteredQuests->objectAtIndex(menuLayerObj->questMenu))->loadedMap(menuLayerObj->mapNumber));
//      }
//    }
//  }
//  
//  printf( "Load Map: Checking for No SYS.OnLoad Event\n");
//    if(menuLayerObj->eventByName(CCString::create( "SYS.OnLoad")) != NULL ) 
//  {
//    printf( "Load Map: SYS.OnLoad Event Found\n");
////    [self triggerEvent:[self eventByName:@"SYS.OnLoad"] onCollision: false];
//      
//      menuLayerObj->triggerEvent((gameEvent*)CCString::create("SYS.OnLoad"), false); 
//      
//  } 
//  else 
//  {
//    printf( "Load Map: No SYS.OnLoad Event Found\n");
//    
//  }
//  
//  menuLayerObj->changeGameScaleTo(oldScale);
//	
//}
//
//
//
//void GameEngine::setMapCenter()
//{
//	int width = CCDirector::sharedDirector()->getWinSize().width;
//	int height = CCDirector::sharedDirector()->getWinSize().height;
//	int ySink = 4;
//	
//	int MyX = menuLayerObj->me->mapPosition.x * 16 * menuLayerObj->gameScale;
//	int MyY = menuLayerObj->me->mapPosition.y * 16 *menuLayerObj-> gameScale;
//  
//  double mapWidth = menuLayerObj->map->getMapSize().width *menuLayerObj-> map->getTileSize().width * menuLayerObj->gameScale;
//  double mapHeight = menuLayerObj->map->getMapSize().height * menuLayerObj->map->getTileSize().height *menuLayerObj-> gameScale;
//	
//	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
//	winSize.width = width;
//	winSize.height = height;
//	
//	
//	int xTmp = MAX(MyX, winSize.width / 2);
//	int yTmp = MAX(MyY, winSize.height / 2);
//	xTmp = MIN(xTmp, mapWidth
//             - winSize.width / 2);
//	yTmp = MIN(yTmp, mapHeight 
//             - winSize.height/2);
//	CCPoint actualPosition = ccp(xTmp, yTmp);
//	
//	CCPoint centerOfView = ccp(width/2, height/2);
//	CCPoint viewPoint = ccpSub(centerOfView, actualPosition);
//	
//	int heroStepX = 0;
//	int heroStepY = 0;
//	if( menuLayerObj->heroDirection == 0 ) 
//  {
//		heroStepY = menuLayerObj->heroStepPart * menuLayerObj->gameScale;
//	} 
//  else if( menuLayerObj->heroDirection == 1 ) 
//  {
//		heroStepY = -menuLayerObj->heroStepPart *menuLayerObj-> gameScale;
//	} 
//  else if( menuLayerObj->heroDirection == 2 ) 
//  {
//		heroStepX = menuLayerObj->heroStepPart * menuLayerObj->gameScale;
//	} 
//  else if( menuLayerObj->heroDirection == 3 )
//  {
//		
//    heroStepX = -menuLayerObj->heroStepPart * menuLayerObj->gameScale;
//	}  
//	
//	
//	if( MyX-heroStepX > mapWidth - width/2)
//  {
//		heroStepX = 0;
//	}
//	if( MyX-heroStepX < width/2 ) 
//  {
//		heroStepX = 0;
//	}
//	
//	if( MyY-heroStepY > mapHeight - height/2 )
//  {
//		heroStepY=0;
//	}
//	if( MyY-heroStepY < height/2 )
//  {
//		heroStepY=0;
//	}
//	
//	
//	int additionalDown = height - mapHeight;
//	
//	menuLayerObj->mapLeft = viewPoint.x + heroStepX ;//+11;
//	menuLayerObj->mapTop =(viewPoint.y+heroStepY)*-1+additionalDown;
//	
//	//NSLog([NSString stringWithFormat:@"Map Position: %d, %d",mapLeft,mapTop]);
//  
//  if( menuLayerObj->layerAbove != NULL )
//  {
//     menuLayerObj->layerAbove->setPosition(ccp(menuLayerObj->mapLeft,menuLayerObj->mapTop));
//  }
//   
//	menuLayerObj->map->setPosition(ccp(menuLayerObj->mapLeft,menuLayerObj->mapTop));
//	menuLayerObj->clouds->updatePosition(ccp(menuLayerObj->mapLeft+(mapWidth)/2,menuLayerObj->mapTop+(mapHeight)/2));
//	menuLayerObj->blackOverlay->updatePosition(ccp(menuLayerObj->mapLeft+(mapWidth)/2,menuLayerObj->mapTop+(mapHeight)/2));
//	//User position should update as if it was an event, theirfore it should not be done in this function but rather in the gameEvent Class.
//	//me.
//	//[me updatePosition:ccp( width/2 + offsetX , height/2 + offsetY - ySink )];
//}
//
//
//void GameEngine::setGlobal(CCString * key,CCString * value)
//{
//  menuLayerObj->globalSettings->setObject(value,key->getCString());
//}
//
//
//
//bool GameEngine::getGlobalBool(CCString * key)
//{
//  CCString * value = CCString::create(menuLayerObj->globalSettings->valueForKey(key->getCString())->getCString());
//  if( value->isEqual(CCString::create("T")))
//  {
//    return true;
//  } 
//  else 
//  {
//    return false;
//  }
//}
//
//void GameEngine::updateGlobal(CCString * globalName,int action)
//{
//	if( action == 0 ) 
//  {
//		this->setGlobal(globalName,CCString::create("F"));
//	}
//  else if( action == 1 ) 
//  {
//		this->setGlobal(globalName,CCString::create("T"));
//	} 
//  else 
//  {
//		if( this->globalValue(globalName) ) 
//    {
//			this->setGlobal(globalName,CCString::create("F"));
//		} 
//    else 
//    {
//			this->setGlobal(globalName,CCString::create("T"));
//		}
//	}  
//}
//
//bool GameEngine::globalValue(CCString * globalName)
//{
//  return this->getGlobalBool(globalName);
//  /*
//   if( [self retrieveFromUserDefaults:[NSString stringWithFormat:@"GLOBAL_%d_%@",profileNumber,globalName]] == nil ) {
//   return false;
//   } else {
//   if( [[self retrieveFromUserDefaults:[NSString stringWithFormat:@"GLOBAL_%d_%@",profileNumber,globalName]] isEqualToString:@"F"] ) {
//   return false;
//   } else {
//   return true;
//   }
//   }
//   */
//}
//
//void GameEngine::eventCheck()
//{
//  for(int i=0; i<menuLayerObj->mapEvents->count();i++)
//	{
//    gameEvent * evnt= (gameEvent*)menuLayerObj->mapEvents->objectAtIndex(i); 
//		
//		if( evnt->mapPosition.x == menuLayerObj->me->mapPosition.x && evnt->mapPosition.y == menuLayerObj->me->mapPosition.y  ) 
//    {
//			if( evnt->onWalk() && evnt->isEnabled() && menuLayerObj->activeScript->count() == 0 && evnt->getScript() != NULL)
//      {
//          if( menuLayerObj->triggerEvent( evnt, false) )
//        {
//					return;
//				}
//			}
//		}
//		
//		if( evnt->isEnabled() && (evnt->onViewCollisionX1() || evnt->onViewCollisionX2() || evnt->onViewCollisionX3())  && menuLayerObj->activeScript->count()== 0 && evnt->getScript() != NULL)
//    {
//			int stepsCheck = 1;
//			if( evnt->onViewCollisionX2())
//      {
//        stepsCheck = 2;
//      }
//				
//        if( evnt->onViewCollisionX3() )
//        {
//          stepsCheck = 3;
//        }
//      for(int check = 1;check <= stepsCheck;check++) 
//          {
//            if( evnt->mapPosition.x+check == menuLayerObj->me->mapPosition.x && evnt->mapPosition.y == menuLayerObj->me->mapPosition.y && evnt->getDirection() == 3 )
//            {
//              
//              if( menuLayerObj->triggerEvent(evnt, true) ) 
//              {
//                return;
//              }
//            }
//            if( evnt->mapPosition.x-check == menuLayerObj->me->mapPosition.x && evnt->mapPosition.y ==menuLayerObj-> me->mapPosition.y && evnt->getDirection() == 2  )
//            {
//              
//              if( menuLayerObj->triggerEvent(evnt,true) )
//              {
//                return;
//              }
//            }
//            if( evnt->mapPosition.x ==menuLayerObj-> me->mapPosition.x && evnt->mapPosition.y+check == menuLayerObj->me->mapPosition.y && evnt->getDirection() == 1  )
//            {
//              
//              if( menuLayerObj->triggerEvent( evnt,true) ) {
//                return;
//              }
//            }
//            if( evnt->mapPosition.x == menuLayerObj->me->mapPosition.x && evnt->mapPosition.y-check == menuLayerObj->me->mapPosition.y && evnt->getDirection() == 0  )
//            {
//                if( menuLayerObj->triggerEvent(evnt, true) )
//               {
//                return;
//              }
//            }
//          }
//    }
//  }
//}
//
//
//
//
//
//void GameEngine::arrivedOnTile()
//{
// menuLayerObj-> stepsTaken++;
//  this->eventCheck();
//  
//  if( menuLayerObj->mapIsGeoRealm() && menuLayerObj->activeScript->count() == 0) 
//  {
//    //Check for portals between maps.
//    int newX =  menuLayerObj->me->mapPosition.x ;
//    int newY =  menuLayerObj->me->mapPosition.y ;
//    CCString * tmpStr = NULL;
//    
//    
//    if( menuLayerObj->me->mapPosition.y == 0 ) 
//    {
//      if(menuLayerObj-> mapNumber > 4 ) 
//      {
//        //Can Warp Upwards
//        newY = 46;
//        tmpStr = CCString::createWithFormat("seedMap.%s.%d.tmx",((CCString*)((CCArray*)(convertedString->componentsSeparatedByString(menuLayerObj->mapFilename, CCString::create("."))->getCString()))->objectAtIndex(1))->getCString(),menuLayerObj->mapNumber-5);
//      }
//    }
//    else if( menuLayerObj->me->mapPosition.x == 0 )
//    {
//      if(  menuLayerObj->mapNumber != 0 &&menuLayerObj-> mapNumber != 5 &&menuLayerObj-> mapNumber != 10  ) 
//      {
//        //Can Warp Left
//        newX = 46;
//        tmpStr = CCString::createWithFormat("seedMap.%s.%d.tmx",((CCString*)((CCArray*)(convertedString->componentsSeparatedByString(menuLayerObj->mapFilename, CCString::create("."))->getCString()))->objectAtIndex(1))->getCString(),menuLayerObj->mapNumber-1);
//      }
//    } else if( menuLayerObj->me->mapPosition.y == 47 ) 
//    {
//      if( menuLayerObj->mapNumber < 10 ) 
//      {
//        //Can Warp Downwards
//        newY = 1;
//        tmpStr =CCString::createWithFormat("seedMap.%s.%d.tmx",((CCString*)((CCArray*)(convertedString->componentsSeparatedByString(menuLayerObj->mapFilename, CCString::create("."))->getCString()))->objectAtIndex(1))->getCString(),menuLayerObj->mapNumber+5);
//      }
//    } else if( menuLayerObj->me->mapPosition.x == 47 )
//    {
//      if(  menuLayerObj->mapNumber != 4 && menuLayerObj->mapNumber != 9 && menuLayerObj->mapNumber != 14  )
//      {
//        //Can Warp Right
//        newX = 1;
//        tmpStr = CCString::createWithFormat("seedMap.%s.%d.tmx",((CCString*)((CCArray*)(convertedString->componentsSeparatedByString(menuLayerObj->mapFilename, CCString::create("."))->getCString()))->objectAtIndex(1))->getCString(),menuLayerObj->mapNumber+1);
//        
//      }
//    } 
//    
//    if( tmpStr != NULL ) 
//    {
//      
//      CCString * tmpCmd = CCString::createWithFormat("Relocate User\t%s^%d^%d",tmpStr->getCString(), newX, newY); 
//     
//        menuLayerObj->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpCmd, CCString::create("\t"))));
//      
//      menuLayerObj->scriptProgress();
//      
//      return;
//    }
//  }
//  
//  
//  
//  
//  
//  if( menuLayerObj->zoneMonsters->count() > 0 )
//  {
//    menuLayerObj->stepTimer++;
//    
//    int chanceOfEncounter = 0;
//    if( menuLayerObj->stepTimer < 25 ) 
//    {
//      chanceOfEncounter = 0; //0%
//    } 
//    else if( menuLayerObj->stepTimer < 35 ) 
//    {
//      chanceOfEncounter = 5; //25%
//    } 
//    else if( menuLayerObj->stepTimer < 45 )
//    {
//      chanceOfEncounter = 10; //45%
//    } 
//    else if( menuLayerObj->stepTimer < 100 )
//    {
//      chanceOfEncounter = 25; //80%
//    } 
//    
//    int result = arc4random()% 100;
//    if( result <= chanceOfEncounter && chanceOfEncounter != 0 ) {
//      menuLayerObj->stepTimer = 0;
//      //Encounter Wild Monster
//      
//      CCString * battleData = CCString::createWithFormat("TRUE^");
//      int opponentCount = rand() % 3+1;
//      for(int i=1; i<=opponentCount;i++)
//      {
//        
//        dataZoneMonster * wildMon = NULL;
//        
//        int counter = 0;
//        for(int k=0;k<menuLayerObj->zoneMonsters->count();k++)
//        {
//          dataZoneMonster * tmpMon =(dataZoneMonster*)menuLayerObj->zoneMonsters->objectAtIndex(k);
//          counter = counter + tmpMon->getMonster()->rarity * 100000;
//        }
//        result = arc4random() % counter;
//        
//        counter = 0;
//        for(int k=0;k<menuLayerObj->zoneMonsters->count();k++) 
//        {
//          dataZoneMonster * tmpMon = (dataZoneMonster*)menuLayerObj->zoneMonsters->objectAtIndex(k);
//          int oldInt = counter;
//          counter = counter + tmpMon->getMonster()->rarity * 100000;
//          if( result >= oldInt && result < counter ) 
//          {
//            wildMon = (dataZoneMonster*)menuLayerObj->zoneMonsters->objectAtIndex(k);
//          }
//        }
//        
//        int level = rand() % (wildMon->levelhigh - wildMon->levellow) + wildMon->levellow;
//        
//        if(menuLayerObj->mapIsGeoRealm() ) 
//        {
//          if( menuLayerObj->questClass() > 0 )
//          {
//            level = (int)((double)level * ((double)(menuLayerObj->questClass()/2)));
//          }
//          
//        }
//        
//        std::string tempString= battleData->getCString();
//        tempString.append(  CCString::createWithFormat("MON,%d,%d.",wildMon->monid,level)->getCString());
//        
//      }
//      
//      //DEBUG MODE
//      //return;
//      
//      if( IS_DEBUG_MODE )
//      {
//        return;
//      }
//      
//      this->battleStart((CCArray*)(convertedString->componentsSeparatedByString(battleData, CCString::create("^"))->getCString()), true);
//      
//      return;
//    }
//  }
//}
//
//
//void GameEngine::battleStart(CCArray *args,bool bWild)
//{
//  this->resetKeys();
//  menuLayerObj->resignTimer();
//  
//  menuLayerObj->bBattleStarted = true;
//  
//  /*PENDING_DEEPAK battleScene
//  
//  battleScene * bs =   new battleScene(); [[battleScene alloc] initWithParent:self andBattleData: args ];
//  [parent stopAllActions];
//  [[CCDirector sharedDirector] pushScene:[CCSplitRowsTransition transitionWithDuration:1.5 scene:bs]];
//  [bs startTimer];
//  [self battleMusicStart: bWild];
//  
//  [bs release];*/
//}
//
//
//
//bool GameEngine::tileIsFreeFromEvents(CCPoint pos)
//{
//	bool bFree = this->tileIsFreeFromEvent(menuLayerObj->me,pos);
//  if( !bFree )
//    return false;
//  for(int i=0; i<menuLayerObj->mapEvents->count();i++) 
//  {
//    gameEvent * evnt= (gameEvent*)menuLayerObj->mapEvents->objectAtIndex(i); 
//		
//    if( evnt->isEnabled() && evnt->hasAppearance())
//    {
//      bool bFree = this->tileIsFreeFromEvent(evnt,pos);
//      if( !bFree )
//        return false;
//    }
//    
//    if( evnt->spriteSize.size.width == 48 ) 
//    {
//      if( evnt->mapPosition.x-1 == pos.x && evnt->mapPosition.y == pos.y ) 
//      {
//        if( evnt->isEnabled() && evnt->hasAppearance() )
//        {
//          return false;
//        }
//      }
//    }
//	}
//	return true;
//}
//
//bool GameEngine::tileIsFreeFromEvent(gameEvent *evnt,CCPoint pos)
//{
//  //event is standing still in that cell
//  if( evnt->mapPosition.x == pos.x && evnt->mapPosition.y == pos.y )
//  {
//    return false;
//  }
//  
//  //event is walking up into the checked tile
//  if( evnt->mapPosition.x == pos.x && evnt->mapPosition.y+1 == pos.y && evnt->getDirection() == direction_up && evnt->stepPart != 0 )
//  {
//    return false;
//  }
//  
//  //event is walking down into the checked tile
//  if( evnt->mapPosition.x == pos.x && evnt->mapPosition.y-1 == pos.y && evnt->getDirection() == direction_down && evnt->stepPart != 0 ) 
//  {
//    return false;
//  }
//  
//  //event is walking left into the checked tile
//  if( evnt->mapPosition.x+1 == pos.x && evnt->mapPosition.y == pos.y && evnt->getDirection() == direction_left && evnt->stepPart != 0 ) 
//  {
//    return false;
//  }
//  
//  //event is walking right into the checked tile
//  if( evnt->mapPosition.x-1 == pos.x && evnt->mapPosition.y == pos.y && evnt->getDirection() == direction_right && evnt->stepPart != 0 ) 
//  {
//    return false;
//  }
//  return true;
//}
//
//
//
//void GameEngine::evaluateGame()
//{
//	
//	if( menuLayerObj->activeScript->count() > 0 ) 
//  {
//		  menuLayerObj->scriptCheck();
//	}
//	
//	menuLayerObj->me->evaluate();
//	menuLayerObj->heroStepPart = menuLayerObj->me->stepPart;
//	menuLayerObj->heroDirection = menuLayerObj->me->getDirection();
//	
//	
//	//No Scripts are running
//	if( menuLayerObj->activeScript->count() == 0 ) 
//  {
//		if( menuLayerObj->me->moveQueueSize() == 0 )
//    {
//			if( menuLayerObj->bKeyUp ) 
//      {
//				menuLayerObj->me->addMoveQueue(CCString::create("Up"));
//			} 
//      else if( menuLayerObj->bKeyDown )
//      {
//				menuLayerObj->me->addMoveQueue(CCString::create("Down"));
//			} else if( menuLayerObj->bKeyLeft ) 
//      {
//				menuLayerObj->me->addMoveQueue(CCString::create("Left"));
//			} 
//      else if( menuLayerObj->bKeyRight )
//      {
//				menuLayerObj->me->addMoveQueue(CCString::create("Right"));
//			}
//		}
//	}
//	
//	this->setMapCenter();
//  
//	for(int i=0;i<menuLayerObj->mapEvents->count();i++)
//  {
//    
//    gameEvent * evnt =(gameEvent*)menuLayerObj->mapEvents->objectAtIndex(i);
//		evnt->evaluate();
//	}
//}
//
//
//void GameEngine::resetKeys()
//{
//	
//	menuLayerObj->bKeyUp = false;
//	menuLayerObj->bKeyDown = false;
//	menuLayerObj->bKeyLeft = false;
//	menuLayerObj->bKeyRight = false;
//  
//}
//
//void GameEngine::touchGameStop(CCPoint  touch)
//{
//  /*
//   CGPoint btnTalkPosition;
//   CGPoint btnRunPosition;
//   CGPoint btnMenuPosition;
//   */
//  //Menu Button
//  if( menuLayerObj->activeScript->count() == 0 &&menuLayerObj-> monsters->count() > 0 )
//  {
//    CCPoint button = menuLayerObj->btnMenuPosition;
//    if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
//    {
//      if( touch.y > button.y -25 && touch.y < button.y + 25 )
//      {
//        this->resetKeys();
//        menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//       menuLayerObj-> gearMenuLayer->bIsActive = true;
//       menuLayerObj-> gearMenuLayer->bIsOnPC = false;
//       menuLayerObj-> gearMenuLayer->displayIndex();
//        menuLayerObj->gearMenuLayer->setPosition(ccp(0,0));
//        return;
//      }
//    }
//  }
//  
//  //run button
//  CCPoint button = menuLayerObj->btnRunPosition;
//	if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
//  {
//		if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//    {
//      return;
//    }
//  }
//  
//	button  = menuLayerObj->btnScalePosition;
//	if( touch.x > button.x -35 && touch.x < button.x + 35 )
//  {
//		if( touch.y > button.y -35 && touch.y < button.y + 35 )
//    {
//      if( menuLayerObj->gameScale == 1 ) 
//      {
//        menuLayerObj-> changeGameScaleTo( 2);
//      } 
//      else 
//      {
//        menuLayerObj->changeGameScaleTo( 1);
//      }
//      return;
//    }
//  }
//  
//  
//  
//  
//	button  = menuLayerObj->btnMenuPosition;
//	if( touch.x > button.x -35 && touch.x < button.x + 35 ) 
//  {
//		if( touch.y > button.y -35 && touch.y < button.y + 35 ) 
//    {
//      return;
//    }
//  }
//  
//	this->resetKeys();
//  
//  //Disable the new keypad
//  if( menuLayerObj->controlMode == control_mode_dynamic ) 
//  {
//    menuLayerObj->bKeypadOn = false;
//    menuLayerObj->btnKeypad->updatePosition(ccp(-999,-999));
//  }
//  
//}
//
//
//void GameEngine::touchGameStart(CCPoint touch)
//{
//	CCPoint button;
//  /*
//   CGPoint btnTalkPosition;
//   CGPoint btnRunPosition;
//   CGPoint btnMenuPosition;
//   */
//	
//  //Transfer the touch over to the scripting engine if scripts are running
//	if( menuLayerObj->activeScript->count() > 0 )
//  {
//      menuLayerObj->scriptTouch( touch);
//    return;
//  }
//  
//  //Check if the touch was on the Run Button
//	button = menuLayerObj->btnRunPosition;
//	if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
//  {
//		if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//    {
//			//Right
//			menuLayerObj->bKeyC = !menuLayerObj->bKeyC;
//      
//      if( menuLayerObj->bKeyC )
//      {
//        menuLayerObj->btnRunOn->updateOpacity(255);
//      } 
//      else 
//      {
//       menuLayerObj-> btnRunOn->updateOpacity(0);
//      }
//      //Exit if we had a match
//      return;
//		}
//	}
//  
//  
//	//Check for the talk button
//	button  = menuLayerObj->btnTalkPosition;
//	if( touch.x > button.x -35 && touch.x < button.x + 35 )
//  {
//		if( touch.y > button.y -35 && touch.y < button.y + 35 ) 
//    {
//			//Talk
//			
//      //Check if there is an event to talk to.
//      for(int i=0;i<menuLayerObj->mapEvents->count();i++)
//      {
//        
//        gameEvent * evnt= (gameEvent*)menuLayerObj->mapEvents->objectAtIndex(i);
//				if( evnt->isEnabled() && evnt->onTalk() && menuLayerObj->activeScript->count() == 0 && evnt->getScript() != NULL )
//        {
//					int checkX = 0;
//					int checkY = 0;
//					if( menuLayerObj->me->getDirection() == 0 ) 
//						checkY = -1;
//            if( menuLayerObj->me->getDirection() == 1 ) 
//              checkY = 1;
//              if( menuLayerObj->me->getDirection() == 2 ) 
//                checkX = -1;
//                if(menuLayerObj-> me->getDirection() == 3 ) 
//                  checkX = 1;
//                  
//                  if( evnt->mapPosition.x == menuLayerObj->me->mapPosition.x+checkX && evnt->mapPosition.y == menuLayerObj->me->mapPosition.y+checkY  )
//                  {
//                    menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//                    if( menuLayerObj->triggerEvent(evnt,false)) 
//                    {
//                      this->resetKeys();
//                      
//                    }
//                    
//                  }
//				}
//			}
//      
//      //This could cause issues later on
//      return;
//		}
//	}
//  
//  //keypadPosition
//  if( menuLayerObj->bKeypadOn ) 
//  {
//    
//    
//    int dist = 45;
//    int distThin = 15;
//    
//    
//    button = ccp(menuLayerObj->keypadPosition.x,menuLayerObj->keypadPosition.y+(dist*2));
//    if( touch.x > button.x -distThin && touch.x < button.x + distThin ) 
//    {
//      if( touch.y > button.y -dist*2 && touch.y < button.y + dist*2 ) 
//      {
//        //Up
//        menuLayerObj->bKeyUp = true;
//      }
//    }
//    button = ccp(menuLayerObj->keypadPosition.x,menuLayerObj->keypadPosition.y-(dist*2));
//    if( touch.x > button.x -distThin && touch.x < button.x + distThin ) 
//    {
//      if( touch.y > button.y -dist*2 && touch.y < button.y + dist*2 ) 
//      {
//        //Down
//        menuLayerObj->bKeyDown = true;
//      }
//      
//    }
//    button = ccp(menuLayerObj->keypadPosition.x-(dist*2),menuLayerObj->keypadPosition.y);
//    if( touch.x > button.x -dist*2 && touch.x < button.x + dist*2 )
//    {
//      if( touch.y > button.y -distThin && touch.y < button.y + distThin ) 
//      {
//        //Left
//        menuLayerObj->bKeyLeft = true;
//      }
//      
//    }
//    button = ccp(menuLayerObj->keypadPosition.x+(dist*2),menuLayerObj->keypadPosition.y);
//    if( touch.x > button.x -dist*2 && touch.x < button.x + dist*2 )
//    {
//      if( touch.y > button.y -distThin && touch.y < button.y + distThin ) 
//      {
//        //Right
//        menuLayerObj->bKeyRight = true;
//      }
//    }
//    
//  } 
//  else 
//  {
//    //Place the keypad so that movement can then be applied.
//    
//    if(menuLayerObj-> controlMode == control_mode_dynamic ) 
//    {
//      if( touch.x > 30 && touch.x < 480-120  && touch.y > 40 && touch.y < 320-40 )
//      {
//        
//        menuLayerObj->keypadPosition.x = touch.x;
//        menuLayerObj->keypadPosition.y = touch.y;
//        menuLayerObj->bKeypadOn = true;
//        menuLayerObj->btnKeypad->updatePosition(ccp(menuLayerObj->keypadPosition.x,menuLayerObj->keypadPosition.y));
//      }
//    }
//    
//    if( menuLayerObj->controlMode == control_mode_large ) 
//    {
//      int diff = 80;
//      if( touch.x > 480-diff  && touch.y > diff && touch.y < 320-diff ) 
//      {
//       menuLayerObj-> bKeyRight = true;
//      }
//      if( touch.x < diff  && touch.y > diff && touch.y < 320-diff ) 
//      {
//        menuLayerObj->bKeyLeft = true;
//      }
//      if( touch.y > 320-diff  && touch.x > diff && touch.x < 480-diff )
//      {
//        menuLayerObj->bKeyUp = true;
//      }
//      if( touch.y < diff  && touch.x > diff && touch.x < 480-diff )
//      {
//       menuLayerObj-> bKeyDown = true;
//      }
//    }
//    
//  }
//}
//
//void GameEngine::touchGameSlide(CCPoint touch)
//{
//	CCPoint button;
//	/*
//   CGPoint btnTalkPosition;
//   CGPoint btnRunPosition;
//   CGPoint btnMenuPosition;
//   */
//  
//  //run button
//  button = menuLayerObj->btnRunPosition;
//	if( touch.x > button.x -25 && touch.x < button.x + 25 )
//  {
//		if( touch.y > button.y -25 && touch.y < button.y + 25 )
//    {
//      return;
//    }
//  }
//  
//  
//	button  = menuLayerObj->btnTalkPosition;
//	if( touch.x > button.x -35 && touch.x < button.x + 35 ) 
//  {
//		if( touch.y > button.y -35 && touch.y < button.y + 35 )
//    {
//      return;
//    }
//  }
//  
//	this->resetKeys();
//	this->touchGameStart(touch);
//	
//}
//
//
//
//
//
//
//
//
//
//
