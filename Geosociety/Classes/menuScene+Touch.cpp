////
////  menuScene+Touch.cpp
////  Geosociety
////
////  Created by macbookpro on 28/11/13.
////  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
////
//
//#include <iostream>
//#include "menuScene+Touch.h"
//#include "menuScene.h"
//#include <cmath>
//
//
//#pragma mark -
//#pragma mark === TOUCH FUNCTIONS ===
//#pragma mark -
//
//
//
//
//void Touch::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
//{
//      if( gearMenuLayer->bIsActive )
//        return;
//      CCSetIterator it;
//    CCTouch* touch;
//    CCPoint convertedpoint; 
//    
//    for( it = touches->begin(); it != touches->end(); it++)
//    {
//        touch = (CCTouch*)(*it);
//        
//        if(!touch)
//            break;
//        
//        CCPoint location = touch->getLocationInView();
//        
//        convertedpoint = CCDirector::sharedDirector()->convertToGL(location);
//    }
//    
//
//     menuLayerObj->touchStartX = convertedpoint.x;
//	menuLayerObj->touchStartY = convertedpoint.y;
//	menuLayerObj->bTouchWasSlide = false;
//	
//	if(menuLayerObj->menuStage == 999 ) 
//    {
//		gameEngineObj->touchGameStart(convertedpoint);
//	}
//}    
//
//
//
//
//void Touch::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
//{
//   
//    if( gearMenuLayer->bIsActive )
//        return;
//    
//      CCSetIterator it;
//    CCTouch* touch;
//    CCPoint convertedpoint; 
//    
//    for( it = touches->begin(); it != touches->end(); it++)
//    {
//        touch = (CCTouch*)(*it);
//        
//        if(!touch)
//            break;
//        
//        CCPoint location = touch->getLocationInView();
//        
//        convertedpoint = CCDirector::sharedDirector()->convertToGL(location);
//    }
// 
//    
//    if( convertedpoint.x > menuLayerObj->touchStartX + 20 ||  convertedpoint.x < menuLayerObj->touchStartX - 20 || convertedpoint.y > menuLayerObj->touchStartY + 20 ||  convertedpoint.y < menuLayerObj->touchStartY - 20 )
//    {
//		menuLayerObj->bTouchWasSlide = true;
//	}
//
//    if( menuLayerObj->bTouchWasSlide == false ) 
//    {
//		if( menuLayerObj->menuStage == 0 ) 
//        {
//			menuLayerObj->profileDisplay();
//		} 
//        else if( menuLayerObj->menuStage == 1 )
//        {
//			menuLayerObj->profileTouch(convertedpoint);
//		} 
//        else if(menuLayerObj->menuStage == 999 )
//        {
//			gameEngineObj->touchGameStop(convertedpoint);
//		} 
//        else if(menuLayerObj-> menuStage > 99 && menuLayerObj->menuStage < 200)
//        {
//			HelpSceneObj->helpTouch(convertedpoint);
//		}
//		
//        
//        
//        
//		
//		for(int i=0;i<menuLayerObj-> menuItems->count();i++) 
//        {
//           
//           
//           
//            if( dynamic_cast<CoolInput*>(menuLayerObj->menuItems->objectAtIndex(i)))       
//            {
//				CoolInput* tmpInput = (CoolInput* )menuLayerObj->menuItems->objectAtIndex(i);
//				if( (convertedpoint.y > tmpInput->topLeft.y -5) && (convertedpoint.y < tmpInput->topLeft.y + 15) )
//                {
//					tmpInput-> giveFocus();
//				} 
//                else 
//                {
//					tmpInput->takeFocus();
//				}
//			}
//		}
//	}
//}
//bool Touch::HitTest(CCPoint hit, CCPoint test, CCSize sizeToTest)
//{
//
//    if( hit.x > test.x - sizeToTest.width/2 && hit.x < test.x + sizeToTest.width/2 ) 
//    {
//        if( hit.y > test.y - sizeToTest.height/2 && hit.y < test.y + sizeToTest.height/2 )
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//
//
//
//void Touch::ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
//{
//    
//
// if( gearMenuLayer->bIsActive )
//        return;
// 
//    
//    
//    
//    
//    CCSetIterator it;
//    CCTouch* touch;
//    CCPoint convertedpoint; 
//    
//    for( it = touches->begin(); it != touches->end(); it++)
//    {
//        touch = (CCTouch*)(*it);
//        
//        if(!touch)
//            break;
//        
//        CCPoint location = touch->getLocationInView();
//        
//        convertedpoint = CCDirector::sharedDirector()->convertToGL(location);
//    }
//    
// 	
//   	
//	if( convertedpoint.x > menuLayerObj->touchStartX + 20 ||  convertedpoint.x < menuLayerObj->touchStartX - 20 || convertedpoint.y > menuLayerObj->touchStartY + 20 ||  convertedpoint.y < menuLayerObj->touchStartY - 20 ) 
//    {
//		menuLayerObj->bTouchWasSlide = true;
//	}
//	
//	if(menuLayerObj-> bTouchWasSlide ) 
//    {
//		
//		
//	}
//	
//	if(menuLayerObj->menuStage == 999 ) 
//    {
//           gameEngineObj->touchGameSlide(convertedpoint);
//	}
//}
//
//
//
//
//
//
//
