////
////  menuScene+items.cpp
////  Geosociety
////
////  Created by macbookpro on 29/11/13.
////  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
////
//
//#include <iostream>
//#include "menuScene+Items.h"
//#include <assert.h>
//#include "menuScene.h"
//
//
//int Items::itemCount(int itemId) 
//{
//    CCString* itemCount =(CCString*)menuLayerObj->inventory->valueForKey("")->intValue();
//   if( itemCount == NULL )
//        return 0;
//    return itemCount ->intValue();
//    
//   
//}
//
//
//
//void Items::useItems(int itemId,int nTimes)
//{
//    CCString * itemCount=(CCString*)menuLayerObj->inventory->valueForKey(CCString::createWithFormat("%d",itemId)->getCString());
//    
//    assert( itemCount != NULL );
//    assert((itemCount-nTimes)>0);
//    
//    menuLayerObj->inventory->setObject(CCString::createWithFormat("%d",(itemCount->intValue()-nTimes)),(CCString::createWithFormat("%d",itemId))->getCString());
//    
//}
//
//
//
//void Items::addItems(int itemId , int nTimes)
//{
//    
//    CCString* itemCount=(CCString*)menuLayerObj->inventory->valueForKey(CCString::createWithFormat("%d",itemId)->getCString()); 
//    
//    if( itemCount == NULL ) 
//    {
//      
//       menuLayerObj->inventory->setObject(CCString::createWithFormat("%d",(nTimes)),(CCString::createWithFormat("%d",itemId))->getCString());
//    }
//    else
//    {
//        menuLayerObj->inventory->setObject(CCString::createWithFormat("%d",(itemCount->intValue()+nTimes)),(CCString::createWithFormat("%d",itemId))->getCString());
//    }
//}
//
//
//int Items::itemIdFromCode(CCString* itemCode)
//{
//    CCArray* tmpRay =new CCArray();
//      tmpRay->addObject((CCString*)convertedString->componentsSeparatedByString(itemCode, CCString::create(":")));
//
//    return (int)(tmpRay->objectAtIndex(0));
//}
//
//
//
//bool  Items::monSeen(int monid)
//{
//    CCString* monSeen = ((CCString*)menuLayerObj->monstersSeen-> valueForKey(CCString::createWithFormat("%d",monid)->getCString()));
//    if( monSeen == NULL )
//      return false;
//    return true;
//}
//
//void Items::sawMonster(int monid)
//{
//    
//
//   if(  monSeen(monid) == false ) 
//     menuLayerObj-> monstersSeen->setObject(CCString::create("T"), (CCString::createWithFormat("%d",monid)->getCString()));
//}
//
//
//bool Items::monCaught(int monid)
//{
//     CCString* monSeen =  (CCString*)menuLayerObj->monstersCaught-> valueForKey(CCString::createWithFormat("%d",monid)->getCString());
//    if( monSeen == NULL )
//        return false;
//    return true;
//}
//
//void Items::caughtMonster(int monid)
//{
//   
//    if(  monCaught(monid) == false ) 
//   menuLayerObj->monstersSeen->setObject(CCString::create("T"), (CCString::createWithFormat("%d",monid)->getCString()));
//    
//}
//
//
//
