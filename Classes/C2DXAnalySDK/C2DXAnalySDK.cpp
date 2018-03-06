//
//  C2DXAnalySDK.cpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/1/17.
//

#include "C2DXAnalySDK.hpp"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "C2DXiOSAnalySDK.h"

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#endif

using namespace mob::analysdk;

void C2DXAnalySDK::trackEvent(const char *eventName, C2DXDictionary *eventParams)
{
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::trackEvent(eventName, eventParams);
    
#endif
    
}

void C2DXAnalySDK::trackPayEvent(PayEvent *payEvent)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::trackPayEvent(payEvent);
    
#endif
}

void C2DXAnalySDK::userRegister(User *user)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::userRegister(user);
    
#endif
}

void C2DXAnalySDK::userLogin(User *user)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::userLogin(user);
    
#endif
}

void C2DXAnalySDK::userUpdate(User *user)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::userUpdate(user);
    
#endif
}

void C2DXAnalySDK::roleCreate(Role *role)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::roleCreate(role);
    
#endif
}

void C2DXAnalySDK::roleLogin(Role *role)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::roleLogin(role);
    
#endif
}

void C2DXAnalySDK::roleUpdate(Role *role)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::roleUpdate(role);
    
#endif
}

void C2DXAnalySDK::setLocation(double latitude, double longitude)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::setLocation(latitude, longitude);
    
#endif
}

