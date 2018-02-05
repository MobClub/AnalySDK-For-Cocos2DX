//
// Created by yjin on 2018/2/1.
//
#include <stdio.h>
#include "BaseEvent.h"

#ifndef COCOS2DX_FOR_ANALYSDK_ROLEEVENT_H
#define COCOS2DX_FOR_ANALYSDK_ROLEEVENT_H

namespace mob
{
    namespace analysdk{
        class RoleEvent :public BaseEvent
        {
            public:
            C2DXString roServer;
            C2DXString roName;
            C2DXString roCareer;
            int roLevel;
            C2DXString roVip;
            C2DXString roRankLevel;
            int roEnergy;
            float roMoney;
            float roCoin;
            float roSourcel;
            float roSource2;
            float roSource3;
            float reSource4;
            RoleEvent();
        };
    }
}
#endif //COCOS2DX_FOR_ANALYSDK_ROLEEVENT_H
