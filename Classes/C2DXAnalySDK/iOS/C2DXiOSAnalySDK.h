//
//  C2DXiOSAnalySDK.h
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/1/17.
//

#include <stdio.h>
#include "cocos2d.h"

#import "C2DXAnalySDKTypeDef.h"
#include "User.h"
#include "PayEvent.h"
#include "Role.h"

namespace mob
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
             支付事件统计(建议支付类型事件使用此接口统计)
             
             @param payEvent 支付事件
             */
            static void trackPayEvent(PayEvent *payEvent);
            
            /**
             用户注册事件
             建议使用 +[User userWithId:regType:regChannel:]
             创建带有注册类型(regType)和注册渠道(regChannel)的user
             
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
             *    @brief    用户授权
             *
             *    @param     reqID     流水号
             *    @param     platType     平台类型
             *    @param     callback     回调方法
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


