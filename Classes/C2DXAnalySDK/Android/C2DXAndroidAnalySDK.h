//
// Created by yjin on 2018/1/30.
//
#ifndef COCOS2DX_FOR_ANALYSDK_C2DXANDROIDANALYSDK_H
#define COCOS2DX_FOR_ANALYSDK_C2DXANDROIDANALYSDK_H

#include "UserEvent.h"
#include "PayEvent.h"
#include "RoleEvent.h"
#include "JvmJniEnv.h"
#include "CCJSONConverter.h"
#include "C2DXCxxJavaObject.h"

namespace cn
{
    namespace analysdk
    {
        class C2DXAndroidAnalySDK
        {
             public:
                    C2DXAndroidAnalySDK();
                    ~C2DXAndroidAnalySDK();
                     static void setLocation(C2DXDouble longitude,C2DXDouble latitude);

                     static void trackEvent(const char* eventName,C2DXDictionary* dictionary);

                     static void trackPayEvent(PayEvent* payEvent);

                     static void userRegist(UserEvent* userevent);

                     static void userLogin(UserEvent* userevent);

                     static void userUpdate(UserEvent* userEvent);

                     static void roleCreate(RoleEvent* roleEvent);

                     static void roleLogin(RoleEvent* roleEvent);

                     static void roleUpdate(RoleEvent* roleEvent);
        };
    }

}

#endif //COCOS2DX_FOR_ANALYSDK_C2DXANDROIDANALYSDK_H


