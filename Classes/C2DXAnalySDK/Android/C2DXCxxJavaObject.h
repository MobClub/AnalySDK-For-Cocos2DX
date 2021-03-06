#ifndef __C2DXPAYSDKBRIDGE__C2DXCXXJAVAOBJECT__
#define __C2DXPAYSDKBRIDGE__C2DXCXXJAVAOBJECT__

#include "JvmJniEnv.h"
#include <iostream>
#include "map"

using namespace std;
namespace mob
{
    namespace analysdk
    {
        class C2DXCxxJavaObject {
        protected:
            C2DXCxxJavaObject();
        public:
            /**
             * 附加javaObject对象到this对象
             * @param lRef javaObject的引用
             */
            void attachJavaObject(JNIEnv* env, jobject lRef);

            /**
             * 移除javaObject对象从this对象
             * @param lRef 与attachJavaObject保持一致, 并无含义
             */
            void detachJavaObject(JNIEnv* env, jobject lRef);

            /**
             * 获取附加到this对象上的javaObject的全局引用
             * @return javaObject的全局引用
             */
            jobject getJavaObject();

            /**
             * 获取附加到this对象上的javaObject的本地引用
             * @return javaObject的本地引用
             */
            jobject getLocalJavaObject(JNIEnv* env);
            static jobject newJavaInstance(JNIEnv* env, const char* clazz);
            static jclass getJavaClass(JNIEnv* env, jobject jo);
            static jmethodID getJavaMethodID(JNIEnv*, jclass, const char*, const char*);
            /**
             * 释放此对象
             */
            virtual void release();

        protected:

            /**
             * 从映射表中找到java对象对应的cxx对象
             * @param env
             * @return
             */
            static C2DXCxxJavaObject* findCxxJavaObject(JNIEnv* env, jobject);
        public:
            virtual ~C2DXCxxJavaObject();
        };

        static map<C2DXCxxJavaObject*, jobject> cxxJavaMap;
    }
}

#endif
