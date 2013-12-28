//
//  menuScene.cpp
//  Geosociety
//
//  Created by Deepak on 21/11/13.
//
//

#include "gearLayer.h"
#include <typeinfo>
#include <iostream>

gearLayer *gearLayer::initWithParent(menuLayer *par)
{
    parent = par;
        
		menuItems =  new CCArray();
        menuItems->retain();
		staticItems = new CCArray();
        staticItems->retain();
		monsterItems = new CCArray();
        monsterItems->retain();
		monsterPageItems = new CCArray();
        monsterPageItems->retain();
        monsterSearchResults =new CCArray();
        monsterSearchResults->retain();
        popItems = new CCArray();
        popItems->retain();
        team= new CCArray();
        team->retain();
        monsterSprites= new CCArray();
        monsterSprites->retain();
        
        monsters = parent->getMonsters();
        
        
        this->hideMenu();
        this->displayIndex();
        
		setTouchEnabled(true);
    
    return this;

}


gearLayer::~gearLayer()
{
    
}


gearLayer::gearLayer()
{
    
}

void gearLayer::sfx(CCString * effect)
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(effect->getCString());
}




void gearLayer::displayIndex()
{
    
    
    
    
    menuStage = 1;
    
    
	menuItems->removeAllObjects();
	monsterItems->removeAllObjects();
	monsterPageItems->removeAllObjects();
    

	CoolFreeform * tmpFF = new CoolFreeform();
	
   CoolSprite* tmpSpt= new CoolSprite();
    
    
    
    
    
	tmpSpt->initWithFile(CCString::create("bgMenu.png"));
	tmpSpt->updatePosition(ccp(284,160));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,8);
	menuItems->addObject(tmpSpt);
	tmpSpt->release();
	
    
	tmpSpt->initWithFile(CCString::create("radialShadow.png"));
	tmpSpt->updatePosition(ccp(240,160));
	tmpSpt->updateOpacity(150);
	tmpSpt->addToLayer(this,9);
	menuItems->addObject(tmpSpt);
	tmpSpt->release();
    
    
	tmpSpt->initWithFile(CCString::create("iconReturn.png"));
	tmpSpt->updatePosition(ccp(240,160));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,9);
	monsterItems->addObject(tmpSpt);
    tmpSpt->intTag1 = 72;
    tmpSpt->intTag2 = 1;
	tmpSpt->release();
    
	tmpSpt->initWithFile(CCString::create("iconMonsters.png"));
	tmpSpt->updatePosition(ccp(240,160));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,9);
	monsterItems->addObject(tmpSpt);
    tmpSpt->intTag1 = 72+72;
    tmpSpt->intTag2 = 2;
	tmpSpt->release();
    
    
    
    tmpSpt->initWithFile(CCString::create("iconItems.png"));
	tmpSpt->updatePosition(ccp(240,160));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,9);
	monsterItems->addObject(tmpSpt);
    tmpSpt->intTag1 = 72+72+72;
    tmpSpt->intTag2 = 3;
	tmpSpt->release();
    
    tmpSpt->initWithFile(CCString::create("iconMonDB.png"));
	tmpSpt->updatePosition(ccp(240,160));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,9);
	monsterItems->addObject(tmpSpt);
    tmpSpt->intTag1 = 72+72+72+72;
    tmpSpt->intTag2 = 4;
	tmpSpt->release();
    
    tmpSpt->initWithFile(CCString::create("iconSettings.png"));
	tmpSpt->updatePosition(ccp(240,160));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,9);
	monsterItems->addObject(tmpSpt);
    tmpSpt->intTag1 = 72+72+72+72+72;
    tmpSpt->intTag2 = 5;
	tmpSpt->release();
  
    
    if(parent->mapIsGeoRealm()) 
    {
        tmpFF->initWithCoolSheet(CCString::create("Return to Headquarters") ,FONT_WHITE ,0.3 ,310,true);
    } 
    else
    {
        tmpFF->initWithCoolSheet(CCString::create("Return to Headquarters") ,FONT_RED ,0.3 ,310,true);
    }
    tmpFF->bCenter = true;
	tmpFF->updatePosition(ccp(93,480-53+10));
	tmpFF->addToLayer(this,20);
	monsterItems->addObject(tmpFF);
    tmpFF->intTag1 = 72;
    tmpFF->intTag2 = 1;
	tmpFF->release();
    
	tmpFF->initWithCoolSheet(CCString::create("Manage Monsters") ,FONT_WHITE ,0.3,310,true);
    tmpFF->bCenter = true;
	tmpFF->updatePosition(ccp(93,480-53-78+10));
	tmpFF->addToLayer(this,20);
	monsterItems->addObject(tmpFF);
    tmpFF->intTag1 = 72+72;
    tmpFF->intTag2 = 2;
	tmpFF->release();
    
	tmpFF->initWithCoolSheet(CCString::create("Manage Inventory"),FONT_WHITE,0.3,310,true);
    tmpFF->bCenter = true;
	tmpFF->updatePosition(ccp(93,480-53-78-78+10));
	tmpFF->addToLayer(this ,20);
	monsterItems->addObject(tmpFF);
    tmpFF->intTag1 = 72+72+72;
    tmpFF->intTag2 = 3;
	tmpFF->release();

    
    
    
    tmpFF ->initWithCoolSheet(CCString::create("Monster Database"),FONT_WHITE,0.3,310,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(93,480-53-78-78+10));
	tmpFF->addToLayer(this ,20);
	monsterItems->addObject(tmpFF);
    tmpFF->intTag1 = 72+72+72+72;
    tmpFF->intTag2 = 4;
	tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("Save Progress"),FONT_WHITE,0.3,310,true);
    tmpFF->bCenter = true;
	tmpFF->updatePosition(ccp(93,480-53-78-78+10));
	tmpFF->addToLayer(this ,20);
	monsterItems->addObject(tmpFF);
    tmpFF->intTag1 = 72+72+72+72+72;
    tmpFF->intTag2 = 5;
	tmpFF->release();
    
    
    //coin
    roationAngle = 72/2;
    
    
    tmpFF->initWithCoolSheet(CCString::createWithFormat("Coin: %d",parent->coin),FONT_WHITE,0.3,310,true);
    tmpFF->bCenter = true;
	tmpFF->updatePosition(ccp(60,35));
	tmpFF->addToLayer(this ,20);
	menuItems->addObject(tmpFF);
	tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::createWithFormat("Swipe to Rotate the Menu."),FONT_WHITE,0.3,310,true);
    tmpFF->bCenter = true;
	tmpFF->updatePosition(ccp(250,35));
	tmpFF->addToLayer(this ,20);
	menuItems->addObject(tmpFF);
	tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::createWithFormat("Control Mode:"),FONT_WHITE,0.25,310,true);
    tmpFF->bCenter = true;
	tmpFF->updatePosition(ccp(25,85));
	tmpFF->addToLayer(this ,20);
	menuItems->addObject(tmpFF);
	tmpFF->release();
    
    
    
        
    CCString * controlStr = NULL;
    if( parent->controlMode == control_mode_dynamic ) 
        controlStr = CCString::createWithFormat("Dynamic Layout");
    if( parent->controlMode == control_mode_fixed ) 
        controlStr= CCString::createWithFormat("Fixed Layout");
    if( parent->controlMode == control_mode_large ) 
        controlStr =CCString::createWithFormat("Full Screen");
    
    
    tmpFF->initWithCoolSheet(controlStr,FONT_WHITE,0.25,310,true);
    tmpFF->bCenter = false;
    tmpFF->updatePosition(ccp(25,65));
	tmpFF->addToLayer(this ,20);
	menuItems->addObject(tmpFF);
	tmpFF->release();
    
    this->updateRotation();
}





void gearLayer::updateRotation()
{
    //Current Rotation = roationAngle
    int distance = 140;
    int x,y = 0;
    int centerScreen = 72;
    
    for (int i=0; i<monsterItems->count(); i++)
    {
        CoolSprite*tmpSpt= (CoolSprite*)monsterItems->objectAtIndex(i);
        
        if (typeid(tmpSpt) == typeid(CoolFreeform))
        {
            CoolFreeform*tmpSpt= (CoolFreeform*)tmpSpt;
            double itemRotationAngle = roationAngle + tmpSpt->intTag1;
            
            double rads = itemRotationAngle * PI / 180;
            x = sin(rads) * distance;
            y = cos(rads) * distance;
            
            tmpSpt->updatePosition(ccp(240+x,320+y-40));
        }
        else
        {
            double itemRotationAngle = roationAngle + tmpSpt->intTag1;
            
            double rads = itemRotationAngle * PI / 180;
            x = sin(rads) * distance;
            y = cos(rads) * distance;
            
            //anishtmpSpt->updatePosition(ccp(240+x,320+y-40));
            
        }
    
       
        
    }
   
//    for(int i=0; i<monsterItems->count();i++)
//    {
//        CoolFreeform * tmpFF = (CoolFreeform*) monsterItems->objectAtIndex(i);
//        if (typeid(*tmpFF) == typeid(CoolFreeform))
//        {
//            double itemRotationAngle = roationAngle + tmpFF->intTag1;
//            double rads = itemRotationAngle * PI / 180;
//            x = sin(rads) * distance;
//            y = cos(rads) * distance;
//            
//            tmpFF->updatePosition(ccp(240+x,285+y-40));
//        }
//    }
}






void gearLayer:: indexTouch(CCPoint touch) {
    
    int count = 0;
    for (int i =0 ; i<monsterItems->count(); i++)
    {
        CoolSprite* tmpSpt= (CoolSprite*)monsterItems->objectAtIndex(i);
        
        CCPoint button =ccp(tmpSpt->x,tmpSpt->y);
                
        if( touch.x > button.x -32 && touch.x < button.x + 32 ) 
        {
            if( touch.y > button.y -16 && touch.y < button.y + 16 ) 
            {
                
                if( tmpSpt->intTag2 == 1 ) 
                { //Return to HQ
                    
                    if( parent->mapIsGeoRealm())
                    {
                        
                        CCString * tmpStr =CCString::createWithFormat("Ask Question - Two Answers\tWould you like abort the mission temporarily?^Yes^No"); 
                        parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))));
                        tmpStr =CCString::createWithFormat("IF\tGlobal Variable^SYSYesNoAnswer^T"); 
                        parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))));
                        
                        tmpStr =CCString::createWithFormat("Relocate User\tGeoSocietyHalls.tmx^27^18"); 
                       parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))));
                        
                        
                        parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(CCString::create( "Change Weather\tNormal" ),CCString::create("\t"))));
                       parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(CCString::create("Set Zone\t"), CCString::create("\t"))));
                        parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(CCString::create("Full Restore\t"), CCString::create("\t"))));
                                                                                                                           
                                                                                                                           
                     parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(CCString::create("Change Music\tNewGameLoop^"), CCString::create("\t"))));
                        
                        tmpStr = CCString::createWithFormat("ELSE\t"); 
                        parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr ,CCString::create("\t"))));
                        tmpStr =CCString::createWithFormat("END IF\t"); 
                        parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                        
                    } 
                    else
                    {
                        
                        CCString * tmpStr =CCString::createWithFormat("Display Message\tYou are presently not in the GeoRealm.^"); 
                        parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                    }
                    
                    bIsActive = false;
                    this->hideMenu();
                    this->sfx(CCString::create(SOUND_CONFIRM));
                    parent->scriptProgress();
                    
                } 
                else if( tmpSpt->intTag2 == 2 ) 
                {  //Monsters
                    
                    this->sfx(CCString::create(SOUND_CONFIRM));
                    this->drawMonsterCategories(0);
                    
                } 
                else if( tmpSpt->intTag2 == 3 )
                {  //Items
                    
                    this->sfx(CCString::create(SOUND_CONFIRM));
                    this->displayItemSelectPage();
                    
                } 
                else if( tmpSpt->intTag2 == 4 ) 
                {  //Monster Database
                    
                   this->sfx(CCString::create(SOUND_CONFIRM));
                    this->displayMonsterLoreHome();
                    
                } else if( tmpSpt->intTag2 == 5 )
                {  //Save Game
                    /*
                     if( [parent mapIsGeoRealm] ) {
                     
                     NSString * tmpStr = [NSString stringWithFormat:@"Display Message\tYou cannot save while on a Mission.^"]; 
                     [parent addScript:[tmpStr componentsSeparatedByString:@"\t"]];
                     
                     } else {
                     */
                    CCString * tmpStr = CCString::createWithFormat("Ask Question - Two Answers\tWould you like to Save your Progress?^Yes^No"); 
                    parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                    tmpStr =CCString::createWithFormat("IF\tGlobal Variable^SYSYesNoAnswer^T"); 
                    parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                    
                    tmpStr = CCString::createWithFormat("Save Game\t^"); 
                    parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                    
                    tmpStr =CCString::createWithFormat("Display Message\tYour Progress has been Saved.^"); 
                     parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                    
                    tmpStr =CCString::createWithFormat("ELSE\t"); 
                    parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                    tmpStr = CCString::createWithFormat("END IF\t"); 
                        parent->addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                    
                    // }
                    
                    this->hideMenu();
                    this->sfx(CCString::create(SOUND_CONFIRM));
                   parent->scriptProgress();
                    
                }
                
                return;
            }
        }
        
        count++;
    }
    
    
    
    
    
    if( touch.y < 80 && touch.x > 320 ) 
    {
        this->sfx(CCString::create(SOUND_CONFIRM));
        this->hideMenu();
        return;
    } 
    
    
    if( touch.x < 120 && touch.y < 90 ) 
    {
       this->sfx(CCString::create(SOUND_CONFIRM));
        
        int newControls = parent->controlMode;
        if( parent->controlMode == control_mode_dynamic )
            newControls = control_mode_fixed;
            else if( parent->controlMode == control_mode_fixed )
                newControls = control_mode_large;
                else if( parent->controlMode == control_mode_large )
                    newControls = control_mode_dynamic;
                    
                    parent->setControls( newControls);
        
        
        
        this->displayIndex();
        return;
    } 
}





#pragma mark -
#pragma mark === MONSTER CATEGORY FUNCTIONS ===
#pragma mark -

void gearLayer::drawMonsterCategories(int menuType)
{
	menuStage = 5;
	menuItems->removeAllObjects();
	monsterItems->removeAllObjects();
	monsterPageItems->removeAllObjects();
	
	curMenuType = menuType;
	
	CoolSprite * tmpSpt = NULL;
	CoolFreeform * tmpFF = NULL;
	
	tmpSpt->initWithFile(CCString::create("bg1.png"));
	tmpSpt->updatePosition(ccp(284,160));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,9);
	menuItems->addObject(tmpSpt);
	tmpSpt->release();
	
	tmpSpt->initWithFile(CCString::create("bg7.png"));
	tmpSpt->updatePosition(ccp(284,160));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,10);
	menuItems->addObject(tmpSpt);
	tmpSpt->release();
	
	monsterSearchResults->removeAllObjects();
	
    
    tmpFF->initWithCoolSheet(CCString::create("Change Filter"),FONT_WHITE,0.30,310,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(480-70,320-10));
    tmpFF->addToLayer(this,20);
    monsterItems->addObject(tmpFF);
    tmpFF->release();
	
	monsters = parent->getMonsters();
    
	//curPage = 0;
	if( curMenuType == 0 ) 
    {
       
       tmpFF->initWithCoolSheet(CCString::create("Your Team"),FONT_WHITE,0.4,310,true);
       tmpFF->bCenter = true;
       tmpFF->updatePosition(ccp(235,320-10));
       tmpFF->addToLayer(this,20);
       monsterItems->addObject(tmpFF);
       tmpFF->release();
       
       for(int i=1;i<10;i++)
             {
                 for (int j=0; j<monsters->count(); i++)
                 {
                       monster * mon =(monster*)monsters->objectAtIndex(j); 
                      if( mon->position == i ) 
                      {
                       monsterSearchResults->addObject(mon);}
                 }
             }
       
       int pageCount = monsterSearchResults->count()/6;
       if( (float)(monsterSearchResults->count())/(float)6 != (float)pageCount ) 
       {
         pageCount++;
       }
       if( curPage >= pageCount) 
       {
         curPage = 0;
       }
       this->drawPageFromSearchArray();
    } 
    else if( curMenuType == 1 )
    {
		
       tmpFF->initWithCoolSheet(CCString::create("All Monsters"),FONT_WHITE,0.4,310,true);
       tmpFF->bCenter = true;
       tmpFF->updatePosition(ccp(235,320-10));
       tmpFF->addToLayer(this,20);
       monsterItems->addObject(tmpFF);
       tmpFF->release();
       
     
     for (int i=0; i<monsters->count(); i++)
     {
      monster * mon= (monster*)monsters->objectAtIndex(i);
      monsterSearchResults->addObject(mon);
     }

       
       
       
       int pageCount = monsterSearchResults->count()/ 6;
       if( (float)(monsterSearchResults->count()) / (float)6 != (float)pageCount ) 
             {
        pageCount++;
       }
       if( curPage >= pageCount) {
        curPage = 0;
       }
       
       this->drawPageFromSearchArray();
    } 
    else if( curMenuType == 2 ) 
    {
		
		tmpFF ->initWithCoolSheet(CCString::create("Male Monsters"),FONT_WHITE,0.4,310,true);
		tmpFF->bCenter = true;
		tmpFF->updatePosition(ccp(235,320-10));
		tmpFF->addToLayer(this,20);
		monsterItems->addObject(tmpFF);
		tmpFF->release();
		
		   for (int i=0; i<monsters->count(); i++)
     {
       monster * mon= (monster*)monsters->objectAtIndex(i);
       if( mon->bIsMale )
       {
         monsterSearchResults->addObject(mon);
       }
     }
     
		int pageCount = monsterSearchResults->count() / 6;
		if( (float)(monsterSearchResults->count()) / (float)6 != (float)pageCount ) 
        {
			pageCount++;
		}
		if( curPage >= pageCount) {
			curPage = 0;
		}
		
		this->drawPageFromSearchArray();
        
        
        
	} 
    else if( curMenuType == 3 ) 
    {
		
		tmpFF->initWithCoolSheet(CCString::create("Female Monsters"),FONT_WHITE,0.4,310,true);
		tmpFF->bCenter = true;
		tmpFF->updatePosition(ccp(235,320-10));
		tmpFF->addToLayer(this,20);
		monsterItems->addObject(tmpFF);
		tmpFF->release();
	
     for (int i=0; i<monsters->count(); i++)
     {
       monster * mon= (monster*)monsters->objectAtIndex(i);
       if( mon->bIsMale==false )
       {
        monsterSearchResults->addObject(mon);
       }
      
     }
     
		
		int pageCount = monsterSearchResults->count() / 6;
		if( (float)(monsterSearchResults->count())/ (float)6 != (float)pageCount )
        {
			pageCount++;
		}
		if( curPage >= pageCount) 
        {
			curPage = 0;
		}
		
		this->drawPageFromSearchArray();
	}
}




void gearLayer::drawPageFromSearchArray()
{
	//curPage
	monsterPageItems->removeAllObjects();
	
	
	int pageCount =monsterSearchResults->count() / 6;
	if( (float)(monsterSearchResults->count() )/ (float)6 != (float)pageCount ) 
    {
		pageCount++;
	}
	
	
	CoolFreeform * tmpFF = new CoolFreeform();
    tmpFF->initWithCoolSheet(CCString::createWithFormat("Page %d of %d",curPage+1,pageCount),FONT_WHITE,0.25,310,true);
	tmpFF->bCenter = true;
	tmpFF->updatePosition(ccp(240,30));
	tmpFF->addToLayer(this,20);
	monsterPageItems->addObject(tmpFF);
	tmpFF->release();
	
	
	int startPoint = curPage * 6;
	
	for(int i=startPoint;i<startPoint+6;i++)
 {
   if( i < monsterSearchResults->count() )
   {
     monster * mon = (monster*)monsterSearchResults->objectAtIndex(i);
     this->drawMonster(mon,i-startPoint+1);
   }
 }
}




void gearLayer::drawMonster(monster * mon, int i)
{
     CCPoint pos;
     CoolLabel * tmpLbl = NULL;
     
     if( i == 1 || i == 2 || i == 3 ) 
     {
       pos.y = 320-80;
     }
     else
     {
       pos.y = 120;
     }
     if( i == 1 || i == 4 )
     {
       pos.x = 130;
     } 
     else if( i == 2 || i == 5 ) 
     {
       pos.x = 240;
     }
     else 
     {
       pos.x = 350;
     }
     
  CoolSprite * tmpSpt = new CoolSprite();
  tmpSpt->initWithFile(mon->getImage());
     tmpSpt->updatePosition(pos);
     tmpSpt->updateOpacity(255);
     tmpSpt->updateScale(0.75);
     tmpSpt->addToLayer(this ,15);
     monsterPageItems->addObject(tmpSpt);
     tmpSpt->release();
     
     if( mon->bIsMale ) 
     {
      
       tmpSpt->initWithFile(CCString::create("highlightM.png"));
     } 
     else 
     {
       tmpSpt->initWithFile(CCString::create("highlightF.png"));
     }
     
     tmpSpt->updatePosition(pos);
     tmpSpt->updateOpacity(150);
     tmpSpt->updateScale(0.75);
     tmpSpt->addToLayer(this,14);
     monsterPageItems->addObject(tmpSpt);
     tmpSpt->release();
     
     
  CoolFreeform * tmpFF =new CoolFreeform();
    tmpFF->initWithCoolSheet(mon->getName(),FONT_WHITE,0.3,310,true);
     tmpFF->bCenter = true;
     tmpFF->updatePosition(ccp(pos.x,pos.y-43+10));
     tmpFF->addToLayer(this,20);
     monsterPageItems->addObject(tmpFF);
     tmpFF->release();
     
     if( mon->position != 0 ) 
     {
       tmpFF->initWithCoolSheet(CCString::createWithFormat("%d.", mon->position),FONT_WHITE,0.3,310,true);
     } 
     else 
     {
       tmpFF->initWithCoolSheet(CCString::createWithFormat("B."),FONT_WHITE,0.3,310,true);
     }
     tmpFF->bCenter = true;
     tmpFF->updatePosition(ccp(pos.x-45,pos.y-25+10));
     tmpFF->addToLayer(this,20);
     monsterPageItems->addObject(tmpFF);
     tmpFF->release();
     
     
     if( mon->stat_points > 0 ) 
     {
       CoolSprite * tmpSpt = new CoolSprite();
       tmpSpt->initWithFile(CCString::create("highlightNotification.png"));
      tmpSpt->updatePosition(pos);
      tmpSpt->updateOpacity(200);
      tmpSpt->updateScale(0.75);
      tmpSpt->addToLayer(this,20);
      monsterPageItems->addObject(tmpSpt);
      tmpSpt->release();
      
       tmpLbl->initWithCoolString(CCString::createWithFormat("%d",mon->stat_points),"Arial",14);
      tmpLbl->updatePosition(ccp(pos.x+20,pos.y-25));
      tmpLbl->updateOpacity(255);
      tmpLbl->addToLayer(this ,25);
      monsterPageItems->addObject(tmpLbl);
      tmpLbl->release();
      
     }
     
     /*
         if( mon.bIsMale ) {
         tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"M"  fontName:FONT_WHITE fontSize:0.3 andMaxWidth:310 instant:true];
         } else {
         tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"F"  fontName:FONT_WHITE fontSize:0.3 andMaxWidth:310 instant:true];
         }
         tmpFF.bCenter = true;
         [tmpFF updatePosition:ccp(pos.x+45,pos.y-25+10)];
         [tmpFF addToLayer:self z:20];
         [monsterPageItems addObject:tmpFF];
         [tmpFF release];
         */
     
     
  tmpFF->initWithCoolSheet(CCString::createWithFormat("Level %d",mon->lvl),FONT_WHITE,0.2,310,true);
     tmpFF->bCenter = true;
     tmpFF->updatePosition(ccp(pos.x,pos.y-56+8));
     tmpFF->addToLayer(this,20);
     monsterPageItems->addObject(tmpFF);
     tmpFF->release();
     
     
  tmpFF->initWithCoolSheet(CCString::createWithFormat("+%d",mon->reborn),FONT_WHITE,0.4,310,true);
     tmpFF->bCenter = true;
     tmpFF->updateOpacity(100);
     tmpFF->updatePosition(ccp(pos.x,pos.y+15));
     tmpFF->addToLayer(this,20);
     monsterPageItems->addObject(tmpFF);
     tmpFF->release();
     
     
  tmpFF->initWithCoolSheet(CCString::createWithFormat("Types %s, %s", (parent->getDatabase()->getTypeFromId(mon->getMonster()->type1Id))->getCString(),(parent->getDatabase()->getTypeFromId(mon->getMonster()->type1Id))->getCString()),FONT_WHITE,0.2,310,true);
     tmpFF->bCenter = true;
     tmpFF->updatePosition(ccp(pos.x,pos.y-66+8));
     tmpFF->addToLayer(this,20);
     monsterPageItems->addObject(tmpFF);
     tmpFF->release();
}




void gearLayer::hideMenu()
{
    
    bIsOnPC = false;
    bIsActive = false;
    this->setPosition(ccp(-2000,0));
}

void gearLayer::monsterCategoryTouch(CCPoint touch)
{
    
    //Change Filter Type
	if( touch.y > 320-32  ) 
    {
		if( touch.x > 480-128 ) 
        {
			curMenuType++;
			if( curMenuType > 3 )
            {
				curMenuType = 0;
			}
			this->sfx(CCString::create(SOUND_CONFIRM));
			this->drawMonsterCategories(curMenuType);
		}
	}
	
    //Bottom Bar
	if( touch.y > 0 && touch.y < 35 )
    {
        
        //Menu Button Pressed
		if( touch.x < 88 ) 
        {
			monsterItems->removeAllObjects();
			monsterPageItems->removeAllObjects();
			this->sfx(CCString::create(SOUND_CONFIRM));
            
            if( bIsOnPC ) 
            {
                this->hideMenu();
            } 
            else 
            {
                this->displayIndex();
            }
		}
		
		int pageCount =monsterSearchResults->count() / 6;
		if( (float)(monsterSearchResults->count()) / (float)6 != (float)pageCount ) 
        {
			pageCount++;
		}
		
        
        
		if( touch.x > 480-88 ) 
        {
			if( curPage + 1 < pageCount) 
            {
                //Next Button Pressed
				curPage++;
				this->sfx(CCString::create(SOUND_CONFIRM));
				this->drawPageFromSearchArray();
			}
		} 
        else if( touch.x > 480-88-88 && touch.x < 480-88 ) 
        {
			if( curPage - 1 >= 0 )
            {
                //Previous Button Pressed
				curPage--;
				this->sfx(CCString::create(SOUND_CONFIRM));
				this->drawPageFromSearchArray();
			}
		}  
		
	}
	
	//monster click - displayMonster
    monster * touchMon = NULL;
	int selectPos = 0;
	if( touch.x > 130 - 40 && touch.x < 130 + 40 ) 
    {
		if( touch.y > 240 - 40 && touch.y < 240 + 40 )
        {
			selectPos = 1;
			
		} 
        else if( touch.y > 120 - 40 && touch.y < 120 + 40 )
        {
			selectPos = 4;
			
		}
	} 
    else if( touch.x > 240 - 40 && touch.x < 240 + 40 )
    {
		if( touch.y > 240 - 40 && touch.y < 240 + 40 ) 
        {
			selectPos = 2;
			
		} 
        else if( touch.y > 120 - 40 && touch.y < 120 + 40 ) 
        {
			selectPos = 5;
			
		}
	} 
    else if( touch.x > 350 - 40 && touch.x < 350 + 40 )
    {
		if( touch.y > 240 - 40 && touch.y < 240 + 40 ) 
        {
			selectPos = 3;
			
		} else if( touch.y > 120 - 40 && touch.y < 120 + 40 ) 
        {
			selectPos = 6;
			
		}
	}
	if( selectPos > 0 )
    {
		if( curPage * 6 + selectPos-1 >= 0 && curPage * 6 + selectPos-1 < monsterSearchResults->count() ) 
        {
			touchMon = (monster*)monsterSearchResults->objectAtIndex(curPage * 6 + selectPos-1);
		}
	}
	if( touchMon != NULL )
    {
		this->sfx(CCString::create(SOUND_CONFIRM));
		this->displayMonster(touchMon);
	}
	
}


#pragma mark -
#pragma mark === MONSTER FUNCTIONS ===
#pragma mark -



 void gearLayer::displayMonster(monster * mon)
{
 
     if( selMonster != NULL )
     {
         selMonster->release();
         selMonster = NULL;
     }
       //PENDING_DEEPAK selMonster = mon->retain();
     
     
     menuStage = 30;
     menuItems->removeAllObjects();
     monsterItems->removeAllObjects();
     monsterPageItems->removeAllObjects();
     
     CoolSprite * tmpSpt = NULL;
     CoolLabel * tmpLbl = NULL;
    tmpSpt= new CoolSprite();
     tmpSpt->initWithFile(CCString::create("bgMenu.png"));
     tmpSpt->updatePosition(ccp(284,160));
     tmpSpt->updateOpacity(255);
     tmpSpt->addToLayer(this,8);
     menuItems->addObject(tmpSpt);
     tmpSpt->release();
     
     tmpSpt->initWithFile(CCString::create("monstersinglebg.png"));
     tmpSpt->updatePosition(ccp(284,160));
     tmpSpt->updateOpacity(255);
     tmpSpt->addToLayer(this,9);
     menuItems->addObject(tmpSpt);
     tmpSpt->release();
     
     CoolFreeform * tmpFF = new CoolFreeform();
     /*
     tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Tap for Monster Information" fontName:FONT_WHITE fontSize:0.3 andMaxWidth:310 instant:true];
     tmpFF.bCenter = true;
     [tmpFF updatePosition:ccp(160+5,320-15)];
     [tmpFF addToLayer:self z:20];
     [menuItems addObject:tmpFF];
     [tmpFF release];
     */

    tmpFF->initWithCoolSheet(CCString::createWithFormat("Name: %s",mon->getName()->getCString()),FONT_WHITE,0.35,310,true);
    tmpFF->updatePosition(ccp(108,320-15));
    tmpFF->intTag1 = 480-25;
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();

    tmpFF->initWithCoolSheet(CCString::createWithFormat("Type1: %s, Type2: %s",(parent->getDatabase()->getTypeFromId(mon->getMonster()->type1Id))->getCString() ,(parent->getDatabase() ->getTypeFromId(mon->getMonster()->type2Id))->getCString()),FONT_WHITE,0.25,310,true);
    tmpFF->updatePosition(ccp(108,320-20-20));
    tmpFF->intTag1 = 480-25;
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();

    tmpFF->initWithCoolSheet(CCString::createWithFormat("Level %d. Reborn +%d",mon->lvl,mon->reborn),FONT_WHITE,0.25,310,true);
    tmpFF->updatePosition(ccp(108,320-20-20-15));
    tmpFF->intTag1 = 480-25;
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();

    tmpFF->initWithCoolSheet(CCString::createWithFormat("Base Health Points: %d",mon->hp),FONT_WHITE,0.25,310,true);
    tmpFF->updatePosition(ccp(108,320-20-20-15-15));
    tmpFF->intTag1 = 480-25;
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();


    tmpSpt->initWithFile(mon->getImage());
    tmpSpt->updatePosition(ccp(9+40,320-(9+40)));
    tmpSpt->intTag1 = 480-(9+40);
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,10);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();

 
   //MAKING LOSTRING AS LOWER CASE
   std::string lowercaseString= (parent->getDatabase()->getTypeFromId(mon->getMonster()->type1Id))->getCString();
   std::transform(lowercaseString.begin(), lowercaseString.end(), lowercaseString.begin(), ::tolower);
   
   tmpSpt->initWithFile(CCString::createWithFormat("element-%s.png", CCString::create(lowercaseString)->getCString()));
   tmpSpt->updatePosition(ccp(53+16,320-98-16));
   tmpSpt->intTag1 = 480-98-16;
   tmpSpt->updateOpacity(255);
   tmpSpt->addToLayer(this,10);
   menuItems->addObject(tmpSpt);
   tmpSpt->release();

 
   lowercaseString= (parent->getDatabase()->getTypeFromId(mon->getMonster()->type2Id))->getCString();
   std::transform(lowercaseString.begin(), lowercaseString.end(), lowercaseString.begin(), ::tolower);
 
   tmpSpt->initWithFile(CCString::createWithFormat("element-%s.png",CCString::create(lowercaseString)->getCString()));
    tmpSpt->updatePosition(ccp(14+16,320-98-16));
    tmpSpt->intTag1 = 480-98-16;
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,10);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();


    tmpFF->initWithCoolSheet(CCString::createWithFormat("ATK: %d",mon->atk),FONT_WHITE,0.25,310,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(151,320-101-7));
    tmpFF->intTag1 = 480-106;
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();


    tmpFF->initWithCoolSheet(CCString::createWithFormat("DEF: %d",mon->def),FONT_WHITE,0.25,310,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(260,320-101-7));
    tmpFF->intTag1 = 480-106;
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();


    tmpFF->initWithCoolSheet(CCString::createWithFormat("SPD: %d",mon->spd),FONT_WHITE,0.25,310,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(151,320-140-7));
    tmpFF->intTag1 = 480-145;
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();


    tmpFF->initWithCoolSheet(CCString::createWithFormat("INT: %d",mon->atk),FONT_WHITE,0.25,310,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(260,320-140-7));
    tmpFF->intTag1 = 480-145;
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();



    tmpSpt->initWithFile(CCString::create("monstersinglebg.png"));
    tmpSpt->updatePosition(ccp(284,160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,9);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();



    if( mon->stat_points > 0 )
    {
       tmpFF->initWithCoolSheet(CCString::create("Stat Points"),FONT_GREEN,0.3,310,true);
    } 
    else 
    {
       tmpFF->initWithCoolSheet(CCString::create("Stat Points"),FONT_WHITE,0.3,310,true);
    }
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(395,320-36));
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();

   tmpFF->initWithCoolSheet(CCString::create("Re-Position"),FONT_WHITE,0.3,310,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(395,320-104));
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();

    /*
     tmpLbl = [[CoolLabel alloc] initWithCoolString:@"Stat Points" fontName:@"Arial" fontSize:16];
     [tmpLbl updatePosition:ccp(160,320-263)];
     [tmpLbl updateOpacity:255];
     [tmpLbl addToLayer:self z:15];
     [menuItems addObject:tmpLbl];
     [tmpLbl release];
     
     tmpLbl = [[CoolLabel alloc] initWithCoolString:@"Re-Position Monster" fontName:@"Arial" fontSize:16];
     [tmpLbl updatePosition:ccp(160,320-323)];
     [tmpLbl updateOpacity:255];
     [tmpLbl addToLayer:self z:15];
     [menuItems addObject:tmpLbl];
     [tmpLbl release];
     */


   tmpFF->initWithCoolSheet(CCString::createWithFormat("HP: %d of %d",mon->hpLeft,mon->hp),FONT_WHITE,0.45,310,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(160,320-323-50));
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();

    int nextLvl = mon->lvl+1;
    int expAtNextLevel = nextLvl * nextLvl * nextLvl;
    int expTillNext = expAtNextLevel - mon->exp;
    if( expTillNext < 1 ) 
    {
        expTillNext = 1;
    }

   tmpFF->initWithCoolSheet(CCString::createWithFormat("%d EXP to next Level",expTillNext),FONT_WHITE,0.25,310,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(160,320-323-80));
    tmpFF->addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF->release();



    //used for skills
    atk1=0;
    atk2=0;
    atk3=0;
    atk4=0;

    //Allocation Notification
    /*
     
     //Notifications
     //notifications.png
     if( mon.stat_points > 0 ) {
     
     tmpSpt = [[CoolSprite alloc] initWithFile:@"notifications.png"];
     [tmpSpt updatePosition:ccp(255,320-247)];
     [tmpSpt addToLayer:self z:19];
     [menuItems addObject:tmpSpt];
     [tmpSpt release];
     
     tmpLbl = [[CoolLabel alloc] initWithCoolString:[NSString stringWithFormat:@"%d",mon.stat_points] fontName:@"Arial" fontSize:12];
     [tmpLbl updatePosition:ccp(280,320-271)];
     [tmpLbl addToLayer:self z:20];
     [menuItems addObject:tmpLbl];
     [tmpLbl release];
     
     }
     
     */

}





void gearLayer::displayMonsterLoreMonster(int monid)
{
    /* PENDING_DEEPAK
     monsterScene * monScene = new monsterScene();
   
      monScene->initWithMonsterData(parent->getDatabase(), monid);
     CCDirector::sharedDirector()->pushScene(monScene);
     monScene->release();
     */
}








void gearLayer::monsterTouch(CCPoint touch)
{
	
    //Monster Lore Page
	if( touch.x < 312 & touch.y > 142 ) 
    {
		this->displayMonsterLoreMonster(selMonster->getMonster()->monid );
		return;
	}
	
    //Back Button
	if( touch.y > 0 && touch.y < 35 ) 
    {
		if( touch.x > 320-88 ) {
			this->sfx(CCString::create(SOUND_CONFIRM));
			this->drawMonsterCategories(curMenuType);
		}
	}
	
    //Menu Button - No Image for this.
	if( touch.y > 0 && touch.y < 35 ) 
    {
		if( touch.x < 88 ) 
        {
           this->sfx(CCString::create(SOUND_CONFIRM));
			this->displayIndex();
		}
	}
	
	if( touch.x > 312)
    {
        //Stat Points
        if( touch.y > 320-36-12 - 25 && touch.y < 320-36-12 + 15 )
        {
           this->sfx(CCString::create(SOUND_CONFIRM));
            this->displayMonster(selMonster);
        }
        //Positions
        if( touch.y > 320-104-12 - 25 && touch.y < 320-104-12 + 15 ) 
        {
           this->sfx(CCString::create(SOUND_CONFIRM));
           this->displayMonsterPosition( selMonster);
        }
    }
    
}


#pragma mark -
#pragma mark === MONSTER POSITION FUNCTIONS ===
#pragma mark -
void gearLayer::displayMonsterPosition(monster * mon)
{
	
    if( bIsOnPC == false ) 
    {
        if( selMonster->position == 0 )
        {
            this-> popMenu(CCString::create("Since you are not using the GeoSociety Intranet you can not Withdraw Monsters from the GeoSociety Monster Bank."));
            this-> displayMonster(selMonster);
            return;
        }
    }
    
    
	menuStage = 32;
	menuItems-> removeAllObjects();
	monsterItems-> removeAllObjects();
	monsterPageItems-> removeAllObjects();
	
	CoolSprite* tmpSpt = new CoolSprite();
	CoolLabel* tmpLbl = new CoolLabel();
	
	tmpSpt ->initWithFile(CCString::create("bgMenu.png"));
	tmpSpt-> updatePosition(ccp(284,160));
	tmpSpt-> updateOpacity(255);
	tmpSpt-> addToLayer(this,7);
	menuItems-> addObject(tmpSpt);
	tmpSpt-> release();
	
	tmpSpt-> initWithFile(CCString::create("bg10.png"));
	tmpSpt-> updatePosition(ccp(240,160));
	tmpSpt-> updateOpacity(255);
	tmpSpt-> addToLayer(this,8);
	menuItems-> addObject(tmpSpt);
	tmpSpt-> release();
	
}


void gearLayer::monsterPositionTouch(CCPoint touch)
{
	if( touch.y > 0 && touch.y < 35 ) 
    {
		if( touch.x > 480-88 ) 
        {
			this-> sfx(CCString::create(SOUND_CONFIRM));
			this-> displayMonster(selMonster);
		}
	}
	
    /*
     if( touch.y > 0 && touch.y < 35 ) {
     if( touch.x < 88 ) {
     [self sfx:SOUND_CONFIRM];
     [self displayIndex];
     }
     }
     */
    
	int newPosition = 0;
	bool bHit = false;
	
	int xPos = 71+80;
	int yPos = 320-60;
	if( touch.y > yPos-15 && touch.y < yPos+15 )
    {
		if( touch.x > xPos-25 && touch.x < xPos+25  ) 
        {
			bHit = true;
			newPosition = 1;
		}
	}
	
	xPos = 162+80;
	if( touch.y > yPos-15 && touch.y < yPos+15 ) 
    {
		if( touch.x > xPos-25 && touch.x < xPos+25  )
        {
			bHit = true;
			newPosition = 2;
		}
	}
	
	xPos = 253+80;
	if( touch.y > yPos-15 && touch.y < yPos+15 )
    {
		if( touch.x > xPos-25 && touch.x < xPos+25  )
        {
			bHit = true;
			newPosition = 3;
		}
	}
	
	xPos = 71+80;
	yPos = 320-106;
	if( touch.y > yPos-15 && touch.y < yPos+15 )
    {
		if( touch.x > xPos-25 && touch.x < xPos+25  )
        {
			bHit = true;
			newPosition = 4;
		}
	}
	
	xPos = 162+80;
	if( touch.y > yPos-15 && touch.y < yPos+15 )
    {
		if( touch.x > xPos-25 && touch.x < xPos+25  )
        {
			bHit = true;
			newPosition = 5;
		}
	}
	
	xPos = 253+80;
	if( touch.y > yPos-15 && touch.y < yPos+15 )
    {
		if( touch.x > xPos-25 && touch.x < xPos+25  ) 
        {
			bHit = true;
			newPosition = 6;
		}
	}
	
    
	xPos = 71+80;
	yPos = 320-150;
	if( touch.y > yPos-15 && touch.y < yPos+15 ) 
    {
		if( touch.x > xPos-25 && touch.x < xPos+25  ) 
        {
			bHit = true;
			newPosition = 7;
		}
	}
	
	xPos = 162+80;
	if( touch.y > yPos-15 && touch.y < yPos+15 ) 
    {
		if( touch.x > xPos-25 && touch.x < xPos+25  ) 
        {
			bHit = true;
			newPosition = 8;
		}
	}
	
	xPos = 253+80;
	if( touch.y > yPos-15 && touch.y < yPos+15 ) 
    {
		if( touch.x > xPos-25 && touch.x < xPos+25  ) 
        {
			bHit = true;
			newPosition = 9;
		}
	}
	
	
	yPos = 90;
	if( touch.y > yPos-15 && touch.y < yPos+15 ) 
    {
		bHit = true;
		newPosition = 0;
	}
	
	if( bHit ) 
    {
        this->sfx(CCString::create(SOUND_CONFIRM));
        
        if( newPosition == 0 ) 
        {
            
            bool bHasOthersInTeam = false;
            for(int i=0; i<monsters->count();i++)
            {
                
                monster* mon= (monster*) monsters->objectAtIndex(i); 
                if( mon != selMonster )
                {
                    if( mon->position > 0 )
                    {
                        bHasOthersInTeam = true;
                    }
                }
            }
            
            if( bHasOthersInTeam ) 
            {
                selMonster->position = 0;
                this-> popMenu(CCString::createWithFormat("%@ has been moved to the GeoSociety Monster Bank.",selMonster-> getName()));
            }
            else 
            {
                this-> popMenu(CCString::createWithFormat("You cannot transfer all monsters to the GeoSociety Monster Bank. You must always be carrying at least one monster."));
            }
        }
        else 
        {
            bool bFound = false;
            monster * swapMon = NULL;
            for(int i=0; i<monsters->count();i++)
            {
                
                monster* mon= (monster*) monsters->objectAtIndex(i); 
                if( mon != selMonster )
                {
                    if( mon->position == newPosition )
                    {
                        bFound = true;
                        swapMon = mon;
                    }
                }
            }
            if( bFound ) 
            {
                swapMon->position = selMonster->position;
            } 
            selMonster->position = newPosition;
            this->popMenu(CCString::createWithFormat("%s has been moved to slot #%d in the Party.",selMonster-> getName()->getCString(),newPosition));
        }
		
        this-> displayMonster(selMonster);
        
	}
}


#pragma mark -
#pragma mark === MONSTER STAT POINT FUNCTIONS ===
#pragma mark -




void gearLayer::displayStatResetOptions()
{
    
    menuStage = 33;
    menuItems-> removeAllObjects();
    monsterItems-> removeAllObjects();
    monsterPageItems-> removeAllObjects();
    
    CoolSprite * tmpSpt = new CoolSprite();
    CoolLabel * tmpLbl = new CoolLabel();
    CoolFreeform * tmpFF = new CoolFreeform();
    
    tmpSpt -> initWithFile(CCString::create("bgMenu.png"));
    tmpSpt-> updatePosition(ccp(parent-> sWidth()/2,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,7);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    tmpFF -> initWithCoolSheet(CCString::createWithFormat("You have %d Stat Resets Available.",parent->statResetsRemaining), FONT_WHITE,0.45 ,520 ,true);
    tmpFF-> updatePosition(ccp(10,310));
    tmpFF-> addToLayer(this,11);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpSpt -> initWithFile(CCString::create("buttonRedExt.png"));
    tmpSpt->updatePosition(ccp(240,240));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,7);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpFF -> initWithCoolSheet(CCString::createWithFormat("Reset %s's Stats",selMonster->getName()->getCString()), FONT_WHITE, 0.3 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(240,257));
    tmpFF-> addToLayer(this,12);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    
    /*
     tmpLbl = [[CoolLabel alloc] initWithCoolString:[NSString stringWithFormat:@"You have %d Stat Reset(s) Available.",parent.statResetsRemaining] fontName:@"Arial" fontSize:16];
     [tmpLbl updatePosition:ccp(240,280)];
     [tmpLbl updateOpacity:255];
     [tmpLbl addToLayer:self z:10];
     [menuItems addObject:tmpLbl];
     [tmpLbl release];
     */
    
    IAPStatResetFound = false;
    //pending_sneha    MKStoreManager::sharedManager()-> setParent(parent);
    /*pending_sneha    if(MKStoreManager::sharedManager()->purchasableObjects-> count() == 0 )
     {
     
     tmpLbl -> initWithCoolString(CCString::create("Loading Stat Reset In-App Purchase Data"), "Arial" ,16);
     tmpLbl-> updatePosition(ccp(240,160));
     tmpLbl-> updateOpacity(255);
     tmpLbl-> addToLayer(this,10);
     menuItems-> addObject(tmpLbl);
     tmpLbl-> release();
     
     tmpLbl ->initWithCoolString(CCString::create("Please Wait..."), "Arial" ,14);
     tmpLbl-> updatePosition(ccp(240,140));
     tmpLbl-> updateOpacity(255);
     tmpLbl-> addToLayer(this,10);
     menuItems-> addObject(tmpLbl);
     tmpLbl-> release();
     
     
     } 
     else
     {
     
     SKProduct * prod = NULL;
     //pending_sneha   for(int i=0;i<MKStoreManager::sharedManager()->purchasableObjects-> count();i++) 
     
     {
     //pending_sneha   prod = MKStoreManager::sharedManager()->purchasableObjects-> objectAtIndex(i);
     if( prod->productIdentifier() isEqualToString(featureCId) )
     {
     break;
     }
     else
     {
     prod = NULL;
     }
     }
     
     if( prod!= NULL )
     {
     
     IAPStatResetFound = true;
     
     tmpFF ->initWithCoolSheet(prod->localizedTitle(), FONT_WHITE ,0.45 ,380 ,true);
     tmpFF-> updatePosition(ccp(10,200+15));
     tmpFF-> addToLayer(this,11);
     menuItems-> addObject(tmpFF);
     tmpFF-> release();
     
     tmpFF ->initWithCoolSheet(prod->localizedDescription(), FONT_WHITE ,0.35 ,420 ,true);
     tmpFF-> updatePosition(ccp(10,170+15));
     tmpFF-> addToLayer(this,11);
     menuItems-> addObject(tmpFF);
     tmpFF-> release();
     
     tmpLbl -> initWithCoolString(parent-> stringFromLocalPrice(prod), "Arial", 20);
     tmpLbl-> updatePosition(ccp(480-80,185+15));
     tmpLbl-> updateOpacity(255);
     tmpLbl-> addToLayer(this,10);
     menuItems-> addObject(tmpLbl);
     tmpLbl-> release();
     
     tmpSpt -> initWithFile("buttonGreenExt.png");
     tmpSpt-> updatePosition(ccp(240,90));
     tmpSpt-> updateOpacity(255);
     tmpSpt-> addToLayer(this,7);
     menuItems-> addObject(tmpSpt);
     tmpSpt-> release();
     
     tmpFF -> initWithCoolSheet(CCString::create("Purchase"), FONT_WHITE ,0.4 ,320 ,true);
     tmpFF->bCenter = true;
     tmpFF-> updatePosition(ccp(240,110));
     tmpFF-> addToLayer(this,12);
     menuItems-> addObject(tmpFF);
     tmpFF ->release();
     
     
     }
     else
     {
     
     tmpLbl -> initWithCoolString(CCString::create("There was an Error Loading IAP Details."), "Arial",16);
     tmpLbl-> updatePosition(ccp(240,160));
     tmpLbl-> updateOpacity(255);
     tmpLbl-> addToLayer(this,10);
     menuItems-> addObject(tmpLbl);
     tmpLbl-> release();
     
     tmpLbl -> initWithCoolString(CCString::create("Please Try Again Later by Restarting the Application." ),"Arial" ,12);
     tmpLbl-> updatePosition(ccp(240,140));
     tmpLbl-> updateOpacity(255);
     tmpLbl-> addToLayer(this,10);
     menuItems-> addObject(tmpLbl);
     tmpLbl-> release();
     
     }
     
     
     }*/
    
    
    /*
     tmpLbl = [[CoolLabel alloc] initWithCoolString:[NSString stringWithFormat:@"Purchase More Stat"] fontName:@"Arial" fontSize:16];
     [tmpLbl updatePosition:ccp(240,280)];
     [tmpLbl updateOpacity:255];
     [tmpLbl addToLayer:self z:10];
     [menuItems addObject:tmpLbl];
     [tmpLbl release];
     */
    
    
    
    //statResetsRemaining
}



void gearLayer::statResetTouch(CCPoint  touch)
{
    
    //pending_sneha   if( MKStoreManager::sharedManager()->bIsBusy ) 
    return;
    
    if( touch.y > 0 && touch.y < 35 ) 
    {
        if( touch.x > 480-88 ) 
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            this-> displayMonsterStats(selMonster);
        }
    }
    
    CCPoint button =  ccp(240,90);
    if( touch.x > button.x -25 && touch.x < button.x + 25 )
    {
        if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            
            //pending_sneha   MKStoreManager::sharedManager()-> buyFeatureC(parent);
            
        }
    }
    
    button = ccp(240,240);
    
    
    if( touch.x > button.x -25 && touch.x < button.x + 25 )
    {
        if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
        {
            if( parent->statResetsRemaining > 0 )
            {
                this-> sfx(CCString::create(SOUND_CONFIRM));
                
                selMonster->stat_points = selMonster->stat_points + selMonster->atk + selMonster->def + selMonster->spd + selMonster->intel + selMonster->hp - 5;
                selMonster->atk=1;
                selMonster->def=1;
                selMonster->spd=1;
                selMonster->intel=1;
                selMonster->hp=1;
                
                parent->statResetsRemaining--;
                
                this->displayMonsterStats(selMonster);
            }
        }
    }
    
}


void gearLayer::displayMonsterStats(monster * mon)
{
    
    menuStage = 31;
    menuItems-> removeAllObjects();
    monsterItems-> removeAllObjects();
    monsterPageItems-> removeAllObjects();
    
    CoolSprite * tmpSpt = new CoolSprite();
    CoolLabel * tmpLbl = new CoolLabel();
    
    
    
    tmpSpt -> initWithFile(CCString::create("bgMenu.png"));
    tmpSpt-> updatePosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,7);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt -> initWithFile(CCString::create("bg9.png"));
    tmpSpt-> updatePosition(ccp(240,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,8);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpLbl -> initWithCoolString(CCString:: createWithFormat("%d",selMonster->stat_points), "Arial" ,16);
    tmpLbl-> updatePosition(ccp(200+40,320-265));
    tmpLbl-> updateOpacity(255);
    tmpLbl-> addToLayer(this,10);
    tmpLbl->updateAnchorPointBottomRight();
    menuItems-> addObject(tmpLbl);
    tmpLbl-> release();
    
    tmpLbl -> initWithCoolString(CCString::createWithFormat("%d",selMonster->hp) ,"Arial" ,16);
    tmpLbl-> updatePosition(ccp(80+40,320-35));
    tmpLbl-> updateOpacity(255);
    tmpLbl-> addToLayer(this,10);
    menuItems-> addObject(tmpLbl);
    tmpLbl-> release();
    
    
    tmpLbl -> initWithCoolString(CCString:: createWithFormat("%d",selMonster->atk), "Arial", 16);
    tmpLbl-> updatePosition(ccp(80+40,320-81));
    tmpLbl-> updateOpacity(255);
    tmpLbl-> addToLayer(this,10);
    menuItems-> addObject(tmpLbl);
    tmpLbl-> release();
    
    
    tmpLbl -> initWithCoolString(CCString::createWithFormat("%d",selMonster->def),"Arial" ,16);
    tmpLbl-> updatePosition(ccp(80+40,320-123));
    tmpLbl-> updateOpacity(255);
    tmpLbl-> addToLayer(this,10);
    menuItems-> addObject(tmpLbl);
    tmpLbl-> release();
    
    
    tmpLbl -> initWithCoolString(CCString::createWithFormat("%d",selMonster->spd), "Arial", 16);
    tmpLbl-> updatePosition(ccp(80+40,320-169));
    tmpLbl-> updateOpacity(255);
    tmpLbl-> addToLayer(this,10);
    menuItems-> addObject(tmpLbl);
    tmpLbl-> release();
    
    
    tmpLbl -> initWithCoolString(CCString::createWithFormat("%d",selMonster->intel), "Arial" ,16);
    tmpLbl-> updatePosition(ccp(80+40,320-212));
    tmpLbl-> updateOpacity(255);
    tmpLbl-> addToLayer(this,10);
    menuItems-> addObject(tmpLbl);
    tmpLbl-> release();
    
    //statResetsRemaining
    
    tmpLbl -> initWithCoolString(CCString::create("Stat Reset Options"), "Arial", 16);
    tmpLbl-> updatePosition(ccp(100,25));
    tmpLbl-> updateOpacity(255);
    tmpLbl-> addToLayer(this,10);
    menuItems-> addObject(tmpLbl);
    tmpLbl-> release();
    
}


void gearLayer:: monsterStatsTouch(CCPoint touch)
{
    
    CCPoint button = ccp(100,25);
    
    if( touch.x > button.x -25 && touch.x < button.x + 25 )
    {
        if( touch.y > button.y -25 && touch.y < button.y + 25 )
        {
            this-> sfx(CCString::create(SOUND_CONFIRM));
            this-> displayStatResetOptions();
        }
    }
    
    if( touch.y > 0 && touch.y < 35 ) 
    {
        if( touch.x > 480-88 ) 
        {
            this-> sfx(CCString::create( SOUND_CONFIRM));
            this-> displayMonster(selMonster);
        }
    }
    
    /*
     if( touch.y > 0 && touch.y < 35 ) {
     if( touch.x < 88 ) {
     [self sfx:SOUND_CONFIRM];
     [self displayIndex];
     }
     }
     */
    
    if( touch.y > 320-235 && touch.y < 320-12 ) 
    {
        if( touch.x > 156 )
        {
            int xPos = (touch.x - 156) / 68;
            int yPos = (320-touch.y-12) / 45;
            
            CCString* tmp = NULL;
            if( yPos == 0 ) 
            {
                tmp =CCString::create( "hp");
            }
            else if( yPos == 1 )
            {
                tmp = CCString::create("atk");
            }
            else if( yPos == 2 )
            {
                tmp =CCString::create( "spd");
            }
            else if( yPos == 3 )
            {
                tmp =CCString::create( "def");
            }
            else
            {
                tmp =CCString::create( "int");
            } 
            
            int amt = 0;
            if( xPos == 0 )
            {
                amt = 1;
            }
            else if( xPos == 1 )
            {
                amt = 10;
            }
            else if( xPos == 2 ) 
            {
                amt = 50;
            }
            else
            {
                amt = selMonster->stat_points;
            }
            
            if( selMonster->stat_points >= amt ) 
            {
                this-> sfx(CCString::create(SOUND_CONFIRM));
                
                if( yPos == 0 ) 
                {
                    selMonster->hp=selMonster->hp+amt;
                }
                else if( yPos == 1 ) 
                {
                    selMonster->atk=selMonster->atk+amt;
                }
                else if( yPos == 2 ) 
                {
                    selMonster->def=selMonster->def+amt;
                }
                else if( yPos == 3 ) 
                {
                    selMonster->spd=selMonster->spd+amt;
                }
                else
                {
                    selMonster->intel=selMonster->intel+amt;
                }
                selMonster->stat_points=selMonster->stat_points-amt;
                
                this-> displayMonsterStats(selMonster);
                
            }
        }
    }
}


#pragma mark -
#pragma mark === POPUP MENU FUNCTIONS ===
#pragma mark -

void gearLayer::popMenu(CCString * text)
{
    popItems-> removeAllObjects();
    
    
    CoolSprite* tmpSpt = new  CoolSprite();
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt-> updatePosition(ccp(240,160));
    tmpSpt-> updateOpacity(220);
    tmpSpt-> addToLayer(this,100);
    popItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt ->initWithFile(CCString::create("geoMonsters.png"));
    tmpSpt-> updatePosition(ccp(240,65));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,110);
    popItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    CoolFreeform * tmpLbl = new CoolFreeform();
    tmpLbl->initWithCoolSheet(text, FONT_WHITE ,0.4 ,300 ,true);  
    tmpLbl->bCenter = true;
    tmpLbl-> updatePosition(ccp(480/2,340-80));
    tmpLbl-> addToLayer(this,110);
    popItems-> addObject(tmpLbl);
    tmpLbl-> release();
    
    tmpLbl -> initWithCoolSheet(CCString::create("Ok"), FONT_WHITE ,0.4 ,300 ,true); 
    tmpLbl->bCenter = true;
    tmpLbl-> updatePosition(ccp(480/2,200-80));
    tmpLbl-> addToLayer(this,110);
    popItems-> addObject(tmpLbl);
    tmpLbl-> release();
    
}





void gearLayer::popTouch(CCPoint touch)
{
    
    if( touch.y > 200-80-40 && touch.y < 200-80 + 40 ) 
    {
        this->sfx(CCString::create(SOUND_CONFIRM));
        popItems-> removeAllObjects();
    }
    
}



#pragma mark -
#pragma mark === INVENTORY FUNCTIONS ===
#pragma mark -

void gearLayer::shiftSelection()
{
    for(int i=1;i<menuItems->count();i++)
    {
         if( typeid(menuItems->objectAtIndex(i)) == typeid(CoolSprite))
         {
             CoolSprite* tmp = (CoolSprite*)menuItems-> objectAtIndex(i);
             
             tmp-> updatePosition(ccp(tmp->x,320-(tmp->intTag2+sliderPosition)));
         }
         else
         {
             CoolFreeform* tmp =(CoolFreeform*)menuItems-> objectAtIndex(i);
             tmp-> updatePosition(ccp(tmp->x,320-(tmp->intTag2+sliderPosition)));
         }
    }
}

void gearLayer::itemSelectTouch(CCPoint touch)
{
    
    if( !bTouchWasSlide )
    {
        
        //was in the button column
        
        CCDictionary* inventory = (CCDictionary*)parent-> getItems();
        int titleOffset = 32;
        int count = 0;
        for(int i=0; i<inventory->allKeys()->count();i++)
        {
            CCString* keyName = (CCString*)inventory->allKeys()->objectAtIndex(i);
            int itemId = keyName-> intValue();
            int itemCountInst = parent-> itemCount(itemId);
            if( itemCountInst > 0 )
            {
                
                
                dataItem* itemData =   parent->getDatabase()->itemById(itemId);
                
                //if( [itemData isBattleItem] ) {
                
                
                int monYPos = count * 50 + 25 + titleOffset;
                if( touch.y > 320-(monYPos+sliderPosition)-25 && touch.y < 320-(monYPos+sliderPosition)+25 )
                {
                    
                    if( itemId >= 13 && itemId <= 17  )
                    {
                        //TODO: Open the Monster Select Page.... if so do it!
                        
                        itemForTarget = itemData;
                        this-> sfx(CCString::create(SOUND_CONFIRM));
                        this-> displayMonsterSelectPage();
                        
                    }
                    else
                    {
                        //TODO: Work out if Item Should Do Anything.... if so do it!
                        this-> sfx(CCString::create(SOUND_CONFIRM));
                        itemForTarget = itemData;
                        
                    }
                    return;
                    
                }
                count++;
                //}
            }
        }
        if( count>0)
            count--;
        
        //Check for the cancel button
        int monYPos = count * 50 + 25 + titleOffset + 48;
        if( touch.y > 320-(monYPos+sliderPosition)-20 && touch.y < 320-(monYPos+sliderPosition)+20 ) 
        {
            if( touch.x > 240+104-40 && touch.x < 240+104+40 ) 
            {
                //Cancel Item Selection
                
                this-> sfx(CCString::create(SOUND_CONFIRM));
                this-> displayIndex();
            }
        }
        
        
        
    }
    
}

void gearLayer::displayItemSelectPage()
{
    menuItems-> removeAllObjects();
    
    menuStage = 80;
    
    team->removeAllObjects();
    CCArray* monsters = (CCArray*)parent-> getMonsters();
    
    for(int i=0; i<monsters->count();i++)
    {
        monster* mon =(monster*)monsters->objectAtIndex(i);
        if( mon->position > 0 ) 
        {
            if( mon->position >= team->count() ) 
            {
                team->insertObject(mon,team->count());
            }
            else
            {
                team->insertObject(mon, mon->position-1);
            }
        }
    }
    
    CoolSprite * tmpSpt = NULL;
    CoolFreeform * tmpFF = NULL;
    
    int titleOffset = 32;
    sliderPosition = 0;
    
    tmpSpt = new CoolSprite(); 
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt->updatePosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,30);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpFF = new CoolFreeform();
    tmpFF->initWithCoolSheet(CCString::create("Select an Item to Use"), FONT_WHITE ,0.30 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition( ccp(160,320-12));
    tmpFF->intTag1 = 160;
    tmpFF->intTag2 = 12;
    tmpFF-> addToLayer(this,32);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    
    
    CCDictionary* inventory = (CCDictionary*)parent-> getItems();
    for(int i = inventory->allKeys()-> count()-1;i >= 0;i-- ) 
    {
        CCString* keyName = (CCString*)inventory-> allKeys()-> objectAtIndex(i);
        if( keyName->isEqual(CCString::create("0") ))
        {
            inventory-> removeObjectForKey("0");
        }
    }
    
    
    int count = 0;
    for(int i=0; i<inventory->allKeys()->count();i++)
    {
        CCString* keyName =(CCString*)inventory-> allKeys()->objectAtIndex(i);
        int itemId = keyName->intValue();
        int itemInstCount = parent->itemCount(itemId);
        if( itemInstCount > 0 )
        {
            
            
            dataItem * itemData = parent->getDatabase()->itemById(itemId);
            
            
            //          if( itemData->isBattleItem() ) 
            //          {
            
            //monsterSelectBox.png
            tmpSpt -> initWithFile(CCString::create("moneybag.png"));
            tmpSpt-> updatePosition(ccp(4+16,320- count * 50 + 25 + titleOffset));
            tmpSpt->intTag2 = count * 50 + 25 + titleOffset;
            tmpSpt-> updateOpacity(255);
            tmpSpt-> addToLayer(this,31);
            menuItems-> addObject(tmpSpt);
            tmpSpt-> release();
            
            if( itemId >= 13 && itemId <= 17  )
            {
                tmpFF -> initWithCoolSheet(itemData-> getName(), FONT_GREEN ,0.25 ,320 ,true);
            }
            else
            {
                tmpFF-> initWithCoolSheet(itemData-> getName(), FONT_WHITE, 0.25 ,320 ,true);
            }
            
            tmpFF-> updatePosition(ccp(32+8,320- count * 50 + 5 + titleOffset));
            tmpFF->intTag2 = count * 50 + 5 + titleOffset;
            tmpFF-> addToLayer(this,32);
            menuItems-> addObject(tmpFF);
            tmpFF-> release();
            
            tmpFF -> initWithCoolSheet(itemData-> getScope(), FONT_WHITE ,0.20 ,320 ,true);
            tmpFF->bCenter = true;
            tmpFF-> updatePosition( ccp(480-105,320- count * 50 + 5 + titleOffset));
            tmpFF->intTag2 = count * 50 + 5 + titleOffset;
            tmpFF-> addToLayer(this,32);
            menuItems-> addObject(tmpFF);
            tmpFF-> release();
            
            tmpFF -> initWithCoolSheet(itemData-> getDescription(), FONT_WHITE, 0.20 ,320 ,true);
            tmpFF-> updatePosition(ccp(32+8,320 - count * 50 + 25 + titleOffset));
            tmpFF->intTag2 =count * 50 + 25 + titleOffset;
            tmpFF-> addToLayer(this,32);
            menuItems-> addObject(tmpFF);
            tmpFF-> release();
            
            tmpFF -> initWithCoolSheet(CCString::createWithFormat("x%d",itemInstCount), FONT_WHITE ,0.35 ,100 ,true);
            tmpFF-> updatePosition( ccp(480-50,320- count * 50 + 5 + titleOffset));
            tmpFF->intTag2 =count * 50 + 5 + titleOffset;
            tmpFF-> addToLayer(this,32);
            menuItems-> addObject(tmpFF);
            tmpFF-> release();
            
            count++;
            //}
        }
    }
    itemCount = count;
    if( count > 0)
        count--;
    
    
    tmpFF-> initWithCoolSheet(CCString::create("Cancel"), FONT_WHITE ,0.4 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(240+104,320- count * 50 + 5 + titleOffset + 48));
    tmpFF->intTag1 = 160+104;
    tmpFF->intTag2 = count * 50 + 5 + titleOffset + 48;
    tmpFF-> addToLayer(this,35);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    this-> shiftSelection();
    
}


#pragma mark -
#pragma mark === INVENTORY-MONSTERS FUNCTIONS ===
#pragma mark -




void gearLayer::monsterSelectTouch(CCPoint  touch)
{
    
    if( !bTouchWasSlide )
    {
        
        //was in the button column
        
        if( touch.x > 160+104-40 && touch.x < 160+104+40 )
        {
            //was in the button column
            
            int titleOffset = 32;
            int count = 0;
            for(int i=0; i<team->count();i++)
            {
                monster * mon = (monster*)team->objectAtIndex(i);
                int monYPos = count * 128 + 64 + titleOffset + 36;
                if( touch.y > 320-(monYPos+sliderPosition)-40 && touch.y < 320-(monYPos+sliderPosition)+40 ) 
                {
                    
                    if( itemForTarget->itemid == 13 && mon->hpLeft == 0 )
                    {
                        
                        mon->hpLeft = mon->hp / 4;
                        
                        CCString* tmpStr = CCString::createWithFormat("Display Message\t%s woke up.^",mon->getName()->getCString()); 
                        
                        parent->addScript(((CCArray*)convertedString-> componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                        
                        
                        
                        
                        
                        
                        
                        bIsActive = false;
                        this-> hideMenu();
                        this->sfx(CCString::create(SOUND_CONFIRM));
                        parent-> scriptProgress();
                        
                        parent-> useItems(itemForTarget->itemid,1);
                        //TODO: Revive Action
                        return;
                    }
                    else if( itemForTarget->itemid != 13 && mon->hpLeft > 0 && mon->hpLeft < mon->hp ) 
                    {
                        
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
                            itemHPEffect = mon->hp - mon->hpLeft;
                        } 
                        
                        mon->hpLeft = mon->hpLeft + itemHPEffect;
                        if( mon->hpLeft > mon->hp ) 
                            mon->hpLeft = mon->hp;
                        
                        CCString* tmpStr = CCString::createWithFormat("Display Message\t%s recovered %d health points.^",mon-> getName()->getCString(),itemHPEffect); 
                        parent->addScript(CCArray::create(convertedString-> componentsSeparatedByString(tmpStr,CCString::create("\t"))));
                        bIsActive = false;
                        this-> hideMenu();
                        this-> sfx(CCString::create(SOUND_CONFIRM));
                        parent-> scriptProgress();
                        
                        parent-> useItems(itemForTarget->itemid,1);
                        
                        return;
                    }
                    
                    
                }
                count++;
            }
            count--;
            int monYPos = count * 128 + 64 + titleOffset + 64 + 20;
            if( touch.y > 320-(monYPos+sliderPosition)-20 && touch.y < 320-(monYPos+sliderPosition)+20 ) 
            {
                //Cancel Monster Selection
                this->sfx(CCString::create(SOUND_CONFIRM));
                this->displayItemSelectPage();
            }
            
        }
        
        
        
    }
    
}


void gearLayer::displayMonsterSelectPage()
{
    menuItems-> removeAllObjects();
    
    menuStage = 81;
    
    CoolSprite * tmpSpt = NULL;
    CoolFreeform * tmpFF = NULL;
    
    int titleOffset = 32;
    sliderPosition = 0;
    
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt-> updatePosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,30);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    
    tmpSpt -> initWithFile(CCString::create("monsterSelectFillerBox.png"));
    tmpSpt-> updatePosition( ccp(284,320-18));
    tmpSpt->intTag1 = 240;
    tmpSpt->intTag2 = 18;
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,31);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("Select a Target for the Item"), FONT_WHITE ,0.30 ,320 ,true);  
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(160,320-12));
    tmpFF->intTag1 = 160;
    tmpFF->intTag2 = 12;
    tmpFF-> addToLayer(this,32);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    
    
    
    int count = 0;
    for(int i=0; i<team->count();i++)
    {
        monster * mon = (monster*)team->objectAtIndex(i);
        //monsterSelectBox.png
        
        dataMonster* dataMon = (dataMonster*) mon->getMonster();
        
        tmpSpt ->initWithFile(CCString::create("monsterSelectBox.png"));
        tmpSpt-> updatePosition(ccp(284,320- count * 128 + 64 + titleOffset));
        tmpSpt->intTag1 = 160;
        tmpSpt->intTag2 = count * 128 + 64 + titleOffset;
        tmpSpt-> updateOpacity(255);
        tmpSpt-> addToLayer(this,31);
        menuItems-> addObject(tmpSpt);
        tmpSpt-> release();
        
        tmpSpt ->initWithFile(mon->getImage());
        tmpSpt-> updatePosition(ccp(50,320-count * 128 + 64 + titleOffset - 18));
        tmpSpt->intTag1 = 50;
        tmpSpt->intTag2 = count * 128 + 64 + titleOffset - 18;
        tmpSpt-> updateOpacity(255);
        tmpSpt-> addToLayer(this,31);
        menuItems-> addObject(tmpSpt);
        tmpSpt-> release();
        
        
        tmpFF ->initWithCoolSheet(mon-> getName(), FONT_WHITE ,0.35 ,320 ,true);
        tmpFF-> updatePosition( ccp(160-56,320-count * 128 + 64 + titleOffset -54));
        tmpFF->intTag1 = 160-56;
        tmpFF->intTag2 = count * 128 + 64 + titleOffset -54;
        tmpFF-> addToLayer(this,32);
        menuItems-> addObject(tmpFF);
        tmpFF-> release();
        
        tmpFF -> initWithCoolSheet(mon-> getLvlString(), FONT_WHITE, 0.30 ,100 ,true);
        tmpFF ->updatePosition( ccp(160-56,320-count * 128 + 64 + titleOffset -32));
        tmpFF->intTag1 = 160-56;
        tmpFF->intTag2 =count * 128 + 64 + titleOffset -32;
        tmpFF-> addToLayer(this,32);
        menuItems-> addObject(tmpFF);
        tmpFF-> release();
        
        tmpFF -> initWithCoolSheet(mon-> getHpString(), FONT_WHITE ,0.30 ,100 ,true);
        tmpFF-> updatePosition( ccp(160-56,320-count * 128 + 64 + titleOffset -10));
        tmpFF->intTag1 = 160-56;
        tmpFF->intTag2 = count * 128 + 64 + titleOffset -10;
        tmpFF->addToLayer(this,32);
        menuItems-> addObject(tmpFF);
        tmpFF-> release();
        
        tmpSpt -> initWithFile(CCString::createWithFormat("element-%s.png", convertedString->lowercaseString(dataMon-> getType1())->getCString()));
        tmpSpt-> updatePosition(ccp(14+16,320-count * 128 + 64 + titleOffset + 45));
        tmpSpt->intTag1 = 14+16;
        tmpSpt->intTag2 = count * 128 + 64 + titleOffset + 45;
        tmpSpt-> updateOpacity(255);
        tmpSpt-> addToLayer(this,37);
        menuItems-> addObject(tmpSpt);
        tmpSpt-> release();
        
        
        tmpSpt -> initWithFile(CCString::createWithFormat("element-%s.png", convertedString->lowercaseString(dataMon-> getType2())->getCString()));
        tmpSpt-> updatePosition(ccp(53+16,320-count * 64 + 64 + titleOffset + 45));
        tmpSpt->intTag1 = 53+16;
        tmpSpt->intTag2 = count * 128 + 64 + titleOffset + 45;
        tmpSpt-> updateOpacity(255);
        tmpSpt-> addToLayer(this,37);
        menuItems-> addObject(tmpSpt);
        tmpSpt-> release();
        
        bool bAvailable = false;
        if( itemForTarget->itemid == 13 )
        {
            if( mon->hpLeft == 0 )
            {
                bAvailable = true;
                tmpFF -> initWithCoolSheet(CCString::create("Fainted"), FONT_GREEN ,0.35 ,320 ,true);
            }
            else
            {
                tmpFF -> initWithCoolSheet(CCString::create("Available"), FONT_RED ,0.35 ,320 ,true);
            }
        } 
        else
        { //Other Items Require Monster who havent fainted and arent at full health
            if( mon->hpLeft == 0 )
            {
                tmpFF -> initWithCoolSheet(CCString::create("Fainted"), FONT_RED ,0.35 ,320 ,true);
            }
            else if( mon->hpLeft == mon->hp )
            {
                tmpFF ->initWithCoolSheet(CCString::create("Max Health"), FONT_RED ,0.30 ,320 ,true);
            }
            else
            {
                bAvailable = true;
                tmpFF ->initWithCoolSheet(CCString::create("Available"), FONT_GREEN ,0.35 ,320 ,true);
            }
        }
        tmpFF-> updatePosition(ccp(160-56,320-count * 128 + 64 + titleOffset + 48));
        tmpFF->intTag1 = 160-56;
        tmpFF->intTag2 = count * 128 + 64 + titleOffset + 36;
        tmpFF-> addToLayer(this,32);
        menuItems-> addObject(tmpFF);
        tmpFF-> release();
        
        if( bAvailable )
        {
            tmpFF -> initWithCoolSheet(CCString::create("Select"), FONT_GREEN ,0.35 ,320 ,true);
        }
        else
        {
            tmpFF -> initWithCoolSheet(CCString::create("Select"),FONT_RED ,0.35 ,320 ,true);
        }
        tmpFF->bCenter = true;
        tmpFF-> updatePosition( ccp(160+104,320-count * 128 + 64 + titleOffset + 48));
        tmpFF->intTag1 = 160+104;
        tmpFF->intTag2 = count * 128 + 64 + titleOffset + 36;
        tmpFF-> addToLayer(this,32);
        menuItems-> addObject(tmpFF);
        tmpFF-> release();
        
        
        
        count++;
    }
    count--;
    
    
    tmpSpt -> initWithFile(CCString::create("monsterSelectCancelBox.png"));
    tmpSpt-> updatePosition(ccp(284,320- count * 128 + 64 + titleOffset + 64 + 20));
    tmpSpt->intTag1 = 240;
    tmpSpt->intTag2 = count * 128 + 64 + titleOffset + 64 + 20;
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,34);
    menuItems-> addObject(tmpSpt);
    tmpSpt->release();
    
    tmpFF -> initWithCoolSheet(CCString::create("Cancel"),FONT_WHITE ,0.4 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition( ccp(160+104,320-count * 128 + 64 + titleOffset + 64 + 10));
    tmpFF->intTag1 = 160+104;
    tmpFF->intTag2 = count * 128 + 64 + titleOffset + 64 + 10;
    tmpFF-> addToLayer(this,35);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    
    this-> shiftSelection();
    
}





#pragma mark -
#pragma mark ===  MONSTER LORE MONSTER FUNCTIONS ===
#pragma mark -


void gearLayer::displayMonsterLoreMonster2(int monid)
{
    menuItems-> removeAllObjects();
    monsterSprites-> removeAllObjects();
    
    oldMenuStage = menuStage;
    menuStage = 68;
    
    CoolSprite * tmpSpt = new CoolSprite();
    tmpSpt->initWithFile(CCString::create("bgMenu.png"));
    tmpSpt-> updatePosition(ccp(240,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,9);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    /*
     tmpSpt = [[CoolSprite alloc] initWithFile:@"backmenu.png"];
     [tmpSpt updatePosition:ccp(160,240)];
     [tmpSpt updateOpacity:255];
     [tmpSpt addToLayer:self z:10];
     [menuItems addObject:tmpSpt];
     [tmpSpt release];
     */
    
    //Pending_snehamonsterScene * monScene =  (monsterScene*)initWithMonsterData(parent-> getDatabase() ,monid);
    
    //Pending_sneha                [[CCDirector::sharedDirector()->pushScene(monScene);
    //Pending_sneha monScene-> release();
    
    if( oldMenuStage == 30 )
    {
        this-> displayMonster(selMonster);
    }
    else
    {
        this-> displayMonsterLoreMonsters(loreMonsterType);
    }
}

void gearLayer::monsterLoreMonsterTouch(CCPoint touch)
{
	
	
}



#pragma mark -
#pragma mark ===  MONSTER TYPE POSTER FUNCTIONS ===
#pragma mark -


void gearLayer:: displayMonsterLorePoster()
{
    menuItems-> removeAllObjects();
    monsterSprites-> removeAllObjects();
    
    menuStage = 66;
    
    
    CoolSprite* tmpSpt = new CoolSprite();
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt-> updatePosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,9);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt -> initWithFile(CCString::create("bgMenu.png"));
    tmpSpt-> updatePosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    CoolFreeform * tmpFF =new  CoolFreeform();
    tmpFF->initWithCoolSheet(CCString::create("Attack Element -Left- vs. Defending Monster Element" ),FONT_WHITE ,0.30 ,230 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(480-105,320-5));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    
    tmpSpt ->initWithFile(CCString::create("typeGrid.png"));
    tmpSpt->updatePosition(ccp(135,320-135));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    tmpSpt ->initWithFile(CCString::create("ballRed.png"));
    tmpSpt->updatePosition(ccp(480-210+18,320-100));
    tmpSpt-> updateOpacity(255);
    tmpSpt->addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    tmpFF ->initWithCoolSheet(CCString::create("Half Damage"), FONT_WHITE, 0.2 ,310 ,true);
    tmpFF-> updatePosition(ccp(480-210+34,320-100+5));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    
    tmpSpt ->initWithFile(CCString::create("ballOrange.png"));
    tmpSpt->updatePosition(ccp(480-210+18,320-120));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("Three Quarters Damage") ,FONT_WHITE ,0.2 ,310 ,true);
    tmpFF-> updatePosition(ccp(480-210+34,320-120+5));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    
    
    tmpSpt->initWithFile(CCString::create("ballGreen.png"));
    tmpSpt-> updatePosition(ccp(480-210+18,320-140));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt->release();
    
    
    tmpFF ->initWithCoolSheet(CCString::create("Double Damage"), FONT_WHITE ,0.2 ,310 ,true);
    tmpFF->updatePosition(ccp(480-210+34,320-140+5));
    tmpFF-> addToLayer(this,20);
    menuItems->addObject(tmpFF);
    tmpFF-> release();
    
    tmpSpt ->initWithFile(CCString::create("ballYellow.png"));
    tmpSpt-> updatePosition(ccp(480-210+18,320-160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems->addObject(tmpSpt);
    tmpSpt-> release();
    
    
    tmpFF ->initWithCoolSheet(CCString::create("A Half Extra Damage"),FONT_WHITE ,0.2 ,310 ,true);
    tmpFF-> updatePosition(ccp(480-210+34,320-160+5));
    tmpFF->addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
}

void gearLayer::monsterLorePosterTouch(CCPoint touch)
{
    
    
    if( touch.y > 0 && touch.y < 35 )
    {
        if( touch.x > 320-88 )
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            this->displayMonsterLoreHome();
        }
    }
    
    if( touch.y > 0 && touch.y < 35 ) 
    {
        if( touch.x < 88 )
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            this->displayIndex();
        }
    }
    
    
    
}



#pragma mark -
#pragma mark ===  MONSTER LIBRARY FUNCTIONS ===
#pragma mark -



void gearLayer::displayMonsterLoreMonsters(CCString *type)
{
    menuItems-> removeAllObjects();
    monsterSearchResults-> removeAllObjects();
    monsterSprites-> removeAllObjects();
    menuStage = 67;
    
    if( type != NULL)
    {
        
        CCString* tmpStr = CCString::create(type->getCString());
        
        if( loreMonsterType != NULL ) 
        {
            loreMonsterType-> release();
            loreMonsterType = NULL;
            
        }
        
        
        loreMonsterType =CCString::create(tmpStr->getCString());
        
    }
    else
    {
        if( loreMonsterType != NULL )
        {
            loreMonsterType-> release();
            loreMonsterType = NULL;
        }
    }
    
    CoolSprite* tmpSpt = new  CoolSprite();
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt-> updatePosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,7);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt ->initWithFile(CCString::create("bg7.png"));
    tmpSpt-> updatePosition(ccp(284,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,9);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    
    
    
    
    CCArray* tmpArray = new CCArray;
    tmpArray->retain();
    parent->getDatabase()->getMonstersOfType(convertedString->lowercaseString(type), tmpArray);
    monsterSearchResults-> removeAllObjects();
    monsterSearchResults-> addObjectsFromArray(tmpArray);
    tmpArray-> removeAllObjects();
    tmpArray-> release();
    
    if( loreMonsterType != NULL )
    {
        CoolFreeform * tmpFF = new  CoolFreeform();
        tmpFF->initWithCoolSheet(CCString::createWithFormat("%s Monster Listing",type->getCString()), FONT_WHITE ,0.4 ,310 ,true);
        tmpFF->bCenter = true;
        tmpFF-> updatePosition(ccp(240+5,320-5));
        tmpFF-> addToLayer(this,20);
        menuItems-> addObject(tmpFF);
        tmpFF-> release();
        
        /*
         tmpSpt = [[CoolSprite alloc] initWithFile:[NSString stringWithFormat:@"element-%@.png",[type lowercaseString]]];
         [tmpSpt updatePosition:ccp(240,320-25)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:10];
         [menuItems addObject:tmpSpt];
         [tmpSpt release];
         */
        
    }
    else
    {
        
        CoolFreeform * tmpFF = new CoolFreeform();
        tmpFF->initWithCoolSheet(CCString::create("Complete Monster Listing"),FONT_WHITE ,0.4 ,310, true);
        tmpFF->bCenter = true;
        tmpFF-> updatePosition(ccp(240+5,320-5));
        tmpFF-> addToLayer(this,20);
        menuItems-> addObject(tmpFF);
        tmpFF->release();
        
    }
    
    this-> displayMonsterLoreMonstersPage();
}


void gearLayer::displayMonsterLoreMonstersPage()
{
    monsterSprites-> removeAllObjects();
    
    int itemsPerPage = 12;
    int pages = 0;
    if( (double)monsterSearchResults->count()/(double)itemsPerPage != (int)monsterSearchResults->count()/itemsPerPage ) 
    {
        pages = monsterSearchResults->count()/itemsPerPage+1;
    }
    else
    {
        pages = monsterSearchResults->count()/itemsPerPage;
    }
    curMenuType = pages;
    
    CoolFreeform* tmpFF =  new  CoolFreeform();
    tmpFF->initWithCoolSheet(CCString::createWithFormat("Page %d of %d",curPage+1,pages) ,FONT_WHITE ,0.25 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(194+5,320-290));
    tmpFF-> addToLayer(this,20);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    int yStart = 93;
    int count = 0;
    
    for(int i=curPage*itemsPerPage;i<curPage*itemsPerPage+itemsPerPage;i++)
    {
        if(i<monsterSearchResults->count() )
        {
            int x = 0;
            int y = count * 40 + 20;
            if( count >= 6 ) 
            {
                y = (count-6) * 40 + 20;
                x = 240;
            }
            
            dataMonster * mon =  (dataMonster*)monsterSearchResults-> objectAtIndex(i);
            
            if(  parent->monSeen(mon->monid))
            {
                if( parent->monCaught(mon->monid)) 
                {
                    tmpFF ->initWithCoolSheet(CCString::createWithFormat("%s %s", mon->get3DigitNo()->getCString(),mon-> getName()->getCString()), FONT_GREEN ,0.25 ,310 ,true);
                }
                else
                {
                    tmpFF -> initWithCoolSheet(CCString::createWithFormat("%@ %@", mon-> get3DigitNo(),mon-> getName()) ,FONT_RED ,0.25 ,310 ,true);
                }
            }
            else
            {
                tmpFF ->initWithCoolSheet(CCString::createWithFormat("%@ ????????", mon-> get3DigitNo()), FONT_WHITE ,0.25 ,310 ,true);
            }
            
            tmpFF-> updatePosition(ccp(40+x + 52,320-yStart-y+8+50));
            tmpFF-> addToLayer(this,20);
            monsterSprites-> addObject(tmpFF);
            tmpFF-> release();
            
            
            
            CoolSprite* tmpSpt = new  CoolSprite();
            
            tmpSpt->initWithFile(CCString::createWithFormat("element-%s.png",convertedString->lowercaseString((CCString*)parent->getDatabase()->getItemForValue(mon->type1Id))->getCString()));
            tmpSpt-> updatePosition(ccp(40+x + 14,320-yStart-y+50));
            tmpSpt-> updateOpacity(255);
            tmpSpt-> updateScale(0.75);
            tmpSpt-> addToLayer(this,10);
            monsterSprites-> addObject(tmpSpt);
            tmpSpt-> release();
            
            tmpSpt -> initWithFile(CCString::createWithFormat("element-%s.png",convertedString->lowercaseString((CCString*)parent->getDatabase()->getItemForValue(mon->type2Id))->getCString()));
            tmpSpt-> updatePosition(ccp(40+x + 14 + 24,320-yStart-y+50));
            tmpSpt-> updateOpacity(255);
            tmpSpt-> updateScale(0.75);
            tmpSpt-> addToLayer(this,10);
            monsterSprites-> addObject(tmpSpt);
            tmpSpt-> release();
            
        }
        count++;
    }
}


void gearLayer::monsterLoreMonstersTouch(CCPoint touch)
{                                   
    //Back Button
    if( touch.y > 320-48  ) 
    {
        if( touch.x > 480-88 ) 
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            
            if( loreMonsterType != NULL ) 
            {
                loreMonsterType-> release();
                loreMonsterType = NULL;
                
            }
            this-> displayMonsterLoreHome();
        }
    }
    if( touch.y > 0 && touch.y < 35 ) 
    {
        if( touch.x < 88 ) 
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            monsterSprites-> removeAllObjects();
            this-> displayMonsterLoreHome();
            
        }
    }
    
    if( touch.y > 0 && touch.y < 35 )
    {
        if( touch.x > 480-88 ) 
        {
            if( curPage + 1 < curMenuType) 
            {
                curPage++;
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonstersPage();
            }
            else
            {
                curPage = 0;
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonstersPage();
            }
        }
        else if( touch.x > 480-88-88 && touch.x < 480-88 ) 
        {
            if( curPage - 1 >= 0 ) 
            {
                curPage--;
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonstersPage();
            }
            else
            {
                curPage = curMenuType-1;
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonstersPage();
                
            }
        }  
    }
    
    int yStart = 93;
    if( touch.y > 50 && touch.y < 320-93+50 ) 
    {
        int index = touch.y - 87+20;
        index = index * -1 + (320-113+50);
        index = index / 41;
        index=index-1;
        if( touch.x > 240 ) 
        {
            index = index + 6;
        }
        index = index + curPage * 12;
        
        if( index < monsterSearchResults->count() )
        {
            dataMonster* tmpMon = (dataMonster*)monsterSearchResults-> objectAtIndex(index);
            int monid = tmpMon->monid;
            if( parent-> monSeen(monid) )
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonster2(monid);
            }
            return;
        }
        
    }
}


#pragma mark -
#pragma mark ===  MONSTER LIBRARY FUNCTIONS ===
#pragma mark -



void gearLayer::displayMonsterLoreHome()
{
    curPage = 0;
    
    
    menuItems-> removeAllObjects();
    monsterItems-> removeAllObjects();
    monsterPageItems-> removeAllObjects();
    monsterSprites-> removeAllObjects();
    menuStage = 65;
    
    CoolSprite * tmpSpt = new CoolSprite();
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt-> updatePosition(ccp(284,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,9);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt -> initWithFile(CCString::create("bgMenu.png"));
    tmpSpt-> updatePosition(ccp(284,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    CoolFreeform * tmpFF = new CoolFreeform();
    tmpFF->initWithCoolSheet(CCString::create("Monster Library"), FONT_WHITE ,0.5 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(240+5,320-10));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF -> initWithCoolSheet(CCString::create("Browse By Element"), FONT_WHITE ,0.35 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(320+5,320-49));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF -> initWithCoolSheet(CCString::create("View Elemental Poster"), FONT_WHITE ,0.35 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(110+5,320-74));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF -> initWithCoolSheet(CCString::create("Browse Monster List"), FONT_WHITE ,0.35 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(110+5,320-134));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    
    
    //Box 1 - Basic, Water, Fire, Electric
    tmpSpt ->initWithFile(CCString::create("element-basic.png"));
    tmpSpt-> updatePosition(ccp(200 + 49,320-100));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt ->initWithFile(CCString::create("element-water.png"));
    tmpSpt-> updatePosition(ccp(200 + 49+64,320-100));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt ->initWithFile(CCString::create("element-fire.png"));
    tmpSpt-> updatePosition(ccp(200 + 49+64+64,320-100));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt ->initWithFile(CCString::create("element-electric.png"));
    tmpSpt-> updatePosition(ccp(200 + 49+64+64+64,320-100));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpFF -> initWithCoolSheet(CCString::create("Basic"), FONT_WHITE ,0.25 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49,320-100-12));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();   
    
    tmpFF -> initWithCoolSheet(CCString::create("Water"), FONT_WHITE ,0.25 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49+64,320-100-12));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();                           
    
    tmpFF -> initWithCoolSheet(CCString::create("Fire"), FONT_WHITE ,0.25 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49+64+64,320-100-12));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();                           
    
    tmpFF -> initWithCoolSheet(CCString::create("Electric"), FONT_WHITE ,0.25 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49+64+64+64,320-100-12));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();                           
    
    
    
    
    //Box 2 - earth, air, psychic, ghost
    tmpSpt ->initWithFile(CCString::create("element-earth.png"));
    tmpSpt-> updatePosition(ccp(200 + 49,320-100-70));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    tmpSpt ->initWithFile(CCString::create("element-air.png"));
    tmpSpt-> updatePosition(ccp(200 + 49+64,320-100-70));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt ->initWithFile(CCString::create("element-psychic.png"));
    tmpSpt-> updatePosition(ccp(200 + 49+64+64,320-100-70));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    tmpSpt ->initWithFile(CCString::create("element-ghost.png"));
    tmpSpt-> updatePosition(ccp(200 + 49+64+64+64,320-100-70));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpFF -> initWithCoolSheet(CCString::create("Earth"), FONT_WHITE ,0.25 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49,320-100-12-70));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();                        
    
    
    tmpFF -> initWithCoolSheet(CCString::create("Air"), FONT_WHITE ,0.25 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49+64,320-100-12-70));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF -> initWithCoolSheet(CCString::create("Psychic"), FONT_WHITE ,0.25 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49+64+64,320-100-12-70));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();    
    
    tmpFF -> initWithCoolSheet(CCString::create("Ghost"), FONT_WHITE ,0.25 ,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49+64+64+64,320-100-12-70));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();    
    
    
    //Box 3 - earth, air, psychic, ghost
    tmpSpt -> initWithFile(CCString::create("element-steel.png"));
    tmpSpt-> updatePosition(ccp(200 + 49,320-100-70-70));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt -> initWithFile(CCString::create("element-ancient.png"));
    tmpSpt-> updatePosition(ccp(200 + 49+64,320-100-70-70));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpSpt -> initWithFile(CCString::create("element-divine.png"));
    tmpSpt-> updatePosition(ccp(200 + 49+64+64,320-100-70-70));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    tmpSpt -> initWithFile(CCString::create("element-demonic.png"));
    tmpSpt-> updatePosition(ccp(200 + 49+64+64+64,320-100-70-70));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,10);
    menuItems-> addObject(tmpSpt);
    tmpSpt-> release();
    
    
    
    
    tmpFF->initWithCoolSheet(CCString::create("Steel"),FONT_WHITE ,0.25,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49,320-100-12-70-70));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF->initWithCoolSheet(CCString::create("Ancient"),FONT_WHITE ,0.25,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49+64,320-100-12-70-70));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF->initWithCoolSheet(CCString::create("Divine"),FONT_WHITE ,0.25,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49+64+64,320-100-12-70-70));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();   
    
    tmpFF->initWithCoolSheet(CCString::create("Demonic"),FONT_WHITE ,0.25,310 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(200 + 49+64+64+64,320-100-12-70-70));
    tmpFF-> addToLayer(this,20);
    menuItems-> addObject(tmpFF);
    tmpFF-> release();  
    
    
    
    //element-basic.png
    //element-water.png
    //element-fire.png
    //element-electric.png
    //element-earth.png
    //element-air.png
    //element-phychic.png
    //element-ghost.png
    //element-steel.png
    //element-ancient.png
    //element-divine.png
    //element-demonic.png
    
    
    
}

void gearLayer::monsterLoreHomeTouch(CCPoint touch)
{
    
    
    if( touch.y > 0 && touch.y < 35 )
    {
        if( touch.x > 320-88 ) 
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            this-> displayIndex();
        }
    }
    
    if( touch.y > 0 && touch.y < 35 ) 
    {
        if( touch.x < 88 ) 
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            this-> displayIndex();
        }
    }
    
    //110+5,320-74
    if( touch.x < 180 ) 
    {
        if( touch.y > 320-84-20 && touch.y < 320-84+30 ) 
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            this-> displayMonsterLorePoster();
        }
        
        if(  touch.y > 320-144-20 && touch.y < 320-144+30 ) 
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            this-> displayMonsterLoreMonsters(NULL);
        }
    }
    else
    {
        
        if(  touch.y > 320-100-20 && touch.y < 320-100+20 ) 
        {
            if( touch.x > 200 + 49 - 20 && touch.x < 200 + 49 + 20 ) 
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Basic"));
            }
            if( touch.x > 200 +49+64 - 20 && touch.x < 200 +49+64 + 20 ) 
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Water"));
            }
            if( touch.x > 200 +49+64+64 - 20 && touch.x < 200 +49+64+64 + 20 ) 
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Fire"));
            }
            if( touch.x > 200 +49+64+64+64 - 20 && touch.x < 200 +49+64+64+64 + 20 ) 
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Electric"));
            }
        }
        
        if(  touch.y > 320-100-70-20 && touch.y < 320-100-70+20 ) 
        {
            if( touch.x > 200 + 49 - 20 && touch.x < 200 + 49 + 20 ) 
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Earth"));
            }
            if( touch.x > 200 +49+64 - 20 && touch.x < 200 +49+64 + 20 )
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Air"));
            }
            if( touch.x > 200 +49+64+64 - 20 && touch.x < 200 +49+64+64 + 20 ) 
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Psychic"));
            }
            if( touch.x > 200 +49+64+64+64 - 20 && touch.x < 200 +49+64+64+64 + 20 )
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Ghost"));
            }
        }
        
        if(  touch.y > 320-100-70-70-20 && touch.y < 320-100-70-70+20 ) 
        {
            if( touch.x > 200 + 49 - 20 && touch.x < 200 + 49 + 20 ) 
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Steel"));
            }
            if( touch.x > 200 +49+64 - 20 && touch.x < 200 +49+64 + 20 ) 
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Ancient"));
            }
            if( touch.x > 200 +49+64+64 - 20 && touch.x < 200 +49+64+64 + 20 )
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayMonsterLoreMonsters(CCString::create("Divine"));
            }
            if( touch.x > 200 +49+64+64+64 - 20 && touch.x < 200 +49+64+64+64 + 20 )
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this->displayMonsterLoreMonsters(CCString::create("Demonic"));
            }
        }
    }
    
}




#pragma mark -
#pragma mark === SHOP BUY/SELL FUNCTIONS ===
#pragma mark -


void gearLayer::shopItemBuyTouch(CCPoint touch)
{
    if( !bTouchWasSlide ) 
    {
        CCPoint button;
        
        int limit = 0;
        if( bUserIsBuying ) 
        { 
            limit = 990;
            
            limit = parent->coin / itemForTarget->buyPrice;
        }
        else
        {
            limit = (parent->itemCount(itemForTarget->itemid));
        }
        
        button = ccp(240 - 100,160);
        if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
        {
            if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
            {
                if( buySellAmount > 0 ) 
                {
                    if( bUserIsBuying ) 
                    { 
                        if( parent->coin >= (itemForTarget->buyPrice * buySellAmount) )
                        {
                            parent->coin = parent->coin - (itemForTarget->buyPrice * buySellAmount);
                            parent->addItems(itemForTarget->itemid,buySellAmount);
                            this->sfx(CCString::create(SOUND_CONFIRM));
                            this-> popMenu(CCString::createWithFormat("You have bought %d %s's",buySellAmount,itemForTarget-> getName()->getCString()));
                        }
                        else
                        {
                            this->sfx(CCString::create(SOUND_CONFIRM));
                            this-> popMenu(CCString::create("You presently don't have enough Coin."));
                        }
                    }
                    else
                    {
                        parent->coin = parent->coin + (itemForTarget->sellPrice * buySellAmount);
                        parent->useItems(itemForTarget->itemid,buySellAmount);
                        this->sfx(CCString::create(SOUND_CONFIRM));
                        this-> popMenu(CCString:: createWithFormat("You have sold %d %s's",buySellAmount,itemForTarget-> getName()->getCString()));
                    }
                    this->sfx(CCString::create(SOUND_CONFIRM));
                    this-> displayShop(bUserIsBuying);
                }
            }
        }
        //Decr
        button = ccp(240,160);
        if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
        {
            if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
            {
                buySellAmount--;
                if( buySellAmount < 0 ) 
                    buySellAmount = 0;
                this->sfx(CCString::create(SOUND_CONFIRM));
                this->displayShopBuy_Sell();
            }
        }
        
        //Inc
        button = ccp(240 + 100,160);
        if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
        {
            if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
            {
                buySellAmount++;
                
                if( buySellAmount > limit ) 
                    buySellAmount = limit;
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayShopBuy_Sell();
            }
        }
        
        
        //Cancel
        button = ccp(240,160 - 130);
        if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
        {
            if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
            {
                this->sfx(CCString::create(SOUND_CONFIRM));
                this-> displayShop(bUserIsBuying);
            }
        }
    }
}

void gearLayer:: displayShopBuy_Sell()
{
    monsterSprites-> removeAllObjects();
    menuStage = 41;
    
    
    CoolSprite * tmpSpt = NULL;
    CoolFreeform * tmpFF =NULL;
    
    tmpSpt = new CoolSprite() ;
    tmpFF = new CoolFreeform();  
    
    tmpSpt->initWithFile(CCString::create("itemBox.png"));
    tmpSpt-> updatePosition(ccp(240,160));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,50);
    monsterSprites-> addObject(tmpSpt);
    tmpSpt-> release();
    
    if( bUserIsBuying ) 
    {
        
        tmpFF->initWithCoolSheet(CCString::create("Buying"), FONT_WHITE,0.35 ,320 ,true);
    }
    else
    {
        tmpFF -> initWithCoolSheet(CCString::create("Selling"), FONT_WHITE ,0.35 ,320 ,true);
    }
    tmpFF-> updatePosition(ccp(80+46, 160+85));
    tmpFF-> addToLayer(this,51);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    
    if( itemForTarget->itemid >= 13 && itemForTarget->itemid <= 17  )
    {
        tmpFF -> initWithCoolSheet(itemForTarget-> getName(), FONT_GREEN ,0.25 ,320 ,true);
    }
    else
    {
        tmpFF-> initWithCoolSheet(itemForTarget-> getName(), FONT_WHITE,0.25 ,320 ,true);
    }
    tmpFF->bCenter = true;
    tmpFF-> updatePosition( ccp(240, 160+60));
    tmpFF-> addToLayer(this,51);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF -> initWithCoolSheet(itemForTarget-> getScope(),FONT_WHITE ,0.20 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(240, 160+45));
    tmpFF-> addToLayer(this,51);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    if( bUserIsBuying )
    {
        tmpFF ->initWithCoolSheet(CCString::createWithFormat("%d Coin",itemForTarget->buyPrice * buySellAmount) ,FONT_WHITE ,0.30 ,320 ,true);
    }
    else
    {
        tmpFF-> initWithCoolSheet(CCString::createWithFormat("%d Coin",itemForTarget->sellPrice * buySellAmount), FONT_WHITE ,0.30 ,320 ,true);
    }
    tmpFF->bCenter = true;
    tmpFF-> updatePosition( ccp(320-70, 160+75));
    tmpFF-> addToLayer(this,51);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF -> initWithCoolSheet(itemForTarget-> getDescription() ,FONT_WHITE ,0.20 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition( ccp(240, 160-45));
    tmpFF-> addToLayer(this,51);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF -> initWithCoolSheet(CCString:: createWithFormat("x%d",buySellAmount), FONT_WHITE,0.30 ,100 ,true);
    tmpFF-> updatePosition( ccp(320-50+40,160+ 50));
    tmpFF-> addToLayer(this,51);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpFF -> initWithCoolSheet(CCString::createWithFormat("You have %d Coin",parent->coin ), FONT_WHITE ,0.30 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(240,160-60));
    tmpFF-> addToLayer(this,51);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    
    
    //Buttons
    
    tmpSpt -> initWithFile(CCString::create("buttonGreen.png"));
    tmpSpt-> updatePosition(ccp(240 - 100,150));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,51);
    monsterSprites-> addObject(tmpSpt);
    tmpSpt-> release();
    
    if( bUserIsBuying )
    {
        tmpFF -> initWithCoolSheet(CCString::create("Buy"), FONT_WHITE ,0.30 ,320 ,true);
    }
    else
    {
        tmpFF -> initWithCoolSheet(CCString::create("Sell"), FONT_WHITE ,0.30 ,320 ,true);
    }
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(240 - 100,160));
    tmpFF-> addToLayer(this,52);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpSpt ->initWithFile(CCString::create("buttonBlue.png"));
    tmpSpt-> updatePosition(ccp(240,150));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,51);
    monsterSprites-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpFF -> initWithCoolSheet(CCString::create("- Decr"),FONT_WHITE ,0.30 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(240,160));
    tmpFF-> addToLayer(this,52);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();
    
    tmpSpt ->initWithFile(CCString::create("buttonOrange.png"));
    tmpSpt-> updatePosition(ccp(240 + 100,150));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,51);
    monsterSprites-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpFF -> initWithCoolSheet(CCString::create("+ Inc"), FONT_WHITE ,0.30 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(240 + 100,160));
    tmpFF-> addToLayer(this,52);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();                                                                            
    
    //Cancel Button
    
    tmpSpt ->initWithFile(CCString::create("buttonRed.png"));
    tmpSpt-> updatePosition(ccp(240,160 - 130));
    tmpSpt-> updateOpacity(255);
    tmpSpt-> addToLayer(this,51);
    monsterSprites-> addObject(tmpSpt);
    tmpSpt-> release();
    
    tmpFF -> initWithCoolSheet(CCString::create("Cancel"), FONT_WHITE ,0.30 ,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition(ccp(240,160 - 120));
    tmpFF-> addToLayer(this,52);
    monsterSprites-> addObject(tmpFF);
    tmpFF-> release();   
    
    
    
    
    
    
    //itemForTarget
    
}



void gearLayer:: displayShop(bool bBuying)
{
    menuItems->removeAllObjects();
    monsterSprites->removeAllObjects();
    
    bUserIsBuying = bBuying;
    
	menuStage = 40;
    
    team->removeAllObjects();
    CCArray * monsters = parent->getMonsters();
    
    for(int i= 0;i<monsters->count();i++)
    {
        monster * mon=(monster*)((CCArray*)monsters)->objectAtIndex(i); 
        if( mon->position > 0 ) {
            
            if( mon->position >= team->count()) 
            {
                team->insertObject(mon,team->count());
            } else {
                team->insertObject(mon,mon->position-1);
            }
        }
    }
    
    CoolSprite * tmpSpt = NULL;
    CoolFreeform * tmpFF = NULL;
    tmpSpt= new CoolSprite();
    tmpFF= new CoolFreeform();
    
    int titleOffset = 32;
    sliderPosition = 0;
    
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt->updatePosition(ccp(284,160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,30);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();
    
    
    if( bBuying  ) 
    {
        tmpFF->initWithCoolSheet(CCString::create("Items to Buy") ,FONT_WHITE,0.30,320,true);
    } else {
        tmpFF->initWithCoolSheet(CCString::create("Items to Sell"),FONT_WHITE,0.30,320,true);
    }
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(parent->sWidth()/2,320-12));
    tmpFF->intTag1 = 160;
    tmpFF->intTag2 = 12;
    tmpFF->addToLayer(this,32);
    menuItems->addObject(tmpFF);
    tmpFF->release();
    
    CCDictionary * inventory = parent->getItems();
    int count = 0;
    
    if( !bBuying ) 
    {
        //Selling Items
        
        for(int i=0; i<inventory->allKeys()->count();i++)
        {
            CCString * keyName =(CCString*)inventory->allKeys()->objectAtIndex(1);
            int itemId = keyName->intValue();
            int itemInstCount = parent->itemCount( itemId);
            if( itemInstCount > 0 ) 
            {
                
                dataItem * itemData = parent->getDatabase()->itemById(itemId);
                //if( [itemData isBattleItem] ) {
                
                //monsterSelectBox.png
                tmpSpt-> initWithFile(CCString::create("moneybag.png"));
                tmpSpt->updatePosition(ccp(4+16,320- count * 50 + 25 + titleOffset));
                tmpSpt->intTag2 = count * 50 + 25 + titleOffset;
                tmpSpt->updateOpacity(255);
                tmpSpt->addToLayer(this,31);
                menuItems->addObject(tmpSpt);
                tmpSpt->release();
                
                if( itemId >= 13 && itemId <= 17  ) 
                {
                    tmpFF-> initWithCoolSheet(itemData->getName(),FONT_GREEN,0.25,320,true);
                } 
                else
                {
                    tmpFF->initWithCoolSheet(itemData->getName(),FONT_WHITE,0.25,320,true);
                }
                
                tmpFF->updatePosition(ccp(32+8,320- count * 50 + 5 + titleOffset));
                tmpFF->intTag2 = count * 50 + 5 + titleOffset;
                tmpFF->addToLayer(this,32);
                menuItems->addObject(tmpFF);
                tmpFF-> release();
                
                
                tmpFF -> initWithCoolSheet(itemData-> getScope(), FONT_WHITE ,0.20 ,320 ,true);
                tmpFF->bCenter = true;
                tmpFF-> updatePosition(ccp(480-165,320- count * 50 + 5 + titleOffset));
                tmpFF->intTag2 = count * 50 + 5 + titleOffset;
                tmpFF-> addToLayer(this,32);
                menuItems-> addObject(tmpFF);
                tmpFF-> release();
                
                
                tmpFF ->initWithCoolSheet(CCString::createWithFormat("%d Coin",itemData->sellPrice), FONT_WHITE ,0.30 ,320, true);
                tmpFF->bCenter = true;
                tmpFF-> updatePosition( ccp(480-60,320- count * 50 + 25 + titleOffset));
                tmpFF->intTag2 = count * 50 + 25 + titleOffset;
                tmpFF-> addToLayer(this,32);
                menuItems-> addObject(tmpFF);
                tmpFF-> release();
                
                tmpFF -> initWithCoolSheet(itemData-> getDescription(), FONT_WHITE ,0.20 ,320 ,true);
                tmpFF->bCenter = true;
                tmpFF-> updatePosition(ccp(480-165,320- count * 50 + 5 + titleOffset));
                tmpFF->intTag2 = count * 50 + 25 + titleOffset;
                tmpFF-> addToLayer(this,32);
                menuItems-> addObject(tmpFF);
                tmpFF-> release();    
                
                tmpFF ->initWithCoolSheet(CCString::createWithFormat("x%d",itemInstCount), FONT_WHITE ,0.30 ,100, true);
                tmpFF->bCenter = true;
                tmpFF-> updatePosition( ccp(480-90,320- count * 50 + 5 + titleOffset));
                tmpFF->intTag2 = count * 50 + 5 + titleOffset;
                tmpFF-> addToLayer(this,32);
                menuItems-> addObject(tmpFF);
                tmpFF-> release();                      
                count++;
                //}
            }
        }
        itemCount = count;
        if( count > 0)
            count--;
        
    }
    else 
    {
        //Buying Items
        
        CCArray* items = new CCArray;
        items->retain();   
        
        //Basic GeoShocks
        items-> addObject(CCString::create("1"));
        items-> addObject(CCString::create("2"));
        items-> addObject(CCString::create("3"));
        items-> addObject(CCString::create("4"));
        items-> addObject(CCString::create("5"));
        items-> addObject(CCString::create("6"));
        items-> addObject(CCString::create("7"));
        items-> addObject(CCString::create("10"));
        items-> addObject(CCString::create("11"));
        items-> addObject(CCString::create("12"));
        
        //Healing Items
        items-> addObject(CCString::create("13"));
        items-> addObject(CCString::create("14"));
        items-> addObject(CCString::create("15"));
        items-> addObject(CCString::create("16"));
        
        for(int i=0 ;i< items->count();i++)
        {
            CCString* keyName = (CCString*) items->objectAtIndex(i);
            int itemId = keyName->intValue();
            
            dataItem* itemData =  (dataItem*)parent->getDatabase()->itemById(itemId);
            
            tmpSpt ->initWithFile(CCString::create("moneybag.png"));
            tmpSpt-> updatePosition(ccp(4+16,320- count * 50 + 25 + titleOffset));
            tmpSpt->intTag2 = count * 50 + 25 + titleOffset;
            tmpSpt-> updateOpacity(255);
            tmpSpt-> addToLayer(this,31);
            menuItems-> addObject(tmpSpt);
            tmpSpt-> release();
            
            if( itemId >= 13 && itemId <= 17  )
            {
                tmpFF ->initWithCoolSheet(itemData-> getName(), FONT_GREEN ,0.25 ,320 ,true);
            }
            else
            {
                tmpFF -> initWithCoolSheet(itemData-> getName(), FONT_WHITE ,0.25 ,320 ,true);
            }
            
            tmpFF-> updatePosition(ccp(32+8,320- count * 50 + 5 + titleOffset));
            tmpFF->intTag2 = count * 50 + 5 + titleOffset;
            tmpFF-> addToLayer(this,32);
            menuItems-> addObject(tmpFF);
            tmpFF-> release();
            
            tmpFF ->initWithCoolSheet(itemData-> getScope(), FONT_WHITE ,0.20 ,320 ,true);
            tmpFF->bCenter = true;
            tmpFF-> updatePosition(ccp(480-165,320- count * 50 + 5 + titleOffset));
            tmpFF->intTag2 = count * 50 + 5 + titleOffset;
            tmpFF-> addToLayer(this,32);
            menuItems-> addObject(tmpFF);
            tmpFF-> release();
            
            
            tmpFF -> initWithCoolSheet(CCString ::createWithFormat("%d Coin",itemData->buyPrice), FONT_WHITE ,0.30 ,320 ,true);
            tmpFF->bCenter = true;
            tmpFF-> updatePosition(ccp(480-60,320- count * 50 + 25 + titleOffset));
            tmpFF->intTag2 = count * 50 + 25 + titleOffset;
            tmpFF-> addToLayer(this,32);
            menuItems-> addObject(tmpFF);
            tmpFF-> release();                         
            
            tmpFF ->initWithCoolSheet(itemData-> getDescription(), FONT_WHITE ,0.20 ,320 ,true);
            tmpFF-> updatePosition(ccp(32+8,320 - count * 50 + 25 + titleOffset));
            tmpFF->intTag2 =count * 50 + 25 + titleOffset;
            tmpFF-> addToLayer(this,32);
            menuItems-> addObject(tmpFF);
            tmpFF-> release();
            
            tmpFF -> initWithCoolSheet(CCString::create("x999"),FONT_WHITE ,0.30 ,100 ,true);
            tmpFF-> updatePosition(ccp(480-90,320- count * 50 + 5 + titleOffset));
            tmpFF->intTag2 = count * 50 + 5 + titleOffset;
            tmpFF-> addToLayer(this,32);
            menuItems-> addObject(tmpFF);
            tmpFF-> release()  ;
            
            
            count++;
            
        }
        itemCount = count;
        if( count > 0)
            count--;
        
        
        items-> release();
    }
    
    tmpFF -> initWithCoolSheet(CCString::create("Close"), FONT_WHITE ,0.4,320 ,true);
    tmpFF->bCenter = true;
    tmpFF-> updatePosition( ccp(240+104,320- count * 50 + 5 + titleOffset + 48));
    tmpFF->intTag1 = 160+104;
    tmpFF->intTag2 = count * 50 + 5 + titleOffset + 48;
    tmpFF-> addToLayer(this,35);
    menuItems-> addObject(tmpFF);
    tmpFF-> release() ;                                     
    
    this-> shiftSelection();
    
}


void gearLayer::shopItemSelectTouch(CCPoint touch)
{
    
    if( !bTouchWasSlide ) {
        
        //was in the button column
        
        CCDictionary * inventory = parent->getItems();
        int titleOffset = 32;
        int count = 0;
        
        
        if( bUserIsBuying )
        {
            
            
            CCArray * items =  new CCArray();
            //Basic GeoShocks
            items->addObject(CCString::create("1"));
            items->addObject(CCString::create("2"));
            items->addObject(CCString::create("3"));
            items->addObject(CCString::create("4"));
            items->addObject(CCString::create("5"));
            items->addObject(CCString::create("6"));
            items->addObject(CCString::create("7"));
            items->addObject(CCString::create("10"));
            items->addObject(CCString::create("11"));
            items->addObject(CCString::create("12"));
            
            //Healing Items
            items->addObject(CCString::create("13"));
            items->addObject(CCString::create("14"));
            items->addObject(CCString::create("15"));
            items->addObject(CCString::create("16"));
            
            
            
            
            for(int i =0;i<items->count();i++)            
            {
                CCString * keyName = (CCString*)items->count(); 
                int itemId = keyName->intValue();
                //int itemCountInst = [parent itemCount: itemId];
                //if( itemCountInst > 0 ) {
                
                dataItem * itemData = parent->getDatabase()->itemById(itemId);
                //if( [itemData isBattleItem] ) {
                
                
                int monYPos = count * 50 + 25 + titleOffset;
                if( touch.y > 320-(monYPos+sliderPosition)-25 && touch.y < 320-(monYPos+sliderPosition)+25 ) 
                {
                    
                    //TODO: Work out what we need to do with the selected Item.
                    
                    buySellAmount = 1;
                    itemForTarget = itemData;
                    this->sfx(CCString::create(SOUND_CONFIRM));
                    this ->displayShopBuy_Sell();
                    
                    return;
                    
                }
                count++;
                //}
                // }
            }
            
            items->release();
        } 
        else
        {
            for(int i=0; i<inventory->allKeys()->count();i++)
            {
                CCString * keyName = (CCString*)((CCArray*)inventory->allKeys())->objectAtIndex(i);
                int itemId = keyName->intValue();
                int itemCountInst=parent->itemCount(itemId);
                if( itemCountInst > 0 ) 
                {
                    
                    dataItem * itemData = (parent->getDatabase()->itemById(itemId));
                    //if( [itemData isBattleItem] ) {
                    
                    
                    int monYPos = count * 50 + 25 + titleOffset;
                    if( touch.y > 320-(monYPos+sliderPosition)-25 && touch.y < 320-(monYPos+sliderPosition)+25 ) {
                        
                        //TODO: Work out what we need to do with the selected Item.
                        
                        buySellAmount = 1;
                        itemForTarget = itemData;
                        this->sfx(CCString::create(SOUND_CONFIRM));
                        this->displayShopBuy_Sell();
                        return;
                        
                    }
                    count++;
                    //}
                }
            }
        }
        if( count>0)
            count--;
        
        
        //Check for the cancel button
        int monYPos = count * 50 + 25 + titleOffset + 48;
        if( touch.y > 320-(monYPos+sliderPosition)-20 && touch.y < 320-(monYPos+sliderPosition)+20 ) {
            if( touch.x > 240+104-40 && touch.x < 240+104+40 ) {
                //Cancel Item Selection
                
                this->sfx(CCString::create(SOUND_CONFIRM));
                this->hideMenu();
            }
        }
    }
}

#pragma mark -
#pragma mark === TOUCH FUNCTIONS ===
#pragma mark -



void gearLayer::ccTouchesBegan(cocos2d::CCSet *touches, cocos2d::CCEvent *event)
{
    if( bIsActive == false )
        return;
    
    
    
    
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


void gearLayer::ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    if( bIsActive == false )
        return;
    
    
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
    
    
	
	if( convertedpoint.x > touchStartX + 20 ||  convertedpoint.x < touchStartX - 20 || convertedpoint.y > touchStartY + 20 ||  convertedpoint.y < touchStartY - 20 ) {
		bTouchWasSlide = true;
	}
	
	if( bTouchWasSlide ) 
    {
        if( menuStage == 80 || menuStage == 40 )
        {
            sliderPosition = sliderPosition - (convertedpoint.y-touchStartY);
            touchStartY = convertedpoint.y;
            
            if( sliderPosition > 0 ) 
                sliderPosition = 0;
            
            int lowerBarrier = -50 * itemCount - 70 + 320;
            if( lowerBarrier > sliderPosition ) 
                sliderPosition = lowerBarrier;
            
            this->shiftSelection();
        } else if( menuStage == 81 )
        {	
            sliderPosition = sliderPosition - (convertedpoint.y-touchStartY);
            touchStartY = convertedpoint.y;
            
            if( sliderPosition > 0 ) 
                sliderPosition = 0;
            
            int lowerBarrier = -128 * team->count() - 70 + 320;
            if( lowerBarrier > sliderPosition ) 
                sliderPosition = lowerBarrier;
            
            this->shiftSelection();
        } else if(menuStage == 1 ) 
        {
            double slideDist = (convertedpoint.x-touchStartX);
            roationAngle = roationAngle - (slideDist/3);
            this->updateRotation();
            
        }
        
	}
    
	touchStartX = convertedpoint.x;
	touchStartY = convertedpoint.y;
}


void gearLayer::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)

{
    if( bIsActive == false )
        return;
    
    
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
	
	if( convertedpoint.x > touchStartX + 20 ||  convertedpoint.x < touchStartX - 20 || convertedpoint.y > touchStartY + 20 ||  convertedpoint.y < touchStartY - 20 ) {
		bTouchWasSlide = true;
	}
	
	if( bTouchWasSlide == false ) {
		
		if( popItems->count() > 0 ) 
        {
			this->popTouch(convertedpoint);
			return;
		} 
		
		if( menuStage == 1 )
        {
			this->indexTouch(convertedpoint);	
		} 
        else if(menuStage == 5 )
        {
			this->monsterCategoryTouch(convertedpoint);	
		} 
        else if( menuStage == 30 ) {
			this->monsterTouch(convertedpoint);	
		} 
        else if( menuStage == 31 )
        {
			this->monsterStatsTouch(convertedpoint);
		} 
        else if( menuStage == 33 )
        {
			this->statResetTouch(convertedpoint);	
		}
        else if( menuStage == 32 ) 
        {
			this->monsterPositionTouch(convertedpoint);		
        } 
        else if( menuStage == 80 ) 
        {
			this->itemSelectTouch(convertedpoint);	
        } 
        else if( menuStage == 81 ) 
        {
			this->monsterSelectTouch(convertedpoint);	
        } 
        else if( menuStage == 65 )
        {
			this->monsterLoreHomeTouch(convertedpoint);
		} 
        else if( menuStage == 66 )
        {
			this->monsterLorePosterTouch(convertedpoint);
		} 
        else if( menuStage == 67 )
        {
			this->monsterLoreMonstersTouch(convertedpoint);
		} 
        else if( menuStage == 68 )
        {
			this->monsterLoreMonsterTouch(convertedpoint);
		} 
        else if( menuStage == 40 ) 
        {
			this->shopItemSelectTouch(convertedpoint);
		} 
        else if( menuStage == 41 )
        {
			this->shopItemBuyTouch(convertedpoint);
            
            
           
             for(int i=0;i<menuItems->count();i++) 
             {
                 if( typeid(menuItems->objectAtIndex(i))==typeid(CoolInput) ) 
                 {
                     CoolInput * tmpInput =(CoolInput*)menuItems->objectAtIndex(i);
                     if( convertedpoint.y > tmpInput->topLeft.y -5 && convertedpoint.y < tmpInput->topLeft.y + 15 ) 
                     {
                         tmpInput->giveFocus();
                     } 
                     else 
                     {
                         tmpInput->takeFocus();
                     }
                 }
             }
        }
    }
}











