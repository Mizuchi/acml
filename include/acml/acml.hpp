#ifndef __ACML_HPP__ACML__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#define __ACML_HPP__ACML__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#include<boost/preprocessor/repetition/enum_params.hpp>
#include<boost/preprocessor/seq/for_each.hpp>
#include<boost/preprocessor/stringize.hpp>

#ifndef ACML_DISPLAY_TYPENAME
#define ACML_DISPLAY_TYPENAME true
#endif

#if ACML_DISPLAY_TYPENAME
#include"type_name.hpp"
#endif

namespace acml {
inline const char * type_name_tag() {
    return "type.name";
}
template<bool b> struct bool_ {};
template<class T> struct Reflector {
    static const bool defined = false;
}; 
template<class Value, class Visitor>
void for_each(const Value& value, const Visitor& visitor) {
    Reflector<Value>::for_each(value, visitor);
}
} /* namespace acml */

#define ACML_REGISTER_VISIT_BASE(UNUSED1, UNUSED2, Base) \
    for_each(Base(value), visitor);

#define ACML_REGISTER_VISIT_MEMBER(UNUSED1, UNUSED2, member) \
    visitor(value.member, BOOST_PP_STRINGIZE(member));

#if ACML_DISPLAY_TYPENAME
#define ACML_REGISTER_FOR_EACH(TYPE, INHERITS, MEMBERS)                     \
    {                                                                       \
        visitor(type_name(value), type_name_tag());                         \
        BOOST_PP_SEQ_FOR_EACH(ACML_REGISTER_VISIT_BASE, UNUSED, INHERITS)   \
        BOOST_PP_SEQ_FOR_EACH(ACML_REGISTER_VISIT_MEMBER, UNUSED, MEMBERS)  \
    }
#else
#define ACML_REGISTER_FOR_EACH(TYPE, INHERITS, MEMBERS)                     \
    {                                                                       \
        BOOST_PP_SEQ_FOR_EACH(ACML_REGISTER_VISIT_BASE, UNUSED, INHERITS)   \
        BOOST_PP_SEQ_FOR_EACH(ACML_REGISTER_VISIT_MEMBER, UNUSED, MEMBERS)  \
    }
#endif

#define ACML_REGISTER_HANDLE(TYPE, VISITOR, VALUE)                          \
    namespace acml {                                                        \
    template<> struct Reflector<TYPE> {                                     \
        typedef TYPE Value;                                                 \
        static const bool defined = true;                                   \
        template<class Visitor>                                             \
        static void for_each(const Value&, const Visitor&);                 \
    }; } /* namespace acml */                                               \
    template<class Visitor>                                                 \
    void ::acml::Reflector<TYPE>::for_each(                                 \
            const Value &VALUE, const Visitor &VISITOR)

#define ACML_REGISTER_TEMPLATE_HANDLE(TYPE, LENGTH, VISITOR, VALUE)         \
    namespace acml {                                                        \
    template<BOOST_PP_ENUM_PARAMS(LENGTH, class T)>                         \
    struct Reflector< TYPE<BOOST_PP_ENUM_PARAMS(LENGTH, T)> > {             \
        typedef TYPE<BOOST_PP_ENUM_PARAMS(LENGTH, T)> Value;                \
        static const bool defined = true;                                   \
        template<class Visitor>                                             \
        static void for_each(const Value&, const Visitor&);                 \
    }; } /* namespace acml */                                               \
    template<BOOST_PP_ENUM_PARAMS(LENGTH, class T)>                         \
    template<class Visitor>                                                 \
    void ::acml::Reflector<TYPE<BOOST_PP_ENUM_PARAMS(LENGTH, T)> >::        \
         for_each(const Value &VALUE, const Visitor &VISITOR)

#define ACML_REGISTER(TYPE, INHERITS, MEMBERS)                              \
    ACML_REGISTER_HANDLE(TYPE, visitor, value)                              \
    ACML_REGISTER_FOR_EACH(TYPE, INHERITS, MEMBERS)

#define ACML_REGISTER_TEMPLATE(TYPE, LENGTH, INHERITS, MEMBERS)             \
    ACML_REGISTER_TEMPLATE_HANDLE(TYPE, LENGTH, visitor, value)             \
    ACML_REGISTER_FOR_EACH(TYPE, INHERITS, MEMBERS)

#endif /* __ACML_HPP__ACML__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126 */
