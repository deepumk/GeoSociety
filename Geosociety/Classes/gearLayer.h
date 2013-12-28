//
//  gearLayer.h
//  Geosociety
//
//  Created by macbookpro on 27/11/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Geosociety_gearLayer_h
#define Geosociety_gearLayer_h




#include "cocos2d.h"
//#include "dataDictionary.h"
#include "menuScene.h"
#include "monster.h"
#include "dataDictionary.h"

#define SOUND_CONFIRM "beep.wav"
#define SOUND_ERROR "LowConfirm.wav"
#define SOUND_ATTACKED "hit.wav"

#define FONT_BLACK "alphapixels_black.png"
#define FONT_WHITE "alphapixels_white.png"
#define FONT_GREEN "alphapixels_green.png"
#define FONT_RED "alphapixels_red.png"

/*
 static NSString *featureAId = @"com.greenhillgames.geosociety.onlineplaylobby";
 static NSString *featureBId = @"com.greenhillgames.geosociety.breedingshrine";
 static NSString *featureCId = @"com.greenhillgames.geosociety.threestatresets";
 static NSString *featureDId = @"com.greenhillgames.geosociety.expshare";
 */

//static CCString *featureAId = CCString::create("U9U5YAK62P.com.greenhillgames.geosociety.onlineplaylobby");
//static CCString *featureBId = CCString::create("U9U5YAK62P.com.greenhillgames.geosociety.breedingshrine");
//static CCString *featureCId = CCString::create("U9U5YAK62P.com.greenhillgames.geosociety.threestatresets");
//static CCString *featureDId = CCString::create("U9U5YAK62P.com.greenhillgames.geosociety.expshare");

#define PI 3.14159265358979323846
USING_NS_CC;

class dataItem;
class menuLayer;
class monster;
class monsterScene;
class Scripts;
class StringConvertion;
class gearLayer :  public CCLayer
{
    
public:
    
    ~gearLayer();
    gearLayer();
    
    menuLayer* parent;
    
	CCArray* staticItems;
	CCArray* menuItems;
	CCArray* monsterItems;
    CCArray* monsterSprites;
	CCArray* monsterPageItems;
    CCArray* popItems;
    
	int menuStage;
    double roationAngle;
    
	//Monster Menu Variables
	int curPage;
	int curMenuType;
	CCString* curType;
	CCArray* monsterSearchResults;
	
    
    monster* selMonster;
    Scripts* scriptScene;
    StringConvertion* convertedString;
    
    void updateRotation();
    int atk1;
	int atk2;
	int atk3;
	int atk4;
    
    //Pointsers to menuLayer;
    CCArray* monsters;
    
    
    
    //Inventory Helpers
    dataItem * itemForTarget;
    CCArray * team;
    int sliderPosition;
    int itemCount;
    
    //Monster Lore
    int oldMenuStage;
    CCString* loreMonsterType;
    
    //Touch Helpers
    bool bTouchWasSlide;
	int touchStartX;
	int touchStartY;
    
    //Shop Vars
    bool bUserIsBuying;
    int buySellAmount;
    
    bool bIsActive;
    bool bIsOnPC;
    
    
    bool IAPStatResetFound;
    
    
    void hideMenu() ;
    void sfx(CCString* effect);
    gearLayer *initWithParent(menuLayer * par );
    
    //Monster Functions 
    void drawPageFromSearchArray();
    void drawMonsterCategories(int menuType);
    void displayMonsterLoreHome();
    
    void drawMonster(monster * mon,int i);
     void displayMonster (monster* mon);
    void displayMonsterLoreMonster(int monid);
    //-(void) displayMonsterSkills;
    
    //Inventory Page
    void displayItemSelectPage() ;
    
    //Index Display
    void indexTouch(CCPoint touch);
    void displayIndex();
    
    
    //Shop Front
    void displayShop(bool bBuying);
    
    void displayStatResetOptions();
    void displayMonsterPosition(monster *mon);
    void monsterTouch(CCPoint touch);
    void monsterPositionTouch(CCPoint touch);
    void statResetTouch(CCPoint  touch);
    void displayMonsterStats(monster * mon);
    void monsterStatsTouch(CCPoint touch);
    void popMenu(CCString * text);
    void popTouch(CCPoint touch);
    void shiftSelection();
    void itemSelectTouch(CCPoint touch);
    void monsterSelectTouch(CCPoint  touch);
    void displayMonsterSelectPage();
    void displayMonsterLoreMonster2(int monid);
    void monsterLoreMonsterTouch(CCPoint touch);
    void  displayMonsterLorePoster();
    void monsterLorePosterTouch(CCPoint touch);
    void displayMonsterLoreMonsters(CCString *type);
    void displayMonsterLoreMonstersPage();
    void monsterLoreMonstersTouch(CCPoint touch);
    void monsterLoreHomeTouch(CCPoint touch);
    void shopItemBuyTouch(CCPoint touch);
    void  displayShopBuy_Sell();
    void shopItemSelectTouch(CCPoint touch);
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    void monsterCategoryTouch(CCPoint touch);
    

    
    
};

#endif
