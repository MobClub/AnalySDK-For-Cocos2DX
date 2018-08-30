//
// Created by yjin on 2018/1/30.
//
#include "C2DXAndroidAnalySDK.h"


using namespace mob::analysdk;

void C2DXAndroidAnalySDK::setLocation(C2DXDouble longitude, C2DXDouble latitude) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "setLocation", "(DD)V");
    double longi = longitude.getValue();
    double lati = latitude.getValue();
    env->CallStaticVoidMethod(jApiClazz, jApiMethod, longi, lati);
}

void C2DXAndroidAnalySDK::trackEvent(const char *eventName, C2DXDictionary *dictionary) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "trackEvent", "(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jInfo = NULL;
    jstring event = NULL;
    if (dictionary != NULL) {
        CCJSONConverter *json = CCJSONConverter::sharedConverter();
        const char *ccInfo = json->strFrom(dictionary);
        jInfo = env->NewStringUTF(ccInfo);
    }
    event = env->NewStringUTF(eventName);
    env->CallStaticVoidMethod(jApiClazz, jApiMethod, event, jInfo);
}

void C2DXAndroidAnalySDK::trackPayEvent(PayEvent *payEvent) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "trackPayEvent", "(Ljava/lang/String;)V");
    std::string str = payEvent->toString();
    jstring jInfo = NULL;
    if (!str.empty()) {
        jInfo = env->NewStringUTF(str.c_str());
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod, jInfo);
}

void C2DXAndroidAnalySDK::userRegist(User *userevent) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiRegistMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "userRegist",
                                                                    "(Ljava/lang/String;)V");
    std::string str = userevent->toString();
    jstring jInfo = NULL;
    if (!str.empty()) {
        jInfo = env->NewStringUTF(str.c_str());
    }
    env->CallStaticVoidMethod(jApiClazz, jApiRegistMethod, jInfo);
}

void C2DXAndroidAnalySDK::userLogin(User *userevent) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "userLogin",
                                                                 "(Ljava/lang/String;)V");
    std::string str = userevent->toString();
    jstring jInfo = NULL;
    if (!str.empty()) {
        jInfo = env->NewStringUTF(str.c_str());
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod, jInfo);
}

void C2DXAndroidAnalySDK::userUpdate(User *userEvent) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "userUpdate",
                                                                 "(Ljava/lang/String;)V");
    std::string str = userEvent->toString();
    jstring jInfo = NULL;
    if (!str.empty()) {
        jInfo = env->NewStringUTF(str.c_str());
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod, jInfo);
}

void C2DXAndroidAnalySDK::roleCreate(Role *roleEvent) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "roleCreate",
                                                                 "(Ljava/lang/String;)V");
    std::string str = roleEvent->toString();
    jstring jInfo = NULL;
    if (!str.empty()) {
        jInfo = env->NewStringUTF(str.c_str());
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod, jInfo);
}

void C2DXAndroidAnalySDK::roleLogin(Role *roleEvent) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "roleLogin",
                                                                 "(Ljava/lang/String;)V");
    std::string str = roleEvent->toString();
    jstring jInfo = NULL;
    if (!str.empty()) {
        jInfo = env->NewStringUTF(str.c_str());
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod, jInfo);
}

void C2DXAndroidAnalySDK::roleUpdate(Role *roleEvent) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiPayMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "roleUpdate",
                                                                 "(Ljava/lang/String;)V");
    std::string str = roleEvent->toString();
    jstring jInfo = NULL;
    if (!str.empty()) {
        jInfo = env->NewStringUTF(str.c_str());
    }
    env->CallStaticVoidMethod(jApiClazz, jApiPayMethod, jInfo);
}

void C2DXAndroidAnalySDK::behaviorStart(const char *eventName, C2DXDictionary *dictionary) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "behaviorStart", "(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jInfo = NULL;
    jstring event = NULL;
    if (dictionary != NULL) {
        CCJSONConverter *json = CCJSONConverter::sharedConverter();
        const char *ccInfo = json->strFrom(dictionary);
        jInfo = env->NewStringUTF(ccInfo);
    }
    event = env->NewStringUTF(eventName);
    env->CallStaticVoidMethod(jApiClazz, jApiMethod, event, jInfo);
}

void C2DXAndroidAnalySDK::behaviorEnd(const char *eventName, C2DXDictionary *dictionary) {
    JvmJniEnv env;
    jclass jApiClazz = env->FindClass("com/mob/game/CoCosAPI");
    jmethodID jApiMethod = C2DXCxxJavaObject::getJavaMethodID(env, jApiClazz, "behaviorEnd", "(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jInfo = NULL;
    jstring event = NULL;
    if (dictionary != NULL) {
        CCJSONConverter *json = CCJSONConverter::sharedConverter();
        const char *ccInfo = json->strFrom(dictionary);
        jInfo = env->NewStringUTF(ccInfo);
    }
    event = env->NewStringUTF(eventName);
    env->CallStaticVoidMethod(jApiClazz, jApiMethod, event, jInfo);
}

jstring C2DXAndroidAnalySDK::charTojstring(JvmJniEnv env, const char *pat) {
    //定义java String类 strClass
    jclass strClass = env->FindClass("java/lang/String");
    //获取String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    //建立byte数组
    jbyteArray bytes = (env)->NewByteArray(strlen(pat));
    //将char* 转换为byte数组
    (env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte *) pat);
    // 设置String, 保存语言类型,用于byte数组转换至String时的参数
    jstring encoding = (env)->NewStringUTF("GB2312");
    //将byte数组转换为java String,并输出

    jstring res = (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
    return res;
}
