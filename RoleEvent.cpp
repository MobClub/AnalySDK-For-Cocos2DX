//
// Created by yjin on 2018/2/1.
//
#inlcude "RoleEvent.h"
using namespace mob::analysdk;

RoleEvent::RoleEvent(C2DXString uId,C2DXString rId)
{
    userId = uId;
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
        diction->setObject(roCoin,"_roCoin);
        diction->setObject(roSource1,"_roSource1");
        diction->setObject(roSource2,"_roSource2");
        diction->setObject(roSource3,"_roSource3");
        diction->setObject(roSource4,"_roSource4);
        return diction;
}

RoleEvent::~RoleEvent()
{
}
