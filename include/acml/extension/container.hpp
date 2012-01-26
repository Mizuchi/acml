#ifndef __ACML_HPP__CONT__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#define __ACML_HPP__CONT__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#include"../acml.hpp"
#include<boost/lexical_cast.hpp>
#include<boost/foreach.hpp>
#define ACML_REGISTER_CONTAINER(TYPE, LENGTH)                               \
    ACML_REGISTER_TEMPLATE_HANDLE(TYPE, LENGTH, visitor, value) {           \
        visitor(#TYPE, "type");                                             \
        visitor(value.size(), "size");                                      \
        std::size_t n = 0;                                                  \
        BOOST_FOREACH(const typename Value::value_type &i, value)           \
            visitor(i, boost::lexical_cast<std::string>(n++).c_str());      \
    }

#include<utility>
ACML_REGISTER_TEMPLATE(std::pair, 2, , (first)(second))

#endif /* __ACML_HPP__CONT__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126 */
