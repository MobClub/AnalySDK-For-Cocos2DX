//
//  PayEvent.cpp
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/2/8.
//
#include "PayEvent.h"
using  namespace mob::analysdk;
std::string PayEvent::toString() {
    std::stringstream stream;
    stream << "{";
    stream << "\"_payMoney\":" << "\"" << payMoney << "\",";
    stream << "\"_payContent\":" << "\"" << payContent << "\",";
    stream << "\"_payType\":" << "\"" << payType << "\",";
    stream << "\"_payActivity\":" << "\"" << payActivity << "\",";
    stream << "\"_payDiscount\":" << "\"" << payDiscount << "\",";
    stream << "\"_discountReason\":" << "\"" << discountReason << "\"";
    stream << "}";
    return stream.str();
}

