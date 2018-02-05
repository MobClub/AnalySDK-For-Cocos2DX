//
//  C2DXAnalySDK.hpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/1/17.
//

#ifndef C2DXAnalySDK_hpp
#define C2DXAnalySDK_hpp

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include "cocos2d.h"
#include "C2DXAnalySDKTypeDef.h"

namespace cn
{
    namespace analysdk
    {
        /**
         *    @brief    AnalySDK
         */
        class C2DXAnalySDK
        {
        public:
            
            /**
             *    @brief    事件追踪
             *
             *    @param     eventName     事件名称
             *    @param     eventParams   事件属性
             */
            static void trackEvent(const char *eventName, C2DXDictionary *eventParams);
            
            /**
             *    @brief    设置地理位置信息(一旦设置,则事件的追踪均带上此地理信息;否则不带)
             *
             *    @param     latitude     纬度
             *    @param     longitude    经度
             */
            static int setLocation(C2DXDouble latitude, C2DXDouble longitude);
            
        };
    }
}

#endif /* C2DXAnalySDK_hpp */
