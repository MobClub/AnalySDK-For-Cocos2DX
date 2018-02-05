//
// Created by yjin on 2018/2/1.
//

#ifndef COCOS2DX_FOR_ANALYSDK_PAYEVENT_H
#define COCOS2DX_FOR_ANALYSDK_PAYEVENT_H

#include <stdio.h>
#include "BaseEvent.h"
namespace mob
{
    namespace analysdk
    {
        class PayEvent: public BaseEvent
        {
            public:
            PayEvent(C2DXString userId,C2DXString roleId);
            long payMoney;
            C2DXString payContent;
            C2DXString payType;
            C2DXString payActivity;
            long payDiscount;
            C2DXString discountReason;
            C2DXDictionary toHashMap();
            ~PayEvent(C2DXString userId,C2DXString roleId);
        };
    }
}
#endif //COCOS2DX_FOR_ANALYSDK_PAYEVENT_H
