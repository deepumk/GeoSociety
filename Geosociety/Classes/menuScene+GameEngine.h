////
////  menuScene+GameEngine.h
////  Geosociety
////
////  Created by macbookpro on 04/12/13.
////  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
////
//
//#ifndef Geosociety_menuScene_GameEngine_h
//#define Geosociety_menuScene_GameEngine_h
//#include "gameEvent.h"
//#include "cocos2d.h"
//#include "menuScene.h"
//#include "CCData.h"
//#include "cocos-ext.h"
//#include "StringConvertion.h"
//#include "monster.h"
//#include "questTemplate.h"
//
//USING_NS_CC_EXT;
//USING_NS_CC;
//
//class gameEvent;
//class GameEngine :public CCObject 
//{
//  
//  
//public:
//  void displayGame(CCString * withMap,CCPoint mapPosition);
//  void loadAccount();
//  void loadMap(CCString * mapName,CCPoint mapPosition) ;
//  void arrivedOnTile();
//  void displayMenuButton();
//  void battleStart(CCArray * args,bool bWild);
//  bool tileIsFreeFromEvent(gameEvent * evnt,CCPoint pos);
//  bool tileIsFreeFromEvents(CCPoint pos);
//  void updateGlobal(CCString *globalName,int action);
//  bool globalValue(CCString * globalName);
//  void eventCheck();
//  void saveAccount();
//  void evaluateGame();
//  void touchGameStart(CCPoint touch);
//  void touchGameStop(CCPoint touch);
//  void touchGameSlide(CCPoint touch);
//  void resetKeys();
//  StringConvertion* convertedString;
//    menuLayer* menuLayerObj;
////  menuLayer* tempMenuLayer;
//  void setGlobal(CCString * key,CCString * value);
//  void setMapCenter();
//  bool getGlobalBool(CCString * key);
//  
//    
//  CCData * dictToData(CCDictionary * dict);
//  CCString*base64forData(CCData*theData); 
//    CCDictionary* dataToDict(CCData *data);
//
//};
//
//
//#endif
