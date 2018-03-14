#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace mob::analysdk;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
   
    Size winSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //事件追踪
    MenuItemLabel *trackEvent = MenuItemLabel::create(LabelTTF::create("事件追踪", "Arial", 14),
                                                                     CC_CALLBACK_1(HelloWorld::trackEvent, this));
    trackEvent->setPosition(winSize.width/3 * 1 , winSize.height / 10 * 8);
    auto trackEventMenu = Menu::create(trackEvent,NULL);
    trackEventMenu->setPosition(Vec2::ZERO);
    this->addChild(trackEventMenu);
    
    //支付事件统计
    MenuItemLabel *trackPayEvent = MenuItemLabel::create(LabelTTF::create("支付事件统计", "Arial", 14),
                                                      CC_CALLBACK_1(HelloWorld::trackPayEvent, this));
    trackPayEvent->setPosition(winSize.width/3 * 2 , winSize.height / 10 * 8);
    auto trackPayEventMenu = Menu::create(trackPayEvent, NULL);
    trackPayEventMenu->setPosition(Vec2::ZERO);
    this->addChild(trackPayEventMenu);
    
    //用户注册事件
    MenuItemLabel *userRegister = MenuItemLabel::create(LabelTTF::create("用户注册事件", "Arial", 14),
                                                         CC_CALLBACK_1(HelloWorld::userRegister, this));
    userRegister->setPosition(winSize.width/3 * 1 , winSize.height / 10 * 7);
    auto userRegisterMenu = Menu::create(userRegister, NULL);
    userRegisterMenu->setPosition(Vec2::ZERO);
    this->addChild(userRegisterMenu);
    
    //用户登录事件
    MenuItemLabel *userLogin = MenuItemLabel::create(LabelTTF::create("用户登录事件", "Arial", 14),
                                                        CC_CALLBACK_1(HelloWorld::userLogin, this));
    userLogin->setPosition(winSize.width/3 * 2 , winSize.height / 10 * 7);
    auto userLoginMenu = Menu::create(userLogin, NULL);
    userLoginMenu->setPosition(Vec2::ZERO);
    this->addChild(userLoginMenu);
    
    //用户信息更新事件
    MenuItemLabel *userUpdate = MenuItemLabel::create(LabelTTF::create("用户信息更新事件", "Arial", 14),
                                                        CC_CALLBACK_1(HelloWorld::userUpdate, this));
    userUpdate->setPosition(winSize.width/3 * 1 , winSize.height / 10 * 6);
    auto userUpdateMenu = Menu::create(userUpdate, NULL);
    userUpdateMenu->setPosition(Vec2::ZERO);
    this->addChild(userUpdateMenu);
    
    //角色创建事件
    MenuItemLabel *roleCreate = MenuItemLabel::create(LabelTTF::create("角色创建事件", "Arial", 14),
                                                        CC_CALLBACK_1(HelloWorld::roleCreate, this));
    roleCreate->setPosition(winSize.width/3 * 2 , winSize.height / 10 * 6);
    auto roleCreateMenu = Menu::create(roleCreate, NULL);
    roleCreateMenu->setPosition(Vec2::ZERO);
    this->addChild(roleCreateMenu);
    
    //角色登录事件
    MenuItemLabel *roleLogin = MenuItemLabel::create(LabelTTF::create("角色登录事件", "Arial", 14),
                                                      CC_CALLBACK_1(HelloWorld::roleLogin, this));
    roleLogin->setPosition(winSize.width/3 * 1 , winSize.height / 10 * 5);
    auto roleLoginMenu = Menu::create(roleLogin, NULL);
    roleLoginMenu->setPosition(Vec2::ZERO);
    this->addChild(roleLoginMenu);
    
    //角色信息更新事件
    MenuItemLabel *roleUpdate = MenuItemLabel::create(LabelTTF::create("角色信息更新事件", "Arial", 14),
                                                      CC_CALLBACK_1(HelloWorld::roleUpdate, this));
    roleUpdate->setPosition(winSize.width/3 * 2 , winSize.height / 10 * 5);
    auto roleUpdateMenu = Menu::create(roleUpdate, NULL);
    roleUpdateMenu->setPosition(Vec2::ZERO);
    this->addChild(roleUpdateMenu);
    
    //设置地理位置信息
    MenuItemLabel *setLocation = MenuItemLabel::create(LabelTTF::create("设置地理位置信息", "Arial", 14),
                                                      CC_CALLBACK_1(HelloWorld::setLocation, this));
    setLocation->setPosition(winSize.width/3 * 1 , winSize.height / 10 * 4);
    auto setLocationMenu = Menu::create(setLocation, NULL);
    setLocationMenu->setPosition(Vec2::ZERO);
    this->addChild(setLocationMenu);
    
    return true;
}

void HelloWorld::trackEvent(cocos2d::Ref *pSender)
{
    __Dictionary *eventParams = __Dictionary::create();
    eventParams -> setObject(__String::create("事件参数 Value"), "事件参数 key");

    C2DXAnalySDK::trackEvent("事件名字", eventParams);
}

void HelloWorld::trackPayEvent(cocos2d::Ref *pSender)
{
    PayEvent *payEvent = new PayEvent();
    payEvent->payMoney = 2000;
    payEvent->payContent = "666666";
    //更多字段请参考PayEvent类
    C2DXAnalySDK::trackPayEvent(payEvent);
}

void HelloWorld::userRegister(cocos2d::Ref *pSender)
{
    User *user = new User();
    user->userId = "userId666888";
    user->regType = "regType";
    user->regChannel = "regChannel";
    //更多字段请参考User类
    C2DXAnalySDK::userRegister(user);
}

void HelloWorld::userLogin(cocos2d::Ref *pSender)
{
    User *user = new User();
    user->userId = "userId666888";
    user->regType = "regType";
    user->regChannel = "regChannel";
    //更多字段请参考User类
    C2DXAnalySDK::userLogin(user);
}

void HelloWorld::userUpdate(cocos2d::Ref *pSender)
{
    User *user = new User();
    user->userId = "userId666888";
    user->regType = "regType";
    user->regChannel = "regChannel";
    //更多字段请参考User类
    C2DXAnalySDK::userUpdate(user);
}

void HelloWorld::roleCreate(cocos2d::Ref *pSender)
{
    Role *role = new Role();
    role->userId = "userId666888";
    role->roleId = "roleId666888";
    //更多字段请参考Role类
    C2DXAnalySDK::roleCreate(role);
}

void HelloWorld::roleLogin(cocos2d::Ref *pSender)
{
    Role *role = new Role();
    role->userId = "userId666888";
    role->roleId = "roleId666888";
    //更多字段请参考Role类
    C2DXAnalySDK::roleLogin(role);
}

void HelloWorld::roleUpdate(cocos2d::Ref *pSender)
{
    Role *role = new Role();
    role->userId = "userId666888";
    role->roleId = "roleId666888";
    //更多字段请参考Role类
    C2DXAnalySDK::roleUpdate(role);
}

void HelloWorld::setLocation(cocos2d::Ref *pSender)
{
    C2DXAnalySDK::setLocation(31.27006030476515, 120.70549774169922);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
