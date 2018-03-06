#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "C2DXAnalySDK.hpp"

using namespace std;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void trackEvent(cocos2d::Ref *pSender);
    
    void trackPayEvent(cocos2d::Ref *pSender);
    
    void userRegister(cocos2d::Ref *pSender);
    
    void userLogin(cocos2d::Ref *pSender);
    
    void userUpdate(cocos2d::Ref *pSender);
    
    void roleCreate(cocos2d::Ref *pSender);
    
    void roleLogin(cocos2d::Ref *pSender);
    
    void roleUpdate(cocos2d::Ref *pSender);
    
    void setLocation(cocos2d::Ref *pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
