//
//  CCBundle.h
//  SMSDX
//
//  Created by  陈广文 on 13-3-4.
//
//

#ifndef __SMSDX__CCBundle__
#define __SMSDX__CCBundle__
#include "cocos2d.h"
#include <iostream>
#include <map>
#include "BaseData.h"
#include "DataInputStream.h"
using namespace std;
typedef map<const string, string>  charMap;

typedef map<const string,charMap>  hashMap;


class CCBundle:public cocos2d::CCObject{
public:
    static CCBundle* mainBundle();
    bool init();
    void insertMap(charMap *hMap,const string key,string value);
    void insertMap(hashMap *hMap,const string key,charMap value);
    hashMap::mapped_type getMapValue(const string key);
    cocos2d::CCString* getStrValue(const string key,const string table);
    cocos2d::CCString *localizedForKey(const string  key,string value,const string tableName);
    static string getString( string path);
    
    static String1DArray getStrArray(string str,const char* tag);
    static std::string getKey(string value,const char* tag){
        int index=DataInputStream::indexOf(value, tag, 0);
        return  DataInputStream::substring(value, 1, index-2);
    }
    static std::string getValue(string value,const char* tag){
         int index=DataInputStream::indexOf(value, tag, 0);
         return  DataInputStream::substring(value, index+3, value.length()-2);
    }
private:
    hashMap myMap;
};
#endif /* defined(__SMSDX__CCBundle__) */
