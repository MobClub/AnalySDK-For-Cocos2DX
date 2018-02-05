//
// Created by yjin on 2018/1/30.
//
#include "C2DXAndroidAnalySDK.h"
#include "JvmJniEnv.h"
#include "C2DXCxxJavaObject.h"


 void C2DXAndroidAnalySDK::setLocation(double longitude,double latitude)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiMethod = getJavaMethodID(env,jApiClazz,"setLocation","(DD)V");

    env->CallStaticVoidMethod(jApi, jApiMethod,longitude,latitude);
 }

 void C2DXAndroidAnalySDK::trackEvent(const char* eventName ,C2DXDictionary* dictionary)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiMethod = getJavaMethodID(env,jApiClazz,"trackEvent","(Ljava/lang/String;Ljava/lang/String;)V");

    jstring jInfo = NULL;
    jstring eventName = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
 	}
 	eventName = env->NewStringUTF(eventName);
 	env->CallStaticVoidMethod(jApi, jApiMethod,eventName,jInfo);
 }

 void C2DXAndroidAnalySDK::trackPayEvent(PayEvent* payEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "trackPayEvent",
            "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = payEvent->toHashMap();
    jstring jInfo = NULL;
     if (dictionary != NULL) {
            CCJSONConverter* json = CCJSONConverter::sharedConverter();
            const char* ccInfo = json->strFrom(dictionary);
            jInfo =env->NewStringUTF(ccInfo);
     	}
    env->env->CallStaticVoidMethod(jApi, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::userRegist(UserEvent* userevent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "userRegist",
                "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = userevent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->env->CallStaticVoidMethod(jApi, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::userLogin(UserEvent* userevent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "userLogin",
                    "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = userevent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
         CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->env->CallStaticVoidMethod(jApi, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::userUpdate(UserEvent* userEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "userUpdate",
                        "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = userEvent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->CallStaticVoidMethod(jApi, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::roleCreate(RoleEvent* roleEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "roleCreate",
                            "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = roleEvent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->CallStaticVoidMethod(jApi, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::roleLogin(RoleEvent* roleEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "roleLogin",
                                "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = roleEvent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->CallStaticVoidMethod(jApi, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::roleUpdate(RoleEvent* roleEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "roleUpdate",
                                    "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = roleEvent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
         CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->CallStaticVoidMethod(jApi, jApiPayMethod,jInfo);
 }

