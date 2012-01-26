#ifndef __ACML_HPP_DJSON__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#define __ACML_HPP_DJSON__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>
#include "../xml.hpp"

namespace acml {
namespace json {
namespace detail {

using std::string;
string xml2json(const string &xml) {
    boost::property_tree::ptree pt;
    std::istringstream fin(xml);
    std::ostringstream fout;
    read_xml(fin, pt);
    write_json(fout, pt);
    return fout.str();
}

template<class T>
string dumps(const T &object) {
    return xml2json(::acml::xml::dumps(object));
};

} /* namespace detail */
} /* namespace json */
} /* namespace acml */
#endif /* __ACML_HPP_DJSON__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_ */
