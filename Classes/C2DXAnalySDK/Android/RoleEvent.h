//
// Created by yjin on 2018/2/1.
//
#include <stdio.h>
#include "BaseEvent.h"

#ifndef COCOS2DX_FOR_ANALYSDK_ROLEEVENT_H
#define COCOS2DX_FOR_ANALYSDK_ROLEEVENT_H

namespace cn
{
    namespace analysdk{
        class RoleEvent :public BaseEvent
        {
            public:
            C2DXString* roServer;
            C2DXString* roName;
            C2DXString* roCareer;
            C2DXInteger* roLevel;
            C2DXString* roVip;
            C2DXString* roRankLevel;
            C2DXInteger* roEnergy;
            C2DXDouble* roMoney;
            C2DXDouble* roCoin;
            C2DXDouble* roSourcel;
            C2DXDouble* roSource2;
            C2DXDouble* roSource3;
            C2DXDouble* reSource4;
            C2DXDictionary* toHashMap();
             RoleEvent(C2DXString userId,C2DXString roleId);
            ~RoleEvent();
        };
    }
}
#endif //COCOS2DX_FOR_ANALYSDK_ROLEEVENT_H
