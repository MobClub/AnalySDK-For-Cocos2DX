//
// Created by yjin on 2018/2/1.
//
#include"BaeEvent.h"

using namespace mob::analysdk;

BaeEvent::BaeEvent(C2DXString* userID,C2DXString* roleID)
{
    userId = userID;
    roleId = roleID;
    params = C2DXDictionary::create();
    params->setObject(userId,"_userId");
    params->setObject(roleId,"_roleId");
}

C2DXString BaseEvent::getUserId()
{
    return userId;
}

C2DXString BaseEvent::setUserId(C2DXString id)
{
    userId = id;
}

C2DXDictionary BaseEvent:toHashMap()
{
    return params;
}

C2DXDictionary BaseEvent:getHashMap()
{
}

BaeEvent::~BaeEvent()
{

}