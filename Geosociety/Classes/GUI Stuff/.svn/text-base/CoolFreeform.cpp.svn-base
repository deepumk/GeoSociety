//
//  CoolFreeform.cpp
//  Geosociety
//
//  Created by Deepak on 20/11/13.
//
//

#include "CoolFreeform.h"
#define charWidth 30
#define charHeight 44
#define charScale 1.4

CoolFreeform:: CoolFreeform()
{
    contentStr= new CCString();
    contentStr->retain();
    letters= new CCArray();
    letters->retain();
}


CoolFreeform::~CoolFreeform()
{
   
    parentObject->removeChild(spriteSheet,true);
	
	letters->release();
	contentStr->release();
	fontStr->release();
	
}
CoolFreeform* CoolFreeform::initWithCoolSheet(cocos2d::CCString *content, const char *font, float size, int MaxWidth, bool showInstantly)
{
    
    
    
    spriteSheet= CCSpriteBatchNode::create(font);
    
    
    maxWidth = MaxWidth;
    letters=new CCArray();
    letters->retain();
   contentStr= new CCString();
    if (content!= NULL)
    {
        contentStr=content;
    }   
   
    fontStr=CCString::create(font);
    fontSize = size;
    
    instant = showInstantly;
    printf("\n deepak:: %s\n", contentStr->getCString());
    this->processContent();
    
    
    
    return this;
}



void CoolFreeform::finish()
{
    while (bFinished==false)
    {
        this->evaluate();
    }
}

bool CoolFreeform::isFinished()
{
    return bFinished;
}



void CoolFreeform::evaluate()
{
   int charRealWidth = fontSize * charWidth;
	int centerAdd = 0;
	if( bCenter ) {
		for(int i=0 ; i<letters->count();i++)
        {
            CoolSprite * lbl = (CoolSprite*)letters->objectAtIndex(i);
            if( lbl->intTag1+charRealWidth > centerAdd)
            {
				centerAdd = lbl->intTag1+charRealWidth;
			}
		}
		centerAdd = centerAdd / 2;
	}
	

    
    
	for(int i=0 ; i<letters->count();i++)
    {
        CoolSprite * lbl = (CoolSprite*)letters->objectAtIndex(i);
		if( lbl->intTag3 ==  1 )
        {
			
		}
        else
        {
			lbl->intTag4++;
			if( lbl->intTag4 > 3 )
            {
                lbl->updatePosition(ccp(x+lbl->intTag1-centerAdd,y-lbl->intTag2));
				lbl->intTag3 = 1;
				if( lbl==letters->objectAtIndex(letters->count()-1))
                {
					bFinished = true;
				}
				return;
            }
        }
    }
}



void CoolFreeform::processContent()
{
    
	for(int i=0;i<letters->count();i++)
    {
        letters->fastRemoveObjectAtIndex(i);
    }
	letters->release();	
    letters = new CCArray();
    letters->retain();
    letters->data->num = 0;
    //letters->data->max = 0;
    
    
//    letters->removeAllObjects();
//    letters->release();
//    letters = new CCArray();
//    letters->retain();
    
    
    if( instant ) {
		bFinished = true;
	} else {
		bFinished = false;
	}
    
    
    
    
//    NSMutableArray * tmpArray = [[NSMutableArray alloc] init];
    CCArray* tmpArray=new CCArray();
	for(int i=0;i<contentStr->length();i++)
    {
		
		
        CCString* letter= convertedString->substringFromIndexToIndex(contentStr, i,1);
        tmpArray->addObject(letter);
	}

 
    
    
    int charRealWidth = fontSize * charWidth;
	int charRealHeight = fontSize * charHeight * 1.1;
	
	int rollingX = 2 + charRealWidth / 2;
	int rollingY = 2 + charRealHeight / 2;
	
	int count = 0;
    
    
    
  
    
    
    for (int i=0; i<tmpArray->count(); i++)
    {
        CCString* tmpStr= (CCString*)tmpArray->objectAtIndex(i);
        CoolSprite* tmpSpt= new CoolSprite();
     tmpSpt->initWithTexture(spriteSheet->getTexture(), this->letterToRect(tmpStr));
       
        tmpSpt->updatePosition(ccp(-1000, -1000));
        tmpSpt->updateScale(fontSize*charScale);
		
		if( instant )
        {
			tmpSpt->intTag3 = 1;
		}
        else
        {
			tmpSpt->intTag3 = 0;
		}

        
        if( rollingX + charRealWidth > maxWidth )
        {
			if(tmpStr->isEqual(CCString::create("")))
            {
				rollingX = 2 + charRealWidth / 2 - charRealWidth;
				rollingY = rollingY + charRealHeight;
			}
            else
            {
				int backCount = count-1;
				while( backCount > 0 )
                {
                    CCString* tmpLastStr= (CCString*)tmpArray->objectAtIndex(backCount);
                    
                    if (tmpLastStr->isEqual(CCString::create("")))
                    {
						rollingX = 2 + charRealWidth / 2;
						rollingY = rollingY + charRealHeight;
						
						for(int i = backCount+1;i<count;i++)
                        {
							CoolSprite * repos = (CoolSprite*)letters->objectAtIndex(i);
							
							repos->intTag1 = rollingX;
							repos->intTag2 = rollingY;
							
							rollingX = rollingX + charRealWidth;
						}
						break;
                    }
					backCount--;
				}
            }
        }
        tmpSpt->intTag1 = rollingX;
		tmpSpt->intTag2 = rollingY;
		
		rollingX = rollingX + charRealWidth;
		letters->addObject(tmpSpt);
        
        //tmpSpt->release();
    	count++;
    }
	tmpArray->release();
    CCLog("%d",letters->count());
}



CCRect CoolFreeform::letterToRect(cocos2d::CCString *letter)
{
    int xx = 0;
	int yy = 0;
	
    
    
    if (letter->isEqual(CCString::create("a")))
    {
        xx = 5;
		yy = 6;
    }
     else if(letter->isEqual(CCString::create("b")))
     {
		xx = 6;
		yy = 6;
     }
     else if(letter->isEqual(CCString::create("c")))
     {
		xx = 7;
		yy = 6;
     }
     else if(letter->isEqual(CCString::create(("d"))))
     {
		xx = 8;
		yy = 6;
	}
     else if(letter->isEqual(CCString::create(("e"))))
     {
		xx = 9;
		yy = 6;
     }
    else if(letter->isEqual(CCString::create(("f"))))
    {
		xx = 0;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("g"))))
    {
		xx = 1;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("h"))))
    {
		xx = 2;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("i"))))
    {
		xx = 3;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("j"))))
    {
		xx = 4;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("k"))))
    {
		xx = 5;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("l"))))
    {
		xx = 6;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("m"))))
    {
		xx = 7;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("n"))))
    {
		xx = 8;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("o"))))
    {
		xx = 9;
		yy = 7;
	}
    else if(letter->isEqual(CCString::create(("p"))))
    {
		xx = 0;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("q")))
    {
		xx = 1;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("r")))
    {
		xx = 2;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("s")))
    {
		xx = 3;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("t")))
    {
		xx = 4;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("u")))
    {
		xx = 5;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("v")))
    {
		xx = 6;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("w")))
    {
		xx = 7;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("x")))
    {
		xx = 8;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("y")))
    {
		xx = 9;
		yy = 8;
	}
    else if(letter->isEqual(CCString::create("z")))
    {
		xx = 0;
		yy = 9;
	}
    
    
    
    
    
    if(letter->isEqual(CCString::create("!")))
    {
		xx = 1;
		yy = 0;
	}
    else if(letter->isEqual(CCString::create(".")) )
    {
		xx = 4;
		yy = 1;
	}
    else if(letter->isEqual(CCString::create(",")) )
    {
		xx = 2;
		yy = 1;
	}
    else if(letter->isEqual(CCString::create("?")))
    {
		xx = 1;
		yy = 3;
	}
    else if(letter->isEqual(CCString::create("\"")))
    {
		xx = 2;
		yy = 0;
	}
    else if(letter->isEqual(CCString::create("'")))
    {
		xx = 7;
		yy = 0;
	}
    else if(letter->isEqual(CCString::create("+")))
    {
		xx = 1;
		yy = 1;
	}
    else if(letter->isEqual(CCString::create("-")))
    {
		xx = 3;
		yy = 1;
	}
    else if(letter->isEqual(CCString::create("@")))
    {
		xx = 2;
		yy = 3;
	}
    else if(letter->isEqual(CCString::create("&")))
    {
		xx = 6;
		yy = 0;
	}
    else if(letter->isEqual(CCString::create("/")))
    {
		xx = 5;
		yy = 1;
	}
    
    
    
    if(letter->isEqual(CCString::create("A")))
    {
		xx = 3;
		yy = 3;
	}
    else if(letter->isEqual(CCString::create("B")))
    {
		xx = 4;
		yy = 3;
	}
    else if(letter->isEqual(CCString::create("C")))
    {
		xx = 5;
		yy = 3;
	}
    else if(letter->isEqual(CCString::create("D")))
    {
		xx = 6;
		yy = 3;
	}
    else if(letter->isEqual(CCString::create("E")))
    {
		xx = 7;
		yy = 3;
	}
    else if(letter->isEqual(CCString::create("F")))
    {
		xx = 8;
		yy = 3;
	}
    else if(letter->isEqual(CCString::create("G")))
    {
		xx = 9;
		yy = 3;
	}
    else if(letter->isEqual(CCString::create("H")))
    {
		xx = 0;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("I")))
    {
		xx = 1;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("J")))
    {
		xx = 2;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("K")))
    {
		xx = 3;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("L")))
    {
		xx = 4;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("M")))
    {
		xx = 5;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("N")))
    {
		xx = 6;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("O")))
    {
		xx = 7;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("P")))
    {
		xx = 8;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("Q")))
    {
		xx = 9;
		yy = 4;
	}
    else if(letter->isEqual(CCString::create("R")))
    {
		xx = 0;
		yy = 5;
	}
    else if(letter->isEqual(CCString::create("S")))
    {
		xx = 1;
		yy = 5;
	}
    else if(letter->isEqual(CCString::create("T")))
    {
		xx = 2;
		yy = 5;
	}
    else if(letter->isEqual(CCString::create("U")))
    {
		xx = 3;
		yy = 5;
	}
    else if(letter->isEqual(CCString::create("V")))
    {
		xx = 4;
		yy = 5;
	}
    else if(letter->isEqual(CCString::create("W")))
    {
		xx = 5;
		yy = 5;
	}
    else if(letter->isEqual(CCString::create("X")))
    {
		xx = 6;
		yy = 5;
	}
    else if(letter->isEqual(CCString::create("Y")))
    {
		xx = 7;
		yy = 5;
	}
    else if(letter->isEqual(CCString::create("Z")))
    {
		xx = 8;
		yy = 5;
	}
    
    
    
    
    if(letter->isEqual(CCString::create("0")))
    {
		xx = 6;
		yy = 1;
	}
    else if(letter->isEqual(CCString::create("1")))
    {
		xx = 7;
		yy = 1;
	}
    else if(letter->isEqual(CCString::create("2")))
    {
		xx = 8;
		yy = 1;
	}
    else if(letter->isEqual(CCString::create("3")))
    {
		xx = 9;
		yy = 1;
	}
    else if(letter->isEqual(CCString::create("4")))
    {
		xx = 0;
		yy = 2;
	}
    else if(letter->isEqual(CCString::create("5")))
    {
		xx = 1;
		yy = 2;
	}
    else if(letter->isEqual(CCString::create("6")))
    {
		xx = 2;
		yy = 2;
	}
    else if(letter->isEqual(CCString::create("7")))
    {
		xx = 3;
		yy = 2;
	}
    else if(letter->isEqual(CCString::create("8")))
    {
		xx = 4;
		yy = 2;
	}
    else if(letter->isEqual(CCString::create("9")))
    {
		xx = 5;
		yy = 2;
	}
    else if(letter->isEqual(CCString::create(":")))
    {
		xx = 6;
		yy = 2;
	}
    
    
    return CCRectMake(xx * 63+2+2, yy*102+20+6, 56, 70);

}







void CoolFreeform::updateColor(ccColor3B col)
{
    for (int i=0; i<letters->count(); i++)
    {
        CoolFreeformLabel* lbl= (CoolFreeformLabel*)letters->objectAtIndex(i);
        lbl->setColor(col);
    }
}

void CoolFreeform::addToLayer(cocos2d::CCLayer *layer, int startZ)
{
    z=startZ;
    layer->addChild(spriteSheet);
    for (int i=0; i<letters->count(); i++)
    {
        CoolSprite* lbl= (CoolSprite*)letters->objectAtIndex(i);
        lbl->addToLayer(layer, startZ);
    }
}


void CoolFreeform::updatePosition(cocos2d::CCPoint pos)
{
    
    x = pos.x;
	y = pos.y;
	
	int charRealWidth = fontSize * charWidth;
	int centerAdd = 0;
    if( bCenter )
    {
        if(letters->data != NULL)//TODO: ANISH
        {
            for(int i=0;i<letters->count();i++)
            {
                CoolSprite * lbl = (CoolSprite*)letters->objectAtIndex(i);
                
                if( lbl->intTag1+charRealWidth > centerAdd  )
                {
                    centerAdd = lbl->intTag1+charRealWidth;
                }
            }
            centerAdd = centerAdd / 2;
            
        }
        
    }

    if(letters->data != NULL)//TODO: ANISH
    {
        for(int i=0;i<letters->count();i++)
        {
            CoolSprite* lbl = (CoolSprite*)letters->objectAtIndex(i);
            lbl->updatePosition(ccp(pos.x+lbl->intTag1-centerAdd,pos.y-lbl->intTag2+4*fontSize));
        }
    }
    
}

void CoolFreeform::updateOpacity(int alpha)
{
    for (int i=0; i<letters->count(); i++)
    {
        CoolSprite* lbl = (CoolSprite*)letters->objectAtIndex(i);
        lbl->updateOpacity(alpha);
    }
}




void CoolFreeform::updateContent(cocos2d::CCString *content)
{
    contentStr->release();
    contentStr= CCString::create(content->getCString());
    this->processContent();
    this->updatePosition(ccp(x, y));
    for (int i=0; i<letters->count(); i++)
    {
        CoolSprite* lbl = (CoolSprite*)letters->objectAtIndex(i);
        lbl->addToLayer(parentObject, z);
    }
}









