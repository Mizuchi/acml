#ifndef __ACML_HPP_Dtypename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#define __ACML_HPP_Dtypename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#include"acml.hpp"
#include<typeinfo>
#include<string>

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

template<>
std::string type_name(const std::string&) {
    return "std::string";
}
template<>
std::string type_name(const int&) {
    return "int";
}
template<>
std::string type_name(const double&) {
    return "double";
}
template<>
std::string type_name(const unsigned int&) {
    return "unsigned int";
}

}

#endif /* __ACML_HPP_Dtypename_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_ */
