//
//  AnalySDKCallBack.h
//  Cocos2DX-For-AnalySDK
//
//  Created by 刘靖煌 on 2018/2/8.
//

#ifndef AnalySDKCallBack_h
#define AnalySDKCallBack_h

namespace mob
{
    namespace analysdk
    {
        /**
         获取跟踪标识回调
         
         @param trackId 跟踪标识Id
         */
        typedef void(*TrackIdResult) (const char *trackId);
    }
}

#endif
