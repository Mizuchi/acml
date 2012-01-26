#ifndef __ACML_HPP__XML___AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#define __ACML_HPP__XML___AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#include"acml.hpp"
#include<boost/lexical_cast.hpp>

namespace acml {
namespace xml {
namespace detail {
using std::string;

struct visitor {
    string &result;
    template<class T>
    void operator()(const T &, const string &)const ;
    visitor(string &result): result(result) {}
};

template<class T>
void print(string &result, const T &value, bool_<false>) {
    result += boost::lexical_cast<string>(value);
}

template<class T>
void print(string &result, const T &value, bool_<true>) {
    Reflector<T>::for_each(value, visitor(result));
}

template<class T>
void visitor::operator()(const T& value, const string &name) const {
    result += "<" + name + ">";
    print(result, value, bool_<Reflector<T>::defined>());
    result += "</" + name + ">";
}

} /* namespace detail */

template<class T>
std::string dumps(const T &object) {
    std::string ret;
    detail::print(ret, object, bool_<Reflector<T>::defined>());
    return ret;
};

} /* namespace xml */
} /* namespace acml */
#endif /* __ACML_HPP__XML___AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126 */
