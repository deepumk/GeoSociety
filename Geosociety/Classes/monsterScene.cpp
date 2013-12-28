//
//  monsterScene.cpp
//  Geosociety
//
//  Created by praveen Kumar on 29/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "monsterScene.h"



monsterScene * monsterScene::initWithMonsterData(dataDictionary * database,int monid)
{
	
    layer = new monsterLayer();
    layer->initWithMonsterData(database, monid);
   this->addChild(layer,1);
	
	return this;
}



monsterScene::monsterScene()
{
    
}


#pragma MonsterLayer


monsterLayer *monsterLayer::initWithMonsterData(dataDictionary * database,int monid)
{
	{
    setTouchEnabled(true);
    menuItems = new CCArray();
    staticItems =new CCArray();
		
    CoolSprite * tmpSpt = new CoolSprite();
    tmpSpt->initWithFile(CCString::create("bgMenu.png"));
    tmpSpt->updatePosition(ccp(240,160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,9);
    staticItems->addObject(tmpSpt);
    tmpSpt->release();
		
        menuItems->removeAllObjects();
        
    tmpSpt->initWithFile(CCString::create("monsterbg.png"));
        tmpSpt->updatePosition(ccp(284,160));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this ,9);
        tmpSpt->intTag1 = 240;
        menuItems->addObject(tmpSpt);
        tmpSpt->release();
        
         dataMonster * mon = (dataMonster*)database->monById(monid);
        
        
        CoolFreeform * tmpFF = new CoolFreeform();
        tmpFF->initWithCoolSheet(CCString::createWithFormat("Name: %s",(mon->getName()) ),FONT_WHITE,0.35,310,true);
        tmpFF->updatePosition(ccp(108,320-15));
        tmpFF->intTag1 = 320-25;
        tmpFF->addToLayer(this,20);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
    tmpFF->initWithCoolSheet(CCString::createWithFormat("Type1: %s, Type2: %s", database->getTypeFromId(mon->type1Id)->getCString(),(database->getTypeFromId(mon->type2Id)->getCString())) ,FONT_WHITE,0.25 ,310,true);
        tmpFF->updatePosition(ccp(108,320-20-20));
        tmpFF->intTag1 = 320-25;
        tmpFF-> addToLayer(this,20);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
                             
        tmpFF->initWithCoolSheet(CCString::createWithFormat("Category: %s",(mon->getCategory()->getCString())),FONT_WHITE,0.25,310,true);
        tmpFF->updatePosition(ccp(108,320-20-20-15));
        tmpFF->intTag1 = 320-25;
        tmpFF->addToLayer(this,20);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("Base Health Points: %d",mon->hp),FONT_WHITE,0.25,310,true);
        tmpFF->updatePosition(ccp(108,320-20-20-15-15));
        tmpFF->intTag1 = 320-25;
        tmpFF->addToLayer(this,20);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
      
        CCString * fullID =CCString::createWithFormat("%s%d","000",mon->monid);
        CCString * leadingZerosID = convertedString->substringToIndex(fullID, fullID->length()-3);
        CCString * fileName = CCString::createWithFormat("%s%s%s","dpffa",leadingZerosID->getCString(),".png");
        tmpSpt =new CoolSprite();
        tmpSpt->initWithFile(fileName);
        tmpSpt->updatePosition(ccp(9+40,320-(9+40)));
        tmpSpt->intTag1 = 320-(9+40);
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,10);
        menuItems->addObject(tmpSpt);
        tmpSpt->release();
        
                                 
        tmpSpt->initWithFile(convertedString->lowercaseString((CCString::createWithFormat("element-%d.png",(int)database->getTypeFromId(mon->type1Id)))));
        tmpSpt->updatePosition(ccp(53+16,320-98-16));
        tmpSpt->intTag1 = 320-98-16;
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,10);
        menuItems->addObject(tmpSpt);
        tmpSpt->release();
       
       
       tmpSpt->initWithFile(convertedString->lowercaseString((CCString::createWithFormat("element-%d.png",(int)database->getTypeFromId(mon->type2Id)))));
       tmpSpt->updatePosition(ccp(14+16,320-98-16));
       tmpSpt->intTag1 = 320-98-16;
       tmpSpt->updateOpacity(255);
       tmpSpt->addToLayer(this,10);
       menuItems->addObject(tmpSpt);
       tmpSpt->release();
       
       
        
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("ATK: %d",mon->atk),FONT_WHITE,0.4,310,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(151,320-101));
        tmpFF->intTag1 = 320-106;
        tmpFF->addToLayer(this ,20);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("DEF: %d",mon->def),FONT_WHITE,0.4,310,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(260,320-101));
        tmpFF->intTag1 = 320-106;
        tmpFF->addToLayer(this,20);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("SPD: %d",mon->spd),FONT_WHITE,0.4,310,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(151,320-140));
        tmpFF->intTag1 = 320-145;
        tmpFF->addToLayer(this,20);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("INT: %d",mon->intel),FONT_WHITE,0.4,310,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(260,320-140));
        tmpFF->intTag1 = 320-145;
        tmpFF->addToLayer(this, 20);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
            if( mon->evolvesto > 0 )
             {
             dataMonster * evolve1 = (dataMonster*)database->monById(mon->evolvesto);
             
                fullID = CCString::createWithFormat("%s%d","000",evolve1->monid);
                 leadingZerosID = convertedString->substringToIndex(fullID, fullID->length()-3);
                 fileName = CCString::createWithFormat("%s%s%s","dpffa",leadingZerosID->getCString() ,".png");
                
                
                tmpSpt= new CoolSprite();
             tmpSpt-> initWithFile(fileName);
             tmpSpt->updatePosition(ccp(9+40,320-(184+40)));
             tmpSpt->intTag1 = 320-(222+40);
             tmpSpt->updateOpacity(255);
             tmpSpt->addToLayer(this,10);
             menuItems->addObject(tmpSpt);
             tmpSpt->release();
             
            tmpFF ->initWithCoolSheet(CCString::createWithFormat("Name: %s",evolve1->getName()->getCString()),FONT_WHITE,0.25,310,true);
             tmpFF->updatePosition(ccp(108,320-(184+15)+8));
             tmpFF->intTag1 = 320-(222-35);
             tmpFF->addToLayer(this,20);
             menuItems->addObject(tmpFF);
             tmpFF->release();
             
                tmpFF->initWithCoolSheet(CCString::createWithFormat("Type1: %s",database->getTypeFromId(evolve1->type1Id)->getCString() ),FONT_WHITE,0.20,310,true);
             tmpFF->updatePosition(ccp(108,320-(184+15)-20+8));
             tmpFF->intTag1 = 320-(222-35)-20;
             tmpFF->addToLayer(this,20);
             menuItems->addObject(tmpFF);
             tmpFF->release();
             
              tmpFF->initWithCoolSheet(CCString::createWithFormat("Type2: %s",database->getTypeFromId(evolve1->type2Id)->getCString()),FONT_WHITE,0.20,310,true);
             tmpFF->updatePosition(ccp(108,320-(184+15)-20-10+8));
             tmpFF->intTag1 = 320-(222-35)-20;
             tmpFF->addToLayer(this,20);
             menuItems->addObject(tmpFF);
             tmpFF->release();
             
              tmpFF->initWithCoolSheet(CCString::createWithFormat("Mutates at Level: %d",mon->evolvelvl),FONT_WHITE,0.20,310,true);
             tmpFF->updatePosition(ccp(108,320-(184+15)-20-10-10-8));
             tmpFF->intTag1 = 320-(222-35)-20-15;
             tmpFF->addToLayer(this,20);
             menuItems->addObject(tmpFF);
             tmpFF->release();
             
             if( evolve1->evolvesto > 0 ) 
             { 
                 dataMonster * evolve2 = (dataMonster*)database->monById(evolve1->evolvesto);
                 
                 fullID = CCString::createWithFormat("%s%d","000",evolve2->monid);
                 leadingZerosID = convertedString->substringToIndex(fullID, fullID->length()-3);
                 fileName = CCString::createWithFormat("%s%s%s","dpffa",leadingZerosID->getCString(),".png");
                 tmpSpt= new CoolSprite();
                 tmpSpt->initWithFile(fileName);
                 tmpSpt->updatePosition(ccp(234+9+40,320-(184+40)));
                 tmpSpt->updateOpacity(255);
                 tmpSpt->addToLayer(this ,10);
                 menuItems->addObject(tmpSpt);
                 tmpSpt->release();
                 
                 
                 tmpFF->initWithCoolSheet(CCString::createWithFormat("Name: %s",evolve2->getName()->getCString()),FONT_WHITE,0.25,310,true);
                 tmpFF->updatePosition(ccp(234+108,320-(184+15)+8));
                 tmpFF->intTag1 = 320-(222-35);
                 tmpFF->addToLayer(this,20);
                 menuItems->addObject(tmpFF);
                 tmpFF->release();
                 
               tmpFF->initWithCoolSheet(CCString::createWithFormat("Type1: %s",database->getTypeFromId(evolve2->type1Id)->getCString()),FONT_WHITE,0.20,310,true);
                 tmpFF->updatePosition(ccp(234+108,320-(184+15)-20+8));
                 tmpFF->intTag1 = 320-(222-35)-20;
                 tmpFF->addToLayer(this,20);
                 menuItems->addObject(tmpFF);
                 tmpFF->release();
                 
              tmpFF->initWithCoolSheet(CCString::createWithFormat("Type2: %@",database->getTypeFromId(evolve2->type2Id) ),FONT_WHITE,0.20,310,true);
                 tmpFF->updatePosition(ccp(234+108,320-(184+15)-20-10+8));
                 tmpFF->intTag1 = 320-(222-35)-20;
                 tmpFF->addToLayer(this,20);
                 menuItems->addObject(tmpFF);
                 tmpFF->release();
                 
              tmpFF->initWithCoolSheet(CCString::createWithFormat("Mutates at Level: %d",evolve1->evolvelvl),FONT_WHITE,0.20,310,true);
                 tmpFF->updatePosition(ccp(234+108,320-(184+15)-20-10-10-8));
                 tmpFF->intTag1 = 320-(222-35)-20-15;
                 tmpFF->addToLayer(this,20);
                 menuItems->addObject(tmpFF);
                 tmpFF->release();
                 
                 
             }
         }
        
        
        tmpFF->initWithCoolSheet(CCString::create("Tap to Close") ,FONT_WHITE,0.3,310,true);
        tmpFF->updatePosition(ccp(160+5,25));
        tmpFF->intTag1 = 25;
        tmpFF->addToLayer(this,20);
        menuItems->addObject(tmpFF);
        tmpFF->release();
        
 }
	return this;
}







void monsterLayer::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
//  UITouch *touch = [touches anyObject];
//  CGPoint point = [touch locationInView:[touch view]];
//  CGPoint convertedpoint = [[CCDirector sharedDirector] convertToGL: point];	
  
 
 //Add a new body/atlas sprite at the touched location
 CCSetIterator it;
 CCTouch* touch;
 CCPoint convertedpoint;
 for( it = touches->begin(); it != touches->end(); it++)
 {
  touch = (CCTouch*)(*it);
  
  if(!touch)
   break;
  
  CCPoint location = touch->getLocationInView();
  
  convertedpoint = CCDirector::sharedDirector()->convertToGL(location);
 }
 
 
  touchStartX = convertedpoint.x;
  touchStartY = convertedpoint.y;
  bTouchWasSlide = false;
	
}

void monsterLayer::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
//  UITouch *touch = [touches anyObject];
//  CGPoint point = [touch locationInView:[touch view]];
//  CGPoint convertedpoint = [[CCDirector sharedDirector] convertToGL: point];	
 
 CCSetIterator it;
 CCTouch* touch;
 CCPoint convertedpoint;
 for( it = touches->begin(); it != touches->end(); it++)
 {
  touch = (CCTouch*)(*it);
  
  if(!touch)
   break;
  
  CCPoint location = touch->getLocationInView();
  
  convertedpoint = CCDirector::sharedDirector()->convertToGL(location);
 }
 
  
  if( convertedpoint.x > touchStartX + 20 ||  convertedpoint.x < touchStartX - 20 || convertedpoint.y > touchStartY + 20 ||  convertedpoint.y < touchStartY - 20 )
  {
   bTouchWasSlide = true;
  }
  
  if( bTouchWasSlide == false ) 
  {
    CCDirector::sharedDirector()->popScene();
  }
}

void monsterLayer::ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
//	UITouch *touch = [touches anyObject];
//	CGPoint point = [touch locationInView:[touch view]];
//	CGPoint convertedpoint = [[CCDirector sharedDirector] convertToGL: point];

	
 
 
 CCSetIterator it;
 CCTouch* touch;
 CCPoint convertedpoint;
 for( it = touches->begin(); it != touches->end(); it++)
 {
  touch = (CCTouch*)(*it);
  
  if(!touch)
   break;
  
  CCPoint location = touch->getLocationInView();
  
  convertedpoint = CCDirector::sharedDirector()->convertToGL(location);
 }
 
	if( convertedpoint.x > touchStartX + 20 ||  convertedpoint.x < touchStartX - 20 || convertedpoint.y > touchStartY + 20 ||  convertedpoint.y < touchStartY - 20 ) 
 {
   bTouchWasSlide = true;
	}
	
	if( bTouchWasSlide ) 
 {
		
	}
}











