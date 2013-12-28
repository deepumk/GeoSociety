//
//  menuScene.cpp
//  Geosociety
//
//  Created by Deepak on 21/11/13.
//
//

#include "dataDictionary.h"




dataDictionary *dataDictionary::init() 
{
    monsters =new CCArray();
    items =new CCArray();
		this->readMonsters();
        this->readItems();
	
}


CCString *dataDictionary::typeFromNumber(int no)
{
    if( no == 1 )
        return CCString::create("Fire");
    if( no == 2 )
        return CCString::create("Water");
    if( no == 4 )
        return CCString::create("Electric");
    if( no == 6 )
        return CCString::create("Psychic");
    if( no == 7 )
        return CCString::create("Basic");
    if( no == 9 )
        return CCString::create("Air");
    
    if( no == 10 )
        return CCString::create("Earth");
    if( no == 14 )
        return CCString::create("Ghost");
    
    if( no == 19 )
        return CCString::create("Ancient");
    if( no == 20 )
        return CCString::create("Steel");
    if( no == 21 )
        return CCString::create("Divine");
    if( no == 22 )
        return CCString::create("Demonic");
    
    return CCString::create("Basic");
}





void dataDictionary::loadZoneInto(CCArray * zoneArray,CCString * zone)
{
    zoneArray->removeAllObjects();
    
    
    ///PENDING_DEEPAK @synchronized(self)
    
    {
        
       /* PENDING_DEEPAK  sqlite3* database = [self getOpenDatabase];
        
        // Setup the SQL Statement and compile it for faster access
        CCString * tmpStr =CCString::createWithFormat("SELECT monid,levellow,levelhigh FROM zonemonsters WHERE mapid='%@' AND seed=%d;",zone,seed);
        
        const char *sqlStatement =tmpStr->cStringUsingEncoding(NSASCIIStringEncoding);
        sqlite3_stmt *compiledStatement;
        int queryResult = sqlite3_prepare_v2(database, sqlStatement, -1, &compiledStatement, NULL);
        
        if(queryResult ==  SQLITE_OK)
        {
            // Loop through the results and add them to the feeds array
            while(sqlite3_step(compiledStatement) == SQLITE_ROW) {
                // Read the data from the result row
                
                dataZoneMonster * zoneMon = [[dataZoneMonster alloc] init: compiledStatement andParent: self];
                [zoneArray addObject: zoneMon];
                [zoneMon release];
                
            }
        } else {
            printf( "could not prepare statemnt: %s\n", sqlite3_errmsg(database) );
        }
        // Release the compiled statement from memory
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);*/
        
    }
    
}






void dataDictionary::readMonsters() 
{
	
    /* PENDING_DEEPAK
    @synchronized(self) {
        // Setup some globals
        NSString * databaseName = @"monsters.sql";
        // Get the path to the documents directory and append the databaseName
        NSArray *documentPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory , NSUserDomainMask, YES);
        NSString *documentsDir = [documentPaths objectAtIndex:0];
        NSString * databasePath = [documentsDir stringByAppendingPathComponent:databaseName];
        
        NSString *fullpath = [CCFileUtils fullPathFromRelativePath: databaseName ];
        
        //Remove all Monsters
        [monsters removeAllObjects];
        
        // Setup the database object
        sqlite3 *database;
        
        // Open the database from the users filessytem
        if(sqlite3_open([fullpath UTF8String], &database) == SQLITE_OK) {
            NSLog(@"%@", databasePath);
            
            // Setup the SQL Statement and compile it for faster access
            const char *sqlStatement = "SELECT id,name,hp,atk,def,spd,exp,evolvelvl,evolvesto,evolutionlvl,tamedifficulty,type1Id,type2Id,maleratio,monsterstats.int,type1,type2,category,rarity FROM monsterstats WHERE isReleased=1";
            sqlite3_stmt *compiledStatement;
            int queryResult = sqlite3_prepare_v2(database, sqlStatement, -1, &compiledStatement, NULL);
            
            
            if(queryResult ==  SQLITE_OK) {
                // Loop through the results and add them to the feeds array
                while(sqlite3_step(compiledStatement) == SQLITE_ROW) {
                    // Read the data from the result row
                    
                    dataMonster * newMon = [[dataMonster alloc] init: compiledStatement andDatabase: self];
                    // Add the monster object to the monsters Array
                    [monsters addObject:newMon];
                    
                    [newMon release];
                }
            } else {
                printf( "could not prepare statemnt: %s\n", sqlite3_errmsg(database) );
            }
            // Release the compiled statement from memory
            sqlite3_finalize(compiledStatement);
            
        }
        sqlite3_close(database);
    }
     */
	
}




void dataDictionary::readItems()
{
	
  /*  @synchronized(self) {
        // Setup some globals
        NSString * databaseName = @"monsters.sql";
        // Get the path to the documents directory and append the databaseName
        NSArray *documentPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory , NSUserDomainMask, YES);
        NSString *documentsDir = [documentPaths objectAtIndex:0];
        NSString * databasePath = [documentsDir stringByAppendingPathComponent:databaseName];
        
        NSString *fullpath = [CCFileUtils fullPathFromRelativePath: databaseName ];
        
        //Remove all Monsters
        [items removeAllObjects];
        
        // Setup the database object
        sqlite3 *database;
        
        // Open the database from the users filessytem
        if(sqlite3_open([fullpath UTF8String], &database) == SQLITE_OK) {
            NSLog(@"%@", databasePath);
            
            // Setup the SQL Statement and compile it for faster access
            const char *sqlStatement = "SELECT id,name,scope,description,buyPrice,sellPrice FROM items";
            sqlite3_stmt *compiledStatement;
            int queryResult = sqlite3_prepare_v2(database, sqlStatement, -1, &compiledStatement, NULL);
            
            
            if(queryResult ==  SQLITE_OK) {
                // Loop through the results and add them to the feeds array
                while(sqlite3_step(compiledStatement) == SQLITE_ROW) {
                    // Read the data from the result row
                    
                    dataItem * newItem = [[dataItem alloc] init: compiledStatement];
                    // Add the monster object to the monsters Array
                    [items addObject:newItem];
                    [newItem release];
                }
            } else {
                printf( "could not prepare statemnt: %s\n", sqlite3_errmsg(database) );
            }
            // Release the compiled statement from memory
            sqlite3_finalize(compiledStatement);
            
        }
        sqlite3_close(database);
    }*/
	
}



/* PENDING_DEEPAK SQULITE
-(sqlite3 *) getOpenDatabase {
    
    @synchronized(self) {
        // Setup some globals
        NSString * databaseName = @"monsters.sql";
        // Get the path to the documents directory and append the databaseName
        NSArray *documentPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory , NSUserDomainMask, YES);
        NSString *documentsDir = [documentPaths objectAtIndex:0];
        NSString * databasePath = [documentsDir stringByAppendingPathComponent:databaseName];
        
        NSString *fullpath = [CCFileUtils fullPathFromRelativePath: databaseName ];
        
        // Setup the database object
        sqlite3 *database;
        
        
        // Open the database from the users filessytem
        if(sqlite3_open([fullpath UTF8String], &database) == SQLITE_OK) {
            return database;
        } else {
            return nil;
        }
    }
}
*/




CCString *dataDictionary::getTypeFromId(int typeId)
{
    
    if( typeId == 1 ) {
        return CCString::create("Fire");
    } else if( typeId == 2 ) {
        return CCString::create("Water");
    } else if( typeId == 4 ) {
        return CCString::create("Electric");
    } else if( typeId == 6 ) {
        return CCString::create("Psychic");
    } else if( typeId == 7 ) {
        return CCString::create("Basic");
    } else if( typeId == 9 ) {
        return CCString::create("Air");
    } else if( typeId == 10 ) {
        return CCString::create("Earth");
    } else if( typeId == 14 ) {
        return CCString::create("Ghost");
    } else if( typeId == 19 ) {
        return CCString::create("Ancient");
    } else if( typeId == 20 ) {
        return CCString::create("Steel");
    } else if( typeId == 21 ) {
        return CCString::create("Divine");
    } else if( typeId == 22 ) {
        return CCString::create("Demonic");
    }
    
    return CCString::create("");
}






dataSkill *dataDictionary::getAttackForId(int skillid) 
{
 /* PENDING_DEEPAK   
    @synchronized(self) {
        sqlite3* database = [self getOpenDatabase];
        dataSkill * newItem = nil;
        
        // Setup the SQL Statement and compile it for faster access
        const char *sqlStatement = "SELECT skills.id,skills.name,skills.hits,skills.scope,skills.element_type_id,skills.power,skills.evomultiplier,skills.accuracy FROM skills  WHERE skills.id=?;";
        sqlite3_stmt *compiledStatement;
        int queryResult = sqlite3_prepare_v2(database, sqlStatement, -1, &compiledStatement, NULL);
        
        if( sqlite3_bind_int(compiledStatement,1,skillid) != SQLITE_OK )
            assert(0);
        
        if(queryResult ==  SQLITE_OK) {
            // Loop through the results and add them to the feeds array
            while(sqlite3_step(compiledStatement) == SQLITE_ROW) {
                // Read the data from the result row
                
                newItem = [[dataSkill alloc] init: compiledStatement];
                // Add the monster object to the monsters Array
                
            }
        } else {
            printf( "could not prepare statemnt: %s\n", sqlite3_errmsg(database) );
        }
        // Release the compiled statement from memory
        sqlite3_finalize(compiledStatement);
        
        
        sqlite3_close(database);
        return newItem;
    }
  */
}


void dataDictionary::getMonstersOfType(CCString * type,CCArray * array)
{
    if( type != NULL )
    {
        for (int i=0 ; i<monsters->count(); i++)
        {
            dataMonster * mon= (dataMonster*)monsters->objectAtIndex(i);
            
            if((this->getTypeFromId(mon->type1Id)->isEqual(CCString::create( type->getCString()))))
            {
                array->addObject(mon);
            }
        }
    } 
    else
    {
        for (int i=0 ; i<monsters->count(); i++)
        {
            dataMonster * mon= (dataMonster*)monsters->objectAtIndex(i);

            array->addObject(mon);
        }
    }
}



double dataDictionary::typeModFor(int atkType,int defType)
{
    /* PENDING_DEEPAK
    @synchronized(self) {
        
        sqlite3* database = [self getOpenDatabase];
        
        // Setup the SQL Statement and compile it for faster access
        const char *sqlStatement = "SELECT modvalue FROM element_type_rule WHERE Type1Id=? AND Type2Id=?;";
        sqlite3_stmt *compiledStatement;
        int queryResult = sqlite3_prepare_v2(database, sqlStatement, -1, &compiledStatement, NULL);
        
        if( sqlite3_bind_int(compiledStatement,1,atkType) != SQLITE_OK )
            assert(0);
        if( sqlite3_bind_int(compiledStatement,2,defType) != SQLITE_OK )
            assert(0);
        
        double retValue = 1;
        
        if(queryResult ==  SQLITE_OK) {
            // Loop through the results and add them to the feeds array
            while(sqlite3_step(compiledStatement) == SQLITE_ROW) {
                // Read the data from the result row
                retValue = sqlite3_column_double(compiledStatement,0);
            }
        } else {
            printf( "could not prepare statemnt: %s\n", sqlite3_errmsg(database) );
        }
        // Release the compiled statement from memory
        sqlite3_finalize(compiledStatement);
        
        
        sqlite3_close(database);
        
        return retValue;
    }
     */
    
}


CCArray *dataDictionary::getAttacksForMonster(int monid,int intel)
{
   
    
    CCArray * attacks =new CCArray();
   /* 
    @synchronized(self) {
        sqlite3* database = [self getOpenDatabase];
        
        
        // Setup the SQL Statement and compile it for faster access
        const char *sqlStatement = "SELECT skills.id,skills.name,skills.hits,skills.scope,skills.element_type_id,skills.power,skills.evomultiplier,skills.accuracy FROM skillsmapping LEFT JOIN skills ON skills.id=skillsmapping.skillid WHERE monsterid=? AND skills.power<=? ORDER BY skills.power ASC";
        sqlite3_stmt *compiledStatement;
        int queryResult = sqlite3_prepare_v2(database, sqlStatement, -1, &compiledStatement, NULL);
        
        if( sqlite3_bind_int(compiledStatement,1,monid) != SQLITE_OK )
            assert(0);
        if( sqlite3_bind_int(compiledStatement,2,intel) != SQLITE_OK )
            assert(0);
        
        if(queryResult ==  SQLITE_OK) {
            // Loop through the results and add them to the feeds array
            while(sqlite3_step(compiledStatement) == SQLITE_ROW) {
                // Read the data from the result row
                
                dataSkill * newItem = [[dataSkill alloc] init: compiledStatement];
                // Add the monster object to the monsters Array
                [attacks addObject:newItem];
                [newItem release];
            }
        } else {
            printf( "could not prepare statemnt: %s\n", sqlite3_errmsg(database) );
        }
        // Release the compiled statement from memory
        sqlite3_finalize(compiledStatement);
        
        
        sqlite3_close(database);
        
    }
    
    if( [attacks count] == 0 ) {
        //Add Slap if no other attacks exist
        [attacks addObject:[self getAttackForId: 1]];
    }
    
    return attacks; */
}





dataMonster *dataDictionary::monById(int monid)
{
   
    for(  int i=0;i<monsters->count();i++)
    {
        dataMonster * newMon = (dataMonster*)monsters->objectAtIndex(i);
            if( newMon->monid == monid ) 
            {
                return newMon;
            }
        }
    
	return NULL;
}


dataItem *dataDictionary:: itemById(int itemid)
{
    
    for(int i=0 ;i<items->count();i++)
    {    dataItem * item= (dataItem*)items->objectAtIndex(i);
            if( item->itemid == itemid ) 
            {
                return item;
            }
    }
    
	return NULL;
}


dataItem *dataDictionary::getItemForValue(int value)
{
    // PENDING_DEEPAK @synchronized(self)
    {
        CCArray * itemsWithinRange = new CCArray();
        
        for( int i=0;i<items->count();i++)
        {
            dataItem * item= (dataItem*)items->objectAtIndex(i);
            if( value > item->sellPrice - 150 && value < item->sellPrice + 150 )
            {
                itemsWithinRange->addObject(item);
            }
        }
        
        if( itemsWithinRange->count() == 0 )
        {
            itemsWithinRange->removeAllObjects();
            itemsWithinRange->release();
            return this->itemById(18);
        }
        else 
        {
            int itemToReturn = arc4random() % (itemsWithinRange->count());
            dataItem * tmpItem = (dataItem*)itemsWithinRange->objectAtIndex(itemToReturn);
            
            itemsWithinRange->removeAllObjects();
            itemsWithinRange->release();
            return tmpItem;
        }
        
    }
    //Should never hit this assert.
    //    asert(0);
    return NULL;
}


#pragma dataZoneMonster

/* PENDING_DEEPAK
-(dataZoneMonster *) init: (sqlite3_stmt *) stmt andParent: (dataDictionary *) parent {
    self = [super init];
	if(self != nil ) {
        monid  = sqlite3_column_int(stmt,0);
        levellow = sqlite3_column_int(stmt,1);
        levelhigh = sqlite3_column_int(stmt,2);
        
        mon = [parent monById:monid];
    }
    return self;
}
*/


dataMonster *dataZoneMonster::getMonster() 
{
    return mon;
}


#pragma dataSkill



/*PENDING_DEEPAk
-(dataSkill *) init: (sqlite3_stmt *) stmt {
    //skills.id,skills.name,skills.hits,skills.scope,skills.element_type_id,skills.power,skills.evomultiplier,skills.accuracy
    self = [super init];
	if(self != nil ) {
		
		skillid = sqlite3_column_int(stmt,0);
		name = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 1)];
		[name retain];
        hits = sqlite3_column_int(stmt,2);
        scope = sqlite3_column_int(stmt,3);
        element_type_id = sqlite3_column_int(stmt,4);
        power = sqlite3_column_int(stmt,5);
        evomultiplier = sqlite3_column_int(stmt,6);
        accuracy = sqlite3_column_int(stmt,7);
        
		
	}
	return self;
}*/

CCString* dataSkill::getName()
{
    return name;
}
int dataSkill::getTypeId() 
{
    return element_type_id;
}


#pragma dataItem


/* PENDING_DEEPAK
-(dataItem *) init: (sqlite3_stmt *) stmt {
	self = [super init];
	if(self != nil ) {
		
		itemid = sqlite3_column_int(stmt,0);
		name = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 1)];
		[name retain];
        scope = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 2)];
		[scope retain]; 
        description = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 3)];
		[description retain]; 
		buyPrice = sqlite3_column_int(stmt,4);
        sellPrice = sqlite3_column_int(stmt,5);
        
		
	}
	return self;
}
 */



CCString *dataItem::getName()
{
	return name;
}
CCString *dataItem::getDescription()
{
	return description;
}
bool dataItem::isBattleItem()
{
    if( scope->isEqual(CCString::create("Battle Item")))
    {
        return true;
    }
    return false;
}

CCString* dataItem::getScope()
{
	return scope;
}


#pragma  dataMonster

/* PENDING_DEEPAK
-(dataMonster *) init: (sqlite3_stmt *) stmt andDatabase: (dataDictionary *) parent {
	self = [super init];
	if(self != nil ) {
		parentObj = parent;
        
		monid = sqlite3_column_int(stmt,0);
		name = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 1)];
		[name retain];
		
		hp = sqlite3_column_int(stmt,2);
		atk = sqlite3_column_int(stmt,3);
		def = sqlite3_column_int(stmt,4);
		spd = sqlite3_column_int(stmt,5);
		intel = sqlite3_column_int(stmt,14);
        
		exp = sqlite3_column_int(stmt,6);
		evolvelvl = sqlite3_column_int(stmt,7);
		evolvesto = sqlite3_column_int(stmt,8);
		evolutionlvl = sqlite3_column_int(stmt,9);
		tamedifficulty = sqlite3_column_int(stmt,10);
		type1Id = sqlite3_column_int(stmt,11);
		type2Id = sqlite3_column_int(stmt,12);
		maleratio = sqlite3_column_double(stmt,13);
        rarity = sqlite3_column_double(stmt,18);
        
        type1 = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 15)];
        type2 = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 16)];
        category = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 17)];
        
        [type1 retain];
        [type2 retain];
        [category retain];        
	}
	return self;
}
*/

CCString *dataMonster::get3DigitNo()
{
    CCString * fullID = CCString::createWithFormat("%s%d","000",monid);
    CCString * leadingZerosID = convertedString->substringToIndex(fullID, fullID->length()-3);
	return leadingZerosID;
}

CCString *dataMonster::getImage()
{
    CCString * fullID = CCString::createWithFormat("%s%d","000",monid);
    CCString * leadingZerosID = convertedString->substringToIndex(fullID, fullID->length()-3);
    CCString * fileName =CCString::createWithFormat("%s%s%s","dpffa",leadingZerosID->getCString() ,".png");
   return fileName;
	
}

CCString *dataMonster::getName()
{
	return name;
}
CCString* dataMonster::getType1()
{
	return parentObj->getTypeFromId( type1Id);
}
CCString *dataMonster::getType2()
{
	return parentObj->getTypeFromId( type2Id);
}
CCString *dataMonster::getCategory()
{
	return category;
}













