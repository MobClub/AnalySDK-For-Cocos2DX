//
// Created by yjin on 2018/2/1.
//
#include "UserEvent.h"
using namespace mob::analysdk;

UserEvent::UserEvent(C2DXString uId,C2DXString rId)
{
    userId = uId;
    roleId = rId;
}

C2DXDictionary* UserEvent::toHashMap(){
        C2DXDictionary* diction = getHashMap();
        diction->setObject(regType,"_regType");
        diction->setObject(regChannel,"_regChannel");
        diction->setObject(userType,"_userType");
        diction->setObject(addiction,"_addiction");
        diction->setObject(money,"_money");
        diction->setObject(gender,"_gender");
        diction->setObject(county,"_county");
        diction->setObject(province,"_province");
        diction->setObject(city,"_city");
        diction->setObject(age,"_age");
        diction->setObject(constellation,"_constellation);
        diction->setObject(zodiac,"_zodiac");
        diction->setObject(nickname,"_nickname");
        return diction;
}

UserEvent::~UserEvent()
{
}