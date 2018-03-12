LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../../Classes/AppDelegate.cpp \
                   ../../../Classes/HelloWorldScene.cpp \
                   ../../../Classes/C2DXAnalySDK/PayEvent.cpp \
                   ../../../Classes/C2DXAnalySDK/C2DXAnalySDK.cpp \
                   ../../../Classes/C2DXAnalySDK/Role.cpp \
                   ../../../Classes/C2DXAnalySDK/User.cpp \
                   ../../../Classes/C2DXAnalySDK/iOS/C2DXiOSAnalySDK.mm \
                   ../../../Classes/C2DXAnalySDK/Android/C2DXAndroidAnalySDK.cpp \
                   ../../../Classes/C2DXAnalySDK/Android/C2DXCxxJavaObject.cpp \
                   ../../../Classes/C2DXAnalySDK/Android/JSON/CCJSONConverter.cpp \
                   ../../../Classes/C2DXAnalySDK/Android/JSON/cJSON/cJSON.c

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes \
                    $(LOCAL_PATH)/../../../Classes/C2DXAnalySDK \
                    $(LOCAL_PATH)/../../../Classes/C2DXAnalySDK/Android \
                    $(LOCAL_PATH)/../../../Classes/C2DXAnalySDK/Android/JSON \
                    $(LOCAL_PATH)/../../../Classes/C2DXAnalySDK/Android/JSON/cJSON


# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END


LOCAL_LDLIBS:=  -llog
LOCAL_SHARED_LIBRARIES := liblog libcutils
