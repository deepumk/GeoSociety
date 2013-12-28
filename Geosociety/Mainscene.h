//
//  Mainscene.h
//  Geosociety
//
//  Created by Deepak on 12/11/13.
//
//

#ifndef __Geosociety__Mainscene__
#define __Geosociety__Mainscene__

#include <iostream>
#include "cocos2d.h"
#include "CCControlButton.h"
USING_NS_CC_EXT;
USING_NS_CC;
class MainScene : public cocos2d::CCLayer
{
    MainScene();
    ~MainScene();
public:
    
    CCSize winsize;
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::CCScene* scene();
    void playGame();
    void blank();
    void gotoselectionScene();
  
};



#endif /* defined(__Geosociety__Mainscene__) */
