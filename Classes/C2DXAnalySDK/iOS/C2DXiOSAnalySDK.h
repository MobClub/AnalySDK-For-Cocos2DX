//
//  C2DXiOSAnalySDK.h
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/1/17.
//

#include <stdio.h>
#include "cocos2d.h"

#import "C2DXAnalySDKTypeDef.h"
#include "AnalySDKCallBack.h"
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
             获取跟踪标识
             
             @param callback 回调
             */
            static void trackId(TrackIdResult callback);
        };
    }
}


