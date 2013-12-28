//
//  StringConvertion.h
//  Geosociety
//
//  Created by macbookpro on 04/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Geosociety_StringConvertion_h
#define Geosociety_StringConvertion_h
#include "cocos2d.h"

using namespace cocos2d;

class StringConvertion: public CCObject
{
  
public:
  CCString* componentsSeparatedByString(cocos2d::CCString *mainString, cocos2d::CCString *separator);
  CCString* lowercaseString(cocos2d::CCString *mainString);
  CCString* replace(std::string str, const std::string from, const std::string to);
  CCString* stringByReplacingOccurrencesOfString(std::string str, const std::string from, const std::string to);
  CCString* stringByAppendingFormat(CCString* appendingTo, CCString* appendingfrom);
  CCString* substringToIndex(CCString*subString ,int lenght );
    CCString* substringFromIndexToIndex(cocos2d::CCString *subString,int fromIndex, int length);
  

};


#endif
