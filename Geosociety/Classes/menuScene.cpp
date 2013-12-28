//
//  menuScene.cpp
//  Geosociety
//
//  Created by Deepak on 21/11/13.
//
//

#include "menuScene.h"


bool menuScene:: init()
{
// this->init();
	
//	if( this != NULL) 
	{
		layer = new  menuLayer();//create();
        layer->initWithParent(this);
        
        this->addChild(layer,1);
		printf("%s",CCString::create("menuLayer")->getCString());    
		
		//Create a tick method to be called at the specified interval
  this->startTimer();
	}	
	return this;
}




//
//CCScene *menuScene::scene()
//{
//    // 'scene' is an autorelease object
//    CCScene *scene = CCScene::create();
//    
//    // add layer as a child to scene
//    CCLayer* layer = new menuLayer();
//    scene->addChild(layer);
//    layer->release();
//    
//    return scene;
//}
//
////menuScene::menuScene()
////{
////    
////}


void menuScene::tick(float dt) 
{
	layer->evaluate();
}

void menuScene::resignTimer() 
{
 this->unschedule(schedule_selector(menuScene::tick));
}


void menuScene::startTimer()
{
    
 this->schedule(schedule_selector(menuScene::tick),0.05);
}

#pragma mark -
#pragma mark === MENULAYER ===
#pragma mark -
menuLayer::menuLayer()
{
    
//    this->setTouchEnabled(true);
}


menuLayer::~menuLayer()
{
    
}
void menuLayer::resignTimer()
{
 parent->resignTimer();
}


void menuLayer::startTimer()
{
 parent->startTimer();
}


bool menuLayer::saveToUserDefaults(cocos2d::CCString *arg, cocos2d::CCString *myString)
{
//  PENDING_DEEPAK    NSError *error = nil;
 ///// PENDING_DEEPAK return [SFHFKeychainUtils storeUsername:arg andPassword:myString forServiceName:arg updateExisting:YES error:&error];
    
    CCUserDefault::sharedUserDefault()->setStringForKey(arg->getCString(), arg->getCString());
    return true;
 

}


void menuLayer::saveToStdUserDefaults(cocos2d::CCString *arg, cocos2d::CCString *myString)
{
 CCUserDefault * standardUserDefaults = CCUserDefault::sharedUserDefault();
  
  if (standardUserDefaults) 
  {
    standardUserDefaults->setStringForKey(myString->getCString(), arg->getCString());
  }

}


void menuLayer::deleteFromStdUserDefaults(cocos2d::CCString *arg)
{
   CCUserDefault * standardUserDefaults = CCUserDefault::sharedUserDefault();
   
   if (standardUserDefaults) 
   {
    
    //PENDING_DEEPAK [standardUserDefaults removeObjectForKey:arg];
    
    //PENDING_DEEPAK    [standardUserDefaults synchronize];
   }
   return;
  
}



void menuLayer::deleteFromUserDefaults(CCString * arg)
{
 
 ////// PENDING_DEEPAK NSError *error = nil;
 ////// PENDING_DEEPAK  [SFHFKeychainUtils deleteItemForUsername:arg andServiceName:arg error:&error];
 
 
}


CCString *menuLayer::retrieveFromUserDefaults(CCString *arg)
{
 /* PENDING_DEEPAK
 
   NSError *error = nil;
   NSString * value = [SFHFKeychainUtils getPasswordForUsername:arg andServiceName:arg error:&error];
   return value;*/
    
    std::string temp= CCUserDefault::sharedUserDefault()->getStringForKey(arg->getCString());
    CCString * value= CCString::create(temp);
    return value;
    
    
    
    

}

CCString *menuLayer::retrieveFromStdUserDefaults(cocos2d::CCString *arg)
{
     
    CCUserDefault* standardUserDefaults= CCUserDefault::sharedUserDefault();
    CCString* val = NULL;
     
     if (standardUserDefaults)
     {
         val = CCString::create(CCUserDefault::sharedUserDefault()->getStringForKey(arg->getCString()));
     }
     
     
     return val;
 
}


void menuLayer::freeformAtPosition(cocos2d::CCString *content, cocos2d::CCString *style, float size, int width, bool instant, cocos2d::CCPoint pos, int z)
{
    CoolFreeform * tmpFF = new CoolFreeform();
    
    tmpFF->initWithCoolSheet(content, style->getCString(), size, width, instant);  

    tmpFF->bCenter = true;
    tmpFF->updatePosition(pos);
    tmpFF->addToLayer(this,z);
    menuItems->addObject(tmpFF);
    tmpFF->release();
    
}



void menuLayer::setIAPErrorMessage(cocos2d::CCString *msg)
{
    if( IAPErrorMessage!= NULL) 
    {
        IAPErrorMessage->release();
        IAPErrorMessage = NULL;
    }
    IAPErrorMessage = CCString::create(msg->getCString());
}


void menuLayer::spriteAtPosition(CCString *filename ,CCPoint pos ,int z)
{
    
    
    
    CoolSprite * tmpSpt = new CoolSprite();
    
    tmpSpt->initWithFile(filename);
    tmpSpt->updatePosition(pos);
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,z);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();

}



CCTMXTiledMap *menuLayer::getMap()
{
	return map;
}


void menuLayer::battleMusicStart(bool bWild)
{
    if( oldmusicname != NULL )
    {
        oldmusicname->release();
        oldmusicname=NULL;
    }
    if( musicname != NULL ) {
        oldmusicname  = CCString::create(musicname->getCString());
    }
    if( bWild )
    {
        this->playSong(MUSIC_BATTLEWILD);
    } 
    else 
    {
        this->playSong(MUSIC_BATTLEPLAYER);
    }
}




void menuLayer::battleMusicStop()
{
    this->playSong(oldmusicname->getCString());
    oldmusicname->release();
    oldmusicname=NULL;
}



void menuLayer::playSong(const char *song)
{
    if (this->retrieveFromUserDefaults(CCString::create("MUSIC"))==NULL)
    {
        
    }
    else 
    {
       
		if( (this->retrieveFromUserDefaults(CCString::create("MUSIC")))->isEqual(CCString::create("OFF")))
        {
			return;
		} 
        else
        {
			
		}
        
	}
    
    if( musicname != NULL )
    {
		if( musicname->isEqual(CCString::create(song)))
        {
			return;
		}
	}
	
	if( bgAudio != NULL )
    {
		bgAudio->stopBackgroundMusic();
        bgAudio=NULL;
		bgAudio = NULL;
	}
	
	
	if( musicname != NULL ) {
		musicname->release();
		musicname = NULL;
	}
	musicname = CCString::create(song);
    
    
    bgAudio->playBackgroundMusic(song, -1);
    
	
//	NSString *myExamplePath = [[NSBundle mainBundle] pathForResource:song ofType:@"mp3"]; // *Music filename* is the name of the file that you want to play.  BE SURE that you type the correct characters as the system is case-sensitive.  It caused a crash for me...  Very painful.
//	bgAudio =[[AVAudioPlayer alloc] initWithContentsOfURL:[NSURL fileURLWithPath:myExamplePath] error:nil];
//	bgAudio.delegate = self;
//	[bgAudio prepareToPlay];
//	[bgAudio play];
//	bgAudio.numberOfLoops = -1;    
}



int menuLayer::sHeight()
{
    return   CCDirector::sharedDirector()->getWinSize().height;
}
int menuLayer::sWidth() 
{
    return  CCDirector::sharedDirector()->getWinSize().width;
}
double menuLayer::getGameScale()
{
    return gameScale;
}


CCPoint menuLayer::userPosition()
{
	return me->mapPosition;
}

void menuLayer::changeGameScaleTo(double newScale)
{
    gameScale = newScale;
    
    clouds->updateScale(gameScale);
    blackOverlay->updateScale(gameScale);
    map->setScale(gameScale);
    layerAbove->setScale(gameScale);
    
    
    
    for (int i=0; i<mapEvents->count(); i++)
    {
        gameEvent* event= (gameEvent*)mapEvents->objectAtIndex(i);
        event->scaleTo(gameScale);
       me->scaleTo(gameScale);
    }
    
}


menuLayer* menuLayer::initWithParent(menuScene *par)
{
    statResetsRemaining = 0;
    expSharePurchased = 0;
    gameScale = 1;
    this->setTouchEnabled(true);
    bKeypadOn = false;
    keypadPosition = ccp(-999,-999);
    
    seed = arc4random() %3+1;
    
    zone =  CCString::create("");
    weather = CCString::create("");
    parent = par;
    
    globalSettings =  new CCDictionary();
    globalSettings->retain();
    inventory = new CCDictionary();
    inventory->retain();
    monsters = new CCArray();
    monsters->retain();
    availableQuests = new CCArray();
    availableQuests->retain();
    filteredQuests= new CCArray();
    filteredQuests->retain();
    
    
    
    
    monstersSeen = new CCDictionary();
    monstersSeen->retain();
    monstersCaught = new CCDictionary();
    monstersCaught->retain();
    zoneMonsters= new CCArray();
    zoneMonsters->retain();
    IAPErrorMessage = NULL;
    lastTriggeredEventName = NULL;
    bgAudio = NULL;
    musicname = NULL;
    bSoundEffects = true;
   
   
//    
//  if(  ((CCString*)(this->retrieveFromUserDefaults(CCString::create("SFX"))->getCString()))->isEqual(CCString::create("OFF")) )
//     {
//        bSoundEffects = false;
//    }
//    
//    bMusicEnabled = true;
//  if( ((CCString*)(this->retrieveFromUserDefaults(CCString::create("MUSIC")))->getCString())->isEqual(CCString::create("OFF")))
//  {
//        bMusicEnabled = false;
//    }
//    
    
    
    
    
    
    
  database = new dataDictionary();
    
    mapFilename = new CCString();
    map= new CCTMXTiledMap();
    menuItems = new CCArray();
    menuItems->retain();
    staticItems =new CCArray();
    staticItems->retain();
    mapEvents= new CCArray();
    mapEvents->retain();
    eventObjects=new CCArray();
    eventObjects->retain();
    activeScript =new CCArray();
    activeScript->retain();
    globalVariables = new CCArray();
    globalVariables->retain();
    
    
    this->loadGlobals();
    
    CoolSprite * tmpSpt = new CoolSprite();
    
    int width = this->sWidth();

    
    
    
    
        
        
        
		
        
        /*
         tmpSpt = [[CoolSprite alloc] initWithFile:@"geoMonsters.png"];
         [tmpSpt updatePosition:ccp(width/2,320-268)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:3];
         [staticItems addObject:tmpSpt];
         [tmpSpt release];
         */
		/*
         tmpSpt = [[CoolSprite alloc] initWithFile:@"bg2.png"];
         [tmpSpt updatePosition:ccp(width/2,160)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:2];
         [menuItems addObject:tmpSpt];
         [tmpSpt release];
         
         CoolFreeform * tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Tap To Proceed" fontName:FONT_GREEN fontSize:0.5 andMaxWidth:600 instant:false];
         tmpFF.bCenter = true;
         [tmpFF updatePosition:ccp(width/2,315)];
         [tmpFF addToLayer:self z:3];
         [menuItems addObject:tmpFF];
         [tmpFF release];
         */
		
		types = new CCArray();
        types->retain();
        types->addObject(CCString::create("Fire"));
		types->addObject(CCString::create("Water"));
        types->addObject(CCString::create("Electric"));
        types->addObject(CCString::create("Psychic"));
        types->addObject(CCString::create("Basic"));
        types->addObject(CCString::create("Air"));
        types->addObject(CCString::create("Earth"));
        types->addObject(CCString::create("Ghost"));
        types->addObject(CCString::create("Ancient"));
        types->addObject(CCString::create("Steel"));
        types->addObject(CCString::create("Divine"));
        types->addObject(CCString::create("Demonic"));
        
        
//		this->playSong(MUSIC_INTRO);
		
        me = new gameEvent();       
        me->initSelf(ccp(0,0),this);
		
  if( this->retrieveFromUserDefaults(CCString::create("heroLevel")) == NULL ) 
  {
			heroLevel = 5;
		} else {
			heroLevel = (int)(this->retrieveFromUserDefaults(CCString::create("heroLevel")));
		}
		
  gearMenuLayer = new gearLayer();
  gearMenuLayer->initWithParent(this);
        gearMenuLayer->setPosition(ccp(-2000,0));
        gearMenuLayer->bIsActive = false;
        this->addChild(gearMenuLayer,1000);
        
        this->profileDisplay();
        g_menuLayer = this;
        return this;
    
    
}

int menuLayer::questWeather()
{
    if( questMenu < filteredQuests->count() && filteredQuests->count() != 0 && questMenu >= 0 ) 
    {
      questTemplate * tmp = (questTemplate*)filteredQuests->objectAtIndex(questMenu);
      return tmp->questWeather;
    } 
    else 
    {
        return 0;
    }
        
}
    
int menuLayer::questClass() 
{
    if( questMenu < filteredQuests->count() && filteredQuests->count() != 0 && questMenu >= 0 ) 
    {
        questTemplate * tmp =(questTemplate *)filteredQuests->objectAtIndex(questMenu);
        return tmp->questClass;
    } 
    else 
    {
        return 0;
    }
    
}


CCArray *menuLayer::getMonsters()
{
    return monsters;
}

CCDictionary* menuLayer::getItems()
{
    return inventory;
}







void menuLayer::loadGlobals()
{
    /* PENDING_DEEPAK_NSBundle
	NSString* path = [[NSBundle mainBundle] pathForResource:@"globals" ofType:@"dat"];
	NSString* content = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:NULL];
	
	
	NSArray * globalLines = [content componentsSeparatedByString:@"\n"];
	for(NSString * global in globalLines) {
		if( [global isEqualToString:@""] == false ) {
			NSArray * globalData = [global componentsSeparatedByString:@","];
			[globalVariables addObject:[globalData objectAtIndex:0]];
		}
		
	}*/
	
}



dataDictionary *menuLayer:: getDatabase()
{
	return database;
}

void menuLayer::evaluate()
{
	for(int i=0;i<menuItems->count();i++) 
    {
        
        if (typeid(menuItems->objectAtIndex(i)) == typeid(CoolFreeform) )
        {
            menuItems->objectAtIndex(i);
            this->evaluate();
        }
		if(typeid(menuItems->objectAtIndex(i)) == typeid(CoolFreeform) )
        {
			((CoolFreeform*)menuItems->objectAtIndex(i))->evaluate();
		}
	}
    
    
    
	for(int i=0;i<eventObjects->count();i++) 
    {
		if( typeid(eventObjects->objectAtIndex(i)) == typeid(CoolFreeform))
        {
			((CoolFreeform*)eventObjects->objectAtIndex(i))->evaluate();
		}
	}
	
	
	
	if( menuStage > 99 && menuStage < 200 ) 
    {

          this->helpTick();

	}
	
	if( menuStage == 999 )
    {
         evaluateGame();
	}
}


void menuLayer::sfx(CCString * effect)
{
	if( bSoundEffects ) 
    { 
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(effect->getCString());
	}
}



#pragma mark -
#pragma mark === HOME FUNCTIONS ===
#pragma mark -

bool menuLayer::isActive() 
{
    
 if( gearMenuLayer->bIsActive ) 
    {
        return false;
    }
    
    return true;
}


void menuLayer::profileDisplay()
{
    this->sfx(CCString::create(SOUND_CONFIRM));
    menuStage=1;
    menuItems->removeAllObjects();
    CoolLabel* tmpLbl;
    
    CoolSprite* tmpSpt= new CoolSprite();
    
   tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt->updatePosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, 160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this, 2);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();
    
    
   tmpSpt->initWithFile(CCString::create("profiles.png"));
    tmpSpt->updatePosition(ccp(240, 160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this, 2);
    menuItems->addObject(tmpSpt);
    tmpSpt->release();
    
    
    
    
    CoolFreeform * tmpFF = new CoolFreeform();
	
    int increment = 74;
    int startPoint = 25;
    
    
    
    
    
    for(int i=0;i<3;i++)
    {
		int x = 320/2;
		int y = 0;
		if( i == 0 )
        {
            y = 320-startPoint;
        }
			
        if( i == 1 )
        {
            y = 320-startPoint-increment;
        }
            
        if( i == 2 )
        {
            y = 320-startPoint-increment-increment;
        }
        
        
        //CHANGED_DEEPAK
        
        if( (this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.POSITION",i+1)) == NULL ))
        {
            y=y+10;
            
            
        
            
            CCArray* userPositionArray=((CCArray*)(this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.POSITION",i-1))) /* PENDING_DEEPAK componentsSeparatedByString:@","*/ );
            
            
            CCString * userDataString = (this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.DETAILS",i-1)));
            
            CCString * tmpString = CCString::createWithFormat("Game Save.%d",i+1);
            
            tmpFF->initWithCoolSheet(tmpString, FONT_WHITE, 0.39, 255, true);

            tmpFF->updatePosition(ccp(60,y));
            tmpFF->addToLayer(this,4);
            menuItems->addObject(tmpFF);
            tmpFF->release();
            
            CCString * tmpStr1 = (this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.MISSIONSCOMPLETED",i+1)));
            CCString * tmpStr2 = (this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.MONSTERCOUNT",i+1)));
            CCString * tmpStr3 = (this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.STEPSTAKEN",i+1)));
           
            /* PENDING_DEEPAK USED FOR SEPERTAING NUMBER WITH "," like 1000->1,000
            
            NSNumberFormatter * formatter = [[NSNumberFormatter alloc] init];
            unsigned long long stepsCount = [[formatter numberFromString:tmpStr3] unsignedLongValue];
            [formatter release];
             
             */
            
            tmpFF->initWithCoolSheet((CCString::createWithFormat("%s Missions Complete. %s Monsters.",tmpStr1->getCString(),tmpStr2->getCString())), FONT_WHITE, 0.39, 255, true);
          
            //tmpFF.bCenter = true;
            
            tmpFF->updatePosition(ccp(60,y-25));
            tmpFF->addToLayer(this,4);
            menuItems->addObject(tmpFF);
            tmpFF->release();
        
            /* PENDING _DEEPAK LINKED WITH NSNumberFormatter
            tmpFF = [[CoolFreeform alloc] initWithCoolSheet:[NSString stringWithFormat:@"%qu Steps Taken in Total.",stepsCount] fontName:FONT_WHITE fontSize:0.24 andMaxWidth:255 instant:false];
            //tmpFF.bCenter = true;
            [tmpFF updatePosition:ccp(60,y-40)];
            [tmpFF addToLayer:self z:4];
            [menuItems addObject:tmpFF];
            [tmpFF release];*/
            
            
           tmpSpt->initWithFile(CCString::create("site-ui-trash.png"));
            tmpSpt->updatePosition(ccp(480-75,y-25));
            tmpSpt->addToLayer(this,4);
            menuItems->addObject(tmpSpt);
            tmpSpt->release();
            //
            
        }
        
        else {
            
            y=y+10;
            
            tmpFF ->initWithCoolSheet(CCString::create("Empty Game Save Slot") ,FONT_GREEN,0.4,255,true);
            tmpFF->bCenter = true;
            tmpFF->updatePosition(ccp(240,y));
            tmpFF->addToLayer(this,4);
            menuItems->addObject(tmpFF);
            tmpFF->release();
            
            tmpFF->initWithCoolSheet(CCString::create("Tap here to start a new adventure."),FONT_WHITE,0.25,255,false);
            tmpFF->bCenter = true;
            tmpFF->updatePosition(ccp(240,y-25));
            tmpFF->addToLayer(this,4);
            menuItems->addObject(tmpFF);
            tmpFF->release();
            
        }
	}

    
    
    
	tmpFF->initWithCoolSheet(CCString::create("Sound Settings"),FONT_WHITE,0.25,310,true);
	tmpFF->bCenter = true;
	tmpFF->updatePosition(ccp(400,320-230));
	tmpFF->addToLayer(this,20);
	menuItems->addObject(tmpFF);
	tmpFF->release();
   
    
    
	
    
   tmpSpt->initWithFile(CCString::create("icon_music.png"));
	tmpSpt->updatePosition(ccp(400-30,320-282));
	tmpSpt->updateOpacity(255);
    tmpSpt->updateScale(0.75);
	tmpSpt->addToLayer(this,2);
	menuItems->addObject(tmpSpt);
	if( (this->retrieveFromUserDefaults(CCString::create("MUSIC")) == NULL))
    {
        tmpSpt->updateOpacity(255);
	} 
    else
    {
        
        
		if(this->retrieveFromUserDefaults(CCString::create("MUSIC"))->isEqual(CCString::create("ON")))
        {
            tmpSpt->updateOpacity(255);
		} 
        else
        {
            tmpSpt->updateOpacity(120);
		}
	}
	
    
	tmpSpt->release();   
	
	
   tmpSpt->initWithFile(CCString::create("icon_sfx.png"));
	tmpSpt->updatePosition(ccp(400+30,320-282));
	tmpSpt->updateOpacity(255);
	tmpSpt->addToLayer(this,2);
    tmpSpt->updateScale(0.75);
	menuItems->addObject(tmpSpt);
	if( (this->retrieveFromUserDefaults(CCString::create("SFX"))== NULL))
    {
        tmpSpt->updateOpacity(255);
	} 
    else 
    {
		if(((this->retrieveFromUserDefaults(CCString::create("SFX"))->isEqual(CCString::create("ON"))))) 
        {
            tmpSpt->updateOpacity(255);
		} 
        else 
        {
            tmpSpt->updateOpacity(120);
		}
	}
	tmpSpt->release();
       
    
}
void menuLayer::promptDeleteAccount(int AccountNo)
{
    accountToDelete = AccountNo;
    
    
/* PENDING_DEEPAK     UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Delete Profile?" message:@"Are you sure you want to delete this profile?" delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"Yes", nil];
    alert.tag = UIAlert_ProfileDelete;
	[alert show];
	[alert release]; */
    
    
}




void menuLayer::setControls(int controls)
{
    if( controls == control_mode_fixed )
    {
        bKeypadOn = true;
        keypadPosition = ccp(68,320-256);
        btnKeypad->updatePosition(keypadPosition);
    } 
    else if( controls == control_mode_dynamic ) 
    {
        bKeypadOn = false;
        keypadPosition = ccp(-999,-999);
        btnKeypad->updatePosition(keypadPosition);
        
    } 
    else if( controls == control_mode_large ) 
    {
        bKeypadOn = false;
        keypadPosition = ccp(-999,-999);
        btnKeypad->updatePosition(keypadPosition);
    }
    
    
    //controls
    controlMode = controls;
}

void menuLayer::profileTouch(cocos2d::CCPoint touch)
{
   
	
    int increment = 74;
    int startPoint = 44;
    
    
	if( touch.x > 35 && touch.x < 360 )
    {
        if( touch.y > 320-startPoint-50 && touch.y < 320-startPoint+50 ) 
        {
            profileNumber = 1;
            if( this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.POSITION",1)) != NULL )
            {
                loadAccount();
                // PENDING_DEEPAK [Flurry logEvent:@"Old Game Started"];
                this->sfx(CCString::create(SOUND_CONFIRM));
            } else {
                //New Profile
                statResetsRemaining = 1;
                controlMode = control_mode_fixed;
                displayGame(CCString::create("homeUpper.tmx"), ccp(8,11));
                // PENDING_DEEPAK [Flurry logEvent:@"New Game Started"];
            }
        }
        else if( touch.y > 320-startPoint-increment-50 && touch.y < 320-startPoint-increment+50 ) 
        {
            profileNumber = 2;
            if( this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.POSITION",2)) !=NULL ) 
            {
                loadAccount();
                // PENDING_DEEPAK [Flurry logEvent:@"Old Game Started"];
                this->sfx(CCString::create(SOUND_CONFIRM));

            } 
            else
            {
                //New Profile
                statResetsRemaining = 1;
                controlMode = control_mode_fixed;
                displayGame(CCString::create("homeUpper.tmx"), ccp(8,11));
                // PENDING_DEEPAK [Flurry logEvent:@"New Game Started"];
            }
        } 
        else if( touch.y > 320-startPoint-increment-increment-50 && touch.y < 320-startPoint-increment-increment+50 ) 
        {
            profileNumber = 3;
            if(this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.POSITION",3)) !=NULL )
            {
                loadAccount();
                // PENDING_DEEPAK [Flurry logEvent:@"Old Game Started"];
                this->sfx(CCString::create(SOUND_CONFIRM));
            } 
            else 
            {
                //New Profile
                statResetsRemaining = 1;
                controlMode = control_mode_fixed;
                displayGame(CCString::create("homeUpper.tmx"), ccp(8,11));
                // PENDING_DEEPAK [Flurry logEvent:@"New Game Started"];       
            }
        } 
        else if( touch.y > 480-344-20 && touch.y < 480-344+20 ) 
        {
            
            
        }
        
    }
    else if( touch.x > 360 )
    {
        //delete button
        if( touch.y > 320-startPoint-50 && touch.y < 320-startPoint+50 ) 
        {
            profileNumber = 1;
        } else if( touch.y > 320-startPoint-increment-50 && touch.y < 320-startPoint-increment+50 )
        {
            profileNumber = 2;
        }
        else if( touch.y > 320-startPoint-increment-increment-50 && touch.y < 320-startPoint-increment-increment+50 ) 
        {
            profileNumber = 3;
        }
        
        if(this->retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.POSITION",profileNumber)) !=NULL )
        {
            this->promptDeleteAccount( profileNumber);
        }
        
    }
    
    
	if( touch.y > 320-282-15 && touch.y < 320-282+15 ) 
    {
        if( touch.x > 400-30 - 16 && touch.x < 400-30 + 16 ) 
        {
            this->sfx(CCString::create(SOUND_CONFIRM));
            bool bMusic = false;
            if( this->retrieveFromUserDefaults(CCString::create("MUSIC")) ==NULL )
            {
                bMusic = false;
            } else {
                if( ((CCString*)this->retrieveFromUserDefaults(CCString::create("MUSIC")))->isEqual(CCString::create("ON")))
                {
                    bMusic = false;
                } 
                else
                {
                    bMusic = true;
                }
            }
            
            if( bMusic ) 
            {
                this->saveToUserDefaults(CCString::create("MUSIC"),CCString::create("ON"));
                //PENDING_DEEPAK bgAudio->play();
            } 
            else
            {
                this->saveToUserDefaults(CCString::create("MUSIC"),CCString::create("OFF"));
                bgAudio->stopAllEffects();
            }
            bMusicEnabled = bMusic;
            this->profileDisplay();
        }
        else if( touch.x > 400+30 - 16 && touch.x < 400+30 + 16 ) 
        {
            
            
            this->sfx(CCString::create(SOUND_CONFIRM));
            bool bMusic = false;
            if( this->retrieveFromUserDefaults(CCString::create("SFX")) ==NULL )
            {
                bMusic = false;
            } 
            else 
            {
                if( ((CCString*)this->retrieveFromUserDefaults(CCString::create("SFX")))->isEqual(CCString::create("ON")))
                {
                    bMusic = false;
                } 
                else
                {
                    bMusic = true;
                }
            }
            
            if( bMusic ) 
            {
                this->saveToUserDefaults(CCString::create("SFX"),CCString::create("ON"));
            } 
            else 
            {
                this->saveToUserDefaults(CCString::create("SFX"),CCString::create("OFF"));
            }
            bSoundEffects = bMusic;
            this->profileDisplay();
        }
    }
	
	
	
}



bool menuLayer::mapIsGeoRealm() 
{
    if(map == NULL)
        return false;

    if(map->getProperties() == NULL)//TODO: ANISH
        return false;
    
    CCString * tmpStr =new CCString();
    
   tmpStr=map->propertyNamed("PathSize");
    
    
    
    if( tmpStr == NULL ) 
    {
        return false;
    }
    return true;
}

gameEvent *menuLayer::getUser()
{
    return me;
}
bool menuLayer::isProcessingScript() 
{
    if(activeScript->count()==0)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

#pragma mark -
#pragma mark === CHANGED ===
#pragma mark -

void menuLayer::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    if( gearMenuLayer->bIsActive )
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
	
	if(menuStage == 999 ) 
    {
		touchGameStart(convertedpoint);
	}
}    




void menuLayer::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    
    if( gearMenuLayer->bIsActive )
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
    
    
    if( convertedpoint.x > touchStartX + 20 ||  convertedpoint.x < touchStartX - 20 || convertedpoint.y > touchStartY + 20 ||  convertedpoint.y < touchStartY - 20 )
    {
		bTouchWasSlide = true;
	}
    
    if( bTouchWasSlide == false ) 
    {
		if( menuStage == 0 ) 
        {
			profileDisplay();
		} 
        else if( menuStage == 1 )
        {
			profileTouch(convertedpoint);
		} 
        else if(menuStage == 999 )
        {
			touchGameStop(convertedpoint);
		} 
        else if( menuStage > 99 && menuStage < 200)
        {
			this->helpTouch(convertedpoint);
		}
		
        
        
        
		
		for(int i=0;i< menuItems->count();i++) 
        {
            
            
            
            if( dynamic_cast<CoolInput*>(menuItems->objectAtIndex(i)))       
            {
				CoolInput* tmpInput = (CoolInput* )menuItems->objectAtIndex(i);
				if( (convertedpoint.y > tmpInput->topLeft.y -5) && (convertedpoint.y < tmpInput->topLeft.y + 15) )
                {
					tmpInput-> giveFocus();
				} 
                else 
                {
					tmpInput->takeFocus();
				}
			}
		}
	}
}
bool menuLayer::HitTest(CCPoint hit, CCPoint test, CCSize sizeToTest)
{
    
    if( hit.x > test.x - sizeToTest.width/2 && hit.x < test.x + sizeToTest.width/2 ) 
    {
        if( hit.y > test.y - sizeToTest.height/2 && hit.y < test.y + sizeToTest.height/2 )
        {
            return true;
        }
    }
    return false;
}




void menuLayer::ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    
    
    if( gearMenuLayer->bIsActive )
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
    
 	
   	
	if( convertedpoint.x > touchStartX + 20 ||  convertedpoint.x < touchStartX - 20 || convertedpoint.y > touchStartY + 20 ||  convertedpoint.y < touchStartY - 20 ) 
    {
		bTouchWasSlide = true;
	}
	
	if( bTouchWasSlide ) 
    {
		
		
	}
	
	if(menuStage == 999 ) 
    {
        touchGameSlide(convertedpoint);
	}
}








int menuLayer::itemCount(int itemId) 
{
    CCString* itemCount =(CCString*)inventory->valueForKey("")->intValue();
    if( itemCount == NULL )
        return 0;
    return itemCount ->intValue();
    
    
}



void menuLayer::useItems(int itemId,int nTimes)
{
    CCString * itemCount=(CCString*)inventory->valueForKey(CCString::createWithFormat("%d",itemId)->getCString());
    
    assert( itemCount != NULL );
    assert((itemCount-nTimes)>0);
    
    this->inventory->setObject(CCString::createWithFormat("%d",(itemCount->intValue()-nTimes)),(CCString::createWithFormat("%d",itemId))->getCString());
    
}



void menuLayer::addItems(int itemId , int nTimes)
{
    
    CCString* itemCount=(CCString*)inventory->valueForKey(CCString::createWithFormat("%d",itemId)->getCString()); 
    
    if( itemCount == NULL ) 
    {
        
        this->inventory->setObject(CCString::createWithFormat("%d",(nTimes)),(CCString::createWithFormat("%d",itemId))->getCString());
    }
    else
    {
        this->inventory->setObject(CCString::createWithFormat("%d",(itemCount->intValue()+nTimes)),(CCString::createWithFormat("%d",itemId))->getCString());
    }
}


int menuLayer::itemIdFromCode(CCString* itemCode)
{
    CCArray* tmpRay =new CCArray();
    tmpRay->addObject((CCString*)convertedString->componentsSeparatedByString(itemCode, CCString::create(":")));
    
    return (int)(tmpRay->objectAtIndex(0));
}



bool  menuLayer::monSeen(int monid)
{
    CCString* monSeen = ((CCString*)monstersSeen-> valueForKey(CCString::createWithFormat("%d",monid)->getCString()));
    if( monSeen == NULL )
        return false;
    return true;
}

void menuLayer::sawMonster(int monid)
{
    
    
    if(  monSeen(monid) == false ) 
        this->monstersSeen->setObject(CCString::create("T"), (CCString::createWithFormat("%d",monid)->getCString()));
}


bool menuLayer::monCaught(int monid)
{
    CCString* monSeen =  (CCString*)monstersCaught-> valueForKey(CCString::createWithFormat("%d",monid)->getCString());
    if( monSeen == NULL )
        return false;
    return true;
}

void menuLayer::caughtMonster(int monid)
{
    
    if(  monCaught(monid) == false ) 
        monstersSeen->setObject(CCString::create("T"), (CCString::createWithFormat("%d",monid)->getCString()));
    
}








#pragma mark -
#pragma mark === menuScene+Scripts===
#pragma mark -



gameEvent *menuLayer::eventByName(CCString *eventName)
{
    for(int i=0; i<mapEvents->count();i++)
    {
        gameEvent * evnt= (gameEvent*)mapEvents->objectAtIndex(i);
		if((evnt->getName())->isEqual(eventName)) 
        {
			return evnt;
        }
	}
    return NULL;
}
void menuLayer:: addScript(CCArray * data)
{
   this->activeScript->addObject(data);
}

bool menuLayer::triggerEvent(gameEvent * event,bool fromCollision)
{
	if( event->bEventEnabled )
    {
        
        if( lastTriggeredEventName != NULL )
        {
            lastTriggeredEventName->release();
            lastTriggeredEventName = NULL;
        }
        lastTriggeredEventName = CCString::create(event->getName()->getCString());
        
		CCString * script = CCString::create(event->getScript()->getCString());
		CCArray * scriptLines =  CCArray::create(CCString::create(convertedString->componentsSeparatedByString(script, CCString::create("~"))->getCString()));
        for(int i=0; i<scriptLines->count();i++)
        {
            CCString * functionLine= (CCString*)scriptLines->objectAtIndex(i); 
			if( functionLine->isEqual(CCString::create("")) == false )
            {
				activeScript->addObject((CCString::create(convertedString->componentsSeparatedByString(functionLine, CCString::create("\t"))->getCString())));
			}
		}
		if( activeScript->count() > 0 )
        {
			this->scriptProgress();
			return true;
		} 
        else 
        {
			return false;
		}
		
	}
	return false;
}





void menuLayer::scriptProgress()
{
	//eventObjects
	eventObjects->removeAllObjects();
	
	if( activeScript->count() == 0 )
    {
		return;
	}
	
	CCArray * scriptToExecute = CCArray::create();
    scriptToExecute->retain();
    scriptToExecute->addObject(activeScript->objectAtIndex(0));
    
    
    
    
    CCString* tempString= convertedString->componentsSeparatedByString((CCString*)scriptToExecute->objectAtIndex(0), CCString::create("^"));
    
    
	CCArray * args =  CCArray::create();
    args->retain();
    args->addObject(tempString);
	
	if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Display Message")))
    {
		
		
		CoolSprite * tmpSpt = NULL;
		
		if((((CCString*)args->objectAtIndex(1))->isEqual(CCString::create(""))))
        {
			CoolFreeform * tmpFF = new CoolFreeform();
            tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(0),FONT_WHITE,0.35,360,false);
			tmpFF->updatePosition(ccp(54,320-32));
			tmpFF->addToLayer(this,35);
			eventObjects->addObject(tmpFF);
			tmpFF->release();
		} 
        else 
        {
			CoolFreeform * tmpFF = new CoolFreeform();
            tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(0),FONT_WHITE,0.35,280,false);
			tmpFF->updatePosition(ccp(144,320-32));
			tmpFF->addToLayer(this,35);
			eventObjects->addObject(tmpFF);
			tmpFF->release();
			
			tmpSpt =new CoolSprite();
            tmpSpt->initWithFile((CCString*)args->objectAtIndex(1));
			tmpSpt->updatePosition(ccp(96,320-80));
			tmpSpt->updateOpacity(255);
			tmpSpt->addToLayer(this,36);
			eventObjects->addObject(tmpSpt);
			tmpSpt->release(); 
			
		}
		
		if( ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04.png")))  || ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04-1.png"))) || ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04-2.png")))  || ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04-3.png")))  || ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("80-04-4.png")))) 
        {  //chatBlue.png 80-04.png
			tmpSpt->initWithFile(CCString::create("speechBubble.png"));
		} 
        else 
        {
			tmpSpt->initWithFile(CCString::create("speechBubble.png"));
		}
		tmpSpt->updatePosition(ccp(240,320-80));
		tmpSpt->updateOpacity(255);
		tmpSpt->addToLayer(this,34);
		eventObjects->addObject(tmpSpt);
		tmpSpt->release(); 
		
        bTalkButtonTouched = false;
        
    } 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Monster Farm"))))
    {
        
        farmMenuState = 0;
        
		CoolSprite * tmpSpt = NULL;
        CoolFreeform * tmpFF = NULL;
        
        tmpFF->initWithCoolSheet(CCString::create("What would you like to do?"),FONT_WHITE,0.35,280,true);
        tmpFF->updatePosition(ccp(54,320-32));
        tmpFF->addToLayer(this,35);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpSpt->initWithFile(CCString::create("speechBubble.png"));
        tmpSpt->updatePosition(ccp(240,320-80));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,34);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
        tmpFF->initWithCoolSheet(CCString::create("Return"),FONT_WHITE,0.35,200,false);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240-54,320-80-100));
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpFF ->initWithCoolSheet(CCString::create("Give"),FONT_WHITE,0.35,200,false);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240+54,320-80-100));
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpSpt ->initWithFile(CCString::create("buttonGreen.png"));
        tmpSpt->updatePosition(ccp(240-54,320-80-110));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,36);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
        tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
        tmpSpt->updatePosition(ccp(240+54,320-80-110));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,36);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
        tmpFF->initWithCoolSheet(CCString::create("Leave"),FONT_WHITE,0.35,200,false);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240+54,320-80-100-80));
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpSpt->initWithFile(CCString::create("buttonOrange.png"));
        tmpSpt->updatePosition(ccp(240+54,320-80-110-80));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,36);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Bite"))))
    {
        redFlash->updateOpacity(100);
        redFlash->intTag1 = 100;
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("IAP"))))
    {
        
        bIAPPurchasing = false;
        bIAPShowing = false;
        bQuestionAnswered= false;
        
        
        /* PENDING_DEEPAK  MKStoreManager
         
         if( [MKStoreManager sharedManager].bRequestErrorOccured ) {
         
         [self updateGlobal:@"SYSYesNoAnswer" withAction:0];
         [activeScript removeObjectAtIndex:0];
         [activeScript insertObject:  [[NSString stringWithFormat:@"Display Message\tPlease try again in 30min by restarting the Application.^"] componentsSeparatedByString:@"\t"]  atIndex:0];
         [activeScript insertObject:  [[NSString stringWithFormat:@"Display Message\tErrors occured while Retrieving Product Data.^"] componentsSeparatedByString:@"\t"]  atIndex:0];
         [self scriptProgress];
         
         } else {
         
         //Make a Call to Load the Store.
         [[MKStoreManager sharedManager] setParent: self];
         
         CoolFreeform * tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Retrieving Product Details..." fontName:FONT_WHITE fontSize:0.35 andMaxWidth:200 instant:false];
         [tmpFF updatePosition:ccp(48,320-32)];
         [tmpFF addToLayer:self z:35];
         [eventObjects addObject:tmpFF];
         [tmpFF release];
         
         CoolSprite * tmpSpt = [[CoolSprite alloc] initWithFile:@"speechBubble.png"];
         [tmpSpt updatePosition:ccp(240,320-80)];
         
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:34];
         [eventObjects addObject:tmpSpt];
         [tmpSpt release]; 
         
         } */
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Flash Red"))))
    {
        redFlash->updateOpacity(100);
        redFlash->intTag1 = 100;
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Save Game"))))
    {
        this->saveAccount();
        
        activeScript->removeObjectAtIndex(0);
        this->scriptProgress();
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Change Music"))) )
    {
        playSong(((CCString*)args->objectAtIndex(0))->getCString());
        
        activeScript->removeObjectAtIndex(0);
        this->scriptProgress();
        
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Display Credits"))))
    {
        this->showCredits();
        
        //PENDING_DEEPAK [Flurry logEvent:@"Displayed Credits"];
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Ask Yes or No"))))
    {
        
		CoolSprite * tmpSpt = NULL;
        CoolFreeform * tmpFF = NULL;
        
        
        
        tmpFF->initWithCoolSheet(CCString::create("Yes"),FONT_WHITE,0.35,200,false);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240-54,320-80-100));
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpFF->initWithCoolSheet(CCString::create("No"),FONT_WHITE,0.35,200,false);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240+54,320-80-100));
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        
        tmpSpt->initWithFile(CCString::create("buttonGreen.png"));
        tmpSpt->updatePosition(ccp(240-54,320-80-110));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,36);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
        tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
        tmpSpt->updatePosition(ccp(240+54,320-80-110));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,36);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
		bQuestionAnswered = false;
        bTalkButtonTouched = false;
        
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Mutate Monster at Position"))))
    {
        CoolSprite * tmpSpt = NULL;
        for(int i=0; i<monsters->count();i++)
        {
            monster * mon=(monster*)monsters->objectAtIndex(i); 
            if( mon->position == ((int)args->objectAtIndex(0)))
            {
                if( mon->lvl >= mon->getMonster()->evolvelvl)
                {
                    
                    /* PENDING_DEEPAK Flurry
                     [Flurry logEvent:@"Monster Evolved" withParameters:
                     [NSDictionary dictionaryWithObjectsAndKeys:
                     [NSString stringWithFormat:@"%d",[mon getMonster].monid],@"Monster Id",
                     [mon getName],@"Monster Name",
                     nil] ];*/
                    
                    
                    sawMonster(mon->getMonster()->evolvesto);
                    caughtMonster(mon->getMonster()->evolvesto);
                    
                    tmpSpt->initWithFile(mon->getImage());
                    tmpSpt->updatePosition(ccp(240,320-120));
                    tmpSpt->intTag1 = 255;
                    tmpSpt->updateOpacity(255);
                    tmpSpt->addToLayer(this,36);
                    eventObjects->addObject(tmpSpt);
                    tmpSpt->release(); 
                    
                    dataMonster * evoTo = database->monById(mon->getMonster()->evolvesto);
                    tmpSpt->initWithFile(evoTo->getImage());
                    tmpSpt->intTag1 = 0;
                    tmpSpt->updatePosition(ccp(240,320-120));
                    tmpSpt->updateOpacity(0);
                    tmpSpt->addToLayer(this,36);
                    eventObjects->addObject(tmpSpt);
                    tmpSpt->release(); 
                    
                    mon->evolve(database);
                    
                }
            }
        }
        
        
	} else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Play Sound"))))
    {
        if( ((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Door"))))
        {
            sfx(CCString::create(SOUND_DOOR));
        }
        
        activeScript->removeObjectAtIndex(0);
        this->scriptProgress();
        
        
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Start Storyline Mission"))))
    {
        
        questTemplate * tmpQuest = NULL;
        
        for(int i=0; i<availableQuests->count();i++)
        {
            questTemplate * tmpQ= (questTemplate*)availableQuests->objectAtIndex(i); 
            if( tmpQ->missionCode == ((int)args->objectAtIndex(0)))
            {
                tmpQuest = tmpQ;
            }
        }
        
        if( tmpQuest == NULL ) 
        {
            tmpQuest->initWithParent(this,3, 2);
            availableQuests->addObject(tmpQuest);
            tmpQuest->release();
        }
        
        tmpQuest->setupEvents();
        
        CCString * tmpStr =NULL;
        
        tmpQuest->reloadWithParent( g_menuLayer);
        
        
        tmpStr = CCString::createWithFormat("Fade Out\t^"); 
        this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
        
        
        tmpStr =CCString::createWithFormat("Relocate User\t%@^%d^%d",tmpQuest->getMapName() , (int)tmpQuest->startingPoint.x , (int)tmpQuest->startingPoint.y); 
        this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
        
        if( tmpQuest->questWeather == 0 ) 
        {
            tmpStr = CCString::createWithFormat("Change Weather\tGlare^"); 
        } 
        else if( tmpQuest->questWeather == 1 ) 
        {
            tmpStr = CCString::createWithFormat("Change Weather\tLight Rain^"); 
        }
        else if( tmpQuest->questWeather == 2 ) 
        {
            tmpStr = CCString::createWithFormat("Change Weather\tHeavy Rain^"); 
        } 
        else if( tmpQuest->questWeather == 3 ) 
        {
            tmpStr =CCString::createWithFormat("Change Weather\tNight^"); 
        } 
        else if( tmpQuest->questWeather == 4 ) 
        {
            tmpStr = CCString::createWithFormat("Change Weather\tNight Rain^"); 
        } 
        else if( tmpQuest->questWeather == 5 )
        {
            tmpStr = CCString::createWithFormat("Change Weather\tSnow^"); 
        }
        else 
        {
            tmpStr = CCString::createWithFormat("Change Weather\tNormal^"); 
        }
        this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
        
        tmpStr = CCString::createWithFormat("Set Zone\t%s^",tmpQuest->getZoneName()->getCString()); 
        this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
        
        tmpStr = CCString::createWithFormat("Fade In\t^"); 
        this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
        
        if( tmpQuest->questStory == 3 ) 
        {
            
            
            tmpStr = CCString::createWithFormat("IF\tGlobal Variable^SYS.ZombieModeBefore^F"); 
            this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
            
            tmpStr = CCString::createWithFormat("Display Message\tThis is a Zombie Artifact Mission. Search and Destroy the Zombie Artifact.^"); 
            this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
            
            tmpStr = CCString::createWithFormat("Display Message\tAvoid the Zombies as best you can. Your monsters health will decrease each time you are bitten.^"); 
            this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
            
            tmpStr = CCString::createWithFormat("Display Message\tThe Zombie artifact looks like a glowing green Zombie.^"); 
            this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
            
            tmpStr =CCString::createWithFormat("Update Variable\tSYS.ZombieModeBefore^T"); 
            this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
            
            tmpStr = CCString::createWithFormat("ELSE\t^"); 
            this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
            
            tmpStr =CCString::createWithFormat("END IF\t^"); 
            this->addScript((CCArray*)((CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t"))->getCString()));
        }
        
        questMenu = availableQuests->count()-1;
        
        /* PENDING_DEEPAK
         [Flurry logEvent:@"Quest Started" withParameters:
         [NSDictionary dictionaryWithObjectsAndKeys:
         [NSString stringWithFormat:@"%d",tmpQuest.questStory],@"Quest Type",
         [NSString stringWithFormat:@"%d",tmpQuest.questClass],@"Quest Class",
         [NSString stringWithFormat:@"%d",tmpQuest.missionCode],@"Quest Mission Code",
         [NSString stringWithFormat:@"%d",tmpQuest.type1Id],@"Type 1",
         [NSString stringWithFormat:@"%d",tmpQuest.type2Id],@"Type 2",
         nil] ];
         
         */
        
        
        activeScript->removeObjectAtIndex(0);
        sfx(CCString::create(SOUND_CONFIRM));
        this->scriptProgress();
        
	}
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Allow Save"))))
    {
        this->displayMenuButton();
        
        activeScript->removeObjectAtIndex(0);
        this->scriptProgress();
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Ask Question - Two Answers"))))
    {
        
		CoolSprite * tmpSpt = NULL;
        CoolFreeform * tmpFF = NULL;
        
        
        tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(0),FONT_WHITE,0.35,280,true);
        tmpFF->updatePosition(ccp(54,320-32));
        tmpFF->addToLayer(this,35);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpSpt->initWithFile(CCString::create("speechBubble.png"));
        tmpSpt->updatePosition(ccp(240,320-80));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,34);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
        tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(1),FONT_WHITE,0.35,200,false);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240-54,320-80-100));
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpFF->initWithCoolSheet((CCString*)args->objectAtIndex(2),FONT_WHITE,0.35,200,false);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240+54,320-80-100));
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpSpt->initWithFile(CCString::create("buttonGreen.png"));
        tmpSpt->updatePosition(ccp(240-54,320-80-110));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,36);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
        tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
        tmpSpt->updatePosition(ccp(240+54,320-80-110));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,36);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
		bQuestionAnswered = false;
        bTalkButtonTouched = false;
        
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Full Restore"))))
    {
        for(int i=0; i<monsters->count();i++)
        {
            monster * mon= (monster*)monsters->objectAtIndex(i);
            mon->hpLeft = mon->hp;
        }
        
        
        activeScript->removeObjectAtIndex(0);
        this->scriptProgress();
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Fade In"))))
    {
        fadeTimer = 255;
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Fade Out"))))
    {
        fadeTimer = 0;
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Update Variable"))))
    {
		
		//updateGlobal
		
		if(((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("F"))))
        {
			this->updateGlobal(((CCString*)args->objectAtIndex(1)), 0);
            
		} 
        else if(((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("T"))))
        {
			this->updateGlobal(((CCString*)args->objectAtIndex(1)),  1);
		}
        else 
        {
			this->updateGlobal(((CCString*)args->objectAtIndex(1)),  2);
		}
		
		activeScript->removeObjectAtIndex(0);
		this->scriptProgress();
	}
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Relocate User"))))
    {
		if( !bTransitionHappening ) 
        {
			bFadingOut = true;
			fadeFactor = 255;
			bTransitionHappening = true;
		}
		
		if( bFadingOut )
        {
			fadeFactor = fadeFactor - 20;
			if( fadeFactor < 15 ) {
				fadeFactor = 0;
				bFadingOut = false;
				this->loadMap((CCString*)args->objectAtIndex(0),ccp((int)((CCString*)args->objectAtIndex(1)),(int)args->objectAtIndex(2)));
			}
		} 
        else 
        {
			fadeFactor = fadeFactor + 20;
			if( fadeFactor > 240 ) 
            {
				fadeFactor = 255;
				bTransitionHappening = false;
			}
		}
        
        if( layerAbove != NULL )
            //PENDING_DEEPAK layerAbove->setOpacity(fadeFactor);
            //PENDING_DEEPAK	map->setOpacity(fadeFactor);
            
            
            if( !bTransitionHappening )
            {
                activeScript->removeObjectAtIndex(0);
                this->scriptProgress();
            }
		
	} else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Change Event"))))
    {
        
        gameEvent * evnt = this->eventByName((CCString*)args->objectAtIndex(0));
        evnt->updateImage((CCString*)args->objectAtIndex(1));
        
        activeScript->removeObjectAtIndex(0);
        this->scriptProgress();
        
	} else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Change Weather"))))
    {
        //CHANGED_DEEPAK
//		snowEmitter->resetSystem();
//		snowEmitter->stopSystem();
		
//        weather->release();
        weather = NULL;
         weather = CCString::create(((CCString*)args->objectAtIndex(0))->getCString());
        
		if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Normal")))
        {
            
            
			clouds->updateOpacity(0);
			blackOverlay->updateOpacity(0);
			glare->updateOpacity(0);
			rainEmitter->stopSystem();
		} 
        else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Night")))
        {
            clouds->updateOpacity(255);
			blackOverlay->updateOpacity(100);
			glare->updateOpacity(0);
			rainEmitter->stopSystem();
            
            
		} else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Glare")))
        {
            clouds->updateOpacity(0);
			blackOverlay->updateOpacity(0);
			glare->updateOpacity(255);
			rainEmitter->stopSystem();
            
        }
        else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Light Rain")))
        {
            
            clouds->updateOpacity(255);
			blackOverlay->updateOpacity(60);
			glare->updateOpacity(0);
            rainEmitter->setEmissionRate(20);
			rainEmitter->stopSystem();
            
		} 
        else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Heavy Rain")))
        {
            
            clouds->updateOpacity(255);
			blackOverlay->updateOpacity(90);
			glare->updateOpacity(0);
            rainEmitter->setEmissionRate(60);
			rainEmitter->stopSystem();
		}
        else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Night Rain")))
        {      
            clouds->updateOpacity(255);
			blackOverlay->updateOpacity(100);
			glare->updateOpacity(0);
            rainEmitter->setEmissionRate(40);
			rainEmitter->stopSystem();
            
		} 
        else if((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Snow")))
        {
            clouds->updateOpacity(80);
			blackOverlay->updateOpacity(80);
			glare->updateOpacity(0);
            rainEmitter->stopSystem();
			snowEmitter->stopSystem();
            
		} 
		activeScript->removeObjectAtIndex(0);
		this->scriptProgress();
	}
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Move Event"))))
    {
		if( (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("USER")))
        {
            me->addMoveQueue((CCString*)args->objectAtIndex(1));
		} 
        else 
        {
            for(int i=0;i<mapEvents->count();i++)
            {
                gameEvent * evnt=(gameEvent*)mapEvents->objectAtIndex(i);
                if((evnt->getName())->isEqual(((CCString*)args->objectAtIndex(0))))
                {
                    evnt->addMoveQueue((CCString*)args->objectAtIndex(1));
				}
			}
		}
		activeScript->removeObjectAtIndex(0);
		this->scriptProgress();
    }
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Sync All Events"))))
    {
		bool bHasMovers = false;
		if( me->moveQueueSize() > 0 )
        {
			bHasMovers = true;
		}
        for(int i=0;i<mapEvents->count();i++)
        {
            gameEvent * evnt= (gameEvent*)mapEvents->objectAtIndex(i);
			if( evnt->moveQueueSize() > 0 )
            {
				bHasMovers = true;
			}
		}
		if( bHasMovers == false ) 
        {
			activeScript->removeObjectAtIndex(0);
			this->scriptProgress();
		}
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Start Battle"))))
    {
        if( IS_DEBUG_MODE )
        {
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
            return;
        }
        
		//When a battle finishes scriptProgress should be called.
		if( !bBattleScriptStarted ) 
        { 
            
            this->battleStart(args,false);
            bBattleScriptStarted = true;
		} 
        else
        {
			bBattleStarted = false;
            bBattleScriptStarted = false;
			activeScript->removeObjectAtIndex(0);
			this->scriptProgress();
		}
		
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("IF"))))
    {
        if( (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Global Variable")))
        {
            bool bResult = this->globalValue((CCString*)args->objectAtIndex(1));
            if((bResult == true && (CCString*)args->objectAtIndex(2)->isEqual(CCString::create("T"))) || (bResult == false && (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("F"))))
            {
                this->scriptModifyWithConditionResult(true);
            } 
            else 
            {
                this->scriptModifyWithConditionResult(false);
            }
        }
        else if( (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Item Count")))
        {
            int itemCount = this->itemCount(this->itemIdFromCode((CCString*)args->objectAtIndex(1)));
            
            int needAtLeast;
            if( (CCString*)args->objectAtIndex(0)->isEqual(CCString::create("At Least One")))
            {
                needAtLeast = 1;
            } 
            else 
            {
                needAtLeast = convertedString->stringByReplacingOccurrencesOfString(((CCString*)args->objectAtIndex(2))->getCString(), "Exactly ", "")->intValue();
            }             
            
            if( itemCount >= needAtLeast ) 
            {
                this->scriptModifyWithConditionResult( true);
            } 
            else 
            {
                this->scriptModifyWithConditionResult(false);
            }
        } 
        else if( ((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Coin Held"))))
        {
            if( ((CCString*)args->objectAtIndex(1)->isEqual(CCString::create("Equal or Greater Than"))))
            {
                
                int needAtLeast = ((CCString*)args->objectAtIndex(1))->intValue();
                
                if( coin >= needAtLeast )
                {
                    this->scriptModifyWithConditionResult(true);
                } 
                else 
                {
                    this->scriptModifyWithConditionResult( false);
                }
                
            } 
            else 
            {
                assert(0);
            }
        } 
        else if( ((CCString*)args->objectAtIndex(0)->isEqual(CCString::create("Quests Completed"))) )
        {
            //PENDING_DEEPAK [Flurry logEvent:@"Quest Complete"];
            
            CCArray * conditions =  CCArray::create((CCString::create(convertedString->componentsSeparatedByString((CCString*)args->objectAtIndex(2), CCString::create("."))->getCString()))); 
            int targetAmt = (int)conditions->objectAtIndex(0);
            int classes = (int)conditions->objectAtIndex(1);
            
            int countOfClass = 0;
            for(int i=0; i<availableQuests->count();i++)
            {
                questTemplate * tmp= (questTemplate*)availableQuests->objectAtIndex(i); 
                if( tmp->questClass == classes)
                    countOfClass++;
            }
            
            if( countOfClass >= targetAmt ) 
            {
                this->scriptModifyWithConditionResult(true);
            } 
            else 
            {
                this->scriptModifyWithConditionResult(false);
            }
        }
        
        
        
        /*
         Global Variable - Done
         Item Count - Done
         Coin Held - Done
         Monster Tamed Count
         Monster Defeated Count
         Quests Completed
         */
        
        
        
	}
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Shop - Buy"))))
    {
        
        this->resetKeys();
         gearMenuLayer->bIsActive = true;
         gearMenuLayer->bIsOnPC = false;
        gearMenuLayer->displayShop( true);
        gearMenuLayer->setPosition(ccp(0,0));
        
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Shop - Sell"))))
    {
        
        this->resetKeys();
        gearMenuLayer->bIsActive = true;
        gearMenuLayer->bIsOnPC = false;
         gearMenuLayer->displayShop( false);
         gearMenuLayer->setPosition(ccp(0,0));
        
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("ELSE"))))
    {
		//[activeScript removeObjectAtIndex:0];
		//[self scriptProgress];
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("END IF"))))
    {
		//[activeScript removeObjectAtIndex:0];
		//[self scriptProgress];
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Call Event"))))
    {
        //activeScript
        
		activeScript->removeObjectAtIndex(0);
        
        for(int i=0; i<mapEvents->count();i++)
        {
            gameEvent * evnt = (gameEvent*)mapEvents->objectAtIndex(i);
            if( (CCString::create(convertedString->lowercaseString(evnt->getName())->getCString()))->isEqual(CCString::create(convertedString->lowercaseString((CCString*)args->objectAtIndex(0))->getCString())))
            {
                
                CCString * script =  CCString::create(evnt->getScript()->getCString());
                CCArray * scriptLines = CCArray::create(CCString::create(convertedString->componentsSeparatedByString(script, CCString::create("~"))->getCString()));
                int count = 0;
                for(int i=0; i<scriptLines->count();i++ )
                {
                    CCString * functionLine= (CCString*)scriptLines->objectAtIndex(i); 
                    if(  functionLine->isEqual(CCString::create("")) == false ) 
                    {
                        activeScript->insertObject( CCString::create(convertedString->componentsSeparatedByString(functionLine, CCString::create("\t"))->getCString()),count);
                        count++;
                    }
                }
            }
        }
        
		this->scriptProgress();
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))-> isEqual(CCString::create("Quest Add")))
    {
        
        
        if( (int)args->objectAtIndex(0) == 1 ) 
        {
            //Add the initial Dark Base Raid
            
            questTemplate * newQuest = new questTemplate();
            newQuest->initWithParent(g_menuLayer,1, 1);
             availableQuests->addObject(newQuest);
            newQuest->release();
        } 
        else if( (int)args->objectAtIndex(0) == 2 )
        {
            //Add the second Dark Base Raid
            
            questTemplate * newQuest = new questTemplate();
            newQuest->initWithParent(g_menuLayer,3, 2);
            availableQuests->addObject(newQuest);
            newQuest->release();
        } 
        else if( (int)args->objectAtIndex(0) == 3 )
        {
            //Add the final boss battle Mission
            questTemplate * newQuest = new questTemplate();
            newQuest->initWithParent(g_menuLayer,4, 3);
            availableQuests->addObject(newQuest);
            newQuest->release();
            
        } 
        
		activeScript->removeObjectAtIndex(0);
		this->scriptProgress();
        
	} else if( ((CCString*)scriptToExecute->objectAtIndex(0))-> isEqual(CCString::create("Quest Completed")) )
    {
        
        missionsAccomplished++;
        
        if( filteredQuests->count() > 0 ) 
        {
            if( questMenu < filteredQuests->count() && questMenu >= 0 ) 
            {
                questTemplate * tmpQuest = (questTemplate*)filteredQuests->objectAtIndex(questMenu);
                tmpQuest->bCompleted = true;
                
                //Generate more missions of the same class.
                activeScript->insertObject((CCString::create(convertedString->componentsSeparatedByString(CCString::createWithFormat("Generate Quests\t%d^",tmpQuest->questClass), CCString::create("\t"))->getCString())),1);
                
            }
        }
        
		activeScript->removeObjectAtIndex(0);
		this->scriptProgress();
	}
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Generate Quests")))
    {
        int questsToCreate = arc4random() % 2 + 1;
        //Between 1 and 2
        
        int questClass = -1;
        if( args->count() > 0 ) 
        {
            if( ((CCString*)args->objectAtIndex(0))-> isEqual(CCString::create("")) == false ) 
            {
                questClass = ((CCString*)args->objectAtIndex(0))->intValue();
            }
        }
        
        //questTemplate
        for(int i=0;i<questsToCreate;i++) 
        {
            questTemplate * newQuest =  new questTemplate();
            newQuest->initWithParent(g_menuLayer,questClass, 0);
            availableQuests->addObject(newQuest);
            newQuest->release();
        }
        
		activeScript->removeObjectAtIndex(0);
		this->scriptProgress();
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Quest Selection")))
    {
        
        if( availableQuests->count() ==0 ) 
        {
            questTemplate * newQuest = new questTemplate();
            newQuest->initWithParent(g_menuLayer,-1,0);
            availableQuests->addObject(newQuest);
            newQuest->release();
        }
        
        questMenu = 0;
        this->loadQuest();
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Add Monster")))
    {
        bTalkButtonTouched = false;
        
        CCString* temp = (CCString*)args->objectAtIndex(0);
        int monId = (CCString::create(convertedString->componentsSeparatedByString((CCString*)args->objectAtIndex(0), CCString::create("\t"))->getCString()))->intValue();
        int level = ((CCString*)args->objectAtIndex(1))->intValue();
        int position = ((CCString*)args->objectAtIndex(2))->intValue();
        int special = 0;
        if( args->count() > 3 ) 
        {
            special = ((CCString*)args->objectAtIndex(3))->intValue();
        }
        
        //
        //int position = [[args objectAtIndex:2] intValue];
        
        sawMonster(monId);
        caughtMonster( monId);
        
        dataMonster * mon = (dataMonster*)database->monById(monId);
        monster * newMon = new monster(); 
        newMon->initWithMonster(mon,level);
        newMon->special = special;
        newMon->position = position;
        monsters->addObject(newMon);
        
        //monsterTemplate.png
        CoolSprite * tmpSpt;
        CoolFreeform * tmpFF;
        
        tmpSpt->initWithFile(CCString::create("monsterTemplate.png"));
        tmpSpt->updatePosition(ccp(284,160));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,36);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
        tmpSpt->initWithFile(CCString::create("bg1.png"));
        tmpSpt->updatePosition(ccp(284,160));
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,35);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release(); 
        
        
        
        
        tmpFF ->initWithCoolSheet(CCString::createWithFormat("Name: %s",mon->getName()->getCString() ),FONT_WHITE,0.35,310,true);
        tmpFF->updatePosition(ccp(108,320-15));
        tmpFF->intTag1 = 320-25;
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("Type1: %s, Type2: %s", database->getTypeFromId(mon->type1Id)->getCString()    ,database->getTypeFromId(mon->type2Id)->getCString()),FONT_WHITE,0.25,310,true);
        tmpFF->updatePosition(ccp(108,320-20-20));
        tmpFF->intTag1 = 320-25;
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpFF ->initWithCoolSheet(CCString::createWithFormat("Category: %s",mon->getCategory()->getCString()),FONT_WHITE,0.25,310,true);
        tmpFF->updatePosition(ccp(108,320-20-20-15));
        tmpFF->intTag1 = 320-25;
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("Base Health Points: %d",mon->hp),FONT_WHITE,0.25,310,true);
        tmpFF->updatePosition(ccp(108,320-20-20-15-15));
        tmpFF->intTag1 = 320-25;
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        /*
         NSString * fullID = [NSString stringWithFormat:@"%@%d",@"000",mon.monid];
         NSString * leadingZerosID = [fullID substringFromIndex:[fullID length]-3];
         NSString * fileName = [NSString stringWithFormat:@"%@%@%@",@"dpffa",leadingZerosID,@".png"];
         */
        
        tmpSpt->initWithFile(newMon->getImage());
        tmpSpt->updatePosition(ccp(9+40,320-(9+40)));
        tmpSpt->intTag1 = 320-(9+40);
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,37);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release();
        
        
        
        tmpSpt->initWithFile(CCString::createWithFormat("element-%s.png",CCString::create(convertedString->lowercaseString(database->getTypeFromId(mon->type1Id))->getCString())->getCString()));
        tmpSpt->updatePosition(ccp(53+16,320-98-16));
        tmpSpt->intTag1 = 320-98-16;
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,37);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release();
        
        tmpSpt->initWithFile(CCString::createWithFormat("element-%s.png",CCString::create(convertedString->lowercaseString(database->getTypeFromId(mon->type1Id))->getCString())->getCString()));
        tmpSpt->updatePosition(ccp(14+16,320-98-16));
        tmpSpt->intTag1 = 320-98-16;
        tmpSpt->updateOpacity(255);
        tmpSpt->addToLayer(this,37);
        eventObjects->addObject(tmpSpt);
        tmpSpt->release();
        
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("ATK: %d",mon->atk),FONT_WHITE,0.4,310,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(151,320-101));
        tmpFF->intTag1 = 320-106;
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        
        tmpFF ->initWithCoolSheet(CCString::createWithFormat("DEF: %d",mon->def),FONT_WHITE,0.4,310,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(260,320-101));
        tmpFF->intTag1 = 320-106;
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("SPD: %d",mon->spd),FONT_WHITE,0.4,310,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(151,320-140));
        tmpFF->intTag1 = 320-145;
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        
        tmpFF->initWithCoolSheet(CCString::createWithFormat("INT: %d",mon->intel),FONT_WHITE,0.4,310,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(260,320-140));
        tmpFF->intTag1 = 320-145;
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        
        
        
        tmpFF ->initWithCoolSheet(CCString::createWithFormat("New Monster Acquired!"),FONT_WHITE,0.45,340,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240,320-200));
        tmpFF->intTag1 = 480-145;
        tmpFF->addToLayer(this,37);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
        
        bTalkButtonTouched = false;
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Change Coin")))
    {
        if( ((CCString*)args->objectAtIndex(0))->isEqual(CCString::create("ADD")))
        {
            coin  = coin + ((CCString*)args->objectAtIndex(1))->intValue();
        } 
        else 
        {
            coin  = coin - ((CCString*)args->objectAtIndex(1))->intValue();
        }
		activeScript->removeObjectAtIndex(0);
		this->scriptProgress();
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Change Inventory")))
    {
        if( ((CCString*)args->objectAtIndex(1))->isEqual(CCString::create("ADD")))
        {
            addItems(itemIdFromCode(((CCString*)args->objectAtIndex(0))), ((CCString*)args->objectAtIndex(2))->intValue());
            
        } else 
        {
            useItems(itemIdFromCode(((CCString*)args->objectAtIndex(0))), ((CCString*)args->objectAtIndex(2))->intValue());
        }
		activeScript->removeObjectAtIndex(0);
		this->scriptProgress();
        
	} else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Set Zone"))))
    {
        
        
        database->loadZoneInto(zoneMonsters, (CCString*)args->objectAtIndex(0));
        
        zone->release();
        zone = NULL;
        zone = CCString::create(((CCString*)args->objectAtIndex(0))->getCString());
        
		activeScript->removeObjectAtIndex(0);
		this->scriptProgress();
        
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Start AutoBattle"))))
    {
        
        CCString * funcLine;
        CCString * treasureHash =CCString::createWithFormat("SYS.AUTOBATTLE.%s.%s",mapFilename->getCString(),lastTriggeredEventName->getCString());
        CCString * battleData = CCString::create("");
        
        for(int i=2;i<args->count();i++)
        {
            battleData = convertedString->stringByAppendingFormat(battleData, CCString::createWithFormat("%s",((CCString*)args->objectAtIndex(i))->getCString()));
        }
        battleData =  convertedString->substringToIndex(battleData, battleData->length()-1);
        
        
        int pos = 1;
        funcLine = CCString::createWithFormat("IF|Global Variable^%s^F",treasureHash->getCString());
        activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
        
        funcLine = CCString::createWithFormat("Display Message|%s^",((CCString*)args->objectAtIndex(0))->getCString());
        pos++;
        activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
        
        funcLine = CCString::createWithFormat("Start Battle|%s",battleData->getCString());
        pos++;
        activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
        
        funcLine = CCString::createWithFormat("Update Variable|%s^T",treasureHash->getCString());
        pos++;
        activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
        
        funcLine = CCString::createWithFormat("ELSE|");
        pos++;
        activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
        
        //funcLine = [NSString stringWithFormat:@"Display Message|%@^",[args objectAtIndex:1]];
        //[activeScript addObject:  [funcLine componentsSeparatedByString:@"|"]  ];
        
        funcLine = CCString::createWithFormat("END IF|");
        pos++;
        activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
        
         activeScript->removeObjectAtIndex(0);
        this->scriptProgress();
        
        
	}
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Treasure Chest"))))
    {
        
        if( ((CCString*)args->objectAtIndex(1))->isEqual(CCString::create("COIN")))
        {
            
            int treasureAmt = ((CCString*)args->objectAtIndex(1))->intValue() + (arc4random() % (((CCString*)args->objectAtIndex(2))-> intValue() * 2)) - ((CCString*)args->objectAtIndex(2))->intValue();
            
            CCString * funcLine;
            CCString * treasureHash =CCString::createWithFormat("SYS.TREASURE.%s.%s",mapFilename->getCString(),lastTriggeredEventName->getCString());
            
            int pos = 1;
            funcLine = CCString::createWithFormat("IF|Global Variable^%@^F",treasureHash->getCString());
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            funcLine = CCString::createWithFormat("Display Message|You found %d Coin!^",treasureAmt);
            pos++;
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine = CCString::createWithFormat("Change Coin|ADD^%d",treasureAmt);
            pos++;
             activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine = CCString::createWithFormat("Update Variable|%s^T",treasureHash->getCString());
            pos++;
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine = CCString::createWithFormat("ELSE|");
            pos++;
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine = CCString::createWithFormat("Display Message|The Treasure Chest is Empty!^");
            pos++;
             activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine =CCString::createWithFormat("END IF|");
            pos++;
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
        } 
        else 
        {
            
            int treasureAmt = ((CCString*)args->objectAtIndex(1))->intValue() + (arc4random() % (((CCString*)args->objectAtIndex(2))->intValue() * 2)) - ((CCString*)args->objectAtIndex(2))->intValue();
            
            dataItem * item = database->getItemForValue(treasureAmt);
            
            CCString * funcLine;
            CCString * treasureHash = CCString::createWithFormat("SYS.TREASURE.%s.%s",mapFilename->getCString(),lastTriggeredEventName->getCString());
            
            int pos = 1;
            funcLine = CCString::createWithFormat("IF|Global Variable^%s^F",treasureHash->getCString());
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine = CCString::createWithFormat("Display Message|You found a %s!^",item->getName()->getCString());
            pos++;
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine = CCString::createWithFormat("Change Inventory|%d^ADD^1",item->itemid);
            pos++;
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine =CCString::createWithFormat("Update Variable|%s^T",treasureHash->getCString());
            pos++;
             activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine = CCString::createWithFormat("ELSE|");
            pos++;
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine = CCString::createWithFormat("Display Message|The Treasure Chest is Empty!^");
            pos++;
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
            funcLine = CCString::createWithFormat("END IF|");
            pos++;
            activeScript->insertObject(convertedString->componentsSeparatedByString(funcLine, CCString::create("|")),pos);
            
             activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
        }
    }
}


void menuLayer::scriptCheck()
{
	if(  activeScript->count() == 0 ) 
    {
		return;
	}
    
	CCArray * scriptToExecute = CCArray::create((CCString*) activeScript->objectAtIndex(0));
	if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Display Message")))
    {
		CCArray * args =  CCArray::create((CCString*)convertedString->componentsSeparatedByString(((CCString*)scriptToExecute->objectAtIndex(1)), CCString::create("^")));
		
        if( eventObjects->count() > 0 ) 
        {
            if(  bTalkButtonTouched ) 
            {
                 sfx(CCString::create( SOUND_CONFIRM));
                if( ((CoolFreeform*) eventObjects->objectAtIndex(0))->isFinished())
                {
                    activeScript->removeObjectAtIndex(0);
                    this->scriptProgress();
                } 
                else 
                {
                    ((CoolFreeform*) eventObjects->objectAtIndex(0))->finish();
                }
                  bTalkButtonTouched = false;
            }
        }
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0)->isEqual(CCString::create("Monster Farm"))))
    {
        
        if(  farmMenuState == - 1 )
        {
             activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
        }
        
        
        
        
        
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Monster Selection"))) {
        gearMenuLayer->bIsActive = true;
        gearMenuLayer->bIsOnPC = true;
        gearMenuLayer->drawMonsterCategories(1);
        gearMenuLayer->setPosition(ccp(0,0));
        
        activeScript->removeObjectAtIndex(0);
        this->scriptProgress();
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Fade In")))
    {
        fadeTimer = fadeTimer - 10;
        if( fadeTimer <= 0 ) 
        {
            fadeTimer = 0;
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
        }
        blackCover->updateOpacity(fadeTimer);    
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Fade Out")))
    {
        fadeTimer = fadeTimer + 10;
        if( fadeTimer >= 255 )
        {
            fadeTimer = 255;        
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
        }
         blackCover->updateOpacity(fadeTimer); 
        
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Mutate Monster at Position")))
    {
        
        if( eventObjects->count() == 2 ) 
        {
            
            CoolSprite * tmpSpt = (CoolSprite*)eventObjects->objectAtIndex(0);
            tmpSpt->intTag1 = tmpSpt->intTag1 - 3;
            if( tmpSpt->intTag1 < 0 ) 
                tmpSpt->intTag1 = 0;
            
            tmpSpt->updateOpacity( tmpSpt->intTag1);
            ((CoolSprite*)eventObjects->objectAtIndex(1))->updateOpacity( 255-tmpSpt->intTag1);
            
            if( tmpSpt->intTag1 <= 0 ) 
            {
                //End the function
                
                activeScript->removeObjectAtIndex(0);
                this->scriptProgress();
            }
        }
    } 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Display Credits")))
    {
        creditsTimer++;
        if( creditsTimer < 60 )
            bTalkButtonTouched=false;
        if( bTalkButtonTouched ) 
        {
            
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
            return;
        }
    } 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Shop - Buy")))
    {
        
        if( gearMenuLayer->bIsActive == false ) 
        {
            
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
            
        }
        
	} else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Shop - Sell")))
    {
        
        if( gearMenuLayer->bIsActive == false ) 
        {
            
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
        }
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Flash Red")))
    {
        redFlash->intTag1 = redFlash->intTag1  - 20;
        redFlash->updateOpacity(redFlash->intTag1);
        if( redFlash->intTag1 == 0 ) 
        {
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
        }
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Bite")))
    {
         redFlash->intTag1 = redFlash->intTag1  - 20;
         redFlash->updateOpacity(redFlash->intTag1 );
        if( redFlash->intTag1 == 0 ) 
        {
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
            
            questTemplate * tmpQuest = (questTemplate*)availableQuests->objectAtIndex(questMenu);
            int damage = tmpQuest->questClass * 10 + 5;
            
            bool bMonsterStillAlive = false;
            for(int i=0; i<monsters->count();i++)
            {
                monster * mon=(monster*)monsters->objectAtIndex(i);
                if( mon->position > 0 ) 
                {
                    
                    mon->hpLeft = mon->hpLeft - damage;
                    if( mon->hpLeft <= 0 )
                    {
                        mon->hpLeft  = 0;
                    }
                    else 
                    {
                        bMonsterStillAlive = true;
                    }
                    
                }
            }
            if( bMonsterStillAlive == false ) 
            {
                this->addFaintScriptAndKO();
                this->scriptProgress();
            }
        }
	} else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Quest Selection")))
    {
        
        
        
        
        //[activeScript removeObjectAtIndex:0];
        //[self scriptProgress];
        
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Sync All Events")))
    {
		this->scriptProgress();
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Relocate User")))
    {
		this->scriptProgress();
	}
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("END IF")))
    {
        //CleanUp - This shouldn't be required
        if( activeScript->count() == 1 ) 
        {
            activeScript->removeObjectAtIndex(0);
        }
	} 
    else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("ELSE")))
    {
        //CleanUp - This shouldn't be required
        if(activeScript->count() == 1 )
        {
            activeScript->removeObjectAtIndex(0);
        }
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Ask Yes or No")) || ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Ask Question - Two Answers")) )
    {
        if( bQuestionAnswered )
        {
            sfx(CCString::create(SOUND_CONFIRM));
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
            
        }
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Add Monster")))
    {
        if( bTalkButtonTouched )
        {
            activeScript->removeObjectAtIndex(0);
            this->scriptProgress();
            return;
        }
        
        
	} else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("IAP")))
    { 
        
		CCArray * args = CCArray::create(CCString::create(convertedString->componentsSeparatedByString((CCString*)scriptToExecute->objectAtIndex(1), CCString::create("^"))->getCString()));
        
        /* PENDINH_DEEPAK  BECAUSE MKStoreManager   
         if( [[MKStoreManager sharedManager].purchasableObjects count] == 0 ) {
         //Still Loading
         } else  {
         if( bIAPPurchasing ) {
         ;
         if( IAPResult == 1 ) {
         //Success
         
         [activeScript removeObjectAtIndex:0];
         [activeScript insertObject:  [[NSString stringWithFormat:@"Display Message\tTransaction was successful!^"] componentsSeparatedByString:@"\t"]  atIndex:0];
         [self scriptProgress];
         
         } else if( IAPResult == 2 ) {
         //Failure
         
         //IAPErrorMessage
         
         [self updateGlobal:@"SYSYesNoAnswer" withAction:0];
         [activeScript removeObjectAtIndex:0];
         [activeScript insertObject:  [[NSString stringWithFormat:@"Display Message\t%@^",IAPErrorMessage] componentsSeparatedByString:@"\t"]  atIndex:0];
         [self scriptProgress];
         
         
         } else {
         //Still Loading
         
         
         
         }
         
         } else {
         
         
         if( bIAPShowing == false ) {
         bIAPPurchasing = false;
         
         //Clear Screen and Draw Purchase Option.
         [eventObjects removeAllObjects];
         
         CoolSprite * tmpSpt = nil;
         CoolFreeform * tmpFF = nil;
         
         tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Buy" fontName:FONT_WHITE fontSize:0.35 andMaxWidth:200 instant:true];
         tmpFF.bCenter = true;
         [tmpFF updatePosition:ccp(240-54,320-80-100)];
         [tmpFF addToLayer:self z:37];
         [eventObjects addObject:tmpFF];
         [tmpFF release];
         
         tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"No Thanks" fontName:FONT_WHITE fontSize:0.25 andMaxWidth:200 instant:true];
         tmpFF.bCenter = true;
         [tmpFF updatePosition:ccp(240+54,320-80-100)];
         [tmpFF addToLayer:self z:37];
         [eventObjects addObject:tmpFF];
         [tmpFF release];
         
         tmpSpt = [[CoolSprite alloc] initWithFile:@"buttonGreen.png"];
         [tmpSpt updatePosition:ccp(240-54,320-80-110)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:36];
         [eventObjects addObject:tmpSpt];
         [tmpSpt release]; 
         
         tmpSpt = [[CoolSprite alloc] initWithFile:@"buttonBlue.png"];
         [tmpSpt updatePosition:ccp(240+54,320-80-110)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:36];
         [eventObjects addObject:tmpSpt];
         [tmpSpt release]; 
         
         tmpSpt = [[CoolSprite alloc] initWithFile:@"speechBubble.png"];
         [tmpSpt updatePosition:ccp(240,320-80)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:34];
         [eventObjects addObject:tmpSpt];
         [tmpSpt release]; 
         
         
         SKProduct * prodToUse = nil;
         for(SKProduct * prod in [[MKStoreManager sharedManager] purchasableObjects]) {
         if( [[args objectAtIndex:0] isEqualToString:@"A"] ) {
         //prod
         
         if( [[prod productIdentifier] isEqualToString:featureAId] ) {
         prodToUse = prod;
         break;
         }
         } else if( [[args objectAtIndex:0] isEqualToString:@"B"] ) {
         //prod
         
         if( [[prod productIdentifier] isEqualToString:featureBId] ) {
         prodToUse = prod;
         break;
         }
         }  else if( [[args objectAtIndex:0] isEqualToString:@"C"] ) {
         //prod
         
         if( [[prod productIdentifier] isEqualToString:featureCId] ) {
         prodToUse = prod;
         break;
         }
         }  else if( [[args objectAtIndex:0] isEqualToString:@"D"] ) {
         //prod
         
         if( [[prod productIdentifier] isEqualToString:featureDId] ) {
         prodToUse = prod;
         break;
         }
         } 
         }
         
         if( prodToUse== nil ) {
         //Serious Error
         [self updateGlobal:@"SYSYesNoAnswer" withAction:0];
         } else {
         
         CoolLabel * tmpLbl = [[CoolLabel alloc] initWithCoolString:[NSString stringWithFormat:@"Price: %@",[self stringFromLocalPrice:prodToUse]] fontName:@"Arial" fontSize:14];
         [tmpLbl updatePosition:ccp(480-120,320-42)];
         [tmpLbl addToLayer:self z:35];
         [eventObjects addObject:tmpLbl];
         [tmpLbl release];
         
         tmpFF = [[CoolFreeform alloc] initWithCoolSheet:prodToUse.localizedTitle fontName:FONT_WHITE fontSize:0.35 andMaxWidth:220 instant:true];
         [tmpFF updatePosition:ccp(54,320-32)];
         [tmpFF addToLayer:self z:35];
         [eventObjects addObject:tmpFF];
         [tmpFF release];
         
         tmpFF = [[CoolFreeform alloc] initWithCoolSheet:prodToUse.localizedDescription fontName:FONT_WHITE fontSize:0.25 andMaxWidth:360 instant:true];
         [tmpFF updatePosition:ccp(54,320-52)];
         [tmpFF addToLayer:self z:35];
         [eventObjects addObject:tmpFF];
         [tmpFF release];
         }
         
         
         bQuestionAnswered = false;
         bTalkButtonTouched = false;
         bIAPShowing = true;
         
         } else {
         //Do Nothing
         
         if( bQuestionAnswered ) {
         
         if( [self getGlobalBool:@"SYSYesNoAnswer"] ) {
         //Perform Purchase
         
         
         //Clear Screen and Draw Loading Screen.
         [eventObjects removeAllObjects];
         
         CoolFreeform * tmpFF = [[CoolFreeform alloc] initWithCoolSheet:@"Prompting for Purchase..." fontName:FONT_WHITE fontSize:0.35 andMaxWidth:380 instant:false];
         [tmpFF updatePosition:ccp(54,320-32)];
         [tmpFF addToLayer:self z:35];
         [eventObjects addObject:tmpFF];
         [tmpFF release];
         
         CoolSprite * tmpSpt = [[CoolSprite alloc] initWithFile:@"speechBubble.png"];
         [tmpSpt updatePosition:ccp(240,320-80)];
         [tmpSpt updateOpacity:255];
         [tmpSpt addToLayer:self z:34];
         [eventObjects addObject:tmpSpt];
         [tmpSpt release]; 
         
         IAPResult = 0;
         bIAPPurchasing = true;
         
         if( [[args objectAtIndex:0] isEqualToString:@"A"] ) {
         [[MKStoreManager sharedManager] buyFeatureA:self];
         } else if( [[args objectAtIndex:0] isEqualToString:@"B"] ) {
         [[MKStoreManager sharedManager] buyFeatureB:self];
         }    else if( [[args objectAtIndex:0] isEqualToString:@"C"] ) {
         [[MKStoreManager sharedManager] buyFeatureC:self];
         }    else if( [[args objectAtIndex:0] isEqualToString:@"D"] ) {
         [[MKStoreManager sharedManager] buyFeatureD:self];
         }   
         
         
         } else {
         //Abort Purchase
         //SYSYesNoAnsweris already F so we can abort the script
         [self updateGlobal:@"SYSYesNoAnswer" withAction:0];
         [activeScript removeObjectAtIndex:0];
         [self scriptProgress];
         }
         
         }
         
         }
         
         }
         
         } */
        
	} 
    else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Start Battle")))
    {
        
        
    }
    
    
	
}


/* PENDING_DEEPAK BECAUSE SKProduct
 - (NSString * ) stringFromLocalPrice:(SKProduct *) product{
 
 NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
 [formatter setFormatterBehavior:NSNumberFormatterBehavior10_4];
 [formatter setNumberStyle:NSNumberFormatterCurrencyStyle];
 [formatter setLocale:product.priceLocale];
 
 NSString *str = [formatter stringFromNumber:product.price];
 [formatter release];
 return str;
 
 }
 */

void menuLayer::scriptTouch(CCPoint touch)
{
	CCPoint button = btnTalkPosition;
	if( touch.x > button.x -16 && touch.x < button.x + 16 ) 
    {
		if( touch.y > button.y -16 && touch.y < button.y + 16 )
        {
			bTalkButtonTouched = true;
			
		}
	}
    
    //btn Yes
	button = ccp(240-54,320-80-110);
    if( touch.x > button.x -25 && touch.x < button.x + 25 )
    {
		if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
        {
			this->updateGlobal(CCString::create("SYSYesNoAnswer"),1);
            bQuestionAnswered= true;
		}
	}
    
    //btn No
	button = ccp(240+54,320-80-110);
    if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
    {
		if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
        {
			this->updateGlobal(CCString::create("SYSYesNoAnswer"),0);
            bQuestionAnswered= true;
		}
	}
    
    //TODO: Optimize this
    if( activeScript->count() > 0 )
    {
        
        
        CCArray * scriptToExecute =CCArray::create((CCString*)activeScript->objectAtIndex(0));
        
        if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Display Credits")))
        {
            bTalkButtonTouched = true;
            sfx(CCString::create(SOUND_CONFIRM));
            return;
        }
        
        
        //ccp(240+54,320-80-100-80)
        if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Monster Farm")))
        {
            //leave button
            CCPoint tmp = ccp(240+54,320-80-100-80);
            if( HitTest(touch,tmp,CCSizeMake(120, 42)))
            {
                farmMenuState = -1;
            }
            
            //return monster
            tmp = ccp(240-54,320-80-100);
            if( HitTest(touch,tmp,CCSizeMake(120, 42)))
            {
                farmMenuState = 1;
            }
            
            //place monster
            tmp = ccp(240+54,320-80-100);
            if( HitTest(touch,tmp,CCSizeMake(120, 42)))
            {
                farmMenuState = 2;
            }
            
            //
            
        } 
        else if(((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Quest Selection")))
        {
            
            //Buttons F-S & All
            //
            int ofsetX = 10;
            
            button = ccp(ofsetX+40,320-230);
            if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 )
                {
                    classFilter = 0;
                    sfx(CCString::create(SOUND_CONFIRM));
                    this->buildQuestFilter();
                    this->loadQuest();
                }
            }
            button = ccp(ofsetX+115,320-230);
            if( touch.x > button.x -25 && touch.x < button.x + 25 )
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 )
                {
                    classFilter = 1;
                    sfx(CCString::create(SOUND_CONFIRM));
                    this->buildQuestFilter();
                    this->loadQuest();
                }
            }
            button = ccp(ofsetX+190,320-230);
            if( touch.x > button.x -25 && touch.x < button.x + 25 )
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 )
                {
                    classFilter = 2;
                    sfx(CCString::create(SOUND_CONFIRM));
                    this->buildQuestFilter();
                    this->loadQuest();
                }
            }
            
            button = ccp(ofsetX+265,320-230);
            if( touch.x > button.x -25 && touch.x < button.x + 25 )
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
                {
                    classFilter = 3;
                    sfx(CCString::create(SOUND_CONFIRM));
                    this->buildQuestFilter();
                    this->loadQuest();
                }
            }
            button = ccp(ofsetX+340,320-230);
            if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
                {
                    classFilter = 4;
                    sfx(CCString::create(SOUND_CONFIRM));
                    this->buildQuestFilter();
                    this->loadQuest();
                }
            }
            button = ccp(ofsetX+415,320-230);
            if( touch.x > button.x -25 && touch.x < button.x + 25 )
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
                {
                    classFilter = 5;
                    sfx(CCString::create(SOUND_CONFIRM));
                    this->buildQuestFilter();
                    this->loadQuest();
                }
            }
            
            button = ccp(ofsetX+340,320-230-70);
            if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
                {
                    classFilter = 6;
                    sfx(CCString::create(SOUND_CONFIRM));
                    this->buildQuestFilter();
                    this->loadQuest();
                }
            }
            button = ccp(ofsetX+415,320-230-70);
            if( touch.x > button.x -25 && touch.x < button.x + 25 )
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 )
                {
                    classFilter = -1;
                    sfx(CCString::create(SOUND_CONFIRM));
                    this->buildQuestFilter();
                    this->loadQuest();
                }
            }
            
            
            //Cancel Button
            button = ccp(480-60,320-45);
            if( touch.x > button.x -25 && touch.x < button.x + 25 )
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
                {
                    
                    eventObjects->removeAllObjects();
                    activeScript->removeObjectAtIndex(0);
                    sfx(CCString::create( SOUND_CONFIRM));
                    this->scriptProgress();
                    
                }
            }
            
            //Previous Button
            button = ccp(480-150,320-45-65);
            if( touch.x > button.x -25 && touch.x < button.x + 25 )
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 )
                {
                    questMenu--;
                    if( questMenu < 0 )
                    {
                        questMenu = filteredQuests->count()-1;
                    }
                    sfx(CCString::create( SOUND_CONFIRM));
                    this->loadQuest();
                }
            }
            
            
            //Next Button
            button = ccp(480-60,320-45-65);
            if( touch.x > button.x -25 && touch.x < button.x + 25 )
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
                {
                    questMenu++;
                    if( questMenu >= filteredQuests->count())
                    {
                        questMenu = 0;
                    }
                    sfx(CCString::create( SOUND_CONFIRM));
                    this->loadQuest();
                }
            }
            
            //Accept Button
            button = ccp(480-150,320-45);
            if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
            {
                if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
                {
                    
                    //Start Quest....
                    questTemplate * tmpQuest = (questTemplate*)filteredQuests->objectAtIndex(questMenu);
                    tmpQuest->setupEvents();
                    
                    CCString * tmpStr = NULL;
                    
                    tmpQuest->reloadWithParent(g_menuLayer);
                    
                    
                    tmpStr = CCString::createWithFormat("Fade Out\t^"); 
                    this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                    
                    tmpStr = CCString::createWithFormat("Relocate User\t%s^%d^%d",tmpQuest->getMapName()->getCString() , (int)tmpQuest->startingPoint.x , (int)tmpQuest->startingPoint.y); 
                    this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                    
                    if( tmpQuest->questWeather == 0 ) 
                    {
                        tmpStr = CCString::createWithFormat("Change Weather\tGlare^"); 
                    }
                    else if( tmpQuest->questWeather == 1 ) 
                    {
                        tmpStr = CCString::createWithFormat("Change Weather\tLight Rain^"); 
                    }
                    else if( tmpQuest->questWeather == 2 ) 
                    {
                        tmpStr = CCString::createWithFormat("Change Weather\tHeavy Rain^"); 
                    }
                    else if( tmpQuest->questWeather == 3 ) 
                    {
                        tmpStr = CCString::createWithFormat("Change Weather\tNight^"); 
                    } 
                    else if( tmpQuest->questWeather == 4 )
                    {
                        tmpStr = CCString::createWithFormat("Change Weather\tNight Rain^"); 
                    } 
                    else if( tmpQuest->questWeather == 5 )
                    {
                        tmpStr =CCString::createWithFormat("Change Weather\tSnow^"); 
                    } 
                    else 
                    {
                        tmpStr =CCString::createWithFormat("Change Weather\tNormal^"); 
                    }
                    this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                    
                    tmpStr = CCString::createWithFormat("Set Zone\t%s^",tmpQuest->getZoneName()->getCString()); 
                    this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                    
                    tmpStr = CCString::createWithFormat("Fade In\t^"); 
                    this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                    
                    if( tmpQuest->questStory == 3 )
                    {
                        
                        
                        tmpStr =CCString::createWithFormat("IF\tGlobal Variable^SYS.ZombieModeBefore^F"); 
                        this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                        
                        tmpStr = CCString::createWithFormat("Display Message\tThis is a Zombie Artifact Mission. Search and Destroy the Zombie Artifact.^"); 
                        this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                        
                        tmpStr = CCString::createWithFormat("Display Message\tAvoid the Zombies as best you can. Your monsters health will decrease each time you are bitten.^"); 
                        this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                        
                        tmpStr = CCString::createWithFormat("Display Message\tThe Zombie artifact looks like a glowing green Zombie.^"); 
                        this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                        
                        
                        tmpStr = CCString::createWithFormat("Change Music\tsunnymellow^"); 
                        this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                        
                        tmpStr = CCString::createWithFormat("Update Variable\tSYS.ZombieModeBefore^T"); 
                        this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                        
                        tmpStr = CCString::createWithFormat("ELSE\t^"); 
                        this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                        
                        tmpStr = CCString::createWithFormat("END IF\t^"); 
                        this->addScript((CCArray*)(CCString*)convertedString->componentsSeparatedByString(tmpStr, CCString::create("\t")));
                    }
                    
                    activeScript->removeObjectAtIndex(0);
                    sfx(CCString::create(SOUND_CONFIRM));
                    this->scriptProgress();
                    
                }
                
                
            }
            
        } else if( ((CCString*)scriptToExecute->objectAtIndex(0))->isEqual(CCString::create("Monster Farm")))
        {
            
        }
        
    }
	
}



bool menuLayer::thereAreQuestsOfClass(int questClass)
{
    for(int i=0; i<availableQuests->count();i++) 
    {
        questTemplate * tmp = (questTemplate*)availableQuests->objectAtIndex(i);
        if( tmp->questClass == questClass ) 
            return true;
        
    }
    return false;
}

void menuLayer::buildQuestFilter() 
{
    filteredQuests->removeAllObjects();
    
    for(int i=0; i< availableQuests->count();i++) 
    {
        questTemplate * tmp = (questTemplate*)availableQuests->objectAtIndex(i);
        if( tmp->questClass == classFilter ||classFilter == -1 ) 
            filteredQuests->addObject(tmp);
    }
}


void menuLayer::loadQuest()
{
    
    if( filteredQuests->count() > 0 )
    {
        questTemplate * tmp = (questTemplate*)filteredQuests->objectAtIndex(0);
        if( tmp->questClass != classFilter ) 
        {
            this->buildQuestFilter();
        }
    } 
    else 
    {
        //Filter on All
        classFilter = -1;
        this->buildQuestFilter();
    }
    
    
    CoolSprite * tmpSpt = new CoolSprite();
    CoolFreeform * tmpFF;
    
    eventObjects->removeAllObjects();
    
    
    if(questMenu >= filteredQuests->count() )
        questMenu = 0;
    
    questTemplate * tmpQuest = (questTemplate*)filteredQuests->objectAtIndex(questMenu);
    
    
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt->updatePosition(ccp(284,160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,80);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    tmpSpt->initWithFile(CCString::create("missionTemplate.png"));
    tmpSpt->updatePosition(ccp(284,160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,81);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    
    /*
     //Other Stuff
     tmpSpt = [[CoolSprite alloc] initWithFile:@"screen.png"];
     [tmpSpt updatePosition:ccp(160,240)];
     [tmpSpt updateOpacity:255];
     [tmpSpt addToLayer:self z:1000];
     [eventObjects addObject:tmpSpt];
     [tmpSpt release]; 
     */
    
    int offsetX = 10;
    
    CCString * btnImage = NULL;
    
    btnImage = CCString::create("buttonRed.png");
    if( this->thereAreQuestsOfClass(0))
        btnImage = CCString::create("buttonGreen.png");
    if( classFilter == 0 )
        btnImage = CCString::create("buttonBlue.png");
    
    tmpSpt->initWithFile(btnImage);
    tmpSpt->updatePosition(ccp(offsetX+40,320-230));
    tmpSpt->updateOpacity(255);
    tmpSpt->updateScale(0.95);
    tmpSpt->addToLayer(this,1001);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    
    btnImage = CCString::create("buttonRed.png");
    if( this->thereAreQuestsOfClass(1) )
        btnImage =  CCString::create("buttonGreen.png");
    if( classFilter == 1 )
        btnImage =  CCString::create("buttonBlue.png");
    tmpSpt->initWithFile(btnImage);
    tmpSpt->updatePosition(ccp(offsetX+115,320-230));
    tmpSpt->updateOpacity(255);
    tmpSpt->updateScale(0.95);
    tmpSpt->addToLayer(this,1001);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    
    btnImage =  CCString::create( "buttonRed.png");
    if( this->thereAreQuestsOfClass(2) )
        btnImage = CCString::create("buttonGreen.png");
    if( classFilter == 2 )
        btnImage = CCString::create("buttonBlue.png");
    tmpSpt->initWithFile(btnImage);
    tmpSpt->updatePosition(ccp(offsetX+190,320-230));
    tmpSpt->updateOpacity(255);
    tmpSpt->updateScale(0.95);
    tmpSpt->addToLayer(this,1001);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    
    btnImage = CCString::create("buttonRed.png");
    if( this->thereAreQuestsOfClass(3) )
        btnImage = CCString::create("buttonGreen.png");
    if( classFilter == 3 )
        btnImage = CCString::create("buttonBlue.png");
    tmpSpt->initWithFile(btnImage);
    tmpSpt->updatePosition(ccp(offsetX+265,320-230));
    tmpSpt->updateOpacity(255);
    tmpSpt->updateScale(0.95);
    tmpSpt->addToLayer(this,1001);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    
    btnImage = CCString::create("buttonRed.png");
    if( this->thereAreQuestsOfClass(4) )
        btnImage = CCString::create("buttonGreen.png");
    if( classFilter == 4 )
        btnImage = CCString::create("buttonBlue.png");
    tmpSpt->initWithFile(btnImage);
    tmpSpt->updatePosition(ccp(offsetX+340,320-230));
    tmpSpt->updateOpacity(255);
    tmpSpt->updateScale(0.95);
    tmpSpt->addToLayer(this ,1001);
     eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    
    btnImage = CCString::create("buttonRed.png");
    if( this->thereAreQuestsOfClass(5) )
        btnImage = CCString::create("buttonGreen.png");
    if( classFilter == 5 )
        btnImage = CCString::create("buttonBlue.png");
    tmpSpt->initWithFile(btnImage);
    tmpSpt->updatePosition(ccp(offsetX+415,320-230));
    tmpSpt->updateOpacity(255);
    tmpSpt->updateScale(0.95);
    tmpSpt->addToLayer(this,1001);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    tmpFF->initWithCoolSheet( CCString::create("F Class"),FONT_WHITE ,0.25,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(offsetX+40,320-230+10));
    tmpFF->addToLayer(this,1002);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("E Class"),FONT_WHITE,0.25,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(offsetX+115,320-230+10));
    tmpFF->addToLayer(this ,1002);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("D Class"),FONT_WHITE,0.25,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(offsetX+190,320-230+10));
    tmpFF->addToLayer(this,1002);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create("C Class"),FONT_WHITE,0.25,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(offsetX+265,320-230+10));
    tmpFF->addToLayer(this,1002);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("B Class"),FONT_WHITE,0.25,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(offsetX+340,320-230+10));
    tmpFF ->addToLayer(this,1002);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("A Class"),FONT_WHITE,0.25,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(offsetX+415,320-230+10));
    tmpFF->addToLayer(this,1002);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    
    
    btnImage = CCString::create("buttonRed.png");
    if( this->thereAreQuestsOfClass(6) )
        btnImage = CCString::create("buttonGreen.png");
    if( classFilter == 6 )
        btnImage = CCString::create("buttonBlue.png");
    tmpSpt->initWithFile(btnImage);
    tmpSpt->updatePosition(ccp(offsetX+340,320-230-60));
    tmpSpt->updateOpacity(255);
    tmpSpt->updateScale(0.95);
    tmpSpt->addToLayer(this,1001);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    
    btnImage = CCString::create("buttonRed.png");
    if( this->thereAreQuestsOfClass(0) )
        btnImage =CCString::create("buttonGreen.png");
    if( classFilter == -1 )
        btnImage = CCString::create("buttonBlue.png");
    tmpSpt->initWithFile(btnImage);
    tmpSpt->updatePosition(ccp(offsetX+415,320-230-60));
    tmpSpt->updateOpacity(255);
    tmpSpt->updateScale(0.95);
    tmpSpt->addToLayer(this,1001);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    
    
    tmpFF->initWithCoolSheet(CCString::create("S Class"),FONT_WHITE,0.25,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(offsetX+340,320-230-60+10));
    tmpFF->addToLayer(this,1002);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("Show All"),FONT_WHITE,0.25,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(offsetX+415,320-230-60+10));
    tmpFF->addToLayer(this,1002);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    //Mission Info
    tmpSpt->initWithFile((convertedString->lowercaseString(CCString::createWithFormat("element-%s.png", (getDatabase()->getTypeFromId(tmpQuest->type1Id))->getCString()))));
    
    tmpSpt->updatePosition(ccp(14+16,320-98-16));
    tmpSpt->intTag1 = 480-98-16;
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,83);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release();
    
    tmpSpt->initWithFile((convertedString->lowercaseString(CCString::createWithFormat("element-%s.png", (getDatabase()->getTypeFromId(tmpQuest->type2Id))->getCString()))));
    tmpSpt->updatePosition(ccp(53+16,320-98-16));
    tmpSpt->intTag1 = 480-98-16;
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,83);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release();
    
    
    
    //Menu Bar
    
    
    tmpFF->initWithCoolSheet(CCString::create("Class:"),FONT_WHITE,0.35,200,true);
    tmpFF->updatePosition(ccp(25,320-20));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(tmpQuest->getClass(),FONT_WHITE,0.6,200,true);
    tmpFF->updatePosition(ccp(45,320-35));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create("Description:"),FONT_WHITE,0.25,200,true);
    tmpFF->updatePosition(ccp(100,320-15));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create(tmpQuest->getDescription()->getCString()),FONT_WHITE,0.25,200,true);
    tmpFF->updatePosition(ccp(100,320-30));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    if( tmpQuest->bCompleted ) 
    {
        tmpFF ->initWithCoolSheet(CCString::create("Completed"),FONT_GREEN ,0.3,200,true);
        tmpFF->bCenter = true;
        tmpFF->updatePosition(ccp(240,320-120));
        tmpFF->addToLayer(this,83);
        eventObjects->addObject(tmpFF);
        tmpFF->release();
    }
    
    
    tmpFF ->initWithCoolSheet(CCString::create("Weather:"),FONT_WHITE,0.25,200,true);
    tmpFF->updatePosition(ccp(100,320-80));
    tmpFF->addToLayer(this,83);
     eventObjects ->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(tmpQuest->getWeather(),FONT_WHITE,0.25,200,true);
    tmpFF->updatePosition(ccp(100,320-95));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    
    tmpSpt->initWithFile(CCString::create("buttonGreen.png"));
    tmpSpt->updatePosition(ccp(480-150,320-45));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,83);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    tmpSpt->initWithFile(CCString::create("buttonRed.png"));
    tmpSpt->updatePosition(ccp(480-60,320-45));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,83);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release(); 
    
    tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
    tmpSpt->updatePosition(ccp(480-150,320-45-65));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,83);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release();
    
    tmpSpt->initWithFile(CCString::create("buttonBlue.png"));
    tmpSpt->updatePosition(ccp(480-60,320-45-65));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,83);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release();
    
    tmpFF->initWithCoolSheet(CCString::create("Accept"),FONT_WHITE,0.35,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(480-150,320-45+12));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("Cancel"),FONT_WHITE,0.35,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(480-150,320-45+12));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("Back"),FONT_WHITE,0.35,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(480-150,320-45-65+12));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create("Next"),FONT_WHITE,0.35,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(480-150,320-45-65+12));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::createWithFormat("Mission: %d of %d",questMenu+1,filteredQuests->count()),FONT_WHITE,0.25 ,200,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(480-120,320-150));
    tmpFF->addToLayer(this,83);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
}

void menuLayer::addMapEvent(CCArray * data)
{
    
    
    gameEvent * tmpEvent =   new gameEvent();
    tmpEvent->initWithData(data,g_menuLayer);
    mapEvents->addObject(tmpEvent);
    tmpEvent->release();
    
}


void menuLayer::showCredits() 
{
    
    creditsTimer = 0;
    bTalkButtonTouched = false;
    
    
    CoolSprite * tmpSpt = new CoolSprite();
    tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt->updatePosition(ccp(240,160));
    tmpSpt->updateOpacity(255);
    tmpSpt->addToLayer(this,1000);
    eventObjects->addObject(tmpSpt);
    tmpSpt->release();
    
    
    
    
    CoolFreeform * tmpFF = new CoolFreeform();
    tmpFF->initWithCoolSheet(CCString::create("THANK YOU FOR PLAYING!"),FONT_WHITE,0.45,300,true);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-10));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create("A Misnomer Studios Production." ),FONT_WHITE,0.35,380,false);
    
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-30));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create("Developed by Benjamin Hill" ),FONT_WHITE,0.25,380,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-50));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("Artwork By:"),FONT_WHITE,0.35,300,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-80));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF->initWithCoolSheet(CCString::create("Princess-Phoenix - Monsters"),FONT_WHITE,0.30,300,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-100));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create("BoOmxBiG - Tileset") ,FONT_WHITE,0.30,300,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-120));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF ->initWithCoolSheet(CCString::create("Heather Farnsworth - Characters"),FONT_WHITE,0.30,300,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-140));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    
    tmpFF->initWithCoolSheet(CCString::create("Thanks:"),FONT_WHITE,0.35,300,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-160));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    tmpFF ->initWithCoolSheet(CCString::create("Sharks - Bugging me like a true friend"),FONT_WHITE,0.28,330,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-180));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create("Chloe - Being an Amazing Wife!"),FONT_WHITE,0.30,300,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-200));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release(); 
    
    
    tmpFF->initWithCoolSheet(CCString::create("SoundJay - Music"),FONT_WHITE,0.3,300,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-220));
    tmpFF->addToLayer(this,1001);
     eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create("And Monster Ranchers Everywhere!" ),FONT_WHITE,0.3,300,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-240));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    tmpFF->initWithCoolSheet(CCString::create("www.monsterranch.com"),FONT_WHITE,0.25,300,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-260));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    
    
    tmpFF->initWithCoolSheet(CCString::create("Tap to Continue Playing."),FONT_WHITE,0.35,320,false);
    tmpFF->bCenter = true;
    tmpFF->updatePosition(ccp(240,320-290));
    tmpFF->addToLayer(this,1001);
    eventObjects->addObject(tmpFF);
    tmpFF->release();
    
    
    /*
     tmpSpt = [[CoolSprite alloc] initWithFile:@"geoMonsters.png"];
     [tmpSpt updatePosition:ccp(160,30)];
     [tmpSpt updateOpacity:255];
     [tmpSpt addToLayer:self z:1001];
     [eventObjects addObject:tmpSpt];
     [tmpSpt release];
     */
    
}

void menuLayer::addFaintScriptAndKO()
{
    activeScript->removeAllObjects();
    
    
    activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Display Message\tNone of your Monsters can battle anymore.^"), CCString::create("\t")));
    
    activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Display Message\tYour GeoGear starts glowing red... ..^"), CCString::create("\t")));
    
    activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Change Weather\tNormal"), CCString::create("\t")));
    
    
    activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Set Zone\t"), CCString::create("\t")));
    
    
    activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Change Music\tNewGameLoop^"), CCString::create("\t")));
    
    
    activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Full Restore\t"), CCString::create("\t")));
    
    
    activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Relocate User\thomeUpper.tmx^8^13"), CCString::create("\t")));
    
    activeScript->addObject((CCString*)convertedString->componentsSeparatedByString(CCString::create("Display Message\tAgh! I've got a Headache!^"), CCString::create("\t")));
    
}                          





void menuLayer::scriptModifyWithConditionResult(bool bResult)
{
    if( activeScript->count() == 0 ) 
    {
        return;
    }
    
    
    /*
     NSLog([NSString stringWithFormat:@"****** BEFORE CHECK ******* "]);
     for(NSArray * tmpRay in activeScript) {
     NSLog([tmpRay objectAtIndex:0]);
     }
     */
    
    int tickIf = 0;
    int tickElse = 0;
    
    bool bottomIf = false;
    bool bottomElse = false;
    
    
    int lineNo = 0;
    while(lineNo < activeScript->count() )
    {
        
        
        CCArray * scriptToExecute =  CCArray::create(((CCString*)activeScript->objectAtIndex(lineNo)));
        CCString * function = (CCString*)scriptToExecute->objectAtIndex(0);
        
        if(function->isEqual(CCString::create("IF")))
        {
            tickIf++;
            
            if( tickIf == 1 && tickElse == 0 ) 
            {
                bottomIf = true;
            }
        }
        if( function->isEqual(CCString::create("ELSE")))
        {
            tickIf--;
            tickElse++;
            
            if( tickIf == 0 && tickElse == 1) 
            {
                bottomIf = false;
                bottomElse = true;
            }
            
        }
        
        if(function->isEqual(CCString::create("END IF")))
        {
            tickElse--;
            
            if( tickIf == 0 && tickElse == 0) 
            {
                bottomIf = false;
                bottomElse = false;
            }
            
        }
        
        
        if( bResult ) 
        {
            //If the if statement succeeded remove the entire else statement
            if( bottomElse ) 
            {
                activeScript->removeObjectAtIndex(lineNo);
                lineNo--;
            }
        } 
        else 
        {
            //If the if statement succeeded remove the entire if statement
            if( bottomIf ) 
            {
                activeScript->removeObjectAtIndex(lineNo);
                lineNo--;
            }
        }
        
        
        if( tickIf == 0 && tickElse == 0 )
        {
            //Remove End If
            if( lineNo >= 0 ) 
                activeScript->removeObjectAtIndex(lineNo);
            break;
        }
        lineNo++;
    }
    
    //Remove If or Else
    activeScript->removeObjectAtIndex(0);
    //Remove the Initial If (or Else) Statement and Continue Processing
    //[activeScript removeObjectAtIndex:0];
    
    /*
     NSLog([NSString stringWithFormat:@"****** AFTER CHECK ******* "]);
     for(NSArray * tmpRay in activeScript) {
     NSLog([tmpRay objectAtIndex:0]);
     }
     */
    
    
    this->scriptProgress();
}





#pragma mark -
#pragma mark === menuScene+Help===
#pragma mark -




void menuLayer::displayHelpScreen(bool bSet)
{
	//09Susan.png
	
	//[self playSong:MUSIC_HELP];
	
	if( bSet )
    {
		menuStage = 100;
	}
    else 
    {
		menuStage=menuStage+1;
		if( menuStage > 110)
        {
			gearMenuLayer->displayIndex();
			return;
		}
	}
	helpTimer = 0;
	
	CoolFreeform * tmpFF = new CoolFreeform;
	
	menuItems-> removeAllObjects();
	
	CoolSprite * tmpSpt = new CoolSprite; 
	tmpSpt->initWithFile(CCString::create("bg1.png"));
    tmpSpt-> updatePosition(ccp(160,240));
	tmpSpt-> updateOpacity(255);
	tmpSpt-> addToLayer(g_menuLayer,10);
	menuItems-> addObject(tmpSpt);
	tmpSpt-> release();
	
	
	tmpSpt ->initWithFile(CCString::create("17Peppermint.png"));
	tmpSpt-> updatePosition(ccp(80,480-80));
	tmpSpt-> updateScale(0.5);
	tmpSpt-> updateOpacity(255);
	tmpSpt-> addToLayer(g_menuLayer,10);
	menuItems-> addObject(tmpSpt);
	tmpSpt-> release();
	
	if( menuStage == 100 )
    {
        
        tmpFF->initWithCoolSheet(CCString::create("Hello There! So your the new recruit."), FONT_WHITE ,0.5 ,310,false);
		tmpFF-> updatePosition(ccp(10,320));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
		
	} 
    else if( menuStage == 101 ) 
    {
		
		tmpFF ->initWithCoolSheet(CCString::create("Well I'm sure you've seen about all the power outages on the News Lately. It seems we finally have an explanation."), FONT_WHITE ,0.4 ,310 ,false);
		tmpFF-> updatePosition(ccp(10,320));
		tmpFF-> addToLayer(g_menuLayer, 20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
	} 
    else if( menuStage == 102 ) 
    {
		
		tmpSpt ->initWithFile(CCString::create("ZenvsHinoDark.png"));
		tmpSpt-> updatePosition(ccp(160,98));
		tmpSpt-> updateOpacity(255);
		tmpSpt-> addToLayer(g_menuLayer,15);
		
		tmpSpt-> updateScale(1.5);
		
		menuItems-> addObject(tmpSpt);
		tmpSpt-> release();
		
		tmpFF ->initWithCoolSheet(CCString::create("The really strong monsters fight vicious battles with each other across our power grid."),FONT_WHITE ,0.4 ,310 ,false);
		tmpFF-> updatePosition(ccp(10,320-200));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems ->addObject(tmpFF);
		tmpFF-> release();
		
	} 
    else if( menuStage == 103 )
    {
		
		tmpSpt -> initWithFile(CCString::create("ZenVsHinoChaosPlague.png"));
		tmpSpt-> updatePosition(ccp(-80,480/2));
		tmpSpt-> updateOpacity(255);
		tmpSpt-> addToLayer(g_menuLayer,15);
		
		tmpSpt-> updateScale(1.2);
		
		menuItems-> addObject(tmpSpt);
		tmpSpt-> release();
		
		tmpFF -> initWithCoolSheet(CCString::create("Our Job is to Tame and Log every GeoMonster we can find! To make it interesting we have Tornaments and Challenges"), FONT_WHITE ,0.4 ,310 ,false);
		tmpFF-> updatePosition(ccp(10,320-200));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
	} 
    else if( menuStage == 104 )
    {
		
		tmpFF ->initWithCoolSheet(CCString::create("Is there anything else you would like to know about?" ),FONT_WHITE ,0.5 ,310 ,true);
		tmpFF-> updatePosition(ccp(10,320));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
		
		tmpFF ->initWithCoolSheet(CCString::create("How do my monsters grow?"), FONT_GREEN ,0.4 ,310 ,true);
		tmpFF->bCenter = true;
		tmpFF-> updatePosition(ccp(160,240));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems->addObject(tmpFF);
		tmpFF-> release();
		
		tmpFF ->initWithCoolSheet(CCString::create("How do I tame monsters?"), FONT_GREEN ,0.4 ,310 ,true);
		tmpFF->bCenter = true;
		tmpFF-> updatePosition(ccp(160,240-40));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
		tmpFF ->initWithCoolSheet(CCString::create("Do I need my GPS enabled?"), FONT_GREEN ,0.4 ,310 ,true);
		tmpFF->bCenter = true;
		tmpFF-> updatePosition(ccp(160,240-80));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
		tmpFF ->initWithCoolSheet(CCString::create("Should I battle other Tamers?"), FONT_GREEN ,0.34 ,310 ,true);
		tmpFF->bCenter = true;
		tmpFF-> updatePosition(ccp(160,240-120));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
		tmpFF ->initWithCoolSheet(CCString::create("How does breeding work?" ),FONT_GREEN ,0.4 ,310 ,true);
		tmpFF->bCenter = true;
		tmpFF-> updatePosition(ccp(160,240-160));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF ->release();
		
		
		tmpFF ->initWithCoolSheet(CCString::create("Nothing, Lets Go!"), FONT_RED ,0.5 ,310 ,false);
		tmpFF->bCenter = true;
		tmpFF-> updatePosition(ccp(160,32));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
	}
    else if( menuStage == 105 ) 
    {
		//Monster Grow
		
		
		tmpFF ->initWithCoolSheet(CCString::create("Every Time your Monster Knocks Out another Monster in Battle it will gain some Experience. With enough experience a monster will grow levels which provides you with stat points to allocate to Attack, Defense, Speed or Intelligence. Some monsters will even Mutate automatically when they reach a certain level."), FONT_WHITE ,0.4 ,310 ,false);
		tmpFF-> updatePosition(ccp(10,320));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF ->release();
		
	}
    else if( menuStage == 106 ) 
    {
		//Monster Taming
		
		
		tmpFF -> initWithCoolSheet(CCString::create("From the home screen tap on 'Hunt' from here you should Bait for Monsters or Attack Monsters your friends have Baited. Once you defeat a monster you have the option of Taming it or leaving."), FONT_WHITE ,0.4 ,310 ,false);
		tmpFF-> updatePosition(ccp(10,320));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
	} 
    else if( menuStage == 107 )
    {
		//Do I need GPS
		
		tmpFF -> initWithCoolSheet(CCString::create("The iPhone, iPad or iPod GPS is needed to play GeoMonsters. Within some Countries this functionality does not work. We appologize for this but there is nothing we can do about it."), FONT_WHITE ,0.4 ,310 ,false);
		tmpFF-> updatePosition(ccp(10,320));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
	} 
    else if( menuStage == 108 ) 
    {
		//Battle Others
		
        tmpFF ->initWithCoolSheet(CCString::create("Everytime you win a battle against another Tamer using the World Map or Hunting Screens you will gain one eighth of the Coin they are holding. You can protect your Coin by depositing it in the town bank."), FONT_WHITE ,0.4 ,310,false);
		tmpFF-> updatePosition(ccp(10,320));
		tmpFF-> addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
		
	} 
    else if( menuStage == 109 ) 
    {
		//Breeding
		
        tmpFF ->initWithCoolSheet(CCString::create("Monster Breeding requires two monsters level 10 or above of each gender. Both parents are lost as they run away once an egg is produced. Each time a monster is breed the resulting Egg will have an additional Stat Point to allocate for each level. Monster Breeding is one of the only ways to gather Divine or Demonic GeoMonsters. " ),FONT_WHITE ,0.4 ,310 ,false);
		tmpFF ->updatePosition(ccp(10,320));
		tmpFF ->addToLayer(g_menuLayer,20);
		menuItems-> addObject(tmpFF);
		tmpFF-> release();
	}
}


void menuLayer::helpTick()
{
	CoolFreeform * tmpFF = new CoolFreeform;
	helpTimer++;
	
	if( menuStage == 100 ) 
    {
		if( helpTimer == 60 )
        {
			
			tmpFF ->initWithCoolSheet(CCString::create("We've heard lots about you already, but you should still fill in your profile sometime."), FONT_WHITE ,0.4 ,310 ,false);
			tmpFF-> updatePosition(ccp(10,320-80));
			tmpFF-> addToLayer(g_menuLayer,20);
			menuItems-> addObject(tmpFF);
			tmpFF-> release();
			
            
			((CoolFreeform*)menuItems->objectAtIndex(2))->finish();
            
        }
		
		if( helpTimer == 160 )
        {
			
			tmpFF->initWithCoolSheet(CCString::create("Let me explain exactally what it is we do here. That should clear things up a bit." ),FONT_WHITE ,0.4 ,310 ,false);
			tmpFF-> updatePosition(ccp(10,320-160));
			tmpFF-> addToLayer(g_menuLayer,20);
			menuItems-> addObject(tmpFF);
			tmpFF-> release();
			
            //DEEPAK_DOUBT
            ((CoolFreeform*)menuItems->objectAtIndex(3))->finish();
        }
		
		
		if( helpTimer == 290 )
        {
			this->displayHelpScreen(false);
		}
	} 
    else if( menuStage == 101 ) 
    {
		
		if( helpTimer == 140 )
        {
			
			tmpFF -> initWithCoolSheet(CCString::create("We have discovered Electro-Organisms are the cause, but we know very little about them."), FONT_WHITE ,0.4 ,310 ,false);
			tmpFF-> updatePosition(ccp(10,200));
			tmpFF-> addToLayer(g_menuLayer,20);
			menuItems-> addObject(tmpFF);
			tmpFF-> release();
			
            
            //DEEPAK_DOUBT
			objectOfCoolFreeform= (CoolFreeform*)menuItems->objectAtIndex(2);
            objectOfCoolFreeform->finish();
			
		}
		
		if( helpTimer == 300 ) 
        {
			this-> displayHelpScreen(false);
			
		}
		
	} 
    else if( menuStage == 102 ) 
    {
		
		CoolSprite * tmpSpt =  (CoolSprite*)menuItems-> objectAtIndex(2);
		if( tmpSpt->y + 3 < 392 )
        {
			tmpSpt-> updatePosition(ccp(tmpSpt->x,tmpSpt->y+3));
		}
		
		if( tmpSpt->myScale - 0.01 > 1 ) 
        {
			tmpSpt-> updateScale(tmpSpt->myScale - 0.01);
		}
		
		
		if( helpTimer == 140 )
        {
			this-> displayHelpScreen(false);
			
		}
		
	}
    else if( menuStage == 103 ) 
    {
		CoolSprite * tmpSpt =(CoolSprite*)menuItems-> objectAtIndex(2);
		
        
        if( tmpSpt->x + 3 < 160 )
        {
			tmpSpt ->updatePosition(ccp(tmpSpt->x+3,tmpSpt->y));
		}
		
		if( tmpSpt->myScale - 0.005 > 1 ) 
        {
			tmpSpt ->updateScale(tmpSpt->myScale - 0.005);
		}
		
		if( helpTimer == 180 ) 
        {
			this-> displayHelpScreen(false);
			
		}
		
		
	}
    else if( menuStage == 104 ) 
    {
		
		
	}
}


void menuLayer::helpTouch(CCPoint touch)
{
	//[self displayHelpScreen: false];
	
    
    
    
    
	if( menuStage == 100 )
    {
		if( helpTimer < 59 )
        {
			helpTimer = 59;
		}
        else
        {
			if( helpTimer < 159 )
            {
				helpTimer = 159;
			} 
            else 
            {
				if( menuItems->count() > 4 )
                {
                    objectOfCoolFreeform= (CoolFreeform*)menuItems->objectAtIndex(4);
					if(( helpTimer < 289 && objectOfCoolFreeform->isFinished())== false ) 
                    {
						objectOfCoolFreeform-> finish();
					} 
                    else if( helpTimer < 289 )
                    {
						helpTimer = 289;
					}
				}
			}
		}
	}
    else if( menuStage == 101 )
    {
		if( helpTimer < 139 ) 
        {
			helpTimer = 139;
		} 
        else 
        {
			if( menuItems-> count() > 3 ) 
            {
                objectOfCoolFreeform= (CoolFreeform*)menuItems->objectAtIndex(3);
				if( (helpTimer<299 && objectOfCoolFreeform->isFinished()) == false ) 
                {
                    objectOfCoolFreeform->finish();
				} 
                else if( helpTimer < 299 ) 
                {
					helpTimer = 299;
				}
			}
		}
	}
    else if( menuStage == 104 ) 
    {
		
		if( touch.y < 240 + 20 && touch.y > 240 - 20 )
        {
			
			menuStage = 104;
			this-> displayHelpScreen(false);
			return;
		} 
        else if( touch.y < 200 + 20 && touch.y > 200 - 20 )
        {
			
			menuStage = 105;
			this->displayHelpScreen(false);
			return;
		} 
        else if( touch.y < 160 + 20 && touch.y > 160 - 20 ) 
        {
			
			menuStage = 106;
			this->displayHelpScreen(false);
			return;
		}
        else if( touch.y < 120 + 20 && touch.y > 120 - 20 )
        {
			
			menuStage = 107;
			this-> displayHelpScreen(false);
			return;
		} 
        else if( touch.y < 80 + 20 && touch.y > 80 - 20 ) 
        {
			
			menuStage = 108;
			this->displayHelpScreen(false);
			return;
		} 
		
		
		if( touch.y < 40 ) 
        {            
			
            saveToUserDefaults(CCString::createWithFormat("USER.%d.POSITION",profileNumber),(CCString::createWithFormat("homeUpper.tmx,8,11")));
            
			displayGame(CCString::create("homeUpper.tmx"), ccp(8,11));
			
		}
	}
	
	if( menuStage == 105 )
    {
		//Monster Grow
		
        
        objectOfCoolFreeform= (CoolFreeform*)menuItems->objectAtIndex(2);
		if( objectOfCoolFreeform->isFinished() == false ) 
        {
            objectOfCoolFreeform->finish();
		}
        else 
        {
			menuStage = 103;
			this-> displayHelpScreen(false);
		}
	} 
    else if( menuStage == 106 ) 
    {
		//Monster Taming
		
        
        objectOfCoolFreeform= (CoolFreeform*)menuItems->objectAtIndex(2);
        
		if( objectOfCoolFreeform->isFinished() == false )
        {
			objectOfCoolFreeform-> finish();
		}
        else
        {
			menuStage = 103;
			this->displayHelpScreen(false);
		}
	} 
    else if( menuStage == 107 ) 
    {
		//Do I need GPS
        objectOfCoolFreeform= (CoolFreeform*)menuItems->objectAtIndex(2);
		if( objectOfCoolFreeform->isFinished() == false ) 
        {
			objectOfCoolFreeform-> finish();
		} 
        else
        {
			menuStage = 103;
			this->displayHelpScreen(false);
        }
	} 
    else if( menuStage == 108 ) 
    {
		//Battle Others
        objectOfCoolFreeform= (CoolFreeform*)menuItems->objectAtIndex(2);
		if( objectOfCoolFreeform-> isFinished() == false )
        {
			objectOfCoolFreeform-> finish();
		} 
        else 
        {
			menuStage = 103;
			this->displayHelpScreen(false);
		}
	} 
    else if( menuStage == 109 )
    {
		//Breeding
        objectOfCoolFreeform= (CoolFreeform*)menuItems->objectAtIndex(2);
		if( objectOfCoolFreeform-> isFinished() == false ) 
        {
			objectOfCoolFreeform-> finish();
		} 
        else 
        {
			menuStage = 103;
			this->displayHelpScreen(false);
        }
	}
	
}







#pragma mark -
#pragma mark === menuScene+menuLayer===
#pragma mark -



void menuLayer::saveAccount()
{
	
    
	saveToUserDefaults(CCString::createWithFormat("USER.%d.POSITION",profileNumber),CCString::createWithFormat("%s,%d,%d",mapFilename->getCString(),(int)me->mapPosition.x,(int)me->mapPosition.y));
    
	saveToUserDefaults(CCString::createWithFormat("USER.%d.MUSIC",profileNumber),musicname);
    
	saveToUserDefaults(CCString::createWithFormat("USER.%d.STEPSTAKEN",profileNumber),CCString::createWithFormat("%qu",stepsTaken));
	
    saveToUserDefaults(CCString::createWithFormat("USER.%d.MONSTERCOUNT",profileNumber),CCString::createWithFormat("%d",monsters->count()));
	saveToUserDefaults(CCString::createWithFormat("USER.%d.MISSIONSCOMPLETED",profileNumber),CCString::createWithFormat("%d", missionsAccomplished));
    
    
	saveToUserDefaults(CCString::createWithFormat("USER.%d.CONTROL",profileNumber),CCString::createWithFormat("%d", controlMode));
    
	saveToUserDefaults(CCString::createWithFormat("USER.%d.CLASSFILTER",profileNumber),CCString::createWithFormat("%d", classFilter));
    
    
    
    saveToUserDefaults(CCString::createWithFormat("USER.%d.ZONE",profileNumber), zone);
    saveToUserDefaults(CCString::createWithFormat("USER.%d.WEATHER",profileNumber),weather);
    
    saveToUserDefaults(CCString::createWithFormat("USER.%d.COIN",profileNumber),CCString::createWithFormat("%d",coin));
    
    saveToUserDefaults(CCString::createWithFormat("USER.%d.STATRESETS",profileNumber),CCString::createWithFormat("%d",statResetsRemaining));
    saveToUserDefaults(CCString::createWithFormat("USER.%d.SEED",profileNumber),CCString::createWithFormat("%d",seed));
    
    saveToUserDefaults(CCString::createWithFormat("USER.%d.EXPSHARE",profileNumber),CCString::createWithFormat("%d",expSharePurchased));
    
    
    
    
    CCUserDefault *standardUserDefaults = CCUserDefault::sharedUserDefault();
	if (standardUserDefaults)
    {
        
        CCData * data = this->dictToData(globalSettings);
        CCString * str =(CCString*)this->base64forData(data);
        saveToUserDefaults(CCString::createWithFormat("USER.%d.GLOBALS",profileNumber),str);
        
        data = this->dictToData(inventory);
        str = this->base64forData(data);
        saveToUserDefaults(CCString::createWithFormat("USER.%d.ITEMS",profileNumber),str  );
        
        data = this->dictToData(monstersSeen);
        str = this->base64forData(data);
        saveToUserDefaults(CCString::createWithFormat("USER.%d.MONSEEN",profileNumber),str);
        
        data = this->dictToData(monstersSeen);
        str = this->base64forData(data);
        saveToUserDefaults(CCString::createWithFormat("USER.%d.MONCAUGHT",profileNumber),str);
        
        
        /*
         tmpKey = [NSString stringWithFormat:@"USER.%d.ITEMS",profileNumber];
         [standardUserDefaults setObject:inventory forKey:tmpKey];
         
         tmpKey = [NSString stringWithFormat:@"USER.%d.MONSEEN",profileNumber];
         [standardUserDefaults setObject:monstersSeen forKey:tmpKey];
         
         tmpKey = [NSString stringWithFormat:@"USER.%d.MONCAUGHT",profileNumber];
         [standardUserDefaults setObject:monstersCaught forKey:tmpKey];
         
         NSString * tmpKey = [NSString stringWithFormat:@"USER.%d.GLOBALS",profileNumber];
         [standardUserDefaults setObject:globalSettings forKey:tmpKey];
         */
        
        /* PENDING_DEEPAK  NSKeyedArchiver
         data = [NSKeyedArchiver archivedDataWithRootObject:monsters];
         str = [menuLayer base64forData:data];
         [self saveToUserDefaults:[NSString stringWithFormat:@"USER.%d.MONSTERS",profileNumber] andValue:str  ];
         
         NSLog(@"Saved %d Monsters",[monsters count]);
         
         data = [NSKeyedArchiver archivedDataWithRootObject:availableQuests];
         str = [menuLayer base64forData:data];
         [self saveToStdUserDefaults:[NSString stringWithFormat:@"USER.%d.QUESTS",profileNumber] andValue:str  ];
         
         
         NSLog(@"Saved %d Quests",[availableQuests count]);
         
         ///data = [NSKeyedArchiver archivedDataWithRootObject:filteredQuests];
         //str = [menuLayer base64forData:data];
         //[self saveToUserDefaults:[NSString stringWithFormat:@"USER.%d.FQUESTS",profileNumber] andValue:str  ];
         */
        
        
        
        if( mapIsGeoRealm() )
        {
            //It we are in the georealm then we need to create the active quests sprites in the menuLayer array.
            
            //questTemplate * tmp = [filteredQuests objectAtIndex:questMenu];
            
            
            saveToUserDefaults(CCString::createWithFormat("USER.%d.QUESTMENU",profileNumber),CCString::createWithFormat("%d",questMenu));
            
            // NSLog("Saved %d Quest Menu Item",questMenu);
            
            
        } else {
            
            saveToUserDefaults(CCString::createWithFormat("USER.%d.QUESTMENU",profileNumber),CCString::createWithFormat("%d",-1));
            
            //      NSLog(@"Saved %d Quest Menu Item",-1);
        }
        
        
        
        /*
         tmpKey = [NSString stringWithFormat:@"USER.%d.MONSTERS",profileNumber];
         [standardUserDefaults setObject:[NSKeyedArchiver archivedDataWithRootObject:monsters] forKey:tmpKey];
         
         
         tmpKey = [NSString stringWithFormat:@"USER.%d.QUESTS",profileNumber];
         [standardUserDefaults setObject:[NSKeyedArchiver archivedDataWithRootObject:availableQuests] forKey:tmpKey];
         */
        
        
        
		//PENDING_DEEPAKstandardUserDefaults->synchronize();
	}
    
    
	return;
	
}





CCString *menuLayer::base64forData(CCData* theData )
{
    
    /* PENDING_DEEPAK  Becoz dataWithLength
     const uint8_t* input = (const uint8_t*)theData->getBytes();
     CCInteger length = (int)theData->getSize();
     
     static char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
     
     CCData* data = CCData::dataWithLength:((length + 2) / 3) * 4];
     uint8_t* output = (uint8_t*)data.mutableBytes;
     
     CCInteger i;
     for (i=0; i < length; i += 3) {
     NSInteger value = 0;
     NSInteger j;
     for (j = i; j < (i + 3); j++) {
     value <<= 8;
     
     if (j < length) {
     value |= (0xFF & input[j]);
     }
     }
     
     NSInteger theIndex = (i / 3) * 4;
     output[theIndex + 0] =                    table[(value >> 18) & 0x3F];
     output[theIndex + 1] =                    table[(value >> 12) & 0x3F];
     output[theIndex + 2] = (i + 1) < length ? table[(value >> 6)  & 0x3F] : '=';
     output[theIndex + 3] = (i + 2) < length ? table[(value >> 0)  & 0x3F] : '=';
     }
     
     return [[[NSString alloc] initWithData:data encoding:NSASCIIStringEncoding] autorelease];
     }
     
     
     -(NSData *) dictToData: (NSDictionary *) dict {
     NSMutableData *data = [[NSMutableData alloc]init];
     NSKeyedArchiver *archiver = [[NSKeyedArchiver alloc]initForWritingWithMutableData:data];
     [archiver encodeObject:dict forKey: @"key"];
     [archiver finishEncoding];
     [archiver release];
     return [data autorelease];
     }
     
     -(NSDictionary *) dataToDict:(NSData *)data {
     NSKeyedUnarchiver *unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
     NSDictionary * dict = [unarchiver decodeObjectForKey: @"key"];
     [unarchiver finishDecoding];
     [unarchiver release];
     return dict;
     }
     
     
     */
}




CCData *menuLayer::dictToData(CCDictionary * dict)
{
    CCData *data ;
    //    NSKeyedArchiver *archiver = [[NSKeyedArchiver alloc]initForWritingWithMutableData:data];
    //    [archiver encodeObject:dict forKey: @"key"];
    //    [archiver finishEncoding];
    //    [archiver release];
    return data;
}

CCDictionary *menuLayer:: dataToDict(CCData *data)
{
    //    NSKeyedUnarchiver *unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    //    NSDictionary * dict = [unarchiver decodeObjectForKey: @"key"];
    //    [unarchiver finishDecoding];
    //    [unarchiver release];
    //    return dict;
    
    
}



void menuLayer::loadAccount()
{
    
	if((retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.POSITION",profileNumber))) == NULL)
    {
        //Error Finding Save File
        profileDisplay();
        return;
        
    } 
    else 
    {
        
        
		CCArray * userData = new CCArray();
        userData->addObject(convertedString->componentsSeparatedByString((CCString::createWithFormat("USER.%d.POSITION",profileNumber)), CCString::create(","))); 
		
        
        
        
        //statResetsRemaining
        CCString * tmpStatResets =retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.STATRESETS",profileNumber));
        
        if( tmpStatResets != NULL ) 
        {
            if( tmpStatResets->isEqual(CCString::create("")) == false )
            {
                statResetsRemaining = (int)tmpStatResets;
            }
        } 
        else 
        {
            statResetsRemaining = 1;
        }
        
        CCString * tmpSeed = retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.SEED",profileNumber));
        
        if( tmpSeed != NULL ) 
        {
            if( tmpSeed->isEqual(CCString::create(""))== false ) 
            {
                seed = (int)tmpSeed;
            }
        }
        
        
        CCString * tmpExpShare = retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.EXPSHARE",profileNumber));
        
        if( tmpExpShare != NULL)
        {
            if( tmpExpShare->isEqual(CCString::create("")) == false )
            {
                expSharePurchased = (int)tmpExpShare;
            }
        }
        
        CCString * tmpClassFilter = retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.CLASSFILTER",profileNumber));
        
        if( tmpClassFilter != NULL ) 
        {
            if( tmpClassFilter->isEqual(CCString::create("")) == false ) 
            {
                classFilter = (int)tmpClassFilter;
            }
        }
        
        
        
        CCString * tmpControlMode = retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.CONTROL",profileNumber));
        
        if( tmpControlMode != NULL )
        {
            if( tmpControlMode->isEqual(CCString::create("")) == false ) 
            {
                controlMode = (int)tmpControlMode;
            }
        }
        
        
        CCString * tmpQuestMenu =retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.QUESTMENU",profileNumber));
        
        if( tmpQuestMenu != NULL )
        {
            if( tmpQuestMenu->isEqual(CCString::create("")) == false )
            {
                questMenu = (int)tmpQuestMenu;
            }
        }
        
        
        CCString * tmpMusicName = retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.MUSIC",profileNumber));
        
        if(tmpMusicName  != NULL )
        {
            
            playSong(tmpMusicName->getCString());
        }
        
        
        CCString * tmpStrCoin = retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.COIN",profileNumber));
        
        if( tmpStrCoin != NULL ) 
        {
            coin = (int)tmpStrCoin;
        } 
        else
        {
            //coin = 100000;
        }
        
//        zone->release();
        zone = NULL;
        zone = CCString::create(retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.ZONE",profileNumber))->getCString());
        
        activeScript->addObject(convertedString->componentsSeparatedByString(CCString::createWithFormat("Set Zone\t%s^",zone->getCString()),CCString::create("\t")));
        
//        weather->release();
        weather = NULL;
        weather = CCString::create(retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.WEATHER",profileNumber))->getCString());
        
        activeScript->addObject( convertedString->componentsSeparatedByString(CCString::createWithFormat("Change Weather\t%s^",weather->getCString()),CCString::create("\t")));
        
//        monsters->release();
//        globalSettings->release();
//        inventory->release();
//        monsters = NULL;
        globalSettings = NULL;
        inventory = NULL;
        
        
        
        
        CCUserDefault *standardUserDefaults =  CCUserDefault::sharedUserDefault();
        if (standardUserDefaults) 
        {
            
            /* PENDING_DEEPAK-BECAUSE "NSData+Base64
             CCData *data =this->dataFromBase64String(this->retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.ITEMS",profileNumber]]];
             inventory = [[NSMutableDictionary alloc] initWithDictionary: [self dataToDict: data]];
             
             data = [NSData dataFromBase64String: [self retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.MONSEEN",profileNumber]]];
             monstersSeen = [[NSMutableDictionary alloc] initWithDictionary: [self dataToDict: data]];
             
             data = [NSData dataFromBase64String: [self retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.MONCAUGHT",profileNumber]]];
             monstersCaught = [[NSMutableDictionary alloc] initWithDictionary: [self dataToDict: data]];
             
             data = [NSData dataFromBase64String: [self retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.GLOBALS",profileNumber]]];
             globalSettings = [[NSMutableDictionary alloc] initWithDictionary: [self dataToDict: data]];
             
             
             
             data = [NSData dataFromBase64String: [self retrieveFromUserDefaults:[NSString stringWithFormat:@"USER.%d.MONSTERS",profileNumber]]];
             monsters = [[NSMutableArray alloc] initWithArray: [NSKeyedUnarchiver unarchiveObjectWithData:data]];
             
             data = [NSData dataFromBase64String: [self retrieveFromStdUserDefaults:[NSString stringWithFormat:@"USER.%d.QUESTS",profileNumber]]];
             availableQuests = [[NSMutableArray alloc] initWithArray: [NSKeyedUnarchiver unarchiveObjectWithData:data]];
             
             */
            
            for(int i=0;i<monsters->count();i++)
            {
                monster * mon= (monster*)monsters->objectAtIndex(i);
                mon->check(database);
            }
            
            for(int i=0;i<availableQuests->count();i++)
            {
                questTemplate * quest=(questTemplate*)availableQuests->objectAtIndex(i);
                quest->reloadWithParent(g_menuLayer);
            }
            /*
             if( questMenu > -1 ) {
             [[availableQuests objectAtIndex:questMenu] addAllEvents];
             
             
             }
             */
            
            
            /*   
             CCString * tmpKey = CCString::createWithFormat("USER.%d.GLOBALS",profileNumber);
             globalSettings-> initWithDictionary:[standardUserDefaults objectForKey:tmpKey]];
             globalSettings
             
             tmpKey = [NSString stringWithFormat:@"USER.%d.ITEMS",profileNumber];
             inventory = [[NSMutableDictionary alloc] initWithDictionary: [standardUserDefaults objectForKey:tmpKey]];
             
             
             tmpKey = [NSString stringWithFormat:@"USER.%d.MONSEEN",profileNumber];
             if( [standardUserDefaults objectForKey:tmpKey] != nil ) {
             [monstersSeen release];
             monstersSeen = [[NSMutableDictionary alloc] initWithDictionary: [standardUserDefaults objectForKey:tmpKey]];
             }
             
             
             tmpKey = [NSString stringWithFormat:@"USER.%d.MONCAUGHT",profileNumber];
             if( [standardUserDefaults objectForKey:tmpKey] != nil ) {
             [monstersCaught release];
             monstersCaught = [[NSMutableDictionary alloc] initWithDictionary: [standardUserDefaults objectForKey:tmpKey]];
             }
             */
            
            //PENDING_DEEPAK[standardUserDefaults synchronize];
        }
        
        CCString * tmpStr = CCString::create((retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.STEPSTAKEN",profileNumber)))->getCString());
        
        if( tmpStr !=NULL )
        {
            if( tmpStr->isEqual(CCString::create("")) == false ) 
            {
                /*PENDING_DEEPAK NSNumberFormatter * formatter = [[NSNumberFormatter alloc] init];
                 stepsTaken = [[formatter numberFromString:tmpStr] unsignedLongValue];
                 [formatter release];*/
            }
        }
        
        tmpStr = CCString::create((retrieveFromUserDefaults(CCString::createWithFormat("USER.%d.MISSIONSCOMPLETED",profileNumber)))->getCString());
        
        if( tmpStr != NULL ) 
        {
            missionsAccomplished = (int)tmpStr;
        }
        
		//[self displayGame:@"seedMap.1002.14.tmx" andPosition: ccp(2,3)];
		//PENDING_DEEPAK userData this->displayGame((CCString*)userData->objectAtIndex(0),    ccp([[userData objectAtIndex:1] intValue],[[userData objectAtIndex:2] intValue])];
        this->displayMenuButton();
        
        if( mapIsGeoRealm() ) 
        {
            //questEvents
            
            //Rebuild array
            buildQuestFilter();
            
            if( questMenu < filteredQuests->count())
            {
                questTemplate * tmp = (questTemplate*)filteredQuests->objectAtIndex(questMenu);
                tmp->addAllEvents();
            }
        }
        
        
        activeScript->addObject(convertedString->componentsSeparatedByString(CCString::create("Fade In\t^"), CCString::create("\t")));
        scriptProgress();
        
        
        
        
        
        
        /*
         for(monster * mon in monsters) {
         
         [self sawMonster: [mon getMonster].monid];
         [self caughtMonster: [mon getMonster].monid];
         }
         */
        /* //PENDING_DEEPAK MKStoreManager [[MKStoreManager sharedManager] requestProductData];
         [[MKStoreManager sharedManager].purchasableObjects count];*/
	}
}





void menuLayer::displayGame(CCString * withMap,CCPoint mapPosition)
{
	menuStage = 999;
	
	menuItems->removeAllObjects();
    
    
    btnTalkPosition = CCPoint((CCDirector::sharedDirector()->getWinSize().width)-40, 320-235);
    btnRunPosition = CCPoint((CCDirector::sharedDirector()->getWinSize().width)-40,320-35);
    
	//[self playSong:MUSIC_INTRO];
	spriteAtPosition(CCString::create("bg1.png"),ccp((CCDirector::sharedDirector()->getWinSize().width)/2,160),1);
    spriteAtPosition(CCString::create("buttonTalk.png"),btnTalkPosition,41);
    spriteAtPosition(CCString::create("buttonRun.png"),btnRunPosition,41);
    
    btnRunOn->initWithFile(CCString::create("buttonRunOn.png"));
    btnRunOn->addToLayer(g_menuLayer,42);
    btnRunOn->updateOpacity(0);
    btnRunOn->updatePosition(btnRunPosition);
    
    //320-285 == 35
    
    
    btnScalePosition = CCPoint((CCDirector::sharedDirector()->getWinSize().width)-40, 320-290);
    spriteAtPosition(CCString::create("ZoomIcon.png"),btnScalePosition,41);
    
    btnKeypad= new CoolSprite();
    btnKeypad->initWithFile(CCString::create("dpad.png"));
    btnKeypad->addToLayer(g_menuLayer,41);
    
    if( controlMode == control_mode_fixed ) 
    {
        keypadPosition = ccp(68,320-256);
        btnKeypad->updatePosition(keypadPosition);
        bKeypadOn = true;
    } 
    else 
    {
        btnKeypad->updatePosition(ccp(-999,-999));
        
    }
    btnKeypad->updateOpacity(180);
    menuItems->addObject(btnKeypad);
    btnKeypad->updatePosition(ccp(keypadPosition.x,keypadPosition.y));
    
	if( clouds == NULL ) 
    {
		clouds = new CoolSprite();
        clouds->initWithFile(CCString::create("clouds.png"));
		clouds->addToLayer(g_menuLayer,29);
		clouds->updatePosition(ccp((CCDirector::sharedDirector()->getWinSize().width)/2,320/2));
		clouds->updateOpacity(0);
		clouds->updateScale(1.7);
		
		blackOverlay = new CoolSprite();
        blackOverlay->initWithFile(CCString::create("blackOverlay.png"));
		blackOverlay->addToLayer(g_menuLayer,28);
		blackOverlay->updatePosition(ccp((CCDirector::sharedDirector()->getWinSize().width)/2,320/2));
		blackOverlay->updateOpacity(0);
		
		glare = new CoolSprite();
        glare->initWithFile(CCString::create("glare.png"));
		glare->addToLayer(g_menuLayer,28);
		glare->updatePosition(ccp((CCDirector::sharedDirector()->getWinSize().width)/2,320/2));
		glare->updateOpacity(0);
		
		blackCover =  new CoolSprite();
        blackCover->initWithFile(CCString::create("blackCover.png"));
		blackCover->addToLayer(g_menuLayer,28);
		blackCover->updatePosition(ccp((CCDirector::sharedDirector()->getWinSize().width)/2,320/2));
		blackCover->updateOpacity(255);
        
		redFlash = new CoolSprite();
        redFlash->initWithFile(CCString::create("redFlash.png"));
		redFlash->addToLayer(g_menuLayer,28);
		redFlash->updatePosition(ccp(480/2,320/2));
		redFlash->updateOpacity(0);
        
        
		rainEmitter = new CCParticleRain();
        rainEmitter->setTexture(CCTextureCache::sharedTextureCache()->addImage("rainParticle.png"));
		
		rainEmitter->setPosition(ccp(240,320));
		//double the normal
        rainEmitter->setEmissionRate(40);
        
		addChild(rainEmitter,30);
		rainEmitter->stopSystem();
		
		snowEmitter =new CCParticleSnow();
		snowEmitter->setTexture(CCTextureCache::sharedTextureCache()->addImage("snowParticle.png"));
		snowEmitter->setPosition(ccp(240,320));
		addChild(snowEmitter,30);
		snowEmitter->stopSystem();
	}
    
	
	if( withMap != NULL ) 
    {
		this->loadMap(withMap, mapPosition);
	} 
    else 
    {
		
	}
    
    int seed = rand() % 3 + 1;
    database->seed= seed;
	
    gameEvent * event = eventByName( CCString::create("SYS.Game Start"));
    if( event != NULL )
    {
        triggerEvent( event, false);
    }
    
    //~Display Credits	^
    
    
    //NSString * tmpStr = [NSString stringWithFormat:@"Display Credits\t"]; 
    //[self addScript:[tmpStr componentsSeparatedByString:@"\t"]];
	
}




void menuLayer::displayMenuButton()
{
    btnMenuPosition = ccp((CCDirector::sharedDirector()->getWinSize().width) - 95,320-290);
    spriteAtPosition(CCString::create("buttonMenu.png") ,btnMenuPosition,41);
	//[self spriteAtPosition: @"buttonOrange.png" andPosition:ccp(100+42+120,480-310-64) andZ: 41];
	//[self freeformAtPosition:@"Menu" andStyle:FONT_WHITE fontSize:0.45 andMaxWidth:310 instant:false andPosition:ccp(100+42+3+120,480-310-64+15) andZ:45];
}


void menuLayer::loadMap(CCString * mapName,CCPoint mapPosition)
{
	
    //  printf( "Load Map: %s\n", mapName->UTF8String());
    
    double oldScale = gameScale;
    changeGameScaleTo(1);
    
	//NSURL *url = [NSURL fileURLWithPath:xmlFilename];	
	this->resetKeys();
	
	if( mapFilename != NULL ) 
    {
		mapFilename->release();
		mapFilename = NULL;
	}
	mapFilename->create(mapName->getCString());
	
	if( map != NULL ) 
    {
		removeChild(layerAbove,false);
        layerAbove->release();
        layerAbove = NULL;
        
		removeChild(map,false);
		map->release();
		map = NULL;
        
	}
	map = new CCTMXTiledMap();
    map->create(mapName->getCString());
	map->setPosition(ccp(240,60));
     map->setScale(gameScale);
	addChild(map,8);
	
    printf( "Load Map: Map Object Created\n");
    
    
    
	layerAbove = map->layerNamed("Above");
    if( layerAbove != NULL )
    {
        layerAbove->retain();
        map->removeChild(layerAbove,false);
        addChild(layerAbove,12);
        layerAbove->setScale(gameScale);
    }
    printf( "Load Map: Top Layer Isolated\n");
    
	me->mapPosition = mapPosition;
	this->setMapCenter();
	
	mapEvents->removeAllObjects();
    printf( "Load Map: Map Repositioned\n");
    
	/* PENDING_DEEPAK NSBundle
     NSString* path = [[NSBundle mainBundle] pathForResource:mapName ofType:@"dat"];
     NSString* content = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:NULL];
     NSArray * dataLines = [content componentsSeparatedByString:@"\n"];
     
     printf( "Load Map: Event Data Loaded\n");
     
     for(NSString * eventStr in dataLines) {
     if( [eventStr isEqualToString:@""] == false ) {
     NSArray * eventData = [eventStr componentsSeparatedByString:@"|"];
     
     gameEvent * newEvent = [[gameEvent alloc] initWithData: eventData andLayer:self];
     [mapEvents addObject:newEvent];
     [newEvent scaleTo: gameScale];
     [newEvent release];
     }
     }
     */
    printf( "Load Map: Events Created\n");
    
    
    if( mapIsGeoRealm() ) 
    {
        printf( "Load Map: Map is in the GeoRealm\n");
        
        CCArray * tmpArray = CCArray::create( CCString::create(convertedString->componentsSeparatedByString(mapFilename, CCString::create("."))->getCString()));
        if( tmpArray->count() > 2 ) 
        {
            mapNumber =(int)tmpArray->objectAtIndex(2);
            
            
            if( filteredQuests->count() > 0 )
            {
                (((questTemplate*)filteredQuests->objectAtIndex(questMenu))->loadedMap(mapNumber));
            }
        }
    }
    
    printf( "Load Map: Checking for No SYS.OnLoad Event\n");
    if(eventByName(CCString::create( "SYS.OnLoad")) != NULL ) 
    {
        printf( "Load Map: SYS.OnLoad Event Found\n");
        //    [self triggerEvent:[self eventByName:@"SYS.OnLoad"] onCollision: false];
        
        triggerEvent((gameEvent*)CCString::create("SYS.OnLoad"), false); 
        
    } 
    else 
    {
        printf( "Load Map: No SYS.OnLoad Event Found\n");
        
    }
    
    changeGameScaleTo(oldScale);
	
}



void menuLayer::setMapCenter()
{
	int width = CCDirector::sharedDirector()->getWinSize().width;
	int height = CCDirector::sharedDirector()->getWinSize().height;
	int ySink = 4;
	
	int MyX = me->mapPosition.x * 16 * gameScale;
	int MyY = me->mapPosition.y * 16 * gameScale;
    
    double mapWidth = map->getMapSize().width * map->getTileSize().width * gameScale;
    double mapHeight = map->getMapSize().height * map->getTileSize().height * gameScale;
	
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	winSize.width = width;
	winSize.height = height;
	
	
	int xTmp = MAX(MyX, winSize.width / 2);
	int yTmp = MAX(MyY, winSize.height / 2);
	xTmp = MIN(xTmp, mapWidth
               - winSize.width / 2);
	yTmp = MIN(yTmp, mapHeight 
               - winSize.height/2);
	CCPoint actualPosition = ccp(xTmp, yTmp);
	
	CCPoint centerOfView = ccp(width/2, height/2);
	CCPoint viewPoint = ccpSub(centerOfView, actualPosition);
	
	int heroStepX = 0;
	int heroStepY = 0;
	if( heroDirection == 0 ) 
    {
		heroStepY = heroStepPart * gameScale;
	} 
    else if( heroDirection == 1 ) 
    {
		heroStepY = -heroStepPart * gameScale;
	} 
    else if( heroDirection == 2 ) 
    {
		heroStepX = heroStepPart * gameScale;
	} 
    else if( heroDirection == 3 )
    {
		
        heroStepX = -heroStepPart * gameScale;
	}  
	
	
	if( MyX-heroStepX > mapWidth - width/2)
    {
		heroStepX = 0;
	}
	if( MyX-heroStepX < width/2 ) 
    {
		heroStepX = 0;
	}
	
	if( MyY-heroStepY > mapHeight - height/2 )
    {
		heroStepY=0;
	}
	if( MyY-heroStepY < height/2 )
    {
		heroStepY=0;
	}
	
	
	int additionalDown = height - mapHeight;
	
	mapLeft = viewPoint.x + heroStepX ;//+11;
	mapTop =(viewPoint.y+heroStepY)*-1+additionalDown;
	
	//NSLog([NSString stringWithFormat:@"Map Position: %d, %d",mapLeft,mapTop]);
    
    if( layerAbove != NULL )
    {
        layerAbove->setPosition(ccp(mapLeft,mapTop));
    }
    
	map->setPosition(ccp(mapLeft,mapTop));
	clouds->updatePosition(ccp(mapLeft+(mapWidth)/2,mapTop+(mapHeight)/2));
	blackOverlay->updatePosition(ccp(mapLeft+(mapWidth)/2,mapTop+(mapHeight)/2));
	//User position should update as if it was an event, theirfore it should not be done in this function but rather in the gameEvent Class.
	//me.
	//[me updatePosition:ccp( width/2 + offsetX , height/2 + offsetY - ySink )];
}


void menuLayer::setGlobal(CCString * key,CCString * value)
{
    globalSettings->setObject(value,key->getCString());
}



bool menuLayer::getGlobalBool(CCString * key)
{
    CCString * value = CCString::create(globalSettings->valueForKey(key->getCString())->getCString());
    if( value->isEqual(CCString::create("T")))
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

void menuLayer::updateGlobal(CCString * globalName,int action)
{
	if( action == 0 ) 
    {
		this->setGlobal(globalName,CCString::create("F"));
	}
    else if( action == 1 ) 
    {
		this->setGlobal(globalName,CCString::create("T"));
	} 
    else 
    {
		if( this->globalValue(globalName) ) 
        {
			this->setGlobal(globalName,CCString::create("F"));
		} 
        else 
        {
			this->setGlobal(globalName,CCString::create("T"));
		}
	}  
}

bool menuLayer::globalValue(CCString * globalName)
{
    return this->getGlobalBool(globalName);
    /*
     if( [self retrieveFromUserDefaults:[NSString stringWithFormat:@"GLOBAL_%d_%@",profileNumber,globalName]] == nil ) {
     return false;
     } else {
     if( [[self retrieveFromUserDefaults:[NSString stringWithFormat:@"GLOBAL_%d_%@",profileNumber,globalName]] isEqualToString:@"F"] ) {
     return false;
     } else {
     return true;
     }
     }
     */
}

void menuLayer::eventCheck()
{
    for(int i=0; i<mapEvents->count();i++)
	{
        gameEvent * evnt= (gameEvent*)mapEvents->objectAtIndex(i); 
		
		if( evnt->mapPosition.x == me->mapPosition.x && evnt->mapPosition.y == me->mapPosition.y  ) 
        {
			if( evnt->onWalk() && evnt->isEnabled() && activeScript->count() == 0 && evnt->getScript() != NULL)
            {
                if( triggerEvent( evnt, false) )
                {
					return;
				}
			}
		}
		
		if( evnt->isEnabled() && (evnt->onViewCollisionX1() || evnt->onViewCollisionX2() || evnt->onViewCollisionX3())  && activeScript->count()== 0 && evnt->getScript() != NULL)
        {
			int stepsCheck = 1;
			if( evnt->onViewCollisionX2())
            {
                stepsCheck = 2;
            }
            
            if( evnt->onViewCollisionX3() )
            {
                stepsCheck = 3;
            }
            for(int check = 1;check <= stepsCheck;check++) 
            {
                if( evnt->mapPosition.x+check == me->mapPosition.x && evnt->mapPosition.y == me->mapPosition.y && evnt->getDirection() == 3 )
                {
                    
                    if( triggerEvent(evnt, true) ) 
                    {
                        return;
                    }
                }
                if( evnt->mapPosition.x-check == me->mapPosition.x && evnt->mapPosition.y == me->mapPosition.y && evnt->getDirection() == 2  )
                {
                    
                    if( triggerEvent(evnt,true) )
                    {
                        return;
                    }
                }
                if( evnt->mapPosition.x == me->mapPosition.x && evnt->mapPosition.y+check == me->mapPosition.y && evnt->getDirection() == 1  )
                {
                    
                    if( triggerEvent( evnt,true) ) {
                        return;
                    }
                }
                if( evnt->mapPosition.x == me->mapPosition.x && evnt->mapPosition.y-check == me->mapPosition.y && evnt->getDirection() == 0  )
                {
                    if( triggerEvent(evnt, true) )
                    {
                        return;
                    }
                }
            }
        }
    }
}





void menuLayer::arrivedOnTile()
{
     stepsTaken++;
    this->eventCheck();
    
    if( mapIsGeoRealm() && activeScript->count() == 0) 
    {
        //Check for portals between maps.
        int newX =  me->mapPosition.x ;
        int newY =  me->mapPosition.y ;
        CCString * tmpStr = NULL;
        
        
        if( me->mapPosition.y == 0 ) 
        {
            if( mapNumber > 4 ) 
            {
                //Can Warp Upwards
                newY = 46;
                tmpStr = CCString::createWithFormat("seedMap.%s.%d.tmx",((CCString*)((CCArray*)(convertedString->componentsSeparatedByString(mapFilename, CCString::create("."))->getCString()))->objectAtIndex(1))->getCString(),mapNumber-5);
            }
        }
        else if( me->mapPosition.x == 0 )
        {
            if(  mapNumber != 0 && mapNumber != 5 && mapNumber != 10  ) 
            {
                //Can Warp Left
                newX = 46;
                tmpStr = CCString::createWithFormat("seedMap.%s.%d.tmx",((CCString*)((CCArray*)(convertedString->componentsSeparatedByString(mapFilename, CCString::create("."))->getCString()))->objectAtIndex(1))->getCString(),mapNumber-1);
            }
        } else if( me->mapPosition.y == 47 ) 
        {
            if( mapNumber < 10 ) 
            {
                //Can Warp Downwards
                newY = 1;
                tmpStr =CCString::createWithFormat("seedMap.%s.%d.tmx",((CCString*)((CCArray*)(convertedString->componentsSeparatedByString(mapFilename, CCString::create("."))->getCString()))->objectAtIndex(1))->getCString(),mapNumber+5);
            }
        } else if( me->mapPosition.x == 47 )
        {
            if(  mapNumber != 4 && mapNumber != 9 && mapNumber != 14  )
            {
                //Can Warp Right
                newX = 1;
                tmpStr = CCString::createWithFormat("seedMap.%s.%d.tmx",((CCString*)((CCArray*)(convertedString->componentsSeparatedByString(mapFilename, CCString::create("."))->getCString()))->objectAtIndex(1))->getCString(),mapNumber+1);
                
            }
        } 
        
        if( tmpStr != NULL ) 
        {
            
            CCString * tmpCmd = CCString::createWithFormat("Relocate User\t%s^%d^%d",tmpStr->getCString(), newX, newY); 
            
            addScript(CCArray::create(convertedString->componentsSeparatedByString(tmpCmd, CCString::create("\t"))));
            
            scriptProgress();
            
            return;
        }
    }
    
    
    
    
    
    if( zoneMonsters->count() > 0 )
    {
        stepTimer++;
        
        int chanceOfEncounter = 0;
        if( stepTimer < 25 ) 
        {
            chanceOfEncounter = 0; //0%
        } 
        else if( stepTimer < 35 ) 
        {
            chanceOfEncounter = 5; //25%
        } 
        else if( stepTimer < 45 )
        {
            chanceOfEncounter = 10; //45%
        } 
        else if( stepTimer < 100 )
        {
            chanceOfEncounter = 25; //80%
        } 
        
        int result = arc4random()% 100;
        if( result <= chanceOfEncounter && chanceOfEncounter != 0 ) {
            stepTimer = 0;
            //Encounter Wild Monster
            
            CCString * battleData = CCString::createWithFormat("TRUE^");
            int opponentCount = rand() % 3+1;
            for(int i=1; i<=opponentCount;i++)
            {
                
                dataZoneMonster * wildMon = NULL;
                
                int counter = 0;
                for(int k=0;k<zoneMonsters->count();k++)
                {
                    dataZoneMonster * tmpMon =(dataZoneMonster*)zoneMonsters->objectAtIndex(k);
                    counter = counter + tmpMon->getMonster()->rarity * 100000;
                }
                result = arc4random() % counter;
                
                counter = 0;
                for(int k=0;k<zoneMonsters->count();k++) 
                {
                    dataZoneMonster * tmpMon = (dataZoneMonster*)zoneMonsters->objectAtIndex(k);
                    int oldInt = counter;
                    counter = counter + tmpMon->getMonster()->rarity * 100000;
                    if( result >= oldInt && result < counter ) 
                    {
                        wildMon = (dataZoneMonster*)zoneMonsters->objectAtIndex(k);
                    }
                }
                
                int level = rand() % (wildMon->levelhigh - wildMon->levellow) + wildMon->levellow;
                
                if(mapIsGeoRealm() ) 
                {
                    if( questClass() > 0 )
                    {
                        level = (int)((double)level * ((double)(questClass()/2)));
                    }
                    
                }
                
                std::string tempString= battleData->getCString();
                tempString.append(  CCString::createWithFormat("MON,%d,%d.",wildMon->monid,level)->getCString());
                
            }
            
            //DEBUG MODE
            //return;
            
            if( IS_DEBUG_MODE )
            {
                return;
            }
            
            this->battleStart((CCArray*)(convertedString->componentsSeparatedByString(battleData, CCString::create("^"))->getCString()), true);
            
            return;
        }
    }
}


void menuLayer::battleStart(CCArray *args,bool bWild)
{
    this->resetKeys();
    resignTimer();
    
    bBattleStarted = true;
    
    /*PENDING_DEEPAK battleScene
     
     battleScene * bs =   new battleScene(); [[battleScene alloc] initWithParent:self andBattleData: args ];
     [parent stopAllActions];
     [[CCDirector sharedDirector] pushScene:[CCSplitRowsTransition transitionWithDuration:1.5 scene:bs]];
     [bs startTimer];
     [self battleMusicStart: bWild];
     
     [bs release];*/
}



bool menuLayer::tileIsFreeFromEvents(CCPoint pos)
{
	bool bFree = this->tileIsFreeFromEvent(me,pos);
    if( !bFree )
        return false;
    for(int i=0; i<mapEvents->count();i++) 
    {
        gameEvent * evnt= (gameEvent*)mapEvents->objectAtIndex(i); 
		
        if( evnt->isEnabled() && evnt->hasAppearance())
        {
            bool bFree = this->tileIsFreeFromEvent(evnt,pos);
            if( !bFree )
                return false;
        }
        
        if( evnt->spriteSize.size.width == 48 ) 
        {
            if( evnt->mapPosition.x-1 == pos.x && evnt->mapPosition.y == pos.y ) 
            {
                if( evnt->isEnabled() && evnt->hasAppearance() )
                {
                    return false;
                }
            }
        }
	}
	return true;
}

bool menuLayer::tileIsFreeFromEvent(gameEvent *evnt,CCPoint pos)
{
    //event is standing still in that cell
    if( evnt->mapPosition.x == pos.x && evnt->mapPosition.y == pos.y )
    {
        return false;
    }
    
    //event is walking up into the checked tile
    if( evnt->mapPosition.x == pos.x && evnt->mapPosition.y+1 == pos.y && evnt->getDirection() == direction_up && evnt->stepPart != 0 )
    {
        return false;
    }
    
    //event is walking down into the checked tile
    if( evnt->mapPosition.x == pos.x && evnt->mapPosition.y-1 == pos.y && evnt->getDirection() == direction_down && evnt->stepPart != 0 ) 
    {
        return false;
    }
    
    //event is walking left into the checked tile
    if( evnt->mapPosition.x+1 == pos.x && evnt->mapPosition.y == pos.y && evnt->getDirection() == direction_left && evnt->stepPart != 0 ) 
    {
        return false;
    }
    
    //event is walking right into the checked tile
    if( evnt->mapPosition.x-1 == pos.x && evnt->mapPosition.y == pos.y && evnt->getDirection() == direction_right && evnt->stepPart != 0 ) 
    {
        return false;
    }
    return true;
}



void menuLayer::evaluateGame()
{
	
	if( activeScript->count() > 0 ) 
    {
        scriptCheck();
	}
	
	me->evaluate();
	heroStepPart = me->stepPart;
	heroDirection = me->getDirection();
	
	
	//No Scripts are running
	if( activeScript->count() == 0 ) 
    {
		if( me->moveQueueSize() == 0 )
        {
			if( bKeyUp ) 
            {
				me->addMoveQueue(CCString::create("Up"));
			} 
            else if( bKeyDown )
            {
				me->addMoveQueue(CCString::create("Down"));
			} else if( bKeyLeft ) 
            {
				me->addMoveQueue(CCString::create("Left"));
			} 
            else if( bKeyRight )
            {
				me->addMoveQueue(CCString::create("Right"));
			}
		}
	}
	
	this->setMapCenter();
    
	for(int i=0;i<mapEvents->count();i++)
    {
        
        gameEvent * evnt =(gameEvent*)mapEvents->objectAtIndex(i);
		evnt->evaluate();
	}
}


void menuLayer::resetKeys()
{
	
	bKeyUp = false;
	bKeyDown = false;
	bKeyLeft = false;
	bKeyRight = false;
    
}

void menuLayer::touchGameStop(CCPoint  touch)
{
    /*
     CGPoint btnTalkPosition;
     CGPoint btnRunPosition;
     CGPoint btnMenuPosition;
     */
    //Menu Button
    if( activeScript->count() == 0 && monsters->count() > 0 )
    {
        CCPoint button = btnMenuPosition;
        if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
        {
            if( touch.y > button.y -25 && touch.y < button.y + 25 )
            {
                this->resetKeys();
                sfx(CCString::create(SOUND_CONFIRM));
                 gearMenuLayer->bIsActive = true;
                 gearMenuLayer->bIsOnPC = false;
                 gearMenuLayer->displayIndex();
                gearMenuLayer->setPosition(ccp(0,0));
                return;
            }
        }
    }
    
    //run button
    CCPoint button = btnRunPosition;
	if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
    {
		if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
        {
            return;
        }
    }
    
	button  = btnScalePosition;
	if( touch.x > button.x -35 && touch.x < button.x + 35 )
    {
		if( touch.y > button.y -35 && touch.y < button.y + 35 )
        {
            if( gameScale == 1 ) 
            {
                 changeGameScaleTo( 2);
            } 
            else 
            {
                changeGameScaleTo( 1);
            }
            return;
        }
    }
    
    
    
    
	button  = btnMenuPosition;
	if( touch.x > button.x -35 && touch.x < button.x + 35 ) 
    {
		if( touch.y > button.y -35 && touch.y < button.y + 35 ) 
        {
            return;
        }
    }
    
	this->resetKeys();
    
    //Disable the new keypad
    if( controlMode == control_mode_dynamic ) 
    {
        bKeypadOn = false;
        btnKeypad->updatePosition(ccp(-999,-999));
    }
    
}


void menuLayer::touchGameStart(CCPoint touch)
{
	CCPoint button;
    /*
     CGPoint btnTalkPosition;
     CGPoint btnRunPosition;
     CGPoint btnMenuPosition;
     */
	
    //Transfer the touch over to the scripting engine if scripts are running
	if( activeScript->count() > 0 )
    {
        scriptTouch( touch);
        return;
    }
    
    //Check if the touch was on the Run Button
	button = btnRunPosition;
	if( touch.x > button.x -25 && touch.x < button.x + 25 ) 
    {
		if( touch.y > button.y -25 && touch.y < button.y + 25 ) 
        {
			//Right
			bKeyC = !bKeyC;
            
            if( bKeyC )
            {
                btnRunOn->updateOpacity(255);
            } 
            else 
            {
                 btnRunOn->updateOpacity(0);
            }
            //Exit if we had a match
            return;
		}
	}
    
    
	//Check for the talk button
	button  = btnTalkPosition;
	if( touch.x > button.x -35 && touch.x < button.x + 35 )
    {
		if( touch.y > button.y -35 && touch.y < button.y + 35 ) 
        {
			//Talk
			
            //Check if there is an event to talk to.
            for(int i=0;i<mapEvents->count();i++)
            {
                
                gameEvent * evnt= (gameEvent*)mapEvents->objectAtIndex(i);
				if( evnt->isEnabled() && evnt->onTalk() && activeScript->count() == 0 && evnt->getScript() != NULL )
                {
					int checkX = 0;
					int checkY = 0;
					if( me->getDirection() == 0 ) 
						checkY = -1;
                    if( me->getDirection() == 1 ) 
                        checkY = 1;
                    if( me->getDirection() == 2 ) 
                        checkX = -1;
                    if( me->getDirection() == 3 ) 
                        checkX = 1;
                    
                    if( evnt->mapPosition.x == me->mapPosition.x+checkX && evnt->mapPosition.y == me->mapPosition.y+checkY  )
                    {
                        sfx(CCString::create(SOUND_CONFIRM));
                        if( triggerEvent(evnt,false)) 
                        {
                            this->resetKeys();
                            
                        }
                        
                    }
				}
			}
            
            //This could cause issues later on
            return;
		}
	}
    
    //keypadPosition
    if( bKeypadOn ) 
    {
        
        
        int dist = 45;
        int distThin = 15;
        
        
        button = ccp(keypadPosition.x,keypadPosition.y+(dist*2));
        if( touch.x > button.x -distThin && touch.x < button.x + distThin ) 
        {
            if( touch.y > button.y -dist*2 && touch.y < button.y + dist*2 ) 
            {
                //Up
                bKeyUp = true;
            }
        }
        button = ccp(keypadPosition.x,keypadPosition.y-(dist*2));
        if( touch.x > button.x -distThin && touch.x < button.x + distThin ) 
        {
            if( touch.y > button.y -dist*2 && touch.y < button.y + dist*2 ) 
            {
                //Down
                bKeyDown = true;
            }
            
        }
        button = ccp(keypadPosition.x-(dist*2),keypadPosition.y);
        if( touch.x > button.x -dist*2 && touch.x < button.x + dist*2 )
        {
            if( touch.y > button.y -distThin && touch.y < button.y + distThin ) 
            {
                //Left
                bKeyLeft = true;
            }
            
        }
        button = ccp(keypadPosition.x+(dist*2),keypadPosition.y);
        if( touch.x > button.x -dist*2 && touch.x < button.x + dist*2 )
        {
            if( touch.y > button.y -distThin && touch.y < button.y + distThin ) 
            {
                //Right
                bKeyRight = true;
            }
        }
        
    } 
    else 
    {
        //Place the keypad so that movement can then be applied.
        
        if( controlMode == control_mode_dynamic ) 
        {
            if( touch.x > 30 && touch.x < 480-120  && touch.y > 40 && touch.y < 320-40 )
            {
                
                keypadPosition.x = touch.x;
                keypadPosition.y = touch.y;
                bKeypadOn = true;
                btnKeypad->updatePosition(ccp(keypadPosition.x,keypadPosition.y));
            }
        }
        
        if( controlMode == control_mode_large ) 
        {
            int diff = 80;
            if( touch.x > 480-diff  && touch.y > diff && touch.y < 320-diff ) 
            {
                 bKeyRight = true;
            }
            if( touch.x < diff  && touch.y > diff && touch.y < 320-diff ) 
            {
                bKeyLeft = true;
            }
            if( touch.y > 320-diff  && touch.x > diff && touch.x < 480-diff )
            {
                bKeyUp = true;
            }
            if( touch.y < diff  && touch.x > diff && touch.x < 480-diff )
            {
                 bKeyDown = true;
            }
        }
        
    }
}

void menuLayer::touchGameSlide(CCPoint touch)
{
	CCPoint button;
	/*
     CGPoint btnTalkPosition;
     CGPoint btnRunPosition;
     CGPoint btnMenuPosition;
     */
    
    //run button
    button = btnRunPosition;
	if( touch.x > button.x -25 && touch.x < button.x + 25 )
    {
		if( touch.y > button.y -25 && touch.y < button.y + 25 )
        {
            return;
        }
    }
    
    
	button  = btnTalkPosition;
	if( touch.x > button.x -35 && touch.x < button.x + 35 ) 
    {
		if( touch.y > button.y -35 && touch.y < button.y + 35 )
        {
            return;
        }
    }
    
	this->resetKeys();
	this->touchGameStart(touch);
	
}















