//
// Created by yjin on 2018/2/1.
//
#include <C2DXAnalySDK/C2DXAnalySDKTypeDef.h>
#include "RoleEvent.h"
using namespace cn::analysdk;

BaseEvent::BaseEvent(C2DXString* uId,C2DXString* rId)
{
    setUserId(uId);
    roleId = rId;
}

C2DXDictionary* RoleEvent::toHashMap(){
        C2DXDictionary* diction = getHashMap();
        diction->setObject(roServer,"_roServer");
        diction->setObject(roName,"_roName");
        diction->setObject(roCareer,"_roCareer");
        diction->setObject(roLevel,"_roLevel");
        diction->setObject(roVip,"_roVip");
        diction->setObject(roRankLevel,"_roRankLevel");
        diction->setObject(roEnergy,"_roEnergy");
        diction->setObject(roMoney,"_roMoney");
        diction->setObject(roCoin,"_roCoin");
        diction->setObject(roSourcel,"_roSource1");
        diction->setObject(roSource2,"_roSource2");
        diction->setObject(roSource3,"_roSource3");
        diction->setObject(reSource4,"_roSource4");
        return diction;
}

RoleEvent::~RoleEvent()
{
}
