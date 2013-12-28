//
//  CoolInput.cpp
//  Geosociety
//
//  Created by Deepak on 20/11/13.
//
//

#include "CoolInput.h"


CoolInput* CoolInput::initWithCoolLabel(cocos2d::CCString *labelStr, cocos2d::CCString *data, cocos2d::CCLayer *layer, int zOrder)
{
    
    printf("%s",CCString::create("CoolInput")->getCString());
   
    
    parentObject=layer;
    maxTextWidth=40;
    contentWidth=0;
    CCRect viewRect= CCRectMake(-500, -500, -600, -530);
    
    
    
    /* PENDING 
     
     
    
     faketxtbox = [[UITextView alloc] initWithFrame:viewRect];
     faketxtbox.scrollEnabled = NO;
     faketxtbox.userInteractionEnabled = YES;
     faketxtbox.text = data;
     [[[CCDirector sharedDirector] openGLView] addSubview:faketxtbox];
     faketxtbox.editable = YES;
     faketxtbox.delegate = self; */
    
    
   
    
    
    labelTitle= CCString::create(labelStr->getCString());
    labelContent=CCString::create(data->getCString());
    CCString* tmpStr;
    
   
    
    if (strcmp(labelStr->getCString(), "")!=0)
    {
        
        tmpStr=CCString::createWithFormat("%s",data->getCString());
        
        label->initWithCoolString(tmpStr, "Arial", 35);
        lineBg=NULL;
    }
    else
    {
         tmpStr=CCString::createWithFormat("%s: %s",labelTitle->getCString(),data->getCString());
        label->initWithCoolString(tmpStr, "Arial", 35);
        label->updateAnchorPointBottomRight();
        
       lineBg->initWithFile(CCString::create("entryline.png"));
        lineBg->updatePosition(ccp(-100, -100));
        lineBg->updateOpacity(0);
        lineBg->addToLayer(parentObject, -1);
        
    }

    
    label->updatePosition(ccp(-1000, -1000));
    label->addToLayer(layer, zOrder);
    z = zOrder;

    return this;
    
}


CCString* CoolInput::getData()
{
    return labelContent;
}


void CoolInput::giveFocus()
{
    ////////////////PENDING  [faketxtbox becomeFirstResponder]; ///////////////
    if (lineBg!=NULL)
    {
        lineBg->updateOpacity(120);
    }
    
}



void CoolInput::takeFocus()
{
     ////////////////PENDING  [faketxtbox resignFirstResponder]; ///////////////
    if (lineBg!=NULL)
    {
        lineBg->updateOpacity(0);
    }
}




CoolInput::~CoolInput()
{
    if (labelTitle!=NULL)
    {
        labelTitle->release();
        labelTitle=NULL;
    }
    
    
    
    if (label!=NULL)
    {
        label->release();
        label=NULL;
    }
    
    if (faketxtbox!=NULL)
    {
        /////////  PENDING [faketxtbox removeFromSuperview];/////////
        faketxtbox->release();
        faketxtbox=NULL;
    }
    
    
    if (labelContent!=NULL)
    {
        labelContent->release();
        labelContent=NULL;
    }
    
    if (lineBg!=NULL)
    {
        lineBg->release();
        lineBg=NULL;
    }
}


void CoolInput::updatePosition(cocos2d::CCPoint topleft)
{
    topleft=topleft;
    
    
    label->updatePosition(ccp(topLeft.x,topLeft.y));
    if (lineBg!=NULL)
    {
        lineBg->updatePosition(ccp(160,topLeft.y+10));
    }
    
}





void CoolInput::wipe()
{
   /* PENDING_DEEPAK [faketxtbox setText:@""];
	[self textViewDidChange:faketxtbox];*/
	
	
}

/* PENDING_DEEPAK_UITextView
- (void)textViewDidBeginEditing:(UITextView *)textView {
    [textView setText:@""];
}



- (void)textViewDidChange:(UITextView *)textView {
	[(gearLayer *)parentObject sfx:SOUND_KEYIN];
	//[[SimpleAudioEngine sharedEngine] playEffect:SOUND_KEYIN];
	
	NSString * entryTmp = [[[NSString alloc] initWithString: [textView text]] autorelease];
	NSString * manipulatedText = [NSString stringWithString:entryTmp];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"\n" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"\r" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"UNION" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"union" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"\'" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"\"" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"JOIN" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"join" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@" and " withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@" AND " withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@" or " withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@" OR " withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"|" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"," withString:@""];
	
	
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"!" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"#" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"$" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"%" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"^" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"&" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"*" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"(" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@")" withString:@""];
	
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"[" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"]" withString:@""];
	
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"{" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"}" withString:@""];
	
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"=" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"-" withString:@""];
	
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"~" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"`" withString:@""];
	
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"<" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@">" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"," withString:@""];
	
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"/" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"\"" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@"\'" withString:@""];
	manipulatedText = [manipulatedText stringByReplacingOccurrencesOfString:@";" withString:@""];
    
	
	if( [manipulatedText length] > maxTextWidth ) {
		manipulatedText = [manipulatedText substringToIndex:maxTextWidth];
	}
	[textView setText:manipulatedText];
	
	if( bIsPassword ) {
		NSString * passMask = @"";
		for(int i=0; i<[manipulatedText length];i++) {
			passMask = [passMask stringByAppendingString:@"*"];
		}
		
		
		NSString * tmpStr = nil;
		if( [labelTitle isEqualToString:@""] ) {
			tmpStr = [NSString stringWithFormat:@"%@",passMask];
		} else {
			tmpStr = [NSString stringWithFormat:@"%@: %@",labelTitle,passMask];
		}
		[label updateContent:tmpStr];
	} else {
		
		NSString * tmpStr = nil;
		if( [labelTitle isEqualToString:@""] ) {
			tmpStr = [NSString stringWithFormat:@"%@",manipulatedText];
		} else {
			tmpStr = [NSString stringWithFormat:@"%@: %@",labelTitle,manipulatedText];
		}
		
		[label updateContent:tmpStr];
	}
	
	if( labelContent != nil ) {
		[labelContent release];
		labelContent =nil;
	}
	labelContent = [[NSString alloc] initWithString:manipulatedText];
	
	if( contentWidth > 0 ) {
		[self updateWithConstantWidth:contentWidth];
	}
	
	return;
}

*///////////////////



























