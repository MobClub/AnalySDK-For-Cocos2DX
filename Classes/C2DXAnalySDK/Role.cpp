//
//  Role.cpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/2/7.
//
#include "Role.h"
using namespace mob::analysdk;

std::string Role::toString(){
    std::stringstream stream;
    stream << "{";
    if(userId != NULL) {
        stream << "\"_userId\":" << "\"" << userId << "\",";
    }
    if(roleId != NULL) {
        stream << "\"_roleId\":" << "\"" << roleId << "\",";
    }
    if(roServer != NULL) {
        stream << "\"_roServer\":" << "\"" << roServer << "\",";
    }
    if(roName != NULL) {
        stream << "\"_roName\":" << "\"" << roName << "\",";
    }
    if(roCareer != NULL) {
        stream << "\"_roCareer\":" << "\"" << roCareer << "\",";
    }
    if(roVip != NULL) {
        stream << "\"_roVip\":" << "\"" << roVip << "\",";
    }
    if(roRankLevel != NULL) {
        stream << "\"_roRankLevel\":" << "\"" << roRankLevel << "\",";
    }

    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        if (customProperties != NULL) {
            CCJSONConverter* json = CCJSONConverter::sharedConverter();
            const char* ccInfo = json->strFrom2(customProperties);
            stream << "\"customProperties\":" << "\"" << ccInfo << "\",";
        }
    #endif
    stream << "\"_roLevel\":" << roLevel << ",";
    stream << "\"_roEnergy\":" << roEnergy << ",";
    stream << "\"_roMoney\":" << roMoney << ",";
    stream << "\"_roMoney\":" << roCoin << ",";
    stream << "\"_roSource1\":" << roSource1 << ",";
    stream << "\"_roSource2\":" << roSource2 << ",";
    stream << "\"_roSource3\":" << roSource3 << ",";
    stream << "\"_roSource4\":" << roSource4;
    stream << "}";
    return stream.str();
}
