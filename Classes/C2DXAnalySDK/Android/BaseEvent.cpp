//
// Created by yjin on 2018/2/1.
//

#include <C2DXAnalySDK/C2DXAnalySDKTypeDef.h>
#include "BaseEvent.h"
using namespace cn::analysdk;

BaseEvent::BaseEvent(C2DXString* userID,C2DXString* roleID)
{
    userId = userID;
    roleId = roleID;
    params = C2DXDictionary::create();
    params->setObject(userId,"_userId");
    params->setObject(roleId,"_roleId");
}

C2DXString* BaseEvent::getUserId()
{
    return userId;
}

void BaseEvent::setUserId(C2DXString* id)
{
    userId = id;
}

C2DXDictionary* BaseEvent::toHashMap()
{
    return params;
}

C2DXDictionary* BaseEvent::getHashMap()
{
}

BaseEvent::~BaseEvent()
{
}