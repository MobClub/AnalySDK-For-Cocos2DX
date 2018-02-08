//
//  Role.hpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/2/7.
//

#ifndef Role_hpp
#define Role_hpp

#include "C2DXAnalySDKTypeDef.h"
#include <stdio.h>

namespace mob
{
    namespace analysdk
    {
        class Role
        {
            public:
            
            /**
             *  用户id(必传属性)
             */
            std::string *userId;
            
            /**
             *  角色id(必传属性)
             */
            std::string *roleId;
            
            /**
             *  区服
             */
            std::string *roServer;
            
            /**
             *  角色名称
             */
            std::string *roName;
            
            /**
             *  角色职业
             */
            std::string *roCareer;
            
            /**
             *  角色等级
             */
            double roLevel;
            
            /**
             *  角色vip级别
             */
            std::string *roVip;
            
            /**
             *  角色排位级别
             */
            std::string *roRankLevel;
            
            /**
             *  角色体力
             */
            double roEnergy;
            
            /**
             *  角色货币（直充货币）
             */
            double roMoney;
            
            /**
             *  角色游戏币（非直充货币）
             */
            double roCoin;
            
            /**
             *  核心资源1
             */
            double roSource1;
            
            /**
             *  核心资源2
             */
            double roSource2;
            
            /**
             *  核心资源3
             */
            double roSource3;
            
            /**
             *  核心资源4
             */
            double roSource4;
            
            /**
             *  其他自定义属性
             */
            C2DXDictionary *customProperties;
            
        };
    }
}

#endif 
