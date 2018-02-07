//
// Created by yjin on 2018/2/1.
//
#include <stdio.h>
#include <C2DXAnalySDK/C2DXAnalySDKTypeDef.h>
#include "BaseEvent.h"

#ifndef COCOS2DX_FOR_ANALYSDK_USEREVENT_H
#define COCOS2DX_FOR_ANALYSDK_USEREVENT_H
namespace cn
{
    namespace analysdk{
     class UserEvent: public BaseEvent
     {
        public:
         UserEvent(C2DXString* userId,C2DXString* roleId);
          ~UserEvent();

          C2DXString* regType;
          C2DXString* regChanel;
          C2DXString* userType;
          C2DXString* addiction;
          C2DXDouble* money;
          C2DXString* gender;
          C2DXString* county;
          C2DXString* province;
          C2DXString* city;
          C2DXInteger* age;
          C2DXString* constellation;
          C2DXString* zodiac;
          C2DXString* nickname;
          C2DXDictionary* toHashMap();
     };
    }
}
#endif //COCOS2DX_FOR_ANALYSDK_USEREVENT_H
