//
//  C2DXiOSAnalySDK.m
//  Cocos2DX-For-AnalySDK-mobile
//
//  Created by 刘靖煌 on 2018/1/17.
//

#import "C2DXiOSAnalySDK.h"

#import <Foundation/Foundation.h>
#import <AnalySDK/AnalySDK.h>
#import <CoreLocation/CoreLocation.h>

using namespace mob::analysdk;

#pragma mark - tools

/**
 *    @brief    转换NSDictionary为C2DXDictionary类型
 *
 *    @param     dict     字典
 *
 *    @return    字典类型
 */
C2DXDictionary* convertNSDictToCCDict(NSDictionary *dict);

/**
 *    @brief    转换C2DXDictionary为NSDictionary类型
 *
 *    @param     dict     字典
 *
 *    @return    字典类型
 */
NSMutableDictionary* convertC2DXDictionaryToNSDictionary(C2DXDictionary *Dictionary);

/**
 *    @brief    转换NSString为C2DXString类型
 *
 *    @param     string     字符串
 *
 *    @return    字符类型
 */
C2DXString* convertNSStringToC2DXString(NSString *string);

/**
 *    @brief    转换C2DXString为NSString类型
 *
 *    @param     string     字符串
 *
 *    @return    字符类型
 */
NSString* convertC2DXStringToNSString(C2DXString *String);

/**
 *    @brief    转换NSArray为C2DXArray类型
 *
 *    @param     array     数组
 *
 *    @return    数组类型
 */
C2DXArray* convertNSArrayToC2DXArray(NSArray *array);

/**
 *    @brief    转换C2DXArray为NSArray类型
 *
 *    @param     array     数组
 *
 *    @return    数组类型
 */
NSArray* convertC2DXArrayToNSArray(C2DXArray *Array);

C2DXDictionary* convertNSDictToCCDict(NSDictionary *dict)
{
    if (dict)
    {
        C2DXDictionary *ccDict = C2DXDictionary::create();
        NSArray *allKeys = [dict allKeys];
        for (int i = 0; i < [allKeys count]; i++)
        {
            NSString *key = [allKeys objectAtIndex:i];
            id value = [dict objectForKey:key];
            
            if ([value isKindOfClass:[NSString class]])
            {
                C2DXString *strValue = convertNSStringToC2DXString(value);
                if (strValue)
                {
                    ccDict -> setObject(strValue, [key UTF8String]);
                }
            }
            else if ([value isKindOfClass:[NSNumber class]])
            {
                C2DXString *strValue = convertNSStringToC2DXString([NSString stringWithFormat:@"%@", value]);
                if (strValue)
                {
                    ccDict -> setObject(strValue, [key UTF8String]);
                }
            }
            else if ([value isKindOfClass:[NSDate class]])
            {
                ccDict -> setObject(C2DXDouble::create([value timeIntervalSince1970] * 1000), [key UTF8String]);
            }
            else if ([value isKindOfClass:[NSDictionary class]])
            {
                C2DXDictionary *dictValue = convertNSDictToCCDict(value);
                if (dictValue)
                {
                    ccDict -> setObject(dictValue, [key UTF8String]);
                }
            }
            else if ([value isKindOfClass:[NSArray class]])
            {
                C2DXArray *arrValue = convertNSArrayToC2DXArray(value);
                if (arrValue)
                {
                    ccDict -> setObject(arrValue, [key UTF8String]);
                }
            }
        }
        return ccDict;
    }
    
    return NULL;
}

NSMutableDictionary * convertC2DXDictionaryToNSDictionary(C2DXDictionary * Dictionary)
{
    if (Dictionary)
    {
        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
        C2DXArray *allkeys = Dictionary -> allKeys();
        
        if (allkeys != NULL)
        {
            for (int i = 0; i < allkeys -> count(); i ++)
            {
                C2DXString * key = dynamic_cast<C2DXString *> (allkeys -> C2DXObjectAtIndex(i));
                C2DXObject * value = Dictionary -> objectForKey(key -> getCString());
                
                if (dynamic_cast<C2DXString*>(value) != NULL)
                {
                    NSString *strValue = convertC2DXStringToNSString(dynamic_cast<C2DXString*>(value) );
                    if (strValue)
                    {
                        [dict setObject:strValue
                                 forKey:[NSString stringWithCString:key -> getCString()
                                                           encoding:NSUTF8StringEncoding]];
                    }
                }
                else if (dynamic_cast<C2DXDictionary*>(value) != NULL)
                {
                    NSMutableDictionary *dictValue = convertC2DXDictionaryToNSDictionary(dynamic_cast<C2DXDictionary*>(value));
                    if (dictValue)
                    {
                        [dict setObject:dictValue
                                 forKey:[NSString stringWithCString:key -> getCString()
                                                           encoding:NSUTF8StringEncoding]];
                    }
                }
                else if (dynamic_cast<C2DXArray*>(value) != NULL)
                {
                    NSArray *arrayValue = convertC2DXArrayToNSArray(dynamic_cast<C2DXArray*>(value));
                    if (arrayValue)
                    {
                        [dict setObject:arrayValue
                                 forKey:[NSString stringWithCString:key -> getCString()
                                                           encoding:NSUTF8StringEncoding]];
                    }
                }
            }
        }
        return  dict;
    }
    return NULL;
}

C2DXString* convertNSStringToC2DXString(NSString *string)
{
    if (string)
    {
        return C2DXString::create([string cStringUsingEncoding:NSUTF8StringEncoding]);
    }
    
    return NULL;
}

NSString* convertC2DXStringToNSString(C2DXString *string)
{
    if (string)
    {
        return [NSString stringWithCString:string -> getCString() encoding:NSUTF8StringEncoding];
    }
    return NULL;
}

C2DXArray* convertNSArrayToC2DXArray(NSArray *array)
{
    if (array)
    {
        C2DXArray *ccArray = C2DXArray::create();
        
        for (int i = 0; i < [array count]; i++)
        {
            id value = [array objectAtIndex:i];
            if ([value isKindOfClass:[NSString class]])
            {
                C2DXString *strValue = convertNSStringToC2DXString(value);
                if (strValue)
                {
                    ccArray -> addObject(strValue);
                }
            }
            else if ([value isKindOfClass:[NSNumber class]])
            {
                C2DXString *strValue = convertNSStringToC2DXString([NSString stringWithFormat:@"%@", value]);
                if (strValue)
                {
                    ccArray -> addObject(strValue);
                }
            }
            else if ([value isKindOfClass:[NSDate class]])
            {
                ccArray -> addObject(C2DXDouble::create([value timeIntervalSince1970] * 1000));
            }
            else if ([value isKindOfClass:[NSDictionary class]])
            {
                C2DXDictionary *dictValue = convertNSDictToCCDict(value);
                if (dictValue)
                {
                    ccArray -> addObject(dictValue);
                }
            }
            else if ([value isKindOfClass:[NSArray class]])
            {
                C2DXArray *arrayValue = convertNSArrayToC2DXArray(value);
                if (arrayValue)
                {
                    ccArray -> addObject(arrayValue);
                }
            }
        }
        
        return ccArray;
    }
    
    return NULL;
}

NSArray* convertC2DXArrayToNSArray(C2DXArray *array)
{
    if (array)
    {
        NSMutableArray *nsArray = [NSMutableArray array];
        for (int i = 0; i < array -> count(); i++)
        {
            C2DXObject * value = array -> C2DXObjectAtIndex(i);
            if (dynamic_cast<C2DXString*>(value) != NULL)
            {
                NSString *strValue = convertC2DXStringToNSString(dynamic_cast<C2DXString*>(value) );
                if (strValue)
                {
                    [nsArray addObject:strValue];
                }
            }
            else if (dynamic_cast<C2DXDictionary*>(value) != NULL)
            {
                NSMutableDictionary *dictValue = convertC2DXDictionaryToNSDictionary(dynamic_cast<C2DXDictionary*>(value));
                if (dictValue)
                {
                    [nsArray addObject:dictValue];
                }
            }
            else if (dynamic_cast<C2DXArray*>(value) != NULL)
            {
                NSArray *arrayValue = convertC2DXArrayToNSArray(dynamic_cast<C2DXArray*>(value));
                if (arrayValue)
                {
                    [nsArray addObject:arrayValue];
                }
            }
        }
        return nsArray;
    }
    return NULL;
}

static void trackEvent(const char *eventName, C2DXDictionary *eventParams){}

static void trackPayEvent(PayEvent *payEvent)
{
    ALSDKPayEvent *event = [[ALSDKPayEvent alloc] init];
    
    int payMoney = payEvent->payMoney;
    if (payMoney > 0)
    {
        event.payMoney = payMoney;
    }
    
    const char *payContentChar = payEvent->payContent->c_str();
    NSString *payContent = convertC2DXStringToNSString(C2DXString::create(payContentChar));
    if (payEvent)
    {
        event.payContent = payContent;
    }
    
    const char *payTypeChar = payEvent->payType->c_str();
    NSString *payType = convertC2DXStringToNSString(C2DXString::create(payTypeChar));
    if (payType)
    {
        event.payType = payType;
    }
    
    const char *payActivityChar = payEvent->payType->c_str();
    NSString *payActivity = convertC2DXStringToNSString(C2DXString::create(payActivityChar));
    if (payActivity)
    {
        event.payActivity = payActivity;
    }
    
    double payDiscount = payEvent->payDiscount;
    if (payDiscount > 0)
    {
        event.payDiscount = @(payDiscount);
    }
    
    const char *discountReasonChar = payEvent->payType->c_str();
    NSString *discountReason = convertC2DXStringToNSString(C2DXString::create(discountReasonChar));
    if (discountReason)
    {
        event.discountReason = discountReason;
    }
    
    C2DXDictionary *customPro = payEvent->customProperties;
    if(customPro)
    {
        NSMutableDictionary *customProperties = [NSMutableDictionary dictionary];
        customProperties = convertC2DXDictionaryToNSDictionary(customPro);
        event.customProperties = [NSDictionary dictionaryWithDictionary:customProperties];
    }
    
    [AnalySDK trackPayEvent:event];
    
}

static void userRegister(User *user)
{
    ALSDKUser *userModel = [[ALSDKUser alloc] init];
    
    const char *userIdChar = user->userId->c_str();
    NSString *userId = convertC2DXStringToNSString(C2DXString::create(userIdChar));
    if (userId)
    {
        userModel.userId = userId;
    }
    
    const char *nickNameChar = user->nickName->c_str();
    NSString *nickName = convertC2DXStringToNSString(C2DXString::create(nickNameChar));
    if (nickName)
    {
        userModel.nickName = nickName;
    }
    
    const char *genderChar = user->gender->c_str();
    NSString *gender = convertC2DXStringToNSString(C2DXString::create(genderChar));
    if (gender)
    {
        userModel.gender = gender;
    }
    
    const char *countryChar = user->country->c_str();
    NSString *country = convertC2DXStringToNSString(C2DXString::create(countryChar));
    if (country)
    {
        userModel.country = country;
    }
    
    const char *provinceChar = user->province->c_str();
    NSString *province = convertC2DXStringToNSString(C2DXString::create(provinceChar));
    if (province)
    {
        userModel.province = province;
    }
    
    const char *cityChar = user->city->c_str();
    NSString *city = convertC2DXStringToNSString(C2DXString::create(cityChar));
    if (city)
    {
        userModel.city = city;
    }
    
    int age = user->age;
    if (age > 0)
    {
        userModel.age = @(age);
    }
    
    const char *constellationChar = user->constellation->c_str();
    NSString *constellation = convertC2DXStringToNSString(C2DXString::create(constellationChar));
    if (constellation)
    {
        userModel.constellation = constellation;
    }
    
    const char *zodiacChar = user->zodiac->c_str();
    NSString *zodiac = convertC2DXStringToNSString(C2DXString::create(zodiacChar));
    if (zodiac)
    {
        userModel.zodiac = zodiac;
    }
    
    const char *regTypeChar = user->regType->c_str();
    NSString *regType = convertC2DXStringToNSString(C2DXString::create(regTypeChar));
    if (regType)
    {
        userModel.regType = regType;
    }
    
    const char *regChannelChar = user->regChannel->c_str();
    NSString *regChannel = convertC2DXStringToNSString(C2DXString::create(regChannelChar));
    if (regChannel)
    {
        userModel.regChannel = regChannel;
    }
    
    const char *loginTypeChar = user->loginType->c_str();
    NSString *loginType = convertC2DXStringToNSString(C2DXString::create(loginTypeChar));
    if (loginType)
    {
        userModel.loginType = loginType;
    }
    
    const char *loginChannelChar = user->loginChannel->c_str();
    NSString *loginChannel = convertC2DXStringToNSString(C2DXString::create(loginChannelChar));
    if (loginChannel)
    {
        userModel.loginChannel = loginChannel;
    }
    
    const char *userTypeChar = user->userType->c_str();
    NSString *userType = convertC2DXStringToNSString(C2DXString::create(userTypeChar));
    if (userType)
    {
        userModel.userType = userType;
    }
    
    const char *addictionChar = user->addiction->c_str();
    NSString *addiction = convertC2DXStringToNSString(C2DXString::create(addictionChar));
    if (addiction)
    {
        userModel.addiction = addiction;
    }
    
    double money = user->money;
    if (money > 0)
    {
        userModel.money = @(money);
    }
    
    C2DXDictionary *customPro = user->customProperties;
    if(customPro)
    {
        NSMutableDictionary *customProperties = [NSMutableDictionary dictionary];
        customProperties = convertC2DXDictionaryToNSDictionary(customPro);
        userModel.customProperties = [NSDictionary dictionaryWithDictionary:customProperties];
    }
    
    [AnalySDK userRegist:userModel];
}

static void userUpdate(User *user)
{
    ALSDKUser *userModel = [[ALSDKUser alloc] init];
    
    const char *userIdChar = user->userId->c_str();
    NSString *userId = convertC2DXStringToNSString(C2DXString::create(userIdChar));
    if (userId)
    {
        userModel.userId = userId;
    }
    
    const char *nickNameChar = user->nickName->c_str();
    NSString *nickName = convertC2DXStringToNSString(C2DXString::create(nickNameChar));
    if (nickName)
    {
        userModel.nickName = nickName;
    }
    
    const char *genderChar = user->gender->c_str();
    NSString *gender = convertC2DXStringToNSString(C2DXString::create(genderChar));
    if (gender)
    {
        userModel.gender = gender;
    }
    
    const char *countryChar = user->country->c_str();
    NSString *country = convertC2DXStringToNSString(C2DXString::create(countryChar));
    if (country)
    {
        userModel.country = country;
    }
    
    const char *provinceChar = user->province->c_str();
    NSString *province = convertC2DXStringToNSString(C2DXString::create(provinceChar));
    if (province)
    {
        userModel.province = province;
    }
    
    const char *cityChar = user->city->c_str();
    NSString *city = convertC2DXStringToNSString(C2DXString::create(cityChar));
    if (city)
    {
        userModel.city = city;
    }
    
    int age = user->age;
    if (age > 0)
    {
        userModel.age = @(age);
    }
    
    const char *constellationChar = user->constellation->c_str();
    NSString *constellation = convertC2DXStringToNSString(C2DXString::create(constellationChar));
    if (constellation)
    {
        userModel.constellation = constellation;
    }
    
    const char *zodiacChar = user->zodiac->c_str();
    NSString *zodiac = convertC2DXStringToNSString(C2DXString::create(zodiacChar));
    if (zodiac)
    {
        userModel.zodiac = zodiac;
    }
    
    const char *regTypeChar = user->regType->c_str();
    NSString *regType = convertC2DXStringToNSString(C2DXString::create(regTypeChar));
    if (regType)
    {
        userModel.regType = regType;
    }
    
    const char *regChannelChar = user->regChannel->c_str();
    NSString *regChannel = convertC2DXStringToNSString(C2DXString::create(regChannelChar));
    if (regChannel)
    {
        userModel.regChannel = regChannel;
    }
    
    const char *loginTypeChar = user->loginType->c_str();
    NSString *loginType = convertC2DXStringToNSString(C2DXString::create(loginTypeChar));
    if (loginType)
    {
        userModel.loginType = loginType;
    }
    
    const char *loginChannelChar = user->loginChannel->c_str();
    NSString *loginChannel = convertC2DXStringToNSString(C2DXString::create(loginChannelChar));
    if (loginChannel)
    {
        userModel.loginChannel = loginChannel;
    }
    
    const char *userTypeChar = user->userType->c_str();
    NSString *userType = convertC2DXStringToNSString(C2DXString::create(userTypeChar));
    if (userType)
    {
        userModel.userType = userType;
    }
    
    const char *addictionChar = user->addiction->c_str();
    NSString *addiction = convertC2DXStringToNSString(C2DXString::create(addictionChar));
    if (addiction)
    {
        userModel.addiction = addiction;
    }
    
    double money = user->money;
    if (money > 0)
    {
        userModel.money = @(money);
    }
    
    C2DXDictionary *customPro = user->customProperties;
    if(customPro)
    {
        NSMutableDictionary *customProperties = [NSMutableDictionary dictionary];
        customProperties = convertC2DXDictionaryToNSDictionary(customPro);
        userModel.customProperties = [NSDictionary dictionaryWithDictionary:customProperties];
    }
    
    [AnalySDK userUpdate:userModel];
}

static void roleCreate(Role *role)
{
    ALSDKRole *model = [[ALSDKRole alloc] init];
    
    const char *userIdChar = role->userId->c_str();
    NSString *userId = convertC2DXStringToNSString(C2DXString::create(userIdChar));
    if (userId)
    {
        model.userId = userId;
    }
    
    const char *roleIdChar = role->roleId->c_str();
    NSString *roleId = convertC2DXStringToNSString(C2DXString::create(roleIdChar));
    if (roleId)
    {
        model.roleId = roleId;
    }
    
    const char *roServerChar = role->roServer->c_str();
    NSString *roServer = convertC2DXStringToNSString(C2DXString::create(roServerChar));
    if (roServer)
    {
        model.roServer = roServer;
    }
    
    const char *roNameChar = role->roName->c_str();
    NSString *roName = convertC2DXStringToNSString(C2DXString::create(roNameChar));
    if (roName)
    {
        model.roName = roName;
    }
    
    const char *roCareerChar = role->roleId->c_str();
    NSString *roCareer = convertC2DXStringToNSString(C2DXString::create(roCareerChar));
    if (roCareer)
    {
        model.roCareer = roCareer;
    }
    
    double roLevel = role->roLevel;
    if (roLevel > 0)
    {
        model.roLevel = @(roLevel);
    }
    
    const char *roVipChar = role->roVip->c_str();
    NSString *roVip = convertC2DXStringToNSString(C2DXString::create(roVipChar));
    if (roVip)
    {
        model.roVip = roVip;
    }
    
    const char *roRankLevelChar = role->roRankLevel->c_str();
    NSString *roRankLevel = convertC2DXStringToNSString(C2DXString::create(roRankLevelChar));
    if (roRankLevel)
    {
        model.roRankLevel = roRankLevel;
    }
    
    double roEnergy = role->roEnergy;
    if (roEnergy > 0)
    {
        model.roEnergy = @(roEnergy);
    }
    
    double roMoney = role->roMoney;
    if (roMoney > 0)
    {
        model.roMoney = @(roMoney);
    }
    
    double roCoin = role->roCoin;
    if (roCoin > 0)
    {
        model.roCoin = @(roCoin);
    }
    
    double roSource1 = role->roSource1;
    if (roSource1 > 0)
    {
        model.roSource1 = @(roSource1);
    }
    
    double roSource2 = role->roSource2;
    if (roSource2 > 0)
    {
        model.roSource2 = @(roSource2);
    }
    
    double roSource3 = role->roSource3;
    if (roSource3 > 0)
    {
        model.roSource3 = @(roSource3);
    }
    
    double roSource4 = role->roSource4;
    if (roSource4 > 0)
    {
        model.roSource4 = @(roSource4);
    }
    
    C2DXDictionary *customPro = role->customProperties;
    if(customPro)
    {
        NSMutableDictionary *customProperties = [NSMutableDictionary dictionary];
        customProperties = convertC2DXDictionaryToNSDictionary(customPro);
        model.customProperties = [NSDictionary dictionaryWithDictionary:customProperties];
    }
    
    [AnalySDK roleCreate:model];
}

static void roleLogin(Role *role)
{
    ALSDKRole *model = [[ALSDKRole alloc] init];
    
    const char *userIdChar = role->userId->c_str();
    NSString *userId = convertC2DXStringToNSString(C2DXString::create(userIdChar));
    if (userId)
    {
        model.userId = userId;
    }
    
    const char *roleIdChar = role->roleId->c_str();
    NSString *roleId = convertC2DXStringToNSString(C2DXString::create(roleIdChar));
    if (roleId)
    {
        model.roleId = roleId;
    }
    
    const char *roServerChar = role->roServer->c_str();
    NSString *roServer = convertC2DXStringToNSString(C2DXString::create(roServerChar));
    if (roServer)
    {
        model.roServer = roServer;
    }
    
    const char *roNameChar = role->roName->c_str();
    NSString *roName = convertC2DXStringToNSString(C2DXString::create(roNameChar));
    if (roName)
    {
        model.roName = roName;
    }
    
    const char *roCareerChar = role->roleId->c_str();
    NSString *roCareer = convertC2DXStringToNSString(C2DXString::create(roCareerChar));
    if (roCareer)
    {
        model.roCareer = roCareer;
    }
    
    double roLevel = role->roLevel;
    if (roLevel > 0)
    {
        model.roLevel = @(roLevel);
    }
    
    const char *roVipChar = role->roVip->c_str();
    NSString *roVip = convertC2DXStringToNSString(C2DXString::create(roVipChar));
    if (roVip)
    {
        model.roVip = roVip;
    }
    
    const char *roRankLevelChar = role->roRankLevel->c_str();
    NSString *roRankLevel = convertC2DXStringToNSString(C2DXString::create(roRankLevelChar));
    if (roRankLevel)
    {
        model.roRankLevel = roRankLevel;
    }
    
    double roEnergy = role->roEnergy;
    if (roEnergy > 0)
    {
        model.roEnergy = @(roEnergy);
    }
    
    double roMoney = role->roMoney;
    if (roMoney > 0)
    {
        model.roMoney = @(roMoney);
    }
    
    double roCoin = role->roCoin;
    if (roCoin > 0)
    {
        model.roCoin = @(roCoin);
    }
    
    double roSource1 = role->roSource1;
    if (roSource1 > 0)
    {
        model.roSource1 = @(roSource1);
    }
    
    double roSource2 = role->roSource2;
    if (roSource2 > 0)
    {
        model.roSource2 = @(roSource2);
    }
    
    double roSource3 = role->roSource3;
    if (roSource3 > 0)
    {
        model.roSource3 = @(roSource3);
    }
    
    double roSource4 = role->roSource4;
    if (roSource4 > 0)
    {
        model.roSource4 = @(roSource4);
    }
    
    C2DXDictionary *customPro = role->customProperties;
    if(customPro)
    {
        NSMutableDictionary *customProperties = [NSMutableDictionary dictionary];
        customProperties = convertC2DXDictionaryToNSDictionary(customPro);
        model.customProperties = [NSDictionary dictionaryWithDictionary:customProperties];
    }
    
    [AnalySDK roleLogin:model];
}

static void roleUpdate(Role *role)
{
    ALSDKRole *model = [[ALSDKRole alloc] init];
    
    const char *userIdChar = role->userId->c_str();
    NSString *userId = convertC2DXStringToNSString(C2DXString::create(userIdChar));
    if (userId)
    {
        model.userId = userId;
    }
    
    const char *roleIdChar = role->roleId->c_str();
    NSString *roleId = convertC2DXStringToNSString(C2DXString::create(roleIdChar));
    if (roleId)
    {
        model.roleId = roleId;
    }
    
    const char *roServerChar = role->roServer->c_str();
    NSString *roServer = convertC2DXStringToNSString(C2DXString::create(roServerChar));
    if (roServer)
    {
        model.roServer = roServer;
    }
    
    const char *roNameChar = role->roName->c_str();
    NSString *roName = convertC2DXStringToNSString(C2DXString::create(roNameChar));
    if (roName)
    {
        model.roName = roName;
    }
    
    const char *roCareerChar = role->roleId->c_str();
    NSString *roCareer = convertC2DXStringToNSString(C2DXString::create(roCareerChar));
    if (roCareer)
    {
        model.roCareer = roCareer;
    }
    
    double roLevel = role->roLevel;
    if (roLevel > 0)
    {
        model.roLevel = @(roLevel);
    }
    
    const char *roVipChar = role->roVip->c_str();
    NSString *roVip = convertC2DXStringToNSString(C2DXString::create(roVipChar));
    if (roVip)
    {
        model.roVip = roVip;
    }
    
    const char *roRankLevelChar = role->roRankLevel->c_str();
    NSString *roRankLevel = convertC2DXStringToNSString(C2DXString::create(roRankLevelChar));
    if (roRankLevel)
    {
        model.roRankLevel = roRankLevel;
    }
    
    double roEnergy = role->roEnergy;
    if (roEnergy > 0)
    {
        model.roEnergy = @(roEnergy);
    }
    
    double roMoney = role->roMoney;
    if (roMoney > 0)
    {
        model.roMoney = @(roMoney);
    }
    
    double roCoin = role->roCoin;
    if (roCoin > 0)
    {
        model.roCoin = @(roCoin);
    }
    
    double roSource1 = role->roSource1;
    if (roSource1 > 0)
    {
        model.roSource1 = @(roSource1);
    }
    
    double roSource2 = role->roSource2;
    if (roSource2 > 0)
    {
        model.roSource2 = @(roSource2);
    }
    
    double roSource3 = role->roSource3;
    if (roSource3 > 0)
    {
        model.roSource3 = @(roSource3);
    }
    
    double roSource4 = role->roSource4;
    if (roSource4 > 0)
    {
        model.roSource4 = @(roSource4);
    }
    
    C2DXDictionary *customPro = role->customProperties;
    if(customPro)
    {
        NSMutableDictionary *customProperties = [NSMutableDictionary dictionary];
        customProperties = convertC2DXDictionaryToNSDictionary(customPro);
        model.customProperties = [NSDictionary dictionaryWithDictionary:customProperties];
    }
    
    [AnalySDK roleUpdate:model];
}

static void setLocation(double latitude, double longitude)
{
    CLLocation *location = [[CLLocation alloc] initWithLatitude:latitude longitude:longitude];
    [AnalySDK setLocation:location];
}

