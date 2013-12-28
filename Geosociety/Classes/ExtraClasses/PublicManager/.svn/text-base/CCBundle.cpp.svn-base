//
//  CCBundle.cpp
//  SMSDX
//
//  Created by  陈广文 on 13-3-4.
//
//

#include "CCBundle.h"
#include "DataInputStream.h"
#include <string>
#include "Define.h"
USING_NS_CC;
using namespace std;
static CCBundle* myCCBundle;

CCBundle* CCBundle::mainBundle(){
    if(!myCCBundle){
//         CCLog("mainBundle  ");
        myCCBundle=new CCBundle();
        myCCBundle->init();
    }
    return myCCBundle;
}

bool CCBundle::init(){
    
//    CCLog("FILE_NAME->length() %d ",FILE_NAME->length());
    for (int i=0; i<LEN; i++) {
        std::string fileName=FILE_NAME[i];
//        CCLog("fileName  %s ",fileName.c_str());
        String1DArray tempArray=this->getStrArray(this->getString(fileName), "\n");
//        CCLog("tempArray->length() %d ",tempArray->length);
        charMap tempMap;
        for (int j=0; j<tempArray->length; j++) {
//            CCLog("tempArray value   %s ",tempArray->value[j]);
            const string key=getKey(tempArray->value[j],"=");
//            CCLog("key value   %s ",key.c_str());
            string value=getValue(tempArray->value[j],"=");
//             CCLog("value value   %s ",value.c_str());
            insertMap(&tempMap,key,value);
//            free(tempArray->value[j]);
        }
//         CCLog("**********************************");
         free(tempArray);
         insertMap(&myMap,fileName,tempMap);
       
    }
//     CCLog("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    return true;
}

CCString *CCBundle::localizedForKey(const string  key,string value,const string tableName){
//    getStrValue(key,tableName);
//     CCLog("********CCBundle*********localizedStringForKey***************");
    return getStrValue(key,tableName);
}

void CCBundle::insertMap(charMap *hMap,const string  key, string value){
//    CCLog("********CCBundle****111111111111111111111111*****localizedStringForKey***************");
    hMap->insert(charMap::value_type(key,value));
}
void CCBundle::insertMap(hashMap *hMap,const string key, charMap value){
//    CCLog("********CCBundle******2222222222222222222***localizedStringForKey***************");
    hMap->insert(hashMap::value_type(key,value));
}

//hashMap::mapped_type CCBundle::getMapValue(const string key){
//
//    return myMap[key];
//
//}

CCString* CCBundle::getStrValue(const string key,const string table){
    
    hashMap::mapped_type tmap=myMap[table];
    
    charMap::mapped_type temp=tmap[key];
//    CCLog("getStrValue %s ",temp.data());
    return CCString::create(temp.data());
}
string CCBundle::getString(string path){
    path+=".txt";
    DataInputStream*dis=DataInputStream::create(path.c_str());
    unsigned const char* buffer=dis->readUTF();
    
     int len=dis->length();
    CCString *temp=CCString::createWithData(buffer,len);
//    CCLog("getString %s len %d ",buffer,len);
    dis->close();
    return temp->m_sString;
}

/**
 *
 * @param str
 * @param tag
 * @return String1DArray
 */
String1DArray CCBundle::getStrArray(string str,const char* tag) {//tag 例如“\n” 这种
    CCArray*  array =new  CCArray;
    array->autorelease();
//     CCLog("getStrArray ");
    int start = 0;
    int end =0;
    while ((end=DataInputStream::indexOf(str,tag, start)) != -1) {
//               CCLog(" %s  ",DataInputStream::substring(str,start, end).c_str());
//               CCLog("start: %d end:%d  ",start,end);
        array->addObject(CCString::create(DataInputStream::substring(str,start, end)));
        start = end+1 ;
    }
    int len=array->count();
//     CCLog("len   %d  ",len);
    String1DArray temp=(String1DArray)malloc(sizeof(String1DArrayStruct));
    temp->value=(const char**)malloc(sizeof(const char*)*len);
    temp->length=len;
    for (int i=0;i<len;i++)
    {
        CCString* t=(CCString*)array->objectAtIndex(i);
        temp->value[i]=t->getCString();
    }
    array->removeAllObjects();
    return temp;
}