//
// Created by yjin on 2018/1/30.
//
#ifndef COCOS2DX_FOR_ANALYSDK_C2DXANDROIDANALYSDK_H
#define COCOS2DX_FOR_ANALYSDK_C2DXANDROIDANALYSDK_H

#include "User.h"
#include "PayEvent.h"
#include "Role.h"
#include "JvmJniEnv.h"
#include "CCJSONConverter.h"
#include "C2DXCxxJavaObject.h"

namespace mob
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

            static void userRegist(User* userevent);

            static void userLogin(User* userevent);

            static void userUpdate(User* userEvent);

            static void roleCreate(Role* roleEvent);

            static void roleLogin(Role* roleEvent);

            static void roleUpdate(Role* roleEvent);

            static void behaviorStart(const char* eventName,C2DXDictionary* dictionary);

            static void behaviorEnd(const char* eventName,C2DXDictionary* dictionary);

            static jstring charTojstring(JvmJniEnv env, const char* pat);
        };
    }

}

#endif //COCOS2DX_FOR_ANALYSDK_C2DXANDROIDANALYSDK_H


