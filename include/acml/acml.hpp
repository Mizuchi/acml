#ifndef __ACML_HPP__ACML__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#define __ACML_HPP__ACML__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#include <boost/preprocessor/seq/for_each.hpp> // BOOST_PP_SEQ_FOR_EACH
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/stringize.hpp>    // BOOST_PP_STRINGIZE

namespace acml {
template<bool b> struct bool_ {};
template<class T> struct Reflector {
    static const bool isDefined = false;
};
}

#define ACML_REGISTER_VISIT_BASE(UNUSED1, UNUSED2, Base) \
    apply_visitor(visitor, Base(value));

#define ACML_REGISTER_VISIT_MEMBER(UNUSED1, UNUSED2, member) \
    visitor(BOOST_PP_STRINGIZE(member), value.member);

#define ACML_REGISTER_APPLY_VISITOR(TYPE, INHERITS, MEMBERS)                        \
    template<typename Visitor>                                             \
    static void apply_visitor(const Visitor& visitor, TYPE& value) {              \
        BOOST_PP_SEQ_FOR_EACH(ACML_REGISTER_VISIT_BASE, UNUSED, INHERITS)  \
        BOOST_PP_SEQ_FOR_EACH(ACML_REGISTER_VISIT_MEMBER, UNUSED, MEMBERS) \
    }

#define ACML_REGISTER_DERIVED(TYPE, INHERITS, MEMBERS)                      \
    namespace acml {                                                        \
    template<> struct Reflector<TYPE> {                                     \
        static const bool isDefined = true;                                 \
        static const char *type_name() { return BOOST_PP_STRINGIZE(TYPE); } \
        ACML_REGISTER_APPLY_VISITOR(      TYPE, INHERITS, MEMBERS )         \
        ACML_REGISTER_APPLY_VISITOR(const TYPE, INHERITS, MEMBERS )         \
    };                                                                      \
    }

#define ACML_REGISTER(TYPE, MEMBERS) \
    ACML_REGISTER_DERIVED(TYPE, , MEMBERS)
#endif /* __ACML_HPP__ACML__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126 */
