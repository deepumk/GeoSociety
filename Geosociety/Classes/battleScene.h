//
//  battleScene.h
//  Geosociety
//
//  Created by praveen Kumar on 05/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Geosociety_battleScene_h
#define Geosociety_battleScene_h

#include "cocos2d.h"
#include "CoolLabel.h"
#include "CoolSprite.h"
#include "SimpleAudioEngine.h"
#include "CoolInput.h"
#include "CoolFreeform.h"
#include "monsterScene.h"
#include "dataDictionary.h"
#include "gameEvent.h"
#include "menuScene.h"
#include "battleObject.h"
#include "monster.h"
#include "menuScene+Scripts.h"
#include "StringConvertion.h"
#define SOUND_CONFIRM "beep.wav"
#define SOUND_ERROR "LowConfirm.wav"
#define SOUND_ATTACKED "hit.wav"

class menuLayer;
class battleLayer;
class battleObject;

USING_NS_CC;

class battleScene: public::CCScene 
{
	
public:
    
    battleLayer* layer;

    
battleScene* initWithParent(menuLayer* parentObj ,CCArray* data);
void startTimer();
void tick(float dt);
void resignTimer();
};

class battleLayer: public::CCLayer 
{
	
public:
    battleLayer();
    
    CCArray* staticItems;
	CCArray*  menuItems;
	CCArray*  battleItems;
    
    CCArray*  battleEventQueue;
	
    int battleText;
    bool bDisplayingText;
    bool bAnimating;
    int hpStep;
    
    bool bAnimatingAttack;
    int attackAniFrame;
    int attackAniFrameTick;
    int attackAniFrameCount;
    CCSprite* aniSprite;
    
    CoolFreeform* txtAutoBattle;
    bool bAutoBattle;
    
	//buttonEmpty.png
    
	CCArray*  opponents;
	CCArray*  team;
	
	battleObject * fopOpponent1;
	battleObject * fopOpponent2;
	battleObject * fopOpponent3;
	
	battleObject * fopTeam1;
	battleObject * fopTeam2;
	battleObject * fopTeam3;
	
	CCArray*  battleMessages;
	CCArray*  battleAnimations;
	bool bProcessingMessages;
	
	menuLayer * parent;
	battleScene * parentScene;
	int ticker;
    
    bool bCanRun;
    bool bCanTame;
    
    bool bForcedMonsterSelection;
	
	battleObject * attackingPresently;
	double chosenAction;
	double chosenActionArg;
	int chosenActionTarget;
    
	int currentMenu;
    int currentMenuPage;
	bool bAttackMenuDisplayed;
	
    
    //Items Variables
    int itemCount;
    
    dataSkill * skillForTarget;
    
    bool bSelectingTarget;
    bool bSelectingTargetOpponent;
    dataItem * itemForTarget;
    
    bool bBattleWon;
    
    //Monster Page Slider
    int sliderPosition;
    int touchOriginY;
    bool bWasSlide;
	
    StringConvertion* Convertstring;
    void displayTeamAndOpponents();
    void addExpAni(int damage, CCPoint pos);
    void addDamageAni(int  damage,CCPoint  pos);

battleLayer* initWithParent(menuLayer* parentObj,CCArray* data, battleScene* bscene);
    void addHPChange(int targPos,int ourTeam, int from, int to,int dmg,int typeId); 

//Battle Functions

void autoBattleCalculate();
void advanceEachBattler();
void checkForReadyAttackers();
void displayActionMenu() ;
void drawMonsterBar(int mon);
void addMessageToQueue(CCString* msg);
    void AwardExp(int  exp,battleObject * target,int monPos);     
    void addSoundToQueue(CCString * soundName);
    //-(void) addHPChange:(int) targPos andSide:(int) ourTeam andFrom: (int) from andTo: (int) to  andDmg:(int) dmg;

void processBattleQueue() ;

void sfx(CCString* effect);

void toggleAutoBattle();

void evaluate();
    CCPoint positionForTeam(int  oppNo);
    CCPoint positionForOpponent(int  oppNo);
    ~battleLayer();
    bool checkForFaintedAllies();
    void processAttack();
    void processAIAttack();
    void displayFaintedMonsterSelection();
    bool tameCheck(battleObject * target);
    Scripts* scriptScene;
    void changeHpFor(int target,int to); 
    void drawOpponentMonsterBar(int mon);
    void drawAttackSelectPage();
    void drawMonsterSelectPage();
    void drawItemSelectPage();
    void shiftSelection();
    
    void addBattleMessage(CCString * msg);
    
virtual void ccTouchesBegan(cocos2d::CCSet* touches ,cocos2d::CCEvent* event);
virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event); 
virtual void ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event);

};
#endif
