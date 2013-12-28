//
//  menuScene.h
//  Geosociety
//
//  Created by Deepak on 21/11/13.
//
//

#ifndef __Geosociety__menuScene__
#define __Geosociety__menuScene__
#include "StringConvertion.h"
#include "CCData.h"
#include "cocos2d.h"
#include "CoolInput.h"
#include "CoolFreeform.h"
#include "SimpleAudioEngine.h"
#include "dataDictionary.h"
#include "gameEvent.h"
#include "gearLayer.h"
#include "questTemplate.h"



#define baseFont "Verdana"



#define IS_DEBUG_MODE false


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
#define FONT_WHITE "alphapixels_white.png"
#define FONT_GREEN "alphapixels_green.png"
#define FONT_RED "alphapixels_red.png"

#define UIAlert_ProfileDelete 1

#define control_mode_dynamic    0
#define control_mode_fixed      1
#define control_mode_large      2

#define direction_up            0
#define direction_down          1
#define direction_left          2
#define direction_right         3



//connMgr * conn;
//menuLayer * g_menuLayer;



USING_NS_CC;
USING_NS_CC_EXT;

class battleScene;
class gameEvent;
class dataDictionary;
class monsterScene;
class CoolLabel;
class CoolSprite;
class CoolInput;
class menuLayer;
class CoolFreeform;
class gearLayer;
class GameEngine;




class menuScene:public CCScene 
{
  

public:
    
    
    menuLayer * layer;

    virtual bool init();
    void tick(float dt);
    void resignTimer();
    void startTimer();
    static CCScene* scene();
    
    
  
};



class menuLayer : public CCLayer
{
   
   public: 
    menuLayer();
    
    ~menuLayer();
    menuScene * parent;
	dataDictionary * database;
	menuLayer* g_menuLayer;
    int accountToDelete;
    GameEngine* gameEngineObj;
    int controlMode;
    
    CCString * zone;
    CCString * weather;
	
	CCString * musicname;
	CCString * oldmusicname;
	
	///PENDING_DEEPAK UIViewController *leaderboardVC;
	
    bool bAutoBattle;
    
	
	CCArray * staticItems;
	CCArray * menuItems;
	CCArray * eventObjects;
	CCArray * activeScript;
	CCArray * globalVariables;
    
    CCArray * zoneMonsters;
    
    
     
    
    
    CCArray * types;
	
	
	int menuStage;
	
	bool bSoundEffects;
	bool bMusicEnabled;
	
	int profileNumber;
	int money,bankMoney;
	int helpTimer;
    
    CCString * lastTriggeredEventName;
	StringConvertion* convertedString;
	//Touch Variables
	bool bTouchWasSlide;
	int touchStartX;
	int touchStartY;
	
	CocosDenshion::SimpleAudioEngine * bgAudio;
	
	//GameEngine Variables
	bool bKeyUp;
	bool bKeyDown;
	bool bKeyLeft;
	bool bKeyRight;
	
	bool bKeyA;
	bool bKeyB;
	bool bKeyC;
    
    bool bKeypadOn;
    CCPoint keypadPosition;
    CoolSprite * btnKeypad;
	
	int heroStepPart;
	int heroDirection;
	
    
    int farmMenuState;
    
	//Weather
	CoolSprite * clouds;
	CoolSprite * glare;
	CoolSprite * redFlash;
	CoolSprite * blackOverlay;
    CoolSprite * blackCover;
    
    CoolSprite * btnRunOn;
    
    
    int fadeTimer;
    
	CCParticleRain * rainEmitter;
	CCParticleSnow * snowEmitter;
	
	
	CCTMXTiledMap * map;
    CCTMXLayer * layerAbove; 
    
	CCString * mapFilename;
	
	int mapLeft;
	int mapTop;
	
	//Menu Transitions
	bool bTransitionHappening;
	bool bFadingOut;
	int fadeFactor;
	
    //Battle Animation
    int aniSlide;
    CCArray * argsCopy;
    
    
	//Battle Logic
	bool bBattleStarted;
	bool bBattleWasWon;
	bool bBattleScriptStarted;
	
    
    //Wild Battles
    int stepTimer;
    
    
  gearLayer * gearMenuLayer;
	
    gameEvent * me;
	CCArray * mapEvents;
	
	//Scripts
	bool bTalkButtonTouched;
	bool bQuestionAnswered;
	
	//Game State Data
	int heroLevel;
    
	int coin;
	CCDictionary * globalSettings;
    CCDictionary * inventory;
    CCArray * monsters;
    CCArray * availableQuests;
    
    int classFilter;
    CCArray * filteredQuests;
    
    
    CCDictionary * monstersSeen;
    CCDictionary * monstersCaught;
    
    int creditsTimer;
    
    
    int questMenu;
    int mapNumber;
    
    bool bIAPShowing;
    bool bIAPPurchasing;
    int IAPResult;
    CCString * IAPErrorMessage;
    
    int statResetsRemaining;
    int expSharePurchased;
    
    int seed;
    
    unsigned long long stepsTaken;
    int missionsAccomplished;
    
    CCPoint btnScalePosition;
    CCPoint btnTalkPosition;
    CCPoint btnRunPosition;
    CCPoint btnMenuPosition;
    
    double gameScale;
    
    
    
    
    CREATE_FUNC(menuLayer);
    
    
  public:  
    void  battleMusicStop();
    void  battleMusicStart(bool bWild);
    CCString*  retrieveFromStdUserDefaults(CCString* arg);
    void saveToStdUserDefaults(CCString* arg, CCString* myString);
    void profileTouch(CCPoint touch);
    void profileDisplay();
    bool isActive();
    double getGameScale();
    void changeGameScaleTo(double newScale);
    void setIAPErrorMessage(CCString* msg);
    void resignTimer();
    void startTimer();
    
    bool mapIsGeoRealm();
    //-(void) addScript:(NSArray *) data ;
    CCArray* getMonsters();

    CCDictionary* getItems();
    
    int questWeather() ;
    int questClass() ;
    
    //-(bool) isNotActive;
    
    //-(bool) monSeen:(int) monid;
    //-(void) sawMonster: (int) monid;
    
    
    //-(void) caughtMonster: (int) monid;
    //-(bool) monCaught:(int) monid;
    
   gameEvent * getUser();
    
    //-(void) addMapEvent: (NSArray *) data ;
    
    int sHeight();
     int sWidth();
    void loadGlobals();
    
    CCPoint userPosition();
    bool isProcessingScript();
    //-(void) eventCheck ;
    void productsHaveLoaded();
    bool saveToUserDefaults(CCString* arg,CCString*myString);
    CCString* retrieveFromUserDefaults(CCString* arg);
    void deleteFromUserDefaults(CCString * arg);
    
    void deleteFromStdUserDefaults(CCString* arg);
    
    
    //-(void) setGlobal:(NSString *) key andValue: (NSString *) value;
    //-(bool) getGlobalBool: (NSString *) key;
    
    //- (NSString * ) stringFromLocalPrice:(SKProduct *) product;
    
    //-(void) addFaintScriptAndKO;
  dataDictionary * getDatabase();
     CCTMXTiledMap * getMap();
    
    void spriteAtPosition(CCString *filename ,CCPoint pos ,int z);
    void freeformAtPosition(CCString *content,CCString *style,float size ,int width,bool instant,CCPoint pos,int z) ;
    
    void sfx(CCString * effect);
    //-(void) popMenu:(NSString *) text andOptions:(int) style;
    
    //-(void) displayMonstersFor: (NSString *) typeName andPage: (int)page ;
    //-(void) indexTouch: (CGPoint) touch;
    
    void playSong(const char* song);
    menuLayer * initWithParent(menuScene * par);
    void evaluate();
    
    //-(void) updateAllDataAsync;
    //-(void) updateAllData;
    
    
    void setControls(int controls);
     
   /* PENDING_DEEPAK void alertView(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;*/
    
    void promptDeleteAccount(int AccountNo);
    
    #pragma mark -
    #pragma mark === menuScene+Touch ===
    #pragma mark -

    
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    bool HitTest(CCPoint hit, CCPoint test, CCSize sizeToTest); 

    
    
    
    #pragma mark -
    #pragma mark === menuScene+Items ===
    #pragma mark -
    
    int itemCount(int itemId);
    void useItems(int itemId, int nTimes );
    void addItems(int itemId, int nTimes );
    int itemIdFromCode(CCString* itemCode);
    void sawMonster (int monid);
    void caughtMonster(int monid);
    bool monCaught(int monid);
    bool monSeen(int monid);
    
    
        #pragma mark -
        #pragma mark === menuScene+Scripts===
        #pragma mark -

    
    bool triggerEvent(gameEvent * event,bool fromCollision);
    void scriptCheck();
    void scriptProgress();
    void scriptTouch(CCPoint touch) ;
    void scriptModifyWithConditionResult(bool bResult) ;
    
    void addScript(CCArray * data);
    void buildQuestFilter();
    gameEvent * eventByName(CCString * eventName);
    void addFaintScriptAndKO();
    //PENDING_DEEPAK CCString *  stringFromLocalPrice(SKProduct * product);
    GameEngine* gameEngine;
    void showCredits();
    bool thereAreQuestsOfClass(int questClass);
    void addMapEvent(CCArray * data);
    void loadQuest();
    
    
        #pragma mark -
        #pragma mark === menuScene+Help===
        #pragma mark -
            

    void displayHelpScreen(bool bSet);
    void helpTick();
    void helpTouch(CCPoint touch);
    CoolFreeform* objectOfCoolFreeform;

    
    
    
    #pragma mark -
    #pragma mark === menuScene+Help===
    #pragma mark -

    void displayGame(CCString * withMap,CCPoint mapPosition);
    void loadAccount();
    void loadMap(CCString * mapName,CCPoint mapPosition) ;
    void arrivedOnTile();
    void displayMenuButton();
    void battleStart(CCArray * args,bool bWild);
    bool tileIsFreeFromEvent(gameEvent * evnt,CCPoint pos);
    bool tileIsFreeFromEvents(CCPoint pos);
    void updateGlobal(CCString *globalName,int action);
    bool globalValue(CCString * globalName);
    void eventCheck();
    void saveAccount();
    void evaluateGame();
    void touchGameStart(CCPoint touch);
    void touchGameStop(CCPoint touch);
    void touchGameSlide(CCPoint touch);
    void resetKeys();
    void setGlobal(CCString * key,CCString * value);
    void setMapCenter();
    bool getGlobalBool(CCString * key);
    CCData * dictToData(CCDictionary * dict);
    CCString*base64forData(CCData*theData); 
    CCDictionary* dataToDict(CCData *data);
    
    

};



#endif /* defined(__Geosociety__menuScene__) */
