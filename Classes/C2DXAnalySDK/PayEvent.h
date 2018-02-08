//
//  PayEvent.hpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/2/8.
//

#ifndef PayEvent_hpp
#define PayEvent_hpp

#include <stdio.h>
#include "C2DXAnalySDKTypeDef.h"

namespace mob
{
    namespace analysdk
    {
        class PayEvent
        {
            public:
            
            /**
             *  支付价钱,单位为分
             */
            int payMoney;
            
            /**
             *  角色id(必传属性)
             */
            std::string *payContent;
            
            /**
             *  区服
             */
            std::string *payType;
            
            /**
             *  角色名称
             */
            std::string *payActivity;
            
            /**
             *  角色等级
             */
            double payDiscount;
            
            /**
             *  角色职业
             */
            std::string *discountReason;
            
            /**
             *  其他自定义属性
             */
            C2DXDictionary *customProperties;
        };
    }
}

#endif
