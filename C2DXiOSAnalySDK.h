//
//  C2DXiOSAnalySDK.h
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/1/17.
//

#include <stdio.h>
#include "cocos2d.h"
#import "C2DXAnalySDKTypeDef.h"

namespace cn
{
    namespace analysdk
    {
        /**
         *    @brief    AnalySDK 云端版
         */
        class C2DXiOSAnalySDK
        {
            
        public:
            /**
             *    @brief    初始化ShareSDK
             *
             *    @param     appKey     appKey
             *    @param     configInfo     平台配置信息
             */
            static void trackEvent(const char *eventName, C2DXDictionary *eventParams);
            
            /**
             *    @brief    用户授权
             *
             *    @param     reqID     流水号
             *    @param     platType     平台类型
             *    @param     callback     回调方法
             */
            static void setLocation(C2DXDouble latitude, C2DXDouble longitude);
        };
    }
}


