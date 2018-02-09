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
    stream << "\"_userId\":" << "\"" << userId << "\",";
    stream << "\"_nickName\":" << "\"" << nickName << "\",";
    stream << "\"_gender\":" << "\"" << gender << "\",";
    stream << "\"_country\":" << "\"" << country << "\",";
    stream << "\"_province\":" << "\"" << province << "\",";
    stream << "\"_city\":" << "\"" << city << "\",";
    stream << "\"_constellation\":" << "\"" << constellation << "\",";
    stream << "\"_zodiac\":" << "\"" << zodiac << "\",";
    stream << "\"_regType\":" << "\"" << regType << "\",";
    stream << "\"_regChannel\":" << "\"" << regChannel << "\",";
    stream << "\"_loginType\":" << "\"" << loginType << "\",";
    stream << "\"_loginChannel\":" << "\"" << loginChannel << "\",";
    stream << "\"_userType\":" << "\"" << userType << "\",";
    stream << "\"_addiction\":" << "\"" << addiction << "\",";
    stream << "\"_money\":" << "\"" << money << "\"";
    stream << "}";
    return stream.str();
}
