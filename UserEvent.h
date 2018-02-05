//
// Created by yjin on 2018/2/1.
//
#include <stdio.h>
#include "BaseEvent.h"

#ifndef COCOS2DX_FOR_ANALYSDK_USEREVENT_H
#define COCOS2DX_FOR_ANALYSDK_USEREVENT_H
namespace mob
{
    namespace analysdk{
     class UserEvent: public BaseEvent
     {
        public:
          UserEvent(C2DXString userId,C2DXString roleId);
          ~UserEvent(C2DXString userId,C2DXString roleId);

          C2DXString regType;
          C2DXString regChanel;
          C2DXString addication;
          float money;
          C2DXString gender;
          C2DXString contry;
          C2DXString province;
          C2DXString city;
          int age;
          C2DXString constellation;
          C2DXString zodiac;
          C2DXString nickname;
     };
    }
}
#endif //COCOS2DX_FOR_ANALYSDK_USEREVENT_H
