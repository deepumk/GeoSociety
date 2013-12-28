//
//  Mainscene.cpp
//  Geosociety
//
//  Created by Deepak on 12/11/13.
//
//

#include "Mainscene.h"
//#include "SelectionScene.h"
#include "menuScene.h"
#include "CCDate.h"
#include "HelloWorldScene.h"
#define klabeltype "font_main_white.fnt"

MainScene::MainScene()
{
    
    winsize= CCDirector::sharedDirector()->getWinSize();
    CCSprite* logo = CCSprite::create("ghg_logo_small.png");
    logo->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(logo ,100);
    logo->runAction(CCFadeOut::create(2));
    
    
    
    
    CCDate* time= CCDate::createWithCurrentTime();
    CCString *titleScreen = CCString::create("Title Screen Night.png");
    
    if (time->getHours()>5 && time->getHours()<9)
    {
        titleScreen =  CCString::create("Title Screen Morning.png");
    }
    else if( time->getHours() >= 9 && time->getHours() < 17 ) {
        titleScreen =CCString::create("Title Screen Day.png");
    }

    else
    {
        titleScreen = CCString::create("Title Screen Day.png");
    }
    

    
    CCSprite* background= CCSprite::create(titleScreen->getCString());
    background->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(background);
    background->setContentSize(CCSizeMake(winsize.width, winsize.height));
    
    cocos2d::extension::CCScale9Sprite *backgroundButton = cocos2d::extension::CCScale9Sprite::create("PlayButton.png");
    cocos2d::extension::CCScale9Sprite *backgroundHighlightedButton = cocos2d::extension::CCScale9Sprite::create("PlayButton.png");
    
    CCLabelBMFont *titleButton = CCLabelBMFont::create("Proceed", klabeltype);
    
    titleButton->setScale(0.9);
    titleButton->setColor(ccWHITE);
    cocos2d::extension::CCControlButton *back = cocos2d::extension::CCControlButton::create(titleButton, backgroundButton);
    back->setBackgroundSpriteForState(backgroundHighlightedButton, cocos2d::extension::CCControlStateHighlighted);
    back->setTitleColorForState(ccMAGENTA, cocos2d::extension::CCControlStateHighlighted);
    
    back->setAnchorPoint(ccp(0.5f, 1));
    back->setPreferredSize(CCSizeMake(114,46));
    
    
//    printf("%f",frameSize.height);
//    printf("%f",frameSize.width);
//    
//    if ((frameSize.height ==640.000000  )&& (frameSize.width==960.000000))
//        
//    {
//        back->setPosition(ccp(back->getContentSize().width/2, size.height));
//        
//    }
//    else if((frameSize.height == 640.000000)&& (frameSize.width==1136.000000))
//    {
//        back->setPosition(ccp(back->getContentSize().width/2, size.height/1.08));
//        
//    }
//    else if((frameSize.height == 1536)&& (frameSize.width==2048))
//    {
//        back->setPosition(ccp(back->getContentSize().width/1.2, size.height));
//        
//    }
//    else if((frameSize.height == 768.000000)&& (frameSize.width==1024.000000))
//    {
//        back->setPosition(ccp(back->getContentSize().width/1.2, size.height));
//        
//    }
//    
//    else
//    {
        back->setPosition(ccp(winsize.width/2.04, winsize.height/6));
//    }
    this->addChild(back, 1);
    
    back->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::blank), cocos2d::extension::CCControlEventTouchDown);
    
    
    back->addTargetWithActionForControlEvents(this,cccontrol_selector(MainScene::gotoselectionScene), cocos2d::extension::CCControlEventTouchUpInside);

    
}


MainScene::~MainScene()
{
    
}



CCScene* MainScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new MainScene();
    scene->addChild(layer);
    layer->release();
    
    return scene;
}





void MainScene::blank()
{
    
}


void MainScene::gotoselectionScene()
{
    CCDirector *pDirector = CCDirector::sharedDirector();
//    CCScene *pScene = SelectionScene::scene();
    
    menuScene* temp= new menuScene();
    temp->init();
    
   pDirector->pushScene(temp);
}



















