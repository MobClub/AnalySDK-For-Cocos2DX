//
// Created by yjin on 2018/1/30.
//
#include "UserEvent.h"
#include "PayEvent.h"
#include "RoleEvent.h"
#include "JvmJniEnv.h"
#include "CCJSONConverter.h"
#ifndef COCOS2DX_FOR_ANALYSDK_C2DXANDROIDANALYSDK_H
#define COCOS2DX_FOR_ANALYSDK_C2DXANDROIDANALYSDK_H
namespace mob
{
    namespace analysdk
    {
        class C2DXAndroidAnalySDK
        {
             public:
                    C2DXAndroidAnalySDK();
                    ~C2DXAndroidAnalySDK();
                     void setLocation(double longitude,double latitude);

                     void trackEvent(String eventName,C2DXDictionary dictionary);

                     void trackPayEvent(PayEvent payEvent);

                     void userRegist(UserEvent userevent);

                     void userLogin(UserEvent userevent);

                     void userUpdate(UserEvent userEvent);

                     void roleCreate(RoleEvent roleEvent);

                     void roleLogin(RoleEvent roleEvent);

                     void roleUpdate(RoleEvent roleEvent);
        };
    }

}

#endif //COCOS2DX_FOR_ANALYSDK_C2DXANDROIDANALYSDK_H


