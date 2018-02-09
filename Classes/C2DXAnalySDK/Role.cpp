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
    stream << "\"userId\":" << "\"" << userId << "\",";
    stream << "\"_roleId\":" << "\"" << roleId << "\",";
    stream << "\"_roServer\":" << "\"" << roServer << "\",";
    stream << "\"_roName\":" << "\"" << roName << "\",";
    stream << "\"_roCareer\":" << "\"" << roCareer << "\",";
    stream << "\"_roLevel\":" << "\"" << roLevel << "\",";
    stream << "\"_roVip\":" << "\"" << roVip << "\",";
    stream << "\"_roRankLevel\":" << "\"" << roRankLevel << "\",";
    stream << "\"_roEnergy\":" << "\"" << roEnergy << "\",";
    stream << "\"_roMoney\":" << "\"" << roMoney << "\",";
    stream << "\"_roMoney\":" << "\"" << roCoin << "\",";
    stream << "\"_roSource1\":" << "\"" << roSource1 << "\",";
    stream << "\"_roSource2\":" << "\"" << roSource2 << "\",";
    stream << "\"_roSource3\":" << "\"" << roSource3 << "\",";
    stream << "\"_roSource4\":" << "\"" << roSource4 << "\"";
    stream << "}";
    return stream.str();
}
