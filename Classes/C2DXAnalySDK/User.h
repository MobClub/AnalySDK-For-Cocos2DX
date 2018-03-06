//
//  User.hpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/2/8.
//

#ifndef User_hpp
#define User_hpp

#include "C2DXAnalySDKTypeDef.h"
#include <stdio.h>

namespace mob
{
    namespace analysdk
    {
        class User
        {

        public:
            /**
             *  用户id(必传属性)
             */
            const char *userId;
            
            /**
             *  昵称
             */
            const char *nickName;
            
            /**
             *  性别
             */
            const char *gender;
            
            /**
             *  国家
             */
            const char *country;
            
            /**
             *  省份
             */
            const char *province;
            
            /**
             *  城市
             */
            const char *city;
            
            /**
             *  年龄
             */
            int age;
            
            /**
             *  星座
             */
            const char *constellation;
            
            /**
             *  生肖
             */
            const char *zodiac;
            
            /**
             *  注册方式
             */
            const char *regType;
            
            /**
             *  注册渠道
             */
            const char *regChannel;
            
            /**
             *  登录方式
             */
            const char *loginType;
            
            /**
             *  登录渠道
             */
            const char *loginChannel;
            
            /**
             *  账号类型
             */
            const char *userType;
            
            /**
             *  防沉迷标识
             */
            const char *addiction;
            
            /**
             *  账号通用货币金额
             */
            double money;
            
            /**
             *  其他自定义属性
             */
            C2DXDictionary *customProperties;
            
        };
    }
}


#endif
