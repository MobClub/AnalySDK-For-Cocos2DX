//
// Created by yjin on 2018/2/1.
//

#ifndef COCOS2DX_FOR_ANALYSDK_PAYEVENT_H
#define COCOS2DX_FOR_ANALYSDK_PAYEVENT_H

#include <stdio.h>
#include "BaseEvent.h"
namespace cn
{
    namespace analysdk
    {
        class PayEvent: public BaseEvent
        {
            public:
            PayEvent(C2DXString* userId,C2DXString* roleId);
            C2DXDouble* payMoney;
            C2DXString* payContent;
            C2DXString* payType;
            C2DXString* payActivity;
            C2DXDouble* payDiscount;
            C2DXString* discountReason;
            C2DXDictionary* toHashMap();
            ~PayEvent();
        };
    }
}
#endif //COCOS2DX_FOR_ANALYSDK_PAYEVENT_H
