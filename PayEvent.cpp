//
// Created by yjin on 2018/2/1.
//

#include "PayEvent.h"
using namespace mob::analysdk;

PayEvent::PayEvent(C2DXString uId,C2DXString rId)
{
    setUserId(uId);
    roleId = rId;
}

C2DXDictionary* PayEvent::toHashMap(){
        C2DXDictionary* diction = getHashMap();
        diction->setObject(payMoney,"_userId");
        diction->setObject(payContent,"_roleId");
        diction->setObject(payType,"_payType");
        diction->setObject(payActivity,"_payActivity);
        diction->setObject(payDiscount,"_payDiscount");
        diction->setObject(discountReason,"_discountReason");
        return diction;
}

PayEvent::~PayEvent()
{
}