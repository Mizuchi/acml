#ifndef __ACML_HPP_boost_optional_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#define __ACML_HPP_boost_optional_AUTHOR__YTJ__YTJ000_AT_GMAIL_
#include"../../acml.hpp"
#include<boost/optional.hpp>

ACML_REGISTER_TEMPLATE_HANDLE(boost::optional, 1, visitor, value) {
#if ACML_DISPLAY_TYPENAME
    visitor(TypeName<T0>::value(), type_name_tag());
#endif
    if (value) visitor(*value, "optional");
}
#endif /* __ACML_HPP_boost_optional_AUTHOR__YTJ__YTJ000_AT_GMAIL_ */

