//
// Created by yjin on 2018/2/1.
//

#ifndef COCOS2DX_FOR_ANALYSDK_BASEEVENT_H
#define COCOS2DX_FOR_ANALYSDK_BASEEVENT_H
#include <stdio.h>
#include <iostream>
//typedef std::string C2DXString;
//#define C2DXDictionary CCDictionary

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"


namespace cn
{
    namespace analysdk
    {
        class BaseEvent
        {
            public:
                C2DXString* roleId;
                virtual C2DXString* getUserId();
                virtual void setUserId(C2DXString* userID);
                 BaseEvent(C2DXString* userId,C2DXString* roleId);
            private:
                 C2DXString* userId;
                 C2DXDictionary* params;
            protected:
                virtual C2DXDictionary* toHashMap();
                virtual C2DXDictionary* getHashMap();
            public:
             virtual ~BaseEvent();
        };
    }
}

#endif //COCOS2DX_FOR_ANALYSDK_BASEEVENT_H
