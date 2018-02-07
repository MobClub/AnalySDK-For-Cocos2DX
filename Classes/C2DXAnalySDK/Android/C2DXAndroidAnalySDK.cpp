//
// Created by yjin on 2018/1/30.
//
#include "C2DXAndroidAnalySDK.h"

using namespace cn::analysdk;

void C2DXAndroidAnalySDK::setLocation(C2DXDouble longitude,C2DXDouble latitude)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiMethod = C2DXCxxJavaObject::getJavaMethodID(env,jApiClazz,"setLocation","(DD)V");
    double longi = longitude.getValue();
     double lati = latitude.getValue();
    env->CallStaticVoidMethod(jApiClazz, jApiMethod,longi,lati);
 }

void C2DXAndroidAnalySDK::trackEvent(const char* eventName ,C2DXDictionary* dictionary)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiMethod = C2DXCxxJavaObject::getJavaMethodID(env,jApiClazz,"trackEvent","(Ljava/lang/String;Ljava/lang/String;)V");

    jstring jInfo = NULL;
    jstring event = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
 	}
 	event = env->NewStringUTF(eventName);
 	env->CallStaticVoidMethod(jApiClazz, jApiMethod,event,jInfo);
 }

void C2DXAndroidAnalySDK::trackPayEvent(PayEvent* payEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "trackPayEvent",
            "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = payEvent->toHashMap();
    jstring jInfo = NULL;
     if (dictionary != NULL) {
            CCJSONConverter* json = CCJSONConverter::sharedConverter();
            const char* ccInfo = json->strFrom(dictionary);
            jInfo =env->NewStringUTF(ccInfo);
     	}
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::userRegist(UserEvent* userevent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "userRegist",
                "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = userevent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
     env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::userLogin(UserEvent* userevent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "userLogin",
                    "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = userevent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
         CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::userUpdate(UserEvent* userEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "userUpdate",
                        "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = userEvent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::roleCreate(RoleEvent* roleEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "roleCreate",
                            "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = roleEvent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::roleLogin(RoleEvent* roleEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "roleLogin",
                                "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = roleEvent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
        CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::roleUpdate(RoleEvent* roleEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "roleUpdate",
                                    "(Ljava/lang/String;)V");
    C2DXDictionary* dictionary = roleEvent->toHashMap();
    jstring jInfo = NULL;
    if (dictionary != NULL) {
         CCJSONConverter* json = CCJSONConverter::sharedConverter();
        const char* ccInfo = json->strFrom(dictionary);
        jInfo =env->NewStringUTF(ccInfo);
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

