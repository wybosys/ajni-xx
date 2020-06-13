#ifndef __AJNI_H_INCLUDED
#define __AJNI_H_INCLUDED

#include "core.hpp"
#include "variant.hpp"
#include <set>

AJNI_BEGIN

class JClass;

// 变量定义
class JField
{
public:

    JField(JClass& clz);
    virtual ~JField() {}

    // 变量名
    string name;

    // 变量类型
    JTypeSignature stype;

protected:

    JClass& _clazz;
};

typedef shared_ptr<JVariant> return_type;
typedef JVariant arg_type;

class JMemberField : public JField
{
public:

    JMemberField(JClass& clz) : JField(clz) {}

    // get
    return_type operator()(JObject&) const;

    // set
    void operator()(JObject&, arg_type const&);
};

class JStaticField : public JField
{
public:

    JStaticField(JClass& clz) : JField(clz) {}

    // get
    return_type operator()() const;

    // set
    void operator()(JObject&, arg_type const&);
};

// 方法定义
class JMethod
{
public:

    JMethod(JClass& clz);
    virtual ~JMethod() {}

    // 函数名
    string name;

    // 返回类型
    JTypeSignature sreturn;

    // 参数类型, 设置则代表不使用自动推导，手动指定入参表
    typedef ::std::vector<JTypeSignature> args_signatures_type;
    typedef shared_ptr<args_signatures_type> args_signatures_typep;
    args_signatures_typep sargs;

    // 生成函数标记
    string signature(args_type const &, args_signatures_typep const & = {}) const;

    static string Signature(args_type const &, JTypeSignature const& sreturn, args_signatures_typep const & = {});

protected:

    JClass& _clazz;
};

class JConstructMethod : public JMethod
{
public:

    JConstructMethod(JClass& clz) : JMethod(clz)
    {
        sreturn = TypeSignature::VOID;
    }

    return_type operator()() const;
    return_type operator()(arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;

    virtual return_type invoke(args_type const&) const;

};

class JMemberMethod : public JMethod
{
public:

    JMemberMethod(JClass& clz) : JMethod(clz) {}

    return_type operator()(JObject&) const;
    return_type operator()(JObject&, arg_type const&) const;
    return_type operator()(JObject&, arg_type const&, arg_type const&) const;
    return_type operator()(JObject&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(JObject&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(JObject&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(JObject&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(JObject&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(JObject&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(JObject&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;

    virtual return_type invoke(JObject&, args_type const &) const;

};

class JStaticMethod : public JMethod
{
public:

    JStaticMethod(JClass& clz) : JMethod(clz) {}

    return_type operator()() const;
    return_type operator()(arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;
    return_type operator()(arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&, arg_type const&) const;

    virtual return_type invoke(args_type const &) const;

};

// 类定义
class JClass
{
public:

    JClass(JClassPath const& = "");
    virtual ~JClass() {}

    // 类名
    JClassName name() const;

    // 类路径
    JClassPath const& path() const;

    // 是否存在
    bool exists() const;

    // 定义构造函数
    JConstructMethod construct;

protected:

    JObject _clazz;
    JClassPath _clazzpath;

    friend class JEnv;
    friend class JEnvPrivate;
};

NNT_CLASS_PREPARE(JContext);

// 上下文环境
class JContext
{
    NNT_CLASS_DECL(JContext);

public:

    JContext();
    ~JContext();

    typedef shared_ptr<JClass> class_typep;

    // 添加类
    bool add(class_typep const&);

    // 查找类
    class_typep find_class(JClassPath const&) const;

    // 注册类
    template <typename T>
    class_typep register_class() {
        auto fnd = find_class(T::CLASSPATH);
        if (fnd)
            return fnd;
        auto r = ::NNT_NS::make_dynamic_shared<T, JClass>();
        return add(r) ? r : nullptr;
    }

    typedef typename JVariant::function_type function_type;
    typedef size_t function_index_type;

    // 保存函数返回索引
    function_index_type add(shared_ptr<function_type> const&);

    // 增加函数计数
    void function_grab(function_index_type);

    // 减少函数技术，释放返回true，否则返回false
    bool function_drop(function_index_type);

    // 获得函数
    shared_ptr<function_type> find_function(function_index_type) const;

    // 清空
    void clear();
};

// 实例定义
template <typename TClass>
class JEntry
{
public:

    typedef TClass class_type;
    typedef JEntry<TClass> self_type;
    typedef shared_ptr<JClass> class_typep;

    explicit JEntry(JVariant const& var, class_typep const& clz = nullptr)
    : _clazz(clz)
    {
        _obj = var.toObject();

        if (!_clazz) {
            _clazz = Env.context().register_class<class_type >();
        }
    }

    explicit JEntry(shared_ptr<JObject> const& var, class_typep const& clz = nullptr)
            : _clazz(clz)
    {
        _obj = var;

        if (!_clazz) {
            _clazz = Env.context().register_class<class_type >();
        }
    }

    inline class_type* operator -> () {
        return dynamic_cast<class_type*>(_clazz.get());
    }

    inline class_type const* operator -> () const {
        return dynamic_cast<class_type const*>(_clazz.get());
    }

    inline operator JObject& () {
        return *_obj;
    }

    inline jobject asReturn() const {
        return _obj->asReturn();
    }

private:

    class_typep _clazz;
    shared_ptr<JObject> _obj;
};

extern string tostr(jstring);

AJNI_END

#endif