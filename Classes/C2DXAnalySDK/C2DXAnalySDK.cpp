//
//  C2DXAnalySDK.cpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/1/17.
//

#include "C2DXAnalySDK.hpp"
#include "C2DXiOSAnalySDK.h"
#include "C2DXAndroidAnalySDK.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#endif

using namespace mob::analysdk;

void trackEvent(const char *eventName, C2DXDictionary *eventParams)
{
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidAnalySDK::trackEvent(eventName,eventParams);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::trackEvent(eventName, eventParams);
    
#endif
    
}

void trackPayEvent(PayEvent *payEvent)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidAnalySDK::trackPayEvent(payEvent);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::trackPayEvent(payEvent);
    
#endif
}

void userRegister(User *user)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidAnalySDK::userRegist(user);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::userRegister(user);
    
#endif
}

void userUpdate(User *user)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidAnalySDK::userUpdate(user);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::userUpdate(user);
    
#endif
}

void roleCreate(Role *role)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidAnalySDK::roleCreate(role);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::roleCreate(role);
    
#endif
}

void roleLogin(Role *role)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidAnalySDK::roleLogin(role);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::roleLogin(role);
    
#endif
}

void roleUpdate(Role *role)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidAnalySDK::roleUpdate(role);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::roleUpdate(role);
    
#endif
}

void setLocation(double latitude, double longitude)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidAnalySDK::setLocation(latitude,longitude);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::setLocation(latitude, longitude);
    
#endif
}

