//
//  gameEvent.cpp
//  Geosociety
//
//  Created by praveen Kumar on 30/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "gameEvent.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
gameEvent *gameEvent::initWithData(CCArray * data,menuLayer * pL)
{
 {
		parentLayer = pL;
		sprite = NULL;
		bIsUser = false;
        moveQueue = new CCArray();
		
     eventData = new CCArray();
		this->processConditions();
		
     
        mapPosition.x = (int)eventData->objectAtIndex(5);
        mapPosition.y = (int)eventData->objectAtIndex(6);
		
		
		//Find the correct template and load it
     if( (((CCString*)data->objectAtIndex(2))->isEqual(CCString::create(""))))
     {
			spriteSheet =NULL;
     }
     else 
     {
         spriteSheet = CCSpriteBatchNode::create(((CCString*)data->objectAtIndex(2))->getCString());
         parentLayer->addChild(spriteSheet);
			
            spriteSize = CCRectMake(0,0,24,32);
         
         if(((CCString*)data->objectAtIndex(2))->isEqual(CCString::create("579 - Gargalis.png"))||((CCString*)data->objectAtIndex(2))->isEqual(CCString::create("597 - Striperior.png")))
          {
                spriteSize = CCRectMake(0,0,48,64); 
          }
            
         if( ((CCString*)data->objectAtIndex(2))->isEqual(CCString::create("Zombie.png")))
         {
                bZombie = true;
            }
                
         sprite= new CoolSprite();
      
         
			sprite->initWithTexture(spriteSheet->getTexture(),CCRectMake(spriteSize.size.width * 2,spriteSize.size.height,spriteSize.size.width,spriteSize.size.height));
			
            this->loadAnimationFromSheet();
            sprite->updatePosition(ccp(-1000 , -1000));
			sprite->addToLayer(parentLayer,10);
		
         
         std::string lowercaseString= ((CCString*)data->objectAtIndex(3))->getCString();
         std::transform(lowercaseString.begin(), lowercaseString.end(), lowercaseString.begin(), ::tolower);
         
         CCString* tempString= CCString::create(lowercaseString);
         
       
			if (tempString->isEqual(CCString::create("up")))
            {
				direction = 0;
			}
            else if (tempString->isEqual(CCString::create("down"))) 
            {
				direction = 1;
			} 
            else if (tempString->isEqual(CCString::create("left")))
            {
				direction = 2;
			} 
            else if (tempString->isEqual(CCString::create("right")))
            {
				direction = 3;
			} 
			
			bHasAppearance = true;
			
		}
     this->scaleTo(parentLayer->getGameScale());
		this->evaluate();
	}
	return this;
}



void gameEvent::updateImage(CCString * newStyle)
{
    
    sprite->release();
    sprite = NULL;
    
    parentLayer->removeChild(spriteSheet,false);
    
    spriteSheet =CCSpriteBatchNode::create(newStyle->getCString());
    parentLayer->addChild(spriteSheet);
    
    spriteSize = CCRectMake(0,0,24,32);
    if( (newStyle->isEqual(CCString::create("579 - Gargalis.png"))) || (newStyle->isEqual(CCString::create("597 - Striperior.png"))))
    {
        spriteSize = CCRectMake(0,0,48,64); 
    }
    
    sprite->initWithTexture(spriteSheet->getTexture(),CCRectMake(spriteSize.size.width * 2,spriteSize.size.height,spriteSize.size.width,spriteSize.size.height));
    this->loadAnimationFromSheet();
    sprite->addToLayer(parentLayer,10);
    
}




void gameEvent::loadAnimationFromSheet()
{
	if( spriteSheet == NULL )
    {
		return;
	}
    
	
	//Up
	sprite->addFrame(spriteSheet->getTexture(),CCRectMake(0 * spriteSize.size.width, 0 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	sprite->addFrame(spriteSheet->getTexture(),CCRectMake(1 * spriteSize.size.width, 3 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	sprite->addFrame(spriteSheet->getTexture(),CCRectMake(2 * spriteSize.size.width, 0 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	
	//Down
	sprite->addFrame(spriteSheet->getTexture(),CCRectMake(2 * spriteSize.size.width, 1 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	sprite->addFrame( spriteSheet->getTexture(),CCRectMake(2 * spriteSize.size.width, 2 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	sprite->addFrame(spriteSheet->getTexture(),CCRectMake(2 * spriteSize.size.width, 3 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	
	//Left
	sprite->addFrame( spriteSheet->getTexture(),CCRectMake(0 * spriteSize.size.width, 1 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	sprite->addFrame(spriteSheet->getTexture(),CCRectMake(0 * spriteSize.size.width, 2 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	sprite->addFrame( spriteSheet->getTexture(),CCRectMake(0 * spriteSize.size.width, 3 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	
	//Right
	sprite->addFrame(spriteSheet->getTexture(),CCRectMake(1 * spriteSize.size.width, 0 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	sprite->addFrame( spriteSheet->getTexture(),CCRectMake(1 * spriteSize.size.width, 1 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	sprite->addFrame( spriteSheet->getTexture(),CCRectMake(1 * spriteSize.size.width, 2 * spriteSize.size.height, spriteSize.size.width, spriteSize.size.height));
	
	sprite->commitFrames();
	
}




gameEvent *gameEvent::initSelf(CCPoint position,menuLayer * pL)
{
	
    {
		parentLayer = pL;
		sprite = NULL;
		bIsUser = true;
		moveQueue = new CCArray();
		
		eventData = NULL;
		bEventEnabled = true;
		
        spriteSize =CCRectMake(0,0,24,32);
		spriteSheet= CCSpriteBatchNode::create("4Jake.png");
		parentLayer->addChild(spriteSheet);
		sprite= new CoolSprite();
		sprite->initWithTexture(spriteSheet->getTexture(),CCRectMake(0, 0, 24, 32));
		this->loadAnimationFromSheet();
        this->scaleTo(parentLayer->getGameScale());
		sprite->updatePosition(ccp(-1000,-1000));
		sprite->addToLayer(parentLayer,10);
		this->evaluate();
		
	}
	return this;
}


CCString *gameEvent::getName()
{
	return (CCString*)eventData->objectAtIndex(0);
}


void gameEvent::processConditions()
{
	
	CCArray * conditions = new CCArray();
    conditions->addObject(convertedString->componentsSeparatedByString(((CCString*)eventData->objectAtIndex(7)), CCString::create("~")));  
	bool bShow = true;
	for(int i=0; i< conditions->count();i++)
    {
        CCString * condLine=(CCString*)conditions->objectAtIndex(i); 
		if( condLine->isEqual(CCString::create("")) == false ) 
        {
            
            
            CCArray * condData = new CCArray();
            condData->addObject(convertedString->componentsSeparatedByString(condLine, CCString::create("^")));  
			if( ((CCString*)condData->objectAtIndex(0))->isEqual(CCString::create("Global Variable")))
            {
				
				if( (parentLayer->globalValue((CCString*)condData->objectAtIndex(1)) == true && ((CCString*)condData->objectAtIndex(2))->isEqual(CCString::create("T"))) || ((parentLayer->globalValue((CCString*)condData->objectAtIndex(1)) == false && ((CCString*)condData->objectAtIndex(2))->isEqual(CCString::create("F")))))
                {
                    
                }
                else 
                {
					bShow = false;
				}
				
			}
            else 
            {
				//TODO: Other Criteria
			}
			
		}
	}	
	bEventEnabled = bShow;
	
	if( bEventEnabled == false ) 
    {
		if( sprite != NULL )
        {
			sprite->updatePosition(ccp(-1000,-1000));
		}
	}
	
	//TODO: Run this function for all events whenever a global is updated
}



int gameEvent::moveQueueSize()
{
	return moveQueue->count();
}

bool gameEvent::tileIsWalkable(CCTMXTiledMap * map,CCPoint position)
{
	
	if( map == NULL)
    {
		return false;
	}
	
	if( position.x < 0 )
		return false;
	if( position.y < 0 )
		return false;
	if( position.x >=  map->getContentSize().width )
		return false;
	if( position.y >= map->getContentSize().height )
		return false;
	
    if( parentLayer->tileIsFreeFromEvents(position) == false )
    {
		return false;
	}
	
	
	CCTMXLayer * layer1 = map->layerNamed("Collision");
	CCTMXLayer * layer2 = map->layerNamed("Collision1");
	CCTMXLayer * layer3 = map->layerNamed("Collision2");
    
    if( layer1 != NULL ) 
    {
        if( layer1->tileGIDAt(ccp(position.x,position.y)) == 0 )
        {
            return true;
        }
    }
    if( layer2 != NULL ) 
    {
        if( (layer2 ->tileGIDAt(ccp(position.x,position.y))) == 0 )
        {
            if( layer3 != NULL )
            {
                if( (layer3->tileGIDAt(ccp(position.x,position.y))) == 0 )
                {
                    return true;
                }
            }
            else 
            {
                return true;
            }
        }
    }
	return false;
}


void gameEvent::addMoveQueue(CCString * moveDirection)
{
	
	CCTMXTiledMap * map = parentLayer->getMap();
	if( map == NULL ) 
    {
		return;
	}
	
	bool bAllow = false;
    
   
    
    CCString* tempString= convertedString->lowercaseString(moveDirection);
    

    
	if(tempString->isEqual(CCString::create("up")))
       {
		if( this->tileIsWalkable(map,ccp(mapPosition.x,mapPosition.y-1)) || bIsUser == false ) 
        {
			bAllow = true;
		}
		direction = 0;
	} 
    else if( tempString->isEqual(CCString::create("down"))) 
    {
		if( this->tileIsWalkable( map,ccp(mapPosition.x,mapPosition.y+1)) || bIsUser == false  ) 
        {
			bAllow = true;
		}
		direction = 1;
	} 
    else if( tempString->isEqual(CCString::create("left"))) 
    {
		if( this->tileIsWalkable(map,ccp(mapPosition.x-1,mapPosition.y)) || bIsUser == false  ) 
        {
			bAllow = true;
		}
		direction = 2;
	} 
    else if(tempString->isEqual(CCString::create("right")))
    {
		if(this->tileIsWalkable(map,ccp(mapPosition.x+1,mapPosition.y)) || bIsUser == false ) 
        {
			bAllow = true;
		}
		direction = 3;
	} 
    else if( tempString->isEqual(CCString::create("jump")))
    {
		bJumping = true;
		jumpYAcc = -8;
		bAllow = true;
	} 
    else if(tempString->isEqual(CCString::create("face up")) )
    {
		direction = 0;
	} 
    else if( tempString->isEqual(CCString::create("face down")))
    {
		direction = 1;
	} 
    else if(tempString->isEqual(CCString::create("face left")))
    {
		direction = 2;
	} 
    else if(tempString->isEqual(CCString::create("face right")))
    {
		direction = 3;
	} 
    else if(tempString->isEqual(CCString::create("hide")))
    {
		sprite->updateOpacity(0);
        bHidden = true;
	} 
    else if(tempString->isEqual(CCString::create("show"))) 
    {
		sprite->updateOpacity(255);
        bHidden = false;
	}
    if( bAllow ) 
    {
		moveQueue->addObject(tempString);
	}
}





void gameEvent::processNPCMovement()
{
    
    
    if(eventData->count() > 4 && moveQueue->count() == 0 && parentLayer->isProcessingScript() == false  && parentLayer->isActive() && parentLayer->bBattleStarted == false) 
    {
        CCString * moveType =  (CCString*)eventData->objectAtIndex(4);
        
        if(moveType->isEqual(CCString::create("Slow Random")) || moveType->isEqual(CCString::create("Fast Random")))
        {
            
            
            //Random Movement
            if( arc4random() % 20 == 1 ) 
            {
                int randDirection = arc4random() % 4;
                if( randDirection == 0 ) 
                {
                    this->addMoveQueue(CCString::create("up"));
                } 
                else if( randDirection == 1 ) 
                {
                    this->addMoveQueue(CCString::create("down"));
                } 
                else if( randDirection == 2 )
                {
                    this->addMoveQueue(CCString::create("left"));
                } 
                else 
                {
                    this->addMoveQueue(CCString::create("right"));
                }
            }
            
        } 
        else if( moveType->isEqual(CCString::create("Slow Towards User")) || moveType->isEqual(CCString::create("Fast Towards User"))) 
        {
            
            int difX = mapPosition.x - parentLayer->getUser()->mapPosition.x;
            int difY = mapPosition.y - parentLayer->getUser()->mapPosition.y;
            
            
            double distX = difX;
            if( distX < 0 )
                distX = distX * -1;
                double distY = difY;
                if( distY < 0 )
                    distY = distY * -1;
                    
                    double distance = sqrt( distX * distX + distY * distY );
                    bool bCanSeeUser = false;
                    if( distance < 10 )
                    {
                        bCanSeeUser = true;
                    }
            if( moveType->isEqual(CCString::create("Fast Towards User")))
            {
                if( distance < 16 ) 
                {
                    bCanSeeUser = true;
                }
            }
            
            
            if( bCanSeeUser )
            {
                if( distY == 1 && distX == 1 )
                {
                    
                } 
                else 
                {
                    //Calc the two direction components, we'll judge which is best to do first for best impact.
                    int dirH = 0;
                    int dirV = 0;
                    
                    if( difX > 0 ) 
                    {
                        dirH = 2;
                    } 
                    else if( difX < 0 ) 
                    {
                        dirH = 3;
                    }
                    
                    if( difY > 0 ) 
                    {
                        dirV = 0;
                    } else if( difY < 0 ) 
                    {
                        dirV = 1;
                    }
                    
                    int chanceToMoveOutOf = 1;
                    if( moveType->isEqual(CCString::create("Slow Towards User")))
                    {
                        chanceToMoveOutOf = 5;
                    }
                    
                    if( arc4random() % chanceToMoveOutOf == 0  )
                    {
                        if( (arc4random() % 2 == 1 || difX == 0) && difY != 0 )
                        {
                            if( dirV == 0 ) 
                            {
                                this->addMoveQueue(CCString::create("up"));
                            } 
                            else 
                            {
                                this->addMoveQueue(CCString::create("down"));
                            }
                        } 
                        else 
                        {
                            if( dirH == 2 ) 
                            {
                                this->addMoveQueue(CCString::create("left"));
                            }
                            else 
                            {
                                this->addMoveQueue(CCString::create("right"));
                            }
                        }
                    }
                }
            } else {
                //Random Movement
                if( arc4random() % 20 == 1 ) 
                {
                    int randDirection = arc4random() % 4;
                    if( randDirection == 0 )
                    {
                        this->addMoveQueue(CCString::create("up"));
                    } 
                    else if( randDirection == 1 ) 
                    {
                       this->addMoveQueue(CCString::create("down"));
                    } 
                    else if( randDirection == 2 ) 
                    {
                        this->addMoveQueue(CCString::create("left"));
                    } else 
                    {
                       this->addMoveQueue(CCString::create("right"));
                    }
                }
            }
        }
        
        
    }
}



void gameEvent::evaluate()
{
	if( bEventEnabled == false ) 
    {
		return;
	}
	
	if( spriteSheet == NULL ) 
    {
		
	}
    else 
    {
        if( bIsUser == false )
        {
            this->processNPCMovement();
        }
        
		this->processMoveQueue();
		this->updatePosition();
	}
	
	
	
}

void gameEvent::processMoveQueue()
{
	//Move Queue
	//if( stepPart == 0 ) {
    
    
	CCTMXTiledMap * map = parentLayer->getMap();
	if( map == NULL )
    {
		return;
	}
    
    bool bPassedCheck = false;
    while( bPassedCheck == false ) 
    {
        if(moveQueue->count() > 0 ) 
        {
            if( ((CCString*)(moveQueue->objectAtIndex(0)))->isEqual(CCString::create("up"))) 
            {
                if( !(this->tileIsWalkable(map,ccp(mapPosition.x,mapPosition.y-1)))) 
                {
                    moveQueue->removeObjectAtIndex(0);
                } 
                else 
                {
                    bPassedCheck = true;
                }
            } 
            else if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("down"))))
            {
                if( !(this->tileIsWalkable(map,ccp(mapPosition.x,mapPosition.y+1))))
                {
                    moveQueue->removeObjectAtIndex(0);
                } 
                else 
                {
                    bPassedCheck = true;
                }
            }
            else if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("left"))) )
            {
                if( !(this->tileIsWalkable( map,ccp(mapPosition.x-1,mapPosition.y))))
                {
                    moveQueue->removeObjectAtIndex(0);
                } 
                else {
                    bPassedCheck = true;
                }
            } 
            else if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("right"))))
            {
                if( !(this->tileIsWalkable( map,ccp(mapPosition.x+1,mapPosition.y))))
                {
                    moveQueue->removeObjectAtIndex(0);
                } 
                else 
                {
                    bPassedCheck = true;
                }
            } 
            else if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("jump"))))
            {
                bPassedCheck = true;
            }
        } 
        else 
        {
            bPassedCheck = true;
        }
    }
    
	if(moveQueue->count() > 0 )
    {
		
        
        
		if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("up"))))
        {
			direction = direction_up;
		} 
        else if(((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("down"))))
        {
			direction = direction_down;
		} 
        else if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("left"))))
        {
			direction = direction_left;
		} 
        else if(((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("right"))))
        {
			direction = direction_right;
		} 
        else if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("jump"))))
        {
			jumpYAcc = jumpYAcc + 2;
			jumpYAdd = jumpYAdd + jumpYAcc;
			
			if( jumpYAcc == 4 ) 
            {
				jumpYAcc = 0;
				jumpYAdd = 0;
				bJumping = false;
				
				moveQueue->removeObjectAtIndex(0);
			}
			
			return;
		}
		
		stepAnimation++; 
		if( stepAnimation > 2 ) 
			stepAnimation = 0;
            
            
            stepPart = stepPart + 4;
            if( parentLayer->bKeyC && moveQueue->count() == 1 && bIsUser) 
                stepPart = stepPart + 4;
                
                if( bZombie ) 
                    stepPart = stepPart - 2;
                    
                    if( stepPart >= 16 ) 
                    {
                        stepPart = 0;
                        
                        //update the coordanates at the end of the step.
                        if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("up"))))
                        {
                            mapPosition.y = mapPosition.y - 1;
                        } 
                        else if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("down"))))
                        {
                            mapPosition.y = mapPosition.y + 1;
                        } 
                        else if( ((CCString*)(moveQueue->objectAtIndex(0))->isEqual(CCString::create("left"))))
                        {
                            mapPosition.x = mapPosition.x - 1;
                        } 
                        else 
                        {
                            mapPosition.x = mapPosition.x + 1;
                        }
                        
                        if( bIsUser ) 
                        {
                           parentLayer->arrivedOnTile();
                        }
                        else 
                        {
                            parentLayer->eventCheck();
                        }
                        
                        moveQueue->removeObjectAtIndex(0);
                    }
    }
}



bool gameEvent::onWalk() 
{
	if( eventData != NULL )
    {
		if( ((CCString*)eventData->objectAtIndex(1))->isEqual(CCString::create("Walk Over")))
        {
			return true;
		}
	}
    return false;
}

bool gameEvent::onTalk()
{
	if( eventData != NULL )
    {
		if( ((CCString*)eventData->objectAtIndex(1))->isEqual(CCString::create("Action Button")) )
        {
			return true;
		}
	}
    return false;
}

bool gameEvent::onViewCollisionX1()
{
	if( eventData != NULL )
    {
        CCString * tmpStr =(CCString*)eventData->objectAtIndex(1);
		if( tmpStr->isEqual(CCString::create("View Collision x1")))
        {
			return true;
		}
	}
    return false;
}
bool gameEvent::onViewCollisionX2() 
{
	if( eventData != NULL )
    {
        CCString * tmpStr = (CCString*)eventData->objectAtIndex(1);
		if( tmpStr->isEqual(CCString::create("View Collision x2")))
        {
			return true;
		}
	}
    return false;
}
bool gameEvent::onViewCollisionX3()
{
	if( eventData != NULL )
    {
        CCString * tmpStr =(CCString*)eventData->objectAtIndex(1);
		if( tmpStr->isEqual(CCString::create("View Collision x3")))
        {
			return true;
		}
	}
    return false;
}

bool gameEvent::hasAppearance()
{
    if(bHidden ) 
        return false;
	return bHasAppearance;
}

bool gameEvent::isEnabled()
{
    if(bHidden ) 
        return false;
	return bEventEnabled;
}

CCString *gameEvent::getScript()
{
	if( eventData != NULL ) 
    {
		return (CCString*)eventData->objectAtIndex(8);
	} 
    else 
    {
		return NULL;
	}
}

void gameEvent::scaleTo(double newScale)
{
    gameScale = newScale;
    sprite->updateScale(newScale * 0.9);
}


void gameEvent::updatePosition()
{
	
	int width = parentLayer->sWidth();
	int height = parentLayer->sHeight();
	int ySink = 0;
	
	int offsetX = 0;
	int offsetY = 0;
	
    
	int MyX = mapPosition.x * 16 * gameScale;
	int MyY = mapPosition.y * 16 * gameScale;
	
	CCTMXTiledMap * map = new CCTMXTiledMap();
    map=parentLayer->getMap();
	if( map == NULL)
    {
		sprite->updatePosition(ccp(-1000 , -1000));
		return;
	}
	
    double mapWidth =200;// Changed map->getContentSize().width * map->getContentSize().width * gameScale;
    double mapHeight =200; // Changed map->getContentSize().height * map->getContentSize().height * gameScale;
    
	int stepX = 0;
	int stepY = 0;
	if( bIsUser == false ) 
    {
		if( moveQueue->count() > 0 ) 
        {
			if(((CCString*)moveQueue->objectAtIndex(0))->isEqual(CCString::create("up")))
            {
				stepY = -stepPart;
			} 
            else if(((CCString*)moveQueue->objectAtIndex(0))->isEqual(CCString::create("down")))
            {
				stepY = stepPart;
			} 
            else if(((CCString*)moveQueue->objectAtIndex(0))->isEqual(CCString::create("left")))
            {
				stepX = -stepPart;
			} 
            else
            {
				stepX = stepPart;
			}
		}
		
		stepX = stepX * gameScale;
		stepY = stepY * gameScale;
        
        
        int addY = 0;
        
        int magicNumber = 480;
        if( gameScale > 1 ) {
            magicNumber = 1280;
            addY = -32;
        }
        
        
        
        
		int yValue = ( ((MyY-parentLayer->mapTop+stepY )-magicNumber)*-1)+ height +(5+26-26-40) + addY;
		if( mapHeight <= height*2 ) {
			height = 0;
			yValue = ( ((MyY-parentLayer->mapTop+stepY )-magicNumber)*-1)+ height +(5+26) + addY ;
		} 
        
        if( spriteSize.size.width == 48 ) 
        {
            sprite->updatePosition(ccp( parentLayer->mapLeft+MyX+stepX, yValue*gameScale - jumpYAdd*gameScale+13+2));
        } 
        else 
        {  
            sprite->updatePosition(ccp( parentLayer->mapLeft+MyX+stepX+8*gameScale, yValue - jumpYAdd*gameScale+2));
        }
	} 
    else 
    {
		if(moveQueue->count() > 0 )
        {
			if( (CCString*)moveQueue->objectAtIndex(0)->isEqual(CCString::create("left")))
            {
				if(  MyX <= width/2 || MyX > mapWidth - width/2 ) 
                {
					stepX = -stepPart;
				}
			} 
            else if((CCString*)moveQueue->objectAtIndex(0)->isEqual(CCString::create("right")))
            {
				if(  MyX < width/2 || MyX >= mapWidth - width/2 ) 
                {
					stepX = stepPart;
				}
			}
		}
		if(  MyY <= height/2 || MyY >= mapHeight - height/2 ) 
        {
			if(moveQueue->count() > 0 ) 
            {
				if((CCString*)moveQueue->objectAtIndex(0)->isEqual(CCString::create("up")))
                {
					stepY = -stepPart;
				} 
                else if((CCString*)moveQueue->objectAtIndex(0)->isEqual(CCString::create("down")))
                {
					stepY = stepPart;
				}
			}
		}
		
		
		stepX = stepX * gameScale;
		stepY = stepY * gameScale;
        
        
		if(moveQueue->count() > 0 )
        {
			if( (CCString*)moveQueue->objectAtIndex(0)->isEqual(CCString::create("right")))
            {
				if( MyX+stepX >= mapWidth - width/2 ) 
                {
					offsetX = width/2 + ( mapWidth - MyX-stepX ) * -1;
				}
			} 
            else 
            {
				if( MyX-stepX > mapWidth - width/2 ) 
                {
					offsetX = width/2 + ( mapWidth - MyX-stepX ) * -1;
				}
			}
		} 
        else 
        {
			if( MyX-stepX > mapWidth - width/2 ) {
				offsetX = width/2 + ( mapWidth - MyX-stepX ) * -1;
			}
		}
		
		if(moveQueue->count() > 0 )
        {
			if( (CCString*)moveQueue->objectAtIndex(0)->isEqual(CCString::create("left")))
            {
				if( MyX+stepX <= width/2 )
                {
					offsetX = (width/2-MyX-stepX)*-1;
				}
			} 
            else 
            {
				if( MyX-stepX < width/2 ) 
                {
					offsetX = (width/2-MyX-stepX)*-1;
				}
			}
		} 
        else 
        {
			if( MyX-stepX < width/2 ) 
            {
				offsetX = (width/2-MyX-stepX)*-1;
			}
		}
        
		if( MyY+stepY > mapHeight - height/2 ) 
        {
			offsetY = height/2 + ( mapHeight - MyY-stepY ) * -1;
		}
		if( MyY+stepY < height/2 ) 
        {
			offsetY = (height/2-MyY-stepY)*-1;
		}
		
        
        //NSLog(@"Height: %d OffsetY: %d Sink: %f JumpAdd: %f ", height-height/2,offsetY,ySink*gameScale,jumpYAdd*gameScale);
        
		sprite->updatePosition(ccp( width/2 + offsetX +8*gameScale , height-height/2 - offsetY - ySink*gameScale - jumpYAdd*gameScale ));
	}
	
	sprite->setFrame((direction*3) + stepAnimation);
	
	if( bIsUser == false ) 
    {
		CCPoint pos = parentLayer->userPosition();
		if( pos.y < mapPosition.y ) 
        {
			sprite->reorderTo(11);
		} 
        else 
        {
			sprite->reorderTo(9);
		}
		
	}
	
}
int gameEvent::getDirection()
{
	return direction;
}


