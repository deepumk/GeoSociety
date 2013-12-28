//
//  StringConvertion.cpp
//  Geosociety
//
//  Created by macbookpro on 04/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "StringConvertion.h"



CCString* StringConvertion::componentsSeparatedByString(cocos2d::CCString *mainString, cocos2d::CCString *separator)
{
  
  std::string FileMeasure=(mainString->getCString());
  int TempNumOne=FileMeasure.size();
  char str[100];
  for (int a=0;a<=TempNumOne;a++)
  {
    str[a]=FileMeasure[a];
  } 
  char * pch;
  pch = strtok (str,separator->getCString());
  return CCString::create(pch);

  
  
}



CCString *StringConvertion::lowercaseString(cocos2d::CCString *mainString)
{
  std::string lowercaseString= mainString->getCString();
  std::transform(lowercaseString.begin(), lowercaseString.end(), lowercaseString.begin(), ::tolower);
  return CCString::create(lowercaseString);
  
}






CCString* StringConvertion::replace(std::string str, const std::string from, const std::string to) 
{
  
  
  size_t start_pos = str.find(from);
   str.replace(start_pos, from.length(), to);
  return CCString::create(str);
}




CCString *StringConvertion::stringByReplacingOccurrencesOfString(std::string str, const std::string from, const std::string to)
{
  
  return replace(str, from, to);
  
  
  
}


CCString *StringConvertion::stringByAppendingFormat(cocos2d::CCString *appendingTo, cocos2d::CCString *appendingfrom)
{
  std::string S_appendingTo= appendingTo->getCString();
  std::string S_appendingfrom= appendingfrom->getCString();
  
  return  CCString::create(S_appendingTo.append(S_appendingfrom));
  
  
}

CCString *StringConvertion::substringToIndex(cocos2d::CCString *subString, int length)
{
  const char* s = subString->getCString();
  size_t start = 0;
  size_t end = length; // Assume this is an exclusive bound.
  
  std::string substring(s + start, end - start);
  return CCString::create(substring);

}

CCString *StringConvertion::substringFromIndexToIndex(cocos2d::CCString *subString,int fromIndex, int length)
{
    std::string str(subString->getCString());
    std::string str2 = str.substr (fromIndex,length);
    return CCString::create(str2.c_str());
    
}




