//
//  C2DXAnalySDK.cpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/1/17.
//

#include "C2DXAnalySDK.hpp"
#include "C2DXiOSAnalySDK.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#endif

using namespace cn::analysdk;

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


void setLocation(C2DXDouble latitude, C2DXDouble longitude)
{
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidAnalySDK::trackEvent(latitude,longitude);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSAnalySDK::setLocation(latitude, longitude);
    
#endif
    
}
