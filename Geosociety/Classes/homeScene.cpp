//
//  homeScene.cpp
//  Geosociety
//
//  Created by Deepak on 19/11/13.
//
//

#include "homeScene.h"
#include "CCDate.h"
#define IS_DEBUG_MODE false
#include "CoolFreeform.h"
#include "CoolSprite.h"
#include "menuScene.h"
#define SOUND_CONFIRM "beep.wav"
#define SOUND_ERROR "LowConfirm.wav"
#define SOUND_ATTACKED "hit.wav"
#define SOUND_DOOR "doorCloseOpen.wav"

#define MUSIC_INTRO "HappyPoppyMusic"
#define MUSIC_BATTLEPLAYER "midnight-ride"
#define MUSIC_BATTLEWILD "jungle-run"
#define MUSIC_HOME "NewGameLoop"
#define MUSIC_EXCITING "iron-man"


#define FONT_BLACK "alphapixels_black.png"
#define FONT_WHITE  "alphapixels_white.png"
#define FONT_GREEN  "alphapixels_green.png"
#define FONT_RED "alphapixels_red.png"

#define UIAlert_ProfileDelete 1

#define control_mode_dynamic    0
#define control_mode_fixed      1
#define control_mode_large      2

#define direction_up            0
#define direction_down          1
#define direction_left          2
#define direction_right         3




bool homeScene::init()
{
//    this->init();
//    
//    if (this!=NULL)
    {
//        layer= new homeLayer();
//        this->addChild(layer,1);
//        layer->startTimer();
    }
    return true;
}



homeScene::homeScene()
{
    layer= new homeLayer();
    this->addChild(layer,1);
    layer->startTimer();
    
   printf("%s",CCString::create("homeScene")->getCString());    
    
}



#pragma mark - Setup and Timers




//
//bool homeLayer::initWithParent(homeScene* par)
//{
//   this->init();
////    
////    if (this!= NULL)
//    {
//        menuItems= new CCDictionary();
//    
//        
//        width= CCDirector::sharedDirector()->getWinSize().width;
//        height=CCDirector::sharedDirector()->getWinSize().height;
//        
//        CCString  *bgName = CCString::create("ghg_logo.png");
//        CCString * backgroundName= CCString::create("background");
//        
//        this->spriteAtPosition(bgName, ccp(width/2, height/2), 1, 0.5, 255,backgroundName);
//        fadeOut=-1;
//        
//        menuItems= new CCDictionary();
//        menuItems->retain();
//        
//        
//    }
//    return true;
//    
//}


homeLayer::homeLayer()
{
    menuItems= new CCDictionary();
    
    
    width= CCDirector::sharedDirector()->getWinSize().width;
    height=CCDirector::sharedDirector()->getWinSize().height;
    
    CCString  *bgName = CCString::create("ghg_logo.png");
    CCString * backgroundName= CCString::create("background");
    
    this->spriteAtPosition(bgName, ccp(width/2, height/2), 1, 0.5, 255,backgroundName);
    fadeOut=-1;
    
    
    
    menuItems= new CCDictionary();
    menuItems->retain();

}


//CCScene  *homeLayer::scene()
//{
//    // 'scene' is an autorelease object
//    CCScene *scene = CCScene::create();
//    
//    // 'layer' is an autorelease object
//    homeLayer *layer = new homeLayer();
//    
//    // add layer as a child to scene
//    scene->addChild(layer);
//    
//    // return the scene
//    return scene;
//}



void homeLayer::resignTimer()
{
    this->unschedule(schedule_selector(homeLayer::tick));
}

void homeLayer::startTimer()
{
    this->schedule(schedule_selector(homeLayer::tick),0.05);
}


void homeLayer::tick(float dt)
{
    if (page==0)
    {
        
        
        if( fadeOut > 15 )
        {
            fadeOut = fadeOut - 10;
          ((CoolSprite*)menuItems->objectForKey("background"))->updateOpacity(fadeOut);
        }
        
        if( fadeOut <= 15 & fadeOut > -1 )
        {
            
            CCDate* date= CCDate::createWithCurrentTime();
            CCString *titleScreen = CCString::create("Title Screen Night.png");
            
            if (date->getHours()>5 && date->getHours()<9)
            {
                titleScreen =  CCString::create("Title Screen Morning.png");
            }
            else
            {
                titleScreen = CCString::create("Title Screen Day.png");
            }
            
            CCString * backgroundName= CCString::create("background");
            CCString * text= CCString::create("text");
            CCString * proceed= CCString::create("proceed");
            
            menuItems->removeAllObjects();
            this->spriteAtPosition(titleScreen, ccp(width/2, height/2), 1, 0.5, 15, backgroundName);
            
            this->freeformAtPosition(proceed, CCString::create(FONT_WHITE), 0.4, 200, true, ccp(width/2,40), 2, text);
            
            
            page++;
            

        }
        
        if( tick_wait == 13 )
        {
            fadeOut = 255;
            tick_wait++;
            return;
        }
    }
    else  if( page == 1 )
    {
        if( fadeOut < 255  )
        {
            fadeOut = fadeOut + 10;
            menuItems->objectForKey("background");
        }
        
    }
    tick_wait++;
}


void homeLayer::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    if( page == 0 )
    {
        if( fadeOut == -1 )
        {
            fadeOut = 255;
        }
    }
    else  if( page == 1 )
    {
        if( fadeOut >= 255  )
        {
            
            this->resignTimer();
//            CCDirector::sharedDirector()->pushScene(menuScene::init());
        }
    }
}




#pragma mark - Support Functions


void homeLayer::freeformAtPosition(CCString* content,CCString* style,float size,int width,bool instant, CCPoint pos, int z, CCString* key)
{
    
    CoolFreeform*tmpFF =     new CoolFreeform();
    tmpFF->initWithCoolSheet(content, style->getCString(), size, width, instant);
    tmpFF->bCenter=true;
    tmpFF->updatePosition(pos);
    tmpFF->addToLayer(this, z);
    menuItems->setObject(tmpFF, key->getCString());
    tmpFF->release();
    
    
}

void homeLayer::spriteAtPosition(CCString *image ,CCPoint pos ,int z,float scale,float opacity,CCString* key)
{   
    
    CoolSprite* tmpSpt;//= new CoolSprite();
    tmpSpt->initWithFile(image);
    tmpSpt->updatePosition(pos);
    tmpSpt->updateOpacity(opacity);
    tmpSpt->addToLayer(this, z);
    tmpSpt->updateScale(scale);
    menuItems->setObject(tmpSpt, key->getCString());
    tmpSpt->release();
    
}
























