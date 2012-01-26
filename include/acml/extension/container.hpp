#ifndef __ACML_HPP__CONTAINER__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#define __ACML_HPP__CONTAINER__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#include"../acml.hpp"
#include<string>

namespace acml {
    template<class T> std::string print(const T&);
}

#define ACML_REGISTER_CONTAINER(TYPE, LENGTH)                               \
    ACML_REGISTER_TEMPLATE_HANDLE(TYPE, LENGTH, visitor, value) {           \
        visitor(#TYPE, "type");                                             \
        visitor(value.size(), "size");                                      \
        std::size_t n = 0;                                                  \
        typedef typename Value::const_iterator Iter;                        \
        for(Iter i = value.begin(); i != value.end(); ++i)                  \
            visitor(*i, print(n++).c_str());                                \
    }

#include<utility>
ACML_REGISTER_TEMPLATE(std::pair, 2, , (first)(second))

#endif /* __ACML_HPP__CONTAINER__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_ */
