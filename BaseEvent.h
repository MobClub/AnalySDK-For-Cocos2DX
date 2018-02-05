//
// Created by yjin on 2018/2/1.
//

#ifndef COCOS2DX_FOR_ANALYSDK_BASEEVENT_H
#define COCOS2DX_FOR_ANALYSDK_BASEEVENT_H
typedef std::string C2DXString;
#define C2DXDictionary CCDictionary

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"


namespace mob
{
    namespace analysdk
    {
        class BaseEvent
        {
            public:
                C2DXString roleId;
                virtual C2DXString getUserId();
                virtual C2DXString setUserId(C2DXString userId);
                BaseEvent(C2DXString userId,C2DXString roleId);
                C2DXString roleId;
            private:
                virtual C2DXString userId;
                virtual C2DXDictionary * params;
            protected:
                virtual C2DXDictionary toHashMap();
                virtual C2DXDictionary getHashMap();
            public:
             virtual ~BaseEvent(C2DXString userId,C2DXString roleId);
        };
    }
}

#endif //COCOS2DX_FOR_ANALYSDK_BASEEVENT_H
