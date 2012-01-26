#ifndef __ACML_HPP__JSON__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#define __ACML_HPP__JSON__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#include "detail/json.hpp"

namespace acml {
namespace json {

template<class T>
std::string dumps(const T &object) {
    return detail::dumps(object);
};

} /* namespace json */
} /* namespace acml */
#endif /* __ACML_HPP__JSON__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126 */
