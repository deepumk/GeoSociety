////
////  menuScene+Scripts.cpp
////  Geosociety
////
////  Created by macbookpro on 05/12/13.
////  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
////
//
//#include <iostream>
//#include "menuScene+Scripts.h"
//
//
//
//
//
//
//gameEvent *Scripts::eventByName(CCString *eventName)
//{
//  for(int i=0; i<menuLayerObj->mapEvents->count();i++)
//  {
//    gameEvent * evnt= (gameEvent*)menuLayerObj->mapEvents->objectAtIndex(i);
//		if((evnt->getName())->isEqual(eventName)) 
//    {
//			return evnt;
//    }
//	}
//  return NULL;
//}
//void Scripts:: addScript(CCArray * data)
//{
//  menuLayerObj->activeScript->addObject(data);
//}
//
//bool Scripts::triggerEvent(gameEvent * event,bool fromCollision)
//{
//	if( event->bEventEnabled )
//  {
//    
//    if( menuLayerObj->lastTriggeredEventName != NULL )
//    {
//      menuLayerObj->lastTriggeredEventName->release();
//      menuLayerObj->lastTriggeredEventName = NULL;
//    }
//    menuLayerObj->lastTriggeredEventName = CCString::create(event->getName()->getCString());
//    
//		CCString * script = CCString::create(event->getScript()->getCString());
//		CCArray * scriptLines =  CCArray::create(CCString::create(convertedString->componentsSeparatedByString(script, CCString::create("~"))->getCString()));
//    for(int i=0; i<scriptLines->count();i++)
//    {
//      CCString * functionLine= (CCString*)scriptLines->objectAtIndex(i); 
//			if( functionLine->isEqual(CCString::create("")) == false )
//      {
//				menuLayerObj->activeScript->addObject((CCString::create(convertedString->componentsSeparatedByString(functionLine, CCString::create("\t"))->getCString())));
//			}
//		}
//		if( menuLayerObj->activeScript->count() > 0 )
//    {
//			this->scriptProgress();
//			return true;
//		} 
//    else 
//    {
//			return false;
//		}
//		
//	}
//	return false;
//}
//
//
//
//
//
//void Scripts::scriptProgress()
//{
//	//eventObjects
//	menuLayerObj->eventObjects->removeAllObjects();
//	
//	if( menuLayerObj->activeScript->count() == 0 )
//  {
//		return;
//	}
//	
//	CCArray * scriptToExecute = CCArray::create(menuLayerObj->activeScript->objectAtIndex(0));
//	CCArray * args =   CCArray::create(CCString::create(convertedString->componentsSeparatedByString((CCString*)scriptToExecute->objectAtIndex(1), CCString::create("^"))->getCString()));
//	
//	if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Display Message")))
//  {
//		
//		
//		CoolSprite * tmpSpt = NULL;
//		
//		if((((CCString*)args->objectAtIndex(1))->isEqual(CCString::create(""))))
//    {
//			CoolFreeform * tmpFF = new CoolFreeform();
//      tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(0),FONT_WHITE,0.35,360,false);
//			tmpFF->updatePosition(ccp(54,320-32));
//			tmpFF->addToLayer(this,35);
//			menuLayerObj->eventObjects->addObject(tmpFF);
//			tmpFF->release();
//		} 
//    else 
//    {
//			CoolFreeform * tmpFF = new CoolFreeform();
//     tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(0),FONT_WHITE,0.35,280,false);
//			tmpFF->updatePosition(ccp(144,320-32));
//			tmpFF->addToLayer(this,35);
//			menuLayerObj->eventObjects->addObject(tmpFF);
//			tmpFF->release();
//			
//			tmpSpt =new CoolSprite();
//     tmpSpt->initWithFile((CCString*)args->objectAtIndex(1));
//			tmpSpt->updatePosition(ccp(96,320-80));
//			tmpSpt->updateOpacity(255);
//			tmpSpt->addToLayer(this,36);
//			menuLayerObj->eventObjects->addObject(tmpSpt);
//			tmpSpt->release(); 
//			
//		}
//		
//		if( ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04.png")))  || ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04-1.png"))) || ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04-2.png")))  || ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04-3.png")))  || ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04-4.png")))) 
//    {  //chatBlue.png 80-04.png
//			tmpSpt->initWithFile(CCString::create("speechBubble.png"));
//		} 
//    else 
//    {
//			tmpSpt->initWithFile(CCString::create("speechBubble.png"));
//		}
//		tmpSpt->updatePosition(ccp(240,320-80));
//		tmpSpt->updateOpacity(255);
//		tmpSpt->addToLayer(this,34);
//		menuLayerObj->eventObjects->addObject(tmpSpt);
//		tmpSpt->release(); 
//		
//    menuLayerObj->bTalkButtonTouched = false;
//    
//  } 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Monster Farm"))))
//  {
//    
//    menuLayerObj->farmMenuState = 0;
//    
//		CoolSprite * tmpSpt = NULL;
//    CoolFreeform * tmpFF = NULL;
//    
//    tmpFF->initWithCoolSheet(CCString::create("What would you like to do?"),FONT_WHITE,0.35,280,true);
//    tmpFF->updatePosition(ccp(54,320-32));
//    tmpFF->addToLayer(this,35);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpSpt->initWithFile(CCString::create("speechBubble.png"));
//    tmpSpt->updatePosition(ccp(240,320-80));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,34);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//    tmpFF->initWithCoolSheet(CCString::create("Return"),FONT_WHITE,0.35,200,false);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240-54,320-80-100));
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpFF ->initWithCoolSheet(CCString::create("Give"),FONT_WHITE,0.35,200,false);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240+54,320-80-100));
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpSpt ->initWithFile(CCString::create("buttonGreen.png"));
//    tmpSpt->updatePosition(ccp(240-54,320-80-110));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,36);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//    tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
//    tmpSpt->updatePosition(ccp(240+54,320-80-110));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,36);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//    tmpFF->initWithCoolSheet(CCString::create("Leave"),FONT_WHITE,0.35,200,false);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240+54,320-80-100-80));
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpSpt->initWithFile(CCString::create("buttonOrange.png"));
//    tmpSpt->updatePosition(ccp(240+54,320-80-110-80));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,36);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Bite"))))
//  {
//    menuLayerObj->redFlash->updateOpacity(100);
//    menuLayerObj->redFlash->intTag1 = 100;
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("IAP"))))
//  {
//    
//    menuLayerObj->bIAPPurchasing = false;
//    menuLayerObj->bIAPShowing = false;
//    menuLayerObj->bQuestionAnswered= false;
//    
//    
//   /* PENDING_DEEPAK  MKStoreManager
//    
//    if( [MKStoreManager sharedManager].bRequestErrorOccured ) {
//      
//      [self updateGlobal:@"SYSYesNoAnswer" withAction:0];
//      [activeScript removeObjectAtIndex:0];
//      [activeScript insertObject:  [[NSString stringWithFormat:@"Display Message\tPlease try again in 30min by restarting the Application.^"] componentsSeparatedByString:@"\t"]  atIndex:0];
//      [activeScript insertObject:  [[NSString stringWithFormat:@"Display Message\tErrors occured while Retrieving Product Data.^"] componentsSeparatedByString:@"\t"]  atIndex:0];
//      [self scriptProgress];
//      
//    } else {
//      
//      //Make a Call to Load the Store.
//      [[MKStoreManager sharedManager] setParent: self];
//      
//      CoolFreeform * tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Retrieving Product Details..." fontName:FONT_WHITE fontSize:0.35 andMaxWidth:200 instant:false];
//      [tmpFF updatePosition:ccp(48,320-32)];
//      [tmpFF addToLayer:self z:35];
//      [eventObjects addObject:tmpFF];
//      [tmpFF release];
//      
//      CoolSprite * tmpSpt = [[CoolSprite alloc] initWithFile:@"speechBubble.png"];
//      [tmpSpt updatePosition:ccp(240,320-80)];
//      
//      [tmpSpt updateOpacity:255];
//      [tmpSpt addToLayer:self z:34];
//      [eventObjects addObject:tmpSpt];
//      [tmpSpt release]; 
//      
//    } */
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Flash Red"))))
//  {
//    menuLayerObj->redFlash->updateOpacity(100);
//    menuLayerObj->redFlash->intTag1 = 100;
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Save Game"))))
//  {
//    gameEngine->saveAccount();
//    
//    menuLayerObj->activeScript->removeObjectAtIndex(0);
//    this->scriptProgress();
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Change Music"))) )
//  {
//    menuLayerObj->playSong(((CCString*)args->objectAtIndex(0))->getCString());
//    
//    menuLayerObj->activeScript->removeObjectAtIndex(0);
//    this->scriptProgress();
//    
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Display Credits"))))
//  {
//    this->showCredits();
//    
//    //PENDING_DEEPAK [Flurry logEvent:@"Displayed Credits"];
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Ask Yes or No"))))
//  {
//    
//		CoolSprite * tmpSpt = nil;
//    CoolFreeform * tmpFF = nil;
//    
//    
//    
//    tmpFF->initWithCoolSheet(CCString::create("Yes"),FONT_WHITE,0.35,200,false);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240-54,320-80-100));
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpFF->initWithCoolSheet(CCString::create("No"),FONT_WHITE,0.35,200,false);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240+54,320-80-100));
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    
//    tmpSpt->initWithFile(CCString::create("buttonGreen.png"));
//    tmpSpt->updatePosition(ccp(240-54,320-80-110));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,36);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//    tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
//    tmpSpt->updatePosition(ccp(240+54,320-80-110));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,36);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//		menuLayerObj->bQuestionAnswered = false;
//    menuLayerObj->bTalkButtonTouched = false;
//    
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Mutate Monster at Position"))))
//  {
//    CoolSprite * tmpSpt = NULL;
//    for(int i=0; i<menuLayerObj->monsters->count();i++)
//    {
//      monster * mon=(monster*)menuLayerObj->monsters->objectAtIndex(i); 
//      if( mon->position == ((int)args->objectAtIndex(0)))
//      {
//        if( mon->lvl >= mon->getMonster()->evolvelvl)
//        {
//         
//          /* PENDING_DEEPAK Flurry
//          [Flurry logEvent:@"Monster Evolved" withParameters:
//           [NSDictionary dictionaryWithObjectsAndKeys:
//            [NSString stringWithFormat:@"%d",[mon getMonster].monid],@"Monster Id",
//            [mon getName],@"Monster Name",
//            nil] ];*/
//          
//          
//         menuLayerObj->sawMonster(mon->getMonster()->evolvesto);
//          menuLayerObj->caughtMonster(mon->getMonster()->evolvesto);
//          
//          tmpSpt->initWithFile(mon->getImage());
//          tmpSpt->updatePosition(ccp(240,320-120));
//          tmpSpt->intTag1 = 255;
//          tmpSpt->updateOpacity(255);
//          tmpSpt->addToLayer(this,36);
//          menuLayerObj->eventObjects->addObject(tmpSpt);
//          tmpSpt->release(); 
//          
//          dataMonster * evoTo = menuLayerObj->database->monById(mon->getMonster()->evolvesto);
//          tmpSpt->initWithFile(evoTo->getImage());
//          tmpSpt->intTag1 = 0;
//          tmpSpt->updatePosition(ccp(240,320-120));
//          tmpSpt->updateOpacity(0);
//          tmpSpt->addToLayer(this,36);
//          menuLayerObj->eventObjects->addObject(tmpSpt);
//          tmpSpt->release(); 
//          
//          mon->evolve(menuLayerObj->database);
//          
//        }
//      }
//    }
//    
//    
//	} else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Play Sound"))))
//  {
//    if( ((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Door"))))
//    {
//      menuLayerObj->sfx(CCString::create(SOUND_DOOR));
//    }
//    
//    menuLayerObj->activeScript->removeObjectAtIndex(0);
//   this->scriptProgress();
//    
//    
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Start Storyline Mission"))))
//  {
//    
//    questTemplate * tmpQuest = NULL;
//    
//    for(int i=0; i<menuLayerObj->availableQuests->count();i++)
//    {
//      questTemplate * tmpQ= (questTemplate*)menuLayerObj->availableQuests->objectAtIndex(i); 
//      if( tmpQ->missionCode == ((int)args->objectAtIndex(0)))
//      {
//        tmpQuest = tmpQ;
//      }
//    }
//    
//    if( tmpQuest == NULL ) 
//    {
//      tmpQuest->initWithParent(menuLayerObj,3, 2);
//      menuLayerObj->availableQuests->addObject(tmpQuest);
//      tmpQuest->release();
//    }
//    
//    tmpQuest->setupEvents();
//    
//    CCString * tmpStr =NULL;
//    
//    tmpQuest->reloadWithParent( menuLayerObj);
//    
//    
//    tmpStr = CCString::createWithFormat("Fade Out\t^"); 
//    this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//    
//    
//    tmpStr =CCString::createWithFormat("Relocate User\t%@^%d^%d",tmpQuest->getMapName() , (int)tmpQuest->startingPoint.x , (int)tmpQuest->startingPoint.y); 
//    this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//    
//    if( tmpQuest->questWeather == 0 ) 
//    {
//      tmpStr = CCString::createWithFormat("Change Weather\tGlare^"); 
//    } 
//    else if( tmpQuest->questWeather == 1 ) 
//    {
//      tmpStr = CCString::createWithFormat("Change Weather\tLight Rain^"); 
//    }
//    else if( tmpQuest->questWeather == 2 ) 
//    {
//      tmpStr = CCString::createWithFormat("Change Weather\tHeavy Rain^"); 
//    } 
//    else if( tmpQuest->questWeather == 3 ) 
//    {
//      tmpStr =CCString::createWithFormat("Change Weather\tNight^"); 
//    } 
//    else if( tmpQuest->questWeather == 4 ) 
//    {
//      tmpStr = CCString::createWithFormat("Change Weather\tNight Rain^"); 
//    } 
//    else if( tmpQuest->questWeather == 5 )
//    {
//      tmpStr = CCString::createWithFormat("Change Weather\tSnow^"); 
//    }
//    else 
//    {
//      tmpStr = CCString::createWithFormat("Change Weather\tNormal^"); 
//    }
//    this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//    
//    tmpStr = CCString::createWithFormat("Set Zone\t%s^",tmpQuest->getZoneName()->getCString()); 
//    this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//    
//    tmpStr = CCString::createWithFormat("Fade In\t^"); 
//    this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//    
//    if( tmpQuest->questStory == 3 ) 
//    {
//      
//      
//      tmpStr = CCString::createWithFormat("IF\tGlobal Variable^SYS.ZombieModeBefore^F"); 
//     this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//      
//      tmpStr = CCString::createWithFormat("Display Message\tThis is a Zombie Artifact Mission. Search and Destroy the Zombie Artifact.^"); 
//      this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//      
//      tmpStr = CCString::createWithFormat("Display Message\tAvoid the Zombies as best you can. Your monsters health will decrease each time you are bitten.^"); 
//     this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//      
//      tmpStr = CCString::createWithFormat("Display Message\tThe Zombie artifact looks like a glowing green Zombie.^"); 
//      this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//      
//      tmpStr =CCString::createWithFormat("Update Variable\tSYS.ZombieModeBefore^T"); 
//      this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//      
//      tmpStr = CCString::createWithFormat("ELSE\t^"); 
//      this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//      
//      tmpStr =CCString::createWithFormat("END IF\t^"); 
//      this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
//    }
//    
//    menuLayerObj->questMenu = menuLayerObj->availableQuests->count()-1;
//    
//    /* PENDING_DEEPAK
//    [Flurry logEvent:@"Quest Started" withParameters:
//     [NSDictionary dictionaryWithObjectsAndKeys:
//      [NSString stringWithFormat:@"%d",tmpQuest.questStory],@"Quest Type",
//      [NSString stringWithFormat:@"%d",tmpQuest.questClass],@"Quest Class",
//      [NSString stringWithFormat:@"%d",tmpQuest.missionCode],@"Quest Mission Code",
//      [NSString stringWithFormat:@"%d",tmpQuest.type1Id],@"Type 1",
//      [NSString stringWithFormat:@"%d",tmpQuest.type2Id],@"Type 2",
//      nil] ];
//    
//    */
//    
//    
//    menuLayerObj->activeScript->removeObjectAtIndex(0);
//    menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//    this->scriptProgress();
//    
//	}
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Allow Save"))))
//  {
//    gameEngine->displayMenuButton();
//    
//    menuLayerObj->activeScript->removeObjectAtIndex(0);
//    this->scriptProgress();
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Ask Question - Two Answers"))))
//  {
//    
//		CoolSprite * tmpSpt = NULL;
//    CoolFreeform * tmpFF = nil;
//    
//    
//    tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(0),FONT_WHITE,0.35,280,true);
//    tmpFF->updatePosition(ccp(54,320-32));
//    tmpFF->addToLayer(this,35);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpSpt->initWithFile(CCString::create("speechBubble.png"));
//    tmpSpt->updatePosition(ccp(240,320-80));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,34);
//      menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//    tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(1),FONT_WHITE,0.35,200,false);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240-54,320-80-100));
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(2),FONT_WHITE,0.35,200,false);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240+54,320-80-100));
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpSpt->initWithFile(CCString::create("buttonGreen.png"));
//    tmpSpt->updatePosition(ccp(240-54,320-80-110));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,36);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//    tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
//    tmpSpt->updatePosition(ccp(240+54,320-80-110));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,36);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//		menuLayerObj->bQuestionAnswered = false;
//    menuLayerObj->bTalkButtonTouched = false;
//    
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Full Restore"))))
//  {
//    for(int i=0; i<menuLayerObj->monsters->count();i++)
//    {
//      monster * mon= (monster*)menuLayerObj->monsters->objectAtIndex(i);
//      mon->hpLeft = mon->hp;
//    }
//    
//    
//    menuLayerObj->activeScript->removeObjectAtIndex(0);
//    this->scriptProgress();
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Fade In"))))
//  {
//    menuLayerObj->fadeTimer = 255;
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Fade Out"))))
//  {
//    menuLayerObj->fadeTimer = 0;
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Update Variable"))))
//  {
//		
//		//updateGlobal
//		
//		if(((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("F"))))
//    {
//			gameEngine->updateGlobal(((CCString*)args->objectAtIndex(1)), 0);
//            
//		} 
//    else if(((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("T"))))
//    {
//			gameEngine->updateGlobal(((CCString*)args->objectAtIndex(1)),  1);
//		}
//    else 
//    {
//			gameEngine->updateGlobal(((CCString*)args->objectAtIndex(1)),  2);
//		}
//		
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//		this->scriptProgress();
//	}
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Relocate User"))))
//  {
//		if( !menuLayerObj->bTransitionHappening ) 
//    {
//			menuLayerObj->bFadingOut = true;
//			menuLayerObj->fadeFactor = 255;
//			menuLayerObj->bTransitionHappening = true;
//		}
//		
//		if( menuLayerObj->bFadingOut )
//    {
//			menuLayerObj->fadeFactor = menuLayerObj->fadeFactor - 20;
//			if( menuLayerObj->fadeFactor < 15 ) {
//				menuLayerObj->fadeFactor = 0;
//				menuLayerObj->bFadingOut = false;
//				gameEngine->loadMap((CCString*)args->objectAtIndex(0),ccp((int)((CCString*)args->objectAtIndex(1)),(int)args->objectAtIndex(2)));
//			}
//		} 
//    else 
//    {
//			menuLayerObj->fadeFactor = menuLayerObj->fadeFactor + 20;
//			if( menuLayerObj->fadeFactor > 240 ) 
//      {
//				menuLayerObj->fadeFactor = 255;
//				menuLayerObj->bTransitionHappening = false;
//			}
//		}
//    
//    if( menuLayerObj->layerAbove != NULL )
//      //PENDING_DEEPAK layerAbove->setOpacity(fadeFactor);
//	 //PENDING_DEEPAK	map->setOpacity(fadeFactor);
//		
//		
//		if( !menuLayerObj->bTransitionHappening )
//    {
//			menuLayerObj->activeScript->removeObjectAtIndex(0);
//			this->scriptProgress();
//		}
//		
//	} else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Change Event"))))
// {
//    
//    gameEvent * evnt = this->eventByName((CCString*)args->objectAtIndex(0));
//    evnt->updateImage((CCString*)args->objectAtIndex(1));
//    
//    menuLayerObj->activeScript->removeObjectAtIndex(0);
//    this->scriptProgress();
//    
//	} else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Change Weather"))))
//  {
//		menuLayerObj->snowEmitter->resetSystem();
//		menuLayerObj->snowEmitter->stopSystem();
//		
//    menuLayerObj->weather->release();
//    menuLayerObj->weather = NULL;
//   menuLayerObj-> weather = CCString::create(((CCString*)args->objectAtIndex(0))->getCString());
//    
//		if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Normal")))
//    {
//      
//      
//			menuLayerObj->clouds->updateOpacity(0);
//			menuLayerObj->blackOverlay->updateOpacity(0);
//			menuLayerObj->glare->updateOpacity(0);
//			menuLayerObj->rainEmitter->stopSystem();
//		} 
//    else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Night")))
//    {
//      menuLayerObj->clouds->updateOpacity(255);
//			menuLayerObj->blackOverlay->updateOpacity(100);
//			menuLayerObj->glare->updateOpacity(0);
//			menuLayerObj->rainEmitter->stopSystem();
//      
//      
//		} else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Glare")))
//    {
//            menuLayerObj->clouds->updateOpacity(0);
//			menuLayerObj->blackOverlay->updateOpacity(0);
//			menuLayerObj->glare->updateOpacity(255);
//			menuLayerObj->rainEmitter->stopSystem();
//
//    }
//    else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Light Rain")))
//    {
//      
//            menuLayerObj->clouds->updateOpacity(255);
//			menuLayerObj->blackOverlay->updateOpacity(60);
//			menuLayerObj->glare->updateOpacity(0);
//            menuLayerObj->rainEmitter->setEmissionRate(20);
//			menuLayerObj->rainEmitter->stopSystem();
//      
//		} 
//    else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Heavy Rain")))
//    {
//			      
//            menuLayerObj->clouds->updateOpacity(255);
//			menuLayerObj->blackOverlay->updateOpacity(90);
//			menuLayerObj->glare->updateOpacity(0);
//            menuLayerObj->rainEmitter->setEmissionRate(60);
//			menuLayerObj->rainEmitter->stopSystem();
//		}
//    else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Night Rain")))
//    {      
//            menuLayerObj->clouds->updateOpacity(255);
//			menuLayerObj->blackOverlay->updateOpacity(100);
//			menuLayerObj->glare->updateOpacity(0);
//            menuLayerObj->rainEmitter->setEmissionRate(40);
//			menuLayerObj->rainEmitter->stopSystem();
//      
//		} 
//    else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Snow")))
//    {
//            menuLayerObj->clouds->updateOpacity(80);
//			menuLayerObj->blackOverlay->updateOpacity(80);
//			menuLayerObj->glare->updateOpacity(0);
//            menuLayerObj->rainEmitter->stopSystem();
//			menuLayerObj->snowEmitter->stopSystem();
//      
//		} 
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//		this->scriptProgress();
//	}
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Move Event"))))
//  {
//		if( (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("USER")))
//      {
//        menuLayerObj->me->addMoveQueue((CCString*)args->objectAtIndex(1));
//		} 
//      else 
//      {
//        for(int i=0;i<menuLayerObj->mapEvents->count();i++)
//        {
//          gameEvent * evnt=(gameEvent*)menuLayerObj->mapEvents->objectAtIndex(i);
//          if((evnt->getName())->isEqual(((CCString*)args->objectAtIndex(0))))
//          {
//            evnt->addMoveQueue((CCString*)args->objectAtIndex(1));
//				}
//			}
//		}
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//		this->scriptProgress();
//  }
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Sync All Events"))))
//  {
//		bool bHasMovers = false;
//		if( menuLayerObj->me->moveQueueSize() > 0 )
//    {
//			bHasMovers = true;
//		}
//    for(int i=0;i<menuLayerObj->mapEvents->count();i++)
//    {
//      gameEvent * evnt= (gameEvent*)menuLayerObj->mapEvents->objectAtIndex(i);
//			if( evnt->moveQueueSize() > 0 )
//      {
//				bHasMovers = true;
//			}
//		}
//		if( bHasMovers == false ) 
//    {
//			menuLayerObj->activeScript->removeObjectAtIndex(0);
//			this->scriptProgress();
//		}
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Start Battle"))))
//  {
//    if( IS_DEBUG_MODE )
//    {
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//      return;
//    }
//    
//		//When a battle finishes scriptProgress should be called.
//		if( !menuLayerObj->bBattleScriptStarted ) 
//    { 
//      
//      gameEngine->battleStart(args,false);
//      menuLayerObj->bBattleScriptStarted = true;
//		} 
//    else
//    {
//			menuLayerObj->bBattleStarted = false;
//            menuLayerObj->bBattleScriptStarted = false;
//			menuLayerObj->activeScript->removeObjectAtIndex(0);
//			this->scriptProgress();
//		}
//		
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("IF"))))
//  {
//    if( (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Global Variable")))
//    {
//      bool bResult = gameEngine->globalValue((CCString*)args->objectAtIndex(1));
//      if((bResult == true && (CCString*)args->objectAtIndex(2)->isEqual(CCString::create("T"))) || (bResult == false && (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("F"))))
//      {
//        this->scriptModifyWithConditionResult(true);
//      } 
//      else 
//      {
//        this->scriptModifyWithConditionResult(false);
//      }
//    }
//    else if( (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Item Count")))
//    {
//      int itemCount = menuLayerObj->itemCount(menuLayerObj->itemIdFromCode((CCString*)args->objectAtIndex(1)));
//      
//      int needAtLeast;
//      if( (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("At Least One")))
//      {
//        needAtLeast = 1;
//      } 
//      else 
//      {
//        needAtLeast = convertedString->stringByReplacingOccurrencesOfString(((CCString*)args->objectAtIndex(2))->getCString(), "Exactly ", "")->intValue();
//      }             
//      
//      if( itemCount >= needAtLeast ) 
//      {
//        this->scriptModifyWithConditionResult( true);
//      } 
//      else 
//      {
//        this->scriptModifyWithConditionResult(false);
//      }
//    } 
//    else if( ((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Coin Held"))))
//    {
//      if( ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("Equal or Greater Than"))))
//      {
//        
//        int needAtLeast = ((CCString*)args->objectAtIndex(1))->intValue();
//        
//        if( menuLayerObj->coin >= needAtLeast )
//        {
//          this->scriptModifyWithConditionResult(true);
//        } 
//        else 
//        {
//          this->scriptModifyWithConditionResult( false);
//        }
//        
//      } 
//      else 
//      {
//        assert(0);
//      }
//    } 
//    else if( ((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Quests Completed"))) )
//    {
//      //PENDING_DEEPAK [Flurry logEvent:@"Quest Complete"];
//      
//      CCArray * conditions =  CCArray::create((CCString::create(convertedString->componentsSeparatedByString((CCString*)args->objectAtIndex(2), CCString::create("."))->getCString()))); 
//      int targetAmt = (int)conditions->objectAtIndex(0);
//      int classes = (int)conditions->objectAtIndex(1);
//      
//      int countOfClass = 0;
//      for(int i=0; i<menuLayerObj->availableQuests->count();i++)
//      {
//        questTemplate * tmp= (questTemplate*)menuLayerObj->availableQuests->objectAtIndex(i); 
//        if( tmp->questClass == classes)
//          countOfClass++;
//      }
//      
//      if( countOfClass >= targetAmt ) 
//      {
//        this->scriptModifyWithConditionResult(true);
//      } 
//      else 
//      {
//        this->scriptModifyWithConditionResult(false);
//      }
//    }
//    
//    
//    
//    /*
//     Global Variable - Done
//     Item Count - Done
//     Coin Held - Done
//     Monster Tamed Count
//     Monster Defeated Count
//     Quests Completed
//     */
//    
//    
//    
//	}
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Shop - Buy"))))
//  {
//    
//    gameEngine->resetKeys();
//   menuLayerObj-> gearMenuLayer->bIsActive = true;
//   menuLayerObj-> gearMenuLayer->bIsOnPC = false;
//    menuLayerObj->gearMenuLayer->displayShop( true);
//    menuLayerObj->gearMenuLayer->setPosition(ccp(0,0));
//    
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Shop - Sell"))))
//  {
//    
//    gameEngine->resetKeys();
//    menuLayerObj->gearMenuLayer->bIsActive = true;
//    menuLayerObj->gearMenuLayer->bIsOnPC = false;
//   menuLayerObj-> gearMenuLayer->displayShop( false);
//   menuLayerObj-> gearMenuLayer->setPosition(ccp(0,0));
//    
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("ELSE"))))
//  {
//		//[activeScript removeObjectAtIndex:0];
//		//[self scriptProgress];
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("END IF"))))
//  {
//		//[activeScript removeObjectAtIndex:0];
//		//[self scriptProgress];
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Call Event"))))
//  {
//    //activeScript
//    
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//    
//    for(int i=0; i<menuLayerObj->mapEvents->count();i++)
//    {
//      gameEvent * evnt = (gameEvent*)menuLayerObj->mapEvents->objectAtIndex(i);
//      if( (CCString::create(convertedString->lowercaseString(evnt->getName())->getCString()))->isEqual(CCString::create(convertedString->lowercaseString((CCString*)args->objectAtIndex(0))->getCString())))
//      {
//        
//        CCString * script =  CCString::create(evnt->getScript()->getCString());
//        CCArray * scriptLines = CCArray::create(CCString::create(convertedString->componentsSeparatedByString(script, CCString::create("~"))->getCString()));
//        int count = 0;
//        for(int i=0; i<scriptLines->count();i++ )
//        {
//          CCString * functionLine= (CCString*)scriptLines->objectAtIndex(i); 
//          if(  functionLine->isEqual(CCString::create("")) == false ) 
//          {
//            menuLayerObj->activeScript->insertObject( CCString::create(convertedString->componentsSeparatedByString(functionLine, CCString::create("\t"))->getCString()),count);
//            count++;
//          }
//        }
//      }
//    }
//    
//		this->scriptProgress();
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))-> isEqual(CCString::create("Quest Add")))
//  {
//    
//    
//    if( (int)args->objectAtIndex(0) == 1 ) 
//    {
//      //Add the initial Dark Base Raid
//      
//      questTemplate * newQuest = new questTemplate();
//      newQuest->initWithParent(menuLayerObj,1, 1);
//     menuLayerObj-> availableQuests->addObject(newQuest);
//      newQuest->release();
//    } 
//    else if( (int)args->objectAtIndex(0) == 2 )
//    {
//      //Add the second Dark Base Raid
//      
//      questTemplate * newQuest = new questTemplate();
//      newQuest->initWithParent(menuLayerObj,3, 2);
//      menuLayerObj->availableQuests->addObject(newQuest);
//      newQuest->release();
//    } 
//    else if( (int)args->objectAtIndex(0) == 3 )
//    {
//      //Add the final boss battle Mission
//      questTemplate * newQuest = new questTemplate();
//      newQuest->initWithParent(menuLayerObj,4, 3);
//      menuLayerObj->availableQuests->addObject(newQuest);
//      newQuest->release();
//      
//    } 
//    
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//		this->scriptProgress();
//    
//	} else if( ((CCString*)scriptToExecute->objectAtIndex(0))-> isEqual(CCString::create("Quest Completed")) )
//  {
//    
//    menuLayerObj->missionsAccomplished++;
//    
//    if( menuLayerObj->filteredQuests->count() > 0 ) 
//    {
//      if( menuLayerObj->questMenu < menuLayerObj->filteredQuests->count() &&menuLayerObj-> questMenu >= 0 ) 
//      {
//        questTemplate * tmpQuest = (questTemplate*)menuLayerObj->filteredQuests->objectAtIndex(menuLayerObj->questMenu);
//        tmpQuest->bCompleted = true;
//        
//        //Generate more missions of the same class.
//       menuLayerObj->activeScript->insertObject((CCString::create(convertedString->componentsSeparatedByString(CCString::createWithFormat("Generate Quests\t%d^",tmpQuest->questClass), CCString::create("\t"))->getCString())),1);
//        
//      }
//    }
//    
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//		this->scriptProgress();
//	}
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Generate Quests")))
//  {
//    int questsToCreate = arc4random() % 2 + 1;
//    //Between 1 and 2
//    
//    int questClass = -1;
//    if( args->count() > 0 ) 
//    {
//      if( ((CCString*)args->objectAtIndex(0))-> isEqual(CCString::create("")) == false ) 
//      {
//        questClass = ((CCString*)args->objectAtIndex(0))->intValue();
//      }
//    }
//    
//    //questTemplate
//    for(int i=0;i<questsToCreate;i++) 
//    {
//      questTemplate * newQuest =  new questTemplate();
//      newQuest->initWithParent(menuLayerObj,questClass, 0);
//      menuLayerObj->availableQuests->addObject(newQuest);
//      newQuest->release();
//    }
//    
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//		this->scriptProgress();
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Quest Selection")))
//  {
//    
//    if( menuLayerObj->availableQuests->count() ==0 ) 
//    {
//      questTemplate * newQuest = new questTemplate();
//       newQuest->initWithParent(menuLayerObj,-1,0);
//      menuLayerObj->availableQuests->addObject(newQuest);
//      newQuest->release();
//    }
//    
//    menuLayerObj->questMenu = 0;
//    this->loadQuest();
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Add Monster")))
//  {
//    menuLayerObj->bTalkButtonTouched = false;
//    
//    CCString* temp = (CCString*)args->objectAtIndex(0);
//    int monId = (CCString::create(convertedString->componentsSeparatedByString((CCString*)args->objectAtIndex(0), CCString::create("\t"))->getCString()))->intValue();
//    int level = ((CCString*)args->objectAtIndex(1))->intValue();
//    int position = ((CCString*)args->objectAtIndex(2))->intValue();
//    int special = 0;
//    if( args->count() > 3 ) 
//    {
//      special = ((CCString*)args->objectAtIndex(3))->intValue();
//    }
//    
//    //
//    //int position = [[args objectAtIndex:2] intValue];
//    
//    menuLayerObj->sawMonster(monId);
//    menuLayerObj->caughtMonster( monId);
//    
//    dataMonster * mon = (dataMonster*)menuLayerObj->database->monById(monId);
//    monster * newMon = new monster(); 
//    newMon->initWithMonster(mon,level);
//    newMon->special = special;
//    newMon->position = position;
//    menuLayerObj->monsters->addObject(newMon);
//    
//    //monsterTemplate.png
//    CoolSprite * tmpSpt;
//    CoolFreeform * tmpFF;
//    
//    tmpSpt->initWithFile(CCString::create("monsterTemplate.png"));
//    tmpSpt->updatePosition(ccp(284,160));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,36);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//    tmpSpt->initWithFile(CCString::create("bg1.png"));
//    tmpSpt->updatePosition(ccp(284,160));
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,35);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release(); 
//    
//    
//    
//    
//    tmpFF ->initWithCoolSheet(CCString::createWithFormat("Name: %s",mon->getName()->getCString() ),FONT_WHITE,0.35,310,true);
//    tmpFF->updatePosition(ccp(108,320-15));
//    tmpFF->intTag1 = 320-25;
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpFF->initWithCoolSheet(CCString::createWithFormat("Type1: %s, Type2: %s", menuLayerObj->database->getTypeFromId(mon->type1Id)->getCString()    ,menuLayerObj->database->getTypeFromId(mon->type2Id)->getCString()),FONT_WHITE,0.25,310,true);
//    tmpFF->updatePosition(ccp(108,320-20-20));
//    tmpFF->intTag1 = 320-25;
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpFF ->initWithCoolSheet(CCString::createWithFormat("Category: %s",mon->getCategory()->getCString()),FONT_WHITE,0.25,310,true);
//    tmpFF->updatePosition(ccp(108,320-20-20-15));
//    tmpFF->intTag1 = 320-25;
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    tmpFF->initWithCoolSheet(CCString::createWithFormat("Base Health Points: %d",mon->hp),FONT_WHITE,0.25,310,true);
//    tmpFF->updatePosition(ccp(108,320-20-20-15-15));
//    tmpFF->intTag1 = 320-25;
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    /*
//     NSString * fullID = [NSString stringWithFormat:@"%@%d",@"000",mon.monid];
//     NSString * leadingZerosID = [fullID substringFromIndex:[fullID length]-3];
//     NSString * fileName = [NSString stringWithFormat:@"%@%@%@",@"dpffa",leadingZerosID,@".png"];
//     */
//    
//    tmpSpt->initWithFile(newMon->getImage());
//    tmpSpt->updatePosition(ccp(9+40,320-(9+40)));
//    tmpSpt->intTag1 = 320-(9+40);
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release();
//    
//    
//    
//    tmpSpt->initWithFile(CCString::createWithFormat("element-%s.png",CCString::create(convertedString->lowercaseString(menuLayerObj->database->getTypeFromId(mon->type1Id))->getCString())->getCString()));
//    tmpSpt->updatePosition(ccp(53+16,320-98-16));
//    tmpSpt->intTag1 = 320-98-16;
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release();
//    
//    tmpSpt->initWithFile(CCString::createWithFormat("element-%s.png",CCString::create(convertedString->lowercaseString(menuLayerObj->database->getTypeFromId(mon->type1Id))->getCString())->getCString()));
//    tmpSpt->updatePosition(ccp(14+16,320-98-16));
//    tmpSpt->intTag1 = 320-98-16;
//    tmpSpt->updateOpacity(255);
//    tmpSpt->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpSpt);
//    tmpSpt->release();
//    
//    
//    tmpFF->initWithCoolSheet(CCString::createWithFormat("ATK: %d",mon->atk),FONT_WHITE,0.4,310,true);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(151,320-101));
//    tmpFF->intTag1 = 320-106;
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    
//    tmpFF ->initWithCoolSheet(CCString::createWithFormat("DEF: %d",mon->def),FONT_WHITE,0.4,310,true);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(260,320-101));
//    tmpFF->intTag1 = 320-106;
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    
//    tmpFF->initWithCoolSheet(CCString::createWithFormat("SPD: %d",mon->spd),FONT_WHITE,0.4,310,true);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(151,320-140));
//    tmpFF->intTag1 = 320-145;
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    
//    tmpFF->initWithCoolSheet(CCString::createWithFormat("INT: %d",mon->intel),FONT_WHITE,0.4,310,true);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(260,320-140));
//    tmpFF->intTag1 = 320-145;
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    
//    
//    
//    tmpFF ->initWithCoolSheet(CCString::createWithFormat("New Monster Acquired!"),FONT_WHITE,0.45,340,true);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240,320-200));
//    tmpFF->intTag1 = 480-145;
//    tmpFF->addToLayer(this,37);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//    
//    menuLayerObj->bTalkButtonTouched = false;
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Change Coin")))
//  {
//    if( ((CCString*)args->objectAtIndex(0))->isEqual(CCString::create("ADD")))
//    {
//      menuLayerObj->coin  = menuLayerObj->coin + ((CCString*)args->objectAtIndex(1))->intValue();
//    } 
//    else 
//    {
//      menuLayerObj->coin  = menuLayerObj->coin - ((CCString*)args->objectAtIndex(1))->intValue();
//    }
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//		this->scriptProgress();
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Change Inventory")))
//  {
//    if( ((CCString*)args->objectAtIndex(1))->isEqual(CCString::create("ADD")))
//    {
//      menuLayerObj->addItems(menuLayerObj->itemIdFromCode(((CCString*)args->objectAtIndex(0))), ((CCString*)args->objectAtIndex(2))->intValue());
//      
//    } else 
//    {
//      menuLayerObj->useItems(menuLayerObj->itemIdFromCode(((CCString*)args->objectAtIndex(0))), ((CCString*)args->objectAtIndex(2))->intValue());
//   }
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//		this->scriptProgress();
//    
//	} else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Set Zone"))))
//  {
//    
//   
//    menuLayerObj->database->loadZoneInto(menuLayerObj->zoneMonsters, (CCString*)args->objectAtIndex(0));
//    
//    menuLayerObj->zone->release();
//    menuLayerObj->zone = NULL;
//    menuLayerObj->zone = CCString::create(((CCString*)args->objectAtIndex(0))->getCString());
//    
//		menuLayerObj->activeScript->removeObjectAtIndex(0);
//		this->scriptProgress();
//      
//      
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Start AutoBattle"))))
//  {
//    
//    CCString * funcLine;
//    CCString * treasureHash =CCString::createWithFormat("SYS.AUTOBATTLE.%s.%s",menuLayerObj->mapFilename->getCString(),menuLayerObj->lastTriggeredEventName->getCString());
//    CCString * battleData = CCString::create("");
//    
//    for(int i=2;i<args->count();i++)
//    {
//      battleData = convertedString->stringByAppendingFormat(battleData, CCString::createWithFormat("%s",((CCString*)args->objectAtIndex(i))->getCString()));
//    }
//    battleData =  convertedString->substringToIndex(battleData, battleData->length()-1);
//    
//    
//    int pos = 1;
//    funcLine = CCString::createWithFormat("IF|Global Variable^%s^F",treasureHash->getCString());
//    menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//    
//    funcLine = CCString::createWithFormat("Display Message|%s^",((CCString*)args->objectAtIndex(0))->getCString());
//    pos++;
//    menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//    
//    funcLine = CCString::createWithFormat("Start Battle|%s",battleData->getCString());
//    pos++;
//     menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//    
//    funcLine = CCString::createWithFormat("Update Variable|%s^T",treasureHash->getCString());
//    pos++;
//    menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//    
//    funcLine = CCString::createWithFormat("ELSE|");
//    pos++;
//    menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//    
//    //funcLine = [NSString stringWithFormat:@"Display Message|%@^",[args objectAtIndex:1]];
//    //[activeScript addObject:  [funcLine componentsSeparatedByString:@"|"]  ];
//    
//    funcLine = CCString::createWithFormat("END IF|");
//    pos++;
//    menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//    
//   menuLayerObj-> activeScript->removeObjectAtIndex(0);
//    this->scriptProgress();
//    
//    
//	}
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Treasure Chest"))))
//  {
//    
//    if( ((CCString*)args->objectAtIndex(1))->isEqual(CCString::create("COIN")))
//    {
//      
//      int treasureAmt = ((CCString*)args->objectAtIndex(1))->intValue() + (arc4random() % (((CCString*)args->objectAtIndex(2))-> intValue() * 2)) - ((CCString*)args->objectAtIndex(2))->intValue();
//      
//      CCString * funcLine;
//      CCString * treasureHash =CCString::createWithFormat("SYS.TREASURE.%s.%s",menuLayerObj->mapFilename->getCString(),menuLayerObj->lastTriggeredEventName->getCString());
//      
//      int pos = 1;
//      funcLine = CCString::createWithFormat("IF|Global Variable^%@^F",treasureHash->getCString());
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      funcLine = CCString::createWithFormat("Display Message|You found %d Coin!^",treasureAmt);
//      pos++;
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine = CCString::createWithFormat("Change Coin|ADD^%d",treasureAmt);
//      pos++;
//     menuLayerObj-> activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine = CCString::createWithFormat("Update Variable|%s^T",treasureHash->getCString());
//      pos++;
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine = CCString::createWithFormat("ELSE|");
//      pos++;
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine = CCString::createWithFormat("Display Message|The Treasure Chest is Empty!^");
//      pos++;
//     menuLayerObj-> activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine =CCString::createWithFormat("END IF|");
//      pos++;
//     menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//    } 
//    else 
//    {
//      
//      int treasureAmt = ((CCString*)args->objectAtIndex(1))->intValue() + (arc4random() % (((CCString*)args->objectAtIndex(2))->intValue() * 2)) - ((CCString*)args->objectAtIndex(2))->intValue();
//      
//      dataItem * item = menuLayerObj->database->getItemForValue(treasureAmt);
//      
//      CCString * funcLine;
//      CCString * treasureHash = CCString::createWithFormat("SYS.TREASURE.%s.%s",menuLayerObj->mapFilename->getCString(),menuLayerObj->lastTriggeredEventName->getCString());
//      
//      int pos = 1;
//      funcLine = CCString::createWithFormat("IF|Global Variable^%s^F",treasureHash->getCString());
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine = CCString::createWithFormat("Display Message|You found a %s!^",item->getName()->getCString());
//      pos++;
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine = CCString::createWithFormat("Change Inventory|%d^ADD^1",item->itemid);
//      pos++;
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine =CCString::createWithFormat("Update Variable|%s^T",treasureHash->getCString());
//      pos++;
//        menuLayerObj-> activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine = CCString::createWithFormat("ELSE|");
//      pos++;
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine = CCString::createWithFormat("Display Message|The Treasure Chest is Empty!^");
//      pos++;
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//      funcLine = CCString::createWithFormat("END IF|");
//      pos++;
//      menuLayerObj->activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
//      
//     menuLayerObj-> activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//    }
//  }
//}
//
//
//void Scripts::scriptCheck()
//{
//	if(menuLayerObj->  activeScript->count() == 0 ) 
//  {
//		return;
//	}
//  
//	CCArray * scriptToExecute = CCArray::create((CCString*)menuLayerObj-> activeScript->objectAtIndex(0));
//	if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Display Message")))
//  {
//		CCArray * args =  CCArray::create((CCString*)convertedString->componentsSeparatedByString(((CCString*)scriptToExecute->objectAtIndex(1)), CCString::create("^")));
//		
//    if(menuLayerObj-> eventObjects->count() > 0 ) 
//    {
//      if( menuLayerObj-> bTalkButtonTouched ) 
//      {
//        menuLayerObj-> sfx(CCString::create( SOUND_CONFIRM));
//        if( ((CoolFreeform*)menuLayerObj-> eventObjects->objectAtIndex(0))->isFinished())
//        {
//          menuLayerObj->activeScript->removeObjectAtIndex(0);
//          this->scriptProgress();
//        } 
//        else 
//        {
//          ((CoolFreeform*)menuLayerObj-> eventObjects->objectAtIndex(0))->finish();
//        }
//       menuLayerObj->  bTalkButtonTouched = false;
//      }
//    }
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Monster Farm"))))
//  {
//    
//    if( menuLayerObj-> farmMenuState == - 1 )
//    {
//      menuLayerObj-> activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//    }
//    
//    
//    
//    
//    
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Monster Selection"))) {
//    gearMenuLayer->bIsActive = true;
//    gearMenuLayer->bIsOnPC = true;
//    gearMenuLayer->drawMonsterCategories(1);
//    gearMenuLayer->setPosition(ccp(0,0));
//    
//    menuLayerObj->activeScript->removeObjectAtIndex(0);
//    this->scriptProgress();
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Fade In")))
//  {
//    menuLayerObj->fadeTimer = menuLayerObj->fadeTimer - 10;
//    if( menuLayerObj->fadeTimer <= 0 ) 
//    {
//      menuLayerObj->fadeTimer = 0;
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//    }
//    menuLayerObj->blackCover->updateOpacity(menuLayerObj->fadeTimer);    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Fade Out")))
//  {
//    menuLayerObj->fadeTimer = menuLayerObj->fadeTimer + 10;
//    if( menuLayerObj->fadeTimer >= 255 )
//    {
//      menuLayerObj->fadeTimer = 255;        
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//    }
//   menuLayerObj-> blackCover->updateOpacity(menuLayerObj->fadeTimer); 
//    
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Mutate Monster at Position")))
//  {
//    
//    if( menuLayerObj->eventObjects->count() == 2 ) 
//    {
//      
//      CoolSprite * tmpSpt = (CoolSprite*)menuLayerObj->eventObjects->objectAtIndex(0);
//      tmpSpt->intTag1 = tmpSpt->intTag1 - 3;
//      if( tmpSpt->intTag1 < 0 ) 
//        tmpSpt->intTag1 = 0;
//        
//        tmpSpt->updateOpacity( tmpSpt->intTag1);
//      ((CoolSprite*)menuLayerObj->eventObjects->objectAtIndex(1))->updateOpacity( 255-tmpSpt->intTag1);
//      
//      if( tmpSpt->intTag1 <= 0 ) 
//      {
//        //End the function
//        
//        menuLayerObj->activeScript->removeObjectAtIndex(0);
//        this->scriptProgress();
//      }
//    }
//  } 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Display Credits")))
//  {
//    menuLayerObj->creditsTimer++;
//    if( menuLayerObj->creditsTimer < 60 )
//      menuLayerObj->bTalkButtonTouched=false;
//      if( menuLayerObj->bTalkButtonTouched ) 
//      {
//        
//        menuLayerObj->activeScript->removeObjectAtIndex(0);
//        this->scriptProgress();
//        return;
//      }
//  } 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Shop - Buy")))
//  {
//    
//    if( gearMenuLayer->bIsActive == false ) 
//    {
//      
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//      
//    }
//    
//	} else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Shop - Sell")))
//  {
//    
//    if( gearMenuLayer->bIsActive == false ) 
//    {
//      
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//    }
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Flash Red")))
//  {
//    menuLayerObj->redFlash->intTag1 = menuLayerObj->redFlash->intTag1  - 20;
//    menuLayerObj->redFlash->updateOpacity(menuLayerObj->redFlash->intTag1);
//    if( menuLayerObj->redFlash->intTag1 == 0 ) 
//    {
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//    }
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Bite")))
//  {
//   menuLayerObj-> redFlash->intTag1 = menuLayerObj->redFlash->intTag1  - 20;
//   menuLayerObj-> redFlash->updateOpacity(menuLayerObj->redFlash->intTag1 );
//    if( menuLayerObj->redFlash->intTag1 == 0 ) 
//    {
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//      
//      questTemplate * tmpQuest = (questTemplate*)menuLayerObj->availableQuests->objectAtIndex(menuLayerObj->questMenu);
//      int damage = tmpQuest->questClass * 10 + 5;
//      
//      bool bMonsterStillAlive = false;
//      for(int i=0; i<menuLayerObj->monsters->count();i++)
//      {
//        monster * mon=(monster*)menuLayerObj->monsters->objectAtIndex(i);
//        if( mon->position > 0 ) 
//        {
//          
//          mon->hpLeft = mon->hpLeft - damage;
//          if( mon->hpLeft <= 0 )
//          {
//            mon->hpLeft  = 0;
//          }
//          else 
//          {
//            bMonsterStillAlive = true;
//          }
//          
//        }
//      }
//      if( bMonsterStillAlive == false ) 
//      {
//        this->addFaintScriptAndKO();
//        this->scriptProgress();
//      }
//    }
//	} else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Quest Selection")))
//  {
//    
//    
//    
//    
//    //[activeScript removeObjectAtIndex:0];
//    //[self scriptProgress];
//    
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Sync All Events")))
//  {
//		this->scriptProgress();
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Relocate User")))
//  {
//		this->scriptProgress();
//	}
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("END IF")))
//  {
//    //CleanUp - This shouldn't be required
//    if( menuLayerObj->activeScript->count() == 1 ) 
//    {
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//    }
//	} 
//  else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("ELSE")))
//  {
//    //CleanUp - This shouldn't be required
//    if(menuLayerObj->activeScript->count() == 1 )
//    {
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//    }
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Ask Yes or No")) || ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Ask Question - Two Answers")) )
//  {
//    if( menuLayerObj->bQuestionAnswered )
//    {
//      menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//      
//    }
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Add Monster")))
//  {
//    if( menuLayerObj->bTalkButtonTouched )
//    {
//      menuLayerObj->activeScript->removeObjectAtIndex(0);
//      this->scriptProgress();
//      return;
//    }
//    
//    
//	} else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("IAP")))
//  { 
//    
//		CCArray * args = CCArray::create(CCString::create(convertedString->componentsSeparatedByString((CCString*)scriptToExecute->objectAtIndex(1), CCString::create("^"))->getCString()));
//
//    /* PENDINH_DEEPAK  BECAUSE MKStoreManager   
//    if( [[MKStoreManager sharedManager].purchasableObjects count] == 0 ) {
//      //Still Loading
//    } else  {
//      if( bIAPPurchasing ) {
//        ;
//        if( IAPResult == 1 ) {
//          //Success
//          
//          [activeScript removeObjectAtIndex:0];
//          [activeScript insertObject:  [[NSString stringWithFormat:@"Display Message\tTransaction was successful!^"] componentsSeparatedByString:@"\t"]  atIndex:0];
//          [self scriptProgress];
//          
//        } else if( IAPResult == 2 ) {
//          //Failure
//          
//          //IAPErrorMessage
//          
//          [self updateGlobal:@"SYSYesNoAnswer" withAction:0];
//          [activeScript removeObjectAtIndex:0];
//          [activeScript insertObject:  [[NSString stringWithFormat:@"Display Message\t%@^",IAPErrorMessage] componentsSeparatedByString:@"\t"]  atIndex:0];
//          [self scriptProgress];
//          
//          
//        } else {
//          //Still Loading
//          
//          
//          
//        }
//        
//      } else {
//        
//        
//        if( bIAPShowing == false ) {
//          bIAPPurchasing = false;
//          
//          //Clear Screen and Draw Purchase Option.
//          [eventObjects removeAllObjects];
//          
//          CoolSprite * tmpSpt = nil;
//          CoolFreeform * tmpFF = nil;
//          
//          tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Buy" fontName:FONT_WHITE fontSize:0.35 andMaxWidth:200 instant:true];
//          tmpFF.bCenter = true;
//          [tmpFF updatePosition:ccp(240-54,320-80-100)];
//          [tmpFF addToLayer:self z:37];
//          [eventObjects addObject:tmpFF];
//          [tmpFF release];
//          
//          tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"No Thanks" fontName:FONT_WHITE fontSize:0.25 andMaxWidth:200 instant:true];
//          tmpFF.bCenter = true;
//          [tmpFF updatePosition:ccp(240+54,320-80-100)];
//          [tmpFF addToLayer:self z:37];
//          [eventObjects addObject:tmpFF];
//          [tmpFF release];
//          
//          tmpSpt = [[CoolSprite alloc] initWithFile:@"buttonGreen.png"];
//          [tmpSpt updatePosition:ccp(240-54,320-80-110)];
//          [tmpSpt updateOpacity:255];
//          [tmpSpt addToLayer:self z:36];
//          [eventObjects addObject:tmpSpt];
//          [tmpSpt release]; 
//          
//          tmpSpt = [[CoolSprite alloc] initWithFile:@"buttonBlue.png"];
//          [tmpSpt updatePosition:ccp(240+54,320-80-110)];
//          [tmpSpt updateOpacity:255];
//          [tmpSpt addToLayer:self z:36];
//          [eventObjects addObject:tmpSpt];
//          [tmpSpt release]; 
//          
//          tmpSpt = [[CoolSprite alloc] initWithFile:@"speechBubble.png"];
//          [tmpSpt updatePosition:ccp(240,320-80)];
//          [tmpSpt updateOpacity:255];
//          [tmpSpt addToLayer:self z:34];
//          [eventObjects addObject:tmpSpt];
//          [tmpSpt release]; 
//          
//          
//          SKProduct * prodToUse = nil;
//          for(SKProduct * prod in [[MKStoreManager sharedManager] purchasableObjects]) {
//            if( [[args objectAtIndex:0] isEqualToString:@"A"] ) {
//              //prod
//              
//              if( [[prod productIdentifier] isEqualToString:featureAId] ) {
//                prodToUse = prod;
//                break;
//              }
//            } else if( [[args objectAtIndex:0] isEqualToString:@"B"] ) {
//              //prod
//              
//              if( [[prod productIdentifier] isEqualToString:featureBId] ) {
//                prodToUse = prod;
//                break;
//              }
//            }  else if( [[args objectAtIndex:0] isEqualToString:@"C"] ) {
//              //prod
//              
//              if( [[prod productIdentifier] isEqualToString:featureCId] ) {
//                prodToUse = prod;
//                break;
//              }
//            }  else if( [[args objectAtIndex:0] isEqualToString:@"D"] ) {
//              //prod
//              
//              if( [[prod productIdentifier] isEqualToString:featureDId] ) {
//                prodToUse = prod;
//                break;
//              }
//            } 
//          }
//          
//          if( prodToUse== nil ) {
//            //Serious Error
//            [self updateGlobal:@"SYSYesNoAnswer" withAction:0];
//          } else {
//            
//            CoolLabel * tmpLbl = [[CoolLabel alloc] initWithCoolString:[NSString stringWithFormat:@"Price: %@",[self stringFromLocalPrice:prodToUse]] fontName:@"Arial" fontSize:14];
//            [tmpLbl updatePosition:ccp(480-120,320-42)];
//            [tmpLbl addToLayer:self z:35];
//            [eventObjects addObject:tmpLbl];
//            [tmpLbl release];
//            
//            tmpFF = [[CoolFreeform alloc] initWithCoolSheet:prodToUse.localizedTitle fontName:FONT_WHITE fontSize:0.35 andMaxWidth:220 instant:true];
//            [tmpFF updatePosition:ccp(54,320-32)];
//            [tmpFF addToLayer:self z:35];
//            [eventObjects addObject:tmpFF];
//            [tmpFF release];
//            
//            tmpFF = [[CoolFreeform alloc] initWithCoolSheet:prodToUse.localizedDescription fontName:FONT_WHITE fontSize:0.25 andMaxWidth:360 instant:true];
//            [tmpFF updatePosition:ccp(54,320-52)];
//            [tmpFF addToLayer:self z:35];
//            [eventObjects addObject:tmpFF];
//            [tmpFF release];
//          }
//          
//          
//          bQuestionAnswered = false;
//          bTalkButtonTouched = false;
//          bIAPShowing = true;
//          
//        } else {
//          //Do Nothing
//          
//          if( bQuestionAnswered ) {
//            
//            if( [self getGlobalBool:@"SYSYesNoAnswer"] ) {
//              //Perform Purchase
//              
//              
//              //Clear Screen and Draw Loading Screen.
//              [eventObjects removeAllObjects];
//              
//              CoolFreeform * tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Prompting for Purchase..." fontName:FONT_WHITE fontSize:0.35 andMaxWidth:380 instant:false];
//              [tmpFF updatePosition:ccp(54,320-32)];
//              [tmpFF addToLayer:self z:35];
//              [eventObjects addObject:tmpFF];
//              [tmpFF release];
//              
//              CoolSprite * tmpSpt = [[CoolSprite alloc] initWithFile:@"speechBubble.png"];
//              [tmpSpt updatePosition:ccp(240,320-80)];
//              [tmpSpt updateOpacity:255];
//              [tmpSpt addToLayer:self z:34];
//              [eventObjects addObject:tmpSpt];
//              [tmpSpt release]; 
//              
//              IAPResult = 0;
//              bIAPPurchasing = true;
//              
//              if( [[args objectAtIndex:0] isEqualToString:@"A"] ) {
//                [[MKStoreManager sharedManager] buyFeatureA:self];
//              } else if( [[args objectAtIndex:0] isEqualToString:@"B"] ) {
//                [[MKStoreManager sharedManager] buyFeatureB:self];
//              }    else if( [[args objectAtIndex:0] isEqualToString:@"C"] ) {
//                [[MKStoreManager sharedManager] buyFeatureC:self];
//              }    else if( [[args objectAtIndex:0] isEqualToString:@"D"] ) {
//                [[MKStoreManager sharedManager] buyFeatureD:self];
//              }   
//              
//              
//            } else {
//              //Abort Purchase
//              //SYSYesNoAnsweris already F so we can abort the script
//              [self updateGlobal:@"SYSYesNoAnswer" withAction:0];
//              [activeScript removeObjectAtIndex:0];
//              [self scriptProgress];
//            }
//            
//          }
//          
//        }
//        
//      }
//      
//    } */
//    
//	} 
//  else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Start Battle")))
//  {
//    
//    
//  }
//  
//  
//	
//}
//
//
///* PENDING_DEEPAK BECAUSE SKProduct
//- (NSString * ) stringFromLocalPrice:(SKProduct *) product{
//	
//	NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
//	[formatter setFormatterBehavior:NSNumberFormatterBehavior10_4];
//	[formatter setNumberStyle:NSNumberFormatterCurrencyStyle];
//	[formatter setLocale:product.priceLocale];
//	
//	NSString *str = [formatter stringFromNumber:product.price];
//	[formatter release];
//	return str;
//	
//}
//*/
//
//void Scripts::scriptTouch(CCPoint touch)
//{
//	CCPoint button = menuLayerObj->btnTalkPosition;
//	if( touch.x > button.x -16 && touch.x < button.x + 16 ) 
//  {
//		if( touch.y > button.y -16 && touch.y < button.y + 16 )
//    {
//			menuLayerObj->bTalkButtonTouched = true;
//			
//		}
//	}
//  
//  //btn Yes
//	button = ccp(240-54,320-80-110);
//  if( touch.x > button.x -25 && touch.x < button.x + 25 )
//  {
//		if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//    {
//			gameEngine->updateGlobal(CCString::create("SYSYesNoAnswer"),1);
//      menuLayerObj->bQuestionAnswered= true;
//		}
//	}
//  
//  //btn No
//	button = ccp(240+54,320-80-110);
//  if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
//  {
//		if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//    {
//			gameEngine->updateGlobal(CCString::create("SYSYesNoAnswer"),0);
//      menuLayerObj->bQuestionAnswered= true;
//		}
//	}
//  
//  //TODO: Optimize this
//  if(menuLayerObj-> activeScript->count() > 0 )
//  {
//    
//    
//    CCArray * scriptToExecute =CCArray::create((CCString*)menuLayerObj->activeScript->objectAtIndex(0));
//    
//    if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Display Credits")))
//    {
//      menuLayerObj->bTalkButtonTouched = true;
//      menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//      return;
//    }
//    
//    
//    //ccp(240+54,320-80-100-80)
//    if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Monster Farm")))
//    {
//      //leave button
//      CCPoint tmp = ccp(240+54,320-80-100-80);
//      if( menuLayerObj->HitTest(touch,tmp,CCSizeMake(120, 42)))
//      {
//        menuLayerObj->farmMenuState = -1;
//      }
//      
//      //return monster
//      tmp = ccp(240-54,320-80-100);
//      if( menuLayerObj->HitTest(touch,tmp,CCSizeMake(120, 42)))
//      {
//        menuLayerObj->farmMenuState = 1;
//      }
//      
//      //place monster
//      tmp = ccp(240+54,320-80-100);
//      if( menuLayerObj->HitTest(touch,tmp,CCSizeMake(120, 42)))
//      {
//        menuLayerObj->farmMenuState = 2;
//      }
//      
//      //
//      
//    } 
//    else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Quest Selection")))
//    {
//      
//      //Buttons F-S & All
//      //
//      int ofsetX = 10;
//      
//      button = ccp(ofsetX+40,320-230);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 )
//        {
//          menuLayerObj->classFilter = 0;
//          menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//          this->buildQuestFilter();
//         this->loadQuest();
//        }
//      }
//      button = ccp(ofsetX+115,320-230);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 )
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 )
//        {
//          menuLayerObj->classFilter = 1;
//          menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//          this->buildQuestFilter();
//          this->loadQuest();
//        }
//      }
//      button = ccp(ofsetX+190,320-230);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 )
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 )
//        {
//          menuLayerObj->classFilter = 2;
//          menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//          this->buildQuestFilter();
//          this->loadQuest();
//        }
//      }
//      
//      button = ccp(ofsetX+265,320-230);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 )
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//        {
//          menuLayerObj->classFilter = 3;
//          menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//          this->buildQuestFilter();
//          this->loadQuest();
//        }
//      }
//      button = ccp(ofsetX+340,320-230);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//        {
//          menuLayerObj->classFilter = 4;
//          menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//          this->buildQuestFilter();
//          this->loadQuest();
//        }
//      }
//      button = ccp(ofsetX+415,320-230);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 )
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//        {
//          menuLayerObj->classFilter = 5;
//          menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//          this->buildQuestFilter();
//          this->loadQuest();
//        }
//      }
//      
//      button = ccp(ofsetX+340,320-230-70);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//        {
//          menuLayerObj->classFilter = 6;
//          menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//          this->buildQuestFilter();
//          this->loadQuest();
//        }
//      }
//      button = ccp(ofsetX+415,320-230-70);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 )
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 )
//        {
//          menuLayerObj->classFilter = -1;
//          menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//          this->buildQuestFilter();
//          this->loadQuest();
//        }
//      }
//      
//      
//      //Cancel Button
//      button = ccp(480-60,320-45);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 )
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//        {
//          
//          menuLayerObj->eventObjects->removeAllObjects();
//          menuLayerObj->activeScript->removeObjectAtIndex(0);
//          menuLayerObj->sfx(CCString::create( SOUND_CONFIRM));
//          this->scriptProgress();
//          
//        }
//      }
//      
//      //Previous Button
//      button = ccp(480-150,320-45-65);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 )
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 )
//        {
//          menuLayerObj->questMenu--;
//          if( menuLayerObj->questMenu < 0 )
//          {
//            menuLayerObj->questMenu = menuLayerObj->filteredQuests->count()-1;
//          }
//          menuLayerObj->sfx(CCString::create( SOUND_CONFIRM));
//          this->loadQuest();
//        }
//      }
//      
//      
//      //Next Button
//      button = ccp(480-60,320-45-65);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 )
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//        {
//          menuLayerObj->questMenu++;
//          if( menuLayerObj->questMenu >= menuLayerObj->filteredQuests->count())
//          {
//            menuLayerObj->questMenu = 0;
//          }
//          menuLayerObj->sfx(CCString::create( SOUND_CONFIRM));
//          this->loadQuest();
//        }
//      }
//      
//      //Accept Button
//      button = ccp(480-150,320-45);
//      if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
//      {
//        if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
//        {
//          
//          //Start Quest....
//          questTemplate * tmpQuest = (questTemplate*)menuLayerObj->filteredQuests->objectAtIndex(menuLayerObj->questMenu);
//          tmpQuest->setupEvents();
//          
//          CCString * tmpStr = nil;
//          
//          tmpQuest->reloadWithParent(menuLayerObj);
//          
//          
//          tmpStr = CCString::createWithFormat("Fade Out\t^"); 
//          this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//          
//          tmpStr = CCString::createWithFormat("Relocate User\t%s^%d^%d",tmpQuest->getMapName()->getCString() , (int)tmpQuest->startingPoint.x , (int)tmpQuest->startingPoint.y); 
//          this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//          
//          if( tmpQuest->questWeather == 0 ) 
//          {
//            tmpStr = CCString::createWithFormat("Change Weather\tGlare^"); 
//          }
//          else if( tmpQuest->questWeather == 1 ) 
//          {
//            tmpStr = CCString::createWithFormat("Change Weather\tLight Rain^"); 
//          }
//          else if( tmpQuest->questWeather == 2 ) 
//          {
//            tmpStr = CCString::createWithFormat("Change Weather\tHeavy Rain^"); 
//          }
//          else if( tmpQuest->questWeather == 3 ) 
//          {
//            tmpStr = CCString::createWithFormat("Change Weather\tNight^"); 
//          } 
//          else if( tmpQuest->questWeather == 4 )
//          {
//            tmpStr = CCString::createWithFormat("Change Weather\tNight Rain^"); 
//          } 
//          else if( tmpQuest->questWeather == 5 )
//          {
//            tmpStr =CCString::createWithFormat("Change Weather\tSnow^"); 
//          } 
//          else 
//          {
//            tmpStr =CCString::createWithFormat("Change Weather\tNormal^"); 
//          }
//          this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//          
//          tmpStr = CCString::createWithFormat("Set Zone\t%s^",tmpQuest->getZoneName()->getCString()); 
//          this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//          
//          tmpStr = CCString::createWithFormat("Fade In\t^"); 
//          this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//          
//          if( tmpQuest->questStory == 3 )
//          {
//            
//            
//            tmpStr =CCString::createWithFormat("IF\tGlobal Variable^SYS.ZombieModeBefore^F"); 
//             this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//            
//            tmpStr = CCString::createWithFormat("Display Message\tThis is a Zombie Artifact Mission. Search and Destroy the Zombie Artifact.^"); 
//             this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//            
//            tmpStr = CCString::createWithFormat("Display Message\tAvoid the Zombies as best you can. Your monsters health will decrease each time you are bitten.^"); 
//             this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//            
//            tmpStr = CCString::createWithFormat("Display Message\tThe Zombie artifact looks like a glowing green Zombie.^"); 
//             this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//            
//            
//            tmpStr = CCString::createWithFormat("Change Music\tsunnymellow^"); 
//             this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//            
//            tmpStr = CCString::createWithFormat("Update Variable\tSYS.ZombieModeBefore^T"); 
//             this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//            
//            tmpStr = CCString::createWithFormat("ELSE\t^"); 
//             this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//            
//            tmpStr = CCString::createWithFormat("END IF\t^"); 
//             this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
//          }
//          
//          menuLayerObj->activeScript->removeObjectAtIndex(0);
//          menuLayerObj->sfx(CCString::create(SOUND_CONFIRM));
//         this->scriptProgress();
//          
//        }
//        
//        
//      }
//      
//    } else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Monster Farm")))
//    {
//      
//    }
//    
//  }
//	
//}
//
//
//
//bool Scripts::thereAreQuestsOfClass(int questClass)
//{
//  for(int i=0; i<menuLayerObj->availableQuests->count();i++) 
//  {
//    questTemplate * tmp = (questTemplate*)menuLayerObj->availableQuests->objectAtIndex(i);
//    if( tmp->questClass == questClass ) 
//      return true;
//    
//  }
//  return false;
//}
//
//void Scripts::buildQuestFilter() 
//{
//  menuLayerObj->filteredQuests->removeAllObjects();
//  
//  for(int i=0; i<menuLayerObj-> availableQuests->count();i++) 
//  {
//    questTemplate * tmp = (questTemplate*)menuLayerObj->availableQuests->objectAtIndex(i);
//    if( tmp->questClass == menuLayerObj->classFilter ||menuLayerObj->classFilter == -1 ) 
//      menuLayerObj->filteredQuests->addObject(tmp);
//  }
//}
//
//
//void Scripts::loadQuest()
//{
//  
//  if( menuLayerObj->filteredQuests->count() > 0 )
//  {
//    questTemplate * tmp = (questTemplate*)menuLayerObj->filteredQuests->objectAtIndex(0);
//    if( tmp->questClass != menuLayerObj->classFilter ) 
//    {
//      this->buildQuestFilter();
//    }
//  } 
//  else 
//  {
//    //Filter on All
//    menuLayerObj->classFilter = -1;
//    this->buildQuestFilter();
//  }
//  
//  
//  CoolSprite * tmpSpt = new CoolSprite();
//  CoolFreeform * tmpFF;
//  
//  menuLayerObj->eventObjects->removeAllObjects();
//  
//  
//  if(menuLayerObj->questMenu >= menuLayerObj->filteredQuests->count() )
//    menuLayerObj->questMenu = 0;
//    
//    questTemplate * tmpQuest = (questTemplate*)menuLayerObj->filteredQuests->objectAtIndex(menuLayerObj->questMenu);
//    
//    
//  tmpSpt->initWithFile(CCString::create("bg1.png"));
//  tmpSpt->updatePosition(ccp(284,160));
//  tmpSpt->updateOpacity(255);
//  tmpSpt->addToLayer(this,80);
//  menuLayerObj->eventObjects->addObject(tmpSpt);
//  tmpSpt->release(); 
//  
//  tmpSpt->initWithFile(CCString::create("missionTemplate.png"));
//  tmpSpt->updatePosition(ccp(284,160));
//  tmpSpt->updateOpacity(255);
//  tmpSpt->addToLayer(this,81);
//  menuLayerObj->eventObjects->addObject(tmpSpt);
//  tmpSpt->release(); 
//
//  
//  /*
//   //Other Stuff
//   tmpSpt = [[CoolSprite alloc] initWithFile:@"screen.png"];
//   [tmpSpt updatePosition:ccp(160,240)];
//   [tmpSpt updateOpacity:255];
//   [tmpSpt addToLayer:self z:1000];
//   [eventObjects addObject:tmpSpt];
//   [tmpSpt release]; 
//   */
//  
//  int offsetX = 10;
//  
//  CCString * btnImage = NULL;
//  
//  btnImage = CCString::create("buttonRed.png");
//  if( this->thereAreQuestsOfClass(0))
//    btnImage = CCString::create("buttonGreen.png");
//    if( menuLayerObj->classFilter == 0 )
//      btnImage = CCString::create("buttonBlue.png");
//      
//      tmpSpt->initWithFile(btnImage);
//      tmpSpt->updatePosition(ccp(offsetX+40,320-230));
//  tmpSpt->updateOpacity(255);
//  tmpSpt->updateScale(0.95);
//  tmpSpt->addToLayer(this,1001);
//  menuLayerObj->eventObjects->addObject(tmpSpt);
//  tmpSpt->release(); 
//  
//  
//  btnImage = CCString::create("buttonRed.png");
//  if( this->thereAreQuestsOfClass(1) )
//    btnImage =  CCString::create("buttonGreen.png");
//    if( menuLayerObj->classFilter == 1 )
//      btnImage =  CCString::create("buttonBlue.png");
//      tmpSpt->initWithFile(btnImage);
//      tmpSpt->updatePosition(ccp(offsetX+115,320-230));
//      tmpSpt->updateOpacity(255);
//      tmpSpt->updateScale(0.95);
//      tmpSpt->addToLayer(this,1001);
//      menuLayerObj->eventObjects->addObject(tmpSpt);
//      tmpSpt->release(); 
//  
//  
//  btnImage =  CCString::create( "buttonRed.png");
//  if( this->thereAreQuestsOfClass(2) )
//    btnImage = CCString::create("buttonGreen.png");
//    if(menuLayerObj-> classFilter == 2 )
//      btnImage = CCString::create("buttonBlue.png");
//      tmpSpt->initWithFile(btnImage);
//      tmpSpt->updatePosition(ccp(offsetX+190,320-230));
//      tmpSpt->updateOpacity(255);
//      tmpSpt->updateScale(0.95);
//      tmpSpt->addToLayer(this,1001);
//      menuLayerObj->eventObjects->addObject(tmpSpt);
//      tmpSpt->release(); 
//  
//  
//  btnImage = CCString::create("buttonRed.png");
//  if( this->thereAreQuestsOfClass(3) )
//    btnImage = CCString::create("buttonGreen.png");
//    if(menuLayerObj-> classFilter == 3 )
//      btnImage = CCString::create("buttonBlue.png");
//      tmpSpt->initWithFile(btnImage);
//      tmpSpt->updatePosition(ccp(offsetX+265,320-230));
//      tmpSpt->updateOpacity(255);
//      tmpSpt->updateScale(0.95);
//      tmpSpt->addToLayer(this,1001);
//      menuLayerObj->eventObjects->addObject(tmpSpt);
//      tmpSpt->release(); 
//  
//  
//  btnImage = CCString::create("buttonRed.png");
//  if( this->thereAreQuestsOfClass(4) )
//    btnImage = CCString::create("buttonGreen.png");
//    if( menuLayerObj->classFilter == 4 )
//      btnImage = CCString::create("buttonBlue.png");
//      tmpSpt->initWithFile(btnImage);
//      tmpSpt->updatePosition(ccp(offsetX+340,320-230));
//      tmpSpt->updateOpacity(255);
//      tmpSpt->updateScale(0.95);
//      tmpSpt->addToLayer(this ,1001);
//     menuLayerObj-> eventObjects->addObject(tmpSpt);
//      tmpSpt->release(); 
//  
//  
//  btnImage = CCString::create("buttonRed.png");
//  if( this->thereAreQuestsOfClass(5) )
//    btnImage = CCString::create("buttonGreen.png");
//    if(menuLayerObj-> classFilter == 5 )
//      btnImage = CCString::create("buttonBlue.png");
//      tmpSpt->initWithFile(btnImage);
//      tmpSpt->updatePosition(ccp(offsetX+415,320-230));
//      tmpSpt->updateOpacity(255);
//      tmpSpt->updateScale(0.95);
//      tmpSpt->addToLayer(this,1001);
//      menuLayerObj->eventObjects->addObject(tmpSpt);
//      tmpSpt->release(); 
//  
//  tmpFF->initWithCoolSheet( CCString::create("F Class"),FONT_WHITE ,0.25,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(offsetX+40,320-230+10));
//  tmpFF->addToLayer(this,1002);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  tmpFF->initWithCoolSheet(CCString::create("E Class"),FONT_WHITE,0.25,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(offsetX+115,320-230+10));
//  tmpFF->addToLayer(this ,1002);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  tmpFF->initWithCoolSheet(CCString::create("D Class"),FONT_WHITE,0.25,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(offsetX+190,320-230+10));
//  tmpFF->addToLayer(this,1002);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  tmpFF->initWithCoolSheet(CCString::create("C Class"),FONT_WHITE,0.25,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(offsetX+265,320-230+10));
//  tmpFF->addToLayer(this,1002);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  tmpFF->initWithCoolSheet(CCString::create("B Class"),FONT_WHITE,0.25,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(offsetX+340,320-230+10));
//  tmpFF ->addToLayer(this,1002);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  tmpFF->initWithCoolSheet(CCString::create("A Class"),FONT_WHITE,0.25,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(offsetX+415,320-230+10));
//  tmpFF->addToLayer(this,1002);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  
//  
//  btnImage = CCString::create("buttonRed.png");
//  if( this->thereAreQuestsOfClass(6) )
//    btnImage = CCString::create("buttonGreen.png");
//    if( menuLayerObj->classFilter == 6 )
//      btnImage = CCString::create("buttonBlue.png");
//      tmpSpt->initWithFile(btnImage);
//      tmpSpt->updatePosition(ccp(offsetX+340,320-230-60));
//      tmpSpt->updateOpacity(255);
//      tmpSpt->updateScale(0.95);
//      tmpSpt->addToLayer(this,1001);
//      menuLayerObj->eventObjects->addObject(tmpSpt);
//      tmpSpt->release(); 
//  
//  
//  btnImage = CCString::create("buttonRed.png");
//  if( this->thereAreQuestsOfClass(0) )
//    btnImage =CCString::create("buttonGreen.png");
//    if( menuLayerObj->classFilter == -1 )
//      btnImage = CCString::create("buttonBlue.png");
//      tmpSpt->initWithFile(btnImage);
//      tmpSpt->updatePosition(ccp(offsetX+415,320-230-60));
//      tmpSpt->updateOpacity(255);
//      tmpSpt->updateScale(0.95);
//      tmpSpt->addToLayer(this,1001);
//      menuLayerObj->eventObjects->addObject(tmpSpt);
//      tmpSpt->release(); 
//  
//  
//  
//  tmpFF->initWithCoolSheet(CCString::create("S Class"),FONT_WHITE,0.25,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(offsetX+340,320-230-60+10));
//  tmpFF->addToLayer(this,1002);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  tmpFF->initWithCoolSheet(CCString::create("Show All"),FONT_WHITE,0.25,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(offsetX+415,320-230-60+10));
//  tmpFF->addToLayer(this,1002);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  //Mission Info
//  tmpSpt->initWithFile((convertedString->lowercaseString(CCString::createWithFormat("element-%s.png", (menuLayerObj->getDatabase()->getTypeFromId(tmpQuest->type1Id))->getCString()))));
//                     
//  tmpSpt->updatePosition(ccp(14+16,320-98-16));
//  tmpSpt->intTag1 = 480-98-16;
//  tmpSpt->updateOpacity(255);
//  tmpSpt->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpSpt);
//  tmpSpt->release();
//  
//  tmpSpt->initWithFile((convertedString->lowercaseString(CCString::createWithFormat("element-%s.png", (menuLayerObj->getDatabase()->getTypeFromId(tmpQuest->type2Id))->getCString()))));
//  tmpSpt->updatePosition(ccp(53+16,320-98-16));
//  tmpSpt->intTag1 = 480-98-16;
//  tmpSpt->updateOpacity(255);
//  tmpSpt->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpSpt);
//  tmpSpt->release();
//  
//  
//  
//  //Menu Bar
//  
//  
//  tmpFF->initWithCoolSheet(CCString::create("Class:"),FONT_WHITE,0.35,200,true);
//  tmpFF->updatePosition(ccp(25,320-20));
//  tmpFF->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  tmpFF->initWithCoolSheet(tmpQuest->getClass(),FONT_WHITE,0.6,200,true);
//  tmpFF->updatePosition(ccp(45,320-35));
//  tmpFF->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  tmpFF->initWithCoolSheet(CCString::create("Description:"),FONT_WHITE,0.25,200,true);
//  tmpFF->updatePosition(ccp(100,320-15));
//  tmpFF->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  tmpFF->initWithCoolSheet(CCString::create(tmpQuest->getDescription()->getCString()),FONT_WHITE,0.25,200,true);
//  tmpFF->updatePosition(ccp(100,320-30));
//  tmpFF->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  if( tmpQuest->bCompleted ) 
//  {
//    tmpFF ->initWithCoolSheet(CCString::create("Completed"),FONT_GREEN ,0.3,200,true);
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240,320-120));
//    tmpFF->addToLayer(this,83);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//  }
//  
//  
//  tmpFF ->initWithCoolSheet(CCString::create("Weather:"),FONT_WHITE,0.25,200,true);
//  tmpFF->updatePosition(ccp(100,320-80));
//  tmpFF->addToLayer(this,83);
// menuLayerObj-> eventObjects ->addObject(tmpFF);
//  tmpFF->release();
//  
//  tmpFF->initWithCoolSheet(tmpQuest->getWeather(),FONT_WHITE,0.25,200,true);
//  tmpFF->updatePosition(ccp(100,320-95));
//  tmpFF->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  
//  tmpSpt->initWithFile(CCString::create("buttonGreen.png"));
//  tmpSpt->updatePosition(ccp(480-150,320-45));
//  tmpSpt->updateOpacity(255);
//  tmpSpt->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpSpt);
//  tmpSpt->release(); 
//  
//  tmpSpt->initWithFile(CCString::create("buttonRed.png"));
//  tmpSpt->updatePosition(ccp(480-60,320-45));
//  tmpSpt->updateOpacity(255);
//  tmpSpt->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpSpt);
//  tmpSpt->release(); 
//  
//   tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
//  tmpSpt->updatePosition(ccp(480-150,320-45-65));
//  tmpSpt->updateOpacity(255);
//  tmpSpt->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpSpt);
//  tmpSpt->release();
//  
//                           tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
//  tmpSpt->updatePosition(ccp(480-60,320-45-65));
//  tmpSpt->updateOpacity(255);
//  tmpSpt->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpSpt);
//  tmpSpt->release();
//  
//  tmpFF->initWithCoolSheet(CCString::create("Accept"),FONT_WHITE,0.35,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(480-150,320-45+12));
//  tmpFF->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  tmpFF->initWithCoolSheet(CCString::create("Cancel"),FONT_WHITE,0.35,200,true);
// tmpFF->bCenter = true;
// tmpFF->updatePosition(ccp(480-150,320-45+12));
// tmpFF->addToLayer(this,83);
// menuLayerObj->eventObjects->addObject(tmpFF);
// tmpFF->release();
//  
//  
//  tmpFF->initWithCoolSheet(CCString::create("Back"),FONT_WHITE,0.35,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(480-150,320-45-65+12));
//  tmpFF->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  tmpFF->initWithCoolSheet(CCString::create("Next"),FONT_WHITE,0.35,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(480-150,320-45-65+12));
//  tmpFF->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//  tmpFF->initWithCoolSheet(CCString::createWithFormat("Mission: %d of %d",menuLayerObj->questMenu+1,menuLayerObj->filteredQuests->count()),FONT_WHITE,0.25 ,200,true);
//  tmpFF->bCenter = true;
//  tmpFF->updatePosition(ccp(480-120,320-150));
//  tmpFF->addToLayer(this,83);
//  menuLayerObj->eventObjects->addObject(tmpFF);
//  tmpFF->release();
//  
//  
//}
//                           
//void Scripts::addMapEvent(CCArray * data)
//{
//     
// 
//  gameEvent * tmpEvent =   new gameEvent();
//  tmpEvent->initWithData(data,menuLayerObj);
// menuLayerObj->mapEvents->addObject(tmpEvent);
// tmpEvent->release();
// 
//}
//
//
//void Scripts::showCredits() 
//{
// 
// menuLayerObj->creditsTimer = 0;
// menuLayerObj->bTalkButtonTouched = false;
// 
// 
//  CoolSprite * tmpSpt = new CoolSprite();
//  tmpSpt->initWithFile(CCString::create("bg1.png"));
// tmpSpt->updatePosition(ccp(240,160));
// tmpSpt->updateOpacity(255);
// tmpSpt->addToLayer(this,1000);
// menuLayerObj->eventObjects->addObject(tmpSpt);
// tmpSpt->release();
// 
// 
// 
// 
//    CoolFreeform * tmpFF = new CoolFreeform();
//    tmpFF->initWithCoolSheet(CCString::create("THANK YOU FOR PLAYING!"),FONT_WHITE,0.45,300,true);
//   tmpFF->bCenter = true;
//   tmpFF->updatePosition(ccp(240,320-10));
//   tmpFF->addToLayer(this,1001);
//   menuLayerObj->eventObjects->addObject(tmpFF);
//   tmpFF->release();
//   
//   tmpFF->initWithCoolSheet(CCString::create("A Misnomer Studios Production." ),FONT_WHITE,0.35,380,false);
//    
//    tmpFF->bCenter = true;
//    tmpFF->updatePosition(ccp(240,320-30));
//    tmpFF->addToLayer(this,1001);
//    menuLayerObj->eventObjects->addObject(tmpFF);
//    tmpFF->release();
//   
//   tmpFF->initWithCoolSheet(CCString::create("Developed by Benjamin Hill" ),FONT_WHITE,0.25,380,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-50));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//
//   
//   tmpFF->initWithCoolSheet(CCString::create("Artwork By:"),FONT_WHITE,0.35,300,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-80));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//
//   
//   tmpFF->initWithCoolSheet(CCString::create("Princess-Phoenix - Monsters"),FONT_WHITE,0.30,300,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-100));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//   
//   tmpFF->initWithCoolSheet(CCString::create("BoOmxBiG - Tileset") ,FONT_WHITE,0.30,300,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-120));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//   
//   tmpFF ->initWithCoolSheet(CCString::create("Heather Farnsworth - Characters"),FONT_WHITE,0.30,300,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-140));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//   
//   
//   
//   tmpFF->initWithCoolSheet(CCString::create("Thanks:"),FONT_WHITE,0.35,300,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-160));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//   
//   
//   tmpFF ->initWithCoolSheet(CCString::create("Sharks - Bugging me like a true friend"),FONT_WHITE,0.28,330,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-180));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//                            
//   tmpFF->initWithCoolSheet(CCString::create("Chloe - Being an Amazing Wife!"),FONT_WHITE,0.30,300,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-200));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release(); 
//   
//   
//   tmpFF->initWithCoolSheet(CCString::create("SoundJay - Music"),FONT_WHITE,0.3,300,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-220));
//                            tmpFF->addToLayer(this,1001);
//                           menuLayerObj-> eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//   
//   tmpFF->initWithCoolSheet(CCString::create("And Monster Ranchers Everywhere!" ),FONT_WHITE,0.3,300,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-240));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//   
//   tmpFF->initWithCoolSheet(CCString::create("www.monsterranch.com"),FONT_WHITE,0.25,300,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-260));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//
//   
//   
//   
//   tmpFF->initWithCoolSheet(CCString::create("Tap to Continue Playing."),FONT_WHITE,0.35,320,false);
//                            tmpFF->bCenter = true;
//                            tmpFF->updatePosition(ccp(240,320-290));
//                            tmpFF->addToLayer(this,1001);
//                            menuLayerObj->eventObjects->addObject(tmpFF);
//                            tmpFF->release();
//
//   
//   /*
//    tmpSpt = [[CoolSprite alloc] initWithFile:@"geoMonsters.png"];
//    [tmpSpt updatePosition:ccp(160,30)];
//    [tmpSpt updateOpacity:255];
//    [tmpSpt addToLayer:self z:1001];
//    [eventObjects addObject:tmpSpt];
//    [tmpSpt release];
//    */
//   
//}
//
//void Scripts::addFaintScriptAndKO()
//{
//    menuLayerObj->activeScript->removeAllObjects();
//    
//    
//    menuLayerObj->activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Display Message\tNone of your Monsters can battle anymore.^"), CCString::create("\t")));
//    
//    menuLayerObj->activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Display Message\tYour GeoGear starts glowing red... ..^"), CCString::create("\t")));
//    
//    menuLayerObj->activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Change Weather\tNormal"), CCString::create("\t")));
//
//    
//    menuLayerObj->activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Set Zone\t"), CCString::create("\t")));
//    
//    
//    menuLayerObj->activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Change Music\tNewGameLoop^"), CCString::create("\t")));
//    
//    
//    menuLayerObj->activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Full Restore\t"), CCString::create("\t")));
//    
//    
//    menuLayerObj->activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Relocate User\thomeUpper.tmx^8^13"), CCString::create("\t")));
//    
//    menuLayerObj->activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Display Message\tAgh! I've got a Headache!^"), CCString::create("\t")));
//    
//}                          
//  
//                            
//
//                            
//
//void Scripts::scriptModifyWithConditionResult(bool bResult)
//{
//    if( menuLayerObj->activeScript->count() == 0 ) 
//    {
//        return;
//    }
//    
//    
//    /*
//     NSLog([NSString stringWithFormat:@"****** BEFORE CHECK ******* "]);
//     for(NSArray * tmpRay in activeScript) {
//     NSLog([tmpRay objectAtIndex:0]);
//     }
//     */
//    
//    int tickIf = 0;
//    int tickElse = 0;
//    
//    bool bottomIf = false;
//    bool bottomElse = false;
//    
//    
//    int lineNo = 0;
//    while(lineNo < menuLayerObj->activeScript->count() )
//    {
//        
//        
//        CCArray * scriptToExecute =  CCArray::create(((CCString*)menuLayerObj->activeScript->objectAtIndex(lineNo)));
//        CCString * function = (CCString*)scriptToExecute->objectAtIndex(0);
//        
//        if(function->isEqual(CCString::create("IF")))
//        {
//            tickIf++;
//            
//            if( tickIf == 1 && tickElse == 0 ) 
//            {
//                bottomIf = true;
//            }
//        }
//        if( function->isEqual(CCString::create("ELSE")))
//        {
//            tickIf--;
//            tickElse++;
//            
//            if( tickIf == 0 && tickElse == 1) 
//            {
//                bottomIf = false;
//                bottomElse = true;
//            }
//            
//        }
//        
//        if(function->isEqual(CCString::create("END IF")))
//        {
//            tickElse--;
//            
//            if( tickIf == 0 && tickElse == 0) 
//            {
//                bottomIf = false;
//                bottomElse = false;
//            }
//            
//        }
//        
//        
//        if( bResult ) 
//        {
//            //If the if statement succeeded remove the entire else statement
//            if( bottomElse ) 
//            {
//                menuLayerObj->activeScript->removeObjectAtIndex(lineNo);
//                lineNo--;
//            }
//        } 
//        else 
//        {
//            //If the if statement succeeded remove the entire if statement
//            if( bottomIf ) 
//            {
//                menuLayerObj->activeScript->removeObjectAtIndex(lineNo);
//                lineNo--;
//            }
//        }
//        
//        
//        if( tickIf == 0 && tickElse == 0 )
//        {
//            //Remove End If
//            if( lineNo >= 0 ) 
//                menuLayerObj->activeScript->removeObjectAtIndex(lineNo);
//            break;
//        }
//        lineNo++;
//    }
//    
//    //Remove If or Else
//    menuLayerObj->activeScript->removeObjectAtIndex(0);
//    //Remove the Initial If (or Else) Statement and Continue Processing
//    //[activeScript removeObjectAtIndex:0];
//    
//    /*
//     NSLog([NSString stringWithFormat:@"****** AFTER CHECK ******* "]);
//     for(NSArray * tmpRay in activeScript) {
//     NSLog([tmpRay objectAtIndex:0]);
//     }
//     */
//    
//    
//    this->scriptProgress();
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
//
//
//
//
