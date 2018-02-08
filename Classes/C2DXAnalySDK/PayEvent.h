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
             *  支付类型
             */
            std::string *payType;
            
            /**
             *  支付活动
             */
            std::string *payActivity;
            
            /**
             *  折扣
             */
            double payDiscount;
            
            /**
             *  折扣原因
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
