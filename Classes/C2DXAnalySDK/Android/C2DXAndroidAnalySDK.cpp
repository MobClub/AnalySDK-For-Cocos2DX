//
// Created by yjin on 2018/1/30.
//
#include "C2DXAndroidAnalySDK.h"

using namespace mob::analysdk;

void C2DXAndroidAnalySDK::setLocation(double latitude, double longitude)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiMethod = C2DXCxxJavaObject::getJavaMethodID(env,jApiClazz,"setLocation","(DD)V");

    env->CallStaticVoidMethod(jApiClazz, jApiMethod,longitude,latitude);
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
    string jInfo = payEvent->toString();

//     CCJSONConverter* json = CCJSONConverter::sharedConverter();
//     json->
////     cJSON* cJson = json->getObjJson(payEvent);
////     char * ccInfo = cJson->string;
//      jInfo = env->NewStringUTF(ccInfo);

    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::userRegist(User* userevent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "userRegist",
                "(Ljava/lang/String;)V");
    string jInfo = userevent->toString();
//    jstring jInfo = NULL;
//    if (dictionary != NULL) {
//        CCJSONConverter* json = CCJSONConverter::sharedConverter();
//        const char* ccInfo = json->strFrom(dictionary);
//        jInfo =env->NewStringUTF(ccInfo);
//    }
     env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::userLogin(User* userevent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "userLogin",
                    "(Ljava/lang/String;)V");
    string jInfo = userevent->toString();
//    jstring jInfo = NULL;
//    if (dictionary != NULL) {
//         CCJSONConverter* json = CCJSONConverter::sharedConverter();
//        const char* ccInfo = json->strFrom(dictionary);
//        jInfo =env->NewStringUTF(ccInfo);
//    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::userUpdate(User* userEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "userUpdate",
                        "(Ljava/lang/String;)V");
    string jInfo = userEvent->toString();
//    jstring jInfo = NULL;
//    if (dictionary != NULL) {
//        CCJSONConverter* json = CCJSONConverter::sharedConverter();
//        const char* ccInfo = json->strFrom(dictionary);
//        jInfo =env->NewStringUTF(ccInfo);
//    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::roleCreate(Role* roleEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "roleCreate",
                            "(Ljava/lang/String;)V");
    string jInfo = roleEvent->toString();
//    jstring jInfo = NULL;
//    if (dictionary != NULL) {
//        CCJSONConverter* json = CCJSONConverter::sharedConverter();
//        const char* ccInfo = json->strFrom(dictionary);
//        jInfo =env->NewStringUTF(ccInfo);
//    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::roleLogin(Role* roleEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "roleLogin",
                                "(Ljava/lang/String;)V");
    string jInfo = roleEvent->toString();
//    jstring jInfo = NULL;
//    if (dictionary != NULL) {
//        CCJSONConverter* json = CCJSONConverter::sharedConverter();
//        const char* ccInfo = json->strFrom(dictionary);
//        jInfo =env->NewStringUTF(ccInfo);
//    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

 void C2DXAndroidAnalySDK::roleUpdate(Role* roleEvent)
 {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/analysdk/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "roleUpdate",
                                    "(Ljava/lang/String;)V");

    string jInfo = roleEvent->toString();
//    if (dictionary != NULL) {
//         CCJSONConverter* json = CCJSONConverter::sharedConverter();
//        const char* ccInfo = json->strFrom(dictionary);
//        jInfo =env->NewStringUTF(ccInfo);
//    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod,jInfo);
 }

