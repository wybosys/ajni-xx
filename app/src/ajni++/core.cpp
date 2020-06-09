#include "core.hpp"
#include "ajni++.hpp"
#include "jre.hpp"
#include "variant.hpp"

AJNI_BEGIN

const jobject jnull = nullptr;

static JavaVM *gs_vm = nullptr;
static JNIEnv *gs_env = nullptr;
static thread_local bool tls_ismain = false;
static thread_local JNIEnv *tls_env = nullptr;

JEnv Env;

void JEnv::BindVM(JavaVM *vm, JNIEnv *env) {
    ajni::gs_vm = vm;

    if (!env) {
        vm->GetEnv((void **) &env, JNI_VERSION_1_4);
        vm->AttachCurrentThread(&env, nullptr);
    }

    ajni::gs_env = ajni::tls_env = env;
    ajni::tls_ismain = true;
}

jclass JEnv::FindClass(string const& str)
{
    return tls_env->FindClass(str.c_str());
}

jfieldID JEnv::GetStaticFieldID(jclass cls, const string &name, const string &typ)
{
    return tls_env->GetStaticFieldID(cls, name.c_str(), typ.c_str());
}

jboolean JEnv::GetStaticBooleanField(jclass cls, jfieldID id)
{
    return tls_env->GetStaticBooleanField(cls, id);
}

jbyte JEnv::GetStaticByteField(jclass cls, jfieldID id)
{
    return tls_env->GetStaticByteField(cls, id);
}

jobject JEnv::GetStaticObjectField(jclass cls, jfieldID id)
{
    return tls_env->GetStaticObjectField(cls, id);
}

jchar JEnv::GetStaticCharField(jclass cls, jfieldID id)
{
    return tls_env->GetStaticCharField(cls, id);
}

jshort JEnv::GetStaticShortField(jclass cls, jfieldID id)
{
    return tls_env->GetStaticShortField(cls, id);
}

jint JEnv::GetStaticIntField(jclass cls, jfieldID id)
{
    return tls_env->GetStaticIntField(cls, id);
}

jlong JEnv::GetStaticLongField(jclass cls, jfieldID id)
{
    return tls_env->GetStaticLongField(cls, id);
}

jfloat JEnv::GetStaticFloatField(jclass cls, jfieldID id)
{
    return tls_env->GetStaticFloatField(cls, id);
}

jdouble JEnv::GetStaticDoubleField(jclass cls, jfieldID id)
{
    return tls_env->GetStaticDoubleField(cls, id);
}

jfieldID JEnv::GetFieldID(jclass cls, string const &name, string const &sig)
{
    return tls_env->GetFieldID(cls, name.c_str(), sig.c_str());
}

jobject JEnv::GetObjectField(jobject obj, jfieldID fid)
{
    return tls_env->GetObjectField(obj, fid);
}

jboolean JEnv::GetBooleanField(jobject obj, jfieldID fid)
{
    return tls_env->GetBooleanField(obj, fid);
}

jbyte JEnv::GetByteField(jobject obj, jfieldID fid)
{
    return tls_env->GetByteField(obj, fid);
}

jchar JEnv::GetCharField(jobject obj, jfieldID fid)
{
    return tls_env->GetCharField(obj, fid);
}

jshort JEnv::GetShortField(jobject obj, jfieldID fid)
{
    return tls_env->GetShortField(obj, fid);
}

jint JEnv::GetIntField(jobject obj, jfieldID fid)
{
    return tls_env->GetIntField(obj, fid);
}

jlong JEnv::GetLongField(jobject obj, jfieldID fid)
{
    return tls_env->GetLongField(obj, fid);
}

jfloat JEnv::GetFloatField(jobject obj, jfieldID fid)
{
    return tls_env->GetFloatField(obj, fid);
}

jdouble JEnv::GetDoubleField(jobject obj, jfieldID fid)
{
    return tls_env->GetDoubleField(obj, fid);
}

jmethodID JEnv::GetMethodID(jclass cls, string const &name, string const &sig)
{
    return tls_env->GetMethodID(cls, name.c_str(), sig.c_str());
}

jmethodID JEnv::GetStaticMethodID(jclass cls, string const& name, string const& sig)
{
    return tls_env->GetStaticMethodID(cls, name.c_str(), sig.c_str());
}

#define JENV_IMPL_EXPAND(func, pre)                                                                                 \
    switch (vals.size())                                                                                            \
    {                                                                                                               \
    case 0:                                                                                                         \
        return tls_env->func(pre);                                                                                  \
    case 1:                                                                                                         \
        return tls_env->func(pre, vals[0]);                                                                         \
    case 2:                                                                                                         \
        return tls_env->func(pre, vals[0], vals[1]);                                                                \
    case 3:                                                                                                         \
        return tls_env->func(pre, vals[0], vals[1], vals[2]);                                                       \
    case 4:                                                                                                         \
        return tls_env->func(pre, vals[0], vals[1], vals[2], vals[3]);                                              \
    case 5:                                                                                                         \
        return tls_env->func(pre, vals[0], vals[1], vals[2], vals[3], vals[4]);                                     \
    case 6:                                                                                                         \
        return tls_env->func(pre, vals[0], vals[1], vals[2], vals[3], vals[4], vals[5]);                            \
    case 7:                                                                                                         \
        return tls_env->func(pre, vals[0], vals[1], vals[2], vals[3], vals[4], vals[5], vals[6]);                   \
    case 8:                                                                                                         \
        return tls_env->func(pre, vals[0], vals[1], vals[2], vals[3], vals[4], vals[5], vals[6], vals[7]);          \
    case 9:                                                                                                         \
        return tls_env->func(pre, vals[0], vals[1], vals[2], vals[3], vals[4], vals[5], vals[6], vals[7], vals[8]); \
    default:                                                                                                        \
        break;                                                                                                      \
    }

jobject JEnv::NewObject(jclass cls, jmethodID id, JValues const &vals)
{
    JENV_IMPL_EXPAND(NewObject, cls NNT_COMMA id);
    return nullptr;
}

jboolean JEnv::CallStaticBooleanMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticBooleanMethod, cls NNT_COMMA id);
    return false;
}

jbyte JEnv::CallStaticByteMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticByteMethod, cls NNT_COMMA id);
    return 0;
}

jchar JEnv::CallStaticCharMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticCharMethod, cls NNT_COMMA id);
    return 0;
}

jshort JEnv::CallStaticShortMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticShortMethod, cls NNT_COMMA id);
    return 0;
}

jint JEnv::CallStaticIntMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticIntMethod, cls NNT_COMMA id);
    return 0;
}

jlong JEnv::CallStaticLongMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticLongMethod, cls NNT_COMMA id);
    return 0;
}

jfloat JEnv::CallStaticFloatMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticFloatMethod, cls NNT_COMMA id);
    return 0;
}

jdouble JEnv::CallStaticDoubleMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticDoubleMethod, cls NNT_COMMA id);
    return 0;
}

jobject JEnv::CallStaticObjectMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticObjectMethod, cls NNT_COMMA id);
    return 0;
}

void JEnv::CallStaticVoidMethod(jclass cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallStaticVoidMethod, cls NNT_COMMA id);
}

jboolean JEnv::CallBooleanMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallBooleanMethod, cls NNT_COMMA id);
    return false;
}

jbyte JEnv::CallByteMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallByteMethod, cls NNT_COMMA id);
    return 0;
}

jchar JEnv::CallCharMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallCharMethod, cls NNT_COMMA id);
    return 0;
}

jshort JEnv::CallShortMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallShortMethod, cls NNT_COMMA id);
    return 0;
}

jint JEnv::CallIntMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallIntMethod, cls NNT_COMMA id);
    return 0;
}

jlong JEnv::CallLongMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallLongMethod, cls NNT_COMMA id);
    return 0;
}

jfloat JEnv::CallFloatMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallFloatMethod, cls NNT_COMMA id);
    return 0;
}

jdouble JEnv::CallDoubleMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallDoubleMethod, cls NNT_COMMA id);
    return 0;
}

jobject JEnv::CallObjectMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallObjectMethod, cls NNT_COMMA id);
    return nullptr;
}

void JEnv::CallVoidMethod(jobject cls, jmethodID id, JValues const& vals)
{
    JENV_IMPL_EXPAND(CallVoidMethod, cls NNT_COMMA id);
}

jobject JEnv::NewLocalRef(jobject obj)
{
    return tls_env->NewLocalRef(obj);
}

void JEnv::DeleteLocalRef(jobject obj)
{
    tls_env->DeleteLocalRef(obj);
}

jobject JEnv::NewGlobalRef(jobject obj)
{
    return tls_env->NewGlobalRef(obj);
}

void JEnv::DeleteGlobalRef(jobject obj)
{
    return tls_env->DeleteGlobalRef(obj);
}

jsize JEnv::GetStringUTFLength(jstring jstr)
{
    return tls_env->GetStringUTFLength(jstr);
}

string JEnv::GetStringUTFChars(jstring jstr)
{
    jboolean cp = false;
    char const* cs = tls_env->GetStringUTFChars(jstr, &cp);
    if (cs) {
        string r = cs;
        if (cp)
            tls_env->ReleaseStringUTFChars(jstr, cs);
        return r;
    }
    return "";
}

jstring JEnv::NewStringUTF(string const& str)
{
    return tls_env->NewStringUTF(str.c_str());
}

namespace TypeSignature
{
    const JTypeSignature CLASS = "Ljava/lang/Class;";
    const JTypeSignature STRING = "Ljava/lang/String;";
    const JTypeSignature OBJECT = "Ljava/lang/Object;";
    const JTypeSignature BOOLEAN = "Z";
    const JTypeSignature BYTE = "B";
    const JTypeSignature CHAR = "C";
    const JTypeSignature SHORT = "S";
    const JTypeSignature INT = "I";
    const JTypeSignature LONG = "J";
    const JTypeSignature FLOAT = "F";
    const JTypeSignature DOUBLE = "D";
    const JTypeSignature VOID = "V";
} // namespace TypeSignature

ExceptionGuard::~ExceptionGuard()
{
    if (!gs_env->ExceptionCheck())
        return;
    jthrowable exp = gs_env->ExceptionOccurred();
    gs_env->ExceptionClear();

    JEntry<jre::Throwable> obj(exp);
    string msg = obj->toString(obj);
    AJNI_LOGE("捕获JNI异常 %s", msg.c_str());
}

AJNI_END