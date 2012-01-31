#ifndef __ACML_HPP_boost_variant__AUTHOR__YTJ__YTJ000_AT_GMAIL_
#define __ACML_HPP_boost_variant__AUTHOR__YTJ__YTJ000_AT_GMAIL_
#include"../container.hpp"
#include"../../type_name.hpp"
#include<boost/variant.hpp>
#include<boost/typeof/typeof.hpp>
namespace acml {

    template<class Visitor>
    struct boost_variant_visitor : public boost::static_visitor<> {
        const Visitor& visitor;
        template<class T>
            void operator()(const T& value) const {
                visitor(value, "variant(" + type_name(value) + ")");
            }
        boost_variant_visitor(const Visitor& visitor): visitor(visitor) {}
    };

}
ACML_REGISTER_TEMPLATE_HANDLE(boost::variant, 
        BOOST_VARIANT_LIMIT_TYPES, visitor, value) {
    boost_variant_visitor<BOOST_TYPEOF(visitor)> handle(visitor);
    boost::apply_visitor(handle, value);
}
#endif /* __ACML_HPP_boost_variant__AUTHOR__YTJ__YTJ000_AT_GMAIL_ */

