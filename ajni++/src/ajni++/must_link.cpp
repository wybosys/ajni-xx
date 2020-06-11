#include <ajni++/ajni++.hpp>

USE_AJNI

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1grab)(JNIEnv *env, jobject thiz, jlong fnidx) {
    Env.context().function_grab(fnidx);
    return nullptr;
}

AJNI_API(jboolean) AJNI_FUNC(Callback, jni_1drop)(JNIEnv *env, jobject thiz, jlong fnidx) {
    return Env.context().function_drop(fnidx);
}

#define _AJNI_CALLBACK_IMPL_BEGIN \
    auto &ctx = Env.context(); \
    auto fn = ctx.find_function(fnidx); \
    if (!fn) { \
        Logger::Error("没有找到回调函数"); \
        return 0; \
    }

#define _AJNI_CALLBACK_IMPL_END return 0;
// ctx.function_drop(fnidx); value释放时，会自动调用drop

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke)(JNIEnv *env, jobject thiz, jlong fnidx) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)();
    _AJNI_CALLBACK_IMPL_END
}

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke1)(JNIEnv *env, jobject thiz, jlong fnidx,
                                                 jobject v0) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)(*JObject(v0).toVariant());
    _AJNI_CALLBACK_IMPL_END
}

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke2)(JNIEnv *env, jobject thiz, jlong fnidx, jobject v0,
                                                 jobject v1) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)(*JObject(v0).toVariant(), *JObject(v1).toVariant());
    _AJNI_CALLBACK_IMPL_END
}

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke3)(JNIEnv *env, jobject thiz, jlong fnidx, jobject v0,
                                                 jobject v1, jobject v2) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)(*JObject(v0).toVariant(), *JObject(v1).toVariant(), *JObject(v2).toVariant());
    _AJNI_CALLBACK_IMPL_END
}

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke4)(JNIEnv *env, jobject thiz, jlong fnidx, jobject v0,
                                                 jobject v1, jobject v2, jobject v3) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)(*JObject(v0).toVariant(), *JObject(v1).toVariant(), *JObject(v2).toVariant(),
          *JObject(v3).toVariant());
    _AJNI_CALLBACK_IMPL_END
}

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke5)(JNIEnv *env, jobject thiz, jlong fnidx, jobject v0,
                                                 jobject v1, jobject v2, jobject v3, jobject v4) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)(*JObject(v0).toVariant(), *JObject(v1).toVariant(), *JObject(v2).toVariant(),
          *JObject(v3).toVariant(), *JObject(v4).toVariant());
    _AJNI_CALLBACK_IMPL_END
}

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke6)(JNIEnv *env, jobject thiz, jlong fnidx, jobject v0,
                                                 jobject v1, jobject v2, jobject v3, jobject v4,
                                                 jobject v5) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)(*JObject(v0).toVariant(), *JObject(v1).toVariant(), *JObject(v2).toVariant(),
          *JObject(v3).toVariant(), *JObject(v4).toVariant(), *JObject(v5).toVariant());
    _AJNI_CALLBACK_IMPL_END
}

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke7)(JNIEnv *env, jobject thiz, jlong fnidx, jobject v0,
                                                 jobject v1, jobject v2, jobject v3, jobject v4,
                                                 jobject v5, jobject v6) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)(*JObject(v0).toVariant(), *JObject(v1).toVariant(), *JObject(v2).toVariant(),
          *JObject(v3).toVariant(), *JObject(v4).toVariant(), *JObject(v5).toVariant(),
          *JObject(v6).toVariant());
    _AJNI_CALLBACK_IMPL_END
}

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke8)(JNIEnv *env, jobject thiz, jlong fnidx, jobject v0,
                                                 jobject v1, jobject v2, jobject v3, jobject v4,
                                                 jobject v5, jobject v6, jobject v7) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)(*JObject(v0).toVariant(), *JObject(v1).toVariant(), *JObject(v2).toVariant(),
          *JObject(v3).toVariant(), *JObject(v4).toVariant(), *JObject(v5).toVariant(),
          *JObject(v6).toVariant(), *JObject(v7).toVariant());
    _AJNI_CALLBACK_IMPL_END
}

AJNI_API(jobject) AJNI_FUNC(Callback, jni_1invoke9)(JNIEnv *env, jobject thiz, jlong fnidx, jobject v0,
                                                 jobject v1, jobject v2, jobject v3, jobject v4,
                                                 jobject v5, jobject v6, jobject v7, jobject v8) {
    _AJNI_CALLBACK_IMPL_BEGIN
    (*fn)(*JObject(v0).toVariant(), *JObject(v1).toVariant(), *JObject(v2).toVariant(),
          *JObject(v3).toVariant(), *JObject(v4).toVariant(), *JObject(v5).toVariant(),
          *JObject(v6).toVariant(), *JObject(v7).toVariant(), *JObject(v8).toVariant());
    _AJNI_CALLBACK_IMPL_END
}