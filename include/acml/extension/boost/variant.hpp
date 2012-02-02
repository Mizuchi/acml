#ifndef __ACML_HPP_boost_variant__AUTHOR__YTJ__YTJ000_AT_GMAIL_
#define __ACML_HPP_boost_variant__AUTHOR__YTJ__YTJ000_AT_GMAIL_
#include"../container.hpp"
#include"../../type_name.hpp"
#include<boost/variant.hpp>

namespace acml {

template<class Visitor>
struct boost_variant_visitor : public boost::static_visitor<> {
    const Visitor &visitor;
    template<class T>
    void operator()(const T &value) const {
#if ACML_DISPLAY_TYPENAME
        visitor(type_name(value), type_name_tag());
#endif
        visitor(value, "variant");
    }
    boost_variant_visitor(const Visitor &visitor): visitor(visitor) {}
};

template<class Visitor>
boost_variant_visitor<Visitor>
make_boost_variant_visitor(const Visitor& visitor) {
    return boost_variant_visitor<Visitor>(visitor);
};

} // namespace acml

ACML_REGISTER_TEMPLATE_HANDLE(boost::variant,
                              BOOST_VARIANT_LIMIT_TYPES, visitor, value) {
    boost::apply_visitor(make_boost_variant_visitor(visitor), value);
}
#endif /* __ACML_HPP_boost_variant__AUTHOR__YTJ__YTJ000_AT_GMAIL_ */

