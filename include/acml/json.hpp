#ifndef __ACML_HPP__JSON__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#define __ACML_HPP__JSON__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>
#include "xml.hpp"
namespace acml { namespace json { namespace detail {
std::string xml2json(const std::string &xml) {
    boost::property_tree::ptree pt;
    std::istringstream fin(xml);
    std::ostringstream fout;
    read_xml(fin, pt);
    write_json(fout, pt);
    return fout.str();
}
} /* namespace detail */
template<class T>
std::string dumps(const T &object) {
    return detail::xml2json(xml::dumps(object));
};
} /* namespace json */ 
} /* namespace acml */
#endif /* __ACML_HPP__JSON__AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_20120126 */
