#ifndef __ACML_HPP_Dtypename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#define __ACML_HPP_Dtypename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#include"acml.hpp"
#include<string>
#include<typeinfo>

namespace acml {
namespace detail {

template<class T>
std::string type_name(const T &, bool_<true>) {
    return Reflector<T>::type_name();
}

template<class T>
std::string type_name(const T &, bool_<false>) {
    return typeid(T).name();
}

}
}

namespace acml {

template<class T>
std::string type_name(const T &value) {
    return detail::type_name(value, bool_<Reflector<T>::defined>());
}

}

#define ACML_TYPE_NAME_REGISTER(TYPE) \
    namespace acml {                  \
    template<> std::string type_name(const TYPE&) { return #TYPE; } }

ACML_TYPE_NAME_REGISTER(std::string);

#endif /* __ACML_HPP_Dtypename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_ */
