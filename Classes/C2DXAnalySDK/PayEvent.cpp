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
    stream << "\"_payMoney\":" << payMoney << ",";

    if(payContent != NULL) {
        stream << "\"_payContent\":" << "\"" << payContent << "\",";
    }
    if(payType != NULL) {
        stream << "\"_payType\":" << "\"" << payType << "\",";
    }
    if(payActivity != NULL){
        stream << "\"_payActivity\":" << "\"" << payActivity << "\",";
    }

    if(discountReason != NULL){
        stream << "\"_discountReason\":" << "\"" << discountReason << "\",";
    }
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        if (customProperties != NULL) {
            CCJSONConverter* json = CCJSONConverter::sharedConverter();
            const char* ccInfo = json->strFrom2(customProperties);
            stream << "\"customProperties\":" << "\"" << ccInfo << "\",";
        }
    #endif
    stream << "\"_payDiscount\":" << payDiscount;
    stream << "}";
    return stream.str();
}

