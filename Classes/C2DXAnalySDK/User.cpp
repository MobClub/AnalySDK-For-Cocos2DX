//
//  User.cpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/2/8.
//

#include "User.h"

using namespace mob::analysdk;
std::string User::toString() {
    std::stringstream stream;
    stream << "{";
    if(userId != NULL) {
        stream << "\"_userId\":" << "\"" << userId << "\",";
    }
    if(nickName != NULL) {
        stream << "\"_nickName\":" << "\"" << nickName << "\",";
    }
    if(gender != NULL) {
        stream << "\"_gender\":" << "\"" << gender << "\",";
    }
    if(country != NULL) {
        stream << "\"_country\":" << "\"" << country << "\",";
    }
    if(province != NULL) {
        stream << "\"_province\":" << "\"" << province << "\",";
    }
    if(constellation != NULL) {
        stream << "\"_constellation\":" << "\"" << constellation << "\",";
    }
    if(zodiac != NULL) {
        stream << "\"_zodiac\":" << "\"" << zodiac << "\",";
    }
    if(regType != NULL) {
        stream << "\"_regType\":" << "\"" << regType << "\",";
    }
    if(regChannel != NULL) {
        stream << "\"_regChannel\":" << "\"" << regChannel << "\",";
    }
    if(loginType != NULL) {
        stream << "\"_loginType\":" << "\"" << loginType << "\",";
    }
    if(loginChannel != NULL) {
        stream << "\"_loginChannel\":" << "\"" << loginChannel << "\",";
    }
    if(userType != NULL) {
        stream << "\"_userType\":" << "\"" << userType << "\",";
    }
    if(addiction != NULL) {
        stream << "\"_addiction\":" << "\"" << addiction << "\",";
    }
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        if (customProperties != NULL) {
            CCJSONConverter* json = CCJSONConverter::sharedConverter();
            const char* ccInfo = json->strFrom2(customProperties);
            stream << "\"customProperties\":" << "\"" << ccInfo << "\",";
        }
    #endif
    stream << "\"_age\":" << age << ",";
    stream << "\"_money\":" << money;
    stream << "}";
    return stream.str();
}
