////
////  menuScene+Help.cpp
////  Geosociety
////
////  Created by macbookpro on 02/12/13.
////  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
////
//
//#include "menuScene+Help.h"
//#include "gearLayer.h"
//
//
//
//#pragma mark -
//#pragma mark === HELP FUNCTIONS ===
//#pragma mark -
//
//
//
//void Help::displayHelpScreen(bool bSet)
//{
//	//09Susan.png
//	
//	//[self playSong:MUSIC_HELP];
//	
//	if( bSet )
//    {
//		menuLayerObj->menuStage = 100;
//	}
//    else 
//    {
//		menuLayerObj->menuStage=menuLayerObj->menuStage+1;
//		if( menuLayerObj->menuStage > 110)
//        {
//			menuLayerObj->gearMenuLayer->displayIndex();
//			return;
//		}
//	}
//	menuLayerObj->helpTimer = 0;
//	
//	CoolFreeform * tmpFF = new CoolFreeform;
//	
//	menuLayerObj->menuItems-> removeAllObjects();
//	
//	CoolSprite * tmpSpt = new CoolSprite; 
//	tmpSpt->initWithFile(CCString::create("bg1.png"));
//    tmpSpt-> updatePosition(ccp(160,240));
//	tmpSpt-> updateOpacity(255);
//	tmpSpt-> addToLayer(menuLayerObj,10);
//	menuLayerObj->menuItems-> addObject(tmpSpt);
//	tmpSpt-> release();
//	
//	
//	tmpSpt ->initWithFile(CCString::create("17Peppermint.png"));
//	tmpSpt-> updatePosition(ccp(80,480-80));
//	tmpSpt-> updateScale(0.5);
//	tmpSpt-> updateOpacity(255);
//	tmpSpt-> addToLayer(menuLayerObj,10);
//	menuLayerObj->menuItems-> addObject(tmpSpt);
//	tmpSpt-> release();
//	
//	if( menuLayerObj->menuStage == 100 )
//    {
//        
//        tmpFF->initWithCoolSheet(CCString::create("Hello There! So your the new recruit."), FONT_WHITE ,0.5 ,310,false);
//		tmpFF-> updatePosition(ccp(10,320));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//		
//	} 
//    else if(menuLayerObj-> menuStage == 101 ) 
//    {
//		
//		tmpFF ->initWithCoolSheet(CCString::create("Well I'm sure you've seen about all the power outages on the News Lately. It seems we finally have an explanation."), FONT_WHITE ,0.4 ,310 ,false);
//		tmpFF-> updatePosition(ccp(10,320));
//		tmpFF-> addToLayer(menuLayerObj, 20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//	} 
//    else if( menuLayerObj->menuStage == 102 ) 
//    {
//		
//		tmpSpt ->initWithFile(CCString::create("ZenvsHinoDark.png"));
//		tmpSpt-> updatePosition(ccp(160,98));
//		tmpSpt-> updateOpacity(255);
//		tmpSpt-> addToLayer(menuLayerObj,15);
//		
//		tmpSpt-> updateScale(1.5);
//		
//		menuLayerObj->menuItems-> addObject(tmpSpt);
//		tmpSpt-> release();
//		
//		tmpFF ->initWithCoolSheet(CCString::create("The really strong monsters fight vicious battles with each other across our power grid."),FONT_WHITE ,0.4 ,310 ,false);
//		tmpFF-> updatePosition(ccp(10,320-200));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems ->addObject(tmpFF);
//		tmpFF-> release();
//		
//	} 
//    else if( menuLayerObj->menuStage == 103 )
//    {
//		
//		tmpSpt -> initWithFile(CCString::create("ZenVsHinoChaosPlague.png"));
//		tmpSpt-> updatePosition(ccp(-80,480/2));
//		tmpSpt-> updateOpacity(255);
//		tmpSpt-> addToLayer(menuLayerObj,15);
//		
//		tmpSpt-> updateScale(1.2);
//		
//		menuLayerObj->menuItems-> addObject(tmpSpt);
//		tmpSpt-> release();
//		
//		tmpFF -> initWithCoolSheet(CCString::create("Our Job is to Tame and Log every GeoMonster we can find! To make it interesting we have Tornaments and Challenges"), FONT_WHITE ,0.4 ,310 ,false);
//		tmpFF-> updatePosition(ccp(10,320-200));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//	} 
//    else if( menuLayerObj->menuStage == 104 )
//    {
//		
//		tmpFF ->initWithCoolSheet(CCString::create("Is there anything else you would like to know about?" ),FONT_WHITE ,0.5 ,310 ,true);
//		tmpFF-> updatePosition(ccp(10,320));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//		
//		tmpFF ->initWithCoolSheet(CCString::create("How do my monsters grow?"), FONT_GREEN ,0.4 ,310 ,true);
//		tmpFF->bCenter = true;
//		tmpFF-> updatePosition(ccp(160,240));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems->addObject(tmpFF);
//		tmpFF-> release();
//		
//		tmpFF ->initWithCoolSheet(CCString::create("How do I tame monsters?"), FONT_GREEN ,0.4 ,310 ,true);
//		tmpFF->bCenter = true;
//		tmpFF-> updatePosition(ccp(160,240-40));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//		tmpFF ->initWithCoolSheet(CCString::create("Do I need my GPS enabled?"), FONT_GREEN ,0.4 ,310 ,true);
//		tmpFF->bCenter = true;
//		tmpFF-> updatePosition(ccp(160,240-80));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//		tmpFF ->initWithCoolSheet(CCString::create("Should I battle other Tamers?"), FONT_GREEN ,0.34 ,310 ,true);
//		tmpFF->bCenter = true;
//		tmpFF-> updatePosition(ccp(160,240-120));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//		tmpFF ->initWithCoolSheet(CCString::create("How does breeding work?" ),FONT_GREEN ,0.4 ,310 ,true);
//		tmpFF->bCenter = true;
//		tmpFF-> updatePosition(ccp(160,240-160));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF ->release();
//		
//		
//		tmpFF ->initWithCoolSheet(CCString::create("Nothing, Lets Go!"), FONT_RED ,0.5 ,310 ,false);
//		tmpFF->bCenter = true;
//		tmpFF-> updatePosition(ccp(160,32));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//	}
//    else if( menuLayerObj->menuStage == 105 ) 
//    {
//		//Monster Grow
//		
//		
//		tmpFF ->initWithCoolSheet(CCString::create("Every Time your Monster Knocks Out another Monster in Battle it will gain some Experience. With enough experience a monster will grow levels which provides you with stat points to allocate to Attack, Defense, Speed or Intelligence. Some monsters will even Mutate automatically when they reach a certain level."), FONT_WHITE ,0.4 ,310 ,false);
//		tmpFF-> updatePosition(ccp(10,320));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF ->release();
//		
//	}
//    else if(menuLayerObj-> menuStage == 106 ) 
//    {
//		//Monster Taming
//		
//		
//		tmpFF -> initWithCoolSheet(CCString::create("From the home screen tap on 'Hunt' from here you should Bait for Monsters or Attack Monsters your friends have Baited. Once you defeat a monster you have the option of Taming it or leaving."), FONT_WHITE ,0.4 ,310 ,false);
//		tmpFF-> updatePosition(ccp(10,320));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//	} 
//    else if(menuLayerObj-> menuStage == 107 )
//    {
//		//Do I need GPS
//		
//		tmpFF -> initWithCoolSheet(CCString::create("The iPhone, iPad or iPod GPS is needed to play GeoMonsters. Within some Countries this functionality does not work. We appologize for this but there is nothing we can do about it."), FONT_WHITE ,0.4 ,310 ,false);
//		tmpFF-> updatePosition(ccp(10,320));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//	} 
//    else if(menuLayerObj-> menuStage == 108 ) 
//        {
//		//Battle Others
//		
//            tmpFF ->initWithCoolSheet(CCString::create("Everytime you win a battle against another Tamer using the World Map or Hunting Screens you will gain one eighth of the Coin they are holding. You can protect your Coin by depositing it in the town bank."), FONT_WHITE ,0.4 ,310,false);
//		tmpFF-> updatePosition(ccp(10,320));
//		tmpFF-> addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//		
//	} 
//    else if(menuLayerObj-> menuStage == 109 ) 
//        {
//		//Breeding
//		
//            tmpFF ->initWithCoolSheet(CCString::create("Monster Breeding requires two monsters level 10 or above of each gender. Both parents are lost as they run away once an egg is produced. Each time a monster is breed the resulting Egg will have an additional Stat Point to allocate for each level. Monster Breeding is one of the only ways to gather Divine or Demonic GeoMonsters. " ),FONT_WHITE ,0.4 ,310 ,false);
//		tmpFF ->updatePosition(ccp(10,320));
//		tmpFF ->addToLayer(menuLayerObj,20);
//		menuLayerObj->menuItems-> addObject(tmpFF);
//		tmpFF-> release();
//	}
//}
//
//
//void Help::helpTick()
//{
//	CoolFreeform * tmpFF = new CoolFreeform;
//	menuLayerObj->helpTimer++;
//	
//	if( menuLayerObj->menuStage == 100 ) 
//    {
//		if( menuLayerObj->helpTimer == 60 )
//        {
//			
//			tmpFF ->initWithCoolSheet(CCString::create("We've heard lots about you already, but you should still fill in your profile sometime."), FONT_WHITE ,0.4 ,310 ,false);
//			tmpFF-> updatePosition(ccp(10,320-80));
//			tmpFF-> addToLayer(menuLayerObj,20);
//			menuLayerObj->menuItems-> addObject(tmpFF);
//			tmpFF-> release();
//			
//           
//			((CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(2))->finish();
//           
//        }
//		
//		if( menuLayerObj->helpTimer == 160 )
//        {
//			
//			tmpFF->initWithCoolSheet(CCString::create("Let me explain exactally what it is we do here. That should clear things up a bit." ),FONT_WHITE ,0.4 ,310 ,false);
//			tmpFF-> updatePosition(ccp(10,320-160));
//			tmpFF-> addToLayer(menuLayerObj,20);
//			menuLayerObj->menuItems-> addObject(tmpFF);
//			tmpFF-> release();
//			
//            //DEEPAK_DOUBT
//            ((CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(3))->finish();
//        }
//		
//		
//		if(menuLayerObj-> helpTimer == 290 )
//        {
//			this->displayHelpScreen(false);
//		}
//	} 
//    else if( menuLayerObj->menuStage == 101 ) 
//    {
//		
//		if( menuLayerObj->helpTimer == 140 )
//        {
//			
//			tmpFF -> initWithCoolSheet(CCString::create("We have discovered Electro-Organisms are the cause, but we know very little about them."), FONT_WHITE ,0.4 ,310 ,false);
//			tmpFF-> updatePosition(ccp(10,200));
//			tmpFF-> addToLayer(menuLayerObj,20);
//			menuLayerObj->menuItems-> addObject(tmpFF);
//			tmpFF-> release();
//			
//            
//            //DEEPAK_DOUBT
//			objectOfCoolFreeform= (CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(2);
//            objectOfCoolFreeform->finish();
//			
//		}
//		
//		if( menuLayerObj->helpTimer == 300 ) 
//        {
//			this-> displayHelpScreen(false);
//			
//		}
//		
//	} 
//    else if(menuLayerObj-> menuStage == 102 ) 
//    {
//		
//		CoolSprite * tmpSpt =  (CoolSprite*)menuLayerObj->menuItems-> objectAtIndex(2);
//		if( tmpSpt->y + 3 < 392 )
//        {
//			tmpSpt-> updatePosition(ccp(tmpSpt->x,tmpSpt->y+3));
//		}
//		
//		if( tmpSpt->myScale - 0.01 > 1 ) 
//        {
//			tmpSpt-> updateScale(tmpSpt->myScale - 0.01);
//		}
//		
//		
//		if( menuLayerObj->helpTimer == 140 )
//        {
//			this-> displayHelpScreen(false);
//			
//		}
//		
//	}
//    else if(menuLayerObj-> menuStage == 103 ) 
//    {
//		CoolSprite * tmpSpt =(CoolSprite*)menuLayerObj->menuItems-> objectAtIndex(2);
//		
//       		
//        if( tmpSpt->x + 3 < 160 )
//        {
//			tmpSpt ->updatePosition(ccp(tmpSpt->x+3,tmpSpt->y));
//		}
//		
//		if( tmpSpt->myScale - 0.005 > 1 ) 
//        {
//			tmpSpt ->updateScale(tmpSpt->myScale - 0.005);
//		}
//		
//		if( menuLayerObj->helpTimer == 180 ) 
//        {
//			this-> displayHelpScreen(false);
//			
//		}
//		
//		
//	}
//    else if(menuLayerObj-> menuStage == 104 ) 
//    {
//		
//		
//	}
//}
//
//
//void Help::helpTouch(CCPoint touch)
//{
//	//[self displayHelpScreen: false];
//	
//    
//    
//    
//    
//	if(menuLayerObj-> menuStage == 100 )
//    {
//		if( menuLayerObj->helpTimer < 59 )
//        {
//			menuLayerObj->helpTimer = 59;
//		}
//        else
//        {
//			if(menuLayerObj-> helpTimer < 159 )
//            {
//				menuLayerObj->helpTimer = 159;
//			} 
//            else 
//            {
//				if( menuLayerObj->menuItems->count() > 4 )
//                {
//                     objectOfCoolFreeform= (CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(4);
//					if((menuLayerObj-> helpTimer < 289 && objectOfCoolFreeform->isFinished())== false ) 
//                    {
//						objectOfCoolFreeform-> finish();
//					} 
//                    else if(menuLayerObj-> helpTimer < 289 )
//                    {
//						menuLayerObj->helpTimer = 289;
//					}
//				}
//			}
//		}
//	}
//    else if( menuLayerObj->menuStage == 101 )
//    {
//		if(menuLayerObj-> helpTimer < 139 ) 
//        {
//			menuLayerObj->helpTimer = 139;
//		} 
//        else 
//        {
//			if( menuLayerObj->menuItems-> count() > 3 ) 
//            {
//                 objectOfCoolFreeform= (CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(3);
//				if( (menuLayerObj->helpTimer<299 && objectOfCoolFreeform->isFinished()) == false ) 
//                {
//					 objectOfCoolFreeform->finish();
//				} 
//                else if( menuLayerObj->helpTimer < 299 ) 
//                {
//					menuLayerObj->helpTimer = 299;
//				}
//			}
//		}
//	}
//    else if(menuLayerObj-> menuStage == 104 ) 
//    {
//		
//		if( touch.y < 240 + 20 && touch.y > 240 - 20 )
//        {
//			
//			menuLayerObj->menuStage = 104;
//			this-> displayHelpScreen(false);
//			return;
//		} 
//        else if( touch.y < 200 + 20 && touch.y > 200 - 20 )
//        {
//			
//			menuLayerObj->menuStage = 105;
//			this->displayHelpScreen(false);
//			return;
//		} 
//        else if( touch.y < 160 + 20 && touch.y > 160 - 20 ) 
//        {
//			
//			menuLayerObj->menuStage = 106;
//			this->displayHelpScreen(false);
//			return;
//		}
//        else if( touch.y < 120 + 20 && touch.y > 120 - 20 )
//        {
//			
//			menuLayerObj->menuStage = 107;
//			this-> displayHelpScreen(false);
//			return;
//		} 
//        else if( touch.y < 80 + 20 && touch.y > 80 - 20 ) 
//        {
//			
//			menuLayerObj->menuStage = 108;
//			this->displayHelpScreen(false);
//			return;
//		} 
//		
//		
//		if( touch.y < 40 ) 
//        {            
//			
//            menuLayerObj->saveToUserDefaults(CCString::createWithFormat("USER.%d.POSITION",menuLayerObj->profileNumber),(CCString::createWithFormat("homeUpper.tmx,8,11")));
//            
//			gameEngineScene->displayGame(CCString::create("homeUpper.tmx"), ccp(8,11));
//			
//		}
//	}
//	
//	if( menuLayerObj->menuStage == 105 )
//    {
//		//Monster Grow
//		
//       
//        objectOfCoolFreeform= (CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(2);
//		if( objectOfCoolFreeform->isFinished() == false ) 
//        {
//            objectOfCoolFreeform->finish();
//		}
//        else 
//        {
//			menuLayerObj->menuStage = 103;
//			this-> displayHelpScreen(false);
//		}
//	} 
//    else if( menuLayerObj->menuStage == 106 ) 
//    {
//		//Monster Taming
//		
//        
//        objectOfCoolFreeform= (CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(2);
//
//		if( objectOfCoolFreeform->isFinished() == false )
//        {
//			objectOfCoolFreeform-> finish();
//		}
//        else
//        {
//			menuLayerObj->menuStage = 103;
//			this->displayHelpScreen(false);
//		}
//	} 
//    else if( menuLayerObj->menuStage == 107 ) 
//    {
//		//Do I need GPS
//        objectOfCoolFreeform= (CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(2);
//		if( objectOfCoolFreeform->isFinished() == false ) 
//        {
//			objectOfCoolFreeform-> finish();
//		} 
//        else
//        {
//			menuLayerObj->menuStage = 103;
//			this->displayHelpScreen(false);
//        }
//	} 
//    else if( menuLayerObj->menuStage == 108 ) 
//    {
//		//Battle Others
//        objectOfCoolFreeform= (CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(2);
//		if( objectOfCoolFreeform-> isFinished() == false )
//        {
//			objectOfCoolFreeform-> finish();
//		} 
//        else 
//        {
//			menuLayerObj->menuStage = 103;
//			this->displayHelpScreen(false);
//		}
//	} 
//    else if( menuLayerObj->menuStage == 109 )
//    {
//		//Breeding
//        objectOfCoolFreeform= (CoolFreeform*)menuLayerObj->menuItems->objectAtIndex(2);
//		if( objectOfCoolFreeform-> isFinished() == false ) 
//        {
//			objectOfCoolFreeform-> finish();
//		} 
//        else 
//        {
//			menuLayerObj->menuStage = 103;
//			this->displayHelpScreen(false);
//        }
//	}
//	
//}
//
//
//
//
