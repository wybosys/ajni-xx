#include "core.hpp"
#include "ajni++.hpp"
#include "inspect.hpp"

AJNI_BEGIN

class JReflectClass : public JClass
{
public:
    JReflectClass()
        : JClass("java/lang/Class"),
          ForName(*this)
    {
        ForName.name = "forName";
        ForName.sreturn = TypeSignature::CLASS;
        ForName.sargs.emplace_back(TypeSignature::STRING);
    }

    JStaticMethod ForName;
};

struct JInspectPrivate
{
    shared_ptr<JReflectClass> rclass;
};

JInspect::JInspect(const ajni::JClass &clz)
    : _clz(clz)
{
    NNT_CLASS_CONSTRUCT();
}

JInspect::~JInspect(){
    NNT_CLASS_DESTORY();
}

AJNI_END