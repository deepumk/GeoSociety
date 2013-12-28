//
//  CoolLabel.cpp
//  Geosociety
//
//  Created by Deepak on 20/11/13.
//
//

#include "CoolLabel.h"

CoolLabel* CoolLabel::initWithCoolString(CCString* content ,const char *font, float size)
{
    
    
    printf("%s",CCString::create("CoolLabel")->getCString());
    main =CCLabelTTF::create(content->getCString(), font, size);
   shadow1=CCLabelTTF::create(content->getCString(), font, size);
    shadow2=CCLabelTTF::create(content->getCString(), font, size);
    shadow3=CCLabelTTF::create(content->getCString(), font, size);
    shadow4=CCLabelTTF::create(content->getCString(), font, size);
   
    contentStr=CCString::create(content->getCString());
    fontStr= CCString::create(font);
    fontSize=size;
    
    shadow1->setColor(ccc3(0, 0, 0));
    shadow2->setColor(ccc3(0, 0, 0));
    shadow3->setColor(ccc3(0, 0, 0));
    shadow4->setColor(ccc3(0, 0, 0));
    
    CCPoint pos;
    
    pos.x=200;
    pos.y=200;
    
    main->setPosition(pos);
    shadow1->setPosition(ccp(pos.x-1,pos.y));
    shadow2->setPosition(ccp(pos.x+1,pos.y));
    shadow3->setPosition(ccp(pos.x,pos.y-1));
    shadow4->setPosition(ccp(pos.x,pos.y+1));

    return this;

    
}


CoolLabel::~CoolLabel()
{
    
    
    if( contentStr != NULL )
    {
		contentStr->release();
		contentStr = NULL;
	}
	if( fontStr != NULL )
    {
		fontStr->release();
		fontStr = NULL;
	}
	if( main != NULL )
    {
        parentObject->removeChild(main, true);
		main->release();
		main = NULL;
	}
	if( shadow1 != NULL )
    {
        parentObject->removeChild(shadow1, true);
        shadow1->release();
		shadow1 = NULL;
	}
	if( shadow2 != NULL )
    {
        parentObject->removeChild(shadow2, true);
        shadow2->release();
		shadow2 = NULL;
	}
	if( shadow3 != NULL)
    {
        parentObject->removeChild(shadow3, true);
        shadow3->release();
		shadow3 = NULL;
	}
	if( shadow4 != NULL )
    {
        parentObject->removeChild(shadow4, true);
        shadow4->release();
		shadow4 = NULL;
	}

}



void CoolLabel::updateColor(ccColor3B col)
{
    main->setColor(col);
}



void CoolLabel::addToLayer(CCLayer *layer, int startZ )
{
    
    layer->addChild(main,startZ);
    layer->addChild(shadow1,startZ-1);
    layer->addChild(shadow2,startZ-1);
    layer->addChild(shadow3,startZ-1);
    layer->addChild(shadow4,startZ-1);
    parentObject=layer;
    
}


void CoolLabel::updatePosition(CCPoint pos)
{
    x=pos.x;
    y=pos.y;
    
    if (main->getContentSize().height>0)
    {
        main->setPosition(ccp(pos.x, pos.y-(main->getContentSize().height-fontSize-3)));
        shadow1->setPosition(ccp(pos.x-1,pos.y-(main->getContentSize().height-fontSize-3)));
        shadow2->setPosition(ccp(pos.x+1,pos.y-(main->getContentSize().height-fontSize-3)));
        shadow3->setPosition(ccp(pos.x,pos.y-1-(main->getContentSize().height-fontSize-3)));
        shadow4->setPosition(ccp(pos.x,pos.y-1-(main->getContentSize().height-fontSize-3)));
    }
    else
    {
        main->setPosition(ccp(pos.x,pos.y));
        shadow1->setPosition(ccp(pos.x-1, pos.y));
        shadow2->setPosition(ccp(pos.x+1,pos.y));
        shadow3->setPosition(ccp(pos.x,pos.y-1));
        shadow4->setPosition(ccp(pos.x,pos.y+1));
    }
}


void CoolLabel::updateOpacity(int alpha)
{
    main->setOpacity(alpha);
    shadow1->setOpacity(alpha);
    shadow2->setOpacity(alpha);
    shadow3->setOpacity(alpha);
    shadow4->setOpacity(alpha);
}

void CoolLabel::updateContent(CCString* content)
{
    
   
    if (contentStr!=NULL)
    {
        contentStr->release();
        contentStr=NULL;
    }
    contentStr=CCString::create(content->getCString());
    main->setString(content->getCString());
    shadow1->setString(content->getCString());
    shadow2->setString(content->getCString());
    shadow3->setString(content->getCString());
    shadow4->setString(content->getCString());
}


void CoolLabel::updateAnchorPointBottomRight()
{
    main->setAnchorPoint(ccp(0, 0));
    shadow1->setAnchorPoint(ccp(0, 0));
    shadow2->setAnchorPoint(ccp(0, 0));
    shadow3->setAnchorPoint(ccp(0, 0));
    shadow4->setAnchorPoint(ccp(0, 0));
}

int CoolLabel::updateWithConstantWidth(int width)
{
    CCLabelTTF* TempLabel = CCLabelTTF::create(contentStr->getCString(), fontStr->getCString(), fontSize);
    CCSize textSize= TempLabel->getContentSize();
    
    main->setDimensions(textSize);
    shadow1->setDimensions(textSize);
    shadow2->setDimensions(textSize);
    shadow3->setDimensions(textSize);
    shadow4->setDimensions(textSize);
    
    
	

    main->setString(contentStr->getCString());
    shadow1->setString(contentStr->getCString());
    shadow2->setString(contentStr->getCString());
    shadow3->setString(contentStr->getCString());
    shadow4->setString(contentStr->getCString());
    
    
    
    this->updatePosition(ccp(x, y));
    fixedHeight=textSize.height;
    return textSize.height;
}







