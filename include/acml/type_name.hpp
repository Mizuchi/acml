#ifndef __ACML_HPP_typename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#define __ACML_HPP_typename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_

#include"detail/type_name.hpp"
#include<string>
#include<typeinfo>
#include<cxxabi.h>

namespace acml {
namespace typeName {
    std::string pretty_print(const char *);
}

template<class T>
struct TypeName {
    static std::string value() {
        static int status;
        static const std::string ret = typeName::pretty_print(
                abi::__cxa_demangle(typeid(T).name(), 0, 0, &status));
        return ret;
    }
};

template<class T>
std::string type_name(const T &) {
    return TypeName<T>().value();
}

} // namespace acml

#define ACML_TYPENAME_HANDLE(TYPE)                        \
    namespace acml {                                      \
    template<> struct TypeName<TYPE> {                    \
        static std::string value();                       \
    }; } /* namespace acml */                             \
    inline std::string acml::TypeName<TYPE>::value()

#endif /* __ACML_HPP_typename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_ */
