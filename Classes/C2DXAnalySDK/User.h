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
            std::string *userId;
            
            /**
             *  昵称
             */
            std::string *nickName;
            
            /**
             *  性别
             */
            std::string *gender;
            
            /**
             *  国家
             */
            std::string *country;
            
            /**
             *  省份
             */
            std::string *province;
            
            /**
             *  城市
             */
            std::string *city;
            
            /**
             *  年龄
             */
            int age;
            
            /**
             *  星座
             */
            std::string *constellation;
            
            /**
             *  生肖
             */
            std::string *zodiac;
            
            /**
             *  注册方式
             */
            std::string *regType;
            
            /**
             *  注册渠道
             */
            std::string *regChannel;
            
            /**
             *  登录方式
             */
            std::string *loginType;
            
            /**
             *  登录渠道
             */
            std::string *loginChannel;
            
            /**
             *  账号类型
             */
            std::string *userType;
            
            /**
             *  防沉迷标识
             */
            std::string *addiction;
            
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
