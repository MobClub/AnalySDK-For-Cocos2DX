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
#include "User.h"
#include "PayEvent.h"
#include "Role.h"

using namespace mob::analysdk;

namespace mob
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
             支付事件统计(建议支付类型事件使用此接口统计)
             
             @param payEvent 支付事件
             */
            static void trackPayEvent(PayEvent *payEvent);
            
            /**
             用户注册事件
             建议创建带有注册类型(regType)和注册渠道(regChannel)的user
             
             @param user 用户实体
             */
            static void userRegister(User *user);
            
            /**
             用户登录事件
             建议创建带有登录类型(regType)和登录渠道(regChannel)的user
             
             @param user 用户实体
             */
            static void userLogin(User *user);
            
            /**
             用户信息更新事件
             
             @param user 用户实体
             */
            static void userUpdate(User *user);
            
            /**
             角色创建事件
             
             @param role 角色实体
             */
            static void roleCreate(Role *role);
            
            /**
             角色登录事件
             
             @param role 角色实体
             */
            static void roleLogin(Role *role);
            
            /**
             角色信息更新事件
             
             @param role 角色实体
             */
            static void roleUpdate(Role *role);
            
            /**
             *    @brief    设置地理位置信息(一旦设置,则事件的追踪均带上此地理信息;否则不带)
             *
             *    @param     latitude     纬度
             *    @param     longitude    经度
             */
            static void setLocation(double latitude, double longitude);
            
            /**
             *    @brief    开始统计行为/事件时长(请结合behaviorEnd()使用,并对同一事件传入同一eventName)
             *
             *    @param     eventName      行为/事件名称
             *    @param     eventParams    自定义参数
             */
            static void behaviorStart(const char *eventName, C2DXDictionary *eventParams);
            
            /**
             *    @brief    结束统计行为/事件时长(请结合behaviorStart()使用,并对同一事件传入同一eventName)
             *
             *    @param     eventName      行为/事件名称
             *    @param     eventParams    自定义参数
             */
            static void behaviorEnd(const char *eventName, C2DXDictionary *eventParams);
            
        };
    }
}

#endif 
