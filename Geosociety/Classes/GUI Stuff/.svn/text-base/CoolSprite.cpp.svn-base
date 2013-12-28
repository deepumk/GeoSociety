    //
//  CoolSprite.cpp
//  Geosociety
//
//  Created by Deepak on 20/11/13.
//
//

#include "CoolSprite.h"
#include <iostream>
using namespace std;



CoolSprite::CoolSprite()
{
//  printf("%s",CCString::create("CoolSprite")->getCString());
    
    img= CCSprite::create();
}

bool CoolSprite::initWithFile(CCString* filename)
{
    
    img=CCSprite::create(filename->getCString());
    frames= new CCAnimation();
    frames->init();// addSpriteFrameWithFileName("frames");
	return this;
    
}


bool CoolSprite::initWithTexture(CCTexture2D * texture, CCRect rect)
{
    img = CCSprite::createWithTexture(texture, rect);
    frames= new CCAnimation();
    
    
    frames->init();//"frames");//CHANGED
    
    return this;
}






void CoolSprite::addFrame(CCString* filename)
{
    frames->addSpriteFrameWithFileName(filename->getCString());
    frameCount++;
    
    
}

void CoolSprite::addFrame(CCTexture2D *texture, CCRect rect )
{
    frames->addSpriteFrameWithTexture(texture, rect);
    frameCount++;
}


void CoolSprite::commitFrames()
{
    ///////////////////PENDING /////////////////////////////
//    [img addAnimation:frames];
	
    frames->release();
    
}











void CoolSprite::reorderTo(int newZ)
{
    parentObject->reorderChild(img, newZ);
}






void CoolSprite::setFrame(int newFrame)
{
    frame=newFrame;
    if( frame >= frameCount )
		frame = 0;
    if( frame < 0 )
        frame = 0;
//    img->setDisplayFrameWithAnimationName("frames", frame);
    

}


void CoolSprite::nextFrame()
{
    frame++;
	if( frame >= frameCount )
		frame = 0;
//    img->setDisplayFrameWithAnimationName("frames", frame);
}

void CoolSprite::flipX()
{
    img->setScaleX(-1);
}


CoolSprite::~CoolSprite()
{
    parentObject->removeChild(img, true);
//    img->release();
    
}

void CoolSprite::updatePosition(cocos2d::CCPoint pos)
{
    img->setPosition(pos);
    x=pos.x;
    y=pos.y;

    
    
}




void CoolSprite::updateRotation(float Rotation)
{
    img->setRotation(Rotation);
}

void CoolSprite::updateScale(float scale)
{
    img->setScale(scale);
    myScale=scale;
}

void CoolSprite::updateXScale(float scaleX)
{
    img->setScaleX(scaleX);
}


void CoolSprite::updateYScale(float scaleY)
{
    img->setScaleY(scaleY);
}




void CoolSprite::updateOpacity(int alpha)
{
    img->setOpacity(alpha);
    curAlpha=alpha;
}



void CoolSprite::updateAnchorPointBottomRight()
{
    img->setAnchorPoint(ccp(0, 0));
}




void CoolSprite::updateFile(cocos2d::CCString *filename)
{
    parentObject->removeChild(img, true);
    img->release();
    img=CCSprite::create(filename->getCString());
    this->updatePosition(ccp(x,y));
    this->updateOpacity(curAlpha);
    this->addToLayer(parentObject, z);
}

void CoolSprite::addToLayer(cocos2d::CCLayer *layer, int startZ)
{
    layer->addChild(img,startZ);
    parentObject=layer;
    z=startZ;
}



















