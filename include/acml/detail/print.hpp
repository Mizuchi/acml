#ifndef __ACML_HPP_Dprint_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#define __ACML_HPP_Dprint_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_
#include<boost/lexical_cast.hpp>
namespace acml {

template<class T>
std::string print(const T &value) {
    return boost::lexical_cast<std::string>(value);
}

}

#endif /* __ACML_HPP_Dprint_AUTHOR__YTJ__YTJ000_AT_GMAIL_DOT_COM_ */
