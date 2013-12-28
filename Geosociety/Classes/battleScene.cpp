//
//  battleScene.cpp
//  Geosociety
//
//  Created by macbookpro on 06/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "battleScene.h"


battleScene *battleScene::initWithParent(menuLayer* parentObj ,CCArray* data)
{
//	self = [super init];
//	if( self != nil) 
	{
		layer = new battleLayer();
        layer->initWithParent(parentObj, data, this);

		this->addChild(layer,1);
		
	}
	return this;
}

void battleScene:: startTimer()
{
	//Create a tick method to be called at the specified interval

    this->schedule(schedule_selector(battleScene::tick),0.05);
}

void battleScene::tick(float dt)
{
	layer->evaluate();
}

void battleScene:: resignTimer()
{
    this->unschedule(schedule_selector(battleScene::resignTimer));
}


battleLayer::battleLayer()
{
    
}

battleLayer*battleLayer::initWithParent(menuLayer* parentObj,CCArray* data, battleScene* bscene)
{
//	self = [super init];
//	if( self != nil ) 
    {
		parent = parentObj;
        parentScene = bscene;
        
		aniSprite = NULL;
        bAnimatingAttack = false;
        attackAniFrame = 0;
        attackAniFrameTick = 0;
        attackAniFrameCount = 0;
        
        
		staticItems =  new CCArray();
		menuItems = new CCArray();
		battleItems = new CCArray();
		
		opponents = new CCArray();
		team = new CCArray();
		
		battleMessages = new CCArray();
		battleAnimations = new CCArray();
        
        battleEventQueue = new CCArray();
        
		for(int i=1;i<data->count(); i++) 
        {
            
            
			CCArray * tmpOpponentRow = CCArray::create(((CCString*)Convertstring->componentsSeparatedByString(((CCString*)data->objectAtIndex(i)), CCString::create("."))));
			if( tmpOpponentRow->count() > 0 ) 
            {
				for(int k=0;k<tmpOpponentRow->count();k++)
                {
					if( !(((CCString*)tmpOpponentRow->objectAtIndex(k))->isEqual(CCString::create(""))))
                    {
						CCArray * dataRay =  CCArray::create(((CCString*)Convertstring->componentsSeparatedByString(((CCString*)tmpOpponentRow->objectAtIndex(k)), CCString::create(","))));
						battleObject * bo =  new battleObject();
                        bo->initWithData(dataRay,i,parent->getDatabase(),parent);
						bo->bPlayersTeam = false;
						
						if( i==1) 
                        {
							if( k == 0 ) 
								fopOpponent1 = bo;
                                if( k == 1 ) 
                                    fopOpponent2 = bo;
                                    if( k == 2 ) 
                                        fopOpponent3 = bo;
                        }
						
						opponents->addObject(bo);
						bo->release();
					}
				}
			}
		}
		
        
        //Create a Sorted List of Users Monsters
        CCArray * monsters = CCArray::create(parentObj->getMonsters());
        for( int i = 1; i <10 ; i++)
        {
            for(int i=0; i<monsters->count();i++) 
            {
                monster * mon =(monster*)monsters->objectAtIndex(i);
                if( mon->position == i  )
                {
                    battleObject * bo = new battleObject();
                   bo->initWithMonster(mon,parent);
                    bo->bPlayersTeam = true;
                    
                    team->addObject(bo);
                    
                }
            }
        }
        
        
        
        
        
        
        
		//Cycle Through Hero's Monsters adding them to the team and fop.
        int placesFilled = 1;
		for(int i=0;i<team->count();i++)
        {
            battleObject * mon= (battleObject*)team->objectAtIndex(i);
            if( placesFilled == 4 )
            {
                break;
            }
            
            if( mon->hpLeft > 0 ) 
            {
                if( placesFilled == 1 )
                {
                    fopTeam1 = mon;
                } 
                else if( placesFilled == 2 )
                {
                    fopTeam2 = mon;
                } 
                else if( placesFilled == 3 )
                {
                    fopTeam3 = mon;
                } 
                placesFilled++;
            }
        }
        
        
        
		
		//Cycle through all monsters in the battle and find the fastest.
		//TODO: Evaluate if this needs to just use the monsters in the fop at the given time.
		int fastestSpeed = 0;
		for(int i=0; i<opponents->count();i++)
        {
            battleObject * battleObj= (battleObject*)opponents->objectAtIndex(i);
			if( battleObj->spd > fastestSpeed)
				fastestSpeed = battleObj->spd;
        }
		for(int i=0; i<team->count();i++)
        {
            battleObject * battleObj= (battleObject*)team->objectAtIndex(i);

			if( battleObj->spd > fastestSpeed)
				fastestSpeed = battleObj->spd;
        }
		for(int i=0; i<opponents->count();i++)
        {
            battleObject * battleObj= (battleObject*)opponents->objectAtIndex(i);
			battleObj->speedOfFastestMonsterInBattle( fastestSpeed);
		}
		for(int i=0; i<team->count();i++)
        {
            battleObject * battleObj= (battleObject*)team->objectAtIndex(i);
			battleObj->speedOfFastestMonsterInBattle( fastestSpeed);
		}
		
		
		CoolSprite * tmpSpt = NULL;
		CoolFreeform * tmpFF = NULL;
		
        
        if( parentObj->questWeather() == 5 )
        {
            tmpSpt->initWithFile(CCString::create("bg-snowforest.png"));
        } 
        else 
        {
            tmpSpt-> initWithFile(CCString::create("bg-forest.png"));
        }
		
		tmpSpt->updatePosition(ccp(parent->sWidth()/2,160));
		tmpSpt->updateOpacity(255);
		tmpSpt->addToLayer(this,1);
		staticItems->addObject(tmpSpt);
		tmpSpt->release();
		
        
        
        
        
		if( ((CCString*)Convertstring->lowercaseString((CCString*)data->objectAtIndex(0)))->isEqual(CCString::create("true")) )
        {
            bCanRun = true;
            bCanTame = true;
		} 
        else 
        {
            bCanRun = false;
            bCanTame = false;
		}
        
        /*
         if( [[[data objectAtIndex:0] lowercaseString] isEqualToString:@"true"] ) {
         tmpSpt = [[CoolSprite alloc] initWithFile:@"cyperbg.png"];
         } else {
         tmpSpt = [[CoolSprite alloc] initWithFile:@"grassbg.png"];
         }
         [tmpSpt updatePosition:ccp(160,480-100)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:11];
         [staticItems addObject:tmpSpt];
         [tmpSpt release];
         
         
         */
		
        
        
		tmpSpt->initWithFile(CCString::create("buttonEmpty.png"));
		tmpSpt->updatePosition(ccp(parent->sWidth()-36,246));
		tmpSpt->updateOpacity(255);
		tmpSpt->addToLayer(this,25);
		staticItems->addObject(tmpSpt);
		tmpSpt->release();
        
        tmpFF->initWithCoolSheet(CCString::create("AUTO:"),FONT_WHITE ,0.20,300,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(parent->sWidth()-34,258));
        tmpFF->addToLayer(this,26);
        staticItems->addObject(tmpFF);
        tmpFF->release();
        
        bAutoBattle = parent->bAutoBattle;
        
        
        if( bAutoBattle )
        {
            txtAutoBattle->initWithCoolSheet(CCString::create("ON"),FONT_RED,0.20,300,true);
        } else {
            txtAutoBattle ->initWithCoolSheet(CCString::create("OFF"),FONT_RED,0.225,300,true);
        }
        txtAutoBattle->bCenter = true;
        txtAutoBattle->updatePosition(ccp(parent->sWidth()-34,243));
        txtAutoBattle->addToLayer(this,26);
        
       /* PENDING_DEEPAK 
        
        [Flurry logEvent:@"Monster Battle Start" withParameters:
         [NSDictionary dictionaryWithObjectsAndKeys:
          [NSString stringWithFormat:@"%d",bAutoBattle],@"Auto Battle",
          [NSString stringWithFormat:@"%d",[team count]],@"Team Count",
          [NSString stringWithFormat:@"%d",[opponents count]],@"Oposition Count",
          [NSString stringWithFormat:@"%d",bCanTame],@"Wild Battle",
          [NSString stringWithFormat:@"%d",bCanRun],@"Trainer Battle",
          nil] ];
        */
        
        
        
		setTouchEnabled(true);
		
		this->displayTeamAndOpponents();
	}
	return this;
}




void battleLayer::toggleAutoBattle()
{
    bAutoBattle = !bAutoBattle;
    if( bAutoBattle )
    {
        txtAutoBattle->updateContent(CCString::create("ON"));
    } else
    {
         txtAutoBattle->updateContent(CCString::create("OFF"));
    }
    parent->bAutoBattle = bAutoBattle;
}





void battleLayer::addExpAni(int damage, CCPoint pos)
{
	
	//[self sfx: SOUND_ATTACKED];
	
	CoolSprite * tmpSpt = NULL;
	
	CCString * damageStr = CCString::createWithFormat("%d",damage);
	for(int i=0;i<damageStr->length();i++) 
    {
		CCString * charName = Convertstring->substringToIndex(damageStr, 1);
		charName = CCString::createWithFormat("%sb.png",charName->getCString());
		
		tmpSpt->initWithFile(charName);
		tmpSpt->updatePosition(ccp(pos.x-24 - (damageStr->length() * 24 / 2) + i * 24 - 24/2,pos.y));
		tmpSpt->addToLayer(this,50);
		tmpSpt->updateScale(0.4);
        tmpSpt->updateOpacity(200);
		battleAnimations->addObject(tmpSpt);
		tmpSpt->release();
		
	}
	
	tmpSpt->initWithFile(CCString::create("XP.png"));
	tmpSpt->updatePosition(ccp(pos.x - (damageStr->length() * 24 / 2) + damageStr->length() * 24 - 24/2,pos.y));
	tmpSpt->addToLayer(this,50);
	tmpSpt->updateScale(0.4);
	tmpSpt->updateOpacity(200);
    
	battleAnimations->addObject(tmpSpt);
	tmpSpt->release();
	
}



void battleLayer::addDamageAni(int  damage,CCPoint  pos)
{
	
	//[self sfx: SOUND_ATTACKED];
	
	CoolSprite * tmpSpt = NULL;
	
	CCString * damageStr = CCString::createWithFormat("%d",damage);
	for(int i=0;i<damageStr->length();i++)
    {
		CCString * charName = Convertstring->substringToIndex(damageStr, 1);
		charName = CCString::createWithFormat("%s.png",charName->getCString());
		tmpSpt->initWithFile(charName);
		tmpSpt->updatePosition(ccp(pos.x-24 - (damageStr->length() * 24 / 2) + i * 24 - 24/2,pos.y));
		tmpSpt->addToLayer(this,50);
		tmpSpt->updateScale(0.5);
        tmpSpt->updateOpacity(200);
		battleAnimations->addObject(tmpSpt);
		tmpSpt->release();
		
	}
	
	
    tmpSpt->initWithFile(CCString::create("dmg.png"));
	tmpSpt->updatePosition(ccp(pos.x - (damageStr->length() * 24 / 2) + damageStr->length() * 24 - 24/2,pos.y));
	tmpSpt->addToLayer(this,50);
	tmpSpt->updateScale(0.5);
	tmpSpt->updateOpacity(200);
    
}



CCPoint battleLayer::positionForTeam(int  oppNo)
{
	/*
     double breaker = 320 / 6;
     if( oppNo == 1 ) {
     return ccp(breaker, 335);
     } else if( oppNo == 2 ) {
     return ccp(breaker*3,335);
     } else {
     return ccp(breaker*5,335);
     } 
     */
    
    CCPoint pos = ccp(480-48,320-152);
    if( oppNo == 2 ) 
    {
        pos = ccp(480-100,320-202);
    } 
    else if( oppNo == 3 )
    {
        pos = ccp(480-48,320-252);
    }  
    
    return pos;
}



CCPoint battleLayer::positionForOpponent(int  oppNo)
{
	/*
     double breaker = 320 / 6;
     if( oppNo == 1 ) {
     return ccp(breaker, 335);
     } else if( oppNo == 2 ) {
     return ccp(breaker*3,335);
     } else {
     return ccp(breaker*5,335);
     } 
     */
    
    CCPoint pos = ccp(48,320-152);
    if( oppNo == 2 ) 
    {
        pos = ccp(100,320-202);
    } 
    else if( oppNo == 3 ) 
    {
        pos = ccp(48,320-252);
    }  
    return pos;
}

battleLayer::~battleLayer()
{
	battleItems->removeAllObjects();
	battleItems->release();
	
	battleMessages->removeAllObjects();
	battleMessages->release();
	
	battleAnimations->removeAllObjects();
	battleAnimations->release();
    
	staticItems->removeAllObjects();
	menuItems->removeAllObjects();
	staticItems->release();
	menuItems->release();
	
    if( aniSprite != NULL )
    {
        this->removeChild(aniSprite,false);
        aniSprite->release();
    }
	
    txtAutoBattle->release();
    
	opponents->removeAllObjects();
	team->removeAllObjects();
	opponents->release();
	team->release();
	
	
}




void battleLayer::autoBattleCalculate()
{
    
   
    
    CCArray * attacks = new CCArray();
    //PENDIG_DEEPAK CCArray::create( (CCString*)(parent->getDatabase()->getMonstersOfType((CCString*)attackingPresently->getMonster()->monid,(CCArray*)attackingPresently->intel)));
    attacks->retain();
    
    chosenAction = 0;
    int count = 0;

    for(int i=0; i<attacks->count();i++)
    {
        dataSkill * skill=(dataSkill*)attacks->objectAtIndex(i);
        if( skill->scope == 2 )
        {
            //attack everyone
            chosenAction = 1;
            chosenActionArg = skill->skillid;
            skillForTarget = skill;
            attacks->release();
            return;
        }
    }
    
    
    dataSkill * highest = (dataSkill*)attacks->objectAtIndex(0);
    for(int i=0; i<attacks->count();i++)
    {
        dataSkill * skill= (dataSkill*)attacks->objectAtIndex(i);
        if( skill->power > highest->power ) 
        {
            highest = skill;
        }
    }
    
    
    chosenAction = 1;
    chosenActionArg = highest->skillid;
    skillForTarget = highest;
    
    CCArray * targets = new CCArray();
    CCArray * targetsPosition = new CCArray();
    if( fopOpponent1 != NULL )
        if( fopOpponent1->hpLeft > 0 ) 
        {
            targets->addObject(fopOpponent1);
            targetsPosition->addObject(CCString::create("1"));
        }
    if( fopOpponent2 != NULL )
        if( fopOpponent2->hpLeft > 0 )
        {
            targets->addObject(fopOpponent2);
            targetsPosition->addObject(CCString::create("2"));
        }
    if( fopOpponent3 != NULL )
        if( fopOpponent3->hpLeft > 0 ) 
        {
            targets->addObject(fopOpponent3);
            targetsPosition->addObject(CCString::create("3"));
        }
    
    int lowestHp = 99999;
    int lowestNumber = 99999;
    for(int i=0;i<targets->count();i++)
    {
        if( ((battleObject *)targets->objectAtIndex(i))->hpLeft < lowestHp )
        {
            lowestHp = ((battleObject *)targets->objectAtIndex(i))->hpLeft;
            lowestNumber = ((CCString*)targetsPosition->objectAtIndex(i))->intValue();
        }
    }
    chosenActionTarget = lowestNumber;
    targets->release();
    targetsPosition->release();
    attacks->release();
    
}



void battleLayer::evaluate()
{
	for(int i=0;i<menuItems->count();i++) 
    {
		if( typeid(menuItems->objectAtIndex(i)) == typeid(CoolFreeform) )
        {
			((CoolFreeform*)menuItems->objectAtIndex(i))->evaluate();
		}
	}
    
	if( battleAnimations->count() > 0 )
    {
		for( int i = battleAnimations->count()-1;i>=0;i--)
        {
            if( typeid(battleAnimations->objectAtIndex(i)) == typeid(CoolLabel) )
            {
				CoolLabel * tmpLbl = (CoolLabel*)battleAnimations->objectAtIndex(i);
				
				tmpLbl->updatePosition(ccp(tmpLbl->x,tmpLbl->y+2));
				tmpLbl->intTag1++;
				
				if( tmpLbl->intTag1 > 10 ) 
                {
					battleAnimations->removeObjectAtIndex(i);
				}
				
				
			}
            else if(  typeid(battleAnimations->objectAtIndex(i)) == typeid(CoolSprite))
            {
				CoolSprite * tmpLbl = (CoolSprite*)battleAnimations->objectAtIndex(i);
				
				tmpLbl->updatePosition(ccp(tmpLbl->x,tmpLbl->y+2));
				tmpLbl->intTag1++;
				
				if( tmpLbl->intTag1 > 10 ) 
                {
					battleAnimations->removeObjectAtIndex(i);
				}
				
				
			}
		}
	}
    
    
    if( attackingPresently == NULL && battleEventQueue->count() == 0 && bAutoBattle )
    {
        bool bOneFainted = false;
        if( fopTeam1 != NULL )
            if( fopTeam1->hpLeft == 0 )
                bOneFainted = true;
                if( fopTeam2 != NULL )
                    if( fopTeam2->hpLeft == 0 )
                        bOneFainted = true;
                        if( fopTeam3 != NULL )
                            if( fopTeam3->hpLeft == 0 )
                                bOneFainted = true;
                                
                                if( bOneFainted  ) 
                                {
                                    this->checkForFaintedAllies();
                                }
        
        while( attackingPresently == NULL ) {
            this->advanceEachBattler();
        }
    }
    
	if( battleEventQueue->count() > 0 ) 
    {
        //Process Battle Queue
        this->processBattleQueue();
    } else if( attackingPresently == NULL  )
    {
        //Process Battle Timers - Because No-Ones Ready to Attack
        if( this->checkForFaintedAllies() )
            return;
        
        ticker++;
        this->advanceEachBattler();
	} 
    else 
    {
        //Process the Attackers Move. Human or AI.
        
        if( attackingPresently->bPlayersTeam ) 
        {
            //Process either the attack selection or the attack
            if( chosenAction == 0 )
            {
                //display Menu
                
                //process the auto batte function
                if( bAutoBattle ) 
                {
                    this->autoBattleCalculate();
                } 
                else 
                {
                    if( bAttackMenuDisplayed == false )
                    {
                        currentMenu = 0;
                        this->displayActionMenu();
                        bAttackMenuDisplayed = true;
                    }
                    else 
                    {
                        //Do Nothing - Waiting for input
                        
                    }
                }
            } 
            else 
            {
                //Process the action and set attackingPresently to nil or next object to attack.
                menuItems->removeAllObjects();
                bAttackMenuDisplayed = false;
                this->processAttack();
                chosenAction = 0;
                attackingPresently->reset();
                attackingPresently = NULL;
            }
        } 
        else
        {
            //Process the Opponents Attack.
            this->processAIAttack();
            attackingPresently->reset();
            attackingPresently = NULL;
        }
	}
}



void battleLayer::displayFaintedMonsterSelection()
{
    
}



bool battleLayer::checkForFaintedAllies()
{
    battleObject * mon;
    
    
    bool bHasTeamSpace = false;
    if( fopTeam1 != NULL ) 
        if( fopTeam1->hpLeft == 0 )
            bHasTeamSpace = true; mon = fopTeam1; 
            
            if( fopTeam2 != NULL ) 
                if( fopTeam2->hpLeft == 0 )
                    bHasTeamSpace = true; mon = fopTeam2; 
                    
                    if( fopTeam3 != NULL ) 
                        if( fopTeam3->hpLeft == 0 )
                            bHasTeamSpace = true; mon = fopTeam3; 
                            
                            bool bMustSwap = false;
                            for(int i=0;i<team->count();i++)
                            {
                                battleObject * oppMon= (battleObject*)team->objectAtIndex(i);
                                if( oppMon->hpLeft > 0 && oppMon != fopTeam1  && oppMon != fopTeam2  && oppMon != fopTeam3 ) 
                                {
                                    bMustSwap = true;
                                }
                            }
    
    if( bAutoBattle && bMustSwap) 
    {
        
        int count = 0;
        
        if( fopTeam3 != NULL ) 
            if( fopTeam3->hpLeft == 0 )
                attackingPresently = fopTeam3;
                
                if( fopTeam2 != NULL ) 
                    if( fopTeam2->hpLeft == 0 )
                        attackingPresently = fopTeam2;
                        
                        if( fopTeam1 != NULL ) 
                            if( fopTeam1->hpLeft == 0 )
                                attackingPresently = fopTeam1;
                                
                                    for(int i=0;i<team->count();i++)
                                    {
                                        battleObject * mon= (battleObject*)team->objectAtIndex(i);
                                    if( mon->hpLeft > 0 && mon != fopTeam1  && mon != fopTeam2  && mon != fopTeam3 )
                                    {
                                        chosenAction = 3;
                                        chosenActionArg = count;
                                        return true;
                                    }
                                    count++;
                                }
        
        return false;
    }
    
    
    
    
    
    if( bHasTeamSpace ) 
    {
        bool bMustSwap = false;
        for(int i=0;i<team->count();i++)
        {
            battleObject * oppMon= (battleObject*)team->objectAtIndex(i);
            if( oppMon->hpLeft > 0 && oppMon != fopTeam1  && oppMon != fopTeam2  && oppMon != fopTeam3 ) 
            {
                bMustSwap = true;
            }
        }
        
        if( bMustSwap ) 
        {
            if( mon != NULL ) 
            {
                CCString * tmpStr = CCString::createWithFormat("Select a Replacement Monster");
                this->addMessageToQueue(tmpStr);
            }
            currentMenu = 3;
            
            if( fopTeam3 != NULL ) 
                if( fopTeam3->hpLeft == 0 )
                    attackingPresently = fopTeam3;
                    
                    if( fopTeam2 != NULL ) 
                        if( fopTeam2->hpLeft == 0 )
                            attackingPresently = fopTeam2;
                            
                            if( fopTeam1 != NULL ) 
                                if( fopTeam1->hpLeft == 0 )
                                    attackingPresently = fopTeam1;
                                    
                                    bForcedMonsterSelection = true;
            battleEventQueue->addObject(CCString::create("monsterselection|"));
            return true;
        }
    }
    return false;
}



void battleLayer::processBattleQueue()
{
    
    if( !bDisplayingText )
    {
        //Not Displaying Something
        menuItems->removeAllObjects();
        
        CCString * queueItem =((CCString*)battleEventQueue->objectAtIndex(0));
        CCArray * function = CCArray::create(CCString::create(Convertstring->componentsSeparatedByString(queueItem, CCString::create("|"))->getCString()));
        
        
        CCString* tempstring= (CCString*)function->objectAtIndex(0);
        
        if( ((CCString*)Convertstring->lowercaseString(tempstring))->isEqual(CCString::create("msg")))
        {
            
            CoolFreeform * tmpFF = new CoolFreeform();
           tmpFF->initWithCoolSheet((CCString*)function->objectAtIndex(1),FONT_WHITE,0.35,300,false);
            tmpFF->bCenter = true;
            tmpFF->updatePosition(ccp(240,320-98));
            tmpFF->addToLayer(this,21);
            menuItems->addObject(tmpFF);
            tmpFF->release();
            
            
            CoolSprite * tmpSpt = new CoolSprite();
            tmpSpt->initWithFile(CCString::create("battleMsg.png"));
            tmpSpt->updatePosition( ccp(240,320-98-15-10));
            tmpSpt->updateOpacity(100);
            tmpSpt->addToLayer(this,20);
            menuItems->addObject(tmpSpt);
            tmpSpt->release();
            
            
            battleText = 0;
            bDisplayingText=true;
        } 
        else if(    ((CCString*)Convertstring->lowercaseString(((CCString*)battleEventQueue->objectAtIndex(0))))->isEqual(CCString::create("exp")))
        {
            
            CCPoint pos = (this->positionForTeam(((CCString*)function->objectAtIndex(1))-> intValue()));
            this->addExpAni(((CCString*)function->objectAtIndex(2))->intValue(),ccp(pos.x-30,pos.y));
            battleEventQueue->removeObjectAtIndex(0);
            
        } else if(((CCString*)Convertstring->lowercaseString(((CCString*)battleEventQueue->objectAtIndex(0))))->isEqual(CCString::create("end")))
        {
            //Evaluate Monster Tame Status
            bool bOneTamed = false;
            if( bBattleWon && bCanTame ) 
            {
                //Only One monster can be tamed from each encounter
                if( fopOpponent1 != NULL )
                {
                    bOneTamed = this->tameCheck( fopOpponent1);
                    if( bOneTamed == false )
                    {
                        if( fopOpponent2 != NULL )
                        {
                            bOneTamed = this->tameCheck( fopOpponent2);
                        }
                        if( bOneTamed == false ) 
                        {
                            
                            if( fopOpponent3 != NULL ) 
                            {
                                bOneTamed = this->tameCheck( fopOpponent3);
                            }
                        }
                    }
                }
            }
            
            if( bBattleWon ) 
            {
                //Add the seen monsters
                for(int i=0 ; i<opponents->count();i++)
                {
                    battleObject * tmpObj=(battleObject*)opponents->objectAtIndex(i); 
                    parent->sawMonster(tmpObj->getMonster()->monid);
                }
                
               
                for(int i=0 ; i<team->count();i++)
                {
                    battleObject * tmpObj=(battleObject*)team->objectAtIndex(i); 

                    if( tmpObj->bReadyToMutate ) 
                    {
                        
                        CCString * tmpStr = CCString::createWithFormat("Display Message\t%s is ready to Mutate.^", tmpObj->getName()->getCString()); 
                        parent->addScript(CCArray::create((CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
                       
                        tmpStr =CCString::createWithFormat("Ask Question - Two Answers\tWill you let %s Mutate?^Yes^No", tmpObj->getName()->getCString()); 
                        parent->addScript(CCArray::create((CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
                        
                        tmpStr = CCString::createWithFormat("IF\tGlobal Variable^SYSYesNoAnswer^T"); 
                        parent->addScript(CCArray::create((CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
                        
                        tmpStr = CCString::createWithFormat("Mutate Monster at Position\t%d",tmpObj->position); 
                        parent->addScript(CCArray::create((CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
                        
                        dataMonster * mon = (dataMonster*)(parent->getDatabase()->monById(tmpObj->getMonster()->evolvesto)); 
                        
                        tmpStr =  CCString::createWithFormat("Display Message\t%s mutated into %s.^", tmpObj->getName()->getCString(),mon->getName()->getCString()); 
                        parent->addScript(CCArray::create((CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
                        
                        tmpStr = CCString::createWithFormat("ELSE\t"); 
                        parent->addScript(CCArray::create((CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
                        tmpStr = CCString::createWithFormat("END IF\t"); 
                        parent->addScript(CCArray::create((CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
                        
                    }
                }
                
            }
            
            parent->bBattleStarted = false;
            
            parentScene->resignTimer();
            
            //Close the Battle Scene
            parent->battleMusicStop();
            parentScene->stopAllActions();
            CCDirector::sharedDirector()->popScene();
            parent->startTimer();
            parent->scriptProgress();
        }
        else if(((CCString*)Convertstring->lowercaseString((CCString*)function->objectAtIndex(0)))->isEqual(CCString::create("hp")))
        {
            int target = ((CCString*)function->objectAtIndex(1))->intValue();
            int targetSide = ((CCString*)function->objectAtIndex(2))->intValue(); //0 = opponents / 1 = Team
            int targetHpFrom = ((CCString*)function->objectAtIndex(3))->intValue();
            int targetHpTo = ((CCString*)function->objectAtIndex(4))->intValue();
            int damage = ((CCString*)function->objectAtIndex(5))->intValue();
            
            CCString * tmpType =NULL;
            if( function->count() > 6 ) 
                tmpType = (CCString*)function->objectAtIndex(6);
                
                
                int hpJump = 0;
                if( targetHpFrom < targetHpTo )
                {
                    hpJump = (targetHpTo - targetHpFrom) / 10;
                    if( hpJump <= 0 )
                        hpJump = 1;
                } 
                else 
                {
                            hpJump = (targetHpFrom - targetHpTo) / 10;
                            if( hpJump <= 0 )
                                hpJump = 1;
                    }
            
            //Setup the bypass for if there is no attack animation to do
            if( tmpType == NULL )
            {
                bAnimatingAttack = true;
                attackAniFrame =  1;
                attackAniFrameCount = 0;
            }
            
            if( !bAnimatingAttack )
            {
                //Setup the attack animation
                
                if( aniSprite != NULL ) 
                {
                    aniSprite->release();
                    
                }
                
                CCString * filename = CCString::createWithFormat("ani-%s.png", tmpType->getCString());
                
                aniSprite = CCSprite::create(filename->getCString(), CCRectMake(0, 0, 80, 80));
                
                CCPoint pos;
                if( targetSide == 0 ) 
                {
                    pos = this->positionForOpponent(target);
                } 
                else 
                {
                    pos = this->positionForOpponent(target);
                }
                
                aniSprite->setPosition(ccp(pos.x,pos.y));
                this->addChild(aniSprite,50);
                
                CCAnimation * frames = CCAnimation::create();//PENDING_DEEPAKinitWithName("frames");
                CCSpriteBatchNode * spriteSheet = CCSpriteBatchNode::create(filename->getCString());
                attackAniFrameCount = spriteSheet->getTexture()->getContentSize().width/80;
                for(int i=0;i<=attackAniFrameCount;i++)
                {
                    frames->addSpriteFrameWithTexture(spriteSheet->getTexture(),CCRectMake(i*80,0, 80, 80));
                }
                    //PENDING_DEEPAK aniSprite->addAnimation(frames);
                frames->release();
                
                attackAniFrame = 0;
                bAnimatingAttack = true;
                
            } else {
                
                if( attackAniFrame < attackAniFrameCount ) {
                    //attackAniFrameTick++;
                    //if( attackAniFrameTick > 2 ) {
                    
                    attackAniFrame++;
                    aniSprite->setDisplayFrameWithAnimationName("frames", attackAniFrame);
                    
                    //    attackAniFrameTick=0;
                    //}
                    
                    
                    
                }
                else
                {
                    
                    if( !bAnimating )
                    {
                        battleText = 0;
                        
                        this->sfx(CCString::create(SOUND_ATTACKED));
                        hpStep = targetHpFrom;
                        bAnimating = true;
                        
                        
                        if( damage > 0 ) 
                        {
                            if( targetSide == 0 ) 
                            {
                                CCPoint pos = this->positionForOpponent(target);
                                this->addDamageAni(damage, ccp(pos.x+30,pos.y));
                            } 
                            else 
                            {
                                CCPoint pos = this->positionForTeam(target);
                                this->addDamageAni(damage,ccp(pos.x-30,pos.y));
                            }
                        }
                        
                        //[self changeHpFor: target+3 To:hpStep];
                    } 
                    else 
                    {
                        battleText++;
                        
                        if( targetHpTo > hpStep ) 
                        {
                            hpStep=hpStep+hpJump;
                            if( hpStep > targetHpTo )
                                hpStep = targetHpTo;
                        } 
                        else if( targetHpTo < hpStep ) 
                        {
                                    hpStep=hpStep-hpJump;
                                    if( hpStep < targetHpTo )
                                        hpStep = targetHpTo;
                        } 
                        
                        if( targetHpTo == hpStep ) 
                        {
                            
                            if( targetSide == 0 ) 
                            {
                                this->changeHpFor(target,hpStep);
                            } 
                            else
                            {
                                this->changeHpFor(target+3,hpStep);
                            }
                            
                            bAnimating = false;
                            bAnimatingAttack = false;
                            hpStep = 0;
                            battleEventQueue->removeObjectAtIndex(0);
                            return;
                        }
                        
                        
                        
                        if( targetSide == 0 ) 
                        {
                             this->changeHpFor(target,hpStep);
                        } 
                        else
                        {
                            this->changeHpFor(target+3,hpStep);
                        }
                        
                        battleText = 0;
                    }
                }
            }
        } 
        else if( ((CCString*)Convertstring->lowercaseString((CCString*)function->objectAtIndex(0)))->isEqual(CCString::create("monsterselection")))
        {
            bSelectingTarget = false;
            chosenAction = 0;
            this->displayActionMenu();
            bAttackMenuDisplayed = true;
            battleEventQueue->removeObjectAtIndex(0);
        } 
        else if(((CCString*)Convertstring->lowercaseString((CCString*)function->objectAtIndex(0)))->isEqual(CCString::create("fieldofplayupdate")))
        {
            this->displayTeamAndOpponents();
            battleEventQueue->removeObjectAtIndex(0);
        } 
        else 
        {
            
            
        }
        
        
    } 
    else
    {
        //Displaying Something Presently
        if( menuItems->count() >= 1 )
        {
            CoolFreeform * tmpFF =(CoolFreeform*)menuItems->objectAtIndex(0);
            if( typeid(tmpFF) == typeid(CoolFreeform) ) 
            {
                if( tmpFF->isFinished() )
                {
                    battleText++;
                    if( battleText > 30 ) 
                    {
                        battleEventQueue->removeObjectAtIndex(0);
                        menuItems->removeAllObjects();
                        bDisplayingText = false;
                    }
                }
                else
                {
                    
                }
            }
        }
        
    }
}




bool battleLayer::tameCheck(battleObject * target)
{
    
    
    
    int chanceToTame = 0;
    if( target->convincedAmount <= 0 )
    {
        chanceToTame = 50;
    } else if( target->convincedAmount < 50 ) 
    { 
        chanceToTame = 15;
    } 
    else
    {
        chanceToTame = 5;
    }
    int result = arc4random() % 100;
    if( result <= chanceToTame )
    {
        
        int monPosition = 0;
        if( team->count() <= 8 )
        {
            monPosition = team->count() + 1;
        }
        
        bool bHasTamed = parent->monCaught(target->getMonster()->monid);
        
        CCString * tmpStr = CCString::createWithFormat("Display Message\t%s has been hanging around since the battle.^", target->getName()->getCString()); 
        parent->addScript( (CCArray*)((CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t"))));      
        if( !bHasTamed ) {
            
            CCString * tmpStr = CCString::createWithFormat("Display Message\tYou have not tamed a %s before!^", target->getName()->getCString()); 
            parent->addScript((CCArray*)(CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t")));
            
        }
        
        
        tmpStr = CCString::createWithFormat("Ask Question - Two Answers\tWill you let %s join your Team?^Yes^No", target->getName()->getCString()); 
        parent->addScript((CCArray*)(CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t")));
        tmpStr = CCString::createWithFormat("IF\tGlobal Variable^SYSYesNoAnswer^T"); 
        parent->addScript((CCArray*)(CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t")));
        
        tmpStr = CCString::createWithFormat("Add Monster\t%d: %s^%d^%d^%d",target->getMonster()->monid, target->getName()->getCString(),target->lvl,monPosition,target->special); 
        parent->addScript((CCArray*)(CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t")));
        
        tmpStr =  CCString::createWithFormat("ELSE\t"); 
        parent->addScript((CCArray*)(CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t")));
        tmpStr =  CCString::createWithFormat("END IF\t"); 
        parent->addScript((CCArray*)(CCString*)Convertstring->componentsSeparatedByString(tmpStr, CCString::create("\t")));
       /*PENDING_DEEPAK 
        [Flurry logEvent:@"Monster Tame Attempt" withParameters:
         [NSDictionary dictionaryWithObjectsAndKeys:
          @"Yes",@"Success",
          [target getName],@"Monster Name",
          [NSString stringWithFormat:@"%d",[target getMonster].monid],@"Monster ID",
          nil] ];*/
        
        return true;
    } 
    else
    {
        /* PENDING_DEEPAK
        [Flurry logEvent:@"Monster Tame Attempt" withParameters:
         [NSDictionary dictionaryWithObjectsAndKeys:
          @"No",@"Success",
          [target getName],@"Monster Name",
          [NSString stringWithFormat:@"%d",[target getMonster].monid],@"Monster ID",
          nil] ];*/
        
        
    }
    return false;
}




void battleLayer::processAIAttack()
{
	
    CCArray * attacks =  parent->getDatabase()->getAttacksForMonster(attackingPresently->getMonster()->monid, attackingPresently->intel);
    dataSkill * attack = (dataSkill*)attacks->objectAtIndex(attacks->count()-1);
    
    CCArray * targets = new CCArray();
    if( attack->scope == 1 ) 
    {
        
        CCArray * opps = new CCArray();
        
        if( fopTeam1 != NULL )
            if( fopTeam1->hpLeft > 0 )
                opps ->addObject(fopTeam1);
        if( fopTeam2 != NULL )
            if( fopTeam2->hpLeft > 0 )
                opps->addObject(fopTeam2);
        if( fopTeam3 != NULL )
            if( fopTeam3->hpLeft > 0 )
                opps->addObject(fopTeam3);
        
        
        if( opps->count() != 0 )
        {
            targets->addObject((opps->objectAtIndex(arc4random() %(opps->count()))));
        }
        
        opps->removeAllObjects();
        opps->release();
        
        CCString * msg = CCString::createWithFormat("%s attacked %s with %s", attackingPresently->getName()->getCString(), ((battleObject*)targets->objectAtIndex(0))->getName()->getCString(), attack->getName()->getCString());
        this->addMessageToQueue(msg);
    } 
    else if( attack->scope == 2 )
    {
        
        CCString * msg = CCString::createWithFormat("%s attacked with %s",attackingPresently->getName()->getCString(), attack->getName()->getCString());
        this->addMessageToQueue(msg);
        
        if( fopTeam1 != NULL )
            if( fopTeam1->hpLeft > 0 )
                targets->addObject(fopTeam1);
        if( fopTeam2 != NULL )
            if( fopTeam2->hpLeft > 0 )
                targets->addObject(fopTeam2);
        if( fopTeam3 != NULL )
            if( fopTeam3->hpLeft > 0 )
                targets->addObject(fopTeam3);
    }
    
    
    dataDictionary * database = parent->getDatabase();
    for(int i=0; i<targets->count();i++) 
    {
        battleObject * target =(battleObject*)targets->objectAtIndex(i);
        int damagePt1 =  1 ; 
        double damagePt2 =  ((double)attack->power /100)*((double)attackingPresently->atk-((double)target->def/3)) ;
        double damagePt3 =  (int)(double)((double)100/(double)target->lvl)/((double)100/(double)attackingPresently->lvl);
        double damagePt4 =  (damagePt1*damagePt2)/10+5;
        int damage = damagePt3 * damagePt4;
        
        if( damage < 1 )
            damage = 1;
            
            
        double typemod1 =  database->typeModFor(attack->element_type_id, target->getMonster()->type1Id);
            double typemod2 = database->typeModFor(attack->element_type_id, target->getMonster()->type2Id);
            double typemodfin = typemod1 * typemod2;
            
            
            damage=damage * typemodfin;
            damage = damage * (75 + (((double)(arc4random() % 10000)/10000) * 50)) / 100;  //  +/- 25%
            damage=floor(damage);
            
            if( damage < 0 )
            {
                CCString * msg = CCString::createWithFormat("%s was Healed %d Points.",target->getName()->getCString(),damage);
                this->addMessageToQueue(msg);
            } 
            else 
            {
                //NSString * msg = [NSString stringWithFormat:@"%@ took %d Damage.",[target getName],damage];
                //[self addMessageToQueue:msg];
            }
        
        int hpBefore = target->hpLeft;
        
        target->hpLeft = target->hpLeft - damage;
        if( target->hpLeft < 0 )
            target->hpLeft  = 0;
            
            if( target->getTeamMonster() != NULL ) 
                target->getTeamMonster()->hpLeft = target->hpLeft;
                
                if( target == fopTeam1)
                   this->addHPChange(1,1,hpBefore, target->hpLeft,damage,attack->element_type_id) ;
        if( target == fopTeam2)
           this->addHPChange(2,1,hpBefore, target->hpLeft,damage,attack->element_type_id) ;
        if( target == fopTeam3)
            this->addHPChange(3,1,hpBefore, target->hpLeft,damage,attack->element_type_id) ;
        
        
        if( target->hpLeft == 0 ) 
        {
            CCString * msg = CCString::createWithFormat("%s Fainted.",target->getName()->getCString());
           this->addMessageToQueue(msg);
            
            bool bReplacementFound = false;
            bool bMustSwap = false;
            
            for(int i=0; i<team->count();i++) 
            {
                battleObject * oppMon =(battleObject*)team->objectAtIndex(i);
                if( oppMon->hpLeft > 0 && oppMon != fopTeam1  && oppMon != fopTeam2  && oppMon != fopTeam3 ) 
                {
                    
                    //Open Swap Menu  - No Cancel
                    bReplacementFound = true;
                    bMustSwap = true;
                }
            }
            
            if( bReplacementFound == false )
            {
                bool bBattleCanContinue = false;
                if( fopTeam1 != NULL )
                    if( fopTeam1->hpLeft > 0 )
                        bBattleCanContinue = true;
                        if( fopTeam2 != NULL )
                            if( fopTeam2->hpLeft > 0 )
                                bBattleCanContinue = true;
                                if( fopTeam3 != NULL )
                                    if( fopTeam3->hpLeft > 0 )
                                        bBattleCanContinue = true;
                                        
                                        
                                        if( bBattleCanContinue == false ) 
                                        {
                                            //Transport User to Safehouse.
                                            CCString * msg =CCString::createWithFormat("You have lost the Battle!");
                                            this->addMessageToQueue(msg);
                                            battleEventQueue->addObject(CCString::create("END|"));
                                            
                                            parent->addFaintScriptAndKO();
                                            
                                            return;
                                        }
            }
        }
    }
}





void battleLayer::processAttack()
{
    currentMenu = 0;
    
    
    if( chosenAction == 1 ) {
        //Attack Skill
        //[self addMessageToQueue:@"Attack"];
        
        dataSkill * attack = skillForTarget;
        
        CCArray * targets =new CCArray();
        if( attack->scope == 1 )
        {
            if( chosenActionTarget == 1 )
            {
                if( fopOpponent1 != NULL )
                    if( fopOpponent1->hpLeft > 0 )
                        targets->addObject(fopOpponent1);
            } 
            else if( chosenActionTarget == 2 ) 
            {
                if( fopOpponent2 != NULL )
                    if( fopOpponent2->hpLeft > 0 )
                        targets->addObject(fopOpponent2);
            } 
            else if( chosenActionTarget == 3 )
            {
                if( fopOpponent3 != NULL )
                    if( fopOpponent3->hpLeft > 0 )
                        targets->addObject(fopOpponent3);
            }  
            
            CCString * msg = CCString::createWithFormat("%s attacked %s with %s",attackingPresently->getName()->getCString(), ((battleObject*)targets->objectAtIndex(0))->getName()->getCString(),attack->getName()->getCString());
                              
            this->addMessageToQueue(msg);
        } 
        else if( attack->scope == 2 )
        {
            
            CCString * msg = CCString::createWithFormat("%s attacked with %s",attackingPresently->getName()->getCString() , attack->getName()->getCString());
           this->addMessageToQueue(msg);
            
            if( fopOpponent1 != NULL )
                if( fopOpponent1->hpLeft > 0 )
                    targets->addObject(fopOpponent1);
            if( fopOpponent2 != NULL )
                if( fopOpponent2->hpLeft > 0 )
                    targets->addObject(fopOpponent2);
            if( fopOpponent3 != NULL )
                if( fopOpponent3->hpLeft > 0 )
                    targets->addObject(fopOpponent3);
        }
        else if( attack->scope == 0 )
        {
            
            CCString * msg = CCString::createWithFormat("%s used %s on Allies",attackingPresently->getName()->getCString(), attack->getName()->getCString());
            this->addMessageToQueue(msg);
            
            if( fopTeam1 != NULL )
                if( fopTeam1->hpLeft > 0 )
                    targets->addObject(fopTeam1);
            if( fopTeam2 != NULL )
                if( fopTeam2->hpLeft > 0 )
                    targets->addObject(fopTeam2);
            if( fopTeam3 != NULL )
                if( fopTeam3->hpLeft > 0 )
                    targets->addObject(fopTeam3);
        }
        else if( attack->scope == 3 ) 
        {
            if( chosenActionTarget == 4 )
            {
                if( fopTeam1 != NULL )
                    if( fopTeam1->hpLeft > 0 )
                        targets->addObject(fopTeam1);
            } 
            else if( chosenActionTarget == 5 )
            {
                if( fopTeam2 != NULL )
                    if( fopTeam2->hpLeft > 0 )
                        targets->addObject(fopTeam2);
            } 
            else if( chosenActionTarget == 6 )
            {
                if( fopTeam3 != NULL )
                    if( fopTeam3->hpLeft > 0 )
                        targets->addObject(fopTeam3);
            } 
            
            CCString * msg = CCString::createWithFormat("%s used %s on %s",attackingPresently->getName()->getCString(), attack->getName()->getCString(),((battleObject*)targets->objectAtIndex(0))->getName()->getCString());
                           
            this->addMessageToQueue(msg);
        }
        
        
        dataDictionary * database = parent->getDatabase();
        for(int i=0; i<targets->count();i++)
        {
            battleObject * target =(battleObject*)targets->objectAtIndex(0); 
            target->convincedAmount=target->convincedAmount+5;
            
            int damagePt1 =  1 ; 
            double damagePt2 =  ((double)attack->power /100)*((double)attackingPresently->atk-((double)target->def/3)) ;
            double damagePt3 =  (int)(double)((double)100/(double)target->lvl)/((double)100/(double)attackingPresently->lvl);
            
            double damagePt4 = (int) (damagePt1*damagePt2)/10+5;
            int damage = damagePt3 * damagePt4;
            
            if( damage < 1 )
                damage = 1;
                
                //damage = damage * 10;
                
                double typemod1 = database->typeModFor(attack->element_type_id,target->getMonster()->type1Id );
                double typemod2 = database->typeModFor(attack->element_type_id,target->getMonster()->type2Id );
                double typemodfin = typemod1 * typemod2;
                
                
                damage= damage * typemodfin;
                damage = damage * (75 +    (((double)(arc4random() % 10000)/10000) * 25)) / 100;
                damage=floor(damage);
                
                if( damage < 0 ) {
                    CCString * msg = CCString::createWithFormat("%s was Healed %d Points.",target->getName()->getCString(),damage);
                    this->addMessageToQueue(msg);
                } else {
                    //NSString * msg = [NSString stringWithFormat:@"%@ took %d Damage.",[target getName],damage];
                    //[self addMessageToQueue:msg];
                }
            
            int hpBefore = target->hpLeft;
            
            target->hpLeft = target->hpLeft - damage;
            if( target->hpLeft < 0 )
                target->hpLeft  = 0;
                
                if( target == fopOpponent1)
                    this->addHPChange(1,0,hpBefore, target->hpLeft,damage,attack->element_type_id) ;
            if( target == fopOpponent2)
                 this->addHPChange(2,0,hpBefore, target->hpLeft,damage,attack->element_type_id) ;
            if( target == fopOpponent3)
                 this->addHPChange(3,0,hpBefore, target->hpLeft,damage,attack->element_type_id) ;
            
            if( target->getTeamMonster() != NULL ) 
                target->getTeamMonster()->hpLeft = target->hpLeft;
                
                if( target->hpLeft == 0 ) 
                {
                    CCString * msg = CCString::createWithFormat("%s Fainted.",target->getName()->getCString());
                    this->addMessageToQueue(msg);
                    
                    
                    int expShare = target->getMonster()->exp * target->lvl / 3;
                    expShare = expShare * 2;
                    
                    if( bCanTame ) 
                    {
                        expShare = expShare * 0.8;
                    }
                    
                    int teamMembersOut = 0;
                    if( fopTeam1 != NULL)
                        if( fopTeam1->hpLeft > 0 )
                            teamMembersOut++;
                    if( fopTeam2 != NULL)
                        if( fopTeam2->hpLeft > 0 )
                            teamMembersOut++;
                    if( fopTeam3 != NULL)
                        if( fopTeam3->hpLeft > 0 )
                            teamMembersOut++;
                    expShare = expShare / teamMembersOut;
                    
                    
                    if( fopTeam1 != NULL)
                        this->AwardExp(expShare, fopTeam1, 1);
                    if( fopTeam2 != NULL)
                        this->AwardExp(expShare, fopTeam2, 2);
                    if( fopTeam3 != NULL)
                        this->AwardExp(expShare, fopTeam3, 3);
                    
                    int expToShare = expShare/4;
                    if( expToShare > 0 && parent->expSharePurchased == 1 )
                    {
                        CCString * msg = CCString::createWithFormat("%d EXP awarded to your team due to Exp Share.",expToShare);
                        this->addMessageToQueue(msg);
                        
                        for(int i=0; i<team->count();i++)
                        {
                            battleObject * mon= (battleObject*)team->objectAtIndex(i); 
                            if( mon != fopTeam1 && mon != fopTeam1 && mon != fopTeam1 )
                            {
                                this->AwardExp(expShare/4, mon, 0);
                            }
                        }
                        
                    }
                    
                    
                    battleEventQueue->addObject(CCString::create("fieldofplayupdate"));
                    
                    
                    
                    bool bReplacementFound = false;
                    for(int i=0; i<opponents->count();i++)
                    {
                        battleObject * oppMon= (battleObject*)opponents->objectAtIndex(i); 
                        if( oppMon->hpLeft > 0 && oppMon != fopOpponent1  && oppMon != fopOpponent2  && oppMon != fopOpponent3 )
                        {
                            if( target == fopOpponent1)
                                fopOpponent1 = oppMon;
                                if( target == fopOpponent2)
                                    fopOpponent2 = oppMon;
                                    if( target == fopOpponent3)
                                        fopOpponent3 = oppMon;
                                        
                                        
                            CCString * msg = CCString::createWithFormat("Opponent Swapped %s for %s",((battleObject*)targets->objectAtIndex(0))->getName()->getCString(),oppMon->getName()->getCString());
                                        this->addMessageToQueue(msg);
                            
                            battleEventQueue->addObject(CCString::create("fieldofplayupdate"));
                            
                            bReplacementFound = true;
                            break;
                        }
                    }
                    
                    if( bReplacementFound == false ) 
                    {
                        bool bBattleCanContinue = false;
                        if( fopOpponent1 != NULL )
                            if( fopOpponent1->hpLeft > 0 )
                                bBattleCanContinue = true;
                                if( fopOpponent2 != NULL )
                                    if( fopOpponent2->hpLeft > 0 )
                                        bBattleCanContinue = true;
                                        if( fopOpponent3 != NULL )
                                            if( fopOpponent3->hpLeft > 0 )
                                                bBattleCanContinue = true;
                                                
                                                
                                                if( bBattleCanContinue == false )
                                                {
                                                    bBattleWon = true;
                                                    CCString * msg = CCString::createWithFormat("You have won the Battle!");
                                                    this->addMessageToQueue(msg);
                                                    battleEventQueue->addObject(CCString::create("END|"));
                                                    return;
                                                }
                    }
                    
                    
                    //TODO: Award Exp
                }
            
        }
        
    } 
    else if( chosenAction == 3 ) 
    {
        //Monster Swap
        //[self addMessageToQueue:@"Swap"];
        
        
        CCString * msg = CCString::createWithFormat("You have taken %s off the field.",attackingPresently->getName()->getCString());
        this->addMessageToQueue(msg);
        
        battleObject * battleObj = (battleObject*)team->objectAtIndex(chosenActionArg);
        
        
        if( attackingPresently == fopTeam1)
            fopTeam1 = battleObj;
            if( attackingPresently == fopTeam2)
                fopTeam2 = battleObj;
                if( attackingPresently == fopTeam3)
                    fopTeam3 = battleObj;
                    
                    
        msg = CCString::createWithFormat("You have sent %s into Battle.",battleObj->getName()->getCString());
                    this->addMessageToQueue(msg);
        
        this->displayTeamAndOpponents();
        
    } 
    else if( chosenAction == 4 )
    {
        //Use Item
        
        
        if( itemForTarget->itemid == 13  )
        {
            //Revives
            
            CCString  * msg = CCString::createWithFormat("%s used a %s on %s",attackingPresently->getName()->getCString(),itemForTarget->getName()->getCString(),((battleObject*)team->objectAtIndex(chosenActionTarget))->getName()->getCString());
            this->addMessageToQueue(msg);
            
            battleObject * tmpObj =(battleObject*)team->objectAtIndex(chosenActionTarget);
            tmpObj->hpLeft = tmpObj->hp / 4;
            
            if( tmpObj->getTeamMonster() != NULL ) 
                tmpObj->getTeamMonster()->hpLeft = tmpObj->hpLeft;
                
                if( tmpObj == fopTeam1 || tmpObj == fopTeam2 || tmpObj == fopTeam3 ) 
                {
                    this->addHPChange(tmpObj->position,1, 0,tmpObj->hpLeft,(int)tmpObj->hp / 4, 0);
                }
            
            
            parent->useItems(itemForTarget->itemid,1);
            
        } 
        else if( itemForTarget->itemid > 13 && itemForTarget->itemid <= 17  ) 
        {
            //Potions
            
            CCString * msg = CCString::createWithFormat("%s used a %s on %s",attackingPresently->getName()->getCString(),itemForTarget->getName()->getCString(),((battleObject*)team->objectAtIndex(chosenActionTarget))->getName()->getCString());
            this->addMessageToQueue(msg);
            
            battleObject * tmpObj = (battleObject*)team->objectAtIndex(chosenActionTarget);
            
            int itemHPEffect = 0;
            if( itemForTarget->itemid == 14 ) 
            {
                itemHPEffect = 20;
            } 
            else if( itemForTarget->itemid == 15 )
            {
                itemHPEffect = 100;
            } 
            else if( itemForTarget->itemid == 16 ) 
            {
                itemHPEffect = 500;
            } 
            else if( itemForTarget->itemid == 17 )
            {
                itemHPEffect = tmpObj->hp - tmpObj->hpLeft;
            } 
            
            int newHP = tmpObj->hpLeft + itemHPEffect;
            if( newHP > tmpObj->hp ) 
                newHP = tmpObj->hp;
                
                if( tmpObj == fopTeam1 || tmpObj == fopTeam2 || tmpObj == fopTeam3 ) 
                {
                    this->addHPChange(tmpObj->position,1,tmpObj->hpLeft,newHP, itemHPEffect,0);
                    
                }
            tmpObj->hpLeft = newHP;
            
            
            if( tmpObj->getTeamMonster() != NULL ) 
                tmpObj->getTeamMonster()->hpLeft = tmpObj->hpLeft;
                
               parent->useItems(itemForTarget->itemid,1);
        } 
        else 
        {
            //GeoShocks
            if( bCanTame )
            {
                CCString * msg = CCString::createWithFormat("%s used a %s on all Opponents",attackingPresently->getName()->getCString(),itemForTarget->getName()->getCString());
                this->addMessageToQueue(msg);
                
                double oppCount = 0;
                if( fopOpponent1 != NULL ) 
                    if( fopOpponent1->hpLeft > 0 )
                        oppCount++;
                if( fopOpponent2 != NULL ) 
                    if( fopOpponent2->hpLeft > 0 )
                        oppCount++;
                if( fopOpponent3 != NULL )
                    if( fopOpponent3->hpLeft > 0 ) 
                        oppCount++;
                
                
                if( fopOpponent1 != NULL )
                    if( fopOpponent1->hpLeft > 0 )
                        
                this->addMessageToQueue((CCString*)fopOpponent1->convince(itemForTarget, 1/oppCount));
                
                
                if( fopOpponent2 != NULL ) 
                    if( fopOpponent2->hpLeft > 0 )
                        this->addMessageToQueue((CCString*)fopOpponent2->convince(itemForTarget, 1/oppCount));
                
                if( fopOpponent3 != NULL ) 
                    if( fopOpponent3->hpLeft > 0 )
                        this->addMessageToQueue((CCString*)fopOpponent3->convince(itemForTarget, 1/oppCount));
                
                parent->useItems(itemForTarget->itemid,1);
            } 
            else 
            {
                //Cant Tame Monsters
                
                CCString * msg =CCString::createWithFormat("You can't use GeoShocks on other Tamers Monsters.");
                this->addMessageToQueue(msg);
            }
        }
        
    } 
    else if( chosenAction == 5 ) 
    {
        //Run Away
        
        if( bCanRun )
        {
            double aggTeamSpd = 0;
            double aggOpponentSpd = 0;
            
            double teamSize;
            double OppSize;
            
            if( fopTeam1 != NULL ) {
                aggTeamSpd = aggTeamSpd + fopTeam1->spd; 
                teamSize++;
            }
            if( fopTeam2 != NULL )
            {
                aggTeamSpd = aggTeamSpd + fopTeam2->spd;
                teamSize++;
            }
            if( fopTeam3 != NULL )
            {
                aggTeamSpd = aggTeamSpd + fopTeam3->spd;
                teamSize++;
            }
            
            
            if( fopOpponent1 != NULL ) 
            {
                aggOpponentSpd = aggOpponentSpd + fopOpponent1->spd;
                OppSize++;
            }
            if( fopOpponent2 != NULL )
            {
                aggOpponentSpd = aggOpponentSpd + fopOpponent2->spd;
                OppSize++;
            }
            if( fopOpponent3 != NULL ) 
            {
                aggOpponentSpd = aggOpponentSpd + fopOpponent3->spd;
                OppSize++;
            }
            
            double runChances = (aggTeamSpd / teamSize) / (aggOpponentSpd / OppSize);
            if( runChances > 0.7 )
                runChances = 0.7;
                
                
                
            this->addMessageToQueue(CCString::create("Your Team Attempts to Run Away..."));
            
            
            int runResult = arc4random() % 100;
            if( runResult <= runChances*100 ) 
            {
                
                this->addMessageToQueue(CCString::create("Your Team Managed to Get Away."));
                
                battleEventQueue->addObject(CCString::create("END|"));
                
            } 
            else 
            {
                
                 this->addMessageToQueue(CCString::create("Your Team Failed to Get Away."));
            }
        } 
        else 
        {
            //Cant Run from this Battle
             this->addMessageToQueue(CCString::create("You can't run away from a Trainer Battle!"));
        }
    } 
}



void battleLayer::AwardExp(int  exp,battleObject * target,int monPos)
{
    if( target->hpLeft == 0 ) 
    {
        return;
    }
    
    if( exp > 0 ) 
    {
        
        //DEBUG LINE
        //exp = exp * 700;
        
        monster * mon = target->getTeamMonster();
        mon->exp = mon->exp + exp;
        
        
        int nextLevel = mon->lvl+1;
        int expToNext = nextLevel * nextLevel * nextLevel;
        
        
        //NSString * tmpString = [NSString stringWithFormat:@"%@ recieved %d exp",[target getName],exp];
        //[self addMessageToQueue:tmpString];
        if( monPos > 0 ) {
            battleEventQueue->addObject(CCString::createWithFormat("EXP|%d|%d",monPos,exp));
        }
        
        while(  mon->exp > expToNext ) 
        {
            
            if( mon->exp > expToNext )
            {
                CCString * tmpString = CCString::createWithFormat("%s has grown to level %d",target->getName(),nextLevel);
                this->addMessageToQueue(tmpString);
                
                mon->lvl = nextLevel;
                target->lvl = nextLevel;
                
                // Get Alloc Points
                int freepoints = ((mon->getMonster()->hp+mon->getMonster()->atk+mon->getMonster()->def+mon->getMonster()->spd+mon->getMonster()->intel+mon->reborn) / 2);
                mon->stat_points = mon->stat_points + freepoints;
                
                if( mon->special == 5 ) {
                    mon->stat_points = mon->stat_points + (freepoints * 0.15);
                }
                
                
                mon->hp = mon->hp + mon->getMonster()->hp;
                mon->atk = mon->atk + mon->getMonster()->atk;
                mon->def = mon->def + mon->getMonster()->def;
                mon->spd = mon->spd + mon->getMonster()->spd;
                mon->intel = mon->intel +mon->getMonster()->intel;
                
                if( mon->special ) 
                {
                    mon->hp = mon->hp + mon->getMonster()->hp;
                    mon->atk = mon->atk +mon->getMonster()->atk;
                    mon->def = mon->def + mon->getMonster()->def;
                    mon->spd = mon->spd + mon->getMonster()->spd;
                    mon->intel = mon->intel + mon->getMonster()->intel;
                }
                
                
                target->hp = mon->hp;
                target->atk = mon->atk;
                target->def = mon-> def;
                target->spd = mon->spd;
                target->intel = mon->intel;
                
                target->hpLeft = target->hp;
                
                //Check for Mutations
                //bReadyToMutate
                if( mon->getMonster()->evolvelvl != 0 && mon->lvl >= mon->getMonster()->evolvelvl) 
                {
                    if( mon->getMonster()->evolvesto != 0 ) 
                    {
                        target->bReadyToMutate = true;
                    }
                }
            }
            nextLevel = mon->lvl+1;
            expToNext = nextLevel * nextLevel * nextLevel;
        }
    }
}

void battleLayer::addMessageToQueue(CCString * msg)
{
    
    battleEventQueue->addObject(CCString::createWithFormat("MSG|%s",msg->getCString()));
    
}


void battleLayer::addHPChange(int  targPos,int  ourTeam,int from,int  to,int  dmg,int typeId)
{
    if( typeId == 0 ) 
    {
        battleEventQueue->addObject(CCString::createWithFormat("HP|%d|%d|%d|%d|%d",targPos,ourTeam,from,to,dmg));
    } else
    {
       
        
        
               
        
        battleEventQueue->addObject(CCString::createWithFormat("HP|%d|%d|%d|%d|%d|%s",targPos,ourTeam,from,to,dmg,Convertstring->lowercaseString((CCString*)parent->getDatabase()->getTypeFromId(typeId))->getCString())) ;
    }
}

void battleLayer::addSoundToQueue(CCString * soundName)
 {
    
     battleEventQueue->addObject(CCString::createWithFormat("SFX|%s",soundName->getCString()));
    
}

void battleLayer::displayTeamAndOpponents()
{
	battleItems->removeAllObjects();
	
	CoolSprite * tmpSpt= new CoolSprite();
	CoolFreeform * tmpFF = new CoolFreeform();
    
	tmpSpt->initWithFile(CCString::create("teamBar.png"));
	tmpSpt->updatePosition( ccp(240,320-44));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,13);
	battleItems->addObject(tmpSpt);
	tmpSpt->release();
	
	if( fopTeam1 != NULL ) 
    {
		this->drawMonsterBar(1);
	} 
    else 
    {
		battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
	}
	if( fopTeam2 != NULL )
    {
		this->drawMonsterBar(2);
	}
    else 
    {
		battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
        battleItems->addObject( new CCObject);
	}
	if( fopTeam3 != NULL ) 
    {
		this->drawMonsterBar(3);
		
	} 
    else 
    {
		battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
	}
	
	if( fopOpponent1 != NULL ) 
    {
        this->drawOpponentMonsterBar(1);
	} 
    else 
    {
		battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
    }
	if( fopOpponent2 != NULL )
    {
        this->drawOpponentMonsterBar(2);
	} 
    else 
    {
		battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
    }
	if( fopOpponent3 != NULL ) 
    {
        this->drawOpponentMonsterBar(3);
	}
    else 
    {
		battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
        battleItems->addObject(new CCObject);
    }
    
}





void battleLayer::drawOpponentMonsterBar(int mon)
{
	
	CoolSprite * tmpSpt= new CoolSprite();;
	CoolFreeform * tmpFF = new CoolFreeform();
	
	battleObject * monObj = fopOpponent1;
	if(mon == 2 ) 
    {
		monObj = fopOpponent2;
	} 
    else if(mon == 3 )
    {
		monObj = fopOpponent3;
	}  
	
    
    int monZLevel = 13;
    CCPoint barPos = ccp((56),320-15);
    if( mon == 2 )
    {
        barPos = ccp((55+64),320-(15+44));
        monZLevel = 14;
    } 
    else if( mon == 3 ) 
    {
        barPos = ccp((179),320-15);
        monZLevel = 15;
    }  
    
    
    CCPoint pos = ccp(48,320-152);
    if( mon == 2 )
    {
        pos = ccp(100,320-202);
    } 
    else if( mon == 3 )
    {
        pos = ccp(48,320-252);
    }  
    
	tmpFF->initWithCoolSheet(monObj->getName(),FONT_WHITE,0.30,320,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(barPos.x,barPos.y+6+10));
	tmpFF->addToLayer(this,17);
	battleItems->addObject(tmpFF);
	tmpFF->release();
	
    
	tmpSpt->initWithFile(CCString::create("timerBar.png"));
	tmpSpt->updateAnchorPointBottomRight();
    tmpSpt->updatePosition(ccp(barPos.x-48,barPos.y-4));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,15);
	battleItems->addObject(tmpSpt);
    tmpSpt->updateXScale(((double)monObj->attackTick / (double)monObj->attackPoint) * 94);
	tmpSpt->release();
    
	
	tmpFF->initWithCoolSheet(monObj->getName(),FONT_WHITE,0.30,320,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(barPos.x,barPos.y+6+10));
	tmpFF->addToLayer(this,16);
	battleItems->addObject(tmpFF);
	tmpFF->release();
	
	tmpSpt->initWithFile(CCString::create("hpBar.png"));
	tmpSpt->updateAnchorPointBottomRight();
    tmpSpt->updatePosition(ccp(barPos.x-48,barPos.y-25));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this ,15);
	battleItems->addObject(tmpSpt);
    //Set the HP Bars Initial Position
    if( monObj->hpLeft == 0 ) 
    {
        tmpSpt->updateXScale(0.00001);
        
    }
    else
    {
        tmpSpt->updateXScale(((double)monObj->hpLeft / (double)monObj->hp) * 94);
    }
	tmpSpt->release();
    
	battleItems->addObject(new CCObject);
	
    
    battleItems->addObject(new CCObject);
    
    
	tmpFF->initWithCoolSheet(monObj->getLvlString(),FONT_WHITE,0.25,100,true);
	tmpFF->bCenter = true;
    //[tmpFF updatePosition: ccp(pos.x,pos.y-40)];
    tmpFF->updatePosition(ccp(barPos.x,barPos.y-13+6)); //in place of the HP Stuff
	tmpFF->addToLayer(this,16);
	battleItems->addObject(tmpFF);
	tmpFF->release();
    
	tmpSpt->initWithFile(monObj->getImage());
    tmpSpt->updatePosition( pos);
	tmpSpt->updateOpacity(255);
    tmpSpt->updateXScale(-1);
	tmpSpt->addToLayer(this,monZLevel);
	battleItems->addObject(tmpSpt);
	tmpSpt->release();
    
    battleItems->addObject(new CCObject);
}




void battleLayer::drawMonsterBar(int  mon)
{
	//55+64
    
	CoolSprite * tmpSpt = new CoolSprite();
	CoolFreeform * tmpFF= new CoolFreeform();
	
    
	battleObject * monObj = fopTeam1;
	if(mon == 2 ) {
		monObj = fopTeam2;
        
	} else if(mon == 3 ) {
		monObj = fopTeam3;
        
	}  
    
    int monZLevel = 13;
    CCPoint barPos = ccp(480-(177),320-15);
    if( mon == 2 ) 
    {
        barPos = ccp(480-(55+64)+1,320-(15+44));
        monZLevel = 14;
    } else if( mon == 3 ) {
        barPos = ccp(480-(55),320-15);
        monZLevel = 15;
    }  
    
    
    CCPoint pos = ccp(480-48,320-152);
    if( mon == 2 ) {
        pos = ccp(480-100,320-202);
    } else if( mon == 3 ) {
        pos = ccp(480-48,320-252);
    }  
    
    
    
	tmpFF ->initWithCoolSheet(monObj->getName(),FONT_WHITE,0.30,320,true);
    tmpFF->bCenter = true;    
    tmpFF->updatePosition(ccp(barPos.x,barPos.y+6+10));
	tmpFF->addToLayer(this,17);
	battleItems->addObject(tmpFF);
	tmpFF->release();
	
    
    
    
	tmpSpt-> initWithFile(CCString::create("timerBar.png"));
	tmpSpt->updateAnchorPointBottomRight();
    tmpSpt->updatePosition(ccp(barPos.x-48,barPos.y-4));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,15);
	battleItems->addObject(tmpSpt);
    tmpSpt->updateXScale(((double)monObj->attackTick / (double)monObj->attackPoint) * 94);
	tmpSpt->release();
    
	
	
	tmpFF ->initWithCoolSheet(monObj->getName(),FONT_WHITE,0.30,320,true);
    tmpFF->bCenter = true;    
    tmpFF->updatePosition( ccp(barPos.x,barPos.y+6+10));
	tmpFF->addToLayer(this ,16);
	battleItems->addObject(tmpFF);
	tmpFF->release();
    
	
	tmpSpt ->initWithFile(CCString::create("hpBar.png"));
	tmpSpt->updateAnchorPointBottomRight();
    tmpSpt->updatePosition(ccp(barPos.x-48,barPos.y-25));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,15);
	battleItems->addObject(tmpSpt);
    //Set the HP Bars Initial Position
    tmpSpt->updateXScale(((double)monObj->hpLeft / (double)monObj->hp) * 94);
	tmpSpt->release();
    
    
	battleItems->addObject(new CCObject);
	
	
	tmpFF->initWithCoolSheet(monObj->getHpString(),FONT_WHITE,0.25,100,true);
	tmpFF->bCenter = true; 
    tmpFF->updatePosition(ccp(barPos.x,barPos.y-13+10));
	tmpFF->addToLayer(this,16);
	battleItems->addObject(tmpFF);
	tmpFF->release();
	
	
	tmpFF->initWithCoolSheet(monObj->getLvlString(),FONT_WHITE ,0.25,100,true);
	tmpFF->bCenter = true; 
    tmpFF->updatePosition(ccp(pos.x,pos.y-40));
    tmpFF->updatePosition(ccp(barPos.x,barPos.y-24+10));
	tmpFF->addToLayer(this,16);
	battleItems->addObject(tmpFF);
	tmpFF->release();
    
    
	tmpSpt->initWithFile(monObj->getImage());
    tmpSpt->updatePosition( pos);
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,monZLevel);
	battleItems->addObject(tmpSpt);
	tmpSpt->release();
    
	battleItems->addObject(new CCObject);
    /*
     tmpSpt = [[CoolSprite alloc] initWithFile:[NSString stringWithFormat:@"element-%@.png",[[[monObj getMonster] getType1] lowercaseString]]];
     if( mon == 1 )
     [tmpSpt updatePosition: ccp(4+16,112+3-16)];
     if( mon == 2 )
     [tmpSpt updatePosition: ccp(4+16,112-40+3-16)];
     if( mon == 3 )
     [tmpSpt updatePosition: ccp(4+16,112-80+3-16)];	
     [tmpSpt updateOpacity:255];
     [tmpSpt addToLayer:self z:17];
     [battleItems addObject:tmpSpt];
     [tmpSpt release];
     
     tmpSpt = [[CoolSprite alloc] initWithFile:[NSString stringWithFormat:@"element-%@.png",[[[monObj getMonster] getType2] lowercaseString]]];
     if( mon == 1 )
     [tmpSpt updatePosition: ccp(43+16,112+3-16)];
     if( mon == 2 )
     [tmpSpt updatePosition: ccp(43+16,112-40+3-16)];
     if( mon == 3 )
     [tmpSpt updatePosition: ccp(43+16,112-80+3-16)];	
     [tmpSpt updateOpacity:255];
     [tmpSpt addToLayer:self z:17];
     [battleItems addObject:tmpSpt];
     [tmpSpt release];
     */
}




void battleLayer::displayActionMenu()
{
	menuItems->removeAllObjects();
	if( currentMenu == 0 ) 
    {
		//Home Menu
		//For Human: Attack, Run, Item, Swap
		//For Monster: Attack, Run, Defend, Swap
		
		CoolSprite * tmpSpt =new CoolSprite();
        tmpSpt->initWithFile(CCString::create("attackoptions.png"));
		tmpSpt->updatePosition(ccp(240,160));
		tmpSpt->updateOpacity(255);
		tmpSpt->addToLayer(this,20);
		menuItems->addObject(tmpSpt);
		tmpSpt->release();
		
        /*
         tmpSpt = [[CoolSprite alloc] initWithFile:@"battleMsg.png"];
         [tmpSpt updatePosition:ccp(240,320-120)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:20];
         [menuItems addObject:tmpSpt];
         [tmpSpt release];
         */
        
		CoolFreeform * tmpFF = new CoolFreeform();
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("Select %s's Action",attackingPresently->getName()->getCString()),FONT_WHITE,0.40,320,false);
		tmpFF->bCenter = true;
		tmpFF->updatePosition(ccp(240,320-98));
		tmpFF->addToLayer(this,21);
		menuItems->addObject(tmpFF);
		tmpFF->release();
        tmpFF->initWithCoolSheet(CCString::createWithFormat("Select %s's Action",attackingPresently->getName()->getCString()) ,FONT_WHITE,0.40,320,false);
		tmpFF->bCenter = true;
		tmpFF->updatePosition(ccp(240,320-98));
		tmpFF->addToLayer(this,21);
		menuItems->addObject(tmpFF);
		tmpFF->release();
    
    } 
    else if( currentMenu == 1 ) 
    {
        //Attack Selection
        //[self setupAttackSelection];
        this->drawAttackSelectPage();
        
	}
    else if( currentMenu == 2 ) 
    {
        //Target Selection
        
        CoolSprite * tmpSpt= new CoolSprite();
		CoolFreeform * tmpFF = new CoolFreeform();
        
        /*
         tmpSpt = [[CoolSprite alloc] initWithFile:@"battleMsg.png"];
         [tmpSpt updatePosition:ccp(320-120,160)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:20];
         [menuItems addObject:tmpSpt];
         [tmpSpt release];
         */
        
        if( skillForTarget->scope == 1 ) 
        {
            
            tmpFF->initWithCoolSheet(CCString::createWithFormat("Select an Opponent %s",attackingPresently->getName()->getCString()),FONT_WHITE,0.40,480,false);
            tmpFF->bCenter = true;
            tmpFF->updatePosition(ccp(240,320-98));
            tmpFF->addToLayer(this,21);
            menuItems->addObject(tmpFF);
            tmpFF->release();
            
            tmpFF->initWithCoolSheet(CCString::createWithFormat("Select an Opponent %s",attackingPresently->getName()->getCString()),FONT_WHITE,0.40,480,false);
            tmpFF->bCenter = true;
            tmpFF->updatePosition(ccp(240,320-98));
            tmpFF->addToLayer(this,21);
            menuItems->addObject(tmpFF);
            tmpFF->release();
            
            if( fopOpponent1 != NULL )
            {
                if( fopOpponent1->hpLeft > 0 ) 
                {
                    CCPoint pos = this->positionForOpponent(1);
                    tmpSpt->initWithFile(CCString::create("targetSelector.png"));
                    tmpSpt->updatePosition(ccp(pos.x,pos.y+40));
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,20);
                    menuItems->addObject(tmpSpt);
                    tmpSpt->release();
                }
            }
            if( fopOpponent2 != NULL ) 
            {
                if( fopOpponent2->hpLeft > 0 )
                {
                    CCPoint pos = this->positionForOpponent(2);
                    tmpSpt->initWithFile(CCString::create("targetSelector.png"));
                    tmpSpt->updatePosition(ccp(pos.x,pos.y+40));
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,20);
                    menuItems->addObject(tmpSpt);
                    tmpSpt->release();
                }
            }
            if( fopOpponent3 != NULL ) 
            {
                if( fopOpponent3->hpLeft > 0 ) 
                {
                    CCPoint pos = this->positionForOpponent(3);
                    tmpSpt->initWithFile(CCString::create("targetSelector.png"));
                    tmpSpt->updatePosition(ccp(pos.x,pos.y+40));
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,20);
                    menuItems->addObject(tmpSpt);
                    tmpSpt->release();
                }
            }
            
            
        } else if( skillForTarget->scope == 3 ) 
        {
            
            tmpFF->initWithCoolSheet(CCString::createWithFormat("Select a Target",attackingPresently->getName()),FONT_WHITE,0.40 ,480,false);
            tmpFF->bCenter = true;
            tmpFF->updatePosition(ccp(240,320-98));
            tmpFF->addToLayer(this,21);
            menuItems->addObject(tmpFF);
            tmpFF->release();
            
            
            tmpFF->initWithCoolSheet(CCString::createWithFormat("Select a Target",attackingPresently->getName()),FONT_WHITE,0.40 ,480,false);
            tmpFF->bCenter = true;
            tmpFF->updatePosition(ccp(240,320-98));
            tmpFF->addToLayer(this,21);
            menuItems->addObject(tmpFF);
            tmpFF->release();
            
            if( fopTeam1 != NULL )
            {
                if( fopTeam1->hpLeft > 0 ) 
                {
                    CCPoint pos = ccp(0,112+3-16);
                    tmpSpt->initWithFile(CCString::create("targetSelector2.png"));
                    tmpSpt->updatePosition(ccp(65,pos.y));
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,20);
                    menuItems->addObject(tmpSpt);
                    tmpSpt->release();
                    tmpSpt->initWithFile(CCString::create("targetSelector3.png"));
                    tmpSpt->updatePosition(ccp(220,pos.y));
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,20);
                    menuItems->addObject(tmpSpt);
                    tmpSpt->release();
                }
            }
            if( fopTeam2 != NULL ) 
            {
                if( fopTeam2->hpLeft > 0 ) 
                {
                    CCPoint pos = ccp(0,112-40+3-16);
                    tmpSpt->initWithFile(CCString::create("targetSelector2.png"));
                    tmpSpt->updatePosition(ccp(65,pos.y));
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,20);
                    menuItems->addObject(tmpSpt);
                    tmpSpt->release();
                    tmpSpt->initWithFile(CCString::create("targetSelector3.png"));
                    tmpSpt->updatePosition(ccp(220,pos.y));
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,20);
                    menuItems->addObject(tmpSpt);
                    tmpSpt->release();
                }
            }
            if( fopTeam3 != NULL ) 
            {
                if( fopTeam3->hpLeft > 0 )
                {
                    CCPoint pos = ccp(0,112-80+3-16);
                    tmpSpt->initWithFile(CCString::create("targetSelector2.png"));
                    tmpSpt->updatePosition(ccp(65,pos.y));
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,20);
                    menuItems->addObject(tmpSpt);
                    tmpSpt->release();
                    tmpSpt->initWithFile(CCString::create("targetSelector3.png"));
                    tmpSpt->updatePosition(ccp(220,pos.y));
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,20);
                    menuItems->addObject(tmpSpt);
                    tmpSpt->release();
                }
            }
            
            
        } 
        
        
	} else if( currentMenu == 3 ) 
    {
        //Monster Selection
        
        
        this->drawMonsterSelectPage();
        
	} else if( currentMenu == 4 )
    {
        //Item Selection
        
        this->drawItemSelectPage();
    }
}




void battleLayer::shiftSelection()
{
    for(int i=1;i<menuItems->count();i++)
    {
        
        if( typeid(menuItems->objectAtIndex(i))== typeid(CoolSprite) ) 
        {
            CoolSprite * tmp =(CoolSprite*)menuItems->objectAtIndex(i);
            tmp->updatePosition(ccp(tmp->x,320-(tmp->intTag2+sliderPosition)));
            
            
        } 
       else 
        {
            CoolFreeform * tmp = (CoolFreeform*)menuItems->objectAtIndex(i);
            tmp->updatePosition(ccp(tmp->x,320-(tmp->intTag2+sliderPosition)));
            
            
            
        }
    }
}



void battleLayer::drawAttackSelectPage()
{
    
    CoolSprite * tmpSpt = NULL;
    CoolFreeform * tmpFF = NULL;
    
    int titleOffset = 32;
    sliderPosition = 0;
    
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt->updatePosition(ccp(240,160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,30);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();
    
    tmpFF->initWithCoolSheet(CCString::create("Select an Attack"),FONT_WHITE,0.30,320,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-12));
    tmpFF->intTag1 = 160;
    tmpFF->intTag2 = 12;
    tmpFF->addToLayer(this,32);
    menuItems->addObject(tmpFF);
    tmpFF->release();
    
    
    
    
    CCArray * attacks =  new CCArray();
    attacks= parent->getDatabase()->getAttacksForMonster(attackingPresently->getMonster()->monid,attackingPresently->intel);
    attacks->retain();
    
    int count = 0;
    for(int i=0 ; i<attacks->count();i++)
    {
        dataSkill * skill=(dataSkill*)attacks->objectAtIndex(i);
        
        //monsterSelectBox.png
        
        
        
        tmpSpt->initWithFile(CCString::createWithFormat("element-%s.png",Convertstring->lowercaseString(parent->getDatabase()->getTypeFromId(skill->element_type_id))->getCString()));
        tmpSpt->updatePosition(ccp(4+16,480- count * 50 + 25 + titleOffset));
        tmpSpt->intTag2 = count * 50 + 25 + titleOffset;
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,31);
        menuItems->addObject(tmpSpt);
        tmpSpt->release();
        
        tmpFF->initWithCoolSheet(skill->getName(),FONT_WHITE,0.35,320,true);
        tmpFF->updatePosition(ccp(32+8,480- count * 50 + 5 + titleOffset));
        tmpFF->intTag2 = count * 50 + 5 + titleOffset;
        tmpFF->addToLayer(this,32);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
        if( skill->scope == 0 )
        {
            tmpFF->initWithCoolSheet(CCString::create("Effects All Allies"),FONT_WHITE,0.25,320,true);
        } 
        else if( skill->scope == 1 )
        {
            tmpFF->initWithCoolSheet(CCString::create("Effects a Single Opponent"),FONT_WHITE,0.25,320,true);
        } 
        else if( skill->scope == 2 ) 
        {
            tmpFF->initWithCoolSheet(CCString::create("Effects All Opponents"),FONT_WHITE,0.25,320,true);
        } 
        else
        {
            tmpFF->initWithCoolSheet(CCString::create("Effects a Single Ally"),FONT_WHITE,0.25,320,true);
        }
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240,480 - count * 50 + 25 + titleOffset));
        tmpFF->intTag2 =count * 50 + 25 + titleOffset;
        tmpFF->addToLayer(this,32);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("Power:%d",(int)skill->power),FONT_WHITE,0.30,100,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(480-50,480- count * 50 + 5 + titleOffset));
        tmpFF->intTag2 =count * 50 + 5 + titleOffset;
        tmpFF->addToLayer(this,32);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
        count++;
        
    }
    itemCount = count;
    if( count > 0)
        count--;
    
    
    tmpFF->initWithCoolSheet(CCString::create("Cancel"),FONT_WHITE,0.4,320,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(160+104,480- count * 50 + 5 + titleOffset + 48));
    tmpFF->intTag1 = 160+104;
    tmpFF->intTag2 = count * 50 + 5 + titleOffset + 48;
    tmpFF->addToLayer(this,35);
    menuItems->addObject(tmpFF);
    tmpFF->release();
    
    attacks->release();
    this->shiftSelection();
    
}




void battleLayer::drawItemSelectPage()
{
    
    CoolSprite * tmpSpt = NULL;
    CoolFreeform * tmpFF = NULL;
    
    int titleOffset = 32;
    sliderPosition = 0;
    
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt->updatePosition(ccp(240,160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,30);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();
    
    tmpFF ->initWithCoolSheet(CCString::create("Select an Item to Use"),FONT_WHITE,0.30,320,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition( ccp(160,480-12));
    tmpFF->intTag1 = 160;
    tmpFF->intTag2 = 12;
    tmpFF->addToLayer(this,32);
    menuItems->addObject(tmpFF);
    tmpFF->release();
    
    CCDictionary * inventory = parent->getItems();
    
    int count = 0;
    
    for (int i=0; i<(int)inventory->allKeys();i++)   
    {
        CCString * keyName =(CCString*)inventory->allKeys();
        int itemId = keyName->intValue();
        int itemInstCount =parent->itemCount( itemId);
        if( itemInstCount > 0 ) 
        {
            
            dataItem * itemData = (parent->getDatabase()->itemById(itemId));
            if( itemData->isBattleItem() ) 
            {
                
                //monsterSelectBox.png
                tmpSpt->initWithFile(CCString::create("moneybag.png"));
                tmpSpt->updatePosition(ccp(4+16,480- count * 50 + 25 + titleOffset));
                tmpSpt->intTag2 = count * 50 + 25 + titleOffset;
                tmpSpt->updateOpacity(255);
                tmpSpt->addToLayer(this,31);
                menuItems->addObject(tmpSpt);
                tmpSpt->release();
                
                tmpFF->initWithCoolSheet(itemData->getName(),FONT_WHITE,0.35,320,true);
                tmpFF->updatePosition(ccp(32+8,480- count * 50 + 5 + titleOffset));
                tmpFF->intTag2 = count * 50 + 5 + titleOffset;
                tmpFF->addToLayer(this,32);
                menuItems->addObject(tmpFF);
                tmpFF->release();
                
                tmpFF->initWithCoolSheet(itemData->getDescription(),FONT_WHITE,0.25,320,true);
                tmpFF->updatePosition(ccp(32+8,480 - count * 50 + 25 + titleOffset));
                tmpFF->intTag2 =count * 50 + 25 + titleOffset;
                tmpFF->addToLayer(this,32);
                menuItems->addObject(tmpFF);
                tmpFF->release();
                
                tmpFF->initWithCoolSheet(CCString::createWithFormat("x%d",itemInstCount),FONT_WHITE,0.35,100,true);
                tmpFF->updatePosition(ccp(480-50,480- count * 50 + 5 + titleOffset));
                tmpFF->intTag2 =count * 50 + 5 + titleOffset;
                tmpFF->addToLayer(this,32);
                menuItems->addObject(tmpFF);
                tmpFF->release();
                
                count++;
            }
        }
    }
    itemCount = count;
    if( count > 0)
        count--;
    
    
    tmpFF->initWithCoolSheet(CCString::create("Cancel"),FONT_WHITE,0.4 ,320,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(160+104,480- count * 50 + 5 + titleOffset + 48));
    tmpFF->intTag1 = 160+104;
    tmpFF->intTag2 = count * 50 + 5 + titleOffset + 48;
    tmpFF->addToLayer(this,35);
    menuItems->addObject(tmpFF);
    tmpFF->release();
    
    this->shiftSelection();
    
    
}


void battleLayer::drawMonsterSelectPage()
{
    
    CoolSprite * tmpSpt = new CoolSprite();
    CoolFreeform * tmpFF = new CoolFreeform();
    
    int titleOffset = 32;
    sliderPosition = 0;
    
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt->updatePosition(ccp(284,160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,30);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();
    
    
    tmpSpt ->initWithFile(CCString::create("monsterSelectFillerBox.png"));
    tmpSpt->updatePosition(ccp(284,320-18));
    tmpSpt->intTag1 = 240;
    tmpSpt->intTag2 = 18;
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,31);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();
    
    
    if( bSelectingTarget ) 
    {
        tmpFF->initWithCoolSheet(CCString::create("Select a Target for the Item"),FONT_WHITE,0.30,320,true);  
    }
    else
    {
        tmpFF-> initWithCoolSheet(CCString::create("Select a Replacement Monster"),FONT_WHITE,0.30,320,true);
    }
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(160,320-12));
    tmpFF->intTag1 = 160;
    tmpFF->intTag2 = 12;
    tmpFF->addToLayer(this,32);
    menuItems->addObject(tmpFF);
    tmpFF->release();
    
    int count = 0;
    for(int i =0 ; i<team->count();i++)
    {
        battleObject * mon = (battleObject*)team->objectAtIndex(i);

        //monsterSelectBox.png
        
        dataMonster * dataMon = mon->getMonster();
        
        tmpSpt->initWithFile(CCString::create("monsterSelectBox.png"));
        tmpSpt->updatePosition(ccp(284,320- count * 128 + 64 + titleOffset));
        tmpSpt->intTag1 = 160;
        tmpSpt->intTag2 = count * 128 + 64 + titleOffset;
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,31);
        menuItems->addObject(tmpSpt);
        tmpSpt->release();
        
        tmpSpt->initWithFile(mon->getImage());
        tmpSpt->updatePosition(ccp(50,320-count * 128 + 64 + titleOffset - 18));
        tmpSpt->intTag1 = 50;
        tmpSpt->intTag2 = count * 128 + 64 + titleOffset - 18;
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,31);
        menuItems->addObject(tmpSpt);
        tmpSpt->release();
        
        
        tmpFF->initWithCoolSheet(mon->getName(),FONT_WHITE,0.35,320,true);
        tmpFF->updatePosition(ccp(160-56,320-count * 128 + 64 + titleOffset -54));
        tmpFF->intTag1 = 160-56;
        tmpFF->intTag2 = count * 128 + 64 + titleOffset -54;
        tmpFF->addToLayer(this,32);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
        tmpFF->initWithCoolSheet(mon->getLvlString(),FONT_WHITE,0.30,100,true);
        tmpFF->updatePosition(ccp(160-56,320-count * 128 + 64 + titleOffset -32));
        tmpFF->intTag1 = 160-56;
        tmpFF->intTag2 =count * 128 + 64 + titleOffset -32;
        tmpFF->addToLayer(this,32);
        menuItems->addObject(tmpFF);
//        [tmpFF release];
//        
//        tmpFF = [[CoolFreeform alloc] initWithCoolSheet:[mon getHpString] fontName:FONT_WHITE fontSize:0.30 andMaxWidth:100 instant:true];
//        [tmpFF updatePosition: ccp(160-56,320-count * 128 + 64 + titleOffset -10)];
//        tmpFF.intTag1 = 160-56;
//        tmpFF.intTag2 = count * 128 + 64 + titleOffset -10;
//        [tmpFF addToLayer:self z:32];
//        [menuItems addObject:tmpFF];
//        [tmpFF release];
//        
//        tmpSpt = [[CoolSprite alloc] initWithFile:[NSString stringWithFormat:@"element-%@.png",[[dataMon getType1] lowercaseString]]];
//        [tmpSpt updatePosition:ccp(14+16,320-count * 128 + 64 + titleOffset + 45)];
//        tmpSpt.intTag1 = 14+16;
//        tmpSpt.intTag2 = count * 128 + 64 + titleOffset + 45;
//        [tmpSpt updateOpacity:255];
//        [tmpSpt addToLayer:self z:37];
//        [menuItems addObject:tmpSpt];
//        [tmpSpt release];
//        
//        
//        tmpSpt = [[CoolSprite alloc] initWithFile:[NSString stringWithFormat:@"element-%@.png",[[dataMon getType2] lowercaseString]]];
//        [tmpSpt updatePosition:ccp(53+16,320-count * 64 + 64 + titleOffset + 45)];
//        tmpSpt.intTag1 = 53+16;
//        tmpSpt.intTag2 = count * 128 + 64 + titleOffset + 45;
//        [tmpSpt updateOpacity:255];
//        [tmpSpt addToLayer:self z:37];
//        [menuItems addObject:tmpSpt];
//        [tmpSpt release];
//        
//        
//        bool bAvailable = false;
//        if( bSelectingTarget ) {
//            if( itemForTarget.itemid == 13 ) {
//                if( mon.hpLeft == 0 ) {
//                    bAvailable = true;
//                    tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Fainted" fontName:FONT_GREEN fontSize:0.35 andMaxWidth:320 instant:true];
//                } else {
//                    if( fopTeam1 == mon || fopTeam2 == mon || fopTeam3 == mon ) {
//                        tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"In Battle" fontName:FONT_RED fontSize:0.35 andMaxWidth:320 instant:true];
//                    } else {
//                        tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Available" fontName:FONT_RED fontSize:0.35 andMaxWidth:320 instant:true];
//                    }
//                }
//            } else { //Other Items Require Monster who havent fainted and arent at full health
//                if( mon.hpLeft == 0 ) {
//                    tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Fainted" fontName:FONT_RED fontSize:0.35 andMaxWidth:320 instant:true];
//                } else if( mon.hpLeft == mon.hp ) {
//                    tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Max Health" fontName:FONT_RED fontSize:0.30 andMaxWidth:320 instant:true];
//                } else {
//                    bAvailable = true;
//                    if( fopTeam1 == mon || fopTeam2 == mon || fopTeam3 == mon ) {
//                        tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"In Battle" fontName:FONT_GREEN fontSize:0.35 andMaxWidth:320 instant:true];
//                    } else {
//                        tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Available" fontName:FONT_GREEN fontSize:0.35 andMaxWidth:320 instant:true];
//                    }
//                }
//            }
//        } else {
//            if( mon.hpLeft == 0 ) {
//                tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Fainted" fontName:FONT_RED fontSize:0.35 andMaxWidth:320 instant:true];
//            } else if( fopTeam1 == mon || fopTeam2 == mon || fopTeam3 == mon ) {
//                tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"In Battle" fontName:FONT_RED fontSize:0.35 andMaxWidth:320 instant:true];
//            } else {
//                tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Available" fontName:FONT_GREEN fontSize:0.35 andMaxWidth:320 instant:true];
//                bAvailable = true;
//            }
//        }
//        [tmpFF updatePosition: ccp(160-56,320-count * 128 + 64 + titleOffset + 48)];
//        tmpFF.intTag1 = 160-56;
//        tmpFF.intTag2 = count * 128 + 64 + titleOffset + 36;
//        [tmpFF addToLayer:self z:32];
//        [menuItems addObject:tmpFF];
//        [tmpFF release];
//        
//        if( bAvailable ) {
//            tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Select" fontName:FONT_GREEN fontSize:0.35 andMaxWidth:320 instant:true];
//        } else {
//            tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Select" fontName:FONT_RED fontSize:0.35 andMaxWidth:320 instant:true];
//        }
//        tmpFF.bCenter = true;
//        [tmpFF updatePosition: ccp(160+104,320-count * 128 + 64 + titleOffset + 48)];
//        tmpFF.intTag1 = 160+104;
//        tmpFF.intTag2 = count * 128 + 64 + titleOffset + 36;
//        [tmpFF addToLayer:self z:32];
//        [menuItems addObject:tmpFF];
//        [tmpFF release];
//        
//        
//        
//        count++;
//    }
//    count--;
//    
//    
//    tmpSpt = [[CoolSprite alloc] initWithFile:@"monsterSelectCancelBox.png"];
//    [tmpSpt updatePosition:ccp(284,320- count * 128 + 64 + titleOffset + 64 + 20)];
//    tmpSpt.intTag1 = 160;
//    tmpSpt.intTag2 = count * 128 + 64 + titleOffset + 64 + 20;
//    [tmpSpt updateOpacity:255];
//    [tmpSpt addToLayer:self z:34];
//    [menuItems addObject:tmpSpt];
//    [tmpSpt release];
//    
//    if( bForcedMonsterSelection == false ) {
//        
//        tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Cancel" fontName:FONT_WHITE fontSize:0.4 andMaxWidth:320 instant:true];
//        tmpFF.bCenter = true;
//        [tmpFF updatePosition: ccp(160+104,480-count * 128 + 64 + titleOffset + 64 + 10)];
//        tmpFF.intTag1 = 160+104;
//        tmpFF.intTag2 = count * 128 + 64 + titleOffset + 64 + 10;
//        [tmpFF addToLayer:self z:35];
//        [menuItems addObject:tmpFF];
//        [tmpFF release];
//        
//   }
//    
//    [self shiftSelection];
    
}
}



void battleLayer::changeHpFor(int target ,int to) 
{
    
}



void battleLayer::advanceEachBattler ()
{
    
}



void battleLayer::checkForReadyAttackers()
{
    
}


void battleLayer:: addBattleMessage(CCString * msg)
{
    
}


void battleLayer::ccTouchesBegan(cocos2d::CCSet* touches ,CCEvent* event)
{
    
}


void battleLayer::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    
}


void battleLayer:: sfx(CCString * effect)
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(effect->getCString());
}

void battleLayer::ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    
}






























